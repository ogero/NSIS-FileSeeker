//---------------------------------------------------------------------------
//
// Name:        NSIS FileSeekerApp.cpp
// Author:      Geronimo Onativia (geronimox@gmail.com)
// Created:     04/06/2008 12:05:41 p.m.
// Description: 
//
//---------------------------------------------------------------------------

#include "NSIS FileSeekerApp.h"
#include "NSIS FileSeekerFrm.h"

IMPLEMENT_APP(NSIS_FileSeekerFrmApp)

bool NSIS_FileSeekerFrmApp::OnInit()
{
    NSIS_FileSeekerFrm* frame = new NSIS_FileSeekerFrm(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int NSIS_FileSeekerFrmApp::OnExit()
{
	return 0;
}
