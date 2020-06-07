#include "MyButton.h"
#if !defined(AFX_DEBUGDLG_H__A1C78B4B_0793_41C6_92E5_13DC407B2593__INCLUDED_)
#define AFX_DEBUGDLG_H__A1C78B4B_0793_41C6_92E5_13DC407B2593__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DebugDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDebugDlg dialog

class CDebugDlg : public CDialog
{
// Construction
public:
	void inputshow(UINT nID);
	bool GoSmallKey(int ctlID,intype intype,float invaluef,float Vlumax,float Vlumin, POINT rect,float* outvaluef);
	CDebugDlg(CWnd* pParent = NULL);   // standard constructor
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
// Dialog Data
	//{{AFX_DATA(CDebugDlg)
	enum { IDD = IDD_DEBUG };
	CMyButton	m_ystepp;
	CMyButton	m_ystepm;
	CMyButton	m_xstepp;
	CMyButton	m_xstepm;
	CMyButton	m_turnplatep;
	CMyButton	m_turnplatem;
	CMyButton	m_tonguejogp;
	CMyButton	m_tonguejogm;
	CMyButton	m_reloadaixlp;
	CMyButton	m_reloadaixlm;
	CMyButton	m_loadaxilp;
	CMyButton	m_loadaxilm;
	CMyButton	m_linejogp;
	CMyButton	m_linejogm;
	CString	m_fixtureinfo;
	float	m_JOGS;
	float	m_JOGV;
	long	m_pasteangle;
	long	m_pastex;
	long	m_pastey;
	long	m_photox;
	long	m_photoy;
	long	m_pickangle;
	long	m_pickx;
	long	m_picky;
	CString	m_stateinfo;
	long	m_photox2;
	long	m_photoy2;
	long	m_tonguein;
	long	m_tongueout;
	long	m_zpick;
	long	m_repasteangle;
	long	m_repastex;
	long	m_repastey;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDebugDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDebugDlg)
	afx_msg void OnVision();
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDestroy();
	virtual void OnOK();
	afx_msg void Onpastestepp();
	afx_msg void Onfixturestepp();
	afx_msg void Onparasetup();
	afx_msg void OnSetfocusphotox();
	afx_msg void OnKillfocusphotox();
	afx_msg void OnSetfocusphotoy();
	afx_msg void OnKillfocusphotoy();
	afx_msg void Onsoftkey2();
	afx_msg void Oncyclephoto();
	afx_msg void Oncounterzero();
	afx_msg void OnVision2();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void Oncyclephoto2();
	afx_msg void OnVision21();
	afx_msg void OnVision22();
	afx_msg void Oncyclephoto3();
	afx_msg void Oncyclephoto4();
	afx_msg void OnVision31();
	afx_msg void OnVision32();
	afx_msg void OnVision41();
	afx_msg void OnVision42();
	afx_msg void OnRollerstepp();
	afx_msg void OnRollerstepm();
	afx_msg void Onzoomp();
	afx_msg void Onzoomm();
	afx_msg void Onzoompup();
	afx_msg void Onzoomdown();
	afx_msg void Onzoomleft();
	afx_msg void Onzoomright();
	afx_msg void Onmstart();
	afx_msg void Onmover();
	afx_msg void Onlinestepm();
	afx_msg void Onlinestepp();
	afx_msg void Onvacuump();
	afx_msg void OnSetfocusphotoxd2();
	afx_msg void OnKillfocusphotoxd2();
	afx_msg void OnSetfocusphotoyd2();
	afx_msg void OnKillfocusphotoyd2();
	afx_msg void OnSetfocuszpick();
	afx_msg void OnKillfocuszpick();
	afx_msg void Onupfinishedp();
	afx_msg void Ondownstartp();
	afx_msg void Onpusher1p();
	afx_msg void Onpusher2p();
	afx_msg void Onload1p();
	afx_msg void Onload2p();
	afx_msg void Onflow1p();
	afx_msg void Onflow2p();
	afx_msg void Onvacuum2p();
	afx_msg void Onloadvacuum1p();
	afx_msg void Onloadvacuum2p();
	afx_msg void Onfixturevacuump();
	afx_msg void Onplacestepp();
	afx_msg void Onreloadp();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void Onpickxd();
	afx_msg void Onpickangled();
	afx_msg void Onpastexd();
	afx_msg void Onrepastexd();
	afx_msg void Onpasteangled();
	afx_msg void Ontongueoutd();
	afx_msg void Onpickyd();
	afx_msg void Onpasteyd();
	afx_msg void Onrepasteyd();
	afx_msg void Onrepasteangled();
	afx_msg void Ontongueind();
	afx_msg void OnJogv();
	afx_msg void OnJogs();
	afx_msg void Onrightpress();
	afx_msg void Onpressvacuum();
	afx_msg void Onrightpress2();
	afx_msg void OnVision3();
	afx_msg void OnVision4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEBUGDLG_H__A1C78B4B_0793_41C6_92E5_13DC407B2593__INCLUDED_)
