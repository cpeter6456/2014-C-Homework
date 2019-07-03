///-----------------------------------------------------------------
///
/// @file      b013040033hw7-2Frm.h
/// @author    user
/// Created:   2013/12/30 ¤U¤È 11:08:35
/// @section   DESCRIPTION
///            b013040033hw7_2Frm class declaration
///
///------------------------------------------------------------------

#ifndef __B013040033HW7_2FRM_H__
#define __B013040033HW7_2FRM_H__

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
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
////Header Include End

////Dialog Style Start
#undef b013040033hw7_2Frm_STYLE
#define b013040033hw7_2Frm_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class b013040033hw7_2Frm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		void WxEdit1Updated(wxCommandEvent& event);
		b013040033hw7_2Frm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("b013040033hw7-2"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = b013040033hw7_2Frm_STYLE);
		virtual ~b013040033hw7_2Frm();
		void WxButton1Click(wxCommandEvent& event);
		void btnCompressClick(wxCommandEvent& event);
		void btnUncompressClick(wxCommandEvent& event);
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxStaticText *WxStaticText2;
		wxStaticText *WxStaticText1;
		wxTextCtrl *editOutputFile;
		wxTextCtrl *editInputFile;
		wxButton *btnUncompress;
		wxButton *btnCompress;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXSTATICTEXT2 = 1006,
			ID_WXSTATICTEXT1 = 1005,
			ID_WXEDIT2 = 1004,
			ID_WXEDIT1 = 1003,
			ID_WXBUTTON2 = 1002,
			ID_WXBUTTON1 = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
