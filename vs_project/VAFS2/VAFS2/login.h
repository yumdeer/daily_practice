#if !defined(AFX_LOGIN_H__B2872795_2FC2_4C39_9B8D_F3AEBEBAF870__INCLUDED_)
#define AFX_LOGIN_H__B2872795_2FC2_4C39_9B8D_F3AEBEBAF870__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// login.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Clogin dialog

class Clogin : public CDialog
{
// Construction
public:
	Clogin(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Clogin)
	enum { IDD = IDD_LOGIN };
	CEdit	m_currentpassword;
	CString	m_password;
	CString	m_change;
	CString	m_changeupdata;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Clogin)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Clogin)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangecurrentpassword();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGIN_H__B2872795_2FC2_4C39_9B8D_F3AEBEBAF870__INCLUDED_)
