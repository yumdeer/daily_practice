#if !defined(AFX_RCPSAVE_H__6524AC6A_D261_4AC6_AB1B_962CD85BDE7F__INCLUDED_)
#define AFX_RCPSAVE_H__6524AC6A_D261_4AC6_AB1B_962CD85BDE7F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RcpSave.h : header file
//
#define OPEN_SOFTKEY1 WM_USER+102
/////////////////////////////////////////////////////////////////////////////
// RcpSave dialog

class RcpSave : public CDialog
{
// Construction
public:
	RcpSave(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(RcpSave)
	enum { IDD = IDD_INPUTRCP };
	CString	m_newrcpname;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(RcpSave)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(RcpSave)
	virtual void OnOK();
	afx_msg LRESULT opensoftkey1(WPARAM wParam,LPARAM lParam); ///////////////////
	afx_msg void OnSetfocusEdit1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RCPSAVE_H__6524AC6A_D261_4AC6_AB1B_962CD85BDE7F__INCLUDED_)
