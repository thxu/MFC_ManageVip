// SpliterDoc.cpp : implementation file
//

#include "stdafx.h"
#include "VipManage_Final.h"
#include "SpliterDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpliterDoc

IMPLEMENT_DYNCREATE(CSpliterDoc, CDocument)

CSpliterDoc::CSpliterDoc()
{
}

BOOL CSpliterDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CSpliterDoc::~CSpliterDoc()
{
}


BEGIN_MESSAGE_MAP(CSpliterDoc, CDocument)
	//{{AFX_MSG_MAP(CSpliterDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpliterDoc diagnostics

#ifdef _DEBUG
void CSpliterDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSpliterDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSpliterDoc serialization

void CSpliterDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSpliterDoc commands
