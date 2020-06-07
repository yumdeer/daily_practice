#if !defined(AFX_IOMONITOR_H__5F5DD7C4_CA41_4126_92E3_0A910529B9A2__INCLUDED_)
#define AFX_IOMONITOR_H__5F5DD7C4_CA41_4126_92E3_0A910529B9A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// IOMonitor.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CIOMonitor dialog

class CIOMonitor : public CDialog
{
// Construction
public:
	void IOdeal(int id,DWORD out);
	CIOMonitor(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CIOMonitor)
	enum { IDD = IDD_IOMONITOR };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIOMonitor)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CIOMonitor)
	afx_msg void OnTimer(UINT nIDEvent);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IOMONITOR_H__5F5DD7C4_CA41_4126_92E3_0A910529B9A2__INCLUDED_)
