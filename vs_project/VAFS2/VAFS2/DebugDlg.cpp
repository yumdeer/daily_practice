// DebugDlg.cpp : implementation file
//

#include "stdafx.h"
#include "VAFS2.h"
#include "DebugDlg.h"
#include "VisionSetDlg.h"
#include "externs.h"
#include "PARAMETERSET.h"
#include "dmc1000.h"  //包含1000B库头文件


#ifdef _DEBUG
#define new DEBUG_NEW  
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

unsigned char tongueprocess=0;
DWORD Lblocksave,Lvacuumsave,Pleftsave,Prightsave,Probotvacuumsave,Pturnsave,Pclipsave, Pdownsave,Pflowsave,Pleftvacuumsave	,Prightvacuumsave, Pdownvacuumsave,Lclippressoutsave,Ltrayoutsave,Ltrayvacuumsave ;
bool manualstart=false;
//定义四个轴的常量
const int XCH = 0;
const int YCH = 1;
const int ZCH = 2;

const int UCH = 3;

/////////////////////////////////////////////////////////////////////////////
// CDebugDlg dialog


CDebugDlg::CDebugDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDebugDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDebugDlg)
	m_JOGS = 10.0f;
	m_JOGV = 10000.0f;
	m_pasteangle = 0;
	m_pastex = 0;
	m_pastey = 0;
	m_photox = 0;
	m_photoy = 0;
	m_pickangle = 0;
	m_pickx = 0;
	m_picky = 0;
	m_stateinfo = _T("");
	m_photox2 = 0;
	m_photoy2 = 0;
	m_tonguein = 0;
	m_tongueout = 0;
	m_zpick = 0;
	m_repasteangle = 0;
	m_repastex = 0;
	m_repastey = 0;
	//}}AFX_DATA_INIT
}


void CDebugDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDebugDlg)
	DDX_Text(pDX, IDC_JOGS, m_JOGS);
	DDX_Text(pDX, IDC_JOGV, m_JOGV);
	DDX_Text(pDX, IDC_pasteangled, m_pasteangle);
	DDX_Text(pDX, IDC_pastexd, m_pastex);
	DDV_MinMaxLong(pDX, m_pastex, -50000, 50000);
	DDX_Text(pDX, IDC_pasteyd, m_pastey);
	DDV_MinMaxLong(pDX, m_pastey, -50000, 50000);
	DDX_Text(pDX, IDC_photoxd, m_photox);
	DDX_Text(pDX, IDC_photoyd, m_photoy);
	DDX_Text(pDX, IDC_pickangled, m_pickangle);
	DDX_Text(pDX, IDC_pickxd, m_pickx);
	DDV_MinMaxLong(pDX, m_pickx, -50000, 50000);
	DDX_Text(pDX, IDC_pickyd, m_picky);
	DDV_MinMaxLong(pDX, m_picky, -50000, 50000);
	DDX_Text(pDX, IDC_stateinfo, m_stateinfo);
	DDX_Text(pDX, IDC_photoxd2, m_photox2);
	DDX_Text(pDX, IDC_photoyd2, m_photoy2);
	DDX_Text(pDX, IDC_tongueind, m_tonguein);
	DDV_MinMaxLong(pDX, m_tonguein, 0,60000);
	DDX_Text(pDX, IDC_tongueoutd, m_tongueout);
	DDV_MinMaxLong(pDX, m_tongueout, 0, 60000);
	DDX_Text(pDX, IDC_zpick, m_zpick);
	DDV_MinMaxLong(pDX, m_zpick, -50000, 50000);
	DDX_Text(pDX, IDC_repasteangled, m_repasteangle);
	DDX_Text(pDX, IDC_repastexd, m_repastex);
	DDX_Text(pDX, IDC_repasteyd, m_repastey);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDebugDlg, CDialog)
	//{{AFX_MSG_MAP(CDebugDlg)
	ON_BN_CLICKED(IDC_Vision, OnVision)
	ON_BN_CLICKED(IDC_XSTEPP, OnXstepp)
	ON_BN_CLICKED(IDC_XSTEPM, OnXstepm)
	ON_BN_CLICKED(IDC_YSTEPP, OnYstepp)
	ON_BN_CLICKED(IDC_YSTEPM, OnYstepm)
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_EN_CHANGE(IDC_JOGS, OnChangeJogs)
	ON_BN_CLICKED(IDC_pastestepp, Onpastestepp)
	/*ON_BN_CLICKED(IDC_fixturestepp, Onfixturestepp)*/
	ON_BN_CLICKED(IDC_parasetup, Onparasetup)
	ON_EN_SETFOCUS(IDC_pickxd, OnSetfocuspickx)
	ON_EN_KILLFOCUS(IDC_pickxd, OnKillfocuspickx)
	ON_EN_SETFOCUS(IDC_pickyd, OnSetfocuspicky)
	ON_EN_KILLFOCUS(IDC_pickyd, OnKillfocuspicky)
	ON_EN_SETFOCUS(IDC_photoxd, OnSetfocusphotox)
	ON_EN_KILLFOCUS(IDC_photoxd, OnKillfocusphotox)
	ON_EN_SETFOCUS(IDC_photoyd, OnSetfocusphotoy)
	ON_EN_KILLFOCUS(IDC_photoyd, OnKillfocusphotoy)
	ON_EN_SETFOCUS(IDC_pastexd, OnSetfocuspastex)
	ON_EN_KILLFOCUS(IDC_pastexd, OnKillfocuspastex)
	ON_EN_SETFOCUS(IDC_pasteyd, OnSetfocuspastey)
	ON_EN_KILLFOCUS(IDC_pasteyd, OnKillfocuspastey)
	ON_BN_CLICKED(IDC_softkey2, Onsoftkey2)
	ON_BN_CLICKED(IDC_cyclephoto, Oncyclephoto)
	ON_EN_SETFOCUS(IDC_JOGS, OnSetfocusJogs)
	ON_EN_KILLFOCUS(IDC_JOGS, OnKillfocusJogs)
	ON_EN_SETFOCUS(IDC_JOGV, OnSetfocusJogv)
	ON_EN_KILLFOCUS(IDC_JOGV, OnKillfocusJogv)
	ON_BN_CLICKED(IDC_counterzero, Oncounterzero)
	ON_EN_SETFOCUS(IDC_pasteangled, OnSetfocustrunplateout)
	ON_EN_KILLFOCUS(IDC_pasteangled, OnKillfocustrunplateout)
	ON_EN_SETFOCUS(IDC_pickangled, OnSetfocusturnplatein)
	ON_EN_KILLFOCUS(IDC_pickangled, OnKillfocusturnplatein)
	ON_BN_CLICKED(IDC_TURNPLATEP, OnTurnplatep)
	ON_BN_CLICKED(IDC_TURNPLATEM, OnTurnplatem)
	ON_BN_CLICKED(IDC_Vision2, OnVision2)
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_cyclephoto2, Oncyclephoto2)
	ON_BN_CLICKED(IDC_Vision21, OnVision21)
	ON_BN_CLICKED(IDC_Vision22, OnVision22)
	ON_BN_CLICKED(IDC_Vision31, OnVision31)
	ON_BN_CLICKED(IDC_Vision32, OnVision32)
	ON_BN_CLICKED(IDC_Vision41, OnVision41)
	ON_BN_CLICKED(IDC_Vision42, OnVision42)
	ON_BN_CLICKED(IDC_zoomp, Onzoomp)
	ON_BN_CLICKED(IDC_zoomm, Onzoomm)
	ON_BN_CLICKED(IDC_zoompup, Onzoompup)
	ON_BN_CLICKED(IDC_zoomdown, Onzoomdown)
	ON_BN_CLICKED(IDC_zoomleft, Onzoomleft)
	ON_BN_CLICKED(IDC_zoomright, Onzoomright)
	ON_BN_CLICKED(IDC_mstart, Onmstart)
	ON_BN_CLICKED(IDC_mover, Onmover)
	//ON_BN_CLICKED(IDC_linestepm, Onlinestepm)
	//ON_BN_CLICKED(IDC_linestepp, Onlinestepp)
	ON_EN_SETFOCUS(IDC_photoxd2, OnSetfocusphotoxd2)
	ON_EN_KILLFOCUS(IDC_photoxd2, OnKillfocusphotoxd2)
	ON_EN_SETFOCUS(IDC_photoyd2, OnSetfocusphotoyd2)
	ON_EN_KILLFOCUS(IDC_photoyd2, OnKillfocusphotoyd2)
	ON_BN_CLICKED(IDC_TONGUEJOGP, OnTonguejogp)
	ON_BN_CLICKED(IDC_TONGUEJOGM, OnTonguejogm)
	ON_EN_SETFOCUS(IDC_tongueind, OnSetfocustongueind)
	ON_EN_KILLFOCUS(IDC_tongueind, OnKillfocustongueind)
	ON_EN_SETFOCUS(IDC_tongueoutd, OnSetfocustongueoutd)
	ON_EN_KILLFOCUS(IDC_tongueoutd, OnKillfocustongueoutd)
	ON_BN_CLICKED(IDC_YSTEPP2, OnZstepp)
	ON_BN_CLICKED(IDC_YSTEPM2, OnZstepm)
	ON_EN_SETFOCUS(IDC_zpick, OnSetfocuszpick)
	ON_EN_KILLFOCUS(IDC_zpick, OnKillfocuszpick)
	ON_BN_CLICKED(IDC_reloadaixlp, Onreloadaixlp)
	ON_BN_CLICKED(IDC_reloadaixlm, Onreloadaixlm)
	ON_BN_CLICKED(IDC_loadaxilp, Onloadaxilp)
	ON_BN_CLICKED(IDC_loadaxilm, Onloadaxilm)
	ON_EN_SETFOCUS(IDC_repasteangled, OnSetfocusrepasteangled)
	ON_EN_KILLFOCUS(IDC_repasteangled, OnKillfocusrepasteangled)
	ON_EN_SETFOCUS(IDC_repastexd, OnSetfocusrepastexd)
	ON_EN_KILLFOCUS(IDC_repastexd, OnKillfocusrepastexd)
	ON_EN_SETFOCUS(IDC_repasteyd, OnSetfocusrepasteyd)
	ON_EN_KILLFOCUS(IDC_repasteyd, OnKillfocusrepasteyd)
	/*ON_BN_CLICKED(IDC_placestepp, Onplacestepp)*/
	/*ON_BN_CLICKED(IDC_reloadstepp, Onreloadp)*/
	ON_BN_CLICKED(IDC_loadp, Onloadp)
	ON_BN_CLICKED(IDC_halfload, Onhalfload)
	ON_BN_CLICKED(IDC_loadopen, Onloadopen)
	ON_BN_CLICKED(IDC_unload, Onunload)
	ON_BN_CLICKED(IDC_halfunload, Onhalfunload)
	ON_BN_CLICKED(IDC_unloadopen, Onunloadopen)
	//ON_BN_CLICKED(IDC_cover, Oncover)
	//ON_BN_CLICKED(IDC_flow, Onflow)
	ON_BN_CLICKED(IDC_vacuum, Onvacuum)
	ON_BN_CLICKED(IDC_fixturevacuum, Onfixturevacuum)
	ON_BN_CLICKED(IDC_covervacuum, Oncovervacuum)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_loadpp, &CDebugDlg::OnBnClickedloadpp)
	ON_BN_CLICKED(IDC_loadmp, &CDebugDlg::OnBnClickedloadmp)
	ON_BN_CLICKED(IDC_unloadpp, &CDebugDlg::OnBnClickedunloadpp)
	ON_BN_CLICKED(IDC_unloadmp, &CDebugDlg::OnBnClickedunloadmp)
	//ON_BN_CLICKED(IDC_backlight, &CDebugDlg::OnBnClickedbacklight)
	ON_BN_CLICKED(IDC_unloadm, &CDebugDlg::OnBnClickedunloadm)
	ON_BN_CLICKED(IDC_unloadp, &CDebugDlg::OnBnClickedunloadp)
	ON_BN_CLICKED(IDC_loadpp2, &CDebugDlg::OnBnClickedloadpp2)
	ON_BN_CLICKED(IDC_unloadpp2, &CDebugDlg::OnBnClickedunloadpp2)
	ON_BN_CLICKED(IDC_loadpp3, &CDebugDlg::OnBnClickedloadpp3)
	ON_BN_CLICKED(IDC_unloadpp3, &CDebugDlg::OnBnClickedunloadpp3)
	ON_BN_CLICKED(IDC_loadmp2, &CDebugDlg::OnBnClickedloadmp2)
	ON_BN_CLICKED(IDC_unloadmp2, &CDebugDlg::OnBnClickedunloadmp2)
	ON_BN_CLICKED(IDC_loadmp3, &CDebugDlg::OnBnClickedloadmp3)
	ON_BN_CLICKED(IDC_unloadmp3, &CDebugDlg::OnBnClickedunloadmp3)
	ON_BN_CLICKED(IDC_Lblock, &CDebugDlg::OnBnClickedLblock)
	ON_BN_CLICKED(IDC_Lvacuum, &CDebugDlg::OnBnClickedLvacuum)

	ON_BN_CLICKED(IDC_Pright, &CDebugDlg::OnBnClickedPright)
	ON_BN_CLICKED(IDC_Probotvacuum, &CDebugDlg::OnBnClickedPronbotvacuum)
	ON_BN_CLICKED(IDC_Ptrun, &CDebugDlg::OnBnClickedPtrun)
	ON_BN_CLICKED(IDC_Pclip, &CDebugDlg::OnBnClickedPclip)
	ON_BN_CLICKED(IDC_Pdown, &CDebugDlg::OnBnClickedPdown)
	ON_BN_CLICKED(IDC_Pflow, &CDebugDlg::OnBnClickedPflow)
	ON_BN_CLICKED(IDC_Pleftvacuum, &CDebugDlg::OnBnClickedPleftvacuum)
	ON_BN_CLICKED(IDC_Prightvacuum, &CDebugDlg::OnBnClickedPrightvacuum)
	ON_BN_CLICKED(IDC_Pdownvacuum, &CDebugDlg::OnBnClickedPdownvacuum)
	ON_BN_CLICKED(IDC_linstepp, &CDebugDlg::OnBnClickedlinstepp)
	ON_BN_CLICKED(IDC_loutstepp, &CDebugDlg::OnBnClickedloutstepp)
	ON_BN_CLICKED(IDC_llstepp, &CDebugDlg::OnBnClickedllstepp)
	ON_BN_CLICKED(IDC_leftstepp, &CDebugDlg::OnBnClickedleftstepp)
	ON_BN_CLICKED(IDC_rightstepp, &CDebugDlg::OnBnClickedrightstepp)
	ON_BN_CLICKED(IDC_peelstepp, &CDebugDlg::OnBnClickedpeelstepp)
	ON_BN_CLICKED(IDC_unloadstepp, &CDebugDlg::OnBnClickedunloadstepp)
	//ON_BN_CLICKED(IDC_Pleft, &CDebugDlg::OnBnClickedPleft)
	ON_BN_CLICKED(IDC_Pright2, &CDebugDlg::OnBnClickedPright2)
	//ON_BN_CLICKED(IDOK, &CDebugDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_ClipRoller, &CDebugDlg::OnBnClickedCliproller)
	ON_BN_CLICKED(IDC_TRAY, &CDebugDlg::OnBnClickedTray)
	ON_BN_CLICKED(IDC_TRAYVACUUM, &CDebugDlg::OnBnClickedTrayvacuum)
	ON_BN_CLICKED(IDC_cyclephoto3, &CDebugDlg::OnBnClickedcyclephoto3)
	END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDebugDlg message handlers

void CDebugDlg::OnVision() 
{
	// TODO: Add your control notification handler code here
	cyclephoto=false;
	cyclephoto2=false;
	cyclephoto3=false;
	cyclephoto4=false;
	initposition=false;
	//overphoto=0;
	startphoto=0;
	startphoto2=0;
	startphoto3=0;
	startphoto4=0;


	int modalselecttemp;
	modalselecttemp=modalselect;
    modalselect=0;
	cameraselect=0;
	visionx=model1y[0];
	visiony=model1x[0];
	//revisionx=remodel11y;
	//revisiony=remodel11x;
	//m_Window.CloseWindow();
	CVisionSetDlg dlg;
	dlg.DoModal();
	modalselect=modalselecttemp;
	//reloadmod=true;

   
	

	
}

BOOL CDebugDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	SetTimer( IDC_TIMER, 100, NULL );
	 m_stateinfo=stateinfo;
	 
	 GetDlgItem(IDC_mover)->EnableWindow(0);

	    m_pickx=pickx;
		m_zpick=zpick;
		m_pastex=pastex;
		m_tonguein=tonguein;
		m_tongueout=tongueout;
		m_repasteangle=repasteangle;
		m_repastex=repastex;
		m_repastey=repastey;

		
		m_photox=photox;
  	    m_photoy=photoy;
		m_photox2=photox2;
  	    m_photoy2=photoy2;
		m_picky=picky;
		m_pastey=pastey;
	
		
	
		m_pasteangle=pasteangle;
		m_pickangle=pickangle;

	
		
	  GetDlgItem(IDC_Lblock)->EnableWindow(0);
	  GetDlgItem(IDC_Lvacuum)->EnableWindow(0);
	  GetDlgItem(IDC_Pright2)->EnableWindow(0);
	  GetDlgItem(IDC_Pright)->EnableWindow(0);
	  GetDlgItem(IDC_Probotvacuum)->EnableWindow(0);
	  GetDlgItem(IDC_Ptrun)->EnableWindow(0);
	  GetDlgItem(IDC_Pclip)->EnableWindow(0);
	  GetDlgItem(IDC_Pdown)->EnableWindow(0);
	  GetDlgItem(IDC_Pflow)->EnableWindow(0);
	  GetDlgItem(IDC_Pleftvacuum)->EnableWindow(0);
	  GetDlgItem(IDC_Prightvacuum)->EnableWindow(0);
	  GetDlgItem(IDC_Pdownvacuum)->EnableWindow(0);
	  GetDlgItem(IDC_halfload)->EnableWindow(0);
	  GetDlgItem(IDC_ClipRoller)->EnableWindow(0);
      GetDlgItem(IDC_TRAY)->EnableWindow(0);
	  GetDlgItem(IDC_TRAYVACUUM)->EnableWindow(0);
	  

					



	HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{
		::SendMessage(h,WM_CLOSE,0,0);
		SetDlgItemText(IDC_softkey2,"键盘");
	}

	 UpdateData(false);
	 MoveWindow(540,0,520,630);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



void CDebugDlg::OnTimer(UINT nIDEvent) 
{
  

	// TODO: Add your message handler code here and/or call default
	static CString string ;
	//int a;
	//a=atoi(C4cpx);
	string.Format("%.0f",C4cpx*100 );
	//string.Format("%ld",string*1000 );
	GetDlgItem( IDC_POSITIONX )->SetWindowText( string );

   
	string.Format("%.0f",C4cpy*100 );
	//string.Format("%ld",string*1000 );
	GetDlgItem( IDC_POSITIONY )->SetWindowText( string );

	string.Format("%.0f",C4cpu*1000 );
	//string.Format("%ld",string*1000 );
	GetDlgItem( IDC_POSITIONTURNPLATE )->SetWindowText( string ); 

		string.Format("%.0f",C4cpz*100 );
		//string.Format("%ld",string*1000 );
	GetDlgItem( IDC_POSITIONmainroller )->SetWindowText( string );

	string.Format("%ld",long( d1000_get_command_pos( 0 )) );
	GetDlgItem( IDC_left )->SetWindowText( string );
	
	string.Format("%ld",long( d1000_get_command_pos( 1 )) );
	GetDlgItem( IDC_right )->SetWindowText( string );

	string.Format("%ld",long( d1000_get_command_pos( 2 )) );
	GetDlgItem( IDC_peel )->SetWindowText( string );

	string.Format("%ld",long( d1000_get_command_pos( 3 )) );
	GetDlgItem( IDC_unloadposition )->SetWindowText( string );

     if(disablelinstepp==true)
	{
		GetDlgItem(IDC_linstepp)->EnableWindow(false);
	}
    
    if(disableloutstepp==true)
	{
		GetDlgItem(IDC_loutstepp)->EnableWindow(false);
	}
	if(disablellstepp==true)
	{
		GetDlgItem(IDC_llstepp)->EnableWindow(false);

	}
	  if(disablemainstepp==true)
	{
		GetDlgItem(IDC_pastestepp)->EnableWindow(false);
	}


     if(disablelinstepp==false)
	{
		GetDlgItem(IDC_linstepp)->EnableWindow(true);
	}
    
    if(disableloutstepp==false)
	{
		GetDlgItem(IDC_loutstepp)->EnableWindow(true);
	}
	if(disablellstepp==false)
	{
		GetDlgItem(IDC_llstepp)->EnableWindow(true);

	}
	  if(disablemainstepp==false)
	{
		GetDlgItem(IDC_pastestepp)->EnableWindow(true);
	}
   

	   if(disableleftstepp==true)
	{
		GetDlgItem(IDC_leftstepp)->EnableWindow(false);
	}
    
    if(disablerightstepp==true)
	{
		GetDlgItem(IDC_rightstepp)->EnableWindow(false);
	}
	if(disablepeelstepp==true)
	{
		GetDlgItem(IDC_peelstepp)->EnableWindow(false);

	}
	  if(disableunloadstepp==true)
	{
		GetDlgItem(IDC_unloadstepp)->EnableWindow(false);
	}


     if(disableleftstepp==false)
	{
		GetDlgItem(IDC_leftstepp)->EnableWindow(true);
	}
    
    if(disablerightstepp==false)
	{
		GetDlgItem(IDC_rightstepp)->EnableWindow(true);
	}
	if(disablepeelstepp==false)
	{
		GetDlgItem(IDC_peelstepp)->EnableWindow(true);

	}
	  if(disableunloadstepp==false)
	{
		GetDlgItem(IDC_unloadstepp)->EnableWindow(true);
	}

   
   m_stateinfo=stateinfo;
   UpdateData(false);
   
   
	


	
	CDialog::OnTimer(nIDEvent);
}


void CDebugDlg::OnDestroy() 
{
	
	
	CFile currentpara;
	currentpara.Open(currentparametername,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);
    CArchive currentparaar(&currentpara,CArchive::store);
    currentparaar<<PARAINPUT;
	currentparaar.Close();
	currentpara.Close();
	cyclephoto=false;
		initposition=false;
	cyclephoto2=false;
	KillTimer( IDC_TIMER );	//在关闭控制卡之前先关闭定时器
//	d1000_board_close();	//关闭控制卡(此句一定要有) 
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	
}

void CDebugDlg::OnOK() 
{
	// TODO: Add extra validation here
	  cyclephoto2=false;
	  cyclephoto=false;
	
	CDialog::OnOK();

}

void CDebugDlg::OnChangeJogs() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}




void CDebugDlg::Onpastestepp() 
{
	// TODO: Add your control notification handler code here
	mainstepp=true;
	cyclephoto=false;
	cyclephoto2=false;
		initposition=false;
	SetTimer( IDC_TIMER, 100, NULL );

	
}





void CDebugDlg::Onparasetup() 
{
	// TODO: Add your control notification handler code here
	PARAMETERSET dlg;
		cyclephoto=false;
		cyclephoto2=false;
			initposition=false;
	//overphoto=0;
	startphoto=0;
	startphoto2=0;
	dlg.DoModal();
	m_zpick=zpick;
		m_pickx=pickx;
		m_pastex=pastex;
			m_repasteangle=repasteangle;
		m_repastex=repastex;
		m_repastey=repastey;
			m_tonguein=tonguein;
		m_tongueout=tongueout;
		
		m_photox=photox;
  		m_photoy=photoy;
		m_picky=picky;
		m_pastey=pastey;
	
	
				m_pasteangle=pasteangle;
		m_pickangle=pickangle;

	 UpdateData(false);
}



void CDebugDlg::OnSetfocuspickx() 
{
	// TODO: Add your control notification handler code here
	KillTimer(IDC_TIMER);
	  CWnd * cwnd=GetDlgItem(IDC_pickxd);
	  HWND handle;
	  handle=cwnd->GetSafeHwnd();
	  RECT r;
	  ::GetWindowRect(handle,&r);
	  HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	WinExec("c:\\windows\\system32\\osk.exe",SW_SHOWNORMAL);
    h=::FindWindow(NULL,"屏幕键盘");
	::MoveWindow(h,0,r.bottom,1024,400,true);
	GetDlgItem(IDC_pickxd)->PostMessage(EM_SETSEL,0,-1);
	

    
	pickx=m_pickx;
	
	
	
}

void CDebugDlg::OnKillfocuspickx() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	pickx=m_pickx;
	  HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
    
	
	
}

void CDebugDlg::OnSetfocuspicky() 
{
	// TODO: Add your control notification handler code here
	KillTimer(IDC_TIMER);
	 CWnd * cwnd=GetDlgItem(IDC_pickyd);
	  HWND handle;
	  handle=cwnd->GetSafeHwnd();
	  RECT r;
	  ::GetWindowRect(handle,&r);
	  HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	WinExec("c:\\windows\\system32\\osk.exe",SW_SHOWNORMAL);
    h=::FindWindow(NULL,"屏幕键盘");
	::MoveWindow(h,0,r.bottom,1024,400,true);
	GetDlgItem(IDC_pickyd)->PostMessage(EM_SETSEL,0,-1);
	picky=m_picky;

	
}

void CDebugDlg::OnKillfocuspicky() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	picky=m_picky;
	HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}

	 
	//SetTimer( IDC_TIMER, 100, NULL );
	
}

void CDebugDlg::OnSetfocusphotox() 
{
	// TODO: Add your control notification handler code here
	KillTimer(IDC_TIMER);
	 CWnd * cwnd=GetDlgItem(IDC_photoxd);
	  HWND handle;
	  handle=cwnd->GetSafeHwnd();
	  RECT r;
	  ::GetWindowRect(handle,&r);
	  HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	WinExec("c:\\windows\\system32\\osk.exe",SW_SHOWNORMAL);
    h=::FindWindow(NULL,"屏幕键盘");
	::MoveWindow(h,0,r.bottom,1024,400,true);
	GetDlgItem(IDC_photoxd)->PostMessage(EM_SETSEL,0,-1);
	photox=m_photox;

	 
}

void CDebugDlg::OnKillfocusphotox() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	photox=m_photox;
	HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	 
//	SetTimer( IDC_TIMER, 100, NULL );
	
}

void CDebugDlg::OnSetfocusphotoy() 
{
	// TODO: Add your control notification handler code here
	KillTimer(IDC_TIMER);
	 CWnd * cwnd=GetDlgItem(IDC_photoyd);
	  HWND handle;
	  handle=cwnd->GetSafeHwnd();
	  RECT r;
	  ::GetWindowRect(handle,&r);
	  HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	WinExec("c:\\windows\\system32\\osk.exe",SW_SHOWNORMAL);
    h=::FindWindow(NULL,"屏幕键盘");
	::MoveWindow(h,0,r.bottom,1024,400,true);
	GetDlgItem(IDC_photoyd)->PostMessage(EM_SETSEL,0,-1);
	photoy=m_photoy;

	
}

void CDebugDlg::OnKillfocusphotoy() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	photoy=m_photoy;
	HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	 
//	SetTimer( IDC_TIMER, 100, NULL );
	
}

void CDebugDlg::OnSetfocuspastex() 
{
	// TODO: Add your control notification handler code here
	KillTimer(IDC_TIMER);
	cyclephoto2=false;
	 CWnd * cwnd=GetDlgItem(IDC_pastexd);
	  HWND handle;
	  handle=cwnd->GetSafeHwnd();
	  RECT r;
	  ::GetWindowRect(handle,&r);
	  HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	WinExec("c:\\windows\\system32\\osk.exe",SW_SHOWNORMAL);
    h=::FindWindow(NULL,"屏幕键盘");
	::MoveWindow(h,0,r.bottom,1024,400,true);
	GetDlgItem(IDC_pastexd)->PostMessage(EM_SETSEL,0,-1);
	pastex=m_pastex;
	
	
}

void CDebugDlg::OnKillfocuspastex() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	pastex=m_pastex;
	HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	 
	//SetTimer( IDC_TIMER, 100, NULL );
	
}








void CDebugDlg::OnSetfocuspastey() 
{
	// TODO: Add your control notification handler code here
	KillTimer(IDC_TIMER);
	cyclephoto2=false;
	 CWnd * cwnd=GetDlgItem(IDC_pasteyd);
	  HWND handle;
	  handle=cwnd->GetSafeHwnd();
	  RECT r;
	  ::GetWindowRect(handle,&r);
	  HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	WinExec("c:\\windows\\system32\\osk.exe",SW_SHOWNORMAL);
    h=::FindWindow(NULL,"屏幕键盘");
	::MoveWindow(h,0,r.bottom,1024,400,true);
	GetDlgItem(IDC_pasteyd)->PostMessage(EM_SETSEL,0,-1);
	pastey=m_pastey;
	
	
}

void CDebugDlg::OnKillfocuspastey() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	pastey=m_pastey;
	HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	 
	//SetTimer( IDC_TIMER, 100, NULL );
	
}

void CDebugDlg::Onsoftkey2() 
{
	// TODO: Add your control notification handler code here
		HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{
		::SendMessage(h,WM_CLOSE,0,0);
		SetDlgItemText(IDC_softkey2,"键盘");
	}
	else
	{
		WinExec("c:\\windows\\system32\\osk.exe",SW_SHOWNORMAL);
		SetDlgItemText(IDC_softkey2,"键盘");
	}
	
}

void CDebugDlg::Oncyclephoto() 
{
	// TODO: Add your control notification handler code here
	 cyclephoto=true;
	 
	cyclephoto2=false;
	cyclephoto3=false;
	cyclephoto4=false;
	initposition=false;


	//overphoto=0;

	startphoto2=0;
	zoomfactor=1;
	zoomupdown=0;
	zoomleftright=0;
	//set_part(m_Window2id,0,0,camera2width,camera2height);
	//set_part(m_Windowid,0,0,camera1width,camera1height);
	
}

void CDebugDlg::OnSetfocusJogs() 
{
	// TODO: Add your control notification handler code here
	KillTimer(IDC_TIMER);
	 CWnd * cwnd=GetDlgItem(IDC_JOGS);
	  HWND handle;
	  handle=cwnd->GetSafeHwnd();
	  RECT r;
	  ::GetWindowRect(handle,&r);
	  HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	WinExec("c:\\windows\\system32\\osk.exe",SW_SHOWNORMAL);
    h=::FindWindow(NULL,"屏幕键盘");
	::MoveWindow(h,0,r.bottom,1024,400,true);
	GetDlgItem(IDC_JOGS)->PostMessage(EM_SETSEL,0,-1);
	
}

void CDebugDlg::OnKillfocusJogs() 
{
	// TODO: Add your control notification handler code here
		UpdateData(true);
	HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	 
//	SetTimer( IDC_TIMER, 100, NULL );
	
}

void CDebugDlg::OnSetfocusJogv() 
{
	// TODO: Add your control notification handler code here
	KillTimer(IDC_TIMER);
	 CWnd * cwnd=GetDlgItem(IDC_JOGV);
	  HWND handle;
	  handle=cwnd->GetSafeHwnd();
	  RECT r;
	  ::GetWindowRect(handle,&r);
	  HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	WinExec("c:\\windows\\system32\\osk.exe",SW_SHOWNORMAL);
    h=::FindWindow(NULL,"屏幕键盘");
	::MoveWindow(h,0,r.bottom,1024,400,true);
	GetDlgItem(IDC_JOGV)->PostMessage(EM_SETSEL,0,-1);
}

void CDebugDlg::OnKillfocusJogv() 
{
	// TODO: Add your control notification handler code here
		UpdateData(true);
			HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	
	 
	//SetTimer( IDC_TIMER, 100, NULL );
	
}

void CDebugDlg::Oncounterzero() 
{
	// TODO: Add your control notification handler code here
	pastecounter=0;
	
}

void CDebugDlg::OnSetfocustrunplateout() 
{
	// TODO: Add your control notification handler code here
	KillTimer(IDC_TIMER);
	cyclephoto2=false;
	 CWnd * cwnd=GetDlgItem(IDC_pasteangled);
	  HWND handle;
	  handle=cwnd->GetSafeHwnd();
	  RECT r;
	  ::GetWindowRect(handle,&r);
	  HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	WinExec("c:\\windows\\system32\\osk.exe",SW_SHOWNORMAL);
    h=::FindWindow(NULL,"屏幕键盘");
	::MoveWindow(h,0,r.bottom,1024,400,true);
	GetDlgItem(IDC_pasteangled)->PostMessage(EM_SETSEL,0,-1);
	pasteangle=m_pasteangle;

	
}

void CDebugDlg::OnKillfocustrunplateout() 
{
	// TODO: Add your control notification handler code here
		UpdateData(true);
	pasteangle=m_pasteangle;
	HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	
}

void CDebugDlg::OnSetfocusturnplatein() 
{
	// TODO: Add your control notification handler code here
	KillTimer(IDC_TIMER);
	 CWnd * cwnd=GetDlgItem(IDC_pickangled);
	  HWND handle;
	  handle=cwnd->GetSafeHwnd();
	  RECT r;
	  ::GetWindowRect(handle,&r);
	  HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	WinExec("c:\\windows\\system32\\osk.exe",SW_SHOWNORMAL);
    h=::FindWindow(NULL,"屏幕键盘");
	::MoveWindow(h,0,r.bottom,1024,400,true);
	GetDlgItem(IDC_pickangled)->PostMessage(EM_SETSEL,0,-1);
	pickangle=m_pickangle;

	
}

void CDebugDlg::OnKillfocusturnplatein() 
{
	// TODO: Add your control notification handler code here
		UpdateData(true);
	pickangle=m_pickangle;
	HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	
}











void CDebugDlg::OnVision2() 
{
	// TODO: Add your control notification handler code here
	cyclephoto=false;
	cyclephoto2=false;
	cyclephoto3=false;
	cyclephoto4=false;
		initposition=false;
	//overphoto=0;
	startphoto=0;
	startphoto2=0;
	startphoto3=0;
	startphoto4=0;
	int modalselecttemp;
	modalselecttemp=modalselect;

	modalselect=1;
	cameraselect=0;
	visionx=model2y[0];
	visiony=model2x[0];
	//	revisionx=remodel21y;
	//revisiony=remodel21x;

	CVisionSetDlg dlg;
	dlg.DoModal();
	modalselect=modalselecttemp;
	//reloadmod=true;
	
	
}


void CDebugDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	  HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	
	CDialog::OnLButtonDown(nFlags, point);
}

void CDebugDlg::Oncyclephoto2() 
{
	// TODO: Add your control notification handler code here
	cyclephoto2=true;
	cyclephoto=false;
	cyclephoto3=false;
	cyclephoto4=false;
		initposition=false;


	//overphoto=0;
	startphoto2=0;
	zoomfactor=1;
	zoomupdown=0;
	zoomleftright=0;
	set_part(m_Window2id,0,0,camera2width,camera2height);

	
}

void CDebugDlg::OnVision21() 
{
	// TODO: Add your control notification handler code here
	cyclephoto=false;
	cyclephoto2=false;
	cyclephoto3=false;
	cyclephoto4=false;
		initposition=false;
	//overphoto=0;
	startphoto=0;
	startphoto2=0;
	startphoto3=0;
	startphoto4=0;
	int modalselecttemp;
	modalselecttemp=modalselect;
	modalselect=2;
	cameraselect=0;
    	visionx=remodel1y[0];
	visiony=remodel1x[0];
 //	revisionx=remodel21y;
	//revisiony=remodel21x;
	CVisionSetDlg dlg;
	dlg.DoModal();
	//reloadmod=true;
	modalselect=modalselecttemp;
	
}

void CDebugDlg::OnVision22() 
{
	// TODO: Add your control notification handler code here
	cyclephoto=false;
	cyclephoto2=false;
	cyclephoto3=false;
	cyclephoto4=false;
	//overphoto=0;
	startphoto=0;
	startphoto2=0;
	startphoto3=0;
	startphoto4=0;
	int modalselecttemp;
	modalselecttemp=modalselect;
	modalselect=3;
	cameraselect=0;
		visionx=remodel2y[0];
	visiony=remodel2x[0];
	//	revisionx=remodel22y;
	//revisiony=remodel22x;

	CVisionSetDlg dlg;
	dlg.DoModal();
	//reloadmod=true;
	modalselect=modalselecttemp;
	
}

void CDebugDlg::Oncyclephoto3() 
{
	// TODO: Add your control notification handler code here
	cyclephoto3=true;
	cyclephoto=false;
	cyclephoto2=false;
	cyclephoto4=false;
		initposition=false;


	//overphoto=0;
	startphoto3=0;
}

void CDebugDlg::Oncyclephoto4() 
{
	// TODO: Add your control notification handler code here
	cyclephoto4=true;
	cyclephoto=false;
	cyclephoto3=false;
	cyclephoto2=false;
	initposition=false;


	//overphoto=0;
	startphoto4=0;
	
}

void CDebugDlg::OnVision31() 
{
	// TODO: Add your control notification handler code here
	cyclephoto=false;
	cyclephoto2=false;
	cyclephoto3=false;
	cyclephoto4=false;
	//overphoto=0; 
	startphoto=0;
	startphoto2=0;
	startphoto3=0;
	startphoto4=0;
	initposition=false;
	int modalselecttemp;
	modalselecttemp=modalselect;
	modalselect=0;
	cameraselect=2;

	CVisionSetDlg dlg;
	dlg.DoModal();
	reloadmod=true;
	modalselect=modalselecttemp;
	
}

void CDebugDlg::OnVision32() 
{
	// TODO: Add your control notification handler code here
		cyclephoto=false;
	cyclephoto2=false;
	cyclephoto3=false;
	cyclephoto4=false;
	//overphoto=0;
	startphoto=0;
	startphoto2=0;
	startphoto3=0;
	startphoto4=0;
		initposition=false;
	int modalselecttemp;
	modalselecttemp=modalselect;
	modalselect=1;
	cameraselect=2;

	CVisionSetDlg dlg;
	dlg.DoModal();
	reloadmod=true;
	modalselect=modalselecttemp;
	
}

void CDebugDlg::OnVision41() 
{
	// TODO: Add your control notification handler code here
		cyclephoto=false;
	cyclephoto2=false;
	cyclephoto3=false;
	cyclephoto4=false;
		initposition=false;
	//overphoto=0;
	startphoto=0;
	startphoto2=0;
	startphoto3=0;
	startphoto4=0;
	int modalselecttemp;
	modalselecttemp=modalselect;
	modalselect=0;
	cameraselect=3;

	CVisionSetDlg dlg;
	dlg.DoModal();
	reloadmod=true;
	modalselect=modalselecttemp;
	
}

void CDebugDlg::OnVision42() 
{
	// TODO: Add your control notification handler code here
	cyclephoto=false;
	cyclephoto2=false;
	cyclephoto3=false;
	cyclephoto4=false;
		initposition=false;
	//overphoto=0;
	startphoto=0;
	startphoto2=0;
	startphoto3=0;
	startphoto4=0;
	int modalselecttemp;
	modalselecttemp=modalselect;
	modalselect=1;
	cameraselect=3;

	CVisionSetDlg dlg;
	dlg.DoModal();
	reloadmod=true;
	modalselect=modalselecttemp;
	
}



void CDebugDlg::Onzoomp() 
{
	// TODO: Add your control notification handler code here
	zoomfactor=zoomfactor+0.2;
	
}

void CDebugDlg::Onzoomm() 
{
	// TODO: Add your control notification handler code here
	if(zoomfactor>=0.2)
	zoomfactor=zoomfactor-0.2;
	
}

void CDebugDlg::Onzoompup() 
{
	// TODO: Add your control notification handler code here
	zoomupdown=zoomupdown+200;
	
}

void CDebugDlg::Onzoomdown() 
{
	// TODO: Add your control notification handler code here
	if(zoomupdown>=200)
	zoomupdown=zoomupdown-200;
	
}

void CDebugDlg::Onzoomleft() 
{
	// TODO: Add your control notification handler code here
	zoomleftright=zoomleftright+200;
	
}

void CDebugDlg::Onzoomright() 
{
	// TODO: Add your control notification handler code here
		if(zoomleftright>=200)
			zoomleftright=zoomleftright-200;
	
}



void CDebugDlg::Onmstart() 
{
	// TODO: Add your control notification handler code here
	manualstart=true;
	GetDlgItem(IDC_mover)->EnableWindow(1);
	Pleftsave=d1000_get_outbit(3);
	Prightsave=d1000_get_outbit(4);
	Probotvacuumsave=d1000_get_outbit(5);
	Pturnsave=d1000_get_outbit(6);
	Pclipsave=d1000_get_outbit(7);
	Pdownsave=d1000_get_outbit(8);
	Pflowsave=d1000_get_outbit(9);
	Pleftvacuumsave=d1000_get_outbit(10);
	Prightvacuumsave=d1000_get_outbit(11);
	Pdownvacuumsave =d1000_get_outbit(12);

	  GetDlgItem(IDC_Lblock)->EnableWindow(1);
	  GetDlgItem(IDC_Lvacuum)->EnableWindow(1);
	  GetDlgItem(IDC_Pright2)->EnableWindow(1);
	  GetDlgItem(IDC_Pright)->EnableWindow(1);
	  GetDlgItem(IDC_Probotvacuum)->EnableWindow(1);
	  GetDlgItem(IDC_Ptrun)->EnableWindow(1);
	  GetDlgItem(IDC_Pclip)->EnableWindow(1);
	  GetDlgItem(IDC_Pdown)->EnableWindow(1);
	  GetDlgItem(IDC_Pflow)->EnableWindow(1);
	  GetDlgItem(IDC_Pleftvacuum)->EnableWindow(1);
	  GetDlgItem(IDC_Prightvacuum)->EnableWindow(1);
	  GetDlgItem(IDC_Pdownvacuum)->EnableWindow(1);
	  GetDlgItem(IDC_halfload)->EnableWindow(1);
	  GetDlgItem(IDC_ClipRoller)->EnableWindow(1);
	  GetDlgItem(IDC_TRAY)->EnableWindow(1);
	  GetDlgItem(IDC_TRAYVACUUM)->EnableWindow(1);
				
					




	disablemainstepp=true;
	disablelinstepp=true;
	disableloutstepp=true;
	disablellstepp=true;
	disableleftstepp=true;
	disablerightstepp=true;
	disablepeelstepp=true;
	disableunloadstepp=true;
	GetDlgItem(IDOK)->EnableWindow(0);
}

void CDebugDlg::Onmover() 
{
	// TODO: Add your control notification handler code here
		manualstart=false;
	//GetDlgItem(IDC_mstart)->EnableWindow(0);

		d1000_out_bit(3,Pleftsave );
		d1000_out_bit(4,Prightsave );
		d1000_out_bit(5,Probotvacuumsave);

		d1000_out_bit(6,Pturnsave );
		d1000_out_bit(7,Pclipsave);
		d1000_out_bit(8,Pdownsave );
		d1000_out_bit(9,Pflowsave );
		d1000_out_bit(19,Pleftvacuumsave );
		d1000_out_bit(11,Prightvacuumsave );
		d1000_out_bit(12,Pdownvacuumsave );


	  GetDlgItem(IDC_Lblock)->EnableWindow(0);
	  GetDlgItem(IDC_Lvacuum)->EnableWindow(0);
	  GetDlgItem(IDC_Pright2)->EnableWindow(0);
	  GetDlgItem(IDC_Pright)->EnableWindow(0);
	  GetDlgItem(IDC_Probotvacuum)->EnableWindow(0);
	  GetDlgItem(IDC_Ptrun)->EnableWindow(0);
	  GetDlgItem(IDC_Pclip)->EnableWindow(0);
	  GetDlgItem(IDC_Pdown)->EnableWindow(0);
	  GetDlgItem(IDC_Pflow)->EnableWindow(0);
	  GetDlgItem(IDC_Pleftvacuum)->EnableWindow(0);
	  GetDlgItem(IDC_Prightvacuum)->EnableWindow(0);
	  GetDlgItem(IDC_Pdownvacuum)->EnableWindow(0);
	  GetDlgItem(IDC_halfload)->EnableWindow(0);
	  GetDlgItem(IDC_ClipRoller)->EnableWindow(0);
	  GetDlgItem(IDC_TRAY)->EnableWindow(0);
	  GetDlgItem(IDC_TRAYVACUUM)->EnableWindow(0);
		
	disablemainstepp=false;
	disablelinstepp=false;
	disableloutstepp=false;
	disablellstepp=false;
	disableleftstepp=false;
	disablerightstepp=false;
	disablepeelstepp=false;
	disableunloadstepp=false;
	GetDlgItem(IDOK)->EnableWindow(1);
	GetDlgItem(IDC_mover)->EnableWindow(0);
	
}








void CDebugDlg::OnXstepp() 
{
	// TODO: Add your control notification handler code here
	//SetTimer( IDC_TIMER, 100, NULL );
	//if( !UpdateData( TRUE ) ) return;
	//RCAPINet::SpelPoint pt;
	//float current;
	//array<float>^value;
	//value=m_spel->GetRobotPos(SpelRobotPosType::World,0,0,0);
	//current=value[0];
	//pt.Y=value[1];
	//pt.Z=value[2];
	//pt.U=value[3];
	//pt.V=value[4];
	//pt.W=value[5];

	//long jog=current+m_JOGS;

	//if(jog<19500)
	//{
	//
	//				pt.X=jog;
	//				m_spel->Go(%pt);
	//				m_spel->WaitCommandComplete();
	//	
	//}
	if(C4getPover==true)
	{
	SetTimer( IDC_TIMER, 100, NULL );
	if( !UpdateData( TRUE ) ) return;
	C4xjogadd=true;
	C4jogv=m_JOGS/100;
	}
}

void CDebugDlg::OnXstepm() 
{
	// TODO: Add your control notification handler code here
	if(C4getPover==true)
	{
	SetTimer( IDC_TIMER, 100, NULL );
	if( !UpdateData( TRUE ) ) return;
	C4xjogsub=true;
	C4jogv=m_JOGS/100;
	}
}

void CDebugDlg::OnYstepp() 
{
	// TODO: Add your control notification handler code here
	if(C4getPover==true)
	{
	SetTimer( IDC_TIMER, 100, NULL );
	if( !UpdateData( TRUE ) ) return;
	C4yjogadd=true;
	C4jogv=m_JOGS/100;
	}
}

void CDebugDlg::OnYstepm() 
{
	// TODO: Add your control notification handler code here
	if(C4getPover==true)
	{
	SetTimer( IDC_TIMER, 100, NULL );
	if( !UpdateData( TRUE ) ) return;
	C4yjogsub=true;
	C4jogv=m_JOGS/100;
	}
}


void CDebugDlg::OnRollerstepp() 
{
	// TODO: Add your control notification handler code here

		// TODO: Add your control notification handler code here

	
}

void CDebugDlg::OnRollerstepm() 
{
	// TODO: Add your control notification handler code here
	SetTimer( IDC_TIMER, 100, NULL );
		int m_JOGSM=-1*m_JOGS;
	if( !UpdateData( TRUE ) ) return;
		
	
}



void CDebugDlg::OnTurnplatep() 
{
	// TODO: Add your control notification handler code here
	if(C4getPover==true)
	{
	SetTimer( IDC_TIMER, 100, NULL );
	if( !UpdateData( TRUE ) ) return;
	C4ujogadd=true;
	C4jogv=m_JOGS/1000;
	}
	
}

void CDebugDlg::OnTurnplatem() 
{
	// TODO: Add your control notification handler code here
	if(C4getPover==true)
	{
	SetTimer( IDC_TIMER, 100, NULL );
	if( !UpdateData( TRUE ) ) return;
	C4ujogsub=true;
	C4jogv=m_JOGS/1000;
	}
}









void CDebugDlg::OnSetfocusphotoxd2() 
{
	// TODO: Add your control notification handler code here
		KillTimer(IDC_TIMER);
	 CWnd * cwnd=GetDlgItem(IDC_photoxd2);
	  HWND handle;
	  handle=cwnd->GetSafeHwnd();
	  RECT r;
	  ::GetWindowRect(handle,&r);
	  HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	WinExec("c:\\windows\\system32\\osk.exe",SW_SHOWNORMAL);
    h=::FindWindow(NULL,"屏幕键盘");
	::MoveWindow(h,0,r.bottom,1024,400,true);
	GetDlgItem(IDC_photoxd2)->PostMessage(EM_SETSEL,0,-1);
	photox2=m_photox2;
}

void CDebugDlg::OnKillfocusphotoxd2() 
{
	// TODO: Add your control notification handler code here
		UpdateData(true);
	photox2=m_photox2;
	HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	 
	//SetTimer( IDC_TIMER, 100, NULL );
	
}

void CDebugDlg::OnSetfocusphotoyd2() 
{
	// TODO: Add your control notification handler code here
		KillTimer(IDC_TIMER);
	 CWnd * cwnd=GetDlgItem(IDC_photoyd2);
	  HWND handle;
	  handle=cwnd->GetSafeHwnd();
	  RECT r;
	  ::GetWindowRect(handle,&r);
	  HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	WinExec("c:\\windows\\system32\\osk.exe",SW_SHOWNORMAL);
    h=::FindWindow(NULL,"屏幕键盘");
	::MoveWindow(h,0,r.bottom,1024,400,true);
	GetDlgItem(IDC_photoyd2)->PostMessage(EM_SETSEL,0,-1);
	photoy2=m_photoy2;
	
}

void CDebugDlg::OnKillfocusphotoyd2() 
{
	// TODO: Add your control notification handler code here
		UpdateData(true);
	photoy2=m_photoy2;
	HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	 
	//SetTimer( IDC_TIMER, 100, NULL );
	
}


void CDebugDlg::OnTonguejogp() 
{
		SetTimer( IDC_TIMER, 100, NULL );
	if( !UpdateData( TRUE ) ) return;
	long current=d1000_get_command_pos( 2 );
	long jog=current+m_JOGS;

	if( d1000_check_done(2) == 0 ) return;//若在运行，则返回
	if(jog<60000)
	{
		d1000_set_sd(2,0);
		d1000_set_pls_outmode(2,1);
		d1000_start_t_move( 2,m_JOGS, 0, m_JOGV, 0.3);//T形
	}

}

void CDebugDlg::OnTonguejogm() 
{
	// TODO: Add your control notification handler code here

SetTimer( IDC_TIMER, 100, NULL );
	int m_JOGSM=-1*m_JOGS;
	if( !UpdateData( TRUE ) ) return;
	long current=d1000_get_command_pos( 2);
	long jog=current+m_JOGSM;
	if( d1000_check_done(2) == 0 ) return;//若在运行，则返回
		if(jog>=0)
	{
		d1000_set_sd(2,0);
		d1000_set_pls_outmode(2,1);
		d1000_start_t_move( 2,m_JOGSM, 0, m_JOGV, 0.3);//T形
	}
}


void CDebugDlg::OnSetfocustongueind() 
{
	// TODO: Add your control notification handler code here

			KillTimer(IDC_TIMER);
	 CWnd * cwnd=GetDlgItem(IDC_tongueind);
	  HWND handle;
	  handle=cwnd->GetSafeHwnd();
	  RECT r;
	  ::GetWindowRect(handle,&r);
	  HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	WinExec("c:\\windows\\system32\\osk.exe",SW_SHOWNORMAL);
    h=::FindWindow(NULL,"屏幕键盘");
	::MoveWindow(h,0,r.bottom,1024,400,true);
	GetDlgItem(IDC_tongueind)->PostMessage(EM_SETSEL,0,-1);
	tonguein=m_tonguein;
	
}

void CDebugDlg::OnKillfocustongueind() 
{
	// TODO: Add your control notification handler code here
		UpdateData(true);
	tonguein=m_tonguein;
	HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	
}

void CDebugDlg::OnSetfocustongueoutd() 
{
	// TODO: Add your control notification handler code here

			KillTimer(IDC_TIMER);
	 CWnd * cwnd=GetDlgItem(IDC_tongueoutd);
	  HWND handle;
	  handle=cwnd->GetSafeHwnd();
	  RECT r;
	  ::GetWindowRect(handle,&r);
	  HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	WinExec("c:\\windows\\system32\\osk.exe",SW_SHOWNORMAL);
    h=::FindWindow(NULL,"屏幕键盘");
	::MoveWindow(h,0,r.bottom,1024,400,true);
	GetDlgItem(IDC_tongueoutd)->PostMessage(EM_SETSEL,0,-1);
	tongueout=m_tongueout;
	
}

void CDebugDlg::OnKillfocustongueoutd() 
{
	// TODO: Add your control notification handler code here
		UpdateData(true);
	tongueout=m_tongueout;
	HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	
}

void CDebugDlg::OnZstepp() 
{
	// TODO: Add your control notification handler code here
	if(C4getPover==true)
	{
	SetTimer( IDC_TIMER, 100, NULL );
	if( !UpdateData( TRUE ) ) return;
	C4zjogadd=true;
	C4jogv=m_JOGS/100;
	}
	
}

void CDebugDlg::OnZstepm() 
{
	// TODO: Add your control notification handler code here
	if(C4getPover==true)
	{
	SetTimer( IDC_TIMER, 100, NULL );
	if( !UpdateData( TRUE ) ) return;
	C4zjogsub=true;
	C4jogv=m_JOGS/100;
	}
	
}




void CDebugDlg::OnSetfocuszpick() 
{
	// TODO: Add your control notification handler code here
	
		KillTimer(IDC_TIMER);
	 CWnd * cwnd=GetDlgItem(IDC_zpick);
	  HWND handle;
	  handle=cwnd->GetSafeHwnd();
	  RECT r;
	  ::GetWindowRect(handle,&r);
	  HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	WinExec("c:\\windows\\system32\\osk.exe",SW_SHOWNORMAL);
    h=::FindWindow(NULL,"屏幕键盘");
	::MoveWindow(h,0,r.bottom,1024,400,true);
	GetDlgItem(IDC_zpick)->PostMessage(EM_SETSEL,0,-1);
	zpick=m_zpick;
	

	
}

void CDebugDlg::OnKillfocuszpick() 
{
	// TODO: Add your control notification handler code here

		UpdateData(true);
	zpick=m_zpick;
	HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	
}



void CDebugDlg::Onreloadaixlp() 
{
	// TODO: Add your control notification handler code here
		SetTimer( IDC_TIMER, 100, NULL );
	if( !UpdateData( TRUE ) ) return;
	long current=d1000_get_command_pos( 0 );
	long jog=current+m_JOGS;

	if( d1000_check_done(0) == 0 ) return;//若在运行，则返回
	if(jog<60000)
	{
		d1000_set_sd(0,0);
		d1000_set_pls_outmode(0,1);
		d1000_start_t_move( 0,m_JOGS, 0, m_JOGV, 0.3);//T形
	}
}



void CDebugDlg::Onreloadaixlm() 
{
	// TODO: Add your control notification handler code here
		SetTimer( IDC_TIMER, 100, NULL );
	int m_JOGSM=-1*m_JOGS;
	if( !UpdateData( TRUE ) ) return;
	long current=d1000_get_command_pos( 0);
	long jog=current+m_JOGSM;
	if( d1000_check_done(0 ) == 0 ) return;//若在运行，则返回
		if(jog>=0)
	{
		d1000_set_sd(0,0);
		d1000_set_pls_outmode(0,1);
		d1000_start_t_move( 0,m_JOGSM, 0, m_JOGV, 0.3);//T形
	}
}

void CDebugDlg::Onloadaxilp() 
{
	// TODO: Add your control notification handler code here
	SetTimer( IDC_TIMER, 100, NULL );
	if( !UpdateData( TRUE ) ) return;
	long current=d1000_get_command_pos( 1 );
	long jog=current+m_JOGS;

	if( d1000_check_done(1) == 0 ) return;//若在运行，则返回
	if(jog<60000)
	{
		d1000_set_sd(1,0);
		d1000_set_pls_outmode(1,1);
		d1000_start_t_move( 1,m_JOGS, 0, m_JOGV, 0.3);//T形
	}
	
}

void CDebugDlg::Onloadaxilm() 
{
	// TODO: Add your control notification handler code here
		SetTimer( IDC_TIMER, 100, NULL );
	int m_JOGSM=-1*m_JOGS;
	if( !UpdateData( TRUE ) ) return;
	long current=d1000_get_command_pos( 1);
	long jog=current+m_JOGSM;
	if( d1000_check_done(1 ) == 0 ) return;//若在运行，则返回
		if(jog>=0)
	{
		d1000_set_sd(1,0);
		d1000_set_pls_outmode(1,1);
		d1000_start_t_move( 1,m_JOGSM, 0, m_JOGV, 0.3);//T形
	}
}

void CDebugDlg::OnSetfocusrepasteangled() 
{
	// TODO: Add your control notification handler code here
			KillTimer(IDC_TIMER);
			cyclephoto2=false;
	 CWnd * cwnd=GetDlgItem(IDC_repasteangled);
	  HWND handle;
	  handle=cwnd->GetSafeHwnd();
	  RECT r;
	  ::GetWindowRect(handle,&r);
	  HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	WinExec("c:\\windows\\system32\\osk.exe",SW_SHOWNORMAL);
    h=::FindWindow(NULL,"屏幕键盘");
	::MoveWindow(h,0,r.bottom,1024,400,true);
	GetDlgItem(IDC_repasteangled)->PostMessage(EM_SETSEL,0,-1);
	repasteangle=m_repasteangle;
	
}

void CDebugDlg::OnKillfocusrepasteangled() 
{
	// TODO: Add your control notification handler code here
			UpdateData(true);
	repasteangle=m_repasteangle;
	HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	
}

void CDebugDlg::OnSetfocusrepastexd() 
{
	// TODO: Add your control notification handler code here
	cyclephoto2=false;
			KillTimer(IDC_TIMER);
	 CWnd * cwnd=GetDlgItem(IDC_repastexd);
	  HWND handle;
	  handle=cwnd->GetSafeHwnd();
	  RECT r;
	  ::GetWindowRect(handle,&r);
	  HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	WinExec("c:\\windows\\system32\\osk.exe",SW_SHOWNORMAL);
    h=::FindWindow(NULL,"屏幕键盘");
	::MoveWindow(h,0,r.bottom,1024,400,true);
	GetDlgItem(IDC_repastexd)->PostMessage(EM_SETSEL,0,-1);
	repastex=m_repastex;
	
}

void CDebugDlg::OnKillfocusrepastexd() 
{
	// TODO: Add your control notification handler code here
			UpdateData(true);
	repastex=m_repastex;
	HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	
}

void CDebugDlg::OnSetfocusrepasteyd() 
{
	// TODO: Add your control notification handler code here
	cyclephoto2=false;
		KillTimer(IDC_TIMER);
	 CWnd * cwnd=GetDlgItem(IDC_repasteyd);
	  HWND handle;
	  handle=cwnd->GetSafeHwnd();
	  RECT r;
	  ::GetWindowRect(handle,&r);
	  HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	WinExec("c:\\windows\\system32\\osk.exe",SW_SHOWNORMAL);
    h=::FindWindow(NULL,"屏幕键盘");
	::MoveWindow(h,0,r.bottom,1024,400,true);
	GetDlgItem(IDC_repasteyd)->PostMessage(EM_SETSEL,0,-1);
	repastey=m_repastey;

	
}

void CDebugDlg::OnKillfocusrepasteyd() 
{
	// TODO: Add your control notification handler code here
			UpdateData(true);
	repastey=m_repastey;
	HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	
}


//void CDebugDlg::Onreloadp() 
//{
//	// TODO: Add your control notification handler code here
//			reloadstepp=true;
//	cyclephoto=false;
//	cyclephoto2=false;
//		initposition=false;
//	SetTimer( IDC_TIMER, 100, NULL );
//	
//}

void CDebugDlg::Onloadp() 
{
	// TODO: Add your control notification handler code here
	DWORD state;
}

void CDebugDlg::Onhalfload() 
{
	// TODO: Add your control notification handler code here
	DWORD state;
}

void CDebugDlg::Onloadopen() 
{
	// TODO: Add your control notification handler code here
	DWORD state;
}

void CDebugDlg::Onunload() 
{
	// TODO: Add your control notification handler code here
	DWORD state;
}

void CDebugDlg::Onhalfunload() 
{
	// TODO: Add your control notification handler code here
	DWORD state;
}

void CDebugDlg::Onunloadopen() 
{
	// TODO: Add your control notification handler code here
	DWORD state;
}

void CDebugDlg::Oncover() 
{
	// TODO: Add your control notification handler code here
    DWORD state;
    state=d1000_get_outbit(7);
    if(state==1)
    {
        d1000_out_bit(7,0);
    }
    else
    {
        d1000_out_bit(7,1);
    }

	
}



void CDebugDlg::Onflow() 
{
	// TODO: Add your control notification handler code here

	   DWORD state;
	    state=d1000_get_outbit(8);
		if(state==1)
		{
			d1000_out_bit(8,0);
		}
		else
		{
			d1000_out_bit(8,1);
		}

	
}

void CDebugDlg::Onvacuum() 
{
	// TODO: Add your control notification handler code here
	   DWORD state;
	    state=d1000_get_outbit(6);
		if(state==1)
		{
			d1000_out_bit(6,0);    
		}
		else
		{
			d1000_out_bit(6,1);
		}

	
}

void CDebugDlg::Onfixturevacuum() 
{
	// TODO: Add your control notification handler code here
	DWORD state;
	    state=d1000_get_outbit(5);
		if(state==1)
		{
			d1000_out_bit(5,0);
		}
		else
		{
			d1000_out_bit(5,1);
		}
	
}

void CDebugDlg::Oncovervacuum() 
{
	// TODO: Add your control notification handler code here
	DWORD state;
}


void CDebugDlg::OnBnClickedloadpp()
{
	// TODO: 在此添加控件通知处理程序代码
	SetTimer( IDC_TIMER, 100, NULL );
	if( !UpdateData( TRUE ) ) return;
}


void CDebugDlg::OnBnClickedloadmp()
{
	// TODO: 在此添加控件通知处理程序代码
		SetTimer( IDC_TIMER, 100, NULL );
	int m_JOGSM=-1*m_JOGS;
	if( !UpdateData( TRUE ) ) return;
}


void CDebugDlg::OnBnClickedunloadpp()
{
	// TODO: 在此添加控件通知处理程序代码
	SetTimer( IDC_TIMER, 100, NULL );
	if( !UpdateData( TRUE ) ) return;
}


void CDebugDlg::OnBnClickedunloadmp()
{
	// TODO: 在此添加控件通知处理程序代码
    SetTimer( IDC_TIMER, 100, NULL );
	int m_JOGSM=-1*m_JOGS;
	if( !UpdateData( TRUE ) ) return;
}
void CDebugDlg::OnBnClickedbacklight()
{
	// TODO: 在此添加控件通知处理程序代码
    DWORD state;
}


void CDebugDlg::OnBnClickedunloadm()
{
	// TODO: 在此添加控件通知处理程序代码
	SetTimer( IDC_TIMER, 100, NULL );
	int m_JOGSM=-1*m_JOGS;
	if( !UpdateData( TRUE ) ) return;
	long current=d1000_get_command_pos( 3);
	long jog=current+m_JOGSM;
	if( d1000_check_done(3 ) == 0 ) return;//若在运行，则返回
		if(jog>=0)
	{
		d1000_set_sd(3,0);
		d1000_set_pls_outmode(3,1);
		d1000_start_t_move( 3,m_JOGSM, 0, m_JOGV, 0.3);//T形
	}
}


void CDebugDlg::OnBnClickedunloadp()
{
	// TODO: 在此添加控件通知处理程序代码
		SetTimer( IDC_TIMER, 100, NULL );
	if( !UpdateData( TRUE ) ) return;
	long current=d1000_get_command_pos( 3 );
	long jog=current+m_JOGS;

	if( d1000_check_done(3) == 0 ) return;//若在运行，则返回
	if(jog<60000)
	{
		d1000_set_sd(3,0);
		d1000_set_pls_outmode(3,1);
		d1000_start_t_move( 3,m_JOGS, 0, m_JOGV, 0.3);//T形
	}
}


void CDebugDlg::OnBnClickedloadpp2()
{
	// TODO: 在此添加控件通知处理程序代码
		SetTimer( IDC_TIMER, 100, NULL );
	if( !UpdateData( TRUE ) ) return;
}


void CDebugDlg::OnBnClickedunloadpp2()
{
	// TODO: 在此添加控件通知处理程序代码
		SetTimer( IDC_TIMER, 100, NULL );
	if( !UpdateData( TRUE ) ) return;
}


void CDebugDlg::OnBnClickedloadpp3()
{
	// TODO: 在此添加控件通知处理程序代码
		SetTimer( IDC_TIMER, 100, NULL );
	if( !UpdateData( TRUE ) ) return;
}


void CDebugDlg::OnBnClickedunloadpp3()
{
	// TODO: 在此添加控件通知处理程序代码
		SetTimer( IDC_TIMER, 100, NULL );
	if( !UpdateData( TRUE ) ) return;
}


void CDebugDlg::OnBnClickedloadmp2()
{
	// TODO: 在此添加控件通知处理程序代码
			SetTimer( IDC_TIMER, 100, NULL );
	int m_JOGSM=-1*m_JOGS;
	if( !UpdateData( TRUE ) ) return;
}


void CDebugDlg::OnBnClickedunloadmp2()
{
	// TODO: 在此添加控件通知处理程序代码
			SetTimer( IDC_TIMER, 100, NULL );
	int m_JOGSM=-1*m_JOGS;
	if( !UpdateData( TRUE ) ) return;
}


void CDebugDlg::OnBnClickedloadmp3()
{
	// TODO: 在此添加控件通知处理程序代码
			SetTimer( IDC_TIMER, 100, NULL );
	int m_JOGSM=-1*m_JOGS;
	if( !UpdateData( TRUE ) ) return;
}


void CDebugDlg::OnBnClickedunloadmp3()
{
	// TODO: 在此添加控件通知处理程序代码
			SetTimer( IDC_TIMER, 100, NULL );
	int m_JOGSM=-1*m_JOGS;
	if( !UpdateData( TRUE ) ) return;
}


void CDebugDlg::OnBnClickedLblock()
{
	// TODO: 在此添加控件通知处理程序代码
		DWORD state;
	   state=d1000_get_outbit(3);
	   if(state==1)
	   {	
		   d1000_out_bit(3,0);  
	   }
	   else
	   {	
		   d1000_out_bit(3,1);   
	   }
}


void CDebugDlg::OnBnClickedLvacuum()
{
	// TODO: 在此添加控件通知处理程序代码
		DWORD state;
	   state=d1000_get_outbit(6);
	   if(state==1)
	   {	
		   d1000_out_bit(6,0);
		   
	   }
	   else
	   {	
		   d1000_out_bit(6,1);
		   
	   }
}



void CDebugDlg::OnBnClickedPright()
{
	// TODO: 在此添加控件通知处理程序代码
		   DWORD state;
	   state=d1000_get_outbit(10);
	   if(state==1)
	   {	
		d1000_out_bit(10,0);
	   }
	   else
	   {	
		d1000_out_bit(10,1);
	   }
}


void CDebugDlg::OnBnClickedPronbotvacuum()
{
	// TODO: 在此添加控件通知处理程序代码
		   DWORD state;
	   state=d1000_get_outbit(5);
	   if(state==1)
	   {	
		d1000_out_bit(5,0);

	   }
	   else
	   {	
		d1000_out_bit(5,1);

	   }
}


void CDebugDlg::OnBnClickedPtrun()
{
	// TODO: 在此添加控件通知处理程序代码
		   DWORD state;
	   state=d1000_get_outbit(5);
	   if(state==1)
	   {	
		d1000_out_bit(5,0);
	   }
	   else
	   {	
		d1000_out_bit(5,1);
	   }
}


void CDebugDlg::OnBnClickedPclip()
{
	// TODO: 在此添加控件通知处理程序代码
		   DWORD state;
	   state=d1000_get_outbit(7);
	   if(state==1)
	   {	
		d1000_out_bit(7,0);
	   }
	   else
	   {	
		d1000_out_bit(7,1);
	   }
}


void CDebugDlg::OnBnClickedPdown()
{
	// TODO: 在此添加控件通知处理程序代码
		   DWORD state;
	   /*state=d1000_get_outbit(8);
	   if(state==1)
	   {	
		d1000_out_bit(8,0);

	   }
	   else
	   {	
		d1000_out_bit(8,1);

	   }*/
}


void CDebugDlg::OnBnClickedPflow()
{
	// TODO: 在此添加控件通知处理程序代码
		   DWORD state;
	   state=d1000_get_outbit(9);
	   if(state==1)
	   {	
		d1000_out_bit(9,0);

	   }
	   else
	   {	
		d1000_out_bit(9,1);

	   }
}


void CDebugDlg::OnBnClickedPleftvacuum()
{
	// TODO: 在此添加控件通知处理程序代码
		   DWORD state;
	   state=d1000_get_outbit(8);
	   if(state==1)
	   {	
		d1000_out_bit(8,0);
	   }
	   else
	   {	
		d1000_out_bit(8,1);
	   }
}


void CDebugDlg::OnBnClickedPrightvacuum()
{
	// TODO: 在此添加控件通知处理程序代码
		   DWORD state;
	   state=d1000_get_outbit(9);
	   if(state==1)
	   {	
		d1000_out_bit(9,0);

	   }
	   else
	   {	
		d1000_out_bit(9,1);

	   }
}


void CDebugDlg::OnBnClickedPdownvacuum()
{
	// TODO: 在此添加控件通知处理程序代码
		   DWORD state;
	   state=d1000_get_outbit(11);
	   if(state==1)
	   {	
		d1000_out_bit(11,0);

	   }
	   else
	   {	
		d1000_out_bit(11,1);

	   }
}


void CDebugDlg::OnBnClickedlinstepp()
{
	// TODO: 在此添加控件通知处理程序代码
		linstepp=true;
	cyclephoto=false;
	cyclephoto2=false;
		initposition=false;
	SetTimer( IDC_TIMER, 100, NULL );
}


void CDebugDlg::OnBnClickedloutstepp()
{
	// TODO: 在此添加控件通知处理程序代码
		loutstepp=true;
	cyclephoto=false;
	cyclephoto2=false;
		initposition=false;
	SetTimer( IDC_TIMER, 100, NULL );
}


void CDebugDlg::OnBnClickedllstepp()
{
	// TODO: 在此添加控件通知处理程序代码
		llstepp=true;
	cyclephoto=false;
	cyclephoto2=false;
		initposition=false;
	SetTimer( IDC_TIMER, 100, NULL );
}


void CDebugDlg::OnBnClickedleftstepp()
{
	// TODO: 在此添加控件通知处理程序代码
	leftstepp=true;
	cyclephoto=false;
	cyclephoto2=false;
		initposition=false;
	SetTimer( IDC_TIMER, 100, NULL );
}


void CDebugDlg::OnBnClickedrightstepp()
{
	// TODO: 在此添加控件通知处理程序代码
		rightstepp=true;
	cyclephoto=false;
	cyclephoto2=false;
		initposition=false;
	SetTimer( IDC_TIMER, 100, NULL );
}


void CDebugDlg::OnBnClickedpeelstepp()
{
	// TODO: 在此添加控件通知处理程序代码
	peelstepp=true;
	cyclephoto=false;
	cyclephoto2=false;
		initposition=false;
	SetTimer( IDC_TIMER, 100, NULL );
}


void CDebugDlg::OnBnClickedunloadstepp()
{
	// TODO: 在此添加控件通知处理程序代码
	unloadstepp=true;
	cyclephoto=false;
	cyclephoto2=false;
		initposition=false;
	SetTimer( IDC_TIMER, 100, NULL );
}


void CDebugDlg::OnBnClickedPleft()
{
	// TODO: 在此添加控件通知处理程序代码
			   DWORD state;
	   state=d1000_get_outbit(3);
	   if(state==1)
	   {	
		d1000_out_bit(3,0);

	   }
	   else
	   {	
		d1000_out_bit(3,1);

	   }
}


void CDebugDlg::OnBnClickedPright2()
{
	// TODO: 在此添加控件通知处理程序代码
				   DWORD state;
	   state=d1000_get_outbit(4);
	   if(state==1)
	   {	
		d1000_out_bit(4,0);
	   }
	   else
	   {	
		d1000_out_bit(4,1);
	   }

}





void CDebugDlg::OnBnClickedCliproller()
{
	// TODO: 在此添加控件通知处理程序代码
	DWORD state;
}


void CDebugDlg::OnBnClickedTray()
{
	// TODO: 在此添加控件通知处理程序代码
	DWORD state;
}





void CDebugDlg::OnBnClickedTrayvacuum()
{
	// TODO: 在此添加控件通知处理程序代码
	DWORD state;
}


void CDebugDlg::OnBnClickedcyclephoto3()
{
	// TODO: 在此添加控件通知处理程序代码
		 cyclephoto=false;
	 
	cyclephoto2=true;
	cyclephoto3=false;
	cyclephoto4=false;
	initposition=false;


	//overphoto=0;

	startphoto=0;
	zoomfactor=1;
	zoomupdown=0;
	zoomleftright=0;
}
