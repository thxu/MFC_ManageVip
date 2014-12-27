// VipManage_Final.h : main header file for the VIPMANAGE_FINAL application
//

#if !defined(AFX_VIPMANAGE_FINAL_H__8B9F7F77_18EE_4431_8BE6_69ABB18DF34C__INCLUDED_)
#define AFX_VIPMANAGE_FINAL_H__8B9F7F77_18EE_4431_8BE6_69ABB18DF34C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CVipManage_FinalApp:
// See VipManage_Final.cpp for the implementation of this class
//

class CVipManage_FinalApp : public CWinApp
{
public:
	CVipManage_FinalApp();
	CMultiDocTemplate* pSpliterDocTemplate;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVipManage_FinalApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CVipManage_FinalApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIPMANAGE_FINAL_H__8B9F7F77_18EE_4431_8BE6_69ABB18DF34C__INCLUDED_)
