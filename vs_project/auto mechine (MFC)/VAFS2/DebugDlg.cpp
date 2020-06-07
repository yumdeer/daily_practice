// DebugDlg.cpp : implementation file
//

#include "stdafx.h"
#include "VAFS2.h"
#include "DebugDlg.h"
#include "VisionSetDlg.h"
#include "dmc1000.h"  //包含1000B库头文件
#include "externs.h"
#include "PARAMETERSET.h"
#include "SmallKey.h"
#include "IOMonitor.h"

#ifdef _DEBUG
#define new DEBUG_NEW  
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//////////////////////////////////////////colorvariable
HBRUSH dfixcolor;
HBRUSH dwhitecolor;
//////////////////////////////////////////
bool stepxp=false;
bool stepxm=false;
bool stepyp=false;
bool stepym=false;
bool stepzp=false;
bool stepzm=false;
bool steprp=false;
bool steprm=false;
bool steplinep=false;
bool steplinem=false;
bool stepLloadp=false;
bool stepLloadm=false;
bool stepRloadp=false;
bool stepRloadm=false;
bool steptonguep=false;
bool steptonguem=false;
int jogtimes=0;
/////////////////////////////////////////
unsigned char tongueprocess=0;
bool pusher1save,pusher2save,load1save,load2save,flow1save,flow2save,rightpresssave,vacuum1save,vacuum2save,loadvacuum1save,loadvacuum2save,fixturevacuumsave,pressvacuumsave;
bool manualstart=false;
//定义四个轴的常量
const int XCH = 0;
const int YCH = 1;
const int ZCH = 2;

const int UCH = 3;

int IDnumd;
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
	DDX_Control(pDX, IDC_YSTEPP, m_ystepp);
	DDX_Control(pDX, IDC_YSTEPM, m_ystepm);
	DDX_Control(pDX, IDC_XSTEPP, m_xstepp);
	DDX_Control(pDX, IDC_XSTEPM, m_xstepm);
	DDX_Control(pDX, IDC_TURNPLATEP, m_turnplatep);
	DDX_Control(pDX, IDC_TURNPLATEM, m_turnplatem);
	DDX_Control(pDX, IDC_TONGUEJOGP, m_tonguejogp);
	DDX_Control(pDX, IDC_TONGUEJOGM, m_tonguejogm);
	DDX_Control(pDX, IDC_reloadaixlp, m_reloadaixlp);
	DDX_Control(pDX, IDC_reloadaixlm, m_reloadaixlm);
	DDX_Control(pDX, IDC_loadaxilp, m_loadaxilp);
	DDX_Control(pDX, IDC_loadaxilm, m_loadaxilm);
	DDX_Control(pDX, IDC_LINEJOGP, m_linejogp);
	DDX_Control(pDX, IDC_LINEJOGM, m_linejogm);
	DDX_Text(pDX, IDC_JOGS, m_JOGS);
	DDX_Text(pDX, IDC_JOGV, m_JOGV);
	DDX_Text(pDX, IDC_pasteangled, m_pasteangle);
	DDX_Text(pDX, IDC_pastexd, m_pastex);
	DDV_MinMaxLong(pDX, m_pastex, 0, 18000);
	DDX_Text(pDX, IDC_pasteyd, m_pastey);
	DDV_MinMaxLong(pDX, m_pastey, 0, 48000);
	DDX_Text(pDX, IDC_photoxd, m_photox);
	DDX_Text(pDX, IDC_photoyd, m_photoy);
	DDX_Text(pDX, IDC_pickangled, m_pickangle);
	DDX_Text(pDX, IDC_pickxd, m_pickx);
	DDX_Text(pDX, IDC_pickyd, m_picky);
	DDX_Text(pDX, IDC_stateinfo, m_stateinfo);
	DDX_Text(pDX, IDC_photoxd2, m_photox2);
	DDX_Text(pDX, IDC_photoyd2, m_photoy2);
	DDX_Text(pDX, IDC_tongueind, m_tonguein);
	DDX_Text(pDX, IDC_tongueoutd, m_tongueout);
	DDV_MinMaxLong(pDX, m_tongueout, 1, 20000);
	DDX_Text(pDX, IDC_zpick, m_zpick);
	DDV_MinMaxLong(pDX, m_zpick, 0, 6000);
	DDX_Text(pDX, IDC_repasteangled, m_repasteangle);
	DDX_Text(pDX, IDC_repastexd, m_repastex);
	DDX_Text(pDX, IDC_repasteyd, m_repastey);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDebugDlg, CDialog)
	//{{AFX_MSG_MAP(CDebugDlg)
	ON_BN_CLICKED(IDC_Vision, OnVision)
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_pastestepp, Onpastestepp)
	ON_BN_CLICKED(IDC_fixturestepp, Onfixturestepp)
	ON_BN_CLICKED(IDC_parasetup, Onparasetup)
	ON_EN_SETFOCUS(IDC_photoxd, OnSetfocusphotox)
	ON_EN_KILLFOCUS(IDC_photoxd, OnKillfocusphotox)
	ON_EN_SETFOCUS(IDC_photoyd, OnSetfocusphotoy)
	ON_EN_KILLFOCUS(IDC_photoyd, OnKillfocusphotoy)
	ON_BN_CLICKED(IDC_softkey2, Onsoftkey2)
	ON_BN_CLICKED(IDC_cyclephoto, Oncyclephoto)
	ON_BN_CLICKED(IDC_counterzero, Oncounterzero)
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
	ON_BN_CLICKED(IDC_linestepm, Onlinestepm)
	ON_BN_CLICKED(IDC_linestepp, Onlinestepp)
	ON_BN_CLICKED(IDC_vacuump, Onvacuump)
	ON_EN_SETFOCUS(IDC_photoxd2, OnSetfocusphotoxd2)
	ON_EN_KILLFOCUS(IDC_photoxd2, OnKillfocusphotoxd2)
	ON_EN_SETFOCUS(IDC_photoyd2, OnSetfocusphotoyd2)
	ON_EN_KILLFOCUS(IDC_photoyd2, OnKillfocusphotoyd2)
	ON_EN_SETFOCUS(IDC_zpick, OnSetfocuszpick)
	ON_EN_KILLFOCUS(IDC_zpick, OnKillfocuszpick)
	ON_BN_CLICKED(IDC_upfinishedp, Onupfinishedp)
	ON_BN_CLICKED(IDC_downstartp, Ondownstartp)
	ON_BN_CLICKED(IDC_pusher1p, Onpusher1p)
	ON_BN_CLICKED(IDC_pusher2p, Onpusher2p)
	ON_BN_CLICKED(IDC_load1p, Onload1p)
	ON_BN_CLICKED(IDC_load2p, Onload2p)
	ON_BN_CLICKED(IDC_flow1p, Onflow1p)
	ON_BN_CLICKED(IDC_flow2p, Onflow2p)
	ON_BN_CLICKED(IDC_vacuum2p, Onvacuum2p)
	ON_BN_CLICKED(IDC_loadvacuum1p, Onloadvacuum1p)
	ON_BN_CLICKED(IDC_loadvacuum2p, Onloadvacuum2p)
	ON_BN_CLICKED(IDC_fixturevacuump, Onfixturevacuump)
	ON_BN_CLICKED(IDC_placestepp, Onplacestepp)
	ON_BN_CLICKED(IDC_reloadstepp, Onreloadp)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_pickxd, Onpickxd)
	ON_BN_CLICKED(IDC_pickangled, Onpickangled)
	ON_BN_CLICKED(IDC_pastexd, Onpastexd)
	ON_BN_CLICKED(IDC_repastexd, Onrepastexd)
	ON_BN_CLICKED(IDC_pasteangled, Onpasteangled)
	ON_BN_CLICKED(IDC_tongueoutd, Ontongueoutd)
	ON_BN_CLICKED(IDC_pickyd, Onpickyd)
	ON_BN_CLICKED(IDC_pasteyd, Onpasteyd)
	ON_BN_CLICKED(IDC_repasteyd, Onrepasteyd)
	ON_BN_CLICKED(IDC_repasteangled, Onrepasteangled)
	ON_BN_CLICKED(IDC_tongueind, Ontongueind)
	ON_BN_CLICKED(IDC_JOGV, OnJogv)
	ON_BN_CLICKED(IDC_JOGS, OnJogs)
	ON_BN_CLICKED(IDC_rightpress, Onrightpress)
	ON_BN_CLICKED(IDC_pressvacuum, Onpressvacuum)
	ON_BN_CLICKED(IDC_rightpress2, Onrightpress2)
	ON_BN_CLICKED(IDC_Vision3, OnVision3)
	ON_BN_CLICKED(IDC_Vision4, OnVision4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDebugDlg message handlers



BOOL CDebugDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	SetTimer( IDC_TIMER, 100, NULL );
	 m_stateinfo=stateinfo;
	 


	    m_pickx=pickx;
//		m_zpick=zpick;
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

	GetDlgItem(IDC_vacuump)->EnableWindow(0);

		GetDlgItem(IDC_pusher1p)->EnableWindow(0);
			GetDlgItem(IDC_pusher2p)->EnableWindow(0);
				GetDlgItem(IDC_load1p)->EnableWindow(0);
					GetDlgItem(IDC_load2p)->EnableWindow(0);
						GetDlgItem(IDC_flow1p)->EnableWindow(0);
							GetDlgItem(IDC_flow2p)->EnableWindow(0);
								GetDlgItem(IDC_vacuum2p)->EnableWindow(0);
									GetDlgItem(IDC_loadvacuum1p)->EnableWindow(0);
										GetDlgItem(IDC_loadvacuum2p)->EnableWindow(0);
											GetDlgItem(IDC_fixturevacuump)->EnableWindow(0);
												GetDlgItem(IDC_upfinishedp)->EnableWindow(0);
													GetDlgItem(IDC_downstartp)->EnableWindow(0);
													GetDlgItem(IDC_rightpress)->EnableWindow(0);
													GetDlgItem(IDC_rightpress2)->EnableWindow(0);




													if(repeat==1)
													{
														GetDlgItem(IDC_Vision3)->EnableWindow(1);
														GetDlgItem(IDC_Vision4)->EnableWindow(1);
													}
													else
													{
														GetDlgItem(IDC_Vision3)->EnableWindow(0);
														GetDlgItem(IDC_Vision4)->EnableWindow(0);
													}

    cyclephoto=false;
    cyclephoto2=false;
	SetDlgItemText(IDC_cyclephoto,"吸头连拍");
	SetDlgItemText(IDC_cyclephoto2,"夹具连拍");

	HWND h=::FindWindow(NULL,"屏幕键盘");
	if(h!=NULL)
	{
		::SendMessage(h,WM_CLOSE,0,0);
		SetDlgItemText(IDC_softkey2,"键盘");
	}

	 UpdateData(false);
	 //MoveWindow(200,0,410,640);
	

	 IDnumd=0;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



void CDebugDlg::OnTimer(UINT nIDEvent) 
{
  

	// TODO: Add your message handler code here and/or call default
	static CString string ;
	string.Format("%ld",long( d1000_get_command_pos( 0 )) );

	GetDlgItem( IDC_POSITIONX )->SetWindowText( string );

   
	string.Format("%ld",long( d1000_get_command_pos( 1 )) );

	GetDlgItem( IDC_POSITIONY )->SetWindowText( string );

	string.Format("%ld",long(d1000_get_command_pos( 4 ) ) );

	GetDlgItem( IDC_POSITIONTONGUE )->SetWindowText( string );



	string.Format("%ld",long( d1000_get_command_pos( 3 )) );

	GetDlgItem( IDC_POSITIONTURNPLATE )->SetWindowText( string );


		string.Format("%ld",long( d1000_get_command_pos( 5 )) );

	GetDlgItem( IDC_POSITIONmainroller )->SetWindowText( string );

			string.Format("%ld",long( d1000_get_command_pos(7 )) );

	GetDlgItem( IDC_POSITIONreload )->SetWindowText( string );
			string.Format("%ld",long( d1000_get_command_pos( 6  )) );

	GetDlgItem( IDC_POSITIONload )->SetWindowText( string );


	



     if(disablelinestepm==true)
	{
		GetDlgItem(IDC_linestepm)->EnableWindow(false);
	}
    
    if(disablelinestepp==true)
	{
		GetDlgItem(IDC_linestepp)->EnableWindow(false);
	}
	if(disablelinestepm==false)
	{
		GetDlgItem(IDC_linestepm)->EnableWindow(true);

	}
    
    if(disablelinestepp==false)
	{
		GetDlgItem(IDC_linestepp)->EnableWindow(true);
	}





 if(disablereloadstepp==true)
	{
		GetDlgItem(IDC_reloadstepp)->EnableWindow(false);
	}

    
    if(disablereloadstepp==false)
	{
		GetDlgItem(IDC_reloadstepp)->EnableWindow(true);

	}
  
    
    if(disablemainstepp==true)
	{
		GetDlgItem(IDC_pastestepp)->EnableWindow(false);
	}

    
    if(disablemainstepp==false)
	{
		GetDlgItem(IDC_pastestepp)->EnableWindow(true);

	}
    if(disableplacestepp==false)
	{
		GetDlgItem(IDC_placestepp)->EnableWindow(true);

	}
	   if(disableplacestepp==true)
	{
		GetDlgItem(IDC_placestepp)->EnableWindow(false);
	}

	 
    if(disablefixturestepp==true)
	{
		GetDlgItem(IDC_fixturestepp)->EnableWindow(false);
	}

    
    if(disablefixturestepp==false)
	{
		GetDlgItem(IDC_fixturestepp)->EnableWindow(true);

	}


	///////////////////////////////////////////////////////////////
	if(stepxp==true)
	{
		
				//if( !UpdateData( TRUE ) )
				//{return CDialog::OnWndMsg(message, wParam, lParam, pResult);}
		        if(jogtimes<2)
				{
					jogtimes++;
				}
				if(jogtimes>=2)
				{
					long current=d1000_get_command_pos( 0 );
					long jog=current+m_JOGS;

					if( d1000_check_done(0 ) != 0 ) 
					{
						if(jog<20000)
						{
							d1000_set_sd(0,0);
							d1000_set_pls_outmode(0,1);
							//d1000_start_t_move( 0,m_JOGS, 0, m_JOGV, 0.3);//T形
							d1000_start_ta_move( 0,20000, 0, m_JOGV, 0.3);
						}
					}
				}
	}
	if(stepxm==true)
	{
		        if(jogtimes<2)
				{
					jogtimes++;
				}
				if(jogtimes>=2)
				{
		            int m_JOGSM=-1*m_JOGS;
				//if( !UpdateData( TRUE ) ) return CDialog::OnWndMsg(message, wParam, lParam, pResult);
					long current=d1000_get_command_pos( 0 );
					long jog=current+m_JOGSM;
					if( d1000_check_done(0 ) != 0 )
					{
						if(jog>=0)
						{
							d1000_set_sd(0,0);
							d1000_set_pls_outmode(0,1);
							//d1000_start_t_move( 0,m_JOGSM, 0, m_JOGV, 0.3);//T形
							d1000_start_ta_move( 0,0, 0, m_JOGV, 0.3);
						}
					}
				}
	}

	if(stepyp==true)
	{
		
				//if( !UpdateData( TRUE ) )
				//{return CDialog::OnWndMsg(message, wParam, lParam, pResult);}
		        if(jogtimes<2)
				{
					jogtimes++;
				}
				if(jogtimes>=2)
				{
					long current=d1000_get_command_pos( 1 );
					long jog=current+m_JOGS;

					if( d1000_check_done(1 ) != 0 ) 
					{
						if(jog<48000)
						{
							d1000_set_sd(1,0);
							d1000_set_pls_outmode(1,1);
							//d1000_start_t_move( 0,m_JOGS, 0, m_JOGV, 0.3);//T形
							d1000_start_ta_move( 1,48000, 0, m_JOGV, 0.3);
						}
					}
				}
	}
	if(stepym==true)
	{
		        if(jogtimes<2)
				{
					jogtimes++;
				}
				if(jogtimes>=2)
				{
		            int m_JOGSM=-1*m_JOGS;
				//if( !UpdateData( TRUE ) ) return CDialog::OnWndMsg(message, wParam, lParam, pResult);
					long current=d1000_get_command_pos( 1 );
					long jog=current+m_JOGSM;
					if( d1000_check_done(1 ) != 0 )
					{
						if(jog>=0)
						{
							d1000_set_sd(1,0);
							d1000_set_pls_outmode(1,1);
							//d1000_start_t_move( 0,m_JOGSM, 0, m_JOGV, 0.3);//T形
							d1000_start_ta_move( 1,0, 0, m_JOGV, 0.3);
						}
					}
				}
	}
	if(stepzp==true)
	{
	}
	if(stepzm==true)
	{
	}
	if(steprp==true)
	{
		if(jogtimes<2)
				{
					jogtimes++;
				}
				if(jogtimes>=2)
				{
					long current=d1000_get_command_pos( 3 );
					long jog=current+m_JOGS;

					if( d1000_check_done(3 ) != 0 ) 
					{
						if(jog<660000)
						{
							d1000_set_sd(3,0);
							d1000_set_pls_outmode(3,1);
							//d1000_start_t_move( 0,m_JOGS, 0, m_JOGV, 0.3);//T形
							d1000_start_ta_move( 3,660000, 0, m_JOGV, 0.3);
						}
					}
				}
	}
	if(steprm==true)
	{
		if(jogtimes<2)
				{
					jogtimes++;
				}
				if(jogtimes>=2)
				{
		            int m_JOGSM=-1*m_JOGS;
				//if( !UpdateData( TRUE ) ) return CDialog::OnWndMsg(message, wParam, lParam, pResult);
					long current=d1000_get_command_pos( 3 );
					long jog=current+m_JOGSM;
					if( d1000_check_done(3 ) != 0 )
					{
						if(jog>=0)
						{
							d1000_set_sd(3,0);
							d1000_set_pls_outmode(3,1);
							//d1000_start_t_move( 0,m_JOGSM, 0, m_JOGV, 0.3);//T形
							d1000_start_ta_move( 3,0, 0, m_JOGV, 0.3);
						}
					}
				}
	}
    if(steplinep==true)
	{
		if(jogtimes<2)
				{
					jogtimes++;
				}
				if(jogtimes>=2)
				{
					long current=d1000_get_command_pos( 5 );
					long jog=current+m_JOGS;

					if( d1000_check_done(5 ) != 0 ) 
					{
						//if(jog<660000)
						{
							d1000_set_sd(5,0);
							d1000_set_pls_outmode(5,1);
							//d1000_start_t_move( 0,m_JOGS, 0, m_JOGV, 0.3);//T形
							d1000_start_tv_move( 5, 0, m_JOGV, 0.3);
						}
					}
				}
	}
	if(steplinem==true)
	{
	}
	if(stepLloadp==true)
	{
		if(jogtimes<2)
				{
					jogtimes++;
				}
				if(jogtimes>=2)
				{
					long current=d1000_get_command_pos( 7 );
					long jog=current+m_JOGS;

					if( d1000_check_done(7 ) != 0 ) 
					{
						if(jog<40000)
						{
							d1000_set_sd(7,0);
							d1000_set_pls_outmode(7,1);
							//d1000_start_t_move( 0,m_JOGS, 0, m_JOGV, 0.3);//T形
							d1000_start_ta_move( 7,40000, 0, m_JOGV, 0.3);
						}
					}
				}
	}
	if(stepLloadm==true)
	{
		if(jogtimes<2)
				{
					jogtimes++;
				}
				if(jogtimes>=2)
				{
		            int m_JOGSM=-1*m_JOGS;
				//if( !UpdateData( TRUE ) ) return CDialog::OnWndMsg(message, wParam, lParam, pResult);
					long current=d1000_get_command_pos( 7 );
					long jog=current+m_JOGSM;
					if( d1000_check_done(7 ) != 0 )
					{
						if(jog>=0)
						{
							d1000_set_sd(7,0);
							d1000_set_pls_outmode(7,1);
							//d1000_start_t_move( 0,m_JOGSM, 0, m_JOGV, 0.3);//T形
							d1000_start_ta_move( 7,0, 0, m_JOGV, 0.3);
						}
					}
				}
	}
	if(stepRloadp==true)
	{
		if(jogtimes<2)
				{
					jogtimes++;
				}
				if(jogtimes>=2)
				{
					long current=d1000_get_command_pos( 6 );
					long jog=current+m_JOGS;

					if( d1000_check_done(6 ) != 0 ) 
					{
						if(jog<40000)
						{
							d1000_set_sd(6,0);
							d1000_set_pls_outmode(6,1);
							//d1000_start_t_move( 0,m_JOGS, 0, m_JOGV, 0.3);//T形
							d1000_start_ta_move( 6,40000, 0, m_JOGV, 0.3);
						}
					}
				}
	}
	if(stepRloadm==true)
	{
		if(jogtimes<2)
				{
					jogtimes++;
				}
				if(jogtimes>=2)
				{
		            int m_JOGSM=-1*m_JOGS;
				//if( !UpdateData( TRUE ) ) return CDialog::OnWndMsg(message, wParam, lParam, pResult);
					long current=d1000_get_command_pos( 6 );
					long jog=current+m_JOGSM;
					if( d1000_check_done(6 ) != 0 )
					{
						if(jog>=0)
						{
							d1000_set_sd(6,0);
							d1000_set_pls_outmode(6,1);
							//d1000_start_t_move( 0,m_JOGSM, 0, m_JOGV, 0.3);//T形
							d1000_start_ta_move( 6,0, 0, m_JOGV, 0.3);
						}
					}
				}
	}
	if(steptonguep==true)
	{
		if(jogtimes<2)
				{
					jogtimes++;
				}
				if(jogtimes>=2)
				{
					long current=d1000_get_command_pos( 4 );
					long jog=current+m_JOGS;

					if( d1000_check_done(4 ) != 0 ) 
					{
						if(jog<37000)
						{
							d1000_set_sd(4,0);
							d1000_set_pls_outmode(4,1);
							//d1000_start_t_move( 0,m_JOGS, 0, m_JOGV, 0.3);//T形
							d1000_start_ta_move( 4,37000, 0, m_JOGV, 0.3);
						}
					}
				}
	}
	if(steptonguem==true)
	{
		if(jogtimes<2)
				{
					jogtimes++;
				}
				if(jogtimes>=2)
				{
		            int m_JOGSM=-1*m_JOGS;
				//if( !UpdateData( TRUE ) ) return CDialog::OnWndMsg(message, wParam, lParam, pResult);
					long current=d1000_get_command_pos( 4 );
					long jog=current+m_JOGSM;
					if( d1000_check_done(4 ) != 0 )
					{
						if(jog>=0)
						{
							d1000_set_sd(4,0);
							d1000_set_pls_outmode(4,1);
							//d1000_start_t_move( 0,m_JOGSM, 0, m_JOGV, 0.3);//T形
							d1000_start_ta_move( 4,0, 0, m_JOGV, 0.3);
						}
					}
				}
	}
	/////////////////////////////////////////////////////////////////////////////////////


   
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

	DeleteObject(dfixcolor);
	DeleteObject(dwhitecolor);
	// TODO: Add your message handler code here
	
}

void CDebugDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();

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







void CDebugDlg::Onfixturestepp() 
{
	// TODO: Add your control notification handler code here
	fixturestepp=true;
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
//	m_zpick=zpick;
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



		if(repeat==1)
		{
			GetDlgItem(IDC_Vision3)->EnableWindow(1);
			GetDlgItem(IDC_Vision4)->EnableWindow(1);
		}
		else
		{
			GetDlgItem(IDC_Vision3)->EnableWindow(0);
			GetDlgItem(IDC_Vision4)->EnableWindow(0);
		}
	

		
	SetDlgItemText(IDC_cyclephoto,"吸头连拍");
	SetDlgItemText(IDC_cyclephoto2,"夹具连拍");
	 UpdateData(false);
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
	 if(cyclephoto==false)
	{
		SetDlgItemText(IDC_cyclephoto,"连拍中");
		SetDlgItemText(IDC_cyclephoto2,"夹具连拍");
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
	}
	else
	{
		SetDlgItemText(IDC_cyclephoto,"吸头连拍");
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
	}
	//set_part(m_Window2id,0,0,camera2width,camera2height);
	//set_part(m_Windowid,0,0,camera1width,camera1height);
	
}




void CDebugDlg::Oncounterzero() 
{
	// TODO: Add your control notification handler code here
	CIOMonitor dlg;
	dlg.DoModal();
	SetDlgItemText(IDC_cyclephoto,"吸头连拍");
	SetDlgItemText(IDC_cyclephoto2,"夹具连拍");
}

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


	bool modalselecttemp;
	modalselecttemp=modalselect;
    modalselect=0;
	cameraselect=0;
	visionx=model11y;
	visiony=model11x;
	revisionx=remodel11y;
	revisiony=remodel11x;
	//m_Window.CloseWindow();
	CVisionSetDlg dlg;
	dlg.DoModal();
	modalselect=modalselecttemp;
	reloadmod=true;

   
	SetDlgItemText(IDC_cyclephoto,"吸头连拍");
	SetDlgItemText(IDC_cyclephoto2,"夹具连拍");

	
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
		bool modalselecttemp;
	modalselecttemp=modalselect;

	modalselect=1;
	cameraselect=0;
	visionx=model12y;
	visiony=model12x;
		revisionx=remodel12y;
	revisiony=remodel12x;

	CVisionSetDlg dlg;
	dlg.DoModal();
	modalselect=modalselecttemp;
	reloadmod=true;
	
	SetDlgItemText(IDC_cyclephoto,"吸头连拍");
	SetDlgItemText(IDC_cyclephoto2,"夹具连拍");
	
}

void CDebugDlg::OnVision3() 
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
		bool modalselecttemp;
	modalselecttemp=modalselect;

	modalselect=2;
	cameraselect=0;
	visionx=remodel11y;
	visiony=remodel11x;
		revisionx=remodel21y;
	revisiony=remodel21x;

	CVisionSetDlg dlg;
	dlg.DoModal();
	modalselect=modalselecttemp;
	reloadmod=true;

	SetDlgItemText(IDC_cyclephoto,"吸头连拍");
	SetDlgItemText(IDC_cyclephoto2,"夹具连拍");
}

void CDebugDlg::OnVision4() 
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
		bool modalselecttemp;
	modalselecttemp=modalselect;

	modalselect=3;
	cameraselect=0;
	visionx=remodel12y;
	visiony=remodel12x;
		revisionx=remodel21y;
	revisiony=remodel21x;

	CVisionSetDlg dlg;
	dlg.DoModal();
	modalselect=modalselecttemp;
	reloadmod=true;

	SetDlgItemText(IDC_cyclephoto,"吸头连拍");
	SetDlgItemText(IDC_cyclephoto2,"夹具连拍");
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
	if(cyclephoto2==false)
	{
		SetDlgItemText(IDC_cyclephoto2,"连拍中");
		SetDlgItemText(IDC_cyclephoto,"吸头连拍");
		cyclephoto2=true;
		cyclephoto=false;
		cyclephoto3=false;
		cyclephoto4=false;
		initposition=false;
		startphoto2=0;
		zoomfactor=1;
		zoomupdown=0;
		zoomleftright=0;
	}
	else
	{
		SetDlgItemText(IDC_cyclephoto2,"夹具连拍");
		cyclephoto=false;
		cyclephoto2=false;
		cyclephoto3=false;
		cyclephoto4=false;
		initposition=false;
		startphoto=0;
		startphoto2=0;
		startphoto3=0;
		startphoto4=0;
	}
	//set_part(m_Window2id,0,0,camera2width,camera2height);

	
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
	bool modalselecttemp;
	modalselecttemp=modalselect;
	modalselect=0;
	cameraselect=1;
    	visionx=model21y;
	visiony=model21x;
 	revisionx=remodel21y;
	revisiony=remodel21x;
	CVisionSetDlg dlg;
	dlg.DoModal();
	reloadmod=true;
	modalselect=modalselecttemp;

	SetDlgItemText(IDC_cyclephoto,"吸头连拍");
	SetDlgItemText(IDC_cyclephoto2,"夹具连拍");
	
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
	bool modalselecttemp;
	modalselecttemp=modalselect;
	modalselect=1;
	cameraselect=1;
		visionx=model22y;
	visiony=model22x;
		revisionx=remodel22y;
	revisiony=remodel22x;

	CVisionSetDlg dlg;
	dlg.DoModal();
	reloadmod=true;
	modalselect=modalselecttemp;

	SetDlgItemText(IDC_cyclephoto,"吸头连拍");
	SetDlgItemText(IDC_cyclephoto2,"夹具连拍");
	
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
	bool modalselecttemp;
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
	bool modalselecttemp;
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
	bool modalselecttemp;
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
	bool modalselecttemp;
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
	//GetDlgItem(IDC_mstart)->EnableWindow(0);
	pusher1save=d1000_get_outbit(3);
	pusher2save=d1000_get_outbit(4);
	load1save=d1000_get_outbit(5);
	load2save=d1000_get_outbit(7);
	flow1save=d1000_get_outbit(6);
	flow2save=d1000_get_outbit(8);
	rightpresssave=d1000_get_outbit(9);
	pressvacuumsave=d1000_get_outbit(10);

    vacuum1save=d1000_get_outbit(35);
	vacuum2save=d1000_get_outbit(36);
	loadvacuum1save=d1000_get_outbit(37);
	loadvacuum2save=d1000_get_outbit(38);
	fixturevacuumsave=d1000_get_outbit(39);


	

	GetDlgItem(IDC_vacuump)->EnableWindow(1);
		GetDlgItem(IDC_pusher1p)->EnableWindow(1);
			GetDlgItem(IDC_pusher2p)->EnableWindow(1);
				GetDlgItem(IDC_load1p)->EnableWindow(1);
					GetDlgItem(IDC_load2p)->EnableWindow(1);
						GetDlgItem(IDC_flow1p)->EnableWindow(1);
							GetDlgItem(IDC_flow2p)->EnableWindow(1);
								GetDlgItem(IDC_vacuum2p)->EnableWindow(1);
									GetDlgItem(IDC_loadvacuum1p)->EnableWindow(1);
										GetDlgItem(IDC_loadvacuum2p)->EnableWindow(1);
											GetDlgItem(IDC_fixturevacuump)->EnableWindow(1);
												GetDlgItem(IDC_upfinishedp)->EnableWindow(1);
													GetDlgItem(IDC_downstartp)->EnableWindow(1);
                                                     GetDlgItem(IDC_rightpress)->EnableWindow(1);
													 GetDlgItem(IDC_rightpress2)->EnableWindow(1);



	disablemainstepp=true;
	disableplacestepp=true;
	disablereloadstepp=true;
	disablelinestepp=true;
	disablelinestepm=true;
	disablefixturestepp=true;
	GetDlgItem(IDOK)->EnableWindow(0);
}

void CDebugDlg::Onmover() 
{
	// TODO: Add your control notification handler code here
		manualstart=false;
	//GetDlgItem(IDC_mstart)->EnableWindow(0);
	
    	d1000_out_bit(3, pusher1save);
		d1000_out_bit(4, pusher2save);
		d1000_out_bit(5, load1save);
		d1000_out_bit(7, load2save);

		d1000_out_bit(6, flow1save);
		d1000_out_bit(8, flow2save);

		d1000_out_bit(35, vacuum1save);
		d1000_out_bit(36, vacuum2save);
		d1000_out_bit(37, loadvacuum1save);
		d1000_out_bit(38, loadvacuum2save);

		d1000_out_bit(39, fixturevacuumsave);
	
	

	


	GetDlgItem(IDC_vacuump)->EnableWindow(0);
		GetDlgItem(IDC_pusher1p)->EnableWindow(0);
			GetDlgItem(IDC_pusher2p)->EnableWindow(0);
				GetDlgItem(IDC_load1p)->EnableWindow(0);
					GetDlgItem(IDC_load2p)->EnableWindow(0);
						GetDlgItem(IDC_flow1p)->EnableWindow(0);
							GetDlgItem(IDC_flow2p)->EnableWindow(0);
								GetDlgItem(IDC_vacuum2p)->EnableWindow(0);
									GetDlgItem(IDC_loadvacuum1p)->EnableWindow(0);
										GetDlgItem(IDC_loadvacuum2p)->EnableWindow(0);
											GetDlgItem(IDC_fixturevacuump)->EnableWindow(0);
												GetDlgItem(IDC_upfinishedp)->EnableWindow(0);
													GetDlgItem(IDC_downstartp)->EnableWindow(0);
													GetDlgItem(IDC_rightpress)->EnableWindow(0);
													GetDlgItem(IDC_rightpress2)->EnableWindow(0);


		




	disablemainstepp=false;
	disableplacestepp=false;
	disablereloadstepp=false;
	disablelinestepp=false;
	disablelinestepm=false;
	disablefixturestepp=false;
	disableplacestepp=false;
	GetDlgItem(IDOK)->EnableWindow(1);
	
}





void CDebugDlg::Onlinestepm() 
{
	// TODO: Add your control notification handler code here
		linestepm=true;
	cyclephoto=false;
	cyclephoto2=false;
		initposition=false;
	SetTimer( IDC_TIMER, 100, NULL );
	
}

void CDebugDlg::Onlinestepp() 
{
	// TODO: Add your control notification handler code here
		linestepp=true;
	cyclephoto=false;
	cyclephoto2=false;
		initposition=false;
	SetTimer( IDC_TIMER, 100, NULL );
	
}




void CDebugDlg::OnRollerstepp() 
{
	// TODO: Add your control notification handler code here

		// TODO: Add your control notification handler code here
	SetTimer( IDC_TIMER, 100, NULL );
	if( !UpdateData( TRUE ) ) return;
	long current=d1000_get_command_pos( 2 );
	long jog=current+m_JOGS;
	if( d1000_check_done(2) == 0 ) return;//若在运行，则返回
	if(jog<11400)
	{
		d1000_set_sd(2,0);
		d1000_set_pls_outmode(2,1);
		d1000_start_t_move( 2,m_JOGS, 0, m_JOGV, 0.3);//T形
	}
	
	
}

void CDebugDlg::OnRollerstepm() 
{
	// TODO: Add your control notification handler code here
	SetTimer( IDC_TIMER, 100, NULL );
		int m_JOGSM=-1*m_JOGS;
	if( !UpdateData( TRUE ) ) return;
	long current=d1000_get_command_pos( 2 );
	long jog=current+m_JOGSM;
	if( d1000_check_done(2 ) == 0 ) return;//若在运行，则返回
	if(jog>=0)
	{
		d1000_set_sd(2,0);
		d1000_set_pls_outmode(2,1);
		d1000_start_t_move( 2,m_JOGSM, 0, m_JOGV, 0.3);//T形
	}
		
	
}












void CDebugDlg::Onvacuump() 
{
	// TODO: Add your control notification handler code here
	   DWORD state;
	   state=d1000_get_outbit(35);
	   if(state==1)
	   {	
		d1000_out_bit(35,0);

	   }
	   else
	   {	
		d1000_out_bit(35,1);

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







void CDebugDlg::Onplacestepp() 
{
	// TODO: Add your control notification handler code here
	loadstepp=true;
	cyclephoto=false;
	cyclephoto2=false;
	initposition=false;
	SetTimer( IDC_TIMER, 100, NULL );
	
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

void CDebugDlg::Onupfinishedp() 
{
	// TODO: Add your control notification handler code here
		d1000_out_bit(40,0);

	   Sleep(500);	
		d1000_out_bit(40,1);
	
}

void CDebugDlg::Ondownstartp() 
{
	// TODO: Add your control notification handler code here
		d1000_out_bit(41,0);

	   Sleep(500);	
		d1000_out_bit(41,1);
	
}

void CDebugDlg::Onpusher1p() 
{
	// TODO: Add your control notification handler code here
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
	   	verifypastex=d1000_get_command_pos( 0);
	verifypastey=d1000_get_command_pos( 1);
}

void CDebugDlg::Onpusher2p() 
{
	// TODO: Add your control notification handler code here
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
	   	verifypastex=d1000_get_command_pos( 0);
	verifypastey=d1000_get_command_pos( 1);
	
}

void CDebugDlg::Onload1p() 
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

void CDebugDlg::Onload2p() 
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

void CDebugDlg::Onrightpress() 
{
	// TODO: Add your control notification handler code here
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

void CDebugDlg::Onrightpress2() 
{
	// TODO: Add your control notification handler code here
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

void CDebugDlg::Onflow1p() 
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

void CDebugDlg::Onflow2p() 
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

void CDebugDlg::Onvacuum2p() 
{
	// TODO: Add your control notification handler code here
		   DWORD state;
	   state=d1000_get_outbit(36);
	   if(state==1)
	   {	
		d1000_out_bit(36,0);

	   }
	   else
	   {	
		d1000_out_bit(36,1);

	   }
	
}

void CDebugDlg::Onloadvacuum1p() 
{
	// TODO: Add your control notification handler code here
		   DWORD state;
	   state=d1000_get_outbit(37);
	   if(state==1)
	   {	
		d1000_out_bit(37,0);

	   }
	   else
	   {	
		d1000_out_bit(37,1);

	   }
	
}

void CDebugDlg::Onloadvacuum2p() 
{
	// TODO: Add your control notification handler code here
		   DWORD state;
	   state=d1000_get_outbit(38);
	   if(state==1)
	   {	
		d1000_out_bit(38,0);

	   }
	   else
	   {	
		d1000_out_bit(38,1);

	   }
	
}

void CDebugDlg::Onfixturevacuump() 
{
	// TODO: Add your control notification handler code here
		   DWORD state;
	   state=d1000_get_outbit(39);
	   if(state==1)
	   {	
		d1000_out_bit(39,0);

	   }
	   else
	   {	
		d1000_out_bit(39,1);

	   }
	
}

void CDebugDlg::Onpressvacuum() 
{
	// TODO: Add your control notification handler code here
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









void CDebugDlg::Onreloadp() 
{
	// TODO: Add your control notification handler code here
			reloadstepp=true;
	cyclephoto=false;
	cyclephoto2=false;
		initposition=false;
	SetTimer( IDC_TIMER, 100, NULL );
	
}





void CDebugDlg::Onpickxd() 
{
	// TODO: Add your control notification handler code here
	inputshow(IDC_pickxd);
	CRect rect;
	GetDlgItem(IDC_pickxd)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_pickxd,inlong ,m_pickx, 18000, 0, pos, &outf);
	m_pickx = outf;
	UpdateData(false);
	inputshow(IDC_pickxd);
	pickx=m_pickx;
}

void CDebugDlg::Onpickangled() 
{
	// TODO: Add your control notification handler code here
	inputshow(IDC_pickangled);
	CRect rect;
	GetDlgItem(IDC_pickangled)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_pickangled,inlong ,m_pickangle, 360000, 0, pos, &outf);
	m_pickangle = outf;
	UpdateData(false);
	inputshow(IDC_pickangled);
	pickangle=m_pickangle;
}

void CDebugDlg::Onpastexd() 
{
	// TODO: Add your control notification handler code here
	inputshow(IDC_pastexd);
	CRect rect;
	GetDlgItem(IDC_pastexd)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_pastexd,inlong ,m_pastex, 19000, 0, pos, &outf);
	m_pastex = outf;
	UpdateData(false);
	inputshow(IDC_pastexd);
    pastex =m_pastex;
}

void CDebugDlg::Onrepastexd() 
{
	// TODO: Add your control notification handler code here
	inputshow(IDC_repastexd);
	CRect rect;
	GetDlgItem(IDC_repastexd)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_repastexd,inlong ,m_repastex, 19000, 0, pos, &outf);
	m_repastex = outf;
	UpdateData(false);
	inputshow(IDC_repastexd);
	repastex =m_repastex;
}

void CDebugDlg::Onpasteangled() 
{
	// TODO: Add your control notification handler code here
	inputshow(IDC_pasteangled);
	CRect rect;
	GetDlgItem(IDC_pasteangled)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_pasteangled,inlong ,m_pasteangle, 360000, -360000, pos, &outf);
	m_pasteangle = outf;
	UpdateData(false);
	inputshow(IDC_pasteangled);
	pasteangle=m_pasteangle;
}

void CDebugDlg::Ontongueoutd() 
{
	// TODO: Add your control notification handler code here
	inputshow(IDC_tongueoutd);
	CRect rect;
	GetDlgItem(IDC_tongueoutd)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_tongueoutd,inlong ,m_tongueout, 20000, 0, pos, &outf);
	m_tongueout = outf;
	UpdateData(false);
	inputshow(IDC_tongueoutd);
	tongueout=m_tongueout;
}

void CDebugDlg::Onpickyd() 
{
	// TODO: Add your control notification handler code here
	inputshow(IDC_pickyd);
	CRect rect;
	GetDlgItem(IDC_pickyd)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_pickyd,inlong ,m_picky, 38000, 0, pos, &outf);
	m_picky = outf;
	UpdateData(false);
	inputshow(IDC_pickyd);
	picky=m_picky;
}

void CDebugDlg::Onpasteyd() 
{
	// TODO: Add your control notification handler code here
	inputshow(IDC_pasteyd);
	CRect rect;
	GetDlgItem(IDC_pasteyd)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_pasteyd,inlong ,m_pastey, 40000, 0, pos, &outf);
	m_pastey = outf;
	UpdateData(false);
	inputshow(IDC_pasteyd);
	pastey =m_pastey;
}

void CDebugDlg::Onrepasteyd() 
{
	// TODO: Add your control notification handler code here
	inputshow(IDC_repasteyd);
	CRect rect;
	GetDlgItem(IDC_repasteyd)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_repasteyd,inlong ,m_repastey, 40000, 0, pos, &outf);
	m_repastey = outf;
	UpdateData(false);
	inputshow(IDC_repasteyd);
	repastey =m_repastey;
}

void CDebugDlg::Onrepasteangled() 
{
	// TODO: Add your control notification handler code here
	inputshow(IDC_repasteangled);
	CRect rect;
	GetDlgItem(IDC_repasteangled)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_repasteangled,inlong ,m_repasteangle, 360000, -360000, pos, &outf);
	m_repasteangle = outf;
	UpdateData(false);
	inputshow(IDC_repasteangled);
	repasteangle=m_repasteangle;
}

void CDebugDlg::Ontongueind() 
{
	// TODO: Add your control notification handler code here
	inputshow(IDC_tongueind);
	CRect rect;
	GetDlgItem(IDC_tongueind)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_tongueind,inlong ,m_tonguein, 36000, 0, pos, &outf);
	m_tonguein = outf;
	UpdateData(false);
	inputshow(IDC_tongueind);
	tonguein =m_tonguein;
}

void CDebugDlg::OnJogv() 
{
	// TODO: Add your control notification handler code here
	inputshow(IDC_JOGV);
	CRect rect;
	GetDlgItem(IDC_JOGV)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_JOGV,inlong ,m_JOGV, 10000, 0, pos, &outf);
	m_JOGV = outf;
	UpdateData(false);
	inputshow(IDC_JOGV);
	
}

void CDebugDlg::OnJogs() 
{
	// TODO: Add your control notification handler code here
	inputshow(IDC_JOGS);
	CRect rect;
	GetDlgItem(IDC_JOGS)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_JOGS,inlong ,m_JOGS, 10000, 0, pos, &outf);
	m_JOGS = outf;
	UpdateData(false);
	inputshow(IDC_JOGS);
	
}


HBRUSH CDebugDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	if ((nCtlColor==CTLCOLOR_STATIC)&&(pWnd-> GetDlgCtrlID()==IDnumd))
	{
		pDC->SetBkMode(TRANSPARENT);
		//HBRUSH B = CreateSolidBrush(RGB(3, 168, 158));
		//return (HBRUSH)B;
		DeleteObject(dfixcolor);
		dfixcolor=CreateSolidBrush(RGB(3, 168, 158));
		return (HBRUSH)dfixcolor;
	}
	if ((nCtlColor==CTLCOLOR_STATIC)&&(pWnd-> GetDlgCtrlID()!=IDC_STATIC)&&(pWnd-> GetDlgCtrlID()!=IDC_POSITIONX)&&(pWnd-> GetDlgCtrlID()!=IDC_POSITIONY)
		&&(pWnd-> GetDlgCtrlID()!=IDC_POSITIONTURNPLATE)&&(pWnd-> GetDlgCtrlID()!=IDC_POSITIONmainroller)&&(pWnd-> GetDlgCtrlID()!=IDC_POSITIONreload)
		&&(pWnd-> GetDlgCtrlID()!=IDC_POSITIONload)&&(pWnd-> GetDlgCtrlID()!=IDC_POSITIONTONGUE)&&(pWnd-> GetDlgCtrlID()!=IDnumd))
	{
		pDC->SetBkMode(TRANSPARENT);
		//HBRUSH B = CreateSolidBrush(RGB(255, 255, 255));
		//return (HBRUSH)B;
		DeleteObject(dwhitecolor);
		dwhitecolor=CreateSolidBrush(RGB(255, 255, 255));
		return (HBRUSH)dwhitecolor;
	}
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CDebugDlg::inputshow(UINT nID)
{
    CRect rect;
	GetDlgItem(nID)->GetWindowRect(&rect);
	ScreenToClient(&rect);
	InvalidateRect(rect);
}


bool CDebugDlg::GoSmallKey(int ctlID,intype intype, float invaluef , float Vlumax, float Vlumin,POINT point, float* outvaluef)
{

    IDnumd=ctlID;
	CSmallKey* smallkey;
	smallkey= new CSmallKey;
	smallkey->m_intype=intype;
	smallkey->ctlposL = point;
	smallkey->m_maximum = Vlumax;
	smallkey->m_minimum = Vlumin;
	
		smallkey->m_inputfloat = invaluef;
	
	//dlgkey->m_input = paravalue;
	smallkey->DoModal();
	
		*outvaluef = smallkey->m_inputfloat;
	//redraw=false;
		IDnumd=0;
	return true;
}



BOOL CDebugDlg::OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	// TODO: 在此添加专用代码和/或调用基类
    switch(message)

	{

	case 9999:

		if((HIWORD(wParam))==WM_LBUTTONDOWN)   // 按钮被鼠标左键按下

		{
            /*CPoint point;//定义一个用于确定光标位置的位置 
			GetCursorPos(&point);//获取当前光标的位置，以便使得菜单可以跟随光标  
			//ScreenToClient(&point);
			//得到窗体的控件句柄
			CWnd* hControlWnd = (CWnd*)WindowFromPoint(point);
			UINT nID = hControlWnd->GetDlgCtrlID();*/
			if((LOWORD(wParam))==IDC_XSTEPP)
			{
				SetTimer( IDC_TIMER, 100, NULL );
			    stepxp=true;
			}
			if((LOWORD(wParam))==IDC_XSTEPM)
			{
			    SetTimer( IDC_TIMER, 100, NULL );
				stepxm=true;	
			}

			if((LOWORD(wParam))==IDC_YSTEPP)
			{
				SetTimer( IDC_TIMER, 100, NULL );
			    stepyp=true;
			}
			if((LOWORD(wParam))==IDC_YSTEPM)
			{
			    SetTimer( IDC_TIMER, 100, NULL );
				stepym=true;	
			}

			if((LOWORD(wParam))==IDC_TURNPLATEP)
			{
				SetTimer( IDC_TIMER, 100, NULL );
			    steprp=true;
			}
			if((LOWORD(wParam))==IDC_TURNPLATEM)
			{
			    SetTimer( IDC_TIMER, 100, NULL );
				steprm=true;	
			}

			if((LOWORD(wParam))==IDC_LINEJOGP)
			{
				SetTimer( IDC_TIMER, 100, NULL );
			    steplinep=true;
			}
			//if(nID==IDC_XSTEPM)
			//{
			//    SetTimer( IDC_TIMER, 100, NULL );
			//	stepxm=true;	
			//}

			if((LOWORD(wParam))==IDC_reloadaixlp)
			{
				SetTimer( IDC_TIMER, 100, NULL );
			    stepLloadp=true;
			}
			if((LOWORD(wParam))==IDC_reloadaixlm)
			{
			    SetTimer( IDC_TIMER, 100, NULL );
				stepLloadm=true;	
			}

			if((LOWORD(wParam))==IDC_loadaxilp)
			{
				SetTimer( IDC_TIMER, 100, NULL );
			    stepRloadp=true;
			}
			if((LOWORD(wParam))==IDC_loadaxilm)
			{
			    SetTimer( IDC_TIMER, 100, NULL );
				stepRloadm=true;	
			}

			if((LOWORD(wParam))==IDC_TONGUEJOGP)
			{
				SetTimer( IDC_TIMER, 100, NULL );
			    steptonguep=true;
			}
			if((LOWORD(wParam))==IDC_TONGUEJOGM)
			{
			    SetTimer( IDC_TIMER, 100, NULL );
				steptonguem=true;	
			}

			
            
		}

		else if((HIWORD(wParam))==WM_LBUTTONUP) // 按钮被鼠标左键抬起

		{
            if(jogtimes<2)
			{
				/*CPoint point;//定义一个用于确定光标位置的位置 
				GetCursorPos(&point);//获取当前光标的位置，以便使得菜单可以跟随光标  
				//ScreenToClient(&point);
				//得到窗体的控件句柄
				CWnd* hControlWnd = (CWnd*)WindowFromPoint(point);
				UINT nID = hControlWnd->GetDlgCtrlID();*/
				if((LOWORD(wParam))==IDC_XSTEPP)
				{
					
					//if( !UpdateData( TRUE ) ) return CDialog::OnWndMsg(message, wParam, lParam, pResult);
						long current=d1000_get_command_pos( 0 );
						long jog=current+m_JOGS;
						if( d1000_check_done(0 ) != 0 )
						{
						if(jog<20000)
						{
							d1000_set_sd(0,0);
							d1000_set_pls_outmode(0,1);
							d1000_start_t_move( 0,m_JOGS, 0, m_JOGV, 0.3);//T形
							//d1000_start_ta_move( 0,0, 0, m_JOGV, 0.3);
						}
						}
						stepxp=false;
						stepxm=false;
				}
				if((LOWORD(wParam))==IDC_XSTEPM)
				{
			    		int m_JOGSM=-1*m_JOGS;
					//if( !UpdateData( TRUE ) ) return CDialog::OnWndMsg(message, wParam, lParam, pResult);
						long current=d1000_get_command_pos( 0 );
						long jog=current+m_JOGSM;
						if( d1000_check_done(0 ) != 0 )
						{
						if(jog>=0)
						{
							d1000_set_sd(0,0);
							d1000_set_pls_outmode(0,1);
							d1000_start_t_move( 0,m_JOGSM, 0, m_JOGV, 0.3);//T形
							//d1000_start_ta_move( 0,0, 0, m_JOGV, 0.3);
						}
						}
						stepxp=false;
						stepxm=false;
				}

				if((LOWORD(wParam))==IDC_YSTEPP)
				{
					
					//if( !UpdateData( TRUE ) ) return CDialog::OnWndMsg(message, wParam, lParam, pResult);
						long current=d1000_get_command_pos( 1 );
						long jog=current+m_JOGS;
						if( d1000_check_done(1 ) != 0 )
						{
						if(jog<48000)
						{
							d1000_set_sd(1,0);
							d1000_set_pls_outmode(1,1);
							d1000_start_t_move( 1,m_JOGS, 0, m_JOGV, 0.3);//T形
							//d1000_start_ta_move( 0,0, 0, m_JOGV, 0.3);
						}
						}
						stepyp=false;
						stepym=false;
				}
				if((LOWORD(wParam))==IDC_YSTEPM)
				{
			    		int m_JOGSM=-1*m_JOGS;
					//if( !UpdateData( TRUE ) ) return CDialog::OnWndMsg(message, wParam, lParam, pResult);
						long current=d1000_get_command_pos( 1 );
						long jog=current+m_JOGSM;
						if( d1000_check_done(1 ) != 0 )
						{
						if(jog>=0)
						{
							d1000_set_sd(1,0);
							d1000_set_pls_outmode(1,1);
							d1000_start_t_move( 1,m_JOGSM, 0, m_JOGV, 0.3);//T形
							//d1000_start_ta_move( 0,0, 0, m_JOGV, 0.3);
						}
						}
						stepyp=false;
						stepym=false;
				}
				
				if((LOWORD(wParam))==IDC_TURNPLATEP)
				{
					
					//if( !UpdateData( TRUE ) ) return CDialog::OnWndMsg(message, wParam, lParam, pResult);
						long current=d1000_get_command_pos( 3 );
						long jog=current+m_JOGS;
						if( d1000_check_done(3 ) != 0 )
						{
						if(jog<660000)
						{
							d1000_set_sd(3,0);
							d1000_set_pls_outmode(3,1);
							d1000_start_t_move( 3,m_JOGS, 0, m_JOGV, 0.3);//T形
							//d1000_start_ta_move( 0,0, 0, m_JOGV, 0.3);
						}
						}
						steprp=false;
						steprm=false;
				}
				if((LOWORD(wParam))==IDC_TURNPLATEM)
				{
			    		int m_JOGSM=-1*m_JOGS;
					//if( !UpdateData( TRUE ) ) return CDialog::OnWndMsg(message, wParam, lParam, pResult);
						long current=d1000_get_command_pos( 3 );
						long jog=current+m_JOGSM;
						if( d1000_check_done(3 ) != 0 )
						{
						if(jog>=0)
						{
							d1000_set_sd(3,0);
							d1000_set_pls_outmode(3,1);
							d1000_start_t_move( 3,m_JOGSM, 0, m_JOGV, 0.3);//T形
							//d1000_start_ta_move( 0,0, 0, m_JOGV, 0.3);
						}
						}
						steprp=false;
						steprm=false;
				}

				if((LOWORD(wParam))==IDC_LINEJOGP)//////
				{
					
					//if( !UpdateData( TRUE ) ) return CDialog::OnWndMsg(message, wParam, lParam, pResult);
						long current=d1000_get_command_pos( 5 );
						long jog=current+m_JOGS;
						if( d1000_check_done(5 ) != 0 )
						{
						//if(jog<660000)
						{
							d1000_set_sd(5,0);
							d1000_set_pls_outmode(5,1);
							d1000_start_t_move( 5,m_JOGS, 0, m_JOGV, 0.3);//T形
							
							//d1000_start_ta_move( 0,0, 0, m_JOGV, 0.3);
						}
						}
						steplinep=false;
						steplinem=false;
				}

				if((LOWORD(wParam))==IDC_reloadaixlp)
				{
					
					//if( !UpdateData( TRUE ) ) return CDialog::OnWndMsg(message, wParam, lParam, pResult);
						long current=d1000_get_command_pos( 7 );
						long jog=current+m_JOGS;
						if( d1000_check_done(7 ) != 0 )
						{
						if(jog<40000)
						{
							d1000_set_sd(7,0);
							d1000_set_pls_outmode(7,1);
							d1000_start_t_move( 7,m_JOGS, 0, m_JOGV, 0.3);//T形
							//d1000_start_ta_move( 0,0, 0, m_JOGV, 0.3);
						}
						}
						stepLloadp=false;
						stepLloadm=false;
				}
				if((LOWORD(wParam))==IDC_reloadaixlm)
				{
			    		int m_JOGSM=-1*m_JOGS;
					//if( !UpdateData( TRUE ) ) return CDialog::OnWndMsg(message, wParam, lParam, pResult);
						long current=d1000_get_command_pos( 7 );
						long jog=current+m_JOGSM;
						if( d1000_check_done(7 ) != 0 )
						{
						if(jog>=0)
						{
							d1000_set_sd(7,0);
							d1000_set_pls_outmode(7,1);
							d1000_start_t_move( 7,m_JOGSM, 0, m_JOGV, 0.3);//T形
							//d1000_start_ta_move( 0,0, 0, m_JOGV, 0.3);
						}
						}
						stepLloadp=false;
						stepLloadm=false;
				}
				
					if((LOWORD(wParam))==IDC_loadaxilp)
				{
					
					//if( !UpdateData( TRUE ) ) return CDialog::OnWndMsg(message, wParam, lParam, pResult);
						long current=d1000_get_command_pos( 6 );
						long jog=current+m_JOGS;
						if( d1000_check_done(6 ) != 0 )
						{
						if(jog<40000)
						{
							d1000_set_sd(6,0);
							d1000_set_pls_outmode(6,1);
							d1000_start_t_move( 6,m_JOGS, 0, m_JOGV, 0.3);//T形
							//d1000_start_ta_move( 0,0, 0, m_JOGV, 0.3);
						}
						}
						stepRloadp=false;
						stepRloadm=false;
				}
				if((LOWORD(wParam))==IDC_loadaxilm)
				{
			    		int m_JOGSM=-1*m_JOGS;
					//if( !UpdateData( TRUE ) ) return CDialog::OnWndMsg(message, wParam, lParam, pResult);
						long current=d1000_get_command_pos( 6 );
						long jog=current+m_JOGSM;
						if( d1000_check_done(6 ) != 0 )
						{
						if(jog>=0)
						{
							d1000_set_sd(6,0);
							d1000_set_pls_outmode(6,1);
							d1000_start_t_move( 6,m_JOGSM, 0, m_JOGV, 0.3);//T形
							//d1000_start_ta_move( 0,0, 0, m_JOGV, 0.3);
						}
						}
						stepRloadp=false;
						stepRloadm=false;
				}

					if((LOWORD(wParam))==IDC_TONGUEJOGP)
				{
					
					//if( !UpdateData( TRUE ) ) return CDialog::OnWndMsg(message, wParam, lParam, pResult);
						long current=d1000_get_command_pos( 4 );
						long jog=current+m_JOGS;
						if( d1000_check_done(4 ) != 0 )
						{
						if(jog<37000)
						{
							d1000_set_sd(4,0);
							d1000_set_pls_outmode(4,1);
							d1000_start_t_move( 4,m_JOGS, 0, m_JOGV, 0.3);//T形
							//d1000_start_ta_move( 0,0, 0, m_JOGV, 0.3);
						}
						}
						steptonguep=false;
						steptonguem=false;
				}
				if((LOWORD(wParam))==IDC_TONGUEJOGM)
				{
			    		int m_JOGSM=-1*m_JOGS;
					//if( !UpdateData( TRUE ) ) return CDialog::OnWndMsg(message, wParam, lParam, pResult);
						long current=d1000_get_command_pos( 4 );
						long jog=current+m_JOGSM;
						if( d1000_check_done(4 ) != 0 )
						{
						if(jog>=0)
						{
							d1000_set_sd(4,0);
							d1000_set_pls_outmode(6,1);
							d1000_start_t_move( 4,m_JOGSM, 0, m_JOGV, 0.3);//T形
							//d1000_start_ta_move( 0,0, 0, m_JOGV, 0.3);
						}
						}
						steptonguep=false;
						steptonguem=false;
				}
			}
			else
			{
				d1000_decel_stop(0);
				d1000_decel_stop(1);
				d1000_decel_stop(2);
				d1000_decel_stop(3);
				d1000_decel_stop(4);
				d1000_decel_stop(5);
				d1000_decel_stop(6);
				d1000_decel_stop(7);
				stepxp=false;
				stepxm=false;
				stepyp=false;
				stepym=false;
				stepzp=false;
				stepzm=false;
				steprp=false;
				steprm=false;
				steplinep=false;
				steplinem=false;
				stepLloadp=false;
				stepLloadm=false;
				stepRloadp=false;
				stepRloadm=false;
				steptonguep=false;
				steptonguem=false;
				//d1000_immediate_stop(0);
			}
           
			jogtimes=0;
		}

		break;

	default:

		break;

	}
	return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}



