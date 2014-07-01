//---------------------------------------------------------------------------
//
// Name:        NSIS FileSeekerFrm.h
// Author:      Geronimo Onativia (geronimox@gmail.com)
// Created:     04/06/2008 12:05:41 p.m.
// Description: NSIS_FileSeekerFrm class declaration
//
//---------------------------------------------------------------------------

#ifndef __NSIS_FILESEEKERFRM_h__
#define __NSIS_FILESEEKERFRM_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/hyperlink.h>
#include <wx/dirdlg.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/checkbox.h>
////Header Include End
#include <wx/dir.h>
////Dialog Style Start
#undef NSIS_FileSeekerFrm_STYLE
#define NSIS_FileSeekerFrm_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class NSIS_FileSeekerFrm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		NSIS_FileSeekerFrm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("NSIS FileSeeker"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = NSIS_FileSeekerFrm_STYLE);
		virtual ~NSIS_FileSeekerFrm();
		void ElejirClick(wxCommandEvent& event);
		void StartClick(wxCommandEvent& event);
		void ClearMemoClick(wxCommandEvent& event);
		void SelectTodoClick(wxCommandEvent& event);
		void vinculoHyperLink(wxHyperlinkEvent& event);
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxHyperlinkCtrl *vinculo;
		wxDirDialog *WxDirDialog1;
		wxButton *ClearMemo;
		wxButton *SelectTodo;
		wxStaticText *WxStaticText3;
		wxTextCtrl *RelativePath;
		wxStaticText *WxStaticText2;
		wxStaticText *WxStaticText1;
		wxTextCtrl *BaseDir;
		wxTextCtrl *Output;
		wxButton *Elejir;
		wxTextCtrl *Directorio;
		wxButton *Start;
		wxCheckBox *RecursiveDir;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_VINCULO = 1015,
			ID_CLEARMEMO = 1014,
			ID_SELECTTODO = 1013,
			ID_WXSTATICTEXT3 = 1012,
			ID_RELATIVEPATH = 1011,
			ID_WXSTATICTEXT2 = 1009,
			ID_WXSTATICTEXT1 = 1008,
			ID_BASEDIR = 1007,
			ID_OUTPUT = 1006,
			ID_ELEJIR = 1005,
			ID_DIRECTORIO = 1004,
			ID_START = 1002,
			ID_RECURSIVEDIR = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
        void recursedir(wxString base,wxString direct);
};
#endif
