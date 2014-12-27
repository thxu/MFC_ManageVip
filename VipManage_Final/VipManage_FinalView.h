// VipManage_FinalView.h : interface of the CVipManage_FinalView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIPMANAGE_FINALVIEW_H__485D6CD8_B359_454F_94D2_28F5394909B2__INCLUDED_)
#define AFX_VIPMANAGE_FINALVIEW_H__485D6CD8_B359_454F_94D2_28F5394909B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CVipManage_FinalView : public CView
{
protected: // create from serialization only
	CVipManage_FinalView();
	DECLARE_DYNCREATE(CVipManage_FinalView)

// Attributes
public:
	CVipManage_FinalDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVipManage_FinalView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CVipManage_FinalView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CVipManage_FinalView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in VipManage_FinalView.cpp
inline CVipManage_FinalDoc* CVipManage_FinalView::GetDocument()
   { return (CVipManage_FinalDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIPMANAGE_FINALVIEW_H__485D6CD8_B359_454F_94D2_28F5394909B2__INCLUDED_)
