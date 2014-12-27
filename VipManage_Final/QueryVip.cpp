// QueryVip.cpp : implementation file
//

#include "stdafx.h"
#include "VipManage_Final.h"
#include "QueryVip.h"

#include "SpliterDetailsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQueryVip dialog


CQueryVip::CQueryVip(CWnd* pParent /*=NULL*/)
	: CDialog(CQueryVip::IDD, pParent)
{
	//{{AFX_DATA_INIT(CQueryVip)
	m_Edit_ID_Query = _T("");
	m_EditHobby_Query = _T("");
	m_EditName_Query = _T("");
	m_EditNumber_Query = _T("");
	//}}AFX_DATA_INIT
}


void CQueryVip::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQueryVip)
	DDX_Control(pDX, IDC_Datetimepick, m_Date_JoinTime_Query);
	DDX_Control(pDX, IDC_ComboSex, m_ComboSex_Query);
	DDX_Control(pDX, IDC_Combo_Level, m_Combo_Level_Query);
	DDX_Text(pDX, IDC_Edit_ID, m_Edit_ID_Query);
	DDX_Text(pDX, IDC_EditHobby, m_EditHobby_Query);
	DDX_Text(pDX, IDC_EditName, m_EditName_Query);
	DDX_Text(pDX, IDC_EditNumber, m_EditNumber_Query);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CQueryVip, CDialog)
	//{{AFX_MSG_MAP(CQueryVip)
	ON_BN_CLICKED(IDC_BtnSelectByNumber, OnBtnSelectByNumber)
	ON_BN_CLICKED(IDC_BtnSelectByName, OnBtnSelectByName)
	ON_BN_CLICKED(IDC_BtnSelectByID, OnBtnSelectByID)
	ON_BN_CLICKED(IDC_BtnSelectBySex, OnBtnSelectBySex)
	ON_BN_CLICKED(IDC_BtnSelectByJoinTime, OnBtnSelectByJoinTime)
	ON_BN_CLICKED(IDC_BtnSelectByHobby, OnBtnSelectByHobby)
	ON_BN_CLICKED(IDC_BtnSelectByLevel, OnBtnSelectByLevel)
	ON_BN_CLICKED(IDC_BtnQuery, OnBtnQuery)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQueryVip message handlers

BOOL CQueryVip::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	

	CString strSex="男";
	m_ComboSex_Query.AddString(strSex);
	strSex="女";
	m_ComboSex_Query.AddString(strSex);
	m_ComboSex_Query.SetCurSel(0);
	
	CString strLevel="初级会员";
	m_Combo_Level_Query.AddString(strLevel);
	strLevel="中级会员";
	m_Combo_Level_Query.AddString(strLevel);
	strLevel="高级会员";
	m_Combo_Level_Query.AddString(strLevel);
	m_Combo_Level_Query.SetCurSel(0);
	
	CTime timetmp;
	timetmp.GetCurrentTime();
	m_Date_JoinTime_Query.SetTime(&timetmp);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CQueryVip::OnBtnSelectByNumber() 
{
	// TODO: Add your control notification handler code here
	extern CSpliterDetailsView *pDetails;

	UpdateData(TRUE);
	if (m_EditNumber_Query=="")
	{
		MessageBox("请输入会员号!");
		return;
	}
	CString strsql;
	strsql.Format("select * from VipUsers where VipNumber='%s'",m_EditNumber_Query);
	pDetails->DoSelect(strsql);
	CDialog::OnOK();
	
}

void CQueryVip::OnBtnSelectByName() 
{
	// TODO: Add your control notification handler code here
	extern CSpliterDetailsView *pDetails;
	
	UpdateData(TRUE);
	if (m_EditName_Query=="")
	{
		MessageBox("请输入会员姓名!");
		return;
	}
	CString strsql;
	strsql.Format("select * from VipUsers where VipName='%s'",m_EditName_Query);
	pDetails->DoSelect(strsql);
	CDialog::OnOK();
}

void CQueryVip::OnBtnSelectByID() 
{
	// TODO: Add your control notification handler code here
	extern CSpliterDetailsView *pDetails;
	
	UpdateData(TRUE);
	if (m_Edit_ID_Query=="")
	{
		MessageBox("请输入会员身份证!");
		return;
	}
	CString strsql;
	strsql.Format("select * from VipUsers where VipID='%s'",m_Edit_ID_Query);
	pDetails->DoSelect(strsql);
	CDialog::OnOK();
}

void CQueryVip::OnBtnSelectBySex() 
{
	// TODO: Add your control notification handler code here
	extern CSpliterDetailsView *pDetails;
	
	UpdateData(TRUE);
	CString strVipSex;
	m_ComboSex_Query.GetLBText(m_ComboSex_Query.GetCurSel(),strVipSex);

	CString strsql;
	strsql.Format("select * from VipUsers where VipSex='%s'",strVipSex);
	pDetails->DoSelect(strsql);
	CDialog::OnOK();
}

void CQueryVip::OnBtnSelectByJoinTime() 
{
	// TODO: Add your control notification handler code here
	extern CSpliterDetailsView *pDetails;
	
	UpdateData(TRUE);
	CTime mytime;
	m_Date_JoinTime_Query.GetTime(mytime);
	CString strVipJoinDate=mytime.Format("%Y-%m-%d");

	CString strsql;
	strsql.Format("select * from VipUsers where VipJoinTime='%s'",strVipJoinDate);
	pDetails->DoSelect(strsql);
	CDialog::OnOK();
}

void CQueryVip::OnBtnSelectByHobby() 
{
	// TODO: Add your control notification handler code here
	extern CSpliterDetailsView *pDetails;
	
	UpdateData(TRUE);
	if (m_EditHobby_Query=="")
	{
		MessageBox("请输入会员爱好!");
		return;
	}
	CString strsql;
	strsql.Format("select * from VipUsers where VipHobby='%s'",m_EditHobby_Query);
	pDetails->DoSelect(strsql);
	CDialog::OnOK();
}

void CQueryVip::OnBtnSelectByLevel() 
{
	// TODO: Add your control notification handler code here
	extern CSpliterDetailsView *pDetails;
	
	UpdateData(TRUE);
	CString strVipLevel;
	m_Combo_Level_Query.GetLBText(m_Combo_Level_Query.GetCurSel(),strVipLevel);
	
	CString strsql;
	strsql.Format("select * from VipUsers where VipLevel='%s'",strVipLevel);
	pDetails->DoSelect(strsql);
	CDialog::OnOK();
}

void CQueryVip::OnBtnQuery() 
{
	// TODO: Add your control notification handler code here
	extern CSpliterDetailsView *pDetails;
	
	UpdateData(TRUE);
	if (m_EditNumber_Query=="")
	{
		MessageBox("请输入会员号!");
		return;
	}
	if (m_EditName_Query=="")
	{
		MessageBox("请输入会员姓名!");
		return;
	}
	if (m_Edit_ID_Query=="")
	{
		MessageBox("请输入会员身份证!");
		return;
	}
	if (m_EditHobby_Query=="")
	{
		MessageBox("请输入会员爱好!");
		return;
	}
	CString strsql;
	strsql.Format("select * from VipUsers where VipID='%s'",m_Edit_ID_Query);
	pDetails->DoSelect(strsql);
	CDialog::OnOK();
}
