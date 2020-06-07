// login.cpp : implementation file
//

#include "stdafx.h"
#include "VAFS2.h"
#include "login.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Clogin dialog


Clogin::Clogin(CWnd* pParent /*=NULL*/)
	: CDialog(Clogin::IDD, pParent)
{
	//{{AFX_DATA_INIT(Clogin)
	m_password = _T("");
	m_change = _T("");
	m_changeupdata = _T("");
	//}}AFX_DATA_INIT
}


void Clogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Clogin)
	DDX_Control(pDX, IDC_currentpassword, m_currentpassword);
	DDX_Text(pDX, IDC_currentpassword, m_password);
	DDX_Text(pDX, IDC_newpassword, m_change);
	DDX_Text(pDX, IDC_passwordupdata, m_changeupdata);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Clogin, CDialog)
	//{{AFX_MSG_MAP(Clogin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Clogin message handlers

BOOL Clogin::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	MoveWindow(300,100,400,200);
	m_currentpassword.SetFocus();
	HWND h=::FindWindow(NULL,"ÆÁÄ»¼üÅÌ");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	WinExec("c:\\windows\\system32\\osk.exe",SW_SHOWNORMAL);
    h=::FindWindow(NULL,"ÆÁÄ»¼üÅÌ");
	::MoveWindow(h,0,300,1024,400,true);

	
	return false;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
