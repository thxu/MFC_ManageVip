// VipManage_FinalDoc.h : interface of the CVipManage_FinalDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIPMANAGE_FINALDOC_H__D132E9FD_4DE0_4897_95DC_D1C739268484__INCLUDED_)
#define AFX_VIPMANAGE_FINALDOC_H__D132E9FD_4DE0_4897_95DC_D1C739268484__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CVipManage_FinalDoc : public CDocument
{
protected: // create from serialization only
	CVipManage_FinalDoc();
	DECLARE_DYNCREATE(CVipManage_FinalDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVipManage_FinalDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CVipManage_FinalDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CVipManage_FinalDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIPMANAGE_FINALDOC_H__D132E9FD_4DE0_4897_95DC_D1C739268484__INCLUDED_)
