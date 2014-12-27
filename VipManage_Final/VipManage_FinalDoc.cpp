// VipManage_FinalDoc.cpp : implementation of the CVipManage_FinalDoc class
//

#include "stdafx.h"
#include "VipManage_Final.h"

#include "VipManage_FinalDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVipManage_FinalDoc

IMPLEMENT_DYNCREATE(CVipManage_FinalDoc, CDocument)

BEGIN_MESSAGE_MAP(CVipManage_FinalDoc, CDocument)
	//{{AFX_MSG_MAP(CVipManage_FinalDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVipManage_FinalDoc construction/destruction

CVipManage_FinalDoc::CVipManage_FinalDoc()
{
	// TODO: add one-time construction code here

}

CVipManage_FinalDoc::~CVipManage_FinalDoc()
{
}

BOOL CVipManage_FinalDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CVipManage_FinalDoc serialization

void CVipManage_FinalDoc::Serialize(CArchive& ar)
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
// CVipManage_FinalDoc diagnostics

#ifdef _DEBUG
void CVipManage_FinalDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CVipManage_FinalDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CVipManage_FinalDoc commands
