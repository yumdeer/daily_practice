// VAFS2Dlg.h : header file
//
//#include "ModelEditDlg.h"
//{{AFX_INCLUDES()
//#include "mscomm.h"
//}}AFX_INCLUDES
#if !defined(AFX_VAFS2DLG_H__46ECE1D9_91EB_47B6_8BE9_8933DB4B44B1__INCLUDED_)
#define AFX_VAFS2DLG_H__46ECE1D9_91EB_47B6_8BE9_8933DB4B44B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CVAFS2Dlg dialog



//using namespace RCAPINet;

class CVAFS2Dlg : public CDialog
{
// Construction
	
public:
	//HIMAGE		m_hImage;    //Í¼ÏñÊý¾Ý¾ä±ú
	CSocket C4pSocket;



	void C4TcpSend(CString str);
	//void BeginTime();
	//void EndTime();


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
	//Herror OnSearchObject2();
	void OnSearchObject3();
	void OnSearchObject4();


	mypoint circle(mypoint point1,mypoint point2,mypoint point3);
	



	CVAFS2Dlg(CWnd* pParent = NULL);	// standard constructor
		afx_msg LRESULT OnGetDataMessage(WPARAM wParam, LPARAM lParam);

// Dialog Data
	//{{AFX_DATA(CVAFS2Dlg)
	enum { IDD = IDD_VAFS2_DIALOG };
	CListCtrl	m_list3;
	CListCtrl	m_list4;
	CListCtrl	m_list2;
	CButton	m_pasteanglem;
	CButton	m_pasteanglep;
	CButton	m_YPB;
	CButton	m_YMB;
	CButton	m_XPB;
	CButton	m_XMB;
	CButton	m_YP;
	CButton	m_YM;
	CButton	m_XP;
	CButton	m_XM;
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
	//CMSComm	m_serial;

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
	afx_msg void OnXp();
	afx_msg void OnXm();
	afx_msg void OnYp();
	afx_msg void OnYm();
	afx_msg void OnAnglep();
	afx_msg void OnAnglem();
	
	afx_msg void Oncounterzero1();
	afx_msg void Onlight();

	
//		static void m_spel_EventReceived(System::Object^  sender, SpelEventArgs^ e);
	
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()




	
public:
	afx_msg void OnBnClickedlight2();
	afx_msg void OnBnClickedBelt();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.



#endif // !defined(AFX_VAFS2DLG_H__46ECE1D9_91EB_47B6_8BE9_8933DB4B44B1__INCLUDED_)
