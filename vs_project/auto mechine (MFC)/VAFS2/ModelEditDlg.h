#if !defined(AFX_MODELEDITDLG_H__55891B86_FC62_4739_9448_D2026372F134__INCLUDED_)
#define AFX_MODELEDITDLG_H__55891B86_FC62_4739_9448_D2026372F134__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "stdafx.h"
#include "externs.h"
#include "resource.h"


	
/////////////////////////////////////////////////////////////////////////////


class CModelEditDlg : public CDialog
{
// Construction
public:
	int NumLevels;
	int m_modalorg;
	Hobject Imageedit;
	Hlong  m_Windoweditid;
	HTuple ShapeModeledit;
	Hobject  m_ImageReduced;
	Hobject modelrect;
	Hlong  startpointx;
	Hlong  startpointy;
	double endpointx;
	double endpointy;
	double modelhalfx,modelhalfy;
	Hlong xi,yi;
	bool model11,model12,model21,model22,model31,model32,model41,model42;
    ;

	void EnableAll();
	void EditModel( BOOL IsEdit );
	CModelEditDlg(CWnd* pParent = NULL);   // standard constructor
//    HWindow m_Windowedit;
	
// Dialog Data
	//{{AFX_DATA(CModelEditDlg)
	enum { IDD = IDD_MODEL_EDIT_DLG };
	CSliderCtrl	m_contrastctr;
	int		m_contrast;
	int		m_contrastin;
	//}}AFX_DATA
	

	BOOL	m_EditModel;
	Hobject m_ShapeModelContours;
    Hobject m_ShapeModelContoursxld,m_ShapeModelContoursxldold;




	int		m_PenWidth;
	int		m_PointState;






     
virtual BOOL PreTranslateMessage(MSG* pMsg);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CModelEditDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
    bool messageout;
	// Generated message map functions
	//{{AFX_MSG(CModelEditDlg)
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnAddEdge();
	afx_msg void OnDelEdge();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void Onsoftkey4();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
		afx_msg void Onup1();
	afx_msg void Oncenter();
	afx_msg void Onrightup2();
	afx_msg void Onright3();
	afx_msg void Onrightdown4();
	afx_msg void Ondown5();
	afx_msg void Onleftdown6();
	afx_msg void Onleft7();
	afx_msg void Onleftup8();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODELEDITDLG_H__55891B86_FC62_4739_9448_D2026372F134__INCLUDED_)
