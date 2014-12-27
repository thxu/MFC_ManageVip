// SpliterChildFrame.cpp : implementation file
//

#include "stdafx.h"
#include "VipManage_Final.h"
#include "SpliterChildFrame.h"

#include "SpliterView.h"
#include "SpliterTreeView.h"
#include "SpliterManageView.h"
#include "SpliterDoc.h"
#include "SpliterDetailsView.h"
#include "SpliterChildFrame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpliterChildFrame

IMPLEMENT_DYNCREATE(CSpliterChildFrame, CMDIChildWnd)

CSpliterChildFrame::CSpliterChildFrame()
{
}

CSpliterChildFrame::~CSpliterChildFrame()
{
}


BEGIN_MESSAGE_MAP(CSpliterChildFrame, CMDIChildWnd)
	//{{AFX_MSG_MAP(CSpliterChildFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpliterChildFrame message handlers

BOOL CSpliterChildFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	if (!m_wndSplitter.CreateStatic(this,1,2))
	{
		TRACE0("can't create spliiter");
		return FALSE;
	}
	if (!m_wndSplitter.CreateView(0,0,RUNTIME_CLASS(CSpliterTreeView),CSize(200,50),pContext))
	{
		TRACE0("can't create treeView");
		return FALSE;
	}
	if (!m_wndSplitter1.CreateStatic(&m_wndSplitter,2,1,WS_CHILD | WS_VISIBLE | WS_BORDER,m_wndSplitter.IdFromRowCol(0,1)))
	{
		TRACE0("Failed to create nested splitter\n");
		return FALSE;
	}
	if (!m_wndSplitter1.CreateView(0,0,RUNTIME_CLASS(CSpliterManageView),CSize(0,400),pContext))
	{
		TRACE0("Failed to create nested splitter\n");
		return FALSE;
	}
	if (!m_wndSplitter1.CreateView(1,0,RUNTIME_CLASS(CSpliterDetailsView),CSize(0,0),pContext))
	{
		TRACE0("Failed to create nested splitter\n");
		return FALSE;
	}

	//return CMDIChildWnd::OnCreateClient(lpcs, pContext);
}

BOOL CSpliterChildFrame::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: Add your specialized code here and/or call the base class
	cs.style |= WS_VISIBLE|WS_MAXIMIZE;
	return CMDIChildWnd::PreCreateWindow(cs);
}
