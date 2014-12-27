#if !defined(AFX_SPLITERCHILDFRAME_H__30FB9BBB_34E2_4583_8EB5_2F6B6F66DAF1__INCLUDED_)
#define AFX_SPLITERCHILDFRAME_H__30FB9BBB_34E2_4583_8EB5_2F6B6F66DAF1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SpliterChildFrame.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSpliterChildFrame frame

class CSpliterChildFrame : public CMDIChildWnd
{
	DECLARE_DYNCREATE(CSpliterChildFrame)
protected:
	CSpliterChildFrame();           // protected constructor used by dynamic creation

// Attributes
public:

	CSplitterWnd m_wndSplitter;
	CSplitterWnd m_wndSplitter1;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpliterChildFrame)
	protected:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CSpliterChildFrame();

	// Generated message map functions
	//{{AFX_MSG(CSpliterChildFrame)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPLITERCHILDFRAME_H__30FB9BBB_34E2_4583_8EB5_2F6B6F66DAF1__INCLUDED_)
