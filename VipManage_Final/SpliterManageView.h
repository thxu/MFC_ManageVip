#if !defined(AFX_SPLITERMANAGEVIEW_H__F5568853_886D_408D_BF15_C31A606B12FB__INCLUDED_)
#define AFX_SPLITERMANAGEVIEW_H__F5568853_886D_408D_BF15_C31A606B12FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SpliterManageView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSpliterManageView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

#include "VipRecord.h"

class CSpliterManageView : public CFormView
{
protected:
	CSpliterManageView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CSpliterManageView)

// Form Data
public:
	//{{AFX_DATA(CSpliterManageView)
	enum { IDD = IDD_Manage };
	CStatic	m_Pic_VipPic;
	CComboBox	m_Combo_VipLevel;
	CDateTimeCtrl	m_Datetimepick_VipJoin;
	CComboBox	m_Combo_VipSex;
	CString	m_Edit_VipHobby;
	CString	m_Edit_VipID;
	CString	m_Edit_VipName;
	CString	m_Edit_VipNumber;
	CString	m_Edit_VipRemarks;
	//}}AFX_DATA

// Attributes
public:
	VipRecord m_VipRec;
	CDatabase m_database;

	CString m_Vip_PicPath;


// Operations
public:
	void UpdataVipPic(CString PicPath);
	bool DoExecuteSQL(CString strSQL);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpliterManageView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CSpliterManageView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CSpliterManageView)
	afx_msg void OnBtnAdd();
	afx_msg void OnBtndelete();
	afx_msg void OnPicVipPic();
	afx_msg void OnBtnChange();
	afx_msg void OnBtnShowAll();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPLITERMANAGEVIEW_H__F5568853_886D_408D_BF15_C31A606B12FB__INCLUDED_)
