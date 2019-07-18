#if !defined(AFX_PARAPRODUCE_H__79693034_76E4_40B0_B8C9_DD1E4124B937__INCLUDED_)
#define AFX_PARAPRODUCE_H__79693034_76E4_40B0_B8C9_DD1E4124B937__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// paraproduce.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Cparaproduce dialog

class Cparaproduce : public CDialog
{
// Construction
public:
	Cparaproduce(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Cparaproduce)
	enum { IDD = IDD_paraproduce };
	long	m_filmwidth;
	long	m_filmlength;
	long	m_filmgap;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cparaproduce)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Cparaproduce)
	afx_msg void OnParaproduce();
	afx_msg void Onsoftkey6();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARAPRODUCE_H__79693034_76E4_40B0_B8C9_DD1E4124B937__INCLUDED_)
