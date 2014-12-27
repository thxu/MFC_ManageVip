// SpliterTreeView.cpp : implementation file
//

#include "stdafx.h"
#include "VipManage_Final.h"
#include "SpliterTreeView.h"

#include "SpliterManageView.h"
#include "SpliterDetailsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpliterTreeView
CSpliterTreeView *pTreeView;

IMPLEMENT_DYNCREATE(CSpliterTreeView, CTreeView)

CSpliterTreeView::CSpliterTreeView()
{
	pTreeView=this;
}

CSpliterTreeView::~CSpliterTreeView()
{
}


BEGIN_MESSAGE_MAP(CSpliterTreeView, CTreeView)
	//{{AFX_MSG_MAP(CSpliterTreeView)
	ON_NOTIFY_REFLECT(NM_CLICK, OnClick)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpliterTreeView drawing

void CSpliterTreeView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CSpliterTreeView diagnostics

#ifdef _DEBUG
void CSpliterTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CSpliterTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSpliterTreeView message handlers

void CSpliterTreeView::OnInitialUpdate() 
{
	CTreeView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class

	//树的初始化
	UpdateVip();

	

}

void CSpliterTreeView::DoSelect(CString strsql)
{
	CTreeCtrl& m_tree=GetTreeCtrl();
	m_tree.DeleteAllItems();
	//插入高级会员节点
	m_tree.ModifyStyle(0,TVS_HASBUTTONS|TVS_HASLINES|TVS_LINESATROOT|TVS_SHOWSELALWAYS);
	TV_INSERTSTRUCT SeniorVip;
	SeniorVip.hParent=TVI_ROOT;
	SeniorVip.hInsertAfter=TVI_LAST;
	SeniorVip.item.mask=TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;//设屏蔽
	SeniorVip.item.pszText="高级会员";
	HTREEITEM SeniorVipRoot=m_tree.InsertItem(&SeniorVip);
	
	//插入中级会员根节点
	TV_INSERTSTRUCT MidVip;
	MidVip.hParent=TVI_ROOT;
	MidVip.hInsertAfter=TVI_LAST;
	MidVip.item.mask=TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;//设屏蔽
	MidVip.item.pszText="中级会员";
	HTREEITEM MidVipRoot=m_tree.InsertItem(&MidVip);
	
	//插入初级会员节点
	TV_INSERTSTRUCT PriVip;
	PriVip.hParent=TVI_ROOT;
	PriVip.hInsertAfter=TVI_LAST;
	PriVip.item.mask=TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;//设屏蔽
	PriVip.item.pszText="初级会员";
	HTREEITEM PriVipRoot=m_tree.InsertItem(&PriVip);
	if (m_VipRec.IsOpen())
	{
		m_VipRec.Close();
	}
	try
	{
		if (!m_VipRec.Open(CRecordset::snapshot,strsql))
		{
			MessageBox("打开失败");
			return;
		}
	}
	catch (CMemoryException* e)
	{
		e->ReportError();
		return;
	}
	long num=m_VipRec.GetRecordCount();
	if (num>0)
	{
		m_VipRec.MoveFirst();
		while(!m_VipRec.IsEOF())
		{
			CString strName,strLevel;
			strName=m_VipRec.m_VipName;
			strLevel=m_VipRec.m_VipLevel;
			strName.TrimRight();
			strLevel.TrimRight();
			
			HTREEITEM hItem = m_tree.GetRootItem();
			while (strLevel!=m_tree.GetItemText(hItem))
			{
				hItem=m_tree.GetNextSiblingItem(hItem);
			}
			TV_INSERTSTRUCT tmppoint;
			tmppoint.hParent=hItem;
			tmppoint.hInsertAfter=TVI_LAST;
			tmppoint.item.mask=TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
			tmppoint.item.pszText=strName.GetBuffer(strName.GetLength());
			hItem=m_tree.InsertItem(&tmppoint);
			
			m_tree.SetItemData(hItem,m_VipRec.m_VipID);
			m_VipRec.MoveNext();
		}
	}
	m_tree.Expand(PriVipRoot,TVE_EXPAND);
	m_tree.Expand(MidVipRoot,TVE_EXPAND);
	m_tree.Expand(SeniorVipRoot,TVE_EXPAND);
	
}

void CSpliterTreeView::OnClick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	extern CSpliterDetailsView *pDetails;
	CTreeCtrl& m_tree=GetTreeCtrl();

	DWORD dwPos = GetMessagePos();
	CPoint pt( LOWORD(dwPos), HIWORD(dwPos) );     
	UINT   nFlags;     
	m_tree.ScreenToClient(&pt); 
	HTREEITEM   hItem = m_tree.HitTest(pt,&nFlags);	
	if (hItem)
	{
		int id=m_tree.GetItemData(hItem);
		
		pDetails->ShowTheVip(id);
	}

	*pResult = 0;
}

void CSpliterTreeView::ShowTheVip(int id)
{
	CTreeCtrl& m_tree=GetTreeCtrl();
	HTREEITEM hItem = m_tree.GetRootItem();
	int Rootcount=3;
	while (Rootcount--)
	{
		if (m_tree.ItemHasChildren(hItem))
		{
			HTREEITEM ChilehItem=m_tree.GetChildItem(hItem);
			while(ChilehItem!=NULL)
			{
				int tmp=m_tree.GetItemData(ChilehItem);
				if (id==tmp)
				{
					m_tree.SelectItem(ChilehItem);
					return;
				}
				else
				{
					ChilehItem=m_tree.GetNextItem(ChilehItem,TVGN_NEXT);
				}
			}
		}
		hItem=m_tree.GetNextSiblingItem(hItem);

	}


}

void CSpliterTreeView::UpdateVip()
{
	CString strSQL="select * from VipUsers";
	DoSelect(strSQL);
}
