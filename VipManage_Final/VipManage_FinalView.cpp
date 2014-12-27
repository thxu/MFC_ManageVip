// VipManage_FinalView.cpp : implementation of the CVipManage_FinalView class
//

#include "stdafx.h"
#include "VipManage_Final.h"

#include "VipManage_FinalDoc.h"
#include "VipManage_FinalView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVipManage_FinalView

IMPLEMENT_DYNCREATE(CVipManage_FinalView, CView)

BEGIN_MESSAGE_MAP(CVipManage_FinalView, CView)
	//{{AFX_MSG_MAP(CVipManage_FinalView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVipManage_FinalView construction/destruction

CVipManage_FinalView::CVipManage_FinalView()
{
	// TODO: add construction code here

}

CVipManage_FinalView::~CVipManage_FinalView()
{
}

BOOL CVipManage_FinalView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CVipManage_FinalView drawing

void CVipManage_FinalView::OnDraw(CDC* pDC)
{
	CVipManage_FinalDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CVipManage_FinalView printing

BOOL CVipManage_FinalView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CVipManage_FinalView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CVipManage_FinalView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CVipManage_FinalView diagnostics

#ifdef _DEBUG
void CVipManage_FinalView::AssertValid() const
{
	CView::AssertValid();
}

void CVipManage_FinalView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CVipManage_FinalDoc* CVipManage_FinalView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVipManage_FinalDoc)));
	return (CVipManage_FinalDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CVipManage_FinalView message handlers
