// VipRecord.cpp : implementation file
//

#include "stdafx.h"
#include "VipManage_Final.h"
#include "VipRecord.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// VipRecord

IMPLEMENT_DYNAMIC(VipRecord, CRecordset)

VipRecord::VipRecord(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(VipRecord)
	m_id = 0;
	m_VipNumber = 0;
	m_VipName = _T("");
	m_VipID = 0;
	m_VipSex = _T("");
	m_VipHobby = _T("");
	m_VipLevel = _T("");
	m_VipPicPath = _T("");
	m_VipRemarks = _T("");
	m_nFields = 10;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString VipRecord::GetDefaultConnect()
{
	return _T("ODBC;DSN=VipManage");
}

CString VipRecord::GetDefaultSQL()
{
	return _T("[dbo].[VipUsers]");
}

void VipRecord::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(VipRecord)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[id]"), m_id);
	RFX_Long(pFX, _T("[VipNumber]"), m_VipNumber);
	RFX_Text(pFX, _T("[VipName]"), m_VipName);
	RFX_Long(pFX, _T("[VipID]"), m_VipID);
	RFX_Text(pFX, _T("[VipSex]"), m_VipSex);
	RFX_Date(pFX, _T("[VipJoinTime]"), m_VipJoinTime);
	RFX_Text(pFX, _T("[VipHobby]"), m_VipHobby);
	RFX_Text(pFX, _T("[VipLevel]"), m_VipLevel);
	RFX_Text(pFX, _T("[VipPicPath]"), m_VipPicPath);
	RFX_Text(pFX, _T("[VipRemarks]"), m_VipRemarks);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// VipRecord diagnostics

#ifdef _DEBUG
void VipRecord::AssertValid() const
{
	CRecordset::AssertValid();
}

void VipRecord::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
