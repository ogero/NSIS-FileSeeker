//---------------------------------------------------------------------------
//
// Name:        NSIS FileSeekerFrm.cpp
// Author:      Geronimo Onativia (geronimox@gmail.com)
// Created:     04/06/2008 12:05:41 p.m.
// Description: NSIS_FileSeekerFrm class implementation
//
//---------------------------------------------------------------------------

#include "NSIS FileSeekerFrm.h"

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// NSIS_FileSeekerFrm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(NSIS_FileSeekerFrm,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(NSIS_FileSeekerFrm::OnClose)
	EVT_BUTTON(ID_CLEARMEMO,NSIS_FileSeekerFrm::ClearMemoClick)
	EVT_BUTTON(ID_SELECTTODO,NSIS_FileSeekerFrm::SelectTodoClick)
	EVT_BUTTON(ID_ELEJIR,NSIS_FileSeekerFrm::ElejirClick)
	EVT_BUTTON(ID_START,NSIS_FileSeekerFrm::StartClick)
END_EVENT_TABLE()
////Event Table End

NSIS_FileSeekerFrm::NSIS_FileSeekerFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

NSIS_FileSeekerFrm::~NSIS_FileSeekerFrm()
{
}

void NSIS_FileSeekerFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	vinculo = new wxHyperlinkCtrl(this, ID_VINCULO, _("Sources"), _("http://wxdsgn.sf.net"), wxPoint(701, 417), wxSize(47, 20), wxNO_BORDER | wxHL_CONTEXTMENU, _("vinculo"));
	vinculo->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, true, _("MS Sans Serif")));

	WxDirDialog1 =  new wxDirDialog(this, _("Pick a path"), _(""));

	ClearMemo = new wxButton(this, ID_CLEARMEMO, _("Clear window"), wxPoint(128, 406), wxSize(113, 29), 0, wxDefaultValidator, _("ClearMemo"));
	ClearMemo->SetToolTip(_("Clear text"));

	SelectTodo = new wxButton(this, ID_SELECTTODO, _("Select All"), wxPoint(9, 406), wxSize(113, 29), 0, wxDefaultValidator, _("SelectTodo"));
	SelectTodo->SetToolTip(_("Select all text to be copied."));

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, _("Relative path to files:"), wxPoint(10, 67), wxDefaultSize, 0, _("WxStaticText3"));

	RelativePath = new wxTextCtrl(this, ID_RELATIVEPATH, _(""), wxPoint(156, 65), wxSize(292, 22), 0, wxDefaultValidator, _("RelativePath"));
	RelativePath->SetToolTip(_("Files path relative to .NSI file."));

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, _("Installation Path:"), wxPoint(9, 11), wxDefaultSize, 0, _("WxStaticText2"));

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, _("Directory to analyze:"), wxPoint(10, 39), wxDefaultSize, 0, _("WxStaticText1"));

	BaseDir = new wxTextCtrl(this, ID_BASEDIR, _(""), wxPoint(156, 9), wxSize(84, 22), 0, wxDefaultValidator, _("BaseDir"));
	BaseDir->SetToolTip(_("Path where NSIS will install the files."));

	Output = new wxTextCtrl(this, ID_OUTPUT, wxEmptyString, wxPoint(10, 143), wxSize(735, 255), wxVSCROLL | wxHSCROLL | wxTE_MULTILINE, wxDefaultValidator, _("Output"));
	Output->SetMaxLength(0);
	Output->SetFocus();
	Output->SetInsertionPointEnd();

	Elejir = new wxButton(this, ID_ELEJIR, _("Pick a Path"), wxPoint(455, 33), wxSize(103, 29), 0, wxDefaultValidator, _("Elejir"));
	Elejir->SetToolTip(_("Shows the path picker dialog."));

	Directorio = new wxTextCtrl(this, ID_DIRECTORIO, _(""), wxPoint(156, 37), wxSize(292, 22), 0, wxDefaultValidator, _("Directorio"));
	Directorio->SetToolTip(_("Path where files to be installed are located."));

	Start = new wxButton(this, ID_START, _("GENERATE SCRIPT"), wxPoint(9, 102), wxSize(158, 28), 0, wxDefaultValidator, _("Start"));
	Start->SetToolTip(_("Generate the files list"));

	RecursiveDir = new wxCheckBox(this, ID_RECURSIVEDIR, _("Analyze Subdirectories"), wxPoint(178, 108), wxSize(153, 20), 0, wxDefaultValidator, _("RecursiveDir"));
	RecursiveDir->SetToolTip(_("Analyze directories recursively"));
	RecursiveDir->SetValue(true);

	SetTitle(_("NSIS FileSeeker"));
	SetIcon(wxNullIcon);
	SetSize(8,8,769,476);
	Center();
	
	////GUI Items Creation End

    Directorio->SetValue(wxT("C:\\Windows\\Temp"));
    RelativePath->SetValue(wxT("C:\\Windows\\Temp"));
    BaseDir->SetValue(wxT("$INSTDIR"));
    vinculo->SetURL(wxT("https://github.com/GeropaPidurulein/NSIS-FileSeeker"));
}

void NSIS_FileSeekerFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}

/*
 * ElejirClick
 */
void NSIS_FileSeekerFrm::ElejirClick(wxCommandEvent& event)
{
    int sel=WxDirDialog1->ShowModal();
    if(sel==wxID_OK){
        Directorio->SetValue(WxDirDialog1->GetPath());
        RelativePath->SetValue(WxDirDialog1->GetPath());
    }
}

/*
 * StartClick
 */
void NSIS_FileSeekerFrm::StartClick(wxCommandEvent& event)
{
    wxDir dir(Directorio->GetValue());
    if(RecursiveDir->GetValue()==false){
        if ( !dir.IsOpened() ){
            Output->AppendText(wxT("Error al abrir directorio...\n"));
            return;
        }
        wxString filename;
        bool cont = dir.GetFirst(&filename, "", wxDIR_FILES | wxDIR_HIDDEN);
        while ( cont ){
            Output->AppendText(wxString::Format(wxT("%s\n"),filename.c_str()));;
            cont = dir.GetNext(&filename);
        }
    }else{
        recursedir(Directorio->GetValue(),Directorio->GetValue());
    }
}
void NSIS_FileSeekerFrm::recursedir(wxString base,wxString direct){
    wxDir dir(direct);
    if ( !dir.IsOpened() ){
        Output->AppendText(wxT("Error al abrir directorio...\n"));
        return;
    }
    wxString filename;
    bool cont = dir.GetFirst(&filename, "", wxDIR_FILES | wxDIR_HIDDEN);
    if(cont)
        Output->AppendText(wxString::Format(wxT("SetOutPath \"%s%s\"\n"),BaseDir->GetValue().c_str(),direct.Mid(base.Length()).c_str()));;
    while ( cont ){
        Output->AppendText(wxString::Format(wxT("\tFile \"%s%s\\%s\"\n"),RelativePath->GetValue().c_str(),direct.Mid(base.Length()).c_str(),filename.c_str()));;
        cont = dir.GetNext(&filename);
    }
    cont = dir.GetFirst(&filename, "", wxDIR_DIRS);
    while ( cont ){
        recursedir(base, wxString::Format(wxT("%s\\%s"),direct.c_str(),filename.c_str()));
        cont = dir.GetNext(&filename);
    }
}

/*
 * ClearMemoClick
 */
void NSIS_FileSeekerFrm::ClearMemoClick(wxCommandEvent& event)
{
    Output->SetFocus();
    Output->Clear();
}

/*
 * SelectTodoClick
 */
void NSIS_FileSeekerFrm::SelectTodoClick(wxCommandEvent& event)
{
    Output->SetFocus();
    Output->SelectAll();
}
