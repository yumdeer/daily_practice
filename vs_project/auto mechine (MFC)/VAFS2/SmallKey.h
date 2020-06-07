#if !defined(AFX_SMALLKEY_H__C69211CA_58D8_40F3_8F13_61FD0A7A8D3B__INCLUDED_)
#define AFX_SMALLKEY_H__C69211CA_58D8_40F3_8F13_61FD0A7A8D3B__INCLUDED_

#include "StdAfx.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SmallKey.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSmallKey dialog

class CSmallKey : public CDialog
{
// Construction
public:
	float inputftemp;
	intype m_intype;
	float m_inputfloat;
	POINT ctlposL;
	void Updateinput();
	void OnBtnClick(HWND hButton);
	CSmallKey(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSmallKey)
	enum { IDD = IDD_SmallKey };
	CStatic	m_cinput;
	float	m_maximum;
	float	m_minimum;
	CString	m_prompt;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSmallKey)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSmallKey)
	virtual void OnOK();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SMALLKEY_H__C69211CA_58D8_40F3_8F13_61FD0A7A8D3B__INCLUDED_)
