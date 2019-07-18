#if !defined(AFX_PARAMETERSET_H__DC098F73_716D_4499_8AD7_D9C959349D39__INCLUDED_)
#define AFX_PARAMETERSET_H__DC098F73_716D_4499_8AD7_D9C959349D39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "externs.h"
// PARAMETERSET.h : header file
//
#define OPEN_SOFTKEY WM_USER+100
#define CLOSE_SOFTKEY WM_USER+101
/////////////////////////////////////////////////////////////////////////////
// PARAMETERSET dialog

class PARAMETERSET : public CDialog
{
// Construction
public:
	PARAMETERSET(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PARAMETERSET)
	enum { IDD = IDD_PARAMETERSET };
	CListBox	m_rcplist;
	float	m_yscale;
	float	m_xscale;
	float	m_xcenterdiv;
	float	m_xdiv;
	float	m_ycenterdiv;
	int		m_fixturedelaytime;
	int		m_fixtureouttime;
	long	m_mainmotorlength;
	long	m_pasteangle;
	long	m_pastex;
	long	m_pastey;
	long	m_photox;
	long	m_photoy;
	int		m_picktime;
	long	m_pickx;
	long	m_picky;
	int		m_pushertime;
	long	m_rollerfinished;
	long	m_vexmainmotorhigh;
	long	m_vexmainmotorlow;
	long	m_vturnplate;
	long	m_vexx;
	long    m_repeat;
	long    m_shieldpaste;
	long	m_vexy;
	long	m_pickangle;
float	m_photo2angle;
	float	m_metalscale;
	float	m_xidv;
	float	m_ydiv;
	float	m_minscore11;
	float	m_minscore21;
	long	m_photox2;
	long	m_photoy2;
	long	m_tonguein;
	long	m_vextonguein;
	long	m_tongueout;
	long	m_vextongueout;
	int		m_unloadtime;
	int		m_loadtime;
	float	m_metalscaley;
	int		m_photodelay;
	float	m_camera2xdiv;
	float	m_camera2ydiv;
	float	m_photo1angle;
	long	m_carrytime;
	long	m_comno;
	long	m_vexroller2;
	long	m_searchrange;
	long	m_zvex;
	long	m_zphoto;
	long	m_zpick;
	long	m_zpush;
	long	m_verifypastex;
	long	m_verifypastey;
	long	m_searchrange2;
	CString	m_verifyinfo;
	long	m_vload;
	long	m_reloadpick;
	long	m_reloadpush;
	long	m_reloadwaiting;
	long	m_repasteangle;
	long	m_repastex;
	long	m_repastey;
	long	m_loadpick;
	long	m_loadwaiting;
	long	m_loadpush;
	long	m_photor;
	long	m_fixturex;
	long	m_fixturey;
	long	m_coverx;
	long	m_covery;
	long	m_stepx;
	long	m_stepy;
	long	m_specialx;
	long	m_specialy;
	long	m_vexfixturex;
	long	m_vexfixturey;
	long	m_numberx;
	long	m_numbery;
	long	m_loadx;
	long	m_loady;
	long	m_unloadx;
	long	m_unloady;
	long	m_films;
	long	m_filml;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PARAMETERSET)
	public:
	virtual BOOL DestroyWindow();
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PARAMETERSET)
	virtual BOOL OnInitDialog();
	afx_msg void Onsaveas();
	afx_msg void Onselectrcp();
	afx_msg void Ondelrcp();
	afx_msg void Onphotoverify();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void Onsoftkey();
	afx_msg void Onparameterproduce();
	afx_msg void Onfixturemove();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSetfocusfixturedelaytime();
	afx_msg void OnKillfocusfixturedelaytime();
	afx_msg void OnSetfocusfixtureouttime();
	afx_msg void OnKillfocusfixtureouttime();
	afx_msg void OnSetfocusmainmotorlength();
	afx_msg void OnKillfocusmainmotorlength();
	afx_msg void OnSetfocuspasteangle();
	afx_msg void OnKillfocuspasteangle();
	afx_msg void OnSetfocuspastex();
	afx_msg void OnKillfocuspastex();
	afx_msg void OnSetfocuspastey();
	afx_msg void OnKillfocuspastey();
	afx_msg void OnSetfocusphotox();
	afx_msg void OnKillfocusphotox();
	afx_msg void OnSetfocusphotoy();
	afx_msg void OnKillfocusphotoy();
	afx_msg void OnSetfocuspicktime();
	afx_msg void OnKillfocuspicktime();
	afx_msg void OnSetfocuspickx();
	afx_msg void OnKillfocuspickx();
	afx_msg void OnSetfocuspicky();
	afx_msg void OnKillfocuspicky();
	afx_msg void OnSetfocuspushertime();
	afx_msg void OnKillfocuspushertime();
	afx_msg void OnSetfocusrollerfinished();
	afx_msg void OnKillfocusrollerfinished();
	afx_msg void OnSetfocusvexmainmotorhigh();
	afx_msg void OnKillfocusvexmainmotorhigh();
	afx_msg void OnSetfocusvexmainmotorlow();
	afx_msg void OnKillfocusvexmainmotorlow();
	afx_msg void OnSetfocusvexx();
	afx_msg void OnKillfocusvexx();
	afx_msg void OnSetfocusvexy();
	afx_msg void OnKillfocusvexy();
	afx_msg void OnSetfocusvturnplate();
	afx_msg void OnKillfocusvturnplate();
	afx_msg LRESULT opensoftkey(WPARAM wParam,LPARAM lParam); 
	afx_msg LRESULT closesoftkey(WPARAM wParam,LPARAM lParam); 
	afx_msg void OnSetfocuspickangle();
	afx_msg void OnKillfocuspickangle();
	afx_msg void Onmetalverify();
	afx_msg void OnSetfocusminscore11();
	afx_msg void OnKillfocusminscore11();
	afx_msg void OnSetfocusminscore21();
	afx_msg void OnKillfocusminscore21();
	afx_msg void OnSetfocusphotox2();
	afx_msg void OnKillfocusphotox2();
	afx_msg void OnSetfocusphotoy2();
	afx_msg void OnKillfocusphotoy2();
	afx_msg void OnSetfocustonguein();
	afx_msg void OnKillfocustonguein();
	afx_msg void OnSetfocustongueout();
	afx_msg void OnKillfocustongueout();
	afx_msg void OnSetfocusvextonguein();
	afx_msg void OnKillfocusvextonguein();
	afx_msg void OnSetfocusvextongueout();
	afx_msg void OnKillfocusvextongueout();
	afx_msg void OnSetfocusloadtime();
	afx_msg void OnKillfocusloadtime();
	afx_msg void OnSetfocusunloadtime();
	afx_msg void OnKillfocusunloadtime();
	afx_msg void OnSetfocusmetalscale();
	afx_msg void OnKillfocusmetalscale();
	afx_msg void OnSetfocusmetalscaley();
	afx_msg void OnKillfocusmetalscaley();
	afx_msg void OnSetfocusphotodelay();
	afx_msg void OnKillfocusphotodelay();
	afx_msg void OnSetfocuscarrytime();
	afx_msg void OnKillfocuscarrytime();
	afx_msg void OnSetfocuscomno();
	afx_msg void OnKillfocuscomno();
	afx_msg void OnSetfocusvexroller2();
	afx_msg void OnKillfocusvexroller2();
	afx_msg void OnSetfocussearchrange();
	afx_msg void OnKillfocussearchrange();
	afx_msg void OnSetfocuszphoto();
	afx_msg void OnKillfocuszphoto();
	afx_msg void OnSetfocuszpicks();
	afx_msg void OnKillfocuszpicks();
	afx_msg void OnSetfocuszpush();
	afx_msg void OnKillfocuszpush();
	afx_msg void OnSetfocuszvex();
	afx_msg void OnKillfocuszvex();
	afx_msg void OnSetfocusverifypastex();
	afx_msg void OnKillfocusverifypastex();
	afx_msg void OnSetfocusverifypastey();
	afx_msg void OnKillfocusverifypastey();
	afx_msg void OnSetfocussearchrange2();
	afx_msg void OnKillfocussearchrange2();
	afx_msg void OnSetfocusreloadpick();
	afx_msg void OnKillfocusreloadpick();
	afx_msg void OnSetfocusreloadpush();
	afx_msg void OnKillfocusreloadpush();
	afx_msg void OnSetfocusreloadwaiting();
	afx_msg void OnKillfocusreloadwaiting();
	afx_msg void OnSetfocusrepasteangle();
	afx_msg void OnKillfocusrepasteangle();
	afx_msg void OnSetfocusrepastex();
	afx_msg void OnKillfocusrepastex();
	afx_msg void OnSetfocusrepastey();
	afx_msg void OnKillfocusrepastey();
	afx_msg void OnSetfocusloadpick();
	afx_msg void OnKillfocusloadpick();
	afx_msg void OnSetfocusloadpush();
	afx_msg void OnKillfocusloadpush();
	afx_msg void OnSetfocusloadwaiting();
	afx_msg void OnKillfocusloadwaiting();
	afx_msg void OnSetfocusphotor();
	afx_msg void OnKillfocusphotor();
	afx_msg void OnSetfocusvload();
	afx_msg void OnKillfocusvload();
	afx_msg void Onshieldpaste();
	afx_msg void Onwithbeep();
	afx_msg void OnSetfocusfixturex();
	afx_msg void OnKillfocusfixturex();
	afx_msg void OnSetfocusfixturey();
	afx_msg void OnKillfocusfixturey();
	afx_msg void OnSetfocusnumberx();
	afx_msg void OnKillfocusnumberx();
	afx_msg void OnSetfocusnumbery();
	afx_msg void OnKillfocusnumbery();
	afx_msg void OnSetfocusstepx();
	afx_msg void OnKillfocusstepx();
	afx_msg void OnSetfocusstepy();
	afx_msg void OnKillfocusstepy();
	afx_msg void OnSetfocusspecialx();
	afx_msg void OnKillfocusspecialx();
	afx_msg void OnSetfocusspecialy();
	afx_msg void OnKillfocusspecialy();
	afx_msg void OnSetfocusvexfixturex();
	afx_msg void OnKillfocusvexfixturex();
	afx_msg void OnSetfocusvexfixturey();
	afx_msg void OnKillfocusvexfixturey();
	afx_msg void OnSetfocusloadx();
	afx_msg void OnKillfocusloadx();
	afx_msg void OnSetfocusloady();
	afx_msg void OnKillfocusloady();
	afx_msg void OnSetfocusunloadx();
	afx_msg void OnKillfocusunloadx();
	afx_msg void OnSetfocusunloady();
	afx_msg void OnKillfocusunloady();
	afx_msg void Ontestone();
	afx_msg void OnSetfocusfilms();
	afx_msg void OnKillfocusfilms();
	afx_msg void OnSetfocusfilml();
	afx_msg void OnKillfocusfilml();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangevexy2();
	long m_vexload;
	long m_vexunload;
	long m_load0;
	long m_load1;
	long m_load2;
	long m_unload0;
	long m_unload1;
	long m_unload2;
	afx_msg void OnSetfocusVexlaod();
	afx_msg void OnKillfocusVexlaod();
	afx_msg void OnSetfocusVexunlaod();
	afx_msg void OnKillfocusVexunlaod();
	afx_msg void OnSetfocusLoad0();
	afx_msg void OnKillfocusLoad0();
	afx_msg void OnSetfocusLoad1();
	afx_msg void OnKillfocusLoad1();
	afx_msg void OnSetfocusLoad2();
	afx_msg void OnKillfocusLoad2();
	afx_msg void OnSetfocusUnload0();
	afx_msg void OnKillfocusUnload0();
	afx_msg void OnSetfocusUnload1();
	afx_msg void OnKillfocusUnload1();
	afx_msg void OnSetfocusUnload2();
	afx_msg void OnKillfocusUnload2();
	afx_msg void OnEnChangepickx();
	afx_msg void OnEnChangecovery();
//	afx_msg void OnBnClickedshieldpaste2();
	afx_msg void OnBnClickedtraymode();
	float m_photo3angle;
	float m_photo4angle;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARAMETERSET_H__DC098F73_716D_4499_8AD7_D9C959349D39__INCLUDED_)
