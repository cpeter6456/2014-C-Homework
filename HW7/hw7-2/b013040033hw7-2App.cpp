//---------------------------------------------------------------------------
//
// Name:        b013040033hw7-2App.cpp
// Author:      user
// Created:     2013/12/30 ¤U¤È 11:08:35
// Description: 
//
//---------------------------------------------------------------------------

#include "b013040033hw7-2App.h"
#include "b013040033hw7-2Frm.h"

IMPLEMENT_APP(b013040033hw7_2FrmApp)

bool b013040033hw7_2FrmApp::OnInit()
{
    b013040033hw7_2Frm* frame = new b013040033hw7_2Frm(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int b013040033hw7_2FrmApp::OnExit()
{
	return 0;
}
