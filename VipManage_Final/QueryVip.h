#if !defined(AFX_QUERYVIP_H__C8200470_A98D_4141_A32E_0C865F235D8F__INCLUDED_)
#define AFX_QUERYVIP_H__C8200470_A98D_4141_A32E_0C865F235D8F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// QueryVip.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CQueryVip dialog

class CQueryVip : public CDialog
{
// Construction
public:
	CQueryVip(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CQueryVip)
	enum { IDD = IDD_DlgVipQuery };
	CDateTimeCtrl	m_Date_JoinTime_Query;
	CComboBox	m_ComboSex_Query;
	CComboBox	m_Combo_Level_Query;
	CString	m_Edit_ID_Query;
	CString	m_EditHobby_Query;
	CString	m_EditName_Query;
	CString	m_EditNumber_Query;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQueryVip)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CQueryVip)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnSelectByNumber();
	afx_msg void OnBtnSelectByName();
	afx_msg void OnBtnSelectByID();
	afx_msg void OnBtnSelectBySex();
	afx_msg void OnBtnSelectByJoinTime();
	afx_msg void OnBtnSelectByHobby();
	afx_msg void OnBtnSelectByLevel();
	afx_msg void OnBtnQuery();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUERYVIP_H__C8200470_A98D_4141_A32E_0C865F235D8F__INCLUDED_)
