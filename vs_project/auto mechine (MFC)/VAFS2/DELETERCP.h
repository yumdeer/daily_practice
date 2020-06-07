#if !defined(AFX_DELETERCP_H__9CD30B46_F33B_447E_A525_437BC53516A5__INCLUDED_)
#define AFX_DELETERCP_H__9CD30B46_F33B_447E_A525_437BC53516A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DELETERCP.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DELETERCP dialog

class DELETERCP : public CDialog
{
// Construction
public:
	DELETERCP(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DELETERCP)
	enum { IDD = IDD_DELETERCP };
	CString	m_selectrcp;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DELETERCP)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DELETERCP)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELETERCP_H__9CD30B46_F33B_447E_A525_437BC53516A5__INCLUDED_)
