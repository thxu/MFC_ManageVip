// SpliterManageView.cpp : implementation file
//

#include "stdafx.h"
#include "VipManage_Final.h"
#include "SpliterManageView.h"

#include "SpliterTreeView.h"
#include "SpliterDetailsView.h"

#include "ChangeVip.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpliterManageView
CSpliterManageView *pManage;

IMPLEMENT_DYNCREATE(CSpliterManageView, CFormView)

CSpliterManageView::CSpliterManageView()
	: CFormView(CSpliterManageView::IDD)
{
	pManage=this;
	//{{AFX_DATA_INIT(CSpliterManageView)
	m_Edit_VipHobby = _T("");
	m_Edit_VipID = _T("");
	m_Edit_VipName = _T("");
	m_Edit_VipNumber = _T("");
	m_Edit_VipRemarks = _T("");
	//}}AFX_DATA_INIT
}

CSpliterManageView::~CSpliterManageView()
{
}

void CSpliterManageView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSpliterManageView)
	DDX_Control(pDX, IDC_Pic_VipPic, m_Pic_VipPic);
	DDX_Control(pDX, IDC_Combo_VipLevel, m_Combo_VipLevel);
	DDX_Control(pDX, IDC_Datetimepick_VipJoin, m_Datetimepick_VipJoin);
	DDX_Control(pDX, IDC_Combo_VipSex, m_Combo_VipSex);
	DDX_Text(pDX, IDC_Edit_VipHobby, m_Edit_VipHobby);
	DDX_Text(pDX, IDC_Edit_VipID, m_Edit_VipID);
	DDX_Text(pDX, IDC_Edit_VipName, m_Edit_VipName);
	DDX_Text(pDX, IDC_Edit_VipNumber, m_Edit_VipNumber);
	DDX_Text(pDX, IDC_Edit_VipRemarks, m_Edit_VipRemarks);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSpliterManageView, CFormView)
	//{{AFX_MSG_MAP(CSpliterManageView)
	ON_BN_CLICKED(IDC_Btn_Add, OnBtnAdd)
	ON_BN_CLICKED(IDC_Btn_delete, OnBtndelete)
	ON_BN_CLICKED(IDC_Pic_VipPic, OnPicVipPic)
	ON_BN_CLICKED(IDC_Btn_Change, OnBtnChange)
	ON_BN_CLICKED(IDC_BtnShowAll, OnBtnShowAll)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpliterManageView diagnostics

#ifdef _DEBUG
void CSpliterManageView::AssertValid() const
{
	CFormView::AssertValid();
}

void CSpliterManageView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSpliterManageView message handlers

void CSpliterManageView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
// 	m_Edit_VipNumber="1";
// 	m_Edit_VipName="张三";
// 	m_Edit_VipID="123456789";
// 	m_Edit_VipHobby="篮球";
// 
// 	GetDlgItem(IDC_Edit_VipNumber)->SetWindowText(m_Edit_VipNumber);
// 	GetDlgItem(IDC_Edit_VipName)->SetWindowText(m_Edit_VipName);
// 	GetDlgItem(IDC_Edit_VipID)->SetWindowText(m_Edit_VipID);
// 	GetDlgItem(IDC_Edit_VipHobby)->SetWindowText(m_Edit_VipHobby);
	
	CString strTmp="男";
	m_Combo_VipSex.AddString(strTmp);
	strTmp="女";
	m_Combo_VipSex.AddString(strTmp);
	m_Combo_VipSex.SetCurSel(0);

	strTmp="初级会员";
	m_Combo_VipLevel.AddString(strTmp);
	strTmp="中级会员";
	m_Combo_VipLevel.AddString(strTmp);
	strTmp="高级会员";
	m_Combo_VipLevel.AddString(strTmp);
	m_Combo_VipLevel.SetCurSel(0);
	
	CTime TimeTemp=TimeTemp.GetCurrentTime();
 	m_Datetimepick_VipJoin.SetTime(&TimeTemp);

	/*显示图片*/
	m_Vip_PicPath=_T("D:\\mfc\\作业\\VipManage_Final\\MyImg\\Vip.bmp");
	CStatic* pWnd = (CStatic*)GetDlgItem(IDC_Pic_VipPic); // 得到 Picture Control 句柄  
	pWnd->SetBitmap((HBITMAP)::LoadImage(NULL, m_Vip_PicPath,   
		                IMAGE_BITMAP,   
		                160,   
		                176,   
		                LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE)); 


	m_database.Open(_T("VipManage"));
}

bool CSpliterManageView::DoExecuteSQL(CString strSQL)
{
	try
	{
		m_database.ExecuteSQL(strSQL);
		return true;
	}
	catch (CMemoryException* e)
	{
		e->ReportError();
		return false;
	}
}

void CSpliterManageView::OnBtnAdd() 
{
	// TODO: Add your control notification handler code here
	extern CSpliterDetailsView *pDetails;
	extern CSpliterTreeView *pTreeView;
	CTreeCtrl& m_tree=pTreeView->GetTreeCtrl();

	UpdateData(TRUE);
	if (m_Edit_VipNumber=="")
	{
		MessageBox("请输入会员号!");
		return;
	}
	if (m_Edit_VipName=="")
	{
		MessageBox("请输入会员姓名!");
		return;
	}
	if (m_Edit_VipID=="")
	{
		MessageBox("请输入会员身份证!");
		return;
	}
	if (m_Edit_VipHobby=="")
	{
		MessageBox("请输入会员爱好!");
		return;
	}

	
	CString strVipSex,strVipLevel;
	m_Combo_VipSex.GetLBText(m_Combo_VipSex.GetCurSel(),strVipSex);
	m_Combo_VipLevel.GetLBText(m_Combo_VipLevel.GetCurSel(),strVipLevel);

	CTime mytime;
	m_Datetimepick_VipJoin.GetTime(mytime);
	CString strVipJoinDate=mytime.Format("%Y-%m-%d");

	bool fond=false;
	CString strSQL;
	strSQL.Format("select * from VipUsers where VipID=%s",m_Edit_VipID);
	if (m_VipRec.IsOpen())
	{
		m_VipRec.Close();
	}
	m_VipRec.Open(CRecordset::snapshot,strSQL);
	int res=m_VipRec.GetRecordCount();
	if (res>0)
	{
		fond=true;/*数据库中已有该记录*/
	}
	
	if (!fond)
	{
		strSQL.Format("insert into VipUsers(VipNumber,VipName,VipID,VipSex,VipJoinTime,VipHobby,VipLevel,VipPicPath,VipRemarks) values('%s','%s','%s','%s','%s','%s','%s','%s','%s')",m_Edit_VipNumber,m_Edit_VipName,m_Edit_VipID,strVipSex,strVipJoinDate,m_Edit_VipHobby,strVipLevel,m_Vip_PicPath,m_Edit_VipRemarks);
		if (DoExecuteSQL(strSQL))
		{
			MessageBox("新增成功!");
			pDetails->UpdateVip();
			pTreeView->UpdateVip();
		}
		else
		{
			MessageBox("新增失败!");
		}
	}
	else
	{
		MessageBox("身份证重复了!");
	}

	
}

void CSpliterManageView::OnBtndelete() 
{
	// TODO: Add your control notification handler code here
	extern CSpliterDetailsView *pDetails;
	extern CSpliterTreeView *pTreeView;
	CTreeCtrl& m_tree=pTreeView->GetTreeCtrl();

	int delFlg=0;

	for (int i=0;i<pDetails->m_List_VipList.GetItemCount();i++)
	{
		if( pDetails->m_List_VipList.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED || pDetails->m_List_VipList.GetCheck(i))
		{
			CString strID=pDetails->m_List_VipList.GetItemText(i,2);
			CString strSQL;
			strSQL.Format("delete VipUsers where VipID=%s",strID);
			if(DoExecuteSQL(strSQL))
			{
				delFlg=1;
			}
		}
	}
	if (delFlg==1)
	{
		MessageBox("删除成功!");
	}
	
	pDetails->UpdateVip();
	pTreeView->UpdateVip();
	
}

void CSpliterManageView::OnPicVipPic() 
{
	// TODO: Add your control notification handler code here
	CFileDialog * myPicFiledlg;
	myPicFiledlg = new CFileDialog(TRUE,"","",OFN_FILEMUSTEXIST|OFN_HIDEREADONLY,"BMP文件(*.bmp)|*.bmp|JPG文件(*.jpg)|*.jpg||");
	myPicFiledlg->DoModal();
	m_Vip_PicPath = myPicFiledlg->GetPathName();

	CStatic* pWnd = (CStatic*)GetDlgItem(IDC_Pic_VipPic); // 得到 Picture Control 句柄  
	pWnd->SetBitmap((HBITMAP)::LoadImage(NULL, m_Vip_PicPath,   
		IMAGE_BITMAP,   
		160,   
		176,   
		LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE)); 
	

}

void CSpliterManageView::UpdataVipPic(CString PicPath)
{
	m_Vip_PicPath=PicPath;
	CStatic* pWnd = (CStatic*)GetDlgItem(IDC_Pic_VipPic); // 得到 Picture Control 句柄  
	pWnd->SetBitmap((HBITMAP)::LoadImage(NULL, m_Vip_PicPath,   
		IMAGE_BITMAP,   
		160,   
		176,   
		LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE)); 
}

void CSpliterManageView::OnBtnChange() 
{
	// TODO: Add your control notification handler code here
	extern CChangeVip *pChange;
	UpdateData(TRUE);
	CString strSex,strLevel,strTime;
	m_Combo_VipSex.GetLBText(m_Combo_VipSex.GetCurSel(),strSex);
	m_Combo_VipLevel.GetLBText(m_Combo_VipLevel.GetCurSel(),strLevel);
	
	CTime mytime;
	m_Datetimepick_VipJoin.GetTime(mytime);
	strTime=mytime.Format("%Y-%m-%d");

	CChangeVip *pMyChangeVip=new CChangeVip();
	pMyChangeVip->Create(IDD_DlgChange);
	pMyChangeVip->ShowWindow(SW_SHOWNORMAL);
	pChange->IniDlg(m_Edit_VipNumber,m_Edit_VipName,m_Edit_VipID,strSex,strTime,m_Edit_VipHobby,strLevel,m_Vip_PicPath,m_Edit_VipRemarks);

	
	
}

void CSpliterManageView::OnBtnShowAll() 
{
	// TODO: Add your control notification handler code here
	extern CSpliterDetailsView *pDetails;
	extern CSpliterTreeView *pTreeView;
	pDetails->UpdateVip();
	pTreeView->UpdateVip();
}
