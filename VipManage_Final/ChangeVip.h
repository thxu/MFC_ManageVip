#if !defined(AFX_CHANGEVIP_H__C3828D2D_BE7C_46A8_A7FB_A4EF7F2374A6__INCLUDED_)
#define AFX_CHANGEVIP_H__C3828D2D_BE7C_46A8_A7FB_A4EF7F2374A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChangeVip.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChangeVip dialog

class CChangeVip : public CDialog
{
// Construction
public:
	bool DoExecuteSQL(CString strSQL);
	void IniDlg(CString number,CString name,CString id,CString sex,CString jointime,CString hobby,CString level,CString picpath,CString remarks);
	CChangeVip(CWnd* pParent = NULL);   // standard constructor

	CString strPicPath_change;
	CDatabase m_database;
// Dialog Data
	//{{AFX_DATA(CChangeVip)
	enum { IDD = IDD_DlgChange };
	CStatic	m_Pic_PicPath_change;
	CComboBox	m_Combo_Level_change;
	CComboBox	m_Combo_Sex_change;
	CDateTimeCtrl	m_JoinTime_change;
	CString	m_Edit_Remarks_change;
	CString	m_Edit_Name_change;
	CString	m_Edit_ID_change;
	CString	m_Edit_Hobby_change;
	CString	m_Edit_Number_change;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChangeVip)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChangeVip)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnChangeVip();
	afx_msg void OnPicVipPicPathchange();
	afx_msg void OnBtnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANGEVIP_H__C3828D2D_BE7C_46A8_A7FB_A4EF7F2374A6__INCLUDED_)
