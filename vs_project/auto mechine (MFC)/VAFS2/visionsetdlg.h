#if !defined(AFX_VISIONSETDLG_H__6E8518A6_6D60_4FFA_958F_72EE762DC474__INCLUDED_)
#define AFX_VISIONSETDLG_H__6E8518A6_6D60_4FFA_958F_72EE762DC474__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// VisionSetDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CVisionSetDlg dialog


#include "ModelEditDlg.h"

extern	BOOL    m_bStartCapture; 



/////////////////////////////////////////////////////////////////////////////
// CCompareImageDlg dialog



class CVisionSetDlg : public CDialog
{
// Construction
public:
	void inputshow(UINT nID);
	bool GoSmallKey(int ctlID,intype intype,float invaluef,float Vlumax,float Vlumin, POINT rect,float* outvaluef);
		CVisionSetDlg(CWnd* pParent = NULL);   // standard constructor
		CModelEditDlg m_ModelEditDlg;

	void BeginTime();
	void EndTime();
    
//    HWindow m_Windowvision;
	Hlong m_Windowvisionid;
	void DrawObject(CDC *pDC);  //显示对象(图像或其他)

	LARGE_INTEGER m_Frequency;
	LARGE_INTEGER m_BeginTime;
	LARGE_INTEGER m_EndTime;
// Dialog Data
	//{{AFX_DATA(CVisionSetDlg)
	enum { IDD = IDD_VISION };
	CListCtrl	m_list1;
	int		m_bright;
	int		m_digitalshift;
	float	m_contrast;
	int		m_gain;
	int		m_shutter;
	float	m_keypastex;
	float	m_keypastey;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVisionSetDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
virtual BOOL PreTranslateMessage(MSG* pMsg);
// Implementation
protected:
	HICON m_hIcon;
	float model11xtemp,model11ytemp,model12xtemp,model12ytemp,model21xtemp,model21ytemp,model22xtemp,model22ytemp;
		float remodel11xtemp,remodel11ytemp,remodel12xtemp,remodel12ytemp,remodel21xtemp,remodel21ytemp,remodel22xtemp,remodel22ytemp;


	// Generated message map functions
	//{{AFX_MSG(CVisionSetDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpenImage();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnStartCollection();
	afx_msg void OnStopCollection();
	afx_msg void OnEditModel();
	afx_msg void OnSearchObject();
	afx_msg void OnDrawRect();
	afx_msg void OnSaveModel();
	afx_msg void OnCreateModel();
	afx_msg void OnChangeEditBright();
	afx_msg void OnOk();
	afx_msg void Onsoftkey3();
	afx_msg void OnChangeDigitalShift();
	afx_msg void OnSetfocuskeypastex();
	afx_msg void OnKillfocuskeypastex();
	afx_msg void OnSetfocuskeypastey();
	afx_msg void OnKillfocuskeypastey();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnEditGain();
	afx_msg void OnEditShutter();
	afx_msg void OnEDITcontrast();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	BOOL InitDeviceFunction();


//	afx_msg void OnStnClickedPorfileRect();

	afx_msg LRESULT OnGetDataMessage(WPARAM wParam, LPARAM lParam);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VISIONSETDLG_H__6E8518A6_6D60_4FFA_958F_72EE762DC474__INCLUDED_)
