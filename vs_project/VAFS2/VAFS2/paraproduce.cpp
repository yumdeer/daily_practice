// paraproduce.cpp : implementation file
//

#include "stdafx.h"
#include "VAFS2.h"
#include "paraproduce.h"
#include "externs.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cparaproduce dialog


Cparaproduce::Cparaproduce(CWnd* pParent /*=NULL*/)
	: CDialog(Cparaproduce::IDD, pParent)
{
	//{{AFX_DATA_INIT(Cparaproduce)
	m_filmwidth = 0;
	m_filmlength = 0;
	m_filmgap = 0;
	//}}AFX_DATA_INIT
}


void Cparaproduce::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Cparaproduce)
	DDX_Text(pDX, IDC_filmwidth, m_filmwidth);
	DDX_Text(pDX, IDC_filmlength, m_filmlength);
	DDX_Text(pDX, IDC_filmgap, m_filmgap);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Cparaproduce, CDialog)
	//{{AFX_MSG_MAP(Cparaproduce)
	ON_BN_CLICKED(IDC_PARAPRODUCE, OnParaproduce)
	ON_BN_CLICKED(IDC_softkey6, Onsoftkey6)
	
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cparaproduce message handlers

void Cparaproduce::OnParaproduce() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if((m_filmwidth==0)||(m_filmlength==0)||(m_filmgap==0))
	{
		MessageBox("请输入参数");
	}
	else
	{

	int nRes = AfxMessageBox("产生新的参数吗？",MB_YESNO|MB_ICONQUESTION);
	if(nRes == IDYES)
		{
			tongueout=100;
			tonguein=100+m_filmlength*100/88;

			vextongueout=30000;
			vextonguein=30000;

			vexmainmotorlow=500;
			vexmainmotorhigh=20000;
			mainmotorlength=10;

			fixturedelaytime=10;
			picktime=10;
			fixtureouttime=10;
			pushertime=1;


			picky=m_filmgap+m_filmwidth-350;
			pickx=6200+m_filmlength;
			

			photox=pickx-6100;
			photoy=picky-m_filmgap+2550;

			pastex=0;
			pastey=0;
			rollerfinished=pastey-m_filmwidth;

			vexx=60000;
			//vexy=60000;
			vexroller=60000;



		
		}

	}
}

void Cparaproduce::Onsoftkey6() 
{
	// TODO: Add your control notification handler code here
			HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{
		::SendMessage(h,WM_CLOSE,0,0);
		SetDlgItemText(IDC_softkey6,"开键盘");
	}
	else
	{
		WinExec("c:\\windows\\system32\\osk.exe",SW_SHOWNORMAL);
		SetDlgItemText(IDC_softkey6,"关键盘");
	}
	
	
}

BOOL Cparaproduce::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	MoveWindow(100,0,700,600);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
