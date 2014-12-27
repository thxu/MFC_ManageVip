#if !defined(AFX_SPLITERDETAILSVIEW_H__ABEB7BC3_5009_495A_BF58_5A903B6DEA0E__INCLUDED_)
#define AFX_SPLITERDETAILSVIEW_H__ABEB7BC3_5009_495A_BF58_5A903B6DEA0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SpliterDetailsView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSpliterDetailsView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

#include "VipRecord.h"
class CSpliterDetailsView : public CFormView
{
protected:
	CSpliterDetailsView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CSpliterDetailsView)

// Form Data
public:
	//{{AFX_DATA(CSpliterDetailsView)
	enum { IDD = IDD_Details };
	CListCtrl	m_List_VipList;
	//}}AFX_DATA

// Attributes
public:
	VipRecord m_VipRec;

// Operations
public:
	void ShowDetailOnManage(int nItem);
	void ShowTheVip(int id);
	void UpdateVip();
	void DoSelect(CString strsql);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpliterDetailsView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CSpliterDetailsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CSpliterDetailsView)
	afx_msg void OnClickListVipList(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPLITERDETAILSVIEW_H__ABEB7BC3_5009_495A_BF58_5A903B6DEA0E__INCLUDED_)
