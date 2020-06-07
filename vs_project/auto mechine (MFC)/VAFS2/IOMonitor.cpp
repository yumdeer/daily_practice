// IOMonitor.cpp : implementation file
//

#include "stdafx.h"
#include "VAFS2.h"
#include "IOMonitor.h"
#include "dmc1000.h" 

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

DWORD Instate[100]={0};
DWORD Outstate[100]={0};
DWORD Orgstate[100]={0};
/////////////////////////////////////////////////////////////////////////////
// CIOMonitor dialog


CIOMonitor::CIOMonitor(CWnd* pParent /*=NULL*/)
	: CDialog(CIOMonitor::IDD, pParent)
{
	//{{AFX_DATA_INIT(CIOMonitor)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CIOMonitor::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIOMonitor)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CIOMonitor, CDialog)
	//{{AFX_MSG_MAP(CIOMonitor)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIOMonitor message handlers



BOOL CIOMonitor::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetTimer( 1, 10, NULL );
    memset(Instate,1,sizeof(Instate));
	memset(Outstate,1,sizeof(Outstate));
	memset(Orgstate,1,sizeof(Orgstate));
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CIOMonitor::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	{
		for(int i=0;i<8;i++)
		{
			DWORD Hstate;
			Hstate=d1000_get_axis_status(i);
		    Hstate=Hstate&0x00000004;
			DWORD a;
            a=(Hstate>>2);
			if(a!=0)
			{
				a=0;
			}
			else
			{
				a=1;
			}
			if(Orgstate[i]!=a)
			{
				IOdeal((i+1202),a);
			}

		}
	}
	{
	for(int i=1; i<17;i++)
	{
		if(Instate[i]!=d1000_in_bit(i))
		{
			DWORD a;
			a=d1000_in_bit(i);
			IOdeal((i+2000),a);
		}
		//d1000_get_outbit(downstartout)
	}
	}


	{
	for(int i=33; i<49;i++)
	{
		if(Instate[i]!=d1000_in_bit(i))
		{
			DWORD a;
			a=d1000_in_bit(i);
			IOdeal((i+2000),a);
		}
		//d1000_get_outbit(downstartout)
	}
	}

	{
	for(int i=1; i<13;i++)
	{
		if(Outstate[i]!=d1000_get_outbit(i))
		{
			DWORD a;
			a=d1000_get_outbit(i);
			IOdeal((i+2100),a);
		}
		//d1000_get_outbit(downstartout)
	}
	}

	{
	for(int i=33; i<45;i++)
	{
		if(Outstate[i]!=d1000_get_outbit(i))
		{
			DWORD a;
			a=d1000_get_outbit(i);
			IOdeal((i+2100),a);
		}
		//d1000_get_outbit(downstartout)
	}
	}
	CDialog::OnTimer(nIDEvent);
}

void CIOMonitor::IOdeal(int id, DWORD out)
{
	CStatic* pWnd=(CStatic*)GetDlgItem(id);
    CBitmap bitmap;
	HBITMAP hBmp;
	if(out==0)
	{
        bitmap.LoadBitmap(IDB_BITMAP4);
	}
	else
	{
        bitmap.LoadBitmap(IDB_BITMAP5);
	}
	hBmp=(HBITMAP)bitmap.GetSafeHandle();
	pWnd->SetBitmap(hBmp);
	//pWnd->SetWindowPos(NULL,0,0,32,32,SWP_NOACTIVATE|SWP_NOMOVE|SWP_NOZORDER);
	DeleteObject(hBmp);

	if(id==2101)
	{
		for(int i=1174;i<1176;i++)
		{
			CStatic* pWnd=(CStatic*)GetDlgItem(i);
			CBitmap bitmap;
			HBITMAP hBmp;
			if(out==0)
			{
				bitmap.LoadBitmap(IDB_BITMAP4);
			}
			else
			{
				bitmap.LoadBitmap(IDB_BITMAP5);
			}
			hBmp=(HBITMAP)bitmap.GetSafeHandle();
			pWnd->SetBitmap(hBmp);
			//pWnd->SetWindowPos(NULL,0,0,32,32,SWP_NOACTIVATE|SWP_NOMOVE|SWP_NOZORDER);
			DeleteObject(hBmp);
		}
	}
	if(id==2133)
	{
		for(int i=1176;i<1178;i++)
		{
			CStatic* pWnd=(CStatic*)GetDlgItem(i);
			CBitmap bitmap;
			HBITMAP hBmp;
			if(out==0)
			{
				bitmap.LoadBitmap(IDB_BITMAP4);
			}
			else
			{
				bitmap.LoadBitmap(IDB_BITMAP5);
			}
			hBmp=(HBITMAP)bitmap.GetSafeHandle();
			pWnd->SetBitmap(hBmp);
			//pWnd->SetWindowPos(NULL,0,0,32,32,SWP_NOACTIVATE|SWP_NOMOVE|SWP_NOZORDER);
			DeleteObject(hBmp);
		}
	}
}
