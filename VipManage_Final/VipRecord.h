#if !defined(AFX_VIPRECORD_H__DD003174_C14D_48F4_B569_56EBFA2BC6BA__INCLUDED_)
#define AFX_VIPRECORD_H__DD003174_C14D_48F4_B569_56EBFA2BC6BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// VipRecord.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// VipRecord recordset

class VipRecord : public CRecordset
{
public:
	VipRecord(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(VipRecord)

// Field/Param Data
	//{{AFX_FIELD(VipRecord, CRecordset)
	long	m_id;
	long	m_VipNumber;
	CString	m_VipName;
	long	m_VipID;
	CString	m_VipSex;
	CTime	m_VipJoinTime;
	CString	m_VipHobby;
	CString	m_VipLevel;
	CString	m_VipPicPath;
	CString	m_VipRemarks;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(VipRecord)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIPRECORD_H__DD003174_C14D_48F4_B569_56EBFA2BC6BA__INCLUDED_)
