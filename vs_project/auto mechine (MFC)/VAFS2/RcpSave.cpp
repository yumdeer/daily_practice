// RcpSave.cpp : implementation file
//

#include "stdafx.h"
#include "VAFS2.h"
#include "RcpSave.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// RcpSave dialog
HWND focushwnd1;

RcpSave::RcpSave(CWnd* pParent /*=NULL*/)
	: CDialog(RcpSave::IDD, pParent)
{
	//{{AFX_DATA_INIT(RcpSave)
	m_newrcpname = _T("");
	//}}AFX_DATA_INIT
}


void RcpSave::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(RcpSave)
	DDX_Text(pDX, IDC_EDIT1, m_newrcpname);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(RcpSave, CDialog)
	//{{AFX_MSG_MAP(RcpSave)
	ON_MESSAGE(OPEN_SOFTKEY1,opensoftkey1)
	ON_EN_SETFOCUS(IDC_EDIT1, OnSetfocusEdit1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// RcpSave message handlers

void RcpSave::OnOK() 
{
	// TODO: Add extra validation here
		UpdateData(true);
	
	CDialog::OnOK();
}



LRESULT RcpSave::opensoftkey1(WPARAM wParam,LPARAM lParam) //////////////////
{
	// TODO: Add your control notification handler code here
	RECT r;
	  ::GetWindowRect(focushwnd1,&r);
	  HWND h=::FindWindow(NULL,"ÆÁÄ»¼üÅÌ");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	WinExec("c:\\windows\\system32\\osk.exe",SW_SHOWNORMAL);
    h=::FindWindow(NULL,"ÆÁÄ»¼üÅÌ");
	if(r.bottom<400)
	::MoveWindow(h,0,r.bottom,1024,400,true);
	else
	::MoveWindow(h,0,r.bottom-500,1024,400,true);
	CWnd * cwnd;
	cwnd=FromHandle(focushwnd1);
	cwnd->PostMessage(EM_SETSEL,0,-1);
	return 0;
	
}

void RcpSave::OnSetfocusEdit1() 
{
	// TODO: Add your control notification handler code here
	HWND h=::FindWindow(NULL,"ÆÁÄ»¼üÅÌ");
   	focushwnd1=::GetFocus();

	{
		PostMessage(OPEN_SOFTKEY1);
	}
}
