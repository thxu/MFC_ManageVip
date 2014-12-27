// SpliterDetailsView.cpp : implementation file
//

#include "stdafx.h"
#include "VipManage_Final.h"
#include "SpliterDetailsView.h"

#include "SpliterManageView.h"
#include "SpliterTreeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpliterDetailsView
CSpliterDetailsView *pDetails;

IMPLEMENT_DYNCREATE(CSpliterDetailsView, CFormView)

CSpliterDetailsView::CSpliterDetailsView()
	: CFormView(CSpliterDetailsView::IDD)
{
	pDetails=this;
	//{{AFX_DATA_INIT(CSpliterDetailsView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CSpliterDetailsView::~CSpliterDetailsView()
{
}

void CSpliterDetailsView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSpliterDetailsView)
	DDX_Control(pDX, IDC_List_VipList, m_List_VipList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSpliterDetailsView, CFormView)
	//{{AFX_MSG_MAP(CSpliterDetailsView)
	ON_NOTIFY(NM_CLICK, IDC_List_VipList, OnClickListVipList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpliterDetailsView diagnostics

#ifdef _DEBUG
void CSpliterDetailsView::AssertValid() const
{
	CFormView::AssertValid();
}

void CSpliterDetailsView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSpliterDetailsView message handlers

void CSpliterDetailsView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	
	//list ctrl 初始化
	LONG lStyle;
	lStyle = GetWindowLong(m_List_VipList.m_hWnd, GWL_STYLE);//获取当前窗口style
	lStyle &= ~LVS_TYPEMASK; //清除显示方式位
	lStyle |= LVS_REPORT; //设置style
    SetWindowLong(m_List_VipList.m_hWnd, GWL_STYLE, lStyle);//设置style
	
	DWORD extStyle=m_List_VipList.GetExtendedStyle();
	extStyle |=LVS_EX_FULLROWSELECT;//选中某行使整行高亮（只适用与report风格）	
	extStyle |= LVS_EX_GRIDLINES;       //网格线（只适用与report风格	
	extStyle |=LVS_EX_CHECKBOXES;  //item前生成CheckBox控件
	m_List_VipList.SetExtendedStyle(extStyle);
	m_List_VipList.InsertColumn(0,"会员号",LVCFMT_LEFT);
	m_List_VipList.SetColumnWidth(0,60);
	m_List_VipList.InsertColumn(1,"姓名",LVCFMT_CENTER,100);
	m_List_VipList.InsertColumn(2,"身份证号",LVCFMT_CENTER,170);
	m_List_VipList.InsertColumn(3,"性别",LVCFMT_CENTER,50);
	m_List_VipList.InsertColumn(4,"入会时间",LVCFMT_CENTER,120);
   	m_List_VipList.InsertColumn(5,"爱好",LVCFMT_LEFT,100);
	m_List_VipList.InsertColumn(6,"会员等级",LVCFMT_LEFT,150);
	m_List_VipList.InsertColumn(7,"备注",LVCFMT_LEFT,150);

	UpdateVip();

}

void CSpliterDetailsView::DoSelect(CString strsql)
{
	m_List_VipList.DeleteAllItems();
	if (m_VipRec.IsOpen())
	{
		m_VipRec.Close();
	}
	try
	{
		if (!m_VipRec.Open(CRecordset::snapshot,strsql))
		{
			MessageBox("open defeat");
			return;
		}
	}
	catch (CMemoryException* e)
	{
		e->ReportError();
	}
	int nIndex=0;    //列表视图指向第1行

	long num=m_VipRec.GetRecordCount();
	if (num>0)
	{
		m_VipRec.MoveFirst();   //记录指针指向第1条记录
		while(!m_VipRec.IsEOF())    
		{
			CString number,id,jointime;
			number.Format("%d",m_VipRec.m_VipNumber);
			id.Format("%d",m_VipRec.m_VipID);
			jointime=m_VipRec.m_VipJoinTime.Format("%Y-%m-%d");
			
			/*去掉空格*/
			CString name,sex,hobby,level,remarks;
			name=m_VipRec.m_VipName;
			sex=m_VipRec.m_VipSex;
			hobby=m_VipRec.m_VipHobby;
			level=m_VipRec.m_VipLevel;
			remarks=m_VipRec.m_VipRemarks;
			name.TrimRight();
			sex.TrimRight();
			hobby.TrimRight();
			level.TrimRight();
			remarks.TrimRight();
			
			
			LV_ITEM lvItem;
			lvItem.mask=LVIF_TEXT;
			lvItem.iItem=nIndex;   //行
			lvItem.iSubItem=0;    //列	
			lvItem.pszText="";
			m_List_VipList.InsertItem(&lvItem);
			
			DWORD d=m_VipRec.m_VipID;
			m_List_VipList.SetItemData(nIndex,d);
			
			m_List_VipList.SetItemText(nIndex,0,number);
			m_List_VipList.SetItemText(nIndex,1,name);
			m_List_VipList.SetItemText(nIndex,2,id);
			m_List_VipList.SetItemText(nIndex,3,sex);
			m_List_VipList.SetItemText(nIndex,4,jointime);
			m_List_VipList.SetItemText(nIndex,5,hobby);
			m_List_VipList.SetItemText(nIndex,6,level);
			m_List_VipList.SetItemText(nIndex,7,remarks);
			
			
			m_VipRec.MoveNext();
			nIndex++;
		}
	}
	

}

void CSpliterDetailsView::UpdateVip()
{
	CString strSQL="select * from VipUsers";
	DoSelect(strSQL);
}

void CSpliterDetailsView::OnClickListVipList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	extern CSpliterManageView *pManage;
	extern CSpliterTreeView *pTreeView;
	CTreeCtrl& m_tree=pTreeView->GetTreeCtrl();

	DWORD dwPos = GetMessagePos();
	CPoint point( LOWORD(dwPos), HIWORD(dwPos) );

	m_List_VipList.ScreenToClient(&point);
	
	LVHITTESTINFO lvinfo;
	lvinfo.pt = point;
	lvinfo.flags = LVHT_ABOVE;	
    int nItem = m_List_VipList.SubItemHitTest(&lvinfo);
	if (nItem!=-1)//把在listcontrol里面选中的用户的信息在面板上更新
	{
		ShowDetailOnManage(nItem);
		int id=m_List_VipList.GetItemData(nItem);
		pTreeView->ShowTheVip(id);
	}


	*pResult = 0;
}

void CSpliterDetailsView::ShowTheVip(int id)
{
	UpdateVip();
	for (int i=0;i<m_List_VipList.GetItemCount();i++)
	{
		if (m_List_VipList.GetItemState(i,LVIS_SELECTED)== LVIS_SELECTED||m_List_VipList.GetCheck(i))
		{
			m_List_VipList.SetItemState(i,0,LVIS_SELECTED|LVIS_FOCUSED|LVIS_DROPHILITED);
		}
	}
	for (int j=0;j<m_List_VipList.GetItemCount();j++)
	{
		int tmpid=m_List_VipList.GetItemData(j);
		if (tmpid==id)
		{
			m_List_VipList.SetItemState(j,LVIS_SELECTED|LVIS_FOCUSED,LVIS_SELECTED|LVIS_FOCUSED|LVIS_DROPHILITED);
			m_List_VipList.SetFocus();
		
			ShowDetailOnManage(j);
			return;
		}
	}
		
}

void CSpliterDetailsView::ShowDetailOnManage(int nItem)
{
	extern CSpliterManageView *pManage;

	pManage->m_Edit_VipNumber=m_List_VipList.GetItemText(nItem,0);
	pManage->m_Edit_VipName=m_List_VipList.GetItemText(nItem,1);
	pManage->m_Edit_VipID=m_List_VipList.GetItemText(nItem,2);
	pManage->m_Edit_VipHobby=m_List_VipList.GetItemText(nItem,5);
	pManage->m_Edit_VipRemarks=m_List_VipList.GetItemText(nItem,7);
	
	CString strSex=m_List_VipList.GetItemText(nItem,3);
	strSex.TrimRight();
	if (strSex=="男")
	{
		pManage->m_Combo_VipSex.SetCurSel(0);
		pManage->GetDlgItem(IDC_Combo_VipSex);
	}
	else if(strSex=="女")
	{
		pManage->m_Combo_VipSex.SetCurSel(1);
	}
	
	CString strLevel=m_List_VipList.GetItemText(nItem,6);
	strLevel.TrimRight();
	if (strLevel=="初级会员")
	{
		pManage->m_Combo_VipLevel.SetCurSel(0);
	}
	else if (strLevel=="中级会员")
	{
		pManage->m_Combo_VipLevel.SetCurSel(2);
	}
	else if(strLevel=="高级会员")
	{
		pManage->m_Combo_VipLevel.SetCurSel(1);
	}
	
	CString strTime=m_List_VipList.GetItemText(nItem,4);
	int first=strTime.Find('-');
	int second=strTime.Find('-',first+1);
	int year=atoi(strTime.Left(4));
	int month=atoi(strTime.Mid(first+1,second-first+1));
	int day=atoi(strTime.Mid(second+1,strTime.GetLength()-second-1));
	CTime timetmp(year,month,day,0,0,0);
	pManage->m_Datetimepick_VipJoin.SetTime(&timetmp);
	
	/*显示会员图片*/
	CString strSQL;
	strSQL.Format("select * from VipUsers where VipID='%s'",m_List_VipList.GetItemText(nItem,2));
	if (m_VipRec.IsOpen())
	{
		m_VipRec.Close();
	}
	try
	{
		m_VipRec.Open(CRecordset::snapshot,strSQL);
		m_VipRec.MoveFirst();
		pManage->UpdataVipPic(m_VipRec.m_VipPicPath);
	}
	catch (CMemoryException* e)
	{
		e->ReportError();
	}
	
	pManage->UpdateData(FALSE);

}
