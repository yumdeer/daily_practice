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
	
	CDebugDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDebugDlg)
	enum { IDD = IDD_DEBUG };
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
	afx_msg void OnXstepp();
	afx_msg void OnXstepm();
	afx_msg void OnYstepp();
	afx_msg void OnYstepm();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDestroy();
	virtual void OnOK();
	afx_msg void OnChangeJogs();
	afx_msg void Onpastestepp();
	/*afx_msg void Onfixturestepp();*/
	afx_msg void Onparasetup();
	afx_msg void OnSetfocuspickx();
	afx_msg void OnKillfocuspickx();
	afx_msg void OnSetfocuspicky();
	afx_msg void OnKillfocuspicky();
	afx_msg void OnSetfocusphotox();
	afx_msg void OnKillfocusphotox();
	afx_msg void OnSetfocusphotoy();
	afx_msg void OnKillfocusphotoy();
	afx_msg void OnSetfocuspastex();
	afx_msg void OnKillfocuspastex();
	afx_msg void OnSetfocuspastey();
	afx_msg void OnKillfocuspastey();
	afx_msg void Onsoftkey2();
	afx_msg void Oncyclephoto();
	afx_msg void OnSetfocusJogs();
	afx_msg void OnKillfocusJogs();
	afx_msg void OnSetfocusJogv();
	afx_msg void OnKillfocusJogv();
	afx_msg void Oncounterzero();
	afx_msg void OnSetfocustrunplateout();
	afx_msg void OnKillfocustrunplateout();
	afx_msg void OnSetfocusturnplatein();
	afx_msg void OnKillfocusturnplatein();
	afx_msg void OnTurnplatep();
	afx_msg void OnTurnplatem();
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
	//afx_msg void Onlinestepm();
	//afx_msg void Onlinestepp();
	afx_msg void OnSetfocusphotoxd2();
	afx_msg void OnKillfocusphotoxd2();
	afx_msg void OnSetfocusphotoyd2();
	afx_msg void OnKillfocusphotoyd2();
	afx_msg void OnTonguejogp();
	afx_msg void OnTonguejogm();
	afx_msg void OnSetfocustongueind();
	afx_msg void OnKillfocustongueind();
	afx_msg void OnSetfocustongueoutd();
	afx_msg void OnKillfocustongueoutd();
	afx_msg void OnZstepp();
	afx_msg void OnZstepm();
	afx_msg void OnSetfocuszpick();
	afx_msg void OnKillfocuszpick();
	afx_msg void Onupfinishedp();
	afx_msg void Ondownstartp();
	afx_msg void Onpusher2p();
	afx_msg void Onload1p();
	afx_msg void Onload2p();
	afx_msg void Onflow1p();
	afx_msg void Onflow2p();
	afx_msg void Onvacuum2p();
	afx_msg void Onloadvacuum1p();
	afx_msg void Onloadvacuum2p();
	afx_msg void Onfixturevacuump();
	afx_msg void Onreloadaixlp();
	afx_msg void Onreloadaixlm();
	afx_msg void Onloadaxilp();
	afx_msg void Onloadaxilm();
	afx_msg void OnSetfocusrepasteangled();
	afx_msg void OnKillfocusrepasteangled();
	afx_msg void OnSetfocusrepastexd();
	afx_msg void OnKillfocusrepastexd();
	afx_msg void OnSetfocusrepasteyd();
	afx_msg void OnKillfocusrepasteyd();
	/*afx_msg void Onplacestepp();*/
	afx_msg void Onreloadp();
	afx_msg void Onloadp();
	afx_msg void Onhalfload();
	afx_msg void Onloadopen();
	afx_msg void Onunload();
	afx_msg void Onhalfunload();
	afx_msg void Onunloadopen();
	afx_msg void Oncover();
	afx_msg void Onflow();
	afx_msg void Onvacuum();
	afx_msg void Onfixturevacuum();
	afx_msg void Oncovervacuum();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedloadpp();
	afx_msg void OnBnClickedloadmp();
	afx_msg void OnBnClickedunloadpp();
	afx_msg void OnBnClickedunloadmp();
	afx_msg void OnBnClickedbacklight();
	afx_msg void OnBnClickedunloadm();
	afx_msg void OnBnClickedunloadp();
	afx_msg void OnBnClickedloadpp2();
	afx_msg void OnBnClickedunloadpp2();
	afx_msg void OnBnClickedloadpp3();
	afx_msg void OnBnClickedunloadpp3();
	afx_msg void OnBnClickedloadmp2();
	afx_msg void OnBnClickedunloadmp2();
	afx_msg void OnBnClickedloadmp3();
	afx_msg void OnBnClickedunloadmp3();
	afx_msg void OnBnClickedLblock();
	afx_msg void OnBnClickedLvacuum();

	afx_msg void OnBnClickedPright();
	afx_msg void OnBnClickedPronbotvacuum();
	afx_msg void OnBnClickedPtrun();
	afx_msg void OnBnClickedPclip();
	afx_msg void OnBnClickedPdown();
	afx_msg void OnBnClickedPflow();
	afx_msg void OnBnClickedPleftvacuum();
	afx_msg void OnBnClickedPrightvacuum();
	afx_msg void OnBnClickedPdownvacuum();
	afx_msg void OnBnClickedlinstepp();
	afx_msg void OnBnClickedloutstepp();
	afx_msg void OnBnClickedllstepp();
	afx_msg void OnBnClickedleftstepp();
	afx_msg void OnBnClickedrightstepp();
	afx_msg void OnBnClickedpeelstepp();
	afx_msg void OnBnClickedunloadstepp();
	afx_msg void OnBnClickedPleft();
	afx_msg void OnBnClickedPright2();
	
	afx_msg void OnBnClickedCliproller();
	afx_msg void OnBnClickedTray();
	afx_msg void OnBnClickedTrayvacuum();
	afx_msg void OnBnClickedcyclephoto3();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEBUGDLG_H__A1C78B4B_0793_41C6_92E5_13DC407B2593__INCLUDED_)
