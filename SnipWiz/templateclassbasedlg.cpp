//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: templateclassbasedlg.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "templateclassbasedlg.h"

// Declare the bitmap loading function
extern void wxC61A6InitBitmapResources();

static bool bBitmapLoaded = false;

TemplateClassBaseDlg::TemplateClassBaseDlg(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos,
                                           const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC61A6InitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* bSizer1 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(bSizer1);

    ID_NOTEBOOK1 = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)),
                                  wxNB_NOPAGETHEME | wxBK_DEFAULT);
    ID_NOTEBOOK1->SetName(wxT("ID_NOTEBOOK1"));

    bSizer1->Add(ID_NOTEBOOK1, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    ID_PANEL = new wxPanel(ID_NOTEBOOK1, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(ID_NOTEBOOK1, wxSize(-1, -1)),
                           wxTAB_TRAVERSAL);
    ID_NOTEBOOK1->AddPage(ID_PANEL, _("Generate"), true);

    wxBoxSizer* bSizer2 = new wxBoxSizer(wxVERTICAL);
    ID_PANEL->SetSizer(bSizer2);

    wxStaticBoxSizer* staticBoxSizer8 =
        new wxStaticBoxSizer(new wxStaticBox(ID_PANEL, wxID_ANY, _("Class")), wxVERTICAL);

    bSizer2->Add(staticBoxSizer8, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* fgSizer1 = new wxFlexGridSizer(0, 2, 0, 0);
    fgSizer1->SetFlexibleDirection(wxBOTH);
    fgSizer1->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    fgSizer1->AddGrowableCol(1);

    staticBoxSizer8->Add(fgSizer1, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_static1 = new wxStaticText(ID_PANEL, wxID_ANY, _("Class name:"), wxDefaultPosition,
                                 wxDLG_UNIT(ID_PANEL, wxSize(-1, -1)), 0);

    fgSizer1->Add(m_static1, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_textCtrlClassName =
        new wxTextCtrl(ID_PANEL, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(ID_PANEL, wxSize(-1, -1)), 0);
    m_textCtrlClassName->SetToolTip(_("Name of new class"));
    m_textCtrlClassName->SetFocus();
#if wxVERSION_NUMBER >= 3000
    m_textCtrlClassName->SetHint(wxT(""));
#endif

    fgSizer1->Add(m_textCtrlClassName, 1, wxALL | wxEXPAND | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_static2 = new wxStaticText(ID_PANEL, wxID_ANY, _("Template:"), wxDefaultPosition,
                                 wxDLG_UNIT(ID_PANEL, wxSize(-1, -1)), 0);

    fgSizer1->Add(m_static2, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    wxArrayString m_comboxCurrentTemplateArr;
    m_comboxCurrentTemplate =
        new wxComboBox(ID_PANEL, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(ID_PANEL, wxSize(-1, -1)),
                       m_comboxCurrentTemplateArr, wxCB_SORT | wxCB_READONLY);
    m_comboxCurrentTemplate->SetToolTip(_("Template for new class"));

    fgSizer1->Add(m_comboxCurrentTemplate, 0, wxALL | wxEXPAND | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    wxStaticBoxSizer* sbSizer02 = new wxStaticBoxSizer(new wxStaticBox(ID_PANEL, wxID_ANY, _("Files")), wxVERTICAL);

    bSizer2->Add(sbSizer02, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* fgSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
    fgSizer2->SetFlexibleDirection(wxBOTH);
    fgSizer2->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    fgSizer2->AddGrowableCol(1);

    sbSizer02->Add(fgSizer2, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_static3 = new wxStaticText(ID_PANEL, wxID_ANY, _("Header file:"), wxDefaultPosition,
                                 wxDLG_UNIT(ID_PANEL, wxSize(-1, -1)), 0);

    fgSizer2->Add(m_static3, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_textCtrlHeaderFile =
        new wxTextCtrl(ID_PANEL, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(ID_PANEL, wxSize(-1, -1)), 0);
    m_textCtrlHeaderFile->SetToolTip(_("Name of header file"));
#if wxVERSION_NUMBER >= 3000
    m_textCtrlHeaderFile->SetHint(wxT(""));
#endif

    fgSizer2->Add(m_textCtrlHeaderFile, 0, wxALL | wxEXPAND | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    fgSizer2->Add(5, 5, 0, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_static4 = new wxStaticText(ID_PANEL, wxID_ANY, _("Implementation file:"), wxDefaultPosition,
                                 wxDLG_UNIT(ID_PANEL, wxSize(-1, -1)), 0);

    fgSizer2->Add(m_static4, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_textCtrlCppFile =
        new wxTextCtrl(ID_PANEL, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(ID_PANEL, wxSize(-1, -1)), 0);
    m_textCtrlCppFile->SetToolTip(_("Name of source file"));
#if wxVERSION_NUMBER >= 3000
    m_textCtrlCppFile->SetHint(wxT(""));
#endif

    fgSizer2->Add(m_textCtrlCppFile, 0, wxALL | wxEXPAND | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    fgSizer2->Add(5, 5, 0, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_staticProjectTreeFolder = new wxStaticText(ID_PANEL, wxID_ANY, _("Project tree folder:"), wxDefaultPosition,
                                                 wxDLG_UNIT(ID_PANEL, wxSize(-1, -1)), 0);

    fgSizer2->Add(m_staticProjectTreeFolder, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_textCtrlVD = new wxTextCtrl(ID_PANEL, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(ID_PANEL, wxSize(230, -1)),
                                  wxTE_READONLY);
    m_textCtrlVD->SetToolTip(_("Virtual folder to add new files"));
#if wxVERSION_NUMBER >= 3000
    m_textCtrlVD->SetHint(wxT(""));
#endif

    fgSizer2->Add(m_textCtrlVD, 0, wxALL | wxEXPAND | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_buttonBrowseVD =
        new wxButton(ID_PANEL, wxID_ANY, _("..."), wxDefaultPosition, wxDLG_UNIT(ID_PANEL, wxSize(-1, -1)), 0);
    m_buttonBrowseVD->SetToolTip(_("Browse virtual folders"));

    fgSizer2->Add(m_buttonBrowseVD, 0, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_static5 =
        new wxStaticText(ID_PANEL, wxID_ANY, _("Path:"), wxDefaultPosition, wxDLG_UNIT(ID_PANEL, wxSize(-1, -1)), 0);

    fgSizer2->Add(m_static5, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_textCtrlFilePath = new wxTextCtrl(ID_PANEL, wxID_ANY, wxT(""), wxDefaultPosition,
                                        wxDLG_UNIT(ID_PANEL, wxSize(230, -1)), wxTE_READONLY);
    m_textCtrlFilePath->SetToolTip(_("Hd folder to add new files"));
#if wxVERSION_NUMBER >= 3000
    m_textCtrlFilePath->SetHint(wxT(""));
#endif

    fgSizer2->Add(m_textCtrlFilePath, 0, wxALL | wxEXPAND | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_buttonBrowsePath =
        new wxButton(ID_PANEL, wxID_ANY, _("..."), wxDefaultPosition, wxDLG_UNIT(ID_PANEL, wxSize(-1, -1)), 0);
    m_buttonBrowsePath->SetToolTip(_("Browse  folders"));

    fgSizer2->Add(m_buttonBrowsePath, 0, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    bSizer2->Add(0, 0, 1, wxALL, WXC_FROM_DIP(5));

    m_stdBtnSizer10 = new wxStdDialogButtonSizer();

    bSizer2->Add(m_stdBtnSizer10, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));

    m_buttonOK = new wxButton(ID_PANEL, wxID_OK, wxT(""), wxDefaultPosition, wxDLG_UNIT(ID_PANEL, wxSize(-1, -1)), 0);
    m_buttonOK->SetDefault();
    m_stdBtnSizer10->AddButton(m_buttonOK);

    m_buttonCancel =
        new wxButton(ID_PANEL, wxID_CANCEL, wxT(""), wxDefaultPosition, wxDLG_UNIT(ID_PANEL, wxSize(-1, -1)), 0);
    m_stdBtnSizer10->AddButton(m_buttonCancel);
    m_stdBtnSizer10->Realize();

    ID_PANEL1 = new wxPanel(ID_NOTEBOOK1, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(ID_NOTEBOOK1, wxSize(-1, -1)),
                            wxTAB_TRAVERSAL);
    ID_NOTEBOOK1->AddPage(ID_PANEL1, _("Templates"), false);

    wxBoxSizer* bSizer4 = new wxBoxSizer(wxVERTICAL);
    ID_PANEL1->SetSizer(bSizer4);

    wxBoxSizer* bSizer5 = new wxBoxSizer(wxHORIZONTAL);

    bSizer4->Add(bSizer5, 0, wxALL | wxEXPAND, WXC_FROM_DIP(1));

    m_static6 =
        new wxStaticText(ID_PANEL1, wxID_ANY, _("Name:"), wxDefaultPosition, wxDLG_UNIT(ID_PANEL1, wxSize(-1, -1)), 0);

    bSizer5->Add(m_static6, 0, wxALL | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(1));

    wxArrayString m_comboxTemplatesArr;
    m_comboxTemplates = new wxComboBox(ID_PANEL1, wxID_ANY, wxT(""), wxDefaultPosition,
                                       wxDLG_UNIT(ID_PANEL1, wxSize(-1, -1)), m_comboxTemplatesArr, wxCB_SORT);
#if wxVERSION_NUMBER >= 3000
    m_comboxTemplates->SetHint(wxT(""));
#endif

    bSizer5->Add(m_comboxTemplates, 1, wxALL | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(1));

    m_buttonAddTemplate =
        new wxButton(ID_PANEL1, wxID_ANY, _("Add"), wxDefaultPosition, wxDLG_UNIT(ID_PANEL1, wxSize(-1, -1)), 0);

    bSizer5->Add(m_buttonAddTemplate, 0, wxALL | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(1));

    m_buttonChangeTemplate =
        new wxButton(ID_PANEL1, wxID_ANY, _("Change"), wxDefaultPosition, wxDLG_UNIT(ID_PANEL1, wxSize(-1, -1)), 0);

    bSizer5->Add(m_buttonChangeTemplate, 0, wxALL | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(1));

    m_buttonRemoveTemplate =
        new wxButton(ID_PANEL1, wxID_ANY, _("Remove"), wxDefaultPosition, wxDLG_UNIT(ID_PANEL1, wxSize(-1, -1)), 0);

    bSizer5->Add(m_buttonRemoveTemplate, 0, wxALL | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(1));

    m_buttonClear =
        new wxButton(ID_PANEL1, wxID_ANY, _("Clear"), wxDefaultPosition, wxDLG_UNIT(ID_PANEL1, wxSize(-1, -1)), 0);

    bSizer5->Add(m_buttonClear, 0, wxALL | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(1));

    m_buttonInsertClassMacro =
        new wxButton(ID_PANEL1, wxID_ANY, _("%CLASS%"), wxDefaultPosition, wxDLG_UNIT(ID_PANEL1, wxSize(-1, -1)), 0);

    bSizer5->Add(m_buttonInsertClassMacro, 0, wxALL | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(1));

    m_notebookFiles = new wxNotebook(ID_PANEL1, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(ID_PANEL1, wxSize(500, -1)),
                                     wxBK_TOP | wxBK_DEFAULT);
    m_notebookFiles->SetName(wxT("m_notebookFiles"));

    bSizer4->Add(m_notebookFiles, 1, wxALL | wxEXPAND, WXC_FROM_DIP(1));

    m_panel3 = new wxPanel(m_notebookFiles, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_notebookFiles, wxSize(-1, -1)),
                           wxTAB_TRAVERSAL);
    m_notebookFiles->AddPage(m_panel3, _("Header File"), true);

    wxBoxSizer* bSizer6 = new wxBoxSizer(wxVERTICAL);
    m_panel3->SetSizer(bSizer6);

    m_textCtrlHeader =
        new wxStyledTextCtrl(m_panel3, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panel3, wxSize(-1, -1)), 0);
    // Configure the fold margin
    m_textCtrlHeader->SetMarginType(4, wxSTC_MARGIN_SYMBOL);
    m_textCtrlHeader->SetMarginMask(4, wxSTC_MASK_FOLDERS);
    m_textCtrlHeader->SetMarginSensitive(4, true);
    m_textCtrlHeader->SetMarginWidth(4, 0);

    // Configure the tracker margin
    m_textCtrlHeader->SetMarginWidth(1, 0);

    // Configure the symbol margin
    m_textCtrlHeader->SetMarginType(2, wxSTC_MARGIN_SYMBOL);
    m_textCtrlHeader->SetMarginMask(2, ~(wxSTC_MASK_FOLDERS));
    m_textCtrlHeader->SetMarginWidth(2, 0);
    m_textCtrlHeader->SetMarginSensitive(2, true);

    // Configure the line numbers margin
    m_textCtrlHeader->SetMarginType(0, wxSTC_MARGIN_NUMBER);
    m_textCtrlHeader->SetMarginWidth(0, 0);

    // Configure the line symbol margin
    m_textCtrlHeader->SetMarginType(3, wxSTC_MARGIN_FORE);
    m_textCtrlHeader->SetMarginMask(3, 0);
    m_textCtrlHeader->SetMarginWidth(3, 0);
    // Select the lexer
    m_textCtrlHeader->SetLexer(wxSTC_LEX_NULL);
    // Set default font / styles
    m_textCtrlHeader->StyleClearAll();
    m_textCtrlHeader->SetWrapMode(0);
    m_textCtrlHeader->SetIndentationGuides(0);
    m_textCtrlHeader->SetKeyWords(0, wxT(""));
    m_textCtrlHeader->SetKeyWords(1, wxT(""));
    m_textCtrlHeader->SetKeyWords(2, wxT(""));
    m_textCtrlHeader->SetKeyWords(3, wxT(""));
    m_textCtrlHeader->SetKeyWords(4, wxT(""));

    bSizer6->Add(m_textCtrlHeader, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_panel4 = new wxPanel(m_notebookFiles, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_notebookFiles, wxSize(-1, -1)),
                           wxTAB_TRAVERSAL);
    m_notebookFiles->AddPage(m_panel4, _("Implementation File"), false);

    wxBoxSizer* bSizer61 = new wxBoxSizer(wxVERTICAL);
    m_panel4->SetSizer(bSizer61);

    m_textCtrlImpl =
        new wxStyledTextCtrl(m_panel4, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panel4, wxSize(-1, -1)), 0);
    // Configure the fold margin
    m_textCtrlImpl->SetMarginType(4, wxSTC_MARGIN_SYMBOL);
    m_textCtrlImpl->SetMarginMask(4, wxSTC_MASK_FOLDERS);
    m_textCtrlImpl->SetMarginSensitive(4, true);
    m_textCtrlImpl->SetMarginWidth(4, 0);

    // Configure the tracker margin
    m_textCtrlImpl->SetMarginWidth(1, 0);

    // Configure the symbol margin
    m_textCtrlImpl->SetMarginType(2, wxSTC_MARGIN_SYMBOL);
    m_textCtrlImpl->SetMarginMask(2, ~(wxSTC_MASK_FOLDERS));
    m_textCtrlImpl->SetMarginWidth(2, 0);
    m_textCtrlImpl->SetMarginSensitive(2, true);

    // Configure the line numbers margin
    m_textCtrlImpl->SetMarginType(0, wxSTC_MARGIN_NUMBER);
    m_textCtrlImpl->SetMarginWidth(0, 0);

    // Configure the line symbol margin
    m_textCtrlImpl->SetMarginType(3, wxSTC_MARGIN_FORE);
    m_textCtrlImpl->SetMarginMask(3, 0);
    m_textCtrlImpl->SetMarginWidth(3, 0);
    // Select the lexer
    m_textCtrlImpl->SetLexer(wxSTC_LEX_NULL);
    // Set default font / styles
    m_textCtrlImpl->StyleClearAll();
    m_textCtrlImpl->SetWrapMode(0);
    m_textCtrlImpl->SetIndentationGuides(0);
    m_textCtrlImpl->SetKeyWords(0, wxT(""));
    m_textCtrlImpl->SetKeyWords(1, wxT(""));
    m_textCtrlImpl->SetKeyWords(2, wxT(""));
    m_textCtrlImpl->SetKeyWords(3, wxT(""));
    m_textCtrlImpl->SetKeyWords(4, wxT(""));

    bSizer61->Add(m_textCtrlImpl, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(ID_NOTEBOOK1)) {
        wxPersistenceManager::Get().RegisterAndRestore(ID_NOTEBOOK1);
    } else {
        wxPersistenceManager::Get().Restore(ID_NOTEBOOK1);
    }
#endif

#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(m_notebookFiles)) {
        wxPersistenceManager::Get().RegisterAndRestore(m_notebookFiles);
    } else {
        wxPersistenceManager::Get().Restore(m_notebookFiles);
    }
#endif

    SetName(wxT("TemplateClassBaseDlg"));
    SetSize(wxDLG_UNIT(this, wxSize(-1, -1)));
    if(GetSizer()) {
        GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    m_textCtrlClassName->Connect(wxEVT_COMMAND_TEXT_UPDATED,
                                 wxCommandEventHandler(TemplateClassBaseDlg::OnClassNameEntered), NULL, this);
    m_staticProjectTreeFolder->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(TemplateClassBaseDlg::OnVirtualDirUI),
                                       NULL, this);
    m_textCtrlVD->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(TemplateClassBaseDlg::OnVirtualDirUI), NULL, this);
    m_buttonBrowseVD->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(TemplateClassBaseDlg::OnBrowseVD),
                              NULL, this);
    m_buttonBrowseVD->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(TemplateClassBaseDlg::OnVirtualDirUI), NULL,
                              this);
    m_buttonBrowsePath->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
                                wxCommandEventHandler(TemplateClassBaseDlg::OnBrowseFilePath), NULL, this);
    m_buttonOK->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(TemplateClassBaseDlg::OnGenerate), NULL,
                        this);
    m_buttonOK->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(TemplateClassBaseDlg::OnGenerateUI), NULL, this);
    m_buttonCancel->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(TemplateClassBaseDlg::OnQuit), NULL,
                            this);
    m_comboxTemplates->Connect(wxEVT_COMMAND_COMBOBOX_SELECTED,
                               wxCommandEventHandler(TemplateClassBaseDlg::OnTemplateClassSelected), NULL, this);
    m_buttonAddTemplate->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(TemplateClassBaseDlg::OnButtonAdd),
                                 NULL, this);
    m_buttonAddTemplate->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(TemplateClassBaseDlg::OnButtonAddUI), NULL,
                                 this);
    m_buttonChangeTemplate->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
                                    wxCommandEventHandler(TemplateClassBaseDlg::OnButtonChange), NULL, this);
    m_buttonChangeTemplate->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(TemplateClassBaseDlg::OnButtonChangeUI),
                                    NULL, this);
    m_buttonRemoveTemplate->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
                                    wxCommandEventHandler(TemplateClassBaseDlg::OnButtonRemove), NULL, this);
    m_buttonRemoveTemplate->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(TemplateClassBaseDlg::OnButtonRemoveUI),
                                    NULL, this);
    m_buttonClear->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(TemplateClassBaseDlg::OnButtonClear),
                           NULL, this);
    m_buttonClear->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(TemplateClassBaseDlg::OnButtonClearUI), NULL, this);
    m_buttonInsertClassMacro->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
                                      wxCommandEventHandler(TemplateClassBaseDlg::OnInsertClassKeyword), NULL, this);
    m_buttonInsertClassMacro->Connect(wxEVT_UPDATE_UI,
                                      wxUpdateUIEventHandler(TemplateClassBaseDlg::OnInsertClassKeywordUI), NULL, this);
    m_textCtrlHeader->Connect(
        wxEVT_STC_CHANGE, wxStyledTextEventHandler(TemplateClassBaseDlg::OnStcHeaderFileContentChnaged), NULL, this);
    m_textCtrlImpl->Connect(wxEVT_STC_CHANGE,
                            wxStyledTextEventHandler(TemplateClassBaseDlg::OnStcImplFileContentChnaged), NULL, this);
}

TemplateClassBaseDlg::~TemplateClassBaseDlg()
{
    m_textCtrlClassName->Disconnect(wxEVT_COMMAND_TEXT_UPDATED,
                                    wxCommandEventHandler(TemplateClassBaseDlg::OnClassNameEntered), NULL, this);
    m_staticProjectTreeFolder->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(TemplateClassBaseDlg::OnVirtualDirUI),
                                          NULL, this);
    m_textCtrlVD->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(TemplateClassBaseDlg::OnVirtualDirUI), NULL, this);
    m_buttonBrowseVD->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(TemplateClassBaseDlg::OnBrowseVD),
                                 NULL, this);
    m_buttonBrowseVD->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(TemplateClassBaseDlg::OnVirtualDirUI), NULL,
                                 this);
    m_buttonBrowsePath->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
                                   wxCommandEventHandler(TemplateClassBaseDlg::OnBrowseFilePath), NULL, this);
    m_buttonOK->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(TemplateClassBaseDlg::OnGenerate), NULL,
                           this);
    m_buttonOK->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(TemplateClassBaseDlg::OnGenerateUI), NULL, this);
    m_buttonCancel->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(TemplateClassBaseDlg::OnQuit), NULL,
                               this);
    m_comboxTemplates->Disconnect(wxEVT_COMMAND_COMBOBOX_SELECTED,
                                  wxCommandEventHandler(TemplateClassBaseDlg::OnTemplateClassSelected), NULL, this);
    m_buttonAddTemplate->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
                                    wxCommandEventHandler(TemplateClassBaseDlg::OnButtonAdd), NULL, this);
    m_buttonAddTemplate->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(TemplateClassBaseDlg::OnButtonAddUI), NULL,
                                    this);
    m_buttonChangeTemplate->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
                                       wxCommandEventHandler(TemplateClassBaseDlg::OnButtonChange), NULL, this);
    m_buttonChangeTemplate->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(TemplateClassBaseDlg::OnButtonChangeUI),
                                       NULL, this);
    m_buttonRemoveTemplate->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
                                       wxCommandEventHandler(TemplateClassBaseDlg::OnButtonRemove), NULL, this);
    m_buttonRemoveTemplate->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(TemplateClassBaseDlg::OnButtonRemoveUI),
                                       NULL, this);
    m_buttonClear->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(TemplateClassBaseDlg::OnButtonClear),
                              NULL, this);
    m_buttonClear->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(TemplateClassBaseDlg::OnButtonClearUI), NULL,
                              this);
    m_buttonInsertClassMacro->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
                                         wxCommandEventHandler(TemplateClassBaseDlg::OnInsertClassKeyword), NULL, this);
    m_buttonInsertClassMacro->Disconnect(
        wxEVT_UPDATE_UI, wxUpdateUIEventHandler(TemplateClassBaseDlg::OnInsertClassKeywordUI), NULL, this);
    m_textCtrlHeader->Disconnect(
        wxEVT_STC_CHANGE, wxStyledTextEventHandler(TemplateClassBaseDlg::OnStcHeaderFileContentChnaged), NULL, this);
    m_textCtrlImpl->Disconnect(wxEVT_STC_CHANGE,
                               wxStyledTextEventHandler(TemplateClassBaseDlg::OnStcImplFileContentChnaged), NULL, this);
}
