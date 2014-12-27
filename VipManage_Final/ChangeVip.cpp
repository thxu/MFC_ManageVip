// ChangeVip.cpp : implementation file
//

#include "stdafx.h"
#include "VipManage_Final.h"
#include "ChangeVip.h"

#include "SpliterDetailsView.h"
#include "SpliterTreeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChangeVip dialog

CChangeVip *pChange;

CChangeVip::CChangeVip(CWnd* pParent /*=NULL*/)
	: CDialog(CChangeVip::IDD, pParent)
{
	pChange=this;
	//{{AFX_DATA_INIT(CChangeVip)
	m_Edit_Remarks_change = _T("");
	m_Edit_Name_change = _T("");
	m_Edit_ID_change = _T("");
	m_Edit_Hobby_change = _T("");
	m_Edit_Number_change = _T("");
	//}}AFX_DATA_INIT
}


void CChangeVip::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChangeVip)
	DDX_Control(pDX, IDC_Pic_VipPicPath_change, m_Pic_PicPath_change);
	DDX_Control(pDX, IDC_Combo_VipLevel_change, m_Combo_Level_change);
	DDX_Control(pDX, IDC_Combo_VipSex_change, m_Combo_Sex_change);
	DDX_Control(pDX, IDC_Datetimepick_VipJoin_change, m_JoinTime_change);
	DDX_Text(pDX, IDC_Edit_VipRemarks_change, m_Edit_Remarks_change);
	DDX_Text(pDX, IDC_Edit_VipName_change, m_Edit_Name_change);
	DDX_Text(pDX, IDC_Edit_VipID_change, m_Edit_ID_change);
	DDX_Text(pDX, IDC_Edit_VipHobby_change, m_Edit_Hobby_change);
	DDX_Text(pDX, IDC_Edit_VipNumber_change, m_Edit_Number_change);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChangeVip, CDialog)
	//{{AFX_MSG_MAP(CChangeVip)
	ON_BN_CLICKED(IDC_Btn_ChangeVip, OnBtnChangeVip)
	ON_BN_CLICKED(IDC_Pic_VipPicPath_change, OnPicVipPicPathchange)
	ON_BN_CLICKED(IDC_BtnCancel, OnBtnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChangeVip message handlers

void CChangeVip::IniDlg(CString number, CString name, CString id, CString sex, CString jointime, CString hobby, CString level, CString picpath, CString remarks)
{

	
	m_Edit_Number_change=number;
	m_Edit_Name_change=name;
	m_Edit_ID_change=id;
	m_Edit_Hobby_change=hobby;
	strPicPath_change=picpath;
	m_Edit_Remarks_change=remarks;

	GetDlgItem(IDC_Edit_VipNumber_change)->SetWindowText(m_Edit_Number_change);
	GetDlgItem(IDC_Edit_VipName_change)->SetWindowText(m_Edit_Name_change);
	GetDlgItem(IDC_Edit_VipID_change)->SetWindowText(m_Edit_ID_change);
	GetDlgItem(IDC_Edit_VipHobby_change)->SetWindowText(m_Edit_Hobby_change);
	GetDlgItem(IDC_Edit_VipRemarks_change)->SetWindowText(m_Edit_Remarks_change);
	

	if (sex=="男")
	{
		m_Combo_Sex_change.SetCurSel(0);
	}
	else if (sex=="女")
	{
		m_Combo_Sex_change.SetCurSel(1);
	}

	if (level=="初级会员")
	{
		m_Combo_Level_change.SetCurSel(0);
	}
	else if (level=="高级会员")
	{
		m_Combo_Level_change.SetCurSel(1);
	}
	else if (level=="中级会员")
	{
		m_Combo_Level_change.SetCurSel(2);
	}

	CString strTime=jointime;
	int first=strTime.Find('-');
	int second=strTime.Find('-',first+1);
	int year=atoi(strTime.Left(4));
	int month=atoi(strTime.Mid(first+1,second-first+1));
	int day=atoi(strTime.Mid(second+1,strTime.GetLength()-second-1));
	CTime timetmp(year,month,day,0,0,0);
	m_JoinTime_change.SetTime(&timetmp);

	CStatic* pWnd = (CStatic*)GetDlgItem(IDC_Pic_VipPicPath_change); // 得到 Picture Control 句柄  
	pWnd->SetBitmap((HBITMAP)::LoadImage(NULL, strPicPath_change,   
		IMAGE_BITMAP,   
		160,   
		176,   
		LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE)); 
	

	UpdateData(FALSE);
}

BOOL CChangeVip::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString strSex="男";
	m_Combo_Sex_change.AddString(strSex);
	strSex="女";
	m_Combo_Sex_change.AddString(strSex);
	m_Combo_Sex_change.SetCurSel(0);

	CString strLevel="初级会员";
	m_Combo_Level_change.AddString(strLevel);
	strLevel="中级会员";
	m_Combo_Level_change.AddString(strLevel);
	strLevel="高级会员";
	m_Combo_Level_change.AddString(strLevel);
	m_Combo_Level_change.SetCurSel(0);

	CTime timetmp;
	timetmp.GetCurrentTime();
	m_JoinTime_change.SetTime(&timetmp);

	m_database.Open(_T("VipManage"));

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CChangeVip::OnBtnChangeVip() 
{
	// TODO: Add your control notification handler code here
	extern CSpliterDetailsView *pDetails;
	extern CSpliterTreeView *pTreeView;
	UpdateData(TRUE);
	if (m_Edit_ID_change=="")
	{
		MessageBox("身份证无效!");
		return;
	}

	CString strSex,strLevel,strTime;
	m_Combo_Sex_change.GetLBText(m_Combo_Sex_change.GetCurSel(),strSex);
	m_Combo_Level_change.GetLBText(m_Combo_Level_change.GetCurSel(),strLevel);
	
	CTime mytime;
	m_JoinTime_change.GetTime(mytime);
	strTime=mytime.Format("%Y-%m-%d");

	CString strsql;//="update VipUsers set"
	strsql.Format("update VipUsers set VipNumber='%s',VipName='%s',VipSex='%s',VipJoinTime='%s',VipHobby='%s',VipLevel='%s',VipPicPath='%s',VipRemarks='%s' where VipID='%s'",m_Edit_Number_change,m_Edit_Name_change,strSex,strTime,m_Edit_Hobby_change,strLevel,strPicPath_change,m_Edit_Remarks_change,m_Edit_ID_change);
	if(DoExecuteSQL(strsql))
	{
		MessageBox("修改成功!");
	}
	else
	{
		MessageBox("修改失败!");
	}
	pDetails->UpdateVip();
	pTreeView->UpdateVip();
	CDialog::OnOK();
}

void CChangeVip::OnPicVipPicPathchange() 
{
	// TODO: Add your control notification handler code here
	
	CFileDialog * myPicFiledlg;
	myPicFiledlg = new CFileDialog(TRUE,"","",OFN_FILEMUSTEXIST|OFN_HIDEREADONLY,"BMP文件(*.bmp)|*.bmp|JPG文件(*.jpg)|*.jpg||");
	myPicFiledlg->DoModal();
	strPicPath_change = myPicFiledlg->GetPathName();
	
	CStatic* pWnd = (CStatic*)GetDlgItem(IDC_Pic_VipPicPath_change); // 得到 Picture Control 句柄  
	pWnd->SetBitmap((HBITMAP)::LoadImage(NULL, strPicPath_change,   
		IMAGE_BITMAP,   
		160,   
		176,   
		LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE)); 
}

bool CChangeVip::DoExecuteSQL(CString strSQL)
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

void CChangeVip::OnBtnCancel() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}
