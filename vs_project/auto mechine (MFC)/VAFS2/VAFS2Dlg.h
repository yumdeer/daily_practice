#include "MyButton.h"
// VAFS2Dlg.h : header file
//
//#include "ModelEditDlg.h"
//{{AFX_INCLUDES()
#include "mscomm.h"
//}}AFX_INCLUDES
#if !defined(AFX_VAFS2DLG_H__46ECE1D9_91EB_47B6_8BE9_8933DB4B44B1__INCLUDED_)
#define AFX_VAFS2DLG_H__46ECE1D9_91EB_47B6_8BE9_8933DB4B44B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CVAFS2Dlg dialog



class CVAFS2Dlg : public CDialog
{
// Construction
public:
	//HIMAGE		m_hImage;    //Í¼ÏñÊý¾Ý¾ä±ú
	void BeginTime();
	void EndTime();
    void MainIOdeal(int id,DWORD out);

	BOOL InitDeviceFunction();
    void ReleaseDevice();
    void OnStartCollection();
	void OnStartCollection2();
	//void OnStartCollection3();
	//void OnStartCollection4();
	void DrawObject(CDC *pDC);
	void OnLoadModel(); 
	void display();
	void display2();
	void calangle();
	void recalangle();
	void calkeypaste();
	void recalkeypaste();
	void transpoint();
	void retranspoint();
	void showscore2();
	void reshowscore2();
	Herror  OnSearchObject();
	Herror OnSearchObject2();
	void OnSearchObject3();
	void OnSearchObject4();


	mypoint circle(mypoint point1,mypoint point2,mypoint point3);
	


    
	CVAFS2Dlg(CWnd* pParent = NULL);	// standard constructor

	virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
		afx_msg LRESULT OnGetDataMessage(WPARAM wParam, LPARAM lParam);

		

// Dialog Data
	//{{AFX_DATA(CVAFS2Dlg)
	enum { IDD = IDD_VAFS2_DIALOG };
	CStatic	m_downfinished;
	CStatic	m_upstart;
	CButton	m_lastone;
	CMyButton	m_pasteanglepm;
	CMyButton	m_pasteanglemm;
	CMyButton	m_YPm;
	CMyButton	m_YMm;
	CMyButton	m_XPm;
	CMyButton	m_XMm;
	CListCtrl	m_list3;
	CListCtrl	m_list4;
	CListCtrl	m_list2;
	CMyButton	m_pasteanglem;
	CMyButton	m_pasteanglep;
	CMyButton	m_YP;
	CMyButton	m_YM;
	CMyButton	m_XP;
	CMyButton	m_XM;
	CButton	m_stop;
	CButton	m_reset;
	CButton	m_debug;
	CButton	m_start;
	CListBox	m_problemlist;
	CListCtrl	m_list1;
	long	m_pastecounter;
	short	m_hour;
	short	m_minute;
	short	m_second;
	long	m_pastex;
	long	m_pastey;
	long	m_pasteangle;
	long	m_repasteangle;
	long	m_repastex;
	long	m_repastey;
	long	m_totalcounter;
	long	m_castcounter;
	long	m_slavenum;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVAFS2Dlg)
	public:
	
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CVAFS2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDebug();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnStart();
	afx_msg void OnStop();
	afx_msg void OnReset();
	afx_msg void OnClose();
	afx_msg void OnOnCommMscomm1();
	afx_msg void Onlastone();
	afx_msg void Oncounterzero1();
	afx_msg void Oncounterzero2();
	afx_msg void Oncounterzero3();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()


	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.



#endif // !defined(AFX_VAFS2DLG_H__46ECE1D9_91EB_47B6_8BE9_8933DB4B44B1__INCLUDED_)
