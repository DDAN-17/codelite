#include "clFileSystemWorkspace.hpp"
#include "clFileSystemWorkspaceView.hpp"
#include "clFilesCollector.h"
#include "JSON.h"
#include "globals.h"
#include "imanager.h"
#include "clWorkspaceView.h"
#include "clWorkspaceManager.h"
#include "event_notifier.h"
#include "codelite_events.h"
#include <thread>
#include "clFileSystemEvent.h"
#include "ctags_manager.h"
#include "file_logger.h"
#include "parse_thread.h"
#include "compiler_command_line_parser.h"
#include <wxStringHash.h>
#include <wx/tokenzr.h>
#include "shell_command.h"
#include "processreaderthread.h"
#include "clFilesCollector.h"
#include <wx/msgdlg.h>

wxDEFINE_EVENT(wxEVT_FS_SCAN_COMPLETED, clFileSystemEvent);
clFileSystemWorkspace::clFileSystemWorkspace(bool dummy)
    : m_dummy(dummy)
{
    SetWorkspaceType("File System Workspace");
    if(!dummy) {
        EventNotifier::Get()->Bind(wxEVT_CMD_CLOSE_WORKSPACE, &clFileSystemWorkspace::OnCloseWorkspace, this);
        EventNotifier::Get()->Bind(wxEVT_CMD_OPEN_WORKSPACE, &clFileSystemWorkspace::OnOpenWorkspace, this);
        EventNotifier::Get()->Bind(wxEVT_ALL_EDITORS_CLOSED, &clFileSystemWorkspace::OnAllEditorsClosed, this);
        EventNotifier::Get()->Bind(wxEVT_FS_SCAN_COMPLETED, &clFileSystemWorkspace::OnScanCompleted, this);
        EventNotifier::Get()->Bind(wxEVT_CMD_RETAG_WORKSPACE, &clFileSystemWorkspace::OnParseWorkspace, this);
        EventNotifier::Get()->Bind(wxEVT_CMD_RETAG_WORKSPACE_FULL, &clFileSystemWorkspace::OnParseWorkspace, this);
        EventNotifier::Get()->Bind(wxEVT_SAVE_SESSION_NEEDED, &clFileSystemWorkspace::OnSaveSession, this);
        Bind(wxEVT_PARSE_THREAD_SCAN_INCLUDES_DONE, &clFileSystemWorkspace::OnParseThreadScanIncludeCompleted, this);

        // Build events
        EventNotifier::Get()->Bind(wxEVT_BUILD_STARTING, &clFileSystemWorkspace::OnBuildStarting, this);
        Bind(wxEVT_ASYNC_PROCESS_TERMINATED, &clFileSystemWorkspace::OnBuildProcessTerminated, this);
        Bind(wxEVT_ASYNC_PROCESS_OUTPUT, &clFileSystemWorkspace::OnBuildProcessOutput, this);
    }
}

clFileSystemWorkspace::~clFileSystemWorkspace()
{
    if(!m_dummy) {
        EventNotifier::Get()->Unbind(wxEVT_CMD_CLOSE_WORKSPACE, &clFileSystemWorkspace::OnCloseWorkspace, this);
        EventNotifier::Get()->Unbind(wxEVT_CMD_OPEN_WORKSPACE, &clFileSystemWorkspace::OnOpenWorkspace, this);
        EventNotifier::Get()->Unbind(wxEVT_ALL_EDITORS_CLOSED, &clFileSystemWorkspace::OnAllEditorsClosed, this);
        EventNotifier::Get()->Unbind(wxEVT_FS_SCAN_COMPLETED, &clFileSystemWorkspace::OnScanCompleted, this);
        EventNotifier::Get()->Unbind(wxEVT_SAVE_SESSION_NEEDED, &clFileSystemWorkspace::OnSaveSession, this);

        // parsing event
        EventNotifier::Get()->Unbind(wxEVT_CMD_RETAG_WORKSPACE, &clFileSystemWorkspace::OnParseWorkspace, this);
        EventNotifier::Get()->Unbind(wxEVT_CMD_RETAG_WORKSPACE_FULL, &clFileSystemWorkspace::OnParseWorkspace, this);
        Unbind(wxEVT_PARSE_THREAD_SCAN_INCLUDES_DONE, &clFileSystemWorkspace::OnParseThreadScanIncludeCompleted, this);

        // Build events
        EventNotifier::Get()->Unbind(wxEVT_BUILD_STARTING, &clFileSystemWorkspace::OnBuildStarting, this);
        Unbind(wxEVT_ASYNC_PROCESS_TERMINATED, &clFileSystemWorkspace::OnBuildProcessTerminated, this);
        Unbind(wxEVT_ASYNC_PROCESS_OUTPUT, &clFileSystemWorkspace::OnBuildProcessOutput, this);
    }
}

wxString clFileSystemWorkspace::GetActiveProjectName() const { return ""; }

wxFileName clFileSystemWorkspace::GetFileName() const { return m_filename; }

wxString clFileSystemWorkspace::GetFilesMask() const
{
    clFileSystemWorkspaceConfig::Ptr_t conf = m_settings.GetSelectedConfig();
    if(conf) { return conf->GetFileExtensions(); }
    return wxEmptyString;
}

wxFileName clFileSystemWorkspace::GetProjectFileName(const wxString& projectName) const
{
    wxUnusedVar(projectName);
    return wxFileName();
}

void clFileSystemWorkspace::GetProjectFiles(const wxString& projectName, wxArrayString& files) const {}

wxString clFileSystemWorkspace::GetProjectFromFile(const wxFileName& filename) const { return ""; }

void clFileSystemWorkspace::GetWorkspaceFiles(wxArrayString& files) const
{
    files.clear();
    files.Alloc(m_files.size());
    for(const wxFileName& file : m_files) {
        files.Add(file.GetFullPath());
    }
}

wxArrayString clFileSystemWorkspace::GetWorkspaceProjects() const { return {}; }

bool clFileSystemWorkspace::IsBuildSupported() const { return true; }

bool clFileSystemWorkspace::IsProjectSupported() const { return false; }

void clFileSystemWorkspace::CacheFiles()
{
    if(!m_files.empty()) { m_files.clear(); }
    std::thread thr(
        [=](const wxString& rootFolder) {
            clFilesScanner fs;
            std::vector<wxString> files;
            wxStringSet_t excludeFolders = { ".git", ".svn", ".codelite" };
            fs.Scan(rootFolder, files, GetFilesMask(), "", excludeFolders);

            clFileSystemEvent event(wxEVT_FS_SCAN_COMPLETED);
            wxArrayString arrfiles;
            arrfiles.Alloc(files.size());
            for(const wxString& f : files) {
                arrfiles.Add(f);
            }
            event.SetPaths(arrfiles);
            EventNotifier::Get()->QueueEvent(event.Clone());
        },
        GetFileName().GetPath());
    thr.detach();
}

void clFileSystemWorkspace::OnBuildStarting(clBuildEvent& event)
{
    event.Skip();
    if(IsOpen()) {
        event.Skip(false);
        if(m_buildProcess) { return; }
        m_buildProcess = ::CreateAsyncProcess(this, GetTargetCommand(event.GetKind()), IProcessCreateDefault,
                                              GetFileName().GetPath());
        if(!m_buildProcess) {
            clCommandEvent e(wxEVT_SHELL_COMMAND_PROCESS_ENDED);
            EventNotifier::Get()->AddPendingEvent(e);
        } else {
            clCommandEvent e(wxEVT_SHELL_COMMAND_STARTED);
            EventNotifier::Get()->AddPendingEvent(e);
        }
    }
}

void clFileSystemWorkspace::OnBuildEnded(clBuildEvent& event) { event.Skip(); }

void clFileSystemWorkspace::OnOpenWorkspace(clCommandEvent& event)
{
    event.Skip();
    wxFileName workspaceFile(event.GetFileName());

    // Test that this is our workspace
    if(m_settings.IsOk(workspaceFile) && Load(workspaceFile)) {
        event.Skip(false);
        DoOpen();

    } else {
        m_filename.Clear();
    }
}

void clFileSystemWorkspace::OnCloseWorkspace(clCommandEvent& event)
{
    event.Skip();
    if(m_isLoaded) {
        event.Skip(false);
        DoClose();
    }
}

bool clFileSystemWorkspace::Load(const wxFileName& file)
{
    if(m_isLoaded) { return true; }
    m_filename = file;
    bool loadOk = m_settings.Load(m_filename);
    if(loadOk && m_settings.GetName().empty()) { m_settings.SetName(m_filename.GetName()); }
    return loadOk;
}

void clFileSystemWorkspace::Save(bool parse)
{
    if(!m_filename.IsOk()) { return; }
    m_settings.Save(m_filename);

    // trigger a file scan
    if(parse) { CacheFiles(); }
}

void clFileSystemWorkspace::RestoreSession()
{
    if(IsOpen()) { clGetManager()->LoadWorkspaceSession(m_filename); }
}

void clFileSystemWorkspace::DoOpen()
{
    // Create the symbols db file
    wxFileName fnFolder(GetFileName());
    fnFolder.SetExt("db");
    fnFolder.AppendDir(".codelite");
    fnFolder.Mkdir(wxS_DIR_DEFAULT, wxPATH_MKDIR_FULL);

    // Init the view
    GetView()->Clear();
    GetView()->AddFolder(GetFileName().GetPath());

    // Notify CodeLite that this workspace is opened
    clGetManager()->GetWorkspaceView()->SelectPage(GetWorkspaceType());
    clWorkspaceManager::Get().SetWorkspace(this);

    // Notify that the a new workspace is loaded
    wxCommandEvent event(wxEVT_WORKSPACE_LOADED);
    event.SetString(GetFileName().GetFullPath());
    EventNotifier::Get()->AddPendingEvent(event);

    // and finally, request codelite to keep this workspace in the recently opened workspace list
    clGetManager()->AddWorkspaceToRecentlyUsedList(m_filename);

    TagsManagerST::Get()->CloseDatabase();
    TagsManagerST::Get()->OpenDatabase(fnFolder.GetFullPath());

    // Update the parser paths with the active configuration
    UpdateParserPaths();

    // Cache the source files from the workspace directories
    CacheFiles();

    // Load the workspace session (if any)
    CallAfter(&clFileSystemWorkspace::RestoreSession);
    m_isLoaded = true;
}

void clFileSystemWorkspace::DoClose()
{
    if(!m_isLoaded) return;

    // Store the session
    clGetManager()->StoreWorkspaceSession(m_filename);

    // avoid any file re-cache, we are closing
    Save(false);
    DoClear();

    // Clear the UI
    GetView()->Clear();

    // Restore the parser search paths
    const wxArrayString& paths = TagsManagerST::Get()->GetCtagsOptions().GetParserSearchPaths();
    ParseThreadST::Get()->SetSearchPaths(paths, {});
    clDEBUG() << "Parser paths are now set to:" << paths;

    // Notify workspace closed event
    wxCommandEvent event(wxEVT_WORKSPACE_CLOSED);
    EventNotifier::Get()->ProcessEvent(event);

    // Notify codelite to close the currently opened workspace
    wxCommandEvent eventClose(wxEVT_MENU, wxID_CLOSE_ALL);
    eventClose.SetEventObject(EventNotifier::Get()->TopFrame());
    EventNotifier::Get()->TopFrame()->GetEventHandler()->ProcessEvent(eventClose);

    // Free the database
    TagsManagerST::Get()->CloseDatabase();

    m_isLoaded = false;
    m_showWelcomePage = true;
}

void clFileSystemWorkspace::DoClear()
{
    m_filename.Clear();
    m_settings.Clear();
}

void clFileSystemWorkspace::OnAllEditorsClosed(wxCommandEvent& event)
{
    event.Skip();
    if(m_showWelcomePage) {
        m_showWelcomePage = false;
        // Show the 'Welcome Page'
        wxFrame* frame = EventNotifier::Get()->TopFrame();
        wxCommandEvent eventShowWelcomePage(wxEVT_MENU, XRCID("view_welcome_page"));
        eventShowWelcomePage.SetEventObject(frame);
        frame->GetEventHandler()->AddPendingEvent(eventShowWelcomePage);
    }
}

clFileSystemWorkspace& clFileSystemWorkspace::Get()
{
    static clFileSystemWorkspace wsp(false);
    return wsp;
}

void clFileSystemWorkspace::New(const wxString& folder)
{
    wxFileName fn(folder, "");
    if(fn.GetDirCount() == 0) {
        ::wxMessageBox(_("Unable to create a workspace on the root folder"), "CodeLite", wxICON_ERROR | wxCENTER);
        return;
    }
    // Check to see if any workspace already exists in this folder
    clFilesScanner fs;
    clFilesScanner::EntryData::Vec_t results;
    fs.ScanNoRecurse(folder, results, "*.workspace");
    for(const auto& f : results) {
        if(clFileSystemWorkspaceSettings::IsOk(f.fullpath)) {
            fn = f.fullpath;
            break;
        }
    }

    // If an workspace is opened and it is the same one as this, dont do nothing
    if(m_isLoaded && (GetFileName() == fn)) { return; }

    // Call close here, it does nothing if a workspace is not opened
    DoClose();
    DoClear();
    if(fn.GetFullName().IsEmpty()) {
        wxString name = ::clGetTextFromUser(_("Workspace Name"), _("Name"), fn.GetDirs().Last());
        if(name.IsEmpty()) { return; }
        fn.SetName(name);
    }

    fn.SetExt("workspace");
    SetName(fn.GetName());

    // Creates an empty workspace file
    m_filename = fn;
    if(!fn.FileExists()) { Save(false); }

    // and load it
    if(Load(m_filename)) {
        DoOpen();
    } else {
        m_filename.Clear();
    }
}

void clFileSystemWorkspace::OnScanCompleted(clFileSystemEvent& event)
{
    m_files.clear();
    m_files.reserve(event.GetPaths().size());
    for(const wxString& filename : event.GetPaths()) {
        m_files.push_back(filename);
    }
    clGetManager()->SetStatusMessage(_("File system scan completed"));

    // Trigger a non full reparse
    Parse(false);
}

void clFileSystemWorkspace::OnParseWorkspace(wxCommandEvent& event)
{
    if(!m_isLoaded) {
        event.Skip();
        return;
    }
    Parse(event.GetInt() == (event.GetEventType() == wxEVT_CMD_RETAG_WORKSPACE));
}

void clFileSystemWorkspace::Parse(bool fullParse)
{
    if(m_files.empty()) { return; }

    // in the case of re-tagging the entire workspace and full re-tagging is enabled
    // it is faster to drop the tables instead of deleting
    if(fullParse) { TagsManagerST::Get()->GetDatabase()->RecreateDatabase(); }

    UpdateParserPaths();

    // Create a parsing request
    ParseRequest* parsingRequest = new ParseRequest(EventNotifier::Get()->TopFrame());
    parsingRequest->_workspaceFiles.reserve(m_files.size());
    // use a deep copy to endure thread safety
    for(const wxFileName& fn : m_files) {
        // filter any non valid coding file
        parsingRequest->_workspaceFiles.push_back(fn.GetFullPath().ToAscii().data());
    }

    parsingRequest->setType(ParseRequest::PR_PARSEINCLUDES);
    parsingRequest->setDbFile(TagsManagerST::Get()->GetDatabase()->GetDatabaseFileName().GetFullPath().c_str());
    parsingRequest->_evtHandler = this;
    parsingRequest->_quickRetag = !fullParse;
    ParseThreadST::Get()->Add(parsingRequest);
    clGetManager()->SetStatusMessage(_("Scanning for files to parse..."));
}

void clFileSystemWorkspace::OnParseThreadScanIncludeCompleted(wxCommandEvent& event)
{
    clGetManager()->SetStatusMessage(_("Parsing..."));

    wxBusyCursor busyCursor;
    std::set<wxString>* fileSet = (std::set<wxString>*)event.GetClientData();

    // add to this set the workspace files to create a unique list of
    // files
    for(const wxFileName& fn : m_files) {
        fileSet->insert(fn.GetFullPath());
    }

    // recreate the list in the form of vector (the API requirs vector)
    std::vector<wxFileName> vFiles;
    vFiles.reserve(fileSet->size());
    vFiles.insert(vFiles.end(), fileSet->begin(), fileSet->end());

    // -----------------------------------------------
    // tag them
    // -----------------------------------------------
    TagsManagerST::Get()->RetagFiles(vFiles, event.GetInt() ? TagsManager::Retag_Quick : TagsManager::Retag_Full);
    wxDELETE(fileSet);
}

void clFileSystemWorkspace::UpdateParserPaths()
{
    clFileSystemWorkspaceConfig::Ptr_t conf = m_settings.GetSelectedConfig();
    if(!conf) { return; }
    // Update the parser paths
    wxArrayString uniquePaths = conf->GetSearchPaths(GetFileName());
    ParseThreadST::Get()->SetSearchPaths(uniquePaths, {});
    clDEBUG() << "[" << conf->GetName() << "]"
              << "Parser paths are now set to:" << uniquePaths;
}

void clFileSystemWorkspace::Close() { DoClose(); }

wxString clFileSystemWorkspace::CompileFlagsAsString(const wxArrayString& arr) const
{
    wxString s;
    for(const wxString& l : arr) {
        if(!l.IsEmpty()) { s << l << "\n"; }
    }
    return s.Trim();
}

wxString clFileSystemWorkspace::GetTargetCommand(const wxString& target) const
{
    if(!m_settings.GetSelectedConfig()) { return wxEmptyString; }
    const wxStringMap_t& M = m_settings.GetSelectedConfig()->GetBuildTargets();
    if(M.count(target)) { return M.find(target)->second; }
    return wxEmptyString;
}

void clFileSystemWorkspace::OnBuildProcessTerminated(clProcessEvent& event)
{
    wxDELETE(m_buildProcess);
    DoPrintBuildMessage(event.GetOutput());

    clCommandEvent e(wxEVT_SHELL_COMMAND_PROCESS_ENDED);
    EventNotifier::Get()->AddPendingEvent(e);
}

void clFileSystemWorkspace::OnBuildProcessOutput(clProcessEvent& event) { DoPrintBuildMessage(event.GetOutput()); }

void clFileSystemWorkspace::DoPrintBuildMessage(const wxString& message)
{
    clCommandEvent e(wxEVT_SHELL_COMMAND_ADDLINE);
    e.SetString(message);
    EventNotifier::Get()->AddPendingEvent(e);
}

void clFileSystemWorkspace::OnSaveSession(clCommandEvent& event)
{
    event.Skip();
    if(IsOpen()) {
        event.Skip(false);
        clGetManager()->StoreWorkspaceSession(m_filename);
    }
}

void clFileSystemWorkspace::Initialise()
{
    if(m_initialized) { return; }
    m_view = new clFileSystemWorkspaceView(clGetManager()->GetWorkspaceView()->GetBook(), GetWorkspaceType());
    clGetManager()->GetWorkspaceView()->AddPage(m_view, GetWorkspaceType());
}
