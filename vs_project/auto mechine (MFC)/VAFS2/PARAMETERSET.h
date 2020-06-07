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
	void inputshow(UINT nID);
	bool GoSmallKey(int ctlID,intype intype,float invaluef,float Vlumax,float Vlumin, POINT rect,float* outvaluef);
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
	long	m_pickx;
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
	afx_msg LRESULT opensoftkey(WPARAM wParam,LPARAM lParam); 
	afx_msg LRESULT closesoftkey(WPARAM wParam,LPARAM lParam); 
	afx_msg void Onmetalverify();
	afx_msg void OnSetfocusmetalscale();
	afx_msg void OnKillfocusmetalscale();
	afx_msg void OnSetfocusmetalscaley();
	afx_msg void OnKillfocusmetalscaley();
	afx_msg void OnSetfocuscarrytime();
	afx_msg void OnKillfocuscarrytime();
	afx_msg void OnSetfocuszpicks();
	afx_msg void OnKillfocuszpicks();
	afx_msg void OnSetfocusverifypastex();
	afx_msg void OnKillfocusverifypastex();
	afx_msg void OnSetfocusverifypastey();
	afx_msg void OnKillfocusverifypastey();
	afx_msg void Onshieldpaste();
	afx_msg void Onwithbeep();
	afx_msg void Onpickx();
	afx_msg void Onpastex();
	afx_msg void Onrepastex();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void Onpickangle();
	afx_msg void Onphotor();
	afx_msg void Onreloadwaiting();
	afx_msg void Onreloadpick();
	afx_msg void Onreloadpush();
	afx_msg void Ontonguein();
	afx_msg void Onphotox();
	afx_msg void Onphotox2();
	afx_msg void Onfixtureouttime();
	afx_msg void Onmainmotorlength();
	afx_msg void Onfixturedelaytime();
	afx_msg void Onpicktime();
	afx_msg void Onphotodelay();
	afx_msg void Onvexx();
	afx_msg void Onvload();
	afx_msg void Onvextonguein();
	afx_msg void Onpicky();
	afx_msg void Onpastey();
	afx_msg void Onrepastey();
	afx_msg void Onpasteangle();
	afx_msg void Onrepasteangle();
	afx_msg void Onloadwaiting();
	afx_msg void Onloadpick();
	afx_msg void Onloadpush();
	afx_msg void Ontongueout();
	afx_msg void Onphotoy();
	afx_msg void Onphotoy2();
	afx_msg void Onzpush();
	afx_msg void Onvexmainmotorlow();
	afx_msg void Onvexmainmotorhigh();
	afx_msg void Onpushertime();
	afx_msg void Onloadtime();
	afx_msg void Onunloadtime();
	afx_msg void Onvexy();
	afx_msg void Onvturnplate();
	afx_msg void Onvextongueout();
	afx_msg void Onsearchrange();
	afx_msg void Onsearchrange2();
	afx_msg void Onminscore11();
	afx_msg void Onminscore21();
	afx_msg void Oncomno();
	afx_msg void Onzphoto();
	afx_msg void Onrollon();
	afx_msg void Onpresson();
	afx_msg void Onrollerfinished();
	afx_msg void Onvexroller2();
	afx_msg void Onzvex();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARAMETERSET_H__DC098F73_716D_4499_8AD7_D9C959349D39__INCLUDED_)
