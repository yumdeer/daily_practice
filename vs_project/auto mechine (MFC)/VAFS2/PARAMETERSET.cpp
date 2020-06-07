// PARAMETERSET.cpp : implementation file
//

#include "stdafx.h"
#include "VAFS2.h"
#include "PARAMETERSET.h"
#include "RcpSave.h"
#include "DELETERCP.h"
#include "externs.h"
#include "paraproduce.h"
#include "SmallKey.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//////////////////////////////////////////colorvariable
HBRUSH pfixcolor;
HBRUSH pwhitecolor;
///////////////////////////////////////////////////////////////////////////
int listrcpcounter;
HWND focushwnd;
int IDnum;
/////////////////////////////////////////////////////////////////////////////
// PARAMETERSET dialog


PARAMETERSET::PARAMETERSET(CWnd* pParent /*=NULL*/)
	: CDialog(PARAMETERSET::IDD, pParent)
{
	//{{AFX_DATA_INIT(PARAMETERSET)
	m_yscale = 0.0f;
	m_xscale = 0.0f;
	m_xdiv = 0.0f;
	m_ycenterdiv = 0.0f;
	m_fixturedelaytime = 0;
	m_fixtureouttime = 0;
	m_mainmotorlength = 0;
	m_pasteangle = 0;
	m_pastex = 0;
	m_pastey = 0;
	m_photox = 0;
	m_photoy = 0;
	m_picktime = 0;
	m_picky = 0;
	m_pushertime = 0;
	m_rollerfinished = 0;
	m_vexmainmotorhigh = 0;
	m_vexmainmotorlow = 0;
	m_vturnplate = 0;
	m_vexx = 0;
    m_repeat=0;
	m_shieldpaste=0;
	m_vexy = 0;
	m_pickangle = 0;
	m_photo2angle = 0;
	m_metalscale = 0.0f;
	m_xidv = 0.0f;
	m_ydiv = 0.0f;
	m_minscore11 = 0.0f;
	m_minscore21 = 0.0f;
	m_photox2 = 0;
	m_photoy2 = 0;
	m_tonguein = 0;
	m_vextonguein = 0;
	m_tongueout = 0;
	m_vextongueout = 0;
	m_unloadtime = 0;
	m_loadtime = 0;
	m_metalscaley = 0.0f;
	m_photodelay = 0;
	m_camera2xdiv = 0.0f;
	m_camera2ydiv = 0.0f;
	m_photo1angle = 0.0f;
	m_carrytime = 0;
	m_comno = 0;
	m_vexroller2 = 0;
	m_searchrange = 0;
	m_zvex = 0;
	m_zphoto = 0;
	m_zpick = 0;
	m_zpush = 0;
	m_verifypastex = 0;
	m_verifypastey = 0;
	m_searchrange2 = 0;
	m_verifyinfo = _T("");
	m_vload = 0;
	m_reloadpick = 0;
	m_reloadpush = 0;
	m_reloadwaiting = 0;
	m_repasteangle = 0;
	m_repastex = 0;
	m_repastey = 0;
	m_loadpick = 0;
	m_loadwaiting = 0;
	m_loadpush = 0;
	m_photor =0;
	m_pickx = 0;
	//}}AFX_DATA_INIT
}


void PARAMETERSET::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PARAMETERSET)
	DDX_Control(pDX, IDC_rcplist, m_rcplist);
	DDX_Text(pDX, IDC_yscale, m_yscale);
	DDX_Text(pDX, IDC_xcale, m_xscale);
	DDX_Text(pDX, IDC_xdiv, m_xdiv);
	DDX_Text(pDX, IDC_fixturedelaytime, m_fixturedelaytime);
	DDX_Text(pDX, IDC_fixtureouttime, m_fixtureouttime);
	DDX_Text(pDX, IDC_mainmotorlength, m_mainmotorlength);
	DDX_Text(pDX, IDC_pasteangle, m_pasteangle);
	DDX_Text(pDX, IDC_pastex, m_pastex);
	DDX_Text(pDX, IDC_pastey, m_pastey);
	DDX_Text(pDX, IDC_photox, m_photox);
	DDX_Text(pDX, IDC_photoy, m_photoy);
	DDX_Text(pDX, IDC_picktime, m_picktime);
	DDX_Text(pDX, IDC_picky, m_picky);
	DDX_Text(pDX, IDC_pushertime, m_pushertime);
	DDX_Text(pDX, IDC_rollerfinished, m_rollerfinished);
	DDX_Text(pDX, IDC_vexmainmotorhigh, m_vexmainmotorhigh);
	DDX_Text(pDX, IDC_vexmainmotorlow, m_vexmainmotorlow);
	DDX_Text(pDX, IDC_vturnplate, m_vturnplate);
	DDX_Text(pDX, IDC_vexx, m_vexx);
	DDX_Text(pDX, IDC_vexy, m_vexy);
	DDX_Text(pDX, IDC_pickangle, m_pickangle);
	DDX_Text(pDX, IDC_photo2angle, m_photo2angle);
	DDX_Text(pDX, IDC_metalscale, m_metalscale);
	DDX_Text(pDX, IDC_ydiv, m_ydiv);
	DDX_Text(pDX, IDC_minscore11, m_minscore11);
	DDX_Text(pDX, IDC_minscore21, m_minscore21);
	DDX_Text(pDX, IDC_photox2, m_photox2);
	DDX_Text(pDX, IDC_photoy2, m_photoy2);
	DDX_Text(pDX, IDC_tonguein, m_tonguein);
	DDX_Text(pDX, IDC_vextonguein, m_vextonguein);
	DDX_Text(pDX, IDC_tongueout, m_tongueout);
	DDX_Text(pDX, IDC_vextongueout, m_vextongueout);
	DDX_Text(pDX, IDC_unloadtime, m_unloadtime);
	DDX_Text(pDX, IDC_loadtime, m_loadtime);
	DDX_Text(pDX, IDC_metalscaley, m_metalscaley);
	DDX_Text(pDX, IDC_photodelay, m_photodelay);
	DDX_Text(pDX, IDC_camera2xdiv, m_camera2xdiv);
	DDX_Text(pDX, IDC_camera2ydiv, m_camera2ydiv);
	DDX_Text(pDX, IDC_photo1angle, m_photo1angle);
	DDX_Text(pDX, IDC_carrytime, m_carrytime);
	DDX_Text(pDX, IDC_comno, m_comno);
	DDX_Text(pDX, IDC_vexroller2, m_vexroller2);
	DDX_Text(pDX, IDC_searchrange, m_searchrange);
	DDX_Text(pDX, IDC_zvex, m_zvex);
	DDV_MinMaxLong(pDX, m_zvex, 0, 70000);
	DDX_Text(pDX, IDC_zphoto, m_zphoto);
	DDX_Text(pDX, IDC_zpicks, m_zpick);
	DDV_MinMaxLong(pDX, m_zpick, 0, 6000);
	DDX_Text(pDX, IDC_zpush, m_zpush);
	DDX_Text(pDX, IDC_verifypastex, m_verifypastex);
	DDX_Text(pDX, IDC_verifypastey, m_verifypastey);
	DDX_Text(pDX, IDC_searchrange2, m_searchrange2);
	DDX_Text(pDX, IDC_verifyinfo, m_verifyinfo);
	DDX_Text(pDX, IDC_vload, m_vload);
	DDX_Text(pDX, IDC_reloadpick, m_reloadpick);
	DDX_Text(pDX, IDC_reloadpush, m_reloadpush);
	DDX_Text(pDX, IDC_reloadwaiting, m_reloadwaiting);
	DDX_Text(pDX, IDC_repasteangle, m_repasteangle);
	DDX_Text(pDX, IDC_repastex, m_repastex);
	DDX_Text(pDX, IDC_repastey, m_repastey);
	DDX_Text(pDX, IDC_loadpick, m_loadpick);
	DDX_Text(pDX, IDC_loadwaiting, m_loadwaiting);
	DDX_Text(pDX, IDC_loadpush, m_loadpush);
	DDX_Text(pDX, IDC_photor, m_photor);
	DDX_Text(pDX, IDC_pickx, m_pickx);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PARAMETERSET, CDialog)
	//{{AFX_MSG_MAP(PARAMETERSET)
	ON_BN_CLICKED(IDC_saveas, Onsaveas)
	ON_BN_CLICKED(IDC_selectrcp, Onselectrcp)
	ON_BN_CLICKED(IDC_delrcp, Ondelrcp)
	ON_BN_CLICKED(IDC_photoverify, Onphotoverify)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_softkey, Onsoftkey)
	ON_BN_CLICKED(IDC_parameterproduce, Onparameterproduce)
	ON_BN_CLICKED(IDC_fixturemove, Onfixturemove)
	ON_WM_LBUTTONDOWN()
	ON_MESSAGE(OPEN_SOFTKEY,opensoftkey)
	ON_MESSAGE(CLOSE_SOFTKEY,closesoftkey)
	ON_BN_CLICKED(IDC_metalverify, Onmetalverify)
	ON_EN_SETFOCUS(IDC_metalscale, OnSetfocusmetalscale)
	ON_EN_KILLFOCUS(IDC_metalscale, OnKillfocusmetalscale)
	ON_EN_SETFOCUS(IDC_metalscaley, OnSetfocusmetalscaley)
	ON_EN_KILLFOCUS(IDC_metalscaley, OnKillfocusmetalscaley)
	ON_EN_SETFOCUS(IDC_carrytime, OnSetfocuscarrytime)
	ON_EN_KILLFOCUS(IDC_carrytime, OnKillfocuscarrytime)
	ON_EN_SETFOCUS(IDC_zpicks, OnSetfocuszpicks)
	ON_EN_KILLFOCUS(IDC_zpicks, OnKillfocuszpicks)
	ON_EN_SETFOCUS(IDC_verifypastex, OnSetfocusverifypastex)
	ON_EN_KILLFOCUS(IDC_verifypastex, OnKillfocusverifypastex)
	ON_EN_SETFOCUS(IDC_verifypastey, OnSetfocusverifypastey)
	ON_EN_KILLFOCUS(IDC_verifypastey, OnKillfocusverifypastey)
	ON_BN_CLICKED(IDC_shieldpaste, Onshieldpaste)
	ON_BN_CLICKED(IDC_withbeep, Onwithbeep)
	ON_BN_CLICKED(IDC_pickx, Onpickx)
	ON_BN_CLICKED(IDC_pastex, Onpastex)
	ON_BN_CLICKED(IDC_repastex, Onrepastex)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_pickangle, Onpickangle)
	ON_BN_CLICKED(IDC_photor, Onphotor)
	ON_BN_CLICKED(IDC_reloadwaiting, Onreloadwaiting)
	ON_BN_CLICKED(IDC_reloadpick, Onreloadpick)
	ON_BN_CLICKED(IDC_reloadpush, Onreloadpush)
	ON_BN_CLICKED(IDC_tonguein, Ontonguein)
	ON_BN_CLICKED(IDC_photox, Onphotox)
	ON_BN_CLICKED(IDC_photox2, Onphotox2)
	ON_BN_CLICKED(IDC_fixtureouttime, Onfixtureouttime)
	ON_BN_CLICKED(IDC_mainmotorlength, Onmainmotorlength)
	ON_BN_CLICKED(IDC_fixturedelaytime, Onfixturedelaytime)
	ON_BN_CLICKED(IDC_picktime, Onpicktime)
	ON_BN_CLICKED(IDC_photodelay, Onphotodelay)
	ON_BN_CLICKED(IDC_vexx, Onvexx)
	ON_BN_CLICKED(IDC_vload, Onvload)
	ON_BN_CLICKED(IDC_vextonguein, Onvextonguein)
	ON_BN_CLICKED(IDC_picky, Onpicky)
	ON_BN_CLICKED(IDC_pastey, Onpastey)
	ON_BN_CLICKED(IDC_repastey, Onrepastey)
	ON_BN_CLICKED(IDC_pasteangle, Onpasteangle)
	ON_BN_CLICKED(IDC_repasteangle, Onrepasteangle)
	ON_BN_CLICKED(IDC_loadwaiting, Onloadwaiting)
	ON_BN_CLICKED(IDC_loadpick, Onloadpick)
	ON_BN_CLICKED(IDC_loadpush, Onloadpush)
	ON_BN_CLICKED(IDC_tongueout, Ontongueout)
	ON_BN_CLICKED(IDC_photoy, Onphotoy)
	ON_BN_CLICKED(IDC_photoy2, Onphotoy2)
	ON_BN_CLICKED(IDC_zpush, Onzpush)
	ON_BN_CLICKED(IDC_vexmainmotorlow, Onvexmainmotorlow)
	ON_BN_CLICKED(IDC_vexmainmotorhigh, Onvexmainmotorhigh)
	ON_BN_CLICKED(IDC_pushertime, Onpushertime)
	ON_BN_CLICKED(IDC_loadtime, Onloadtime)
	ON_BN_CLICKED(IDC_unloadtime, Onunloadtime)
	ON_BN_CLICKED(IDC_vexy, Onvexy)
	ON_BN_CLICKED(IDC_vturnplate, Onvturnplate)
	ON_BN_CLICKED(IDC_vextongueout, Onvextongueout)
	ON_BN_CLICKED(IDC_searchrange, Onsearchrange)
	ON_BN_CLICKED(IDC_searchrange2, Onsearchrange2)
	ON_BN_CLICKED(IDC_minscore11, Onminscore11)
	ON_BN_CLICKED(IDC_minscore21, Onminscore21)
	ON_BN_CLICKED(IDC_comno, Oncomno)
	ON_BN_CLICKED(IDC_zphoto, Onzphoto)
	ON_BN_CLICKED(IDC_rollon, Onrollon)
	ON_BN_CLICKED(IDC_presson, Onpresson)
	ON_BN_CLICKED(IDC_rollerfinished, Onrollerfinished)
	ON_BN_CLICKED(IDC_vexroller2, Onvexroller2)
	ON_BN_CLICKED(IDC_zvex, Onzvex)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PARAMETERSET message handlers

BOOL PARAMETERSET::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	UpdateData(true);

	pickx=m_pickx;
	photox=m_photox;
	pastex=m_pastex;
	photox2=m_photox2;


	rollerfinished=m_rollerfinished;


	photoy=	m_photoy;
	photoy2=m_photoy2;
	picky=m_picky;
	pastey=m_pastey;




	vexmainmotorlow=m_vexmainmotorlow;
	vexmainmotorhigh=m_vexmainmotorhigh;
	vturnplate=m_vturnplate;
	mainmotorlength=m_mainmotorlength;
	fixturedelaytime=m_fixturedelaytime;
 	fixtureouttime=m_fixtureouttime;
 	picktime=m_picktime;
	loadtime=m_loadtime;
	photodelay=m_photodelay;
	unloadtime=m_unloadtime;
 	pushertime=m_pushertime;
	vexroller=m_vexroller2;
	searchrange=m_searchrange;
		searchrange2=m_searchrange2;

	vexx=m_vexx;
	repeat=m_repeat;
	shieldpaste=m_shieldpaste;
	photor=m_photor;
 repasteangle=m_repasteangle; 
 repastex=m_repastex; 
 repastey=m_repastey; 
 reloadwaiting=m_reloadwaiting; 
 reloadpush=m_reloadpush;
 reloadpick=m_reloadpick; 
 loadpush=m_loadpush; 
 loadpick=m_loadpick; 
 loadwaiting=m_loadwaiting; 
 vload=m_vload;

	zpush=m_zpush;
//	zpick=m_zpick;
	zphoto=m_zphoto;
	zvex=m_zvex;
	comno=m_comno;
//	carrytime=m_carrytime;
	vexy=m_vexy;
	tonguein=m_tonguein;
	tongueout=m_tongueout;
	vextonguein=m_vextonguein;
	vextongueout=m_vextongueout;

	minscore11=m_minscore11;
	minscore21=m_minscore21;
	
	pickangle=m_pickangle;
    pasteangle=m_pasteangle;


    
    
	





  
		CFile currentpara;
		currentpara.Open(currentparametername,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);

	     CArchive currentparaar(&currentpara,CArchive::store);
	
		 currentparaar<<PARAINPUT;

 


       
		currentparaar.Close();
		currentpara.Close();




		DeleteObject(pfixcolor);
	DeleteObject(pwhitecolor);
	
	return CDialog::DestroyWindow();
}

BOOL PARAMETERSET::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class

	
	return CDialog::Create(IDD, pParentWnd);
}

BOOL PARAMETERSET::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
    //ModifyStyle(0,WS_CLIPSIBLINGS); 
     
	CFile listrcp;
	listrcp.Open(listrcpname,CFile::modeRead);
	CArchive listrcpar(&listrcp,CArchive::load);
	

    

    listrcpar>> listrcpcounter;

	CString *rcpp=new CString[listrcpcounter+1];
	int rcpi;

	for(rcpi=0;rcpi<=listrcpcounter;rcpi++)
	{
	   listrcpar>>rcpp[rcpi];
	   m_rcplist.AddString(rcpp[rcpi]);

	}
	delete[] rcpp;

    GetDlgItem( IDC_currentrcp )->SetWindowText(rcpname );

	listrcpar.Close();
	listrcp.Close();

        m_xscale=xscale;
		m_yscale=yscale;
		m_xdiv=xdiv;
		m_ydiv=ydiv;

	if(_isnan(camera2xdiv)!=0)
		{camera2xdiv=0;}
	    m_camera2xdiv=camera2xdiv;
		if(_isnan(camera2ydiv)!=0)
		{camera2ydiv=0;}
	    m_camera2xdiv=camera2xdiv;
		m_camera2ydiv=camera2ydiv;
		
		m_metalscale=metalscale;
		if(_isnan(photo2angle)!=0)
		{photo2angle=0;}
		
		m_photo2angle=photo2angle;
		//if(photo1angle==-1.#IND0)
		//{photo1angle=0;}
	
		m_photo1angle=photo1angle;

		m_metalscaley=metalyscale;
	
	

		m_pickx=pickx;
		m_pastex=pastex;
		m_photoy=photoy;
		m_photox=photox;
		m_photoy2=photoy2;
		m_photox2=photox2;
  	    m_rollerfinished=rollerfinished;
	
		m_picky=picky;
		m_pastey=pastey;
	
	
	
		m_vexmainmotorlow=vexmainmotorlow;
		m_vexmainmotorhigh=vexmainmotorhigh;
		m_vturnplate=vturnplate;
		m_mainmotorlength=mainmotorlength;
		m_fixturedelaytime=fixturedelaytime;
 		m_fixtureouttime=fixtureouttime;
 		m_picktime=picktime;
		m_loadtime=loadtime;
		m_unloadtime=unloadtime;
		m_photodelay=photodelay;
 		m_pushertime=pushertime;
		m_vexroller2=vexroller;
		m_tonguein=tonguein;
	    m_tongueout=tongueout;
	    m_vextonguein=vextonguein;
	    m_vextongueout=vextongueout;
        m_searchrange=searchrange;
		   m_searchrange2=searchrange2;
		m_vexx=vexx;
		m_repeat=repeat;
		m_shieldpaste=shieldpaste;
		 m_photor=photor;
 m_repasteangle=repasteangle; 
 m_repastex=repastex; 
 m_repastey=repastey; 
 m_reloadwaiting=reloadwaiting; 
 m_reloadpush=reloadpush;
 m_reloadpick= reloadpick; 
 m_loadpush=loadpush; 
 m_loadpick=loadpick; 
 m_loadwaiting=loadwaiting; 
 m_vload=vload;
			m_zpush=zpush;
//	m_zpick=zpick;
	m_zphoto=zphoto;
	m_zvex=zvex;
		m_comno=comno;
		m_vexy=vexy;
//		m_carrytime=carrytime;
		m_pickangle=pickangle;
		m_pasteangle=pasteangle;
		m_minscore11=minscore11;
		m_minscore21=minscore21;
	
	HWND h=::FindWindow(NULL,"ÆÁÄ»¼üÅÌ");
	if(h!=NULL)
	{
		::SendMessage(h,WM_CLOSE,0,0);
		SetDlgItemText(IDC_softkey,"¼üÅÌ");

	}
    if(withbeep==1)
	{	SetDlgItemText(IDC_withbeep,"ÆôÓÃ·äÃù");}


	 if(withbeep==0)	
	 {SetDlgItemText(IDC_withbeep,"ÆÁ±Î·äÃù");}
	if(repeat==0)
	{
		SetDlgItemText(IDC_fixturemove,"µ¥Æ¬Ä£Ê½");
		GetDlgItem(IDC_rollon)->EnableWindow(1);
		if(carrytime==0)
		{
            SetDlgItemText(IDC_rollon,"²»¹öÄ¤");
            GetDlgItem(IDC_vexroller2)->EnableWindow(0);
			GetDlgItem(IDC_rollerfinished)->EnableWindow(0);
		}
		if(carrytime==1)
		{
            SetDlgItemText(IDC_rollon,"¹öÄ¤");
			GetDlgItem(IDC_vexroller2)->EnableWindow(1);
			GetDlgItem(IDC_rollerfinished)->EnableWindow(1);
		}

	}
	else
	{
	    SetDlgItemText(IDC_fixturemove,"Ë«Æ¬Ä£Ê½");
		GetDlgItem(IDC_rollon)->EnableWindow(0);
		GetDlgItem(IDC_vexroller2)->EnableWindow(0);
	    GetDlgItem(IDC_rollerfinished)->EnableWindow(0);
	}
	if(zpick==0)
	{
		//zpick=1;
		SetDlgItemText(IDC_presson,"²»Ñ¹ºÏ");
		SetDlgItemText(IDC_PRESSTURN,"Ñ¹ºÏÑÓÊ±");
			
	}
	if(zpick==1)
	{
		//zpick=0;
		SetDlgItemText(IDC_presson,"Ñ¹ºÏ");
		SetDlgItemText(IDC_PRESSTURN,"Ñ¹ºÏÑÓÊ±");
	}
    if(zpick==2)
	{
		//zpick=0;
		SetDlgItemText(IDC_presson,"²»·­×ª");
		SetDlgItemText(IDC_PRESSTURN,"·­×ªËÙ¶È");
	}
	if(zpick==3)
	{
		//zpick=0;
		SetDlgItemText(IDC_presson,"·­×ª");
		SetDlgItemText(IDC_PRESSTURN,"·­×ªËÙ¶È");
	}


		if(shieldpaste==0)
		{SetDlgItemText(IDC_shieldpaste,"ÆôÓÃÌùºÏ");}
	else
    {SetDlgItemText(IDC_shieldpaste,"ÆÁ±ÎÌùºÏ");}
   
       
	

        UpdateData( false );


	IDnum=0;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PARAMETERSET::Onsaveas() 
{
	// TODO: Add your control notification handler code here
	RcpSave dlg;
	bool repeatname=false;
	if(dlg.DoModal()==IDOK)
	{

	 

	CFile listrcp;
	listrcp.Open(listrcpname,CFile::modeRead);
	CArchive listrcpar(&listrcp,CArchive::load);

    listrcpar>> listrcpcounter;

	CString *rcpp=new CString[listrcpcounter+1];
	int rcpi;

	for(rcpi=0;rcpi<=listrcpcounter;rcpi++)
	{
	   listrcpar>>rcpp[rcpi];
	   if(rcpp[rcpi]==dlg.m_newrcpname)
	   {repeatname=true;}



	}
	
	listrcpar.Close();
	listrcp.Close();


     if(repeatname==false)
	 {
		m_rcplist.AddString(dlg.m_newrcpname);

	  
	     CFile listrcpnew;
		 listrcpnew.Open(listrcpname,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);

	     CArchive listrcparnew(&listrcpnew,CArchive::store);
		 CString filename;
		 filename=dlg.m_newrcpname;
		 
		 listrcpcounter=listrcpcounter+1;
		 listrcparnew<<listrcpcounter;
		 for(rcpi=0;rcpi<listrcpcounter;rcpi++)
			{
				listrcparnew<<rcpp[rcpi];
			

			}


		 listrcparnew<<filename;
		 listrcparnew.Close();
		 listrcpnew.Close();
		}

		 delete[] rcpp;
		 CString filename;
		 filename=dlg.m_newrcpname;
	

		 CopyFile(currentparametername,(currentdir+"\\"+filename+".para"),false);
		 CopyFile(currentmodelname,(currentdir+"\\"+filename+".shm"),false);
		 CopyFile(currentmodelname2,(currentdir+"\\"+filename+"2.shm"),false);
		 CopyFile(currentmodelname3,(currentdir+"\\"+filename+"3.shm"),false);
		 CopyFile(currentmodelname4,(currentdir+"\\"+filename+"4.shm"),false);
		 CopyFile(currentmodelname21,(currentdir+"\\"+filename+"21.shm"),false);
		 CopyFile(currentmodelname22,(currentdir+"\\"+filename+"22.shm"),false);
		 CopyFile(currentmodelname31,(currentdir+"\\"+filename+"31.shm"),false);
		 CopyFile(currentmodelname32,(currentdir+"\\"+filename+"32.shm"),false);
		 CopyFile(currentmodelname41,(currentdir+"\\"+filename+"41.shm"),false);
		 CopyFile(currentmodelname42,(currentdir+"\\"+filename+"42.shm"),false);

         CopyFile(currentphotoname,(currentdir+"\\"+filename+".photo"),false);



		 	UpdateData(true);

	pickx=m_pickx;
	photox=m_photox;
	photoy=	m_photoy;
	photox2=m_photox2;
	photoy2=m_photoy2;
	pastex=m_pastex;


	rollerfinished=m_rollerfinished;


	
	picky=m_picky;
	pastey=m_pastey;


	vexmainmotorlow=m_vexmainmotorlow;
		vexmainmotorhigh=m_vexmainmotorhigh;
		vturnplate=m_vturnplate;
	mainmotorlength=m_mainmotorlength;
	fixturedelaytime=m_fixturedelaytime;
 	fixtureouttime=m_fixtureouttime;
 	picktime=m_picktime;
 	pushertime=m_pushertime;
	vexroller=m_vexroller2;
	loadtime=m_loadtime;
	unloadtime=m_unloadtime;
	photodelay=m_photodelay;
    searchrange=m_searchrange;
	 searchrange2=m_searchrange2;
	vexx=m_vexx;
	repeat=m_repeat;
	shieldpaste=m_shieldpaste;
	photor=m_photor;
 repasteangle=m_repasteangle; 
 repastex=m_repastex; 
 repastey=m_repastey; 
 reloadwaiting=m_reloadwaiting; 
 reloadpush=m_reloadpush;
 reloadpick=m_reloadpick; 
 loadpush=m_loadpush; 
 loadpick=m_loadpick; 
 loadwaiting=m_loadwaiting; 
 vload=m_vload;

		zpush=m_zpush;
//	zpick=m_zpick;
	zphoto=m_zphoto;
	zvex=m_zvex;
	comno=m_comno;
//	carrytime=m_carrytime;
	vexy=m_vexy;
		tonguein=m_tonguein;
	tongueout=m_tongueout;
	vextonguein=m_vextonguein;
	vextongueout=m_vextongueout;
	minscore11=m_minscore11;
	minscore21=m_minscore21;
	pasteangle=m_pasteangle;
	pickangle=m_pickangle;


    
    
	





  
		CFile currentpara;
		currentpara.Open(currentdir+"\\"+filename+".para",CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);

	     CArchive currentparaar(&currentpara,CArchive::store);
	
		 currentparaar<<PARAINPUT;
 


       
		currentparaar.Close();
		currentpara.Close();




	}
	
}

void PARAMETERSET::Onselectrcp() 
{
	// TODO: Add your control notification handler code here

	int	i=m_rcplist.GetCurSel();
	if(i!=LB_ERR)
	{
		DeleteFileA(currentrcpname);
			
      CString selectrcp;
	  m_rcplist.GetText(i,selectrcp);

	   CFile currentrcpnew;
		 currentrcpnew.Open(currentrcpname,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);

	     CArchive currentrcparnew(&currentrcpnew,CArchive::store);
		
		 currentrcparnew<<selectrcp;
		 currentrcparnew.Close();
		 currentrcpnew.Close();
		 GetDlgItem( IDC_currentrcp )->SetWindowText(selectrcp);

    	currentparametername=currentdir+"\\"+selectrcp+".para";
	currentmodelname=currentdir+"\\"+selectrcp+".shm";
	currentmodelname2=currentdir+"\\"+selectrcp+"2.shm";
	currentmodelname3=currentdir+"\\"+selectrcp+"3.shm";
	currentmodelname4=currentdir+"\\"+selectrcp+"4.shm";
	currentmodelname21=currentdir+"\\"+selectrcp+"21.shm";
	currentmodelname22=currentdir+"\\"+selectrcp+"22.shm";
	currentmodelname31=currentdir+"\\"+selectrcp+"31.shm";
	currentmodelname32=currentdir+"\\"+selectrcp+"32.shm";
	currentmodelname41=currentdir+"\\"+selectrcp+"41.shm";
	currentmodelname42=currentdir+"\\"+selectrcp+"42.shm";

	currentphotoname=currentdir+"\\"+selectrcp+".photo";
	rcpname=selectrcp;
	reloadmod=true;
         
	
    CFile currentphoto;
    currentphoto.Open(currentphotoname,CFile::modeRead);
    CArchive currentphotoar(&currentphoto,CArchive::load);
	currentphotoar>>shutter>>bright>>gain>>shutter2>>shutter3>>shutter4>>shutter5>>gain2>>contrast1>>contrast2>>model11x>>model11y>>model12x>>model12y>>model21x>>model21y>>model22x>>model22y
		>>model11halfx>>model11halfy>>model12halfx>>model12halfy>>model13halfx>>model13halfy>>model14halfx>>model14halfy>>model21halfx>>model21halfy>>model22halfx>>model22halfy>>modalorg11>>modalorg12>>modalorg13>>modalorg14>>modalorg21>>modalorg22
        >>remodel11x>>remodel11y>>remodel12x>>remodel12y>>remodel21x>>remodel21y>>remodel22x>>remodel22y;
     

	currentphotoar.Close();
	currentphoto.Close();

	CFile currentpara;
	currentpara.Open(currentparametername,CFile::modeRead);
	CArchive currentparaar(&currentpara,CArchive::load);
	currentparaar>>PARAOUTPUT;

	currentparaar.Close();
	currentpara.Close();
	   
		m_pickx=pickx;
		m_pastex=pastex;
	
		m_photox=photox;
  	    m_rollerfinished=rollerfinished;
		m_photoy=photoy;
		m_picky=picky;
		m_pastey=pastey;

		m_vexmainmotorlow=vexmainmotorlow;
		m_vexmainmotorhigh=vexmainmotorhigh;
		m_vturnplate=vturnplate;
		m_mainmotorlength=mainmotorlength;
		m_fixturedelaytime=fixturedelaytime;
 		m_fixtureouttime=fixtureouttime;
 		m_picktime=picktime;
 		m_pushertime=pushertime;
		m_vexroller2=vexroller;
		m_loadtime=loadtime;
		m_unloadtime=unloadtime;
		m_photodelay=photodelay;
	    m_searchrange=searchrange;
		m_searchrange2=searchrange2;
		m_vexx=vexx;
		m_repeat=repeat;
		m_shieldpaste=shieldpaste;
			m_zpush=zpush;
			 m_photor=photor;
 m_repasteangle=repasteangle; 
 m_repastex=repastex; 
 m_repastey=repastey; 
 m_reloadwaiting=reloadwaiting; 
 m_reloadpush=reloadpush;
 m_reloadpick= reloadpick; 
 m_loadpush=loadpush; 
 m_loadpick=loadpick; 
 m_loadwaiting=loadwaiting; 
 m_vload=vload;
//	m_zpick=zpick;
	m_zphoto=zphoto;
	m_zvex=zvex;
		m_comno=comno;
		m_vexy=vexy;
//		m_carrytime=carrytime;
		m_tonguein=tonguein;
	    m_tongueout=tongueout;
	    m_vextonguein=vextonguein;
	    m_vextongueout=vextongueout;

		m_minscore11=minscore11;
		m_minscore21=minscore21;
		m_pickangle=pickangle;
		m_pasteangle=pasteangle;
	
        UpdateData( false );
	





	}
	if(i==LB_ERR)
	{MessageBox("ÇëÑ¡ÔñÅä·½");}

}

void PARAMETERSET::Ondelrcp() 
{
	// TODO: Add your control notification handler code here
	DELETERCP dlg;
	int	i=m_rcplist.GetCurSel();
	if(i!=LB_ERR)
	{

			
      CString selectrcp;
	  m_rcplist.GetText(i,selectrcp);

	  dlg.m_selectrcp=selectrcp;

	  if(dlg.DoModal()==IDOK)
		{
		

			if(selectrcp!=rcpname)
				{
					m_rcplist.DeleteString(i);

					CFile listrcp;
					listrcp.Open(listrcpname,CFile::modeRead);
					CArchive listrcpar(&listrcp,CArchive::load);
				    listrcpar>> listrcpcounter;
					CString *rcpp=new CString[listrcpcounter+1];
					int rcpi;
					
					for(rcpi=0;rcpi<listrcpcounter;rcpi++)
						{
						   
                            
							listrcpar>>rcpp[rcpi];

							if(rcpp[rcpi]==selectrcp)
							{rcpi=rcpi-1;}

						}
	
					listrcpar.Close();
					listrcp.Close();

	                DeleteFileA(listrcpname);
				    CFile listrcpnew;
					listrcpnew.Open(listrcpname,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);
				     CArchive listrcparnew(&listrcpnew,CArchive::store);
					 listrcpcounter=listrcpcounter-1;
		             listrcparnew<<listrcpcounter;
		            for(rcpi=0;rcpi<=listrcpcounter;rcpi++)
						{
							listrcparnew<<rcpp[rcpi];
						}

					 listrcparnew.Close();
					listrcpnew.Close();
		

					delete[] rcpp;
		  
					DeleteFileA(currentdir+"\\"+selectrcp+".para");
					DeleteFileA(currentdir+"\\"+selectrcp+".shm");
					DeleteFileA(currentdir+"\\"+selectrcp+".photo");

				}


	  
			else
					{MessageBox("²»ÄÜÉ¾³ýµ±Ç°Åä·½!");}
		}//IDOK
	}//LB_ERR
	if(i==LB_ERR)
	{MessageBox("ÇëÑ¡ÔñÅä·½");}
	
}

void PARAMETERSET::Onphotoverify() 
{
	// TODO: Add your control notification handler code here
	cyclephoto=false;
	cyclephoto2=false;
	metalverify=false;

	photoverify=true;
		initposition=false;
	SetTimer(1,500,NULL);


	
}

void PARAMETERSET::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if((metalverify==false)&&(photoverify==false))
	{
    m_xscale=xscale;
	m_yscale=yscale;
	m_camera2xdiv=camera2xdiv;
	
	m_camera2ydiv=camera2ydiv;

	m_metalscale=metalscale;
    m_photo2angle=photo2angle;
	 m_photo1angle=photo1angle;

	m_metalscaley=metalyscale;
	m_verifyinfo=verifyinfo;
	

	UpdateData( false );
	KillTimer(1);
	CDialog::OnTimer(nIDEvent);
	
	}
}

void PARAMETERSET::Onsoftkey() 
{
	// TODO: Add your control notification handler code here
		HWND h=::FindWindow(NULL,"ÆÁÄ»¼üÅÌ");
	if(h!=NULL)
	{
		::SendMessage(h,WM_CLOSE,0,0);
		SetDlgItemText(IDC_softkey,"¼üÅÌ");
	}
	else
	{
		WinExec("c:\\windows\\system32\\osk.exe",SW_SHOWNORMAL);
		SetDlgItemText(IDC_softkey,"¼üÅÌ");
	}
	
	
	
	
	
	
	
}

void PARAMETERSET::Onparameterproduce() 
{
	// TODO: Add your control notification handler code here
	Cparaproduce dlg;
	dlg.DoModal();
		m_pickx=pickx;
		m_pastex=pastex;
	
		m_photox=photox;
		m_photoy=photoy;
		m_photox2=photox2;
		m_photoy2=photoy2;
  	    m_rollerfinished=rollerfinished;
	
		m_picky=picky;
		m_pastey=pastey;

		m_vexmainmotorlow=vexmainmotorlow;
				m_vexmainmotorhigh=vexmainmotorhigh;
				m_vturnplate=vturnplate;
		m_mainmotorlength=mainmotorlength;
		m_fixturedelaytime=fixturedelaytime;
 		m_fixtureouttime=fixtureouttime;
 		m_picktime=picktime;
 		m_pushertime=pushertime;
		m_vexroller2=vexroller;
		m_loadtime=loadtime;
		m_unloadtime=unloadtime;
		m_photodelay=photodelay;
		m_searchrange=searchrange;
		m_searchrange2=searchrange2;
		m_vexx=vexx;
		m_repeat=repeat;
		m_shieldpaste=shieldpaste;
		 m_photor=photor;
 m_repasteangle=repasteangle; 
 m_repastex=repastex; 
 m_repastey=repastey; 
 m_reloadwaiting=reloadwaiting; 
 m_reloadpush=reloadpush;
 m_reloadpick= reloadpick; 
 m_loadpush=loadpush; 
 m_loadpick=loadpick; 
 m_loadwaiting=loadwaiting; 
 m_vload=vload;
					m_zpush=zpush;
//	m_zpick=zpick;
	m_zphoto=zphoto;
	m_zvex=zvex;
		m_comno=comno;
		m_vexy=vexy;
//		m_carrytime=carrytime;
		m_tonguein=tonguein;
	    m_tongueout=tongueout;
	    m_vextonguein=vextonguein;
	    m_vextongueout=vextongueout;

		m_pickangle=pickangle;
		m_pasteangle=pasteangle;
		m_minscore11=minscore11;
	    m_minscore21=minscore21;
	
		UpdateData( false );

	
}

void PARAMETERSET::Onpresson() 
{
	// TODO: Add your control notification handler code here
	zpick++;
	if(zpick>=4)
	{
		zpick=0;
	}
	if(zpick==0)
	{
		//zpick=1;
		SetDlgItemText(IDC_presson,"²»Ñ¹ºÏ");
		SetDlgItemText(IDC_PRESSTURN,"Ñ¹ºÏÑÓÊ±");
			
	}
	if(zpick==1)
	{
		//zpick=0;
		SetDlgItemText(IDC_presson,"Ñ¹ºÏ");
		SetDlgItemText(IDC_PRESSTURN,"Ñ¹ºÏÑÓÊ±");
	}
    if(zpick==2)
	{
		//zpick=0;
		SetDlgItemText(IDC_presson,"²»·­×ª");
		SetDlgItemText(IDC_PRESSTURN,"·­×ªËÙ¶È");
	}
	if(zpick==3)
	{
		//zpick=0;
		SetDlgItemText(IDC_presson,"·­×ª");
		SetDlgItemText(IDC_PRESSTURN,"·­×ªËÙ¶È");
	}
}

void PARAMETERSET::Onrollon() 
{
	// TODO: Add your control notification handler code here
	if(carrytime==0)
	{
		carrytime=1;
		SetDlgItemText(IDC_rollon,"¹öÄ¤");
			GetDlgItem(IDC_vexroller2)->EnableWindow(1);
			GetDlgItem(IDC_rollerfinished)->EnableWindow(1);
	}
	else
	{
		carrytime=0;
		SetDlgItemText(IDC_rollon,"²»¹öÄ¤");
		GetDlgItem(IDC_vexroller2)->EnableWindow(0);
			GetDlgItem(IDC_rollerfinished)->EnableWindow(0);
	}

}


void PARAMETERSET::Onfixturemove() 
{
	// TODO: Add your control notification handler code here
    int temp;
	temp=repeat;
	if(temp==0)
	{
		repeat=1;
		m_repeat=1;
		SetDlgItemText(IDC_fixturemove,"Ë«Æ¬Ä£Ê½");
		GetDlgItem(IDC_rollon)->EnableWindow(0);
        GetDlgItem(IDC_vexroller2)->EnableWindow(0);
			GetDlgItem(IDC_rollerfinished)->EnableWindow(0);
	}
	if(temp==1)
	{
		repeat=0;
		m_repeat=0;
		SetDlgItemText(IDC_fixturemove,"µ¥Æ¬Ä£Ê½");
		GetDlgItem(IDC_rollon)->EnableWindow(1);
		if(carrytime==0)
		{
            SetDlgItemText(IDC_rollon,"²»¹öÄ¤");
            GetDlgItem(IDC_vexroller2)->EnableWindow(0);
			GetDlgItem(IDC_rollerfinished)->EnableWindow(0);
		}
		if(carrytime==1)
		{
            SetDlgItemText(IDC_rollon,"¹öÄ¤");
			GetDlgItem(IDC_vexroller2)->EnableWindow(1);
			GetDlgItem(IDC_rollerfinished)->EnableWindow(1);
		}

	}
	
	
}


void PARAMETERSET::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	  HWND h=::FindWindow(NULL,"ÆÁÄ»¼üÅÌ");
	if(h!=NULL)
	{::SendMessage(h,WM_CLOSE,0,0);}
	
	CDialog::OnLButtonDown(nFlags, point);
}







LRESULT PARAMETERSET::opensoftkey(WPARAM wParam,LPARAM lParam) 
{
	// TODO: Add your control notification handler code here
	RECT r;
	  ::GetWindowRect(focushwnd,&r);
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
	cwnd=FromHandle(focushwnd);
	cwnd->PostMessage(EM_SETSEL,0,-1);
	return 0;
	
}

LRESULT PARAMETERSET::closesoftkey(WPARAM wParam,LPARAM lParam) 
{
	// TODO: Add your control notification handler code here

	return 0;
	
}



void PARAMETERSET::Onmetalverify() 
{
	// TODO: Add your control notification handler code here
	cyclephoto=false;
	cyclephoto2=false;
	photoverify=false;
	
	m_verifypastex=verifypastex;
	m_verifypastey=verifypastey;
	m_verifyinfo="Á½¸öÃþ°å¶ÔÓ¦£¬ÇÐ¾ÓÖÐ";
	UpdateData(false);

	
	metalverify=true;
	
	initposition=false;
	SetTimer(1,500,NULL);
	
}








void PARAMETERSET::OnSetfocusmetalscale() 
{
	// TODO: Add your control notification handler code here
					HWND h=::FindWindow(NULL,"ÆÁÄ»¼üÅÌ");
   	focushwnd=::GetFocus();

	{
		PostMessage(OPEN_SOFTKEY);
	}
	
	
}

void PARAMETERSET::OnKillfocusmetalscale() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	metalscale=m_metalscale;
	  CFile scalenew;
         scalenew.Open(currentdir+"\\scale.txt",CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);
	     CArchive scalearnew(&scalenew,CArchive::store);
		 scalearnew<<xscale<<yscale<<xdiv<<ydiv<<camera2xdiv<<camera2ydiv<<metalscale<<metalyscale<<photo2angle<<photo1angle;
         scalearnew.Close();
   		 scalenew.Close();
	SendMessage(CLOSE_SOFTKEY);	
	
}

void PARAMETERSET::OnSetfocusmetalscaley() 
{
	// TODO: Add your control notification handler code here
						HWND h=::FindWindow(NULL,"ÆÁÄ»¼üÅÌ");
   	focushwnd=::GetFocus();

	{
		PostMessage(OPEN_SOFTKEY);
	}
	
}

void PARAMETERSET::OnKillfocusmetalscaley() 
{
	// TODO: Add your control notification handler code here
		UpdateData(true);
	metalyscale=m_metalscale;
	  CFile scalenew;
         scalenew.Open(currentdir+"\\scale.txt",CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);
	     CArchive scalearnew(&scalenew,CArchive::store);
		 scalearnew<<xscale<<yscale<<xdiv<<ydiv<<camera2xdiv<<camera2ydiv<<metalscale<<metalyscale<<photo2angle<<photo1angle;
         scalearnew.Close();
   		 scalenew.Close();
	SendMessage(CLOSE_SOFTKEY);	
	
}


void PARAMETERSET::OnSetfocuscarrytime() 
{
	// TODO: Add your control notification handler code here
							HWND h=::FindWindow(NULL,"ÆÁÄ»¼üÅÌ");
   	focushwnd=::GetFocus();

	{
		PostMessage(OPEN_SOFTKEY);
	}
	
}

void PARAMETERSET::OnKillfocuscarrytime() 
{
	// TODO: Add your control notification handler code here
SendMessage(CLOSE_SOFTKEY);		
}







void PARAMETERSET::OnSetfocuszpicks() 
{
	// TODO: Add your control notification handler code here
											HWND h=::FindWindow(NULL,"ÆÁÄ»¼üÅÌ");
   	focushwnd=::GetFocus();

	{
		PostMessage(OPEN_SOFTKEY);
	}
	
}

void PARAMETERSET::OnKillfocuszpicks() 
{
	// TODO: Add your control notification handler code here
		SendMessage(CLOSE_SOFTKEY);	

	
}



  

void PARAMETERSET::OnSetfocusverifypastex() 
{
	// TODO: Add your control notification handler code here
												HWND h=::FindWindow(NULL,"ÆÁÄ»¼üÅÌ");
   	focushwnd=::GetFocus();

	{
		PostMessage(OPEN_SOFTKEY);
	}
	
}

void PARAMETERSET::OnKillfocusverifypastex() 
{
	// TODO: Add your control notification handler code here
		SendMessage(CLOSE_SOFTKEY);	
	
}

void PARAMETERSET::OnSetfocusverifypastey() 
{
	// TODO: Add your control notification handler code here
												HWND h=::FindWindow(NULL,"ÆÁÄ»¼üÅÌ");
   	focushwnd=::GetFocus();

	{
		PostMessage(OPEN_SOFTKEY);
	}
	
}

void PARAMETERSET::OnKillfocusverifypastey() 
{
	// TODO: Add your control notification handler code here
		SendMessage(CLOSE_SOFTKEY);	
	
}








void PARAMETERSET::Onshieldpaste() 
{
	// TODO: Add your control notification handler code here

	 int temp;
	temp=shieldpaste;
	if(temp==0)
	{
		shieldpaste=1;
		m_shieldpaste=1;
		SetDlgItemText(IDC_shieldpaste,"ÆÁ±ÎÌùºÏ");

	}
	if(temp==1)
	{
		shieldpaste=0;
		m_shieldpaste=0;
		SetDlgItemText(IDC_shieldpaste,"ÆôÓÃÌùºÏ");
	}
	
	
}

void PARAMETERSET::Onwithbeep() 
{
	// TODO: Add your control notification handler code here
		 int temp;
	temp=withbeep;
	if(temp==0)
	{
		withbeep=1;
	
		SetDlgItemText(IDC_withbeep,"ÆôÓÃ·äÃù");

	}
	if(temp!=0)
	{
		withbeep=0;
		
		SetDlgItemText(IDC_withbeep,"ÆÁ±Î·äÃù");
	}
	
}

void PARAMETERSET::Onpickx() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_pickx);
	CRect rect;
	GetDlgItem(IDC_pickx)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_pickx,inlong ,m_pickx, 18000, 0, pos, &outf);
	m_pickx = outf;
	UpdateData(false);
	inputshow(IDC_pickx);
}



void PARAMETERSET::Onpastex() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_pastex);
	CRect rect;
	GetDlgItem(IDC_pastex)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_pastex,inlong ,m_pastex, 19000, 0, pos, &outf);
	m_pastex = outf;
	UpdateData(false);
	inputshow(IDC_pastex);

}

void PARAMETERSET::Onrepastex() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_repastex);
	CRect rect;
	GetDlgItem(IDC_repastex)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_repastex,inlong ,m_repastex, 19000, 0, pos, &outf);
	m_repastex = outf;
	UpdateData(false);
	inputshow(IDC_repastex);
}

void PARAMETERSET::Onpickangle() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_pickangle);
	CRect rect;
	GetDlgItem(IDC_pickangle)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_pickangle,inlong ,m_pickangle, 360000, 0, pos, &outf);
	m_pickangle = outf;
	UpdateData(false);
	inputshow(IDC_pickangle);
}



void PARAMETERSET::Onphotor() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_photor);
	CRect rect;
	GetDlgItem(IDC_photor)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_photor,inlong ,m_photor, 360000, 0, pos, &outf);
	m_photor = outf;
	UpdateData(false);
	inputshow(IDC_photor);
}

void PARAMETERSET::Onreloadwaiting() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_reloadwaiting);
	CRect rect;
	GetDlgItem(IDC_reloadwaiting)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_reloadwaiting,inlong ,m_reloadwaiting, 39000, 0, pos, &outf);
	m_reloadwaiting = outf;
	UpdateData(false);
	inputshow(IDC_reloadwaiting);
}

void PARAMETERSET::Onreloadpick() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_reloadpick);
	CRect rect;
	GetDlgItem(IDC_reloadpick)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_reloadpick,inlong ,m_reloadpick, 39000, 0, pos, &outf);
	m_reloadpick = outf;
	UpdateData(false);
	inputshow(IDC_reloadpick);
}

void PARAMETERSET::Onreloadpush() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_reloadpush);
	CRect rect;
	GetDlgItem(IDC_reloadpush)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_reloadpush,inlong ,m_reloadpush, 39000, 0, pos, &outf);
	m_reloadpush = outf;
	UpdateData(false);
	inputshow(IDC_reloadpush);
}

void PARAMETERSET::Ontonguein() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_tonguein);
	CRect rect;
	GetDlgItem(IDC_tonguein)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_tonguein,inlong ,m_tonguein, 36000, 0, pos, &outf);
	m_tonguein = outf;
	UpdateData(false);
	inputshow(IDC_tonguein);
}

void PARAMETERSET::Onphotox() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_photox);
	CRect rect;
	GetDlgItem(IDC_photox)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_photox,inlong ,m_photox, 19000, 0, pos, &outf);
	m_photox = outf;
	UpdateData(false);
	inputshow(IDC_photox);
}

void PARAMETERSET::Onphotox2() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_photox2);
	CRect rect;
	GetDlgItem(IDC_photox2)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_photox2,inlong ,m_photox2, 19000, 0, pos, &outf);
	m_photox2 = outf;
	UpdateData(false);
	inputshow(IDC_photox2);
}




void PARAMETERSET::Onfixtureouttime() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_fixtureouttime);
	CRect rect;
	GetDlgItem(IDC_fixtureouttime)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_fixtureouttime,inlong ,m_fixtureouttime, 100, 0, pos, &outf);
	m_fixtureouttime = outf;
	UpdateData(false);
	inputshow(IDC_fixtureouttime);
}

void PARAMETERSET::Onmainmotorlength() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_mainmotorlength);
	CRect rect;
	GetDlgItem(IDC_mainmotorlength)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_mainmotorlength,inlong ,m_mainmotorlength, 100000, 0, pos, &outf);
	m_mainmotorlength = outf;
	UpdateData(false);
	inputshow(IDC_mainmotorlength);
}

void PARAMETERSET::Onfixturedelaytime() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_fixturedelaytime);
	CRect rect;
	GetDlgItem(IDC_fixturedelaytime)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_fixturedelaytime,inlong ,m_fixturedelaytime, 100, 0, pos, &outf);
	m_fixturedelaytime = outf;
	UpdateData(false);
	inputshow(IDC_fixturedelaytime);
}

void PARAMETERSET::Onpicktime() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_picktime);
	CRect rect;
	GetDlgItem(IDC_picktime)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_picktime,inlong ,m_picktime, 100, 0, pos, &outf);
	m_picktime = outf;
	UpdateData(false);
	inputshow(IDC_picktime);
}

void PARAMETERSET::Onphotodelay() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_photodelay);
	CRect rect;
	GetDlgItem(IDC_photodelay)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_photodelay,inlong ,m_photodelay, 100, 0, pos, &outf);
	m_photodelay = outf;
	UpdateData(false);
	inputshow(IDC_photodelay);

}

void PARAMETERSET::Onvexx() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_vexx);
	CRect rect;
	GetDlgItem(IDC_vexx)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_vexx,inlong ,m_vexx, 150000, 0, pos, &outf);
	m_vexx = outf;
	UpdateData(false);
	inputshow(IDC_vexx);
}

void PARAMETERSET::Onvload() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_vload);
	CRect rect;
	GetDlgItem(IDC_vload)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_vload,inlong ,m_vload, 60000, 0, pos, &outf);
	m_vload = outf;
	UpdateData(false);
	inputshow(IDC_vload);
}

void PARAMETERSET::Onvextonguein() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_vextonguein);
	CRect rect;
	GetDlgItem(IDC_vextonguein)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_vextonguein,inlong ,m_vextonguein, 80000, 0, pos, &outf);
	m_vextonguein = outf;
	UpdateData(false);
	inputshow(IDC_vextonguein);
}

void PARAMETERSET::Onpicky() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_picky);
	CRect rect;
	GetDlgItem(IDC_picky)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_picky,inlong ,m_picky, 38000, 0, pos, &outf);
	m_picky = outf;
	UpdateData(false);
	inputshow(IDC_picky);
}

void PARAMETERSET::Onpastey() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_pastey);
	CRect rect;
	GetDlgItem(IDC_pastey)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_pastey,inlong ,m_pastey, 40000, 0, pos, &outf);
	m_pastey = outf;
	UpdateData(false);
	inputshow(IDC_pastey);
}

void PARAMETERSET::Onrepastey() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_repastey);
	CRect rect;
	GetDlgItem(IDC_repastey)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_repastey,inlong ,m_repastey, 40000, 0, pos, &outf);
	m_repastey = outf;
	UpdateData(false);
	inputshow(IDC_repastey);
}

void PARAMETERSET::Onpasteangle() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_pasteangle);
	CRect rect;
	GetDlgItem(IDC_pasteangle)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_pasteangle,inlong ,m_pasteangle, 360000, -360000, pos, &outf);
	m_pasteangle = outf;
	UpdateData(false);
	inputshow(IDC_pasteangle);
}

void PARAMETERSET::Onrepasteangle() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_repasteangle);
	CRect rect;
	GetDlgItem(IDC_repasteangle)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_repasteangle,inlong ,m_repasteangle, 360000, -360000, pos, &outf);
	m_repasteangle = outf;
	UpdateData(false);
	inputshow(IDC_repasteangle);
}

void PARAMETERSET::Onloadwaiting() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_loadwaiting);
	CRect rect;
	GetDlgItem(IDC_loadwaiting)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_loadwaiting,inlong ,m_loadwaiting, 39000, 0, pos, &outf);
	m_loadwaiting = outf;
	UpdateData(false);
	inputshow(IDC_loadwaiting);
}

void PARAMETERSET::Onloadpick() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_loadpick);
	CRect rect;
	GetDlgItem(IDC_loadpick)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_loadpick,inlong ,m_loadpick, 39000, 0, pos, &outf);
	m_loadpick = outf;
	UpdateData(false);
	inputshow(IDC_loadpick);
}

void PARAMETERSET::Onloadpush() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_loadpush);
	CRect rect;
	GetDlgItem(IDC_loadpush)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_loadpush,inlong ,m_loadpush, 39000, 0, pos, &outf);
	m_loadpush = outf;
	UpdateData(false);
	inputshow(IDC_loadpush);
}

void PARAMETERSET::Ontongueout() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_tongueout);
	CRect rect;
	GetDlgItem(IDC_tongueout)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_tongueout,inlong ,m_tongueout, 20000, 0, pos, &outf);
	m_tongueout = outf;
	UpdateData(false);
	inputshow(IDC_tongueout);
}

void PARAMETERSET::Onphotoy() 
{
	// TODO: Add your control notification handler code here
	
	inputshow(IDC_photoy);
	CRect rect;
	GetDlgItem(IDC_photoy)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_photoy,inlong ,m_photoy, 40000, 0, pos, &outf);
	m_photoy = outf;
	UpdateData(false);	
	inputshow(IDC_photoy);
}

void PARAMETERSET::Onphotoy2() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_photoy2);
	CRect rect;
	GetDlgItem(IDC_photoy2)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_photoy2,inlong ,m_photoy2, 40000, 0, pos, &outf);
	m_photoy2 = outf;
	UpdateData(false);
	inputshow(IDC_photoy2);
}

void PARAMETERSET::Onzpush() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_zpush);
	CRect rect;
	GetDlgItem(IDC_zpush)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_zpush,inlong ,m_zpush, 20, 0, pos, &outf);
	m_zpush = outf;
	UpdateData(false);
	inputshow(IDC_zpush);
}

void PARAMETERSET::Onvexmainmotorlow() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_vexmainmotorlow);
	CRect rect;
	GetDlgItem(IDC_vexmainmotorlow)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_vexmainmotorlow,inlong ,m_vexmainmotorlow, 1000, 0, pos, &outf);
	m_vexmainmotorlow = outf;
	UpdateData(false);
	inputshow(IDC_vexmainmotorlow);
}

void PARAMETERSET::Onvexmainmotorhigh() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_vexmainmotorhigh);
	CRect rect;
	GetDlgItem(IDC_vexmainmotorhigh)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_vexmainmotorhigh,inlong ,m_vexmainmotorhigh, 20000, 0, pos, &outf);
	m_vexmainmotorhigh = outf;
	UpdateData(false);
	inputshow(IDC_vexmainmotorhigh);
}

void PARAMETERSET::Onpushertime() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_pushertime);
	CRect rect;
	GetDlgItem(IDC_pushertime)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_pushertime,inlong ,m_pushertime, 100, 0, pos, &outf);
	m_pushertime = outf;
	UpdateData(false);
	inputshow(IDC_pushertime);
}

void PARAMETERSET::Onloadtime() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_loadtime);
	CRect rect;
	GetDlgItem(IDC_loadtime)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_loadtime,inlong ,m_loadtime, 100, 0, pos, &outf);
	m_loadtime = outf;
	UpdateData(false);
	inputshow(IDC_loadtime);
}

void PARAMETERSET::Onunloadtime() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_unloadtime);
	CRect rect;
	GetDlgItem(IDC_unloadtime)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_unloadtime,inlong ,m_unloadtime, 100, 0, pos, &outf);
	m_unloadtime = outf;
	UpdateData(false);
	inputshow(IDC_unloadtime);
}

void PARAMETERSET::Onvexy() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_vexy);
	CRect rect;
	GetDlgItem(IDC_vexy)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_vexy,inlong ,m_vexy, 150000, 0, pos, &outf);
	m_vexy = outf;
	UpdateData(false);
	inputshow(IDC_vexy);
}

void PARAMETERSET::Onvturnplate() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_vturnplate);
	CRect rect;
	GetDlgItem(IDC_vturnplate)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_vturnplate,inlong ,m_vturnplate, 1000000, 0, pos, &outf);
	m_vturnplate = outf;
	UpdateData(false);
	inputshow(IDC_vturnplate);
}

void PARAMETERSET::Onvextongueout() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_vextongueout);
	CRect rect;
	GetDlgItem(IDC_vextongueout)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_vextongueout,inlong ,m_vextongueout, 80000, 0, pos, &outf);
	m_vextongueout = outf;
	UpdateData(false);
	inputshow(IDC_vextongueout);
}

void PARAMETERSET::Onsearchrange() 
{
	// TODO: Add your control notification handler code here
	

	inputshow(IDC_searchrange);
	CRect rect;
	GetDlgItem(IDC_searchrange)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_searchrange,inlong ,m_searchrange, 2000, 0, pos, &outf);
	m_searchrange = outf;
	UpdateData(false);
	inputshow(IDC_searchrange);
	
}

void PARAMETERSET::Onsearchrange2() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_searchrange2);
	CRect rect;
	GetDlgItem(IDC_searchrange2)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_searchrange2,inlong ,m_searchrange2, 2000, 0, pos, &outf);
	m_searchrange2 = outf;
	UpdateData(false);
	inputshow(IDC_searchrange2);
}

void PARAMETERSET::Onminscore11() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_minscore11);
	CRect rect;
	GetDlgItem(IDC_minscore11)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_minscore11,infloat ,m_minscore11, 0.9, 0.5, pos, &outf);
	m_minscore11 = outf;
	UpdateData(false);
	inputshow(IDC_minscore11);
}

void PARAMETERSET::Onminscore21() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_minscore21);
	CRect rect;
	GetDlgItem(IDC_minscore21)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_minscore21,infloat ,m_minscore21,0.9, 0.5, pos, &outf);
	m_minscore21 = outf;
	UpdateData(false);
	inputshow(IDC_minscore21);
}

void PARAMETERSET::Oncomno() 
{
	// TODO: Add your control notification handler code here

	inputshow(IDC_comno);
	CRect rect;
	GetDlgItem(IDC_comno)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_comno,inlong ,m_comno, 100, 0, pos,&outf);
	m_comno = outf;
	UpdateData(false);
	inputshow(IDC_comno);
}

void PARAMETERSET::Onzphoto() 
{
	// TODO: Add your control notification handler code here
	inputshow(IDC_zphoto);
	CRect rect;
	GetDlgItem(IDC_zphoto)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_zphoto,inlong ,m_zphoto, 120000, 0, pos,&outf);
	m_zphoto = outf;
	UpdateData(false);
	inputshow(IDC_zphoto);
}

HBRUSH PARAMETERSET::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	if ((nCtlColor==CTLCOLOR_STATIC)&&(pWnd-> GetDlgCtrlID()==IDnum))
	{
		pDC->SetBkMode(TRANSPARENT);
		//HBRUSH B = CreateSolidBrush(RGB(3, 168, 158));
		//return (HBRUSH)B;
		DeleteObject(pfixcolor);
		pfixcolor=CreateSolidBrush(RGB(3, 168, 158));
		return (HBRUSH)pfixcolor;
	}
	if ((nCtlColor==CTLCOLOR_STATIC)&&(pWnd-> GetDlgCtrlID()!=IDC_STATIC)&&(pWnd-> GetDlgCtrlID()!=IDC_PRESSTURN)&&(pWnd-> GetDlgCtrlID()!=IDC_currentrcp)
		&&(pWnd-> GetDlgCtrlID()!=IDnum))
	{
		pDC->SetBkMode(TRANSPARENT);
		//HBRUSH B = CreateSolidBrush(RGB(255, 255, 255));
		//return (HBRUSH)B;
		DeleteObject(pwhitecolor);
		pwhitecolor=CreateSolidBrush(RGB(255, 255, 255));
		return (HBRUSH)pwhitecolor;
	}
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void PARAMETERSET::inputshow(UINT nID)
{
    CRect rect;
	GetDlgItem(nID)->GetWindowRect(&rect);
	ScreenToClient(&rect);
	InvalidateRect(rect);
}

bool PARAMETERSET::GoSmallKey(int ctlID,intype intype, float invaluef , float Vlumax, float Vlumin,POINT point, float* outvaluef)
{

    IDnum=ctlID;
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
		IDnum=0;
	return true;
}







void PARAMETERSET::Onrollerfinished() 
{
	// TODO: Add your control notification handler code here
	inputshow(IDC_rollerfinished);
	CRect rect;
	GetDlgItem(IDC_rollerfinished)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_rollerfinished,inlong ,m_rollerfinished, 20000, 0, pos, &outf);
	m_rollerfinished = outf;
	UpdateData(false);
	inputshow(IDC_rollerfinished);
}

void PARAMETERSET::Onvexroller2() 
{
	// TODO: Add your control notification handler code here
	inputshow(IDC_vexroller2);
	CRect rect;
	GetDlgItem(IDC_vexroller2)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_vexroller2,inlong ,m_vexroller2, 120000, 0, pos, &outf);
	m_vexroller2 = outf;
	UpdateData(false);
	inputshow(IDC_vexroller2);
}

void PARAMETERSET::Onzvex() 
{
	// TODO: Add your control notification handler code here
	inputshow(IDC_zvex);
	CRect rect;
	GetDlgItem(IDC_zvex)->GetWindowRect(&rect);
	POINT pos;
	pos.x = rect.right;
	pos.y = rect.bottom;
	UpdateData(true);
	float outf = 0;
	GoSmallKey(IDC_zvex,inlong ,m_zvex, 100, 0, pos,&outf);
	m_zvex = outf;
	UpdateData(false);
	inputshow(IDC_zvex);
}
