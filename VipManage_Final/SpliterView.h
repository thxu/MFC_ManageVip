#if !defined(AFX_SPLITERVIEW_H__AB7E9139_7A01_4C60_9B5D_1CEDA051E2AE__INCLUDED_)
#define AFX_SPLITERVIEW_H__AB7E9139_7A01_4C60_9B5D_1CEDA051E2AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SpliterView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSpliterView view

class CSpliterView : public CView
{
protected:
	CSpliterView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CSpliterView)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpliterView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CSpliterView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CSpliterView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPLITERVIEW_H__AB7E9139_7A01_4C60_9B5D_1CEDA051E2AE__INCLUDED_)
