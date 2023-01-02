#include "clToolBarSpacer.h"
#if !wxUSE_NATIVE_TOOLBAR
clToolBarSpacer::clToolBarSpacer(clToolBar* parent)
    : clToolBarButtonBase(parent, wxID_SEPARATOR, INVALID_BITMAP_ID, "", kDisabled | kSpacer)
{
}

clToolBarSpacer::~clToolBarSpacer() {}

wxSize clToolBarSpacer::CalculateSize(wxDC& dc) const { return wxSize(m_toolbar->GetXSpacer() * 10 + 1, -1); }

void clToolBarSpacer::Render(wxDC& dc, const wxRect& rect)
{
    wxUnusedVar(dc);
    wxUnusedVar(rect);
}
#endif // #if !wxUSE_NATIVE_TOOLBAR
