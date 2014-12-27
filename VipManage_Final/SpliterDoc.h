#if !defined(AFX_SPLITERDOC_H__DA270AFF_DF71_4AD1_A0CE_AA1E7E24B0BE__INCLUDED_)
#define AFX_SPLITERDOC_H__DA270AFF_DF71_4AD1_A0CE_AA1E7E24B0BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SpliterDoc.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSpliterDoc document

class CSpliterDoc : public CDocument
{
protected:
	CSpliterDoc();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CSpliterDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpliterDoc)
	public:
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
	protected:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSpliterDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CSpliterDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPLITERDOC_H__DA270AFF_DF71_4AD1_A0CE_AA1E7E24B0BE__INCLUDED_)
