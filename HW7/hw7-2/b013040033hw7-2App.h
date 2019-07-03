//---------------------------------------------------------------------------
//
// Name:        b013040033hw7-2App.h
// Author:      user
// Created:     2013/12/30 ¤U¤È 11:08:35
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __B013040033HW7_2FRMApp_h__
#define __B013040033HW7_2FRMApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class b013040033hw7_2FrmApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
