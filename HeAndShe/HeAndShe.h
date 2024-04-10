
// HeAndShe.h : main header file for the HeAndShe application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CHeAndSheApp:
// See HeAndShe.cpp for the implementation of this class
//

class CHeAndSheApp : public CWinApp
{
public:
	CHeAndSheApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CHeAndSheApp theApp;
