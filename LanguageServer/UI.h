//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: UI.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef _CODELITE_LANGUAGESERVER_UI_BASE_CLASSES_H
#define _CODELITE_LANGUAGESERVER_UI_BASE_CLASSES_H

// clang-format off
#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/checkbox.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/notebook.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/textctrl.h>
#include <wx/imaglist.h>
#include <wx/stc/stc.h>
#include "clThemedSTC.hpp"
#include <wx/combobox.h>
#include <wx/arrstr.h>
#include "clThemedTextCtrl.hpp"
#include <wx/dataview.h>
#include "clTerminalViewCtrl.hpp"
#include "Notebook.h"
#include <wx/treectrl.h>
#include "clThemedTreeCtrl.h"
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif

#ifdef WXC_FROM_DIP
#undef WXC_FROM_DIP
#endif
#if wxVERSION_NUMBER >= 3100
#define WXC_FROM_DIP(x) wxWindow::FromDIP(x, NULL)
#else
#define WXC_FROM_DIP(x) x
#endif

// clang-format on

class LanguageServerSettingsDlgBase : public wxDialog
{
protected:
    wxCheckBox* m_checkBoxEnable;
    wxStaticLine* m_staticLine102;
    wxStaticText* m_staticText105;
    wxNotebook* m_notebook;
    wxButton* m_buttonScan;
    wxButton* m_buttonNew;
    wxButton* m_buttonDelete;
    wxStdDialogButtonSizer* m_stdBtnSizer4;
    wxButton* m_button6;
    wxButton* m_button8;

protected:
    virtual void OnScan(wxCommandEvent& event) { event.Skip(); }
    virtual void OnAddServer(wxCommandEvent& event) { event.Skip(); }
    virtual void OnDeleteLSP(wxCommandEvent& event) { event.Skip(); }
    virtual void OnDeleteLSPUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnOKUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnButtonOK(wxCommandEvent& event) { event.Skip(); }

public:
    wxCheckBox* GetCheckBoxEnable() { return m_checkBoxEnable; }
    wxStaticLine* GetStaticLine102() { return m_staticLine102; }
    wxStaticText* GetStaticText105() { return m_staticText105; }
    wxNotebook* GetNotebook() { return m_notebook; }
    wxButton* GetButtonScan() { return m_buttonScan; }
    wxButton* GetButtonNew() { return m_buttonNew; }
    wxButton* GetButtonDelete() { return m_buttonDelete; }
    LanguageServerSettingsDlgBase(wxWindow* parent, wxWindowID id = wxID_ANY,
                                  const wxString& title = _("Language Server Settings"),
                                  const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1),
                                  long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~LanguageServerSettingsDlgBase();
};

class LanguageServerPageBase : public wxPanel
{
protected:
    wxCheckBox* m_checkBoxEnabled;
    wxStaticText* m_staticText453;
    wxTextCtrl* m_textCtrlName;
    wxStaticText* m_staticText495;
    wxNotebook* m_notebook201;
    wxPanel* m_panel202;
    clThemedSTC* m_stcCommand;
    wxPanel* m_panel203;
    clThemedSTC* m_stcInitOptions;
    wxStaticText* m_staticText579;
    wxTextCtrl* m_textCtrlWD;
    wxButton* m_button1153;
    wxStaticText* m_staticText6311;
    wxTextCtrl* m_textCtrlLanguages;
    wxButton* m_button115;
    wxStaticText* m_staticText117;
    wxComboBox* m_comboBoxConnection;
    wxCheckBox* m_checkBoxDiagnostics;

protected:
    virtual void OnCommandUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnBrowseWD(wxCommandEvent& event) { event.Skip(); }
    virtual void OnSuggestLanguages(wxCommandEvent& event) { event.Skip(); }

public:
    wxCheckBox* GetCheckBoxEnabled() { return m_checkBoxEnabled; }
    wxStaticText* GetStaticText453() { return m_staticText453; }
    wxTextCtrl* GetTextCtrlName() { return m_textCtrlName; }
    wxStaticText* GetStaticText495() { return m_staticText495; }
    clThemedSTC* GetStcCommand() { return m_stcCommand; }
    wxPanel* GetPanel202() { return m_panel202; }
    clThemedSTC* GetStcInitOptions() { return m_stcInitOptions; }
    wxPanel* GetPanel203() { return m_panel203; }
    wxNotebook* GetNotebook201() { return m_notebook201; }
    wxStaticText* GetStaticText579() { return m_staticText579; }
    wxTextCtrl* GetTextCtrlWD() { return m_textCtrlWD; }
    wxButton* GetButton1153() { return m_button1153; }
    wxStaticText* GetStaticText6311() { return m_staticText6311; }
    wxTextCtrl* GetTextCtrlLanguages() { return m_textCtrlLanguages; }
    wxButton* GetButton115() { return m_button115; }
    wxStaticText* GetStaticText117() { return m_staticText117; }
    wxComboBox* GetComboBoxConnection() { return m_comboBoxConnection; }
    wxCheckBox* GetCheckBoxDiagnostics() { return m_checkBoxDiagnostics; }
    LanguageServerPageBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition,
                           const wxSize& size = wxSize(-1, -1), long style = wxTAB_TRAVERSAL);
    virtual ~LanguageServerPageBase();
};

class NewLanguageServerDlgBase : public wxDialog
{
protected:
    wxStdDialogButtonSizer* m_stdBtnSizer37;
    wxButton* m_buttonOK;
    wxButton* m_button41;

protected:
    virtual void OnOKUI(wxUpdateUIEvent& event) { event.Skip(); }

public:
    NewLanguageServerDlgBase(wxWindow* parent, wxWindowID id = wxID_ANY,
                             const wxString& title = _("New Language Server"), const wxPoint& pos = wxDefaultPosition,
                             const wxSize& size = wxSize(-1, -1),
                             long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~NewLanguageServerDlgBase();
};

class LSPOutlineViewDlgBase : public wxDialog
{
protected:
    wxPanel* m_panel155;
    clThemedTextCtrl* m_textCtrlFilter;
    clTerminalViewCtrl* m_dvTreeCtrll;

protected:
    virtual void OnTextUpdated(wxCommandEvent& event) { event.Skip(); }
    virtual void OnEnter(wxCommandEvent& event) { event.Skip(); }
    virtual void OnKeyDown(wxKeyEvent& event) { event.Skip(); }
    virtual void OnItemActivated(wxDataViewEvent& event) { event.Skip(); }
    virtual void OnListKeyDown(wxKeyEvent& event) { event.Skip(); }

public:
    clThemedTextCtrl* GetTextCtrlFilter() { return m_textCtrlFilter; }
    clTerminalViewCtrl* GetDvTreeCtrll() { return m_dvTreeCtrll; }
    wxPanel* GetPanel155() { return m_panel155; }
    LSPOutlineViewDlgBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Outline View"),
                          const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500, 300),
                          long style = wxDEFAULT_DIALOG_STYLE | wxSTAY_ON_TOP | wxRESIZE_BORDER);
    virtual ~LSPOutlineViewDlgBase();
};

class LanguageServerLogViewBase : public wxPanel
{
protected:
    Notebook* m_notebook207;
    wxPanel* m_panel209;
    clThemedTreeCtrl* m_treeCtrlProblems;
    wxPanel* m_panel208;
    clTerminalViewCtrl* m_dvListCtrl;

protected:
    virtual void OnDiagnosticSelected(wxTreeEvent& event) { event.Skip(); }

public:
    clThemedTreeCtrl* GetTreeCtrlProblems() { return m_treeCtrlProblems; }
    wxPanel* GetPanel209() { return m_panel209; }
    clTerminalViewCtrl* GetDvListCtrl() { return m_dvListCtrl; }
    wxPanel* GetPanel208() { return m_panel208; }
    Notebook* GetNotebook207() { return m_notebook207; }
    LanguageServerLogViewBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition,
                              const wxSize& size = wxSize(500, 300), long style = wxTAB_TRAVERSAL);
    virtual ~LanguageServerLogViewBase();
};

#endif
