// SpliterView.cpp : implementation file
//

#include "stdafx.h"
#include "VipManage_Final.h"
#include "SpliterView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpliterView

IMPLEMENT_DYNCREATE(CSpliterView, CView)

CSpliterView::CSpliterView()
{
}

CSpliterView::~CSpliterView()
{
}


BEGIN_MESSAGE_MAP(CSpliterView, CView)
	//{{AFX_MSG_MAP(CSpliterView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpliterView drawing

void CSpliterView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CSpliterView diagnostics

#ifdef _DEBUG
void CSpliterView::AssertValid() const
{
	CView::AssertValid();
}

void CSpliterView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSpliterView message handlers
