//---------------------------------------------------------------------------
//
// Name:        NSIS FileSeekerApp.h
// Author:      Geronimo Onativia (geronimox@gmail.com)
// Created:     04/06/2008 12:05:41 p.m.
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __NSIS_FILESEEKERFRMApp_h__
#define __NSIS_FILESEEKERFRMApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class NSIS_FileSeekerFrmApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
