#if !defined(AFX_SPLITERTREEVIEW_H__AEFE4151_51DD_433B_8FBC_E475DB9D7759__INCLUDED_)
#define AFX_SPLITERTREEVIEW_H__AEFE4151_51DD_433B_8FBC_E475DB9D7759__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SpliterTreeView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSpliterTreeView view
#include "VipRecord.h"
#include <afxcview.h>
class CSpliterTreeView : public CTreeView
{
protected:
	CSpliterTreeView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CSpliterTreeView)

// Attributes
public:

// Operations
public:
	void UpdateVip();
	void ShowTheVip(int id);
	void DoSelect(CString strsql);

	VipRecord m_VipRec;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpliterTreeView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CSpliterTreeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CSpliterTreeView)
	afx_msg void OnClick(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPLITERTREEVIEW_H__AEFE4151_51DD_433B_8FBC_E475DB9D7759__INCLUDED_)
