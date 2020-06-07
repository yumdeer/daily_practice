// VAFS2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "VAFS2.h"
#include "VAFS2Dlg.h"
#include "DebugDlg.h"
#include "glbs.h"
#include "login.h"
//////////////////////////////////////////
CBitmap bitmap;
	HBITMAP hBmp;
///////////////////////////////////////////
//////////////////////////////////////////
bool positionxp=false;
bool positionxm=false;
bool positionyp=false;
bool positionym=false;
bool positionzp=false;
bool positionzm=false;
bool positionrp=false;
bool positionrm=false;
bool repositionxp=false;
bool repositionxm=false;
bool repositionyp=false;
bool repositionym=false;
bool repositionzp=false;
bool repositionzm=false;
bool repositionrp=false;
bool repositionrm=false;
int positiontimes=0;
/////////////////////////////////////////

//////////////////////////////////////
bool loselockfileerr=false;
bool passtimeerr=false;
bool dateovererr=false;
bool lock=false;
//////////////////////////////
int wastetimes=0;
int tonguedata;
long alarmtime=0;
bool uphandstart=false;
bool downhandstart=false;
bool 	upfinishedbool=false;

DWORD WINAPI Funline(
					 LPVOID lpParameter
					 );
 HANDLE LINETHREAD;

 DWORD WINAPI Funfixture(
					 LPVOID lpParameter
					 );
 HANDLE FIXTURETHREAD;

#include "dmc1000.h"  //包含1000B库头文件


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define NUM_BUFFERS 1
          
		  unsigned char orgdecchar[8]={0x01 ,0x06 ,0x00 ,0x06 ,0x00 ,0x1E ,0xE9 ,0xC3}; // 30ms

		  unsigned char speedrunchar[8]={0x01 ,0x06 ,0x00 ,0x0B ,0xFF ,0x02 ,0x38 ,0x39  };
		  unsigned char zspeedrunchar[8]={0x02 ,0x06 ,0x00 ,0x0B ,0x00 ,0x02 ,0x79 ,0xFA  };

		  unsigned char stopchar[8]={0x01, 0x06,0x00,0x0C,0x00, 0x11 ,0x89, 0xC5};
          unsigned char zstopchar[8]={0x02, 0x06,0x00,0x0C,0x00, 0x11 ,0x89, 0xF6};

	      unsigned char stopechar[8]={0x01, 0x06 ,0x00 ,0x0C ,0x00 ,0x22 ,0xC9 ,0xD0};


		  unsigned char signalchar[8]={0x01 ,0x06 ,0x00 ,0x0D ,0xFF ,0xF4 ,0x58 ,0x7E};
		  unsigned char zsignalchar[8]={0x02, 0x06, 0x00 ,0x0D ,0xFF ,0xF4 ,0x58, 0x4D};

		  unsigned char signalnochar[8]={0x01,0x06,0x00 ,0x0D ,0xFF,0xFF,0x19,0xB9};
		  unsigned char zsignalnochar[8]={0x02,0x06,0x00 ,0x0D ,0xFF,0xFF,0x19,0x8A};


		  unsigned char dectimechar[8]={0x01 ,0x06 ,0x00 ,0x06 ,0x01 ,0x2C ,0x69 ,0x86}; // 300ms 
		  unsigned char aectimechar[8]={0x01,0x06 ,0x00 ,0x05 ,0x01 ,0x2C ,0x99 ,0x86}; // 300ms
		  unsigned char zdectimechar[8]={0X02 ,0X06 ,0X00 ,0X06 ,0X00 ,0X1E ,0XE9,0XF0}; // 30ms 
		  unsigned char zaectimechar[8]={0x02,0x06 ,0x00 ,0x05 ,0x01 ,0x2C ,0x99 ,0xB5}; // 300ms


		  unsigned char divchar[8]={0x01 ,0x06 ,0x00 ,0x03 ,0x00 ,0x08 ,0x78 ,0x0C };// 2000 脉冲/转
		  unsigned char zdivchar[8]={0x02,0x06 ,0x00 ,0x03 ,0x00 ,0x03 ,0x39 ,0xF8}; // 3200 脉冲/转
		 
		  unsigned char powerchar[8]={0x01 ,0x06 ,0x00 ,0x02 ,0xFF ,0x04 ,0x68 ,0x39	}; // 3.1A
		   unsigned char zpowerchar[8]={0x02 ,0x06 ,0x00 ,0x02 ,0xFF ,0x06 ,0xE9 ,0xCB	}; // 4A
		
		  unsigned char startspeedchar[8]={0x01 ,0x06 ,0x00 ,0x04 ,0x00 ,0x02 ,0x49 ,0xCA}; // 2 r/min

		  unsigned char casechar[8]={0x01, 0x03 ,0x00 ,0x0A ,0x00, 0x01 ,0xA4, 0x08}; // 读运行状态
		  unsigned char zcasechar[8]={0x02, 0x03 ,0x00 ,0x0A ,0x00, 0x01 ,0xA4, 0x3B}; // 读运行状态

float centery2temp,centerx2temp;
float centerytemp,centerxtemp;
float recentery2temp,recenterx2temp;
float recenterytemp,recenterxtemp;
long tongueinuse;
long tongueoutuse;
float showtranskeyx,showtranskeyy;
float reshowtranskeyx,reshowtranskeyy;

bool photoalreadyproblem2=false;
int throwcounter=0;

bool firstload=false;
bool secondload=false;

bool fixturefree=false;
bool loadfinished=false;
bool fixturecanphoto=false;
bool vacuumerror=false;
bool tapeerror=false;
bool leftfixtureerror=false;
bool rightfixtureerror=false;
bool lastone=false;
bool lastgoon=false;
bool lastover=false;
bool lastgodis=false;


unsigned char currentsendchar[8];
float xa,ya;
float rexa,reya;

//bool firstbigproblem=false;
bool firstlinestart=true;
bool linestart=false;
bool photoalreadyerror=false;

bool poweronok=false;

float rollerxlength,rollerylength;
float metalverifyx,metalverifyy;

DWORD pushstate;

 CFont fontbig;
 CFont fontsmall;
 CFont fontsmaller;
 CFont fontproblemlist;
 int shapematch=0;
 int progress=0;
bool caculated=false;
bool halfdown=false;
float angle=0;
float angle2=0;
float angle21=0;
float angle22=0;
float reangle=0;
float reangle2=0;
float reangle21=0;
float reangle22=0;
int anglepluse;
int reanglepluse;
float firstrobotx,secondrobotx;
float firstroboty,secondroboty;
float firstcamerax,secondcamerax;
float firstcameray,secondcameray;
float camerax1,cameray1,camerax2,cameray2,servox1,servoy1,servox2,servoy2;
DWORD xorgstate;
DWORD tongueorgstate;


		   DWORD  loadorgstate;
			DWORD turnarroworgstate;
DWORD yorgstate;
DWORD zorgstate;
DWORD turnplateorgstate;

DWORD mainmotorstate;

DWORD updownorgstate;


mypoint point1,point2,point3;
metalpoint metalposition[50],metalpasted[50],currentmetalposition,oldmetalposition;
int metalpastedcounter=0;

float flowx,flowy;
mypoint opticalflowcenter;

    bool leftvacummregion=true;
	bool rightvacummregion=true;
	bool linecango=false;
	bool loadfree=false;


	int times=0;
    int vacuumcounter=0;

	int maintimes=0;
	int fixturetimes;
	int placetimes;
	int presstimes=0;
	bool Rfixturepress=false;
	bool overturnplace=false;
	int replacetimes;

	int linetimes;
	int footup=0;
	int footdown=0;
    int footold=0;
	int footnew=0;
	int fixturevacuumok;

	int loadprogress,unloadprogress;

	int leftfootup=0;
	int leftfootdown=0;
    int leftfootold=0;
	int leftfootnew=0;
	int leftfoottemp;
	int rightfoottemp;
	int leftfixturevacuumok;
	int loadvacuumcounter=0;
	int unloadvacuumcounter=0;
	
	//int servoxtime;
	//int rollerservotime;
	//int updownservotime;
	//int lockhometime;
    int tonguehometime;
	int fixtureerrtime=0;
	//int rollerhometime;
	//int leftvacuumtime;
	//int rightvacuumtime=0;
	//int rolleruptime;
	//int leanuptime;
	//int curtentime=0;
	int servoxtime;
	int servoytime;
	int zerrortime=0;
	int presserrortime=0;
	int pusheruptime;
    int pusherdowntime;
	int rollertime;
	int vacuumtime;
	//int carrylefttime=0;
//	int carryrighttime=0;
	//int loaduptime=0;
	//int unloaduptime=0;
     float rekeypastex,rekeypastey;
	
	int mainmotortime;
	int tonguetime;
//	int highspeedtime;
	int fixtureintime;
//	int fixtureouttimeforerr;
	
//	bool outofrange=false;
		bool xoutofrange=false;
			bool youtofrange=false;
				bool routofrange=false;

	bool photoproblem=false;
	bool photoproblem2=false;

	bool loadvacuum1error=false;
		bool loadvacuum2error=false;
	bool leftanglebig=false;
	bool rightanglebig=false;
	bool leftpositionbig=false;
	bool rightpositionbig=false;
	int doortime;
    bool wasteerror=false;

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVAFS2Dlg dialog

CVAFS2Dlg::CVAFS2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVAFS2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CVAFS2Dlg)
	m_pastecounter = 0;
	m_hour = 0;
	m_minute = 0;
	m_second = 0;
	m_pastex = 0;
	m_pastey = 0;
	m_pasteangle = 0;
	m_repasteangle = 0;
	m_repastex = 0;
	m_repastey = 0;
	m_totalcounter = 0;
	m_castcounter = 0;
	m_slavenum = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
//	m_bStartCapture  = FALSE;
//	m_hDevice = NULL;
}

void CVAFS2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVAFS2Dlg)
	DDX_Control(pDX, IDC_downfinished, m_downfinished);
	DDX_Control(pDX, IDC_upstart, m_upstart);
	DDX_Control(pDX, IDC_lastone, m_lastone);
	DDX_Control(pDX, IDC_ANGLEPm, m_pasteanglepm);
	DDX_Control(pDX, IDC_ANGLEMm, m_pasteanglemm);
	DDX_Control(pDX, IDC_YPm, m_YPm);
	DDX_Control(pDX, IDC_YMm, m_YMm);
	DDX_Control(pDX, IDC_XPm, m_XPm);
	DDX_Control(pDX, IDC_XMm, m_XMm);
	DDX_Control(pDX, IDC_LISTOUT2, m_list2);
	DDX_Control(pDX, IDC_ANGLEM, m_pasteanglem);
	DDX_Control(pDX, IDC_ANGLEP, m_pasteanglep);
	DDX_Control(pDX, IDC_YP, m_YP);
	DDX_Control(pDX, IDC_YM, m_YM);
	DDX_Control(pDX, IDC_XP, m_XP);
	DDX_Control(pDX, IDC_XM, m_XM);
	DDX_Control(pDX, IDC_STOP, m_stop);
	DDX_Control(pDX, IDC_RESET, m_reset);
	DDX_Control(pDX, IDC_DEBUG, m_debug);
	DDX_Control(pDX, IDC_START, m_start);
	DDX_Control(pDX, IDC_problem, m_problemlist);
	DDX_Control(pDX, IDC_LISTOUT, m_list1);
	DDX_Text(pDX, IDC_PASTECOUNTER, m_pastecounter);
	DDX_Text(pDX, IDC_hour, m_hour);
	DDX_Text(pDX, IDC_minute, m_minute);
	DDX_Text(pDX, IDC_second, m_second);
	DDX_Text(pDX, IDC_pastex, m_pastex);
	DDX_Text(pDX, IDC_pastey, m_pastey);
	DDX_Text(pDX, IDC_pasteangle, m_pasteangle);
	DDX_Text(pDX, IDC_repasteanglem, m_repasteangle);
	DDX_Text(pDX, IDC_repastexm, m_repastex);
	DDX_Text(pDX, IDC_repasteym, m_repastey);
	DDX_Text(pDX, IDC_TOTALCOUNTER, m_totalcounter);
	DDX_Text(pDX, IDC_CASTCOUNTER, m_castcounter);
	DDX_Text(pDX, IDC_slavenum, m_slavenum);
	DDX_Control(pDX, IDC_MSCOMM1, m_serial);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CVAFS2Dlg, CDialog)
	//{{AFX_MSG_MAP(CVAFS2Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_DESTROY()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_DEBUG, OnDebug)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_START, OnStart)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_BN_CLICKED(IDC_RESET, OnReset)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_lastone, Onlastone)
	ON_BN_CLICKED(IDC_counterzero1, Oncounterzero1)
	ON_BN_CLICKED(IDC_counterzero2, Oncounterzero2)
	ON_BN_CLICKED(IDC_counterzero3, Oncounterzero3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVAFS2Dlg message handlers




BOOL CVAFS2Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
   
	
	// TODO: Add extra initialization here





    	HException::InstallHHandler(&MyHalconExceptionHandler); 
	//配方参数处理
    //current dir

	CString strAppPath;
	::GetModuleFileName(NULL,strAppPath.GetBuffer(_MAX_PATH),_MAX_PATH);
	strAppPath.ReleaseBuffer();
	int nPos=strAppPath.ReverseFind('\\');
	currentdir=strAppPath.Left(nPos);
	nPos=currentdir.ReverseFind('\\');
	currentdir=currentdir.Left(nPos);
    currentrcpname=currentdir+"\\current.rcp";

	currentparametername=currentdir+"\\current.para";
	currentmodelname=currentdir+"\\current.shm";
	currentmodelname2=currentdir+"\\current2.shm";
	currentmodelname3=currentdir+"\\current3.shm";
	currentmodelname4=currentdir+"\\current4.shm";
	currentmodelname21=currentdir+"\\current21.shm";
	currentmodelname22=currentdir+"\\current22.shm";
	currentmodelname31=currentdir+"\\current31.shm";
	currentmodelname32=currentdir+"\\current32.shm";
	currentmodelname41=currentdir+"\\current41.shm";
	currentmodelname42=currentdir+"\\current42.shm";

	currentphotoname=currentdir+"\\current.photo";
	listrcpname=currentdir+"\\listrcp.txt";
	counterfilename=currentdir+"\\counter.txt";

	
    if(GetFileAttributes(counterfilename)==-1)
	{
		 CFile counterfilenew;
		 counterfilenew.Open(counterfilename,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);

	     CArchive counterfilearnew(&counterfilenew,CArchive::store);
		 
		
		 counterfilearnew<<pastecounter<<castcounter<<totalcounter;
		 counterfilearnew.Close();
		 counterfilenew.Close();
	}
    {
		 CFile counterfile;
		 counterfile.Open(counterfilename,CFile::modeRead);

	     CArchive counterfilear(&counterfile,CArchive::load);
		 
		
		 counterfilear>>pastecounter>>castcounter>>totalcounter;
		 counterfilear.Close();
		 counterfile.Close();
	}
	
    





    if(GetFileAttributes(currentrcpname)==-1)
	{
		 CFile currentrcpnew;
		 currentrcpnew.Open(currentrcpname,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);

	     CArchive currentrcparnew(&currentrcpnew,CArchive::store);
		 CString filename;
		 filename="current";
		 currentrcparnew<<filename;
		 currentrcparnew.Close();
		 currentrcpnew.Close();

		 CFile currentparanew;
         currentparanew.Open(currentparametername,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);
	     CArchive currentparaarnew(&currentparanew,CArchive::store);
		 currentparaarnew<<PARAINPUT;
         currentparaarnew.Close();
		 currentparanew.Close();

		 
        


       
		

	}

    
    if(GetFileAttributes(listrcpname)==-1)
	{
		 CFile listrcpnew;
		 listrcpnew.Open(listrcpname,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);

	     CArchive listrcparnew(&listrcpnew,CArchive::store);
		 CString filename;
		 filename="current";
		 int i=0;
		 listrcparnew<<i<<filename;
		 listrcparnew.Close();
		 listrcpnew.Close();

		 CFile scalenew;
         scalenew.Open(currentdir+"\\scale.txt",CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);
	     CArchive scalearnew(&scalenew,CArchive::store);
		 scalearnew<<xscale<<yscale<<xdiv<<ydiv<<camera2xdiv<<camera2ydiv<<metalscale<<metalyscale<<photo2angle<<photo1angle;
         scalearnew.Close();
		 scalenew.Close();

	}


    CFile scalenew;
    scalenew.Open(currentdir+"\\scale.txt",CFile::modeRead);
	CArchive scalearnew(&scalenew,CArchive::load);
	scalearnew>>xscale>>yscale>>xdiv>>ydiv>>camera2xdiv>>camera2ydiv>>metalscale>>metalyscale>>photo2angle>>photo1angle;
    scalearnew.Close();
	scalenew.Close();


	CFile currentrcp;
	currentrcp.Open(currentrcpname,CFile::modeRead);
	CArchive currentrcpar(&currentrcp,CArchive::load);
	currentrcpar>>rcpname;
	currentparametername=currentdir+"\\"+rcpname+".para";
	currentmodelname=currentdir+"\\"+rcpname+".shm";
	currentmodelname2=currentdir+"\\"+rcpname+"2.shm";
	currentmodelname3=currentdir+"\\"+rcpname+"3.shm";
	currentmodelname4=currentdir+"\\"+rcpname+"4.shm";
	currentmodelname21=currentdir+"\\"+rcpname+"21.shm";
	currentmodelname22=currentdir+"\\"+rcpname+"22.shm";
	currentmodelname31=currentdir+"\\"+rcpname+"31.shm";
	currentmodelname32=currentdir+"\\"+rcpname+"32.shm";
	currentmodelname41=currentdir+"\\"+rcpname+"41.shm";
	currentmodelname42=currentdir+"\\"+rcpname+"42.shm";


	currentphotoname=currentdir+"\\"+rcpname+".photo";
	passwordname=currentdir+"\\"+"password"+".txt";
	currentrcpar.Close();
	currentrcp.Close();

	if(GetFileAttributes(currentphotoname)==-1)
	{
		 CFile currentphotonew;
		 currentphotonew.Open(currentphotoname,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);
	     CArchive currentphotoarnew(&currentphotonew,CArchive::store);
		 currentphotoarnew<<shutter<<bright<<gain<<shutter2<<shutter3<<shutter4<<shutter5<<gain2<<contrast1<<contrast2<<model11x<<model11y<<model12x<<model12y<<model21x<<model21y<<model22x<<model22y
			 <<model11halfx<<model11halfy<<model12halfx<<model12halfy<<model13halfx<<model13halfy<<model14halfx<<model14halfy<<model21halfx<<model21halfy<<model22halfx<<model22halfy<<modalorg11<<modalorg12<<modalorg13<<modalorg14<<modalorg21<<modalorg22
			 <<remodel11x<<remodel11y<<remodel12x<<remodel12y<<remodel21x<<remodel21y<<remodel22x<<remodel22y;
		 currentphotoarnew.Close();
		 currentphotonew.Close();
	}
    if(GetFileAttributes(passwordname)==-1)
	{
		 CFile passwordnew;
		 passwordnew.Open(passwordname,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);
	     CArchive passwordarnew(&passwordnew,CArchive::store);
		 CString password="af";
		 passwordarnew<<password;
		 passwordarnew.Close();
		 passwordnew.Close();
	}
	CFile passwordnew;
	passwordnew.Open(passwordname,CFile::modeRead);
	CArchive passwordarnew(&passwordnew,CArchive::load);
	passwordarnew>>password;
	passwordarnew.Close();
	passwordnew.Close();



	CFile currentpara;
	currentpara.Open(currentparametername,CFile::modeRead);
	CArchive currentparaar(&currentpara,CArchive::load);
	currentparaar>>PARAOUTPUT;
	currentparaar.Close();
	currentpara.Close();


    CFile currentphoto;
    currentphoto.Open(currentphotoname,CFile::modeRead);
    CArchive currentphotoar(&currentphoto,CArchive::load);
	currentphotoar>>shutter>>bright>>gain>>shutter2>>shutter3>>shutter4>>shutter5>>gain2>>contrast1>>contrast2>>model11x>>model11y>>model12x>>model12y>>model21x>>model21y>>model22x>>model22y
		>>model11halfx>>model11halfy>>model12halfx>>model12halfy>>model13halfx>>model13halfy>>model14halfx>>model14halfy>>model21halfx>>model21halfy>>model22halfx>>model22halfy>>modalorg11>>modalorg12>>modalorg13>>modalorg14>>modalorg21>>modalorg22
        >>remodel11x>>remodel11y>>remodel12x>>remodel12y>>remodel21x>>remodel21y>>remodel22x>>remodel22y;
    currentphotoar.Close();
    currentphoto.Close();
   

   

//////////////////////////////////////////////////////

///////////////////////////////////////////////////////   


	
   fontbig.CreatePointFont(240,"黑体",NULL);
   m_start.SetFont(&fontbig);
   m_stop.SetFont(&fontbig);
   m_reset.SetFont(&fontbig);
   m_debug.SetFont(&fontbig);
   m_lastone.SetFont(&fontbig);
 

   fontsmall.CreatePointFont(160,"黑体",NULL);
   fontsmaller.CreatePointFont(120,"宋体",NULL);
   fontproblemlist.CreatePointFont(180,"宋体",NULL);
   //m_problemlist.SetFont(&fontsmall);
   m_problemlist.SetFont(&fontproblemlist);
   m_list1.SetFont(&fontsmaller);
   m_list2.SetFont(&fontsmaller);

   CWnd *cwnd=GetDlgItem(IDC_STATICminder);
   //cwnd->SetFont(&fontsmall);
   cwnd->SetFont(&fontproblemlist);
   cwnd=GetDlgItem(IDC_STATICcounter);
   cwnd->SetFont(&fontsmaller);
   cwnd=GetDlgItem(IDC_STATICcounter2);
   cwnd->SetFont(&fontsmaller);
   cwnd=GetDlgItem(IDC_STATICcounter3);
   cwnd->SetFont(&fontsmaller);

   cwnd=GetDlgItem(IDC_STATICupstart);
   cwnd->SetFont(&fontsmaller);
   cwnd=GetDlgItem(IDC_STATICdownover);
   cwnd->SetFont(&fontsmaller);
   cwnd=GetDlgItem(IDC_STATIClift);
   cwnd->SetFont(&fontsmaller);
   cwnd=GetDlgItem(IDC_STATICright);
   cwnd->SetFont(&fontsmaller);

  //cwnd=GetDlgItem(IDC_STATICcounter);
   //cwnd->SetFont(&fontsmall);
   
   //cwnd=GetDlgItem(IDC_PASTECOUNTER);
   //cwnd->SetFont(&fontsmall);
   cwnd=GetDlgItem(IDC_hour);
   cwnd->SetFont(&fontsmall);
   cwnd=GetDlgItem(IDC_minute);
   cwnd->SetFont(&fontsmall);
   cwnd=GetDlgItem(IDC_second);
   cwnd->SetFont(&fontsmall);
   cwnd=GetDlgItem(IDC_pastex);
   cwnd->SetFont(&fontsmall);
   cwnd=GetDlgItem(IDC_pastey);
   cwnd->SetFont(&fontsmall);
   cwnd=GetDlgItem(IDC_pasteangle);
   cwnd->SetFont(&fontsmall);
  
   cwnd=GetDlgItem(IDC_PASTECOUNTER);
   cwnd->SetFont(&fontsmall);
   cwnd=GetDlgItem(IDC_CASTCOUNTER);
   cwnd->SetFont(&fontsmall);
   cwnd=GetDlgItem(IDC_TOTALCOUNTER);
   cwnd->SetFont(&fontsmall);

    
	m_XP.SetFont(&fontsmall);
	m_XM.SetFont(&fontsmall);
	m_YP.SetFont(&fontsmall);
	m_YM.SetFont(&fontsmall);
	m_pasteanglep.SetFont(&fontsmall);
	m_pasteanglem.SetFont(&fontsmall);

	 cwnd=GetDlgItem(IDC_repastexm);
   cwnd->SetFont(&fontsmall);
   cwnd=GetDlgItem(IDC_repasteym);
   cwnd->SetFont(&fontsmall);
   cwnd=GetDlgItem(IDC_repasteanglem);
   cwnd->SetFont(&fontsmall);
  
   

	m_XPm.SetFont(&fontsmall);
	m_XMm.SetFont(&fontsmall);
	m_YPm.SetFont(&fontsmall);
	m_YMm.SetFont(&fontsmall);
	m_pasteanglepm.SetFont(&fontsmall);
	m_pasteanglemm.SetFont(&fontsmall);






   cwnd=GetDlgItem(IDC_dot1);
   cwnd->SetFont(&fontsmall);
   cwnd=GetDlgItem(IDC_dot2);
   cwnd->SetFont(&fontsmall);

   CString currentexe;
   currentexe=currentdir+"\\Release\\vafs2.exe";
   WritePrivateProfileString(_T("windows"),_T("run"),currentexe,_T("c:/windows/win.ini"));
   m_pastex=pastex;
   m_pastey=pastey;
   m_slavenum=comno;
   m_pasteangle=pasteangle;

      m_repastex=repastex;
   m_repastey=repastey;

   m_repasteangle=repasteangle;






   

	

       m_serial.SetCommPort(1); //选择串4?

       m_serial. SetInBufferSize(2048); //设置输入缓冲区的大小，Bytes

       m_serial. SetOutBufferSize(512); //设置输入缓冲区的大小，Bytes// 

          m_serial.SetEOFEnable(false);
	     m_serial.SetDTREnable(false);
	     m_serial.SetRTSEnable(true);

       if(!m_serial.GetPortOpen()) //打开串口

	   {m_serial.SetPortOpen(TRUE);}

       m_serial.SetInputMode(1); //设置输入方式为二进制方式

       m_serial.SetSettings("19200,n,8,1"); //设置波特率等参数

    
       m_serial.SetRThreshold(1); //为1表示有一个字符引发一个事件

       m_serial.SetInputLen(0);
	   m_serial.GetInput(); 


	 





     
          
		 
	     
         // sendtomotor(speedchar);
           
		 //sendtomotor(highpositionchar);
	

		  //sendtomotor(lowpositionchar);
	 	
		  //sendtomotor(dectimechar);
	  



   

	
   int nCard(0);
   nCard = d1000_board_init();
   if( nCard <= 0 )//控制卡初始化
   MessageBox("未找到控制卡!","警告");
    	d1000_set_sd(0,0);
		d1000_set_pls_outmode(0,1);

		d1000_set_sd(1,0);
		d1000_set_pls_outmode(1,1);

		d1000_set_sd(2,0);
		d1000_set_pls_outmode(2,1);
		d1000_set_sd(3,0);
		d1000_set_pls_outmode(3,1);
		//d1000_out_bit(backlinemotor, back);


	{
		tDSCameraDevInfo DSCameraList[2];
	int m_iNum ;
      	CameraGetDevList(DSCameraList, &m_iNum);

	 emDSCameraStatus status = CameraInit(SnapCallBack1, DSCameraList[0].acFriendlyName, NULL,&camera1);
//	emDSCameraStatus status;	 
	if (status != STATUS_OK)
	{		
		AfxMessageBox("相机1初始化失败！");
		//return true;
	} 
	  char sn[32];
	  int nReaded;
      memset(sn, 0, 32);

      CameraReadSN(camera1, 2, (BYTE*)sn, 32, &nReaded);
	  if(sn[0]==49)//1
	  {
		 status = CameraInit(SnapCallBack2, DSCameraList[1].acFriendlyName, NULL,&camera2);
		//emDSCameraStatus status;	 
		if (status != STATUS_OK)
		{		
		AfxMessageBox("相机2初始化失败！");
		//return true;
		} 

	  }
	  else
	  {
		  CameraStop(camera1);
		  CameraUnInit(camera1);
		  status = CameraInit(SnapCallBack1, DSCameraList[1].acFriendlyName, NULL,&camera1);
		  	if (status != STATUS_OK)
			{AfxMessageBox("相机1初始化失败！");	} 
		  status = CameraInit(SnapCallBack2, DSCameraList[0].acFriendlyName, NULL,&camera2);
		  if (status != STATUS_OK)
			{AfxMessageBox("相机2初始化失败！");	} 

	  }

	//CameraSetWBWindow(camera1,0,0,4384,3288);

	CameraSetOnceWB(camera1);
	CameraSetOnceWB(camera2);


	CameraSetMirror(camera1,MIRROR_DIRECTION_VERTICAL,true);
	CameraSetMirror(camera2,MIRROR_DIRECTION_HORIZONTAL,true);



    InitDeviceFunction();


  }


     
		QueryPerformanceFrequency( &linenewTime );
    	QueryPerformanceFrequency( &lineoldTime );
		QueryPerformanceFrequency( &fixturenewTime );
    	QueryPerformanceFrequency( &fixtureoldTime );
      LINETHREAD=CreateThread(NULL,0,Funline,NULL,0,NULL);
	 FIXTURETHREAD=CreateThread(NULL,0,Funfixture,NULL,0,NULL);
	 QueryPerformanceFrequency( &m_Frequency );
  
 

	m_list1.SetExtendedStyle( 0x22 );
//	m_list1.InsertColumn( 0, "编号", LVCFMT_LEFT, 50 );
	m_list1.InsertColumn( 1, "相似度", LVCFMT_LEFT, 90 );
	m_list1.InsertColumn( 2, "角度", LVCFMT_LEFT, 110 );
//	m_list1.InsertColumn( 3, "比例", LVCFMT_LEFT, 60 );
	m_list1.InsertColumn( 4, "中心x", LVCFMT_LEFT, 120);
	m_list1.InsertColumn( 5, "中心y", LVCFMT_LEFT, 120 );


	m_list2.SetExtendedStyle( 0x22 );
//	m_list1.InsertColumn( 0, "编号", LVCFMT_LEFT, 50 );
	m_list2.InsertColumn( 1, "相似度", LVCFMT_LEFT, 90 );
	m_list2.InsertColumn( 2, "角度", LVCFMT_LEFT, 110 );
//	m_list1.InsertColumn( 3, "比例", LVCFMT_LEFT, 60 );
	m_list2.InsertColumn( 4, "中心x", LVCFMT_LEFT, 120);
	m_list2.InsertColumn( 5, "中心y", LVCFMT_LEFT, 120 );
	




	 {OnLoadModel(); }
      //initdio();
	
    ShowWindow(SW_SHOWMAXIMIZED);
		
	SetTimer( 1, 10, NULL );


	set_system("width",2592);
    set_system("height",2592);
	set_system("pregenerate_shape_models","true");





    Hlong m_WindowRow, m_WindowColumn, m_WindowWidth, m_WindowHeight;
		



			
    set_window_attr("border_width",HTuple(0));
	set_window_attr("window_title",HTuple("Camera"));
	
    set_check("~father");

	CRect rtWindow;	
	HWND hWnd = GetDlgItem(IDC_PORFILE_RECT)->m_hWnd;
    Hlong	lWWindowID = (Hlong)hWnd;


	GetDlgItem(IDC_PORFILE_RECT)->GetClientRect(&rtWindow);
	m_WindowRow = rtWindow.top;
	m_WindowColumn = rtWindow.left;
	m_WindowWidth = rtWindow.Width();
	m_WindowHeight = rtWindow.Height();
	open_window(m_WindowRow,m_WindowColumn,m_WindowWidth,m_WindowHeight,
				lWWindowID,"visible","",&m_Windowid);


	
	set_part(m_Windowid,0,0,camera1width,camera1height);
	set_part_style(m_Windowid,0);
	


		
	hWnd = GetDlgItem(IDC_PORFILE_RECT2)->m_hWnd;
	lWWindowID = (Hlong)hWnd;
	
	GetDlgItem(IDC_PORFILE_RECT2)->EnableWindow(true);//ModifyStyle(0,SS_NOTIFY); 

	GetDlgItem(IDC_PORFILE_RECT2)->GetClientRect(&rtWindow);
	m_WindowRow = rtWindow.top;
	m_WindowColumn = rtWindow.left;
	m_WindowWidth = rtWindow.Width();
	m_WindowHeight = rtWindow.Height();


	open_window(m_WindowRow,m_WindowColumn,m_WindowWidth,m_WindowHeight,
				lWWindowID,"visible","",&m_Window2id);
	set_part(m_Window2id,0,0,camera2width,camera2height);
	set_part_style(m_Window2id,0);
	set_check("father");


    try
	{
//	gen_image_const(&Image1,"byte",1000,1000);
	read_image(&Image1,"1.bmp");//test count
    read_image(&Image2,"1.bmp");
//	gen_image_const(&Image2,"byte",1000,1000);//ReadImage("1.bmp");
    disp_image(Image1,m_Windowid);
	disp_image(Image2,m_Window2id);
	
  //  set_color(m_Window2id,"red");

	//disp_cross(m_Window2id,keypastey,keypastex,80,0);
	  



		set_shape_model_param(ShapeModel11,"timeout",3500);
			set_shape_model_param(ShapeModel12,"timeout",3500);
			    set_shape_model_param(ShapeModel13,"timeout",3500);
			        set_shape_model_param(ShapeModel14,"timeout",3500);
				        set_shape_model_param(ShapeModel21,"timeout",3500);
					        set_shape_model_param(ShapeModel22,"timeout",3500);
	
	}
	catch (HException &except)
	{	
		Herror error_num;
		 error_num= except.err;
        	//MessageBox(error_num);
		 
		 
	}
	





///////////////////////////////////////////////////////////////////////////////LOCK
	{
	
	CString timepath;
	timepath="d:\\install.shm";

	short pass_year,pass_month,pass_day,pass_hour,pass_minute,pass_second;
    pass_year=0;
	pass_month=0;
	pass_day=0;
	pass_hour=0;
	pass_minute=0;
	pass_second=0;
	if(GetFileAttributes(timepath)==-1)
	{
		loselockfileerr=true;
		lock=true;
	}
    else
	{
	     CFile counterfile;
		 counterfile.Open(timepath,CFile::modeRead);

	     CArchive counterfilear(&counterfile,CArchive::load);
		 
		
		 counterfilear>>pass_year>>pass_month>>pass_day>>pass_hour>>pass_minute>>pass_second;
		 counterfilear.Close();
		 counterfile.Close();
		 UpdateData(false);
         SYSTEMTIME systime;
	     ::GetLocalTime(&systime);
		 
		 if(systime.wYear<pass_year)
		 {
			 passtimeerr=true;
			 lock=true;
		 }
		 if(systime.wYear==pass_year)
		 {
			 
			 if(systime.wMonth<pass_month)
			 {
				 passtimeerr=true;
				 lock=true;
			 }
			 if(systime.wMonth==pass_month)
			 {
				 
				 if(systime.wDay<pass_day)
				 {
					 passtimeerr=true;
					 lock=true;
				 }
				 if(systime.wDay==pass_day)
				 {
					 
					 if(systime.wHour<pass_hour)
					 {
						 passtimeerr=true;
						 lock=true;
					 }
				 }
			 }
		 }
		 
	}
	}
    
	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CVAFS2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

void CVAFS2Dlg::OnDestroy()
{
    CameraStop(camera1);
	CameraUnInit(camera1);
	
    CameraStop(camera2);
	CameraUnInit(camera2);

	KillTimer(1);

	{
		 CFile counterfilenew;
		 counterfilenew.Open(counterfilename,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);

	     CArchive counterfilearnew(&counterfilenew,CArchive::store);
		 
		
		 counterfilearnew<<pastecounter<<castcounter<<totalcounter;
		 counterfilearnew.Close();
		 counterfilenew.Close();
	}
	if(m_serial.GetPortOpen()) 
	{  
		m_serial.SetPortOpen(false); 
	} 

	CloseHandle(LINETHREAD);
	CloseHandle(FIXTURETHREAD);

	WinHelp(0L, HELP_QUIT);
	CDialog::OnDestroy();
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CVAFS2Dlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	if (IsIconic())
	{
	

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		DrawObject(&dc);
		CDialog::OnPaint();
	}
}





//初始化设备，给设备指定任务
BOOL CVAFS2Dlg::InitDeviceFunction()
{
	    CameraSetAeState(camera1, FALSE);
        CameraSetExposureTime(camera1, shutter*10000);
	  	
		CameraSetAnalogGain(camera1,gain);

		   CameraSetAeState(camera2, FALSE);
        CameraSetExposureTime(camera2, shutter3*10000);
	  	
		CameraSetAnalogGain(camera2,gain2);
			CameraSetContrast(camera1, contrast1);
	CameraSetContrast(camera2, contrast2);
		



	return TRUE;
	
}





// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CVAFS2Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CVAFS2Dlg::OnDebug() 
{
	// TODO: Add your control notification handler code here
   
	
	Clogin logindlg;
	logindlg.DoModal();
	if(logindlg.m_password==password)
	{

		if((logindlg.m_change==logindlg.m_changeupdata)&&(logindlg.m_change.GetLength()>0))
		{
		 password=logindlg.m_change;
		 CFile passwordnew;
		 passwordnew.Open(passwordname,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);
	     CArchive passwordarnew(&passwordnew,CArchive::store);
		 passwordarnew<<password;
		 passwordarnew.Close();
		 passwordnew.Close();

		
		}
        set_part_style(	m_Windowid,2);
		set_part_style(m_Window2id,2);
		CDebugDlg dlg;
	    dlg.DoModal();

	
		set_part_style(m_Windowid,0);
		set_part_style(m_Window2id,0);
   	    InitDeviceFunction();
		OnLoadModel(); 
		zoomfactor=1;
		zoomupdown=0;
		zoomleftright=0;
	    set_part(m_Windowid,0,0,camera1width,camera1height);
	    //set_part(m_Window2id,0,0,camera2width,camera2height);

		m_pastex=pastex;
		m_pastey=pastey;
		m_slavenum=comno;
		m_pasteangle=pasteangle;
		
      m_repastex=repastex;
   m_repastey=repastey;

   m_repasteangle=repasteangle;

			/*	{
					int i;
					for(i=0;i<4;i++)
					{outspeedchar[i]=speedchar[i];}
					outspeedchar[4]=vextongueout/30/256;
					outspeedchar[5]=vextongueout/30%256;
					outspeedchar[7]= calcrc(outspeedchar, 6)/256;
					outspeedchar[6]=calcrc(outspeedchar,6)%256;
				}
				{
					int i;
					for(i=0;i<4;i++)
					{inspeedchar[i]=speedchar[i];}
					inspeedchar[4]=vextonguein/30/256;
					inspeedchar[5]=vextonguein/30%256;
					inspeedchar[7]=calcrc(inspeedchar, 6)/256;
					inspeedchar[6]=calcrc(inspeedchar,6)%256;
				}

				
				{
					int i;
					for(i=0;i<4;i++)
					{zhighspeedchar[i]=zspeedchar[i];}
					zhighspeedchar[4]=vexmainmotorhigh/30/256;
					zhighspeedchar[5]=vexmainmotorhigh/30%256;
					zhighspeedchar[7]= calcrc(zhighspeedchar, 6)/256;
					zhighspeedchar[6]=calcrc(zhighspeedchar,6)%256;
				}
				{
					int i;
					for(i=0;i<4;i++)
					{zlowspeedchar[i]=zspeedchar[i];}
					zlowspeedchar[4]=vexmainmotorlow/30/256;
					zlowspeedchar[5]=vexmainmotorlow/30%256;
					zlowspeedchar[7]= calcrc(zlowspeedchar, 6)/256;
					zlowspeedchar[6]=calcrc(zlowspeedchar,6)%256;
				}*/
	}
     HWND h=::FindWindow(NULL,"屏幕键盘");

	if(h!=NULL)
	{
		::SendMessage(h,WM_CLOSE,0,0);
		SetDlgItemText(IDC_softkey2,"开键盘");
	}

}

void CVAFS2Dlg::OnStartCollection() 
{
	// TODO: Add your control notification handler code here

	imagephotoover=false;
	CameraPlay(camera1);

}

void CVAFS2Dlg::OnStartCollection2() 
{
	// TODO: Add your control notification handler code here

	imagephotoover2=false;
	CameraPlay(camera2);

}


void CVAFS2Dlg::DrawObject(CDC *pDC)
{
;


}



void CVAFS2Dlg::OnLoadModel() 
{
	// TODO: Add your control notification handler code here

	
		{
			Herror error_num;
	        
			try
			{ 
				read_shape_model(currentmodelname,&ShapeModel11);
				set_shape_model_param(ShapeModel11,"timeout",3500);
			
			}
		    catch (HException &except)
			 {
				error_num = except.err;
				AfxMessageBox("读模板11失败！");
				return;
			}
		}
		{
			Herror error_num;
	        
			try
			{ 
				read_shape_model(currentmodelname2,&ShapeModel12);
				set_shape_model_param(ShapeModel12,"timeout",3500);
			
			}
		    catch (HException &except)
			 {
				error_num = except.err;
				AfxMessageBox("读模板12失败！");
				return;
			}
		}
		if(repeat==1)
		{
			{
				Herror error_num;
				
				try
				{ 
					read_shape_model(currentmodelname3,&ShapeModel13);
					set_shape_model_param(ShapeModel13,"timeout",3500);
				
				}
				catch (HException &except)
				 {
					error_num = except.err;
					AfxMessageBox("读模板13失败！");
					return;
				}
			}
			{
				Herror error_num;
				
				try
				{ 
					read_shape_model(currentmodelname4,&ShapeModel14);
					set_shape_model_param(ShapeModel14,"timeout",3500);
				
				}
				catch (HException &except)
				 {
					error_num = except.err;
					AfxMessageBox("读模板14失败！");
					return;
				}
			}
		}
		{
			Herror error_num;
	        
			try
			{ 
				read_shape_model(currentmodelname21,&ShapeModel21);
				set_shape_model_param(ShapeModel21,"timeout",3500);
			}
		    catch (HException &except)
			 {
				error_num = except.err;
				AfxMessageBox("读模板21失败！");
				return;
			}
		}
		{
			Herror error_num;
	        
			try
			{ 
				read_shape_model(currentmodelname22,&ShapeModel22);
				set_shape_model_param(ShapeModel22,"timeout",3500);
			}
		    catch (HException &except)
			 {
				error_num = except.err;
				AfxMessageBox("读模板22失败！");
				return;
			}
		}
	

}

void CVAFS2Dlg::retranspoint()
				{




                    HTuple   Rows1, Cols1;
                    HTuple   Rows2, Cols2;
                    HTuple   HomMat2D,transkeyy, transkeyx;
                    Herror error_num;
 
  
                  Rows1[0] = remodel21y;
                  Rows1[1] = remodel22y;
                  Cols1[0] = remodel21x;
                  Cols1[1] = remodel22x;

				  Rows2[0] = recamera21centery;
                  Rows2[1] = recamera22centery;
                  Cols2[0] = recamera21centerx;
                  Cols2[1] = recamera22centerx;

			

                  try
				  {
					  HTuple transx,transy;
				     vector_to_rigid(Rows1, Cols1, Rows2, Cols2, &HomMat2D);
				     affine_trans_point_2d(HomMat2D, rekeypastey, rekeypastex, &transkeyy, &transkeyx);
				   float newtranx,newtrany,newkeyx,newkeyy;
					 newkeyx=rekeypastex*cos(photo2angle)+rekeypastey*sin(photo2angle);
					 newkeyy=rekeypastey*cos(photo2angle)-rekeypastex*sin(photo2angle);
					 newtranx=transkeyx[0].D()*cos(photo2angle)+transkeyy[0].D()*sin(photo2angle);
					 newtrany=transkeyy[0].D()*cos(photo2angle)-transkeyx[0].D()*sin(photo2angle);
					 
					 recamera2divx=(newtranx-newkeyx)*metalscale;
					recamera2divy=(newtrany-newkeyy)*metalyscale;

					reshowtranskeyx=transkeyx[0].D();
					reshowtranskeyy=transkeyy[0].D();

					set_color(m_Window2id,"red");

            	     
				  }
                  catch (HException &except)
				  {
					error_num = except.err;;
					photoproblem2=true;
					photoalreadyproblem2=true;
				    if(run==true)
					{display2();}
				
					overphoto2=1;
					metalverify=false;
					progress=0;
			
				  }


					 
  				}

void CVAFS2Dlg::transpoint()

			 	{




                    HTuple   Rows1, Cols1;
                    HTuple   Rows2, Cols2;
                    HTuple   HomMat2D,transkeyy, transkeyx;
                    Herror error_num;
 
  
                  Rows1[0] = model21y;
                  Rows1[1] = model22y;
                  Cols1[0] = model21x;
                  Cols1[1] = model22x;

				  Rows2[0] = camera21centery;
                  Rows2[1] = camera22centery;
                  Cols2[0] = camera21centerx;
                  Cols2[1] = camera22centerx;

			

                  try
				  {
					  HTuple transx,transy;
				     vector_to_rigid(Rows1, Cols1, Rows2, Cols2, &HomMat2D);
				     affine_trans_point_2d(HomMat2D, keypastey, keypastex, &transkeyy, &transkeyx);
				  
							 float newtranx,newtrany,newkeyx,newkeyy;
							 newkeyx=keypastex*cos(photo2angle)+keypastey*sin(photo2angle);
							 newkeyy=keypastey*cos(photo2angle)-keypastex*sin(photo2angle);
							 newtranx=transkeyx[0].D()*cos(photo2angle)+transkeyy[0].D()*sin(photo2angle);
							 newtrany=transkeyy[0].D()*cos(photo2angle)-transkeyx[0].D()*sin(photo2angle);
							 
							 camera2divx=(newtranx-newkeyx)*metalscale;
					camera2divy=(newtrany-newkeyy)*metalyscale;

					showtranskeyx=transkeyx[0].D();
					showtranskeyy=transkeyy[0].D();

					set_color(m_Window2id,"red");

            	     
				  }
                  catch (HException &except)
				  {
					error_num = except.err;;
					photoproblem2=true;
					photoalreadyproblem2=true;
				    if(run==true)
					{display2();}
				
					overphoto2=1;
					metalverify=false;
					progress=0;
			
				  }


					 
  				}


void CVAFS2Dlg::recalkeypaste()
			 {
                float newmodel11x,newmodel11y,newmodel12x,newmodel12y;
				newmodel11x=remodel11x*cos(photo1angle)+remodel11y*sin(photo1angle);
                newmodel11y=remodel11y*cos(photo1angle)-remodel11x*sin(photo1angle);
				newmodel12x=remodel12x*cos(photo1angle)+remodel12y*sin(photo1angle);
                newmodel12y=remodel12y*cos(photo1angle)-remodel12x*sin(photo1angle);
				float centerxtemp,centerytemp;
				
			   centerxtemp=(newmodel11x+newmodel12x)/2;
			   centerytemp=(newmodel11y+newmodel12y)/2;


			  float worldxtemp,worldytemp;
			  float worldx,worldy;
			  float xmove,ymove;
			  worldxtemp=centerxtemp*xscale+xdiv;
			  worldytemp=centerytemp*yscale+ydiv;
			  
			 
			  xmove=repastex-photox;
			  ymove=repastey-photoy;
			  worldx=worldxtemp+xmove;
			  worldy=worldytemp+ymove;
			  float pixworldx,pixworldy;
			  pixworldx=worldx-camera2xdiv;
			  pixworldy=worldy-camera2ydiv;
			  float pixxtemp,pixytemp;
			  pixxtemp=pixworldx/metalscale;
			  pixytemp=pixworldy/metalyscale;
			  
			  rekeypastex=pixxtemp*cos(-photo2angle)+pixytemp*sin(-photo2angle);
              rekeypastey=pixytemp*cos(-photo2angle)-pixxtemp*sin(-photo2angle);
		}
void CVAFS2Dlg::calkeypaste()
		{
                float newmodel11x,newmodel11y,newmodel12x,newmodel12y;
				newmodel11x=model11x*cos(photo1angle)+model11y*sin(photo1angle);
                newmodel11y=model11y*cos(photo1angle)-model11x*sin(photo1angle);
				newmodel12x=model12x*cos(photo1angle)+model12y*sin(photo1angle);
                newmodel12y=model12y*cos(photo1angle)-model12x*sin(photo1angle);
				float centerxtemp,centerytemp;
				
			   centerxtemp=(newmodel11x+newmodel12x)/2;
			   centerytemp=(newmodel11y+newmodel12y)/2;


			  float worldxtemp,worldytemp;
			  float worldx,worldy;
			  float xmove,ymove;
			  worldxtemp=centerxtemp*xscale+xdiv;
			  worldytemp=centerytemp*yscale+ydiv;
			  
			 
			  xmove=pastex-photox;
			  ymove=pastey-photoy;
			  worldx=worldxtemp+xmove;
			  worldy=worldytemp+ymove;
			  float pixworldx,pixworldy;
			  pixworldx=worldx-camera2xdiv;
			  pixworldy=worldy-camera2ydiv;
			  float pixxtemp,pixytemp;
			  pixxtemp=pixworldx/metalscale;
			  pixytemp=pixworldy/metalyscale;
			  
			  keypastex=pixxtemp*cos(-photo2angle)+pixytemp*sin(-photo2angle);
              keypastey=pixytemp*cos(-photo2angle)-pixxtemp*sin(-photo2angle);
		}

void CVAFS2Dlg::recalangle()
	   {
						  float anew,aold;
							float ysuby,xsubx;
			 float anewtemp;
			 float aoldtemp;
			 	ysuby=recamera22centery-recamera21centery;
				xsubx=recamera22centerx-recamera21centerx;
			 if(xsubx==0)
			 {anewtemp=3.141592653589793/2;}
			 if(xsubx!=0)
			 anewtemp=atan(ysuby/xsubx);
			 
			 ysuby=remodel22y-remodel21y;
			 xsubx=remodel22x-remodel21x;

			  if(xsubx==0)
			 {aoldtemp=3.141592653589793/2;}
			 if(xsubx!=0)
             aoldtemp=atan(ysuby/xsubx);//固定角度


			 if((anewtemp<0)&&(aoldtemp>0.8))
			 {anew=3.141592653589793+anewtemp;}
			 else
			 {anew=anewtemp;}


			 
			 
			 if((aoldtemp<0)&&(anewtemp>0.8))
			 {aold=aoldtemp+3.141592653589793;}
			 else
			 {aold=aoldtemp;}

			 
			recamera2divangle=anew-aold;
			 }
			


void CVAFS2Dlg::calangle()
{
		float anew,aold;
		float ysuby,xsubx;
		float anewtemp;
		float aoldtemp;
		ysuby=camera22centery-camera21centery;
		xsubx=camera22centerx-camera21centerx;
			 if(xsubx==0)
			 {anewtemp=3.141592653589793/2;}
			 if(xsubx!=0)
			 anewtemp=atan(ysuby/xsubx);
			 
			 ysuby=model22y-model21y;
			 xsubx=model22x-model21x;

			  if(xsubx==0)
			 {aoldtemp=3.141592653589793/2;}
			 if(xsubx!=0)
             aoldtemp=atan(ysuby/xsubx);//固定角度


			 if((anewtemp<0)&&(aoldtemp>0.8))
			 {anew=3.141592653589793+anewtemp;}
			 else
			 {anew=anewtemp;}


			 
			 
			 if((aoldtemp<0)&&(anewtemp>0.8))
			 {aold=aoldtemp+3.141592653589793;}
			 else
			 {aold=aoldtemp;}

			 
			camera2divangle=anew-aold;
}

Herror  CVAFS2Dlg::OnSearchObject2()
{
      
         

			HTuple		htRowCheck, htColumnCheck, htAngleCheck, htScore;
			HTuple		htRowCheck1, htColumnCheck1, htAngleCheck1, htScore1;
			Herror error_num;
			matchscore21=0;
			matchscore22=0;
			rematchscore21=0;
			rematchscore22=0;
			
			try
			{
			
				
		

			  set_draw(m_Window2id,"margin"); 
			  set_color( m_Window2id,"green");

			 {

			  Hobject model21roi;
			  Hobject roiimage21;
			   Hobject remodel21roi;
			  Hobject reroiimage21;
			  
	
			  //gen_rectangle1(&model21roi,model21y-model21halfx-searchrange2,model21x-model21halfy-searchrange2,remodel21y+model21halfx+searchrange2,remodel21x+model21halfy+searchrange2);
		       
			  gen_rectangle1(&model21roi,model21y-model21halfx-searchrange2,model21x-model21halfy-searchrange2,model21y+model21halfx+searchrange2,model21x+model21halfy+searchrange2);
			  if(repeat==1)
			  {gen_rectangle1(&remodel21roi,remodel21y-model21halfx-searchrange2,remodel21x-model21halfy-searchrange2,remodel21y+model21halfx+searchrange2,remodel21x+model21halfy+searchrange2);}

			  reduce_domain(Image2,model21roi,&roiimage21);
			  if(repeat==1)
			  {
			  reduce_domain(Image2,remodel21roi,&reroiimage21);
			  }
			  //if(metalverify==true)
			  //{roiimage21=Image2;}
			  	HTuple NumLevels,AngleStart,  AngleExtent, AngleStep,ScaleMin,  ScaleMax, ScaleStep;
		HTuple Metric;
		HTuple MinContrast;
		get_shape_model_params(ShapeModel21,&NumLevels,& AngleStart, & AngleExtent,& AngleStep,&ScaleMin, & ScaleMax,& ScaleStep, & Metric,& MinContrast);
	  
			
			  
            
            find_shape_model(roiimage21,ShapeModel21,AngleStart, AngleExtent,minscore21,1,0.5,"least_squares",
						 0,0.9,&htRowCheck,&htColumnCheck,&htAngleCheck,&htScore);
				camera21centery = htRowCheck[0].D();
				
					camera21centerx =htColumnCheck[0].D();
					
					matchscore21=htScore[0].D();
					
					angle21=htAngleCheck[0].D();
					if(repeat==1)
					{
					  find_shape_model(reroiimage21,ShapeModel21,-0.2, 0.4,minscore21,1,0.5,"least_squares",
						 0,0.9,&htRowCheck,&htColumnCheck,&htAngleCheck,&htScore);
				    recamera21centery = htRowCheck[0].D();
				
					recamera21centerx =htColumnCheck[0].D();
					
					rematchscore21=htScore[0].D();
					
					reangle21=htAngleCheck[0].D();
					}


			 }
			 //if(metalverify==false)
			 {
					Hobject model22roi;
					Hobject roiimage22;
					Hobject remodel22roi;
					Hobject reroiimage22;
			  
	
				//	gen_rectangle1(&model22roi,model22y-model22halfx-searchrange2,model22x-model22halfy-searchrange2,remodel22y+model22halfx+searchrange2,remodel22x+model22halfy+searchrange2);
				    gen_rectangle1(&model22roi,model22y-model22halfx-searchrange2,model22x-model22halfy-searchrange2,model22y+model22halfx+searchrange2,model22x+model22halfy+searchrange2);
				   if(repeat==1)
				   {gen_rectangle1(&remodel22roi,remodel22y-model22halfx-searchrange2,remodel22x-model22halfy-searchrange2,remodel22y+model22halfx+searchrange2,remodel22x+model22halfy+searchrange2);}

					reduce_domain(Image2,model22roi,&roiimage22);
					if(repeat==1)
					{reduce_domain(Image2,remodel22roi,&reroiimage22);}
				
				
						{
								HTuple NumLevels,AngleStart,  AngleExtent, AngleStep,ScaleMin,  ScaleMax, ScaleStep;
		HTuple Metric;
		HTuple MinContrast;
		get_shape_model_params(ShapeModel22,&NumLevels,& AngleStart, & AngleExtent,& AngleStep,&ScaleMin, & ScaleMax,& ScaleStep, & Metric,& MinContrast);
	  
							
						find_shape_model(roiimage22,ShapeModel22, AngleStart,  AngleExtent,minscore21,1,0.5,"least_squares",
						 0,0.9,&htRowCheck1,&htColumnCheck1,&htAngleCheck1,&htScore1);
						camera22centery=htRowCheck1[0].D();
						camera22centerx =htColumnCheck1[0].D();
						matchscore22=htScore1[0].D();
						angle22=htAngleCheck1[0].D();
						}

						if(repeat==1)
					
						{
								find_shape_model(reroiimage22,ShapeModel22,-0.2, 0.4,minscore21,1,0.5,"least_squares",
						 0,0.9,&htRowCheck1,&htColumnCheck1,&htAngleCheck1,&htScore1);
						
					recamera22centery=htRowCheck1[0].D();
				
					recamera22centerx =htColumnCheck1[0].D();
					rematchscore22=htScore1[0].D();
					
					reangle22=htAngleCheck1[0].D();
					 }
			 }
            

	

		   
           

            }
			catch (HException &except)
				{
					error_num = except.err;;
					photoproblem2=true;
					photoalreadyproblem2=true;
					if(run==true)
					{display2();}
				
					overphoto2=1;
					metalverify=false;
					progress=0;
				
				
						  			 	
					return 0; 
				}

		
			if(( matchscore21>=minscore21) &&(matchscore22>=minscore21)
				&&(( rematchscore21>=minscore21) &&(rematchscore22>=minscore21)||(repeat==0)))
				{
					  if(metalverify==false)
						  {
				
						     calangle();
						     calkeypaste();
							 transpoint();
							 
							if(repeat==1)
							{
							 recalangle();
							 recalkeypaste();
							 retranspoint();
							}

						  } 

				
	            photoproblem2=false;
				photoalreadyproblem2=false;
				overphoto2=1;
			
			}
		 	  m_list2.DeleteAllItems();
			  char s[100];
			  int i, item;

				if( matchscore21>0)
				{
					
			            for( i = 0; i < 1; i ++ ) 
						{
							item = m_list2.InsertItem(0, "" );
							sprintf( s, "%0.3f",matchscore21);
							m_list2.SetItemText( item, 0, s );
							sprintf( s, "%f", angle21*180/PI  );
							m_list2.SetItemText( item, 1, s );
							sprintf( s, "%f", camera21centerx );
							m_list2.SetItemText( item, 2, s );
							sprintf( s, "%f", camera21centery);
							m_list2.SetItemText( item, 3, s );
                          
						}

				}
				 if(matchscore22>0)
				 {
						  for( i = 0; i < 1; i ++ ) 
						{
							item = m_list2.InsertItem( 1, "" );
							sprintf( s, "%0.3f",matchscore22);
							m_list2.SetItemText( item, 0, s );
							sprintf( s, "%f", angle22*180/PI  );
							m_list2.SetItemText( item, 1, s );
							sprintf( s, "%f", camera22centerx );
							m_list2.SetItemText( item, 2, s );
							sprintf( s, "%f", camera22centery);
							m_list2.SetItemText( item, 3, s );
                          
						}
						
				 }
				 if(rematchscore21>0)	 
				 {
						for( i = 0; i < 1; i ++ ) 
						{
							item = m_list2.InsertItem(2, "" );
							sprintf( s, "%0.3f",rematchscore21);
							m_list2.SetItemText( item, 0, s );
							sprintf( s, "%f", reangle21*180/PI  );
							m_list2.SetItemText( item, 1, s );
							sprintf( s, "%f", recamera21centerx );
							m_list2.SetItemText( item, 2, s );
							sprintf( s, "%f", recamera21centery);
							m_list2.SetItemText( item, 3, s );
                          
						}
				 }
				  if(rematchscore22>0)
				  {
						  for( i = 0; i < 1; i ++ ) 
						{
							item = m_list2.InsertItem( 3, "" );
							sprintf( s, "%0.3f",rematchscore22);
							m_list2.SetItemText( item, 0, s );
							sprintf( s, "%f", reangle22*180/PI  );
							m_list2.SetItemText( item, 1, s );
							sprintf( s, "%f", recamera22centerx );
							m_list2.SetItemText( item, 2, s );
							sprintf( s, "%f", recamera22centery);
							m_list2.SetItemText( item, 3, s );
                          
						}

				  }
						
		


		if((matchscore21<minscore21)||(matchscore22<minscore21)||
			(((rematchscore21<minscore21)||(rematchscore22<minscore21))&&(repeat==1)))
			{
				//MessageBox( "搜索不到相匹配的对象！" );
				photoproblem2=true;
			    metalverify=false;
					photoalreadyproblem2=true;
				if(run==true)
				{display2();}
				
				progress=0;
			
			    overphoto2=1;
			}
	
   
    
       


}



void CVAFS2Dlg::OnSearchObject3()
{
   
	
    m_list3.DeleteAllItems();
	if( 1 ) 
	{
		char s[100];
		int i, item;
		for( i = 0; i < 1; i ++ ) 
		{
			item = m_list3.InsertItem( i, "" );
		//	sprintf( s, "%d", i + 1 );
		//	m_list1.SetItemText( item, 0, s );
			sprintf( s, "%0.3f", matchscore  );
			m_list3.SetItemText( item, 0, s );
		//	sprintf( s, "%f", pMatchArray[i].Angle );
		//	m_list1.SetItemText( item, 1, s );
		//	sprintf( s, "%0.2f", pMatchArray[i].Scale );
		//	m_list1.SetItemText( item, 3, s );
		//	sprintf( s, "%f", pMatchArray[i].CenterX );
			m_list3.SetItemText( item, 1, s );
		//	sprintf( s, "%f", pMatchArray[i].CenterY);
			m_list3.SetItemText( item, 2, s );
		}
	
		overphoto3=1;

		
	} 
	else
	{
	//MessageBox( "搜索不到相匹配的对象！" );
	
	  overphoto3=1;
	
	
	}


}

void CVAFS2Dlg::OnSearchObject4()
{
		// TODO: Add your control notification handler code here

	
    m_list4.DeleteAllItems();
	if( 1 ) 
	{
		char s[100];
		int i, item;
		for( i = 0; i < 1; i ++ ) 
		{
			item = m_list4.InsertItem( i, "" );
		//	sprintf( s, "%d", i + 1 );
		//	m_list1.SetItemText( item, 0, s );
			sprintf( s, "%0.3f", matchscore  );
			m_list4.SetItemText( item, 0, s );
		//	sprintf( s, "%f", pMatchArray[i].Angle );
		//	m_list1.SetItemText( item, 1, s );
		//	sprintf( s, "%0.2f", pMatchArray[i].Scale );
		//	m_list1.SetItemText( item, 3, s );
			//sprintf( s, "%f", pMatchArray[i].CenterX );
			m_list4.SetItemText( item, 1, s );
			//sprintf( s, "%f", pMatchArray[i].CenterY);
			m_list4.SetItemText( item, 2, s );
		}

	
		overphoto4=1;

		
	} 
	else
	{
	//MessageBox( "搜索不到相匹配的对象！" );
	
	  overphoto4=1;
	
	
	}



}


Herror  CVAFS2Dlg::OnSearchObject()
{
	
            matchscore=0;
			matchscore2=0;
			rematchscore=0;
			rematchscore2=0;
			centerx=0;
			centery=0;
			centerx2=0;
			centery2=0;
			

         	
			HTuple		htRowCheck, htColumnCheck, htAngleCheck, htScore;
			HTuple		htRowCheck1, htColumnCheck1, htAngleCheck1, htScore1;
			HTuple	    Transformation;
		//	Hobject		ContourTrans,m_ShapeModelContours; 
			Herror error_num;
			
		
			try
			{
	

             
			 {
			  Hobject model11roi;
			  Hobject roiimage11;
			   Hobject remodel11roi;
			  Hobject reroiimage11;
		
			  //gen_rectangle1(&model11roi,remodel11y-model11halfx-searchrange,remodel11x-model11halfy-searchrange,model11y+model11halfx+searchrange,model11x+model11halfy+searchrange);
			 if(repeat==1)
			 {
			  gen_rectangle1(&remodel11roi,remodel11y-model13halfx-searchrange,remodel11x-model13halfy-searchrange,remodel11y+model13halfx+searchrange,remodel11x+model13halfy+searchrange);
		       reduce_domain(Image1,remodel11roi,&reroiimage11);
			 }
			  gen_rectangle1(&model11roi,model11y-model11halfx-searchrange,model11x-model11halfy-searchrange,model11y+model11halfx+searchrange,model11x+model11halfy+searchrange);
               
			   reduce_domain(Image1,model11roi,&roiimage11);
			   

			  if(photoverify==true)
			  {roiimage11=Image1;}


		      set_shape_model_param(ShapeModel11,"timeout",4000);
			
         	  find_shape_model(roiimage11,ShapeModel11,-0.1, 0.2,minscore11,1,0.5,"least_squares",
						 0,0.9,&htRowCheck,&htColumnCheck,&htAngleCheck,&htScore);
			  	centerytemp = htRowCheck[0].D();
						centerxtemp =htColumnCheck[0].D();

							matchscore=htScore[0].D();
							angle=htAngleCheck[0].D();
							if(repeat==1)
							{
								set_shape_model_param(ShapeModel13,"timeout",3000);
							  find_shape_model(reroiimage11,ShapeModel13,-0.1, 0.2,minscore11,1,0.5,"least_squares",
						 0,0.9,&htRowCheck,&htColumnCheck,&htAngleCheck,&htScore);
			  	recenterytemp = htRowCheck[0].D();
						recenterxtemp =htColumnCheck[0].D();
							rematchscore=htScore[0].D();
								reangle=htAngleCheck[0].D();
							}



			 }
           
           if(photoverify==false)
			{

               Hobject model12roi;
			   Hobject roiimage12;
			     Hobject remodel12roi;
			   Hobject reroiimage12;
			  // gen_rectangle1(&model12roi,remodel12y-model12halfx-searchrange,remodel12x-model12halfy-searchrange,model12y+model12halfx+searchrange,model12x+model12halfy+searchrange);
			   
			  	 gen_rectangle1(&model12roi,model12y-model12halfx-searchrange,model12x-model12halfy-searchrange,model12y+model12halfx+searchrange,model12x+model12halfy+searchrange);
					reduce_domain(Image1,model12roi,&roiimage12);
					if(repeat==1)
					{
                 	gen_rectangle1(&remodel12roi,remodel12y-model14halfx-searchrange,remodel12x-model14halfy-searchrange,remodel12y+model14halfx+searchrange,remodel12x+model14halfy+searchrange);
			  
			         reduce_domain(Image1,remodel12roi,&reroiimage12);
					}
			   set_shape_model_param(ShapeModel12,"timeout",3000);

			   find_shape_model(roiimage12,ShapeModel12,-0.1, 0.2,minscore11,1,0.5,"least_squares",
						 0,0.9,&htRowCheck1,&htColumnCheck1,&htAngleCheck1,&htScore1);
			   	centery2temp = htRowCheck1[0].D();
							centerx2temp =htColumnCheck1[0].D();
								matchscore2=htScore1[0].D();
								angle2=htAngleCheck1[0].D();

				if(repeat==1)
				{
						set_shape_model_param(ShapeModel14,"timeout",3000);	
							  find_shape_model(reroiimage12,ShapeModel14,-0.1, 0.2,minscore11,1,0.5,"least_squares",
						 0,0.9,&htRowCheck1,&htColumnCheck1,&htAngleCheck1,&htScore1);
			   	recentery2temp = htRowCheck1[0].D();
							recenterx2temp =htColumnCheck1[0].D();
							rematchscore2=htScore1[0].D();
								reangle2=htAngleCheck1[0].D();
				}
   			  
   			  
	
			}
        	if(photoverify==true)
			{
				if(htScore[0].D()>0)
				{
				centery= htRowCheck[0].D();
				centerx =htColumnCheck[0].D();
				matchscore=htScore[0].D();
					centerytemp = htRowCheck[0].D();
						centerxtemp =htColumnCheck[0].D();
						angle=htAngleCheck[0].D();
				}
				else
				{
						MessageBox("标定失败");
						photoverify=false;
						//centery= htRowCheck[1].D();
						//centerx =htColumnCheck[1].D();
						//matchscore=htScore[1].D();
						//centerytemp = htRowCheck[1].D();
						//centerxtemp =htColumnCheck[1].D();
						//angle=htAngleCheck[1].D();
				}
			}


	        if(photoverify==false)
				{

				   // if(htColumnCheck[0].D()>htColumnCheck[1].D())
					//{
					//	centerytemp = htRowCheck[0].D();
					//	centerxtemp =htColumnCheck[0].D();
					//	recenterytemp = htRowCheck[1].D();
					//	recenterxtemp =htColumnCheck[1].D();
				
						centerx=centerxtemp*cos(photo1angle)+centerytemp*sin(photo1angle);
		                centery=centerytemp*cos(photo1angle)-centerxtemp*sin(photo1angle);
						recenterx=recenterxtemp*cos(photo1angle)+recenterytemp*sin(photo1angle);
				        recentery=recenterytemp*cos(photo1angle)-recenterxtemp*sin(photo1angle);
					
						//matchscore=htScore[0].D();
						//rematchscore=htScore[0].D();
						
						//angle=htAngleCheck[0].D();
					//	reangle=htAngleCheck[1].D();
				/*	}
					
				  if(htColumnCheck[0].D()<htColumnCheck[1].D())
					{
						centerytemp = htRowCheck[1].D();
						centerxtemp =htColumnCheck[1].D();
						recenterytemp = htRowCheck[0].D();
						recenterxtemp =htColumnCheck[0].D();
				
						centerx=centerxtemp*cos(photo1angle)+centerytemp*sin(photo1angle);
					    centery=centerytemp*cos(photo1angle)-centerxtemp*sin(photo1angle);
						recenterx=recenterxtemp*cos(photo1angle)+recenterytemp*sin(photo1angle);
		                recentery=recenterytemp*cos(photo1angle)-recenterxtemp*sin(photo1angle);
			
					
						matchscore=htScore[1].D();
						rematchscore=htScore[0].D();
					
						angle=htAngleCheck[1].D();
						reangle=htAngleCheck[0].D();
					}*/
				

			}
		
				
				
					
			if(photoverify==false)
					{
					//	if(htColumnCheck1[0].D()>htColumnCheck1[1].D())
					//	{
							//matchscore2=htScore1[0].D();
							//rematchscore2=htScore[0].D();
                    
						
							//recentery2temp = htRowCheck1[1].D();
							//recenterx2temp =htColumnCheck1[1].D();
							centerx2=centerx2temp*cos(photo1angle)+centery2temp*sin(photo1angle);
				            centery2=centery2temp*cos(photo1angle)-centerx2temp*sin(photo1angle);
							recenterx2=recenterx2temp*cos(photo1angle)+recentery2temp*sin(photo1angle);
		                    recentery2=recentery2temp*cos(photo1angle)-recenterx2temp*sin(photo1angle);

		                   //angle2=htAngleCheck1[0].D();
							 //reangle2=htAngleCheck1[1].D();
					/*	}
			   	        if(htColumnCheck1[0].D()<htColumnCheck1[1].D())
						{
							matchscore2=htScore1[1].D();
							rematchscore2=htScore1[0].D();
							centery2temp = htRowCheck1[1].D();
							centerx2temp =htColumnCheck1[1].D();
							recentery2temp = htRowCheck1[0].D();
							recenterx2temp =htColumnCheck1[0].D();
							centerx2=centerx2temp*cos(photo1angle)+centery2temp*sin(photo1angle);
				            centery2=centery2temp*cos(photo1angle)-centerx2temp*sin(photo1angle);
							recenterx2=recenterx2temp*cos(photo1angle)+recentery2temp*sin(photo1angle);
							recentery2=recentery2temp*cos(photo1angle)-recenterx2temp*sin(photo1angle);
							angle2=htAngleCheck1[1].D();
							reangle2=htAngleCheck1[0].D();
						}*/


					}

			
	


        
	

			}

			catch (HException &except)
				{
					error_num = except.err;
					photoproblem=true;
					photoalreadyerror=true;
					photoverify=false;
					progress=0;
					overphoto=1;
					display();
				
					//AfxMessageBox( "查找失败！" );
						  			 	
					return 0; 
				}
			
 
		 
			m_list1.DeleteAllItems();
			if(( matchscore>0))
				{

			
					char s[100];
					int i, item;
					for( i = 0; i < 1; i ++ ) 
						{
							item = m_list1.InsertItem(0, "" );
						
							sprintf( s, "%0.3f", matchscore );
							m_list1.SetItemText( item, 0, s );
								sprintf( s, "%f", angle*180/PI );
								m_list1.SetItemText( item, 1, s );
						
							sprintf( s, "%f", centerx );
							m_list1.SetItemText( item, 2, s );
							sprintf( s, "%f", centery);
							m_list1.SetItemText( item, 3, s );
                            
					
						}
	
			} 

				if(( matchscore2>0 ))
				{



					char s[100];
					int i, item;
					for( i = 0; i < 1; i ++ ) 
						{
							item = m_list1.InsertItem( 1, "" );
					
							sprintf( s, "%0.3f", matchscore2 );
							m_list1.SetItemText( item, 0, s );
								sprintf( s, "%f", angle2*180/PI );
								m_list1.SetItemText( item, 1, s );
						
							sprintf( s, "%f", centerx2 );
							m_list1.SetItemText( item, 2, s );
							sprintf( s, "%f", centery2);
							m_list1.SetItemText( item, 3, s );
                       
						}
		

		
			} 
			if(( rematchscore>0 ))
				{

			
					char s[100];
					int i, item;
					for( i = 0; i < 1; i ++ ) 
						{
							item = m_list1.InsertItem(2, "" );
						
							sprintf( s, "%0.3f",rematchscore );
							m_list1.SetItemText( item, 0, s );
								sprintf( s, "%f", reangle*180/PI );
								m_list1.SetItemText( item, 1, s );
						
							sprintf( s, "%f", recenterx );
							m_list1.SetItemText( item, 2, s );
							sprintf( s, "%f", recentery);
							m_list1.SetItemText( item, 3, s );
                            
					
						}
			

			} 

				if(( rematchscore2>0))
				{



					char s[100];
					int i, item;
					for( i = 0; i < 1; i ++ ) 
						{
							item = m_list1.InsertItem( 3, "" );
					
							sprintf( s, "%0.3f", rematchscore2 );
							m_list1.SetItemText( item, 0, s );
								sprintf( s, "%f", reangle2*180/PI );
								m_list1.SetItemText( item, 1, s );
						
							sprintf( s, "%f", recenterx2 );
							m_list1.SetItemText( item, 2, s );
							sprintf( s, "%f", recentery2);
							m_list1.SetItemText( item, 3, s );
                       
						}
			

			} 
		if((matchscore>=minscore11)&&(((matchscore2>=minscore11)
			&&(rematchscore>=minscore11)&&(rematchscore2>=minscore11))||(photoverify==true)||(repeat==0)))
			{
				//MessageBox( "搜索不到相匹配的对象！" );
			
			 photoproblem=false;
				photoalreadyerror=false;
				overphoto=1;
			   
			}
	       else
		   {	
			   photoproblem=true;
				photoalreadyerror=true;
		       photoverify=false;
				progress=0;
				display();
				
		   }

		return 0;

		
	
}

void CVAFS2Dlg::display2()
{

	
			Herror error_num;
			
			try
			{
			
				
				
			if(zoomfactor!=1)
				{
					Hobject imagezoom;
					zoom_image_factor(Image2,&imagezoom,zoomfactor,zoomfactor,"constant");

                   set_part(m_Window2id,zoomupdown,zoomleftright,camera2width+zoomupdown,camera2height+zoomleftright );
				   disp_obj(imagezoom,m_Window2id);
				     set_color(m_Window2id,"green");

                	//disp_cross(m_Window2id,keypastey,keypastex,80,0);
				}

			 else
			 {
				 disp_obj(Image2,m_Window2id);
				  set_color(m_Window2id,"green");

            	//disp_cross(m_Window2id,keypastey,keypastex,80,0);
			 }

			  set_draw(m_Window2id,"margin"); 
			  set_color( m_Window2id,"green");
			  		 {

			  Hobject model21roi;
			  Hobject roiimage21;
			  
	
			  gen_rectangle1(&model21roi,model21y-model21halfx-searchrange2,model21x-model21halfy-searchrange2,model21y+model21halfx+searchrange2,model21x+model21halfy+searchrange2);
		       disp_obj(model21roi,m_Window2id);
			  gen_rectangle1(&model21roi,remodel21y-model21halfx-searchrange2,remodel21x-model21halfy-searchrange2,remodel21y+model21halfx+searchrange2,remodel21x+model21halfy+searchrange2);
 
			  disp_obj(model21roi,m_Window2id);
			 

			 }
			 //if(metalverify==false)
			 {
					Hobject model22roi;
					Hobject roiimage22;
			  
	
					gen_rectangle1(&model22roi,model22y-model22halfx-searchrange2,model22x-model22halfy-searchrange2,model22y+model22halfx+searchrange2,model22x+model22halfy+searchrange2);
					disp_obj(model22roi,m_Window2id);
						gen_rectangle1(&model22roi,remodel22y-model22halfx-searchrange2,remodel22x-model22halfy-searchrange2,remodel22y+model22halfx+searchrange2,remodel22x+model22halfy+searchrange2);
					disp_obj(model22roi,m_Window2id);
			 }

			
               
			   {

						HTuple	Transformation;
						Hobject		ContourTrans,m_ShapeModelContours;
						set_color(m_Window2id,"red");
						get_shape_model_contours(&m_ShapeModelContours,ShapeModel22,1);
						vector_angle_to_rigid(0,0,0,camera22centery ,camera22centerx ,angle22,&Transformation);

						

						affine_trans_contour_xld(m_ShapeModelContours,&ContourTrans, Transformation);
					

						disp_obj(ContourTrans,m_Window2id);
												vector_angle_to_rigid(0,0,0,recamera22centery ,recamera22centerx ,reangle22,&Transformation);

						

						affine_trans_contour_xld(m_ShapeModelContours,&ContourTrans, Transformation);
					

						disp_obj(ContourTrans,m_Window2id);
			   }
			  
			   {
				         HTuple	Transformation;
						 Hobject		ContourTrans,m_ShapeModelContours; 
						 	set_color(m_Window2id,"red"); 
							get_shape_model_contours(&m_ShapeModelContours,ShapeModel21,1);
							vector_angle_to_rigid(0,0,0,camera21centery,camera21centerx ,angle21,&Transformation);

			           

						affine_trans_contour_xld(m_ShapeModelContours,&ContourTrans,Transformation);

					
						disp_obj(ContourTrans,m_Window2id);
						if(repeat==1)
						{
						vector_angle_to_rigid(0,0,0,recamera21centery,recamera21centerx ,reangle21,&Transformation);

			           

						affine_trans_contour_xld(m_ShapeModelContours,&ContourTrans,Transformation);

					
						disp_obj(ContourTrans,m_Window2id);
						}
			   }


			   		set_color(m_Window2id,"red");

            	     disp_cross(m_Window2id,showtranskeyy,showtranskeyx,80,0);
					 disp_cross(m_Window2id,camera22centery,camera22centerx,40,0);
					disp_cross(m_Window2id,camera21centery,camera21centerx,40,0);
					disp_cross(m_Window2id,reshowtranskeyy,reshowtranskeyx,80,0);
					 disp_cross(m_Window2id,recamera22centery,recamera22centerx,40,0);
					disp_cross(m_Window2id,recamera21centery,recamera21centerx,40,0);
					disp_line(m_Window2id,camera22centery,camera22centerx,camera21centery,camera21centerx);
					disp_line(m_Window2id,recamera22centery,recamera22centerx,recamera21centery,recamera21centerx);

				set_color(m_Window2id,"green");
				disp_cross(m_Window2id,keypastey,keypastex,80,0);


				disp_line(m_Window2id,model21y,model21x,model22y,model22x);
				disp_cross(m_Window2id,model21y,model21x,40,0);
				disp_cross(m_Window2id,model22y,model22x,40,0);	
				disp_cross(m_Window2id,rekeypastey,rekeypastex,80,0);
					disp_line(m_Window2id,remodel21y,remodel21x,remodel22y,remodel22x);
				disp_cross(m_Window2id,remodel21y,remodel21x,40,0);
				disp_cross(m_Window2id,remodel22y,remodel22x,40,0);	
		
           

            }
			catch (HException &except)
				{
					error_num = except.err;;

				}
		 



}



void CVAFS2Dlg::display()
{
			HTuple	    Transformation;
			Hobject		ContourTrans,m_ShapeModelContours; 
			Herror error_num;
			 set_draw(m_Windowid,"margin"); 
			 set_color(m_Windowid,"green");
		
			try
			{
			
				if(zoomfactor!=1)
				{
					Hobject imagezoom;
					zoom_image_factor(Image1,&imagezoom,zoomfactor,zoomfactor,"constant");

                    set_part(m_Windowid,zoomupdown,zoomleftright,camera1width+zoomupdown,camera1height+zoomleftright );
				    
					disp_obj(imagezoom,m_Windowid);
				}

			 else	
			 disp_obj(Image1,m_Windowid);
		

             //if(modalselect==0)
			 {
			  Hobject model11roi;
			  Hobject remodel11roi;
              if(repeat==1)
			  {
			  gen_rectangle1(&model11roi,remodel11y-model13halfx-searchrange,remodel11x-model13halfy-searchrange,remodel11y+model13halfx+searchrange,remodel11x+model13halfy+searchrange);
			
			  disp_obj(model11roi,m_Windowid);//model11y-model11halfx-100,model11x-model11halfy-100,model11y+model11halfx+100,model11x+model11halfy+100);
			  }
			  gen_rectangle1(&model11roi,model11y-model11halfx-searchrange,model11x-model11halfy-searchrange,model11y+model11halfx+searchrange,model11x+model11halfy+searchrange);
			
			  disp_obj(model11roi,m_Windowid);          
			 }
           
            if((photoverify==false))//&&(modalselect==1))
			{

               Hobject model12roi;
			  if(repeat==1)
			  {
			   gen_rectangle1(&model12roi,remodel12y-model14halfx-searchrange,remodel12x-model14halfy-searchrange,remodel12y+model14halfx+searchrange,remodel12x+model14halfy+searchrange);
	           disp_obj(model12roi,m_Windowid);
			  }
			   		   gen_rectangle1(&model12roi,model12y-model12halfx-searchrange,model12x-model12halfy-searchrange,model12y+model12halfx+searchrange,model12x+model12halfy+searchrange);
	           disp_obj(model12roi,m_Windowid);
			}
 
	if(( matchscore>0 ))
        
			{
		    set_color(m_Windowid,"red");
        	

			get_shape_model_contours(&m_ShapeModelContours,ShapeModel11,1);
			vector_angle_to_rigid(0,0,0,centerytemp,centerxtemp,angle,&Transformation);
		    affine_trans_contour_xld(m_ShapeModelContours,&ContourTrans ,Transformation);
			
			disp_obj(ContourTrans,m_Windowid);
			if(repeat==1)
			{
				get_shape_model_contours(&m_ShapeModelContours,ShapeModel13,1);
			vector_angle_to_rigid(0,0,0,recenterytemp,recenterxtemp,reangle,&Transformation);
		    affine_trans_contour_xld(m_ShapeModelContours,&ContourTrans ,Transformation);			
			disp_obj(ContourTrans,m_Windowid);
			}
			}
			if((photoverify==false)&&( matchscore2>0 ))//&&(modalselect==1))
			{

			
		    set_color(m_Windowid,"red");
			get_shape_model_contours(&m_ShapeModelContours,ShapeModel12,1);
			vector_angle_to_rigid(0,0,0,centery2temp,centerx2temp,angle2,&Transformation);

			

			 affine_trans_contour_xld(m_ShapeModelContours,&ContourTrans,Transformation);
			disp_obj(ContourTrans,m_Windowid);
			if(repeat==1)
			{
				get_shape_model_contours(&m_ShapeModelContours,ShapeModel14,1);

						vector_angle_to_rigid(0,0,0,recentery2temp,recenterx2temp,reangle2,&Transformation);

				 affine_trans_contour_xld(m_ShapeModelContours,&ContourTrans,Transformation);
			disp_obj(ContourTrans,m_Windowid);
			}
			
		
			}


			
 
		 
		
			if(( matchscore>0 ))//&&(modalselect==0))
				{


                    set_color(m_Windowid,"green");
                    disp_cross(m_Windowid,centerytemp,centerxtemp,40,0);
					 disp_cross(m_Windowid,recenterytemp,recenterxtemp,40,0);

				
		
			} 
		
				if(( matchscore2>0 ))//&&(modalselect==1))
				{

			
                    set_color(m_Windowid,"green");
                    disp_cross(m_Windowid,centery2temp,centerx2temp,40,0);
					 disp_cross(m_Windowid,recentery2temp,recenterx2temp,40,0);

		
			} 

				
			}

			catch (HException &except)
				{
					error_num = except.err;
							  			 	
				
				}


}

void CVAFS2Dlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
switch(nIDEvent)
{
case 1:
{

//////////////////////////////////////////////////////////////////////////////////
	if(positionxp==true)
	{
		
				//if( !UpdateData( TRUE ) )
				//{return CDialog::OnWndMsg(message, wParam, lParam, pResult);}
		        if(positiontimes<20)
				{
					positiontimes++;
				}
				if(positiontimes>=20)
				{
					if(	pastex<20000)
					{
					    m_pastex=m_pastex+1;
						pastex=m_pastex;
						UpdateData( false );
					}


						
				}
	}
	if(positionxm==true)
	{
		        if(positiontimes<20)
				{
					positiontimes++;
				}
				if(positiontimes>=20)
				{
					if(	pastex>=0)
					{
		            m_pastex=m_pastex-1;
						pastex=m_pastex;
						UpdateData( false );
					}
				}
	}

	if(positionyp==true)
	{
		
				//if( !UpdateData( TRUE ) )
				//{return CDialog::OnWndMsg(message, wParam, lParam, pResult);}
		        if(positiontimes<20)
				{
					positiontimes++;
				}
				if(positiontimes>=20)
				{
					if(	pastey<48000)
					{
					m_pastey=m_pastey+1;
						pastey=m_pastey;
						UpdateData( false );
					}
				}
	}
	if(positionym==true)
	{
		        if(positiontimes<20)
				{
					positiontimes++;
				}
				if(positiontimes>=20)
				{
					if(	pastey>=0)
					{
					m_pastey=m_pastey-1;
						pastey=m_pastey;
						UpdateData( false );
					}
				}
	}

	if(positionrp==true)
	{
		
				//if( !UpdateData( TRUE ) )
				//{return CDialog::OnWndMsg(message, wParam, lParam, pResult);}
		        if(positiontimes<20)
				{
					positiontimes++;
				}
				if(positiontimes>=20)
				{
					m_pasteangle=m_pasteangle+1;
						pasteangle=m_pasteangle;
						UpdateData( false );
				}
	}
	if(positionrm==true)
	{
		        if(positiontimes<20)
				{
					positiontimes++;
				}
				if(positiontimes>=20)
				{
					m_pasteangle=m_pasteangle-1;
						pasteangle=m_pasteangle;
						UpdateData( false );
				}
	}


	if(repositionxp==true)
	{
		
				//if( !UpdateData( TRUE ) )
				//{return CDialog::OnWndMsg(message, wParam, lParam, pResult);}
		        if(positiontimes<20)
				{
					positiontimes++;
				}
				if(positiontimes>=20)
				{
					if(repastex<20000)
					{
					    m_repastex=m_repastex+1;
						repastex=m_repastex;
						UpdateData( false );
					}


						
				}
	}
	if(repositionxm==true)
	{
		        if(positiontimes<20)
				{
					positiontimes++;
				}
				if(positiontimes>=20)
				{
					if(repastex>=0)
					{
		            m_repastex=m_repastex-1;
						repastex=m_repastex;
						UpdateData( false );
					}
				}
	}

	if(repositionyp==true)
	{
		
				//if( !UpdateData( TRUE ) )
				//{return CDialog::OnWndMsg(message, wParam, lParam, pResult);}
		        if(positiontimes<20)
				{
					positiontimes++;
				}
				if(positiontimes>=20)
				{
					if(repastey<48000)
					{
					m_repastey=m_repastey+1;
						repastey=m_repastey;
						UpdateData( false );
					}
				}
	}
	if(repositionym==true)
	{
		        if(positiontimes<20)
				{
					positiontimes++;
				}
				if(positiontimes>=20)
				{
					if(repastey>=0)
					{
					m_repastey=m_repastey-1;
						repastey=m_repastey;
						UpdateData( false );
					}
				}
	}

	if(repositionrp==true)
	{
		
				//if( !UpdateData( TRUE ) )
				//{return CDialog::OnWndMsg(message, wParam, lParam, pResult);}
		        if(positiontimes<20)
				{
					positiontimes++;
				}
				if(positiontimes>=20)
				{
					m_repasteangle=m_repasteangle+1;
						repasteangle=m_repasteangle;
						UpdateData( false );
				}
	}
	if(repositionrm==true)
	{
		        if(positiontimes<20)
				{
					positiontimes++;
				}
				if(positiontimes>=20)
				{
					m_repasteangle=m_repasteangle-1;
						repasteangle=m_repasteangle;
						UpdateData( false );
				}
	}
////////////////////////////////////////////////////////////////////////


  if(d1000_in_bit(jogin)==0)
  {
	  //pastecounter=0;
	  //castcounter=0;
	  totalcounter=0;
  }
	m_pastecounter=pastecounter;
	m_castcounter=castcounter;
	m_totalcounter=totalcounter;
	SYSTEMTIME systime;
	::GetLocalTime(&systime);
	m_hour=systime.wHour;
	m_minute=systime.wMinute;
	m_second=systime.wSecond;
//////////////////////////////////////////////    
/*	if(d1000_in_bit(upstartin)==0)
	{CheckDlgButton( IDC_upstart, 1 );}
	else
	{CheckDlgButton( IDC_upstart, 0 );}
	if(d1000_in_bit(downfinishedin)==0)
	{CheckDlgButton( IDC_downfinished, 1 );}
	else
	{CheckDlgButton( IDC_downfinished, 0 );}*/
	if(d1000_in_bit(upstartin)==0)
	{MainIOdeal(IDC_upstart,0);}
	else
	{MainIOdeal(IDC_upstart,1);}
	if(d1000_in_bit(downfinishedin)==0)
	{MainIOdeal(IDC_downfinished,0);}
	else
	{MainIOdeal(IDC_downfinished,1);}
    
  
 //////////////////////////////////////////////

	 UpdateData( false );
    
	

	 if(((bigproblem==true)||(smallproblem==true))&&(d1000_in_bit(reset)==0))
	 {OnReset() ;}
	 if(((bigproblem==false)&&(smallproblem==false))&&(d1000_in_bit(reset)==0))
	 {OnStart() ;}


	 if(d1000_in_bit(stopin)==0)
	 {
		 	run=false;
			stop=true;
	 }



    if(reloadmod==true)
	{
		reloadmod=false;
		InitDeviceFunction();
		m_bStartCapture=FALSE;
//		SetFeature(m_hDevice,BRIGHTNESS, bright, bright);
	

	
		m_bStartCapture=FALSE;


		OnLoadModel(); 


	}
	
	//相机标定

if(cyclephoto==true)
	{
		if(startphoto==0)
		{
		 
        startphoto=1;
		 OnStartCollection();
		
		}
		if(overphoto==1)
		{

			overphoto=0;
			startphoto=0;
	
		}
		

	}

if(cyclephoto2==true)
	{
		if(startphoto2==0)
		{
		 
        startphoto2=1;
		 OnStartCollection2();
		
		}
		if(overphoto2==1)
		{

			overphoto2=0;
			startphoto2=0;
	
		}
		

	}

  if((imagephotoover==true)&&((cyclephoto==true)||(photoverify==true)))//||(run==true)||(mainstepp==true)))
   {
	
	 
	 
	 OnSearchObject();
	 display();
	 imagephotoover=false;
	
	 
   }


 


	if((imagephotoover2==true)&&((cyclephoto2==true)||(metalverify==true)||(run==true)||(fixturestepp==true)))//&&((cyclephoto2==true)||(run==true)||(fixturestepp==true)))
   {
	 
	 
	   
	 OnSearchObject2();
	 if(run==false)
	 { display2();}
     imagephotoover2=false;
	 
   }

	if(photoverify==true)
	{
        
		
		if(progress==0)
		{

		startphoto=0;
		overphoto=0;
		OnStartCollection(); 
		progress=progress+1;
		}

        if((overphoto==1)&&(progress==1))
			{
			  firstcamerax=centerx;
			  firstcameray=centery;
			  firstrobotx=d1000_get_command_pos(0);
			  firstroboty=d1000_get_command_pos(1);
			  progress=progress+1;
			  servostarted=0;
			}
	     if(progress==2)
		 {
			 d1000_start_t_move( 0,2000, 0, vexx, 0.3);
			 d1000_start_t_move( 1,2000, 0, vexy, 0.3);
			 progress=progress+1;
			 tempa=0;
			 tempb=0;
			 servostarted=1;
		 }
				
			
		 tempa=d1000_check_done(0);
		 tempb=d1000_check_done(1);


		
	    if((tempa==1)&&(tempb==1)&&(progress==3)&&(servostarted==1))
		{
			Sleep(800);
			progress=progress+1;
			servostarted=0;
		}
		if(progress==4)
		{

		startphoto=0;
		overphoto=0;
		OnStartCollection(); 
		progress=progress+1;
		}

        if((overphoto==1)&&(progress==5))
			{
			  secondcamerax=centerx;
			  secondcameray=centery;
			  secondrobotx=d1000_get_command_pos(0);
			  secondroboty=d1000_get_command_pos(1);


			  photo1angle=atan((secondcameray-firstcameray)/(secondcamerax-firstcamerax))+3.141592653589793/4;
			  //xdiv=firstrobotx-firstcamerax*xscale;
			  //ydiv=firstroboty-firstcameray*yscale;
			  float firstcameraxtemp,firstcameraytemp,secondcameraxtemp,secondcameraytemp;

			  firstcameraxtemp=firstcamerax*cos(photo1angle)+firstcameray*sin(photo1angle);
              firstcameraytemp=firstcameray*cos(photo1angle)-firstcamerax*sin(photo1angle);

			  secondcameraxtemp=secondcamerax*cos(photo1angle)+secondcameray*sin(photo1angle);
              secondcameraytemp=secondcameray*cos(photo1angle)-secondcamerax*sin(photo1angle);


			  xscale=(secondrobotx-firstrobotx)/(secondcameraxtemp-firstcameraxtemp);
		      yscale=(secondroboty-firstroboty)/(secondcameraytemp-firstcameraytemp);

			
	          //xscale=(secondrobotx-firstrobotx)/(secondcamerax-firstcamerax);
		      //yscale=(secondroboty-firstroboty)/(secondcameray-firstcameray);
			  //xdiv=firstrobotx-firstcamerax*xscale;
			  //ydiv=firstroboty-firstcameray*yscale;
			  point1.x=centerx;
			  point1.y=centery;
			  
	          progress=progress+1;



		}
		if(progress==6)
		 {
			 d1000_start_t_move( 3,45000, 0, vturnplate, 0.3);
			 
			 progress=progress+1;
		 }
			DWORD tempd=d1000_check_done(3);
		if((tempd==1)&&(progress==7))
		{
			Sleep(500);
			progress=progress+1;
		}
        if(progress==8)
		{

		startphoto=0;
		overphoto=0;
		OnStartCollection(); 
		progress=progress+1;
		}
        if((overphoto==1)&&(progress==9))
			{
			 
			  point2.x=centerx;
			  point2.y=centery;
			  
	          progress=progress+1;



		}
		if(progress==10)
		 {
			 d1000_start_t_move( 3,45000, 0, vturnplate, 0.3);
			 
			 progress=progress+1;
		 }
		DWORD tempf=d1000_check_done(3);
		if((tempf==1)&&(progress==11))
		{
			Sleep(500);
			progress=progress+1;
		}
        if(progress==12)
		{

		startphoto=0;
		overphoto=0;
		OnStartCollection(); 
		progress=progress+1;
		}
        if((overphoto==1)&&(progress==13))
			{
			 
			  point3.x=centerx;
			  point3.y=centery;
			  
	          progress=progress+1;



		}

		if((overphoto==1)&&(progress==14))
			{
			  mypoint center;
			  center=circle(point1,point2,point3);
			  	disp_cross(m_Windowid,center.y,center.x,80,0);
			   float x=d1000_get_command_pos(0);
			  float y=d1000_get_command_pos(1);
			  
			  float rotatex,rotatey;
			  
			  rotatex=center.x*cos(photo1angle)+center.y*sin(photo1angle);
              rotatey=center.y*cos(photo1angle)-center.x*sin(photo1angle);
			  xdiv=x-rotatex*xscale;
			  ydiv=y-rotatey*yscale;


			 // xdiv=x-center.x*xscale;
			  //ydiv=y-center.y*yscale;
			 // xcenterdiv=center.x-x;
			//  ycenterdiv=center.y-y;

              photoverify=false;
			  progress=0;
			  CFile scalenew;
         scalenew.Open(currentdir+"\\scale.txt",CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);
	     CArchive scalearnew(&scalenew,CArchive::store);
		 scalearnew<<xscale<<yscale<<xdiv<<ydiv<<camera2xdiv<<camera2ydiv<<metalscale<<metalyscale<<photo2angle<<photo1angle;
         scalearnew.Close();
   		 scalenew.Close();

		}
	}
    
  
	  	if(metalverify==true)
	{


		if(progress==0)
		{

			startphoto2=0;
			overphoto2=0;
			OnStartCollection2(); 
			progress=progress+1;
			if((verifypastex==0)||(verifypastey==0))
			{
				verifyinfo="Z下移记录贴合位";
				metalverify=0;
				progress=0;
			}
		}

        if((overphoto2==1)&&(progress==1))
		{
			if((centerx==0)||(centerx2==0))
			{
				verifyinfo="吸头连拍，获取吸头模板位置";
				metalverify=0;
				progress=0;
			}
			else
			{
					
				if(photoproblem2==true)
				{
					verifyinfo="夹具模板拍照失败";
					metalverify=0;
					progress=0;
				}
				else
				{

				  float worldx1temp,worldy1temp,worldx2temp,worldy2temp;
				  float worldx1,worldy1,worldx2,worldy2;
				  float xmove,ymove;
				  

				  worldx1temp=centerx*xscale+xdiv;
				  worldy1temp=centery*yscale+ydiv;
				  worldx2temp=centerx2*xscale+xdiv;
				  worldy2temp=centery2*yscale+ydiv;
				  xmove=verifypastex-photox;
				  ymove=verifypastey-photoy;
				  worldx1=worldx1temp+xmove;
				  worldy1=worldy1temp+ymove;
				  worldx2=worldx2temp+xmove;
				  worldy2=worldy2temp+ymove;
				  float lpix,lworld;
				  lpix=sqrt((camera22centerx-camera21centerx)*(camera22centerx-camera21centerx)+(camera22centery-camera21centery)*(camera22centery-camera21centery));
				  lworld=sqrt((worldx2-worldx1)*(worldx2-worldx1)+(worldy2-worldy1)*(worldy2-worldy1));
				  metalscale=lworld/lpix;
				  metalyscale=lworld/lpix;
				  float angleworld,anglepix;
				  angleworld=atan((worldy2-worldy1)/(worldx2-worldx1));
				  anglepix=atan((camera22centery-camera21centery)/(camera22centerx-camera21centerx));
				  photo2angle=anglepix-angleworld;

				  float verifyx21,verifyy21;
				  float verifyx22,verifyy22;

				  verifyx21=camera21centerx*cos(photo2angle)+camera21centery*sin(photo2angle);
				  verifyy21=camera21centery*cos(photo2angle)-camera21centerx*sin(photo2angle);
				  verifyx22=camera22centerx*cos(photo2angle)+camera22centery*sin(photo2angle);
				  verifyy22=camera22centery*cos(photo2angle)-camera22centerx*sin(photo2angle);

				  //metalscale=(worldx2-worldx1)/(verifyx22-verifyx21);
				 // metalyscale=(worldy2-worldy1)/(verifyy22-verifyy21);

				  camera2xdiv=worldx1-verifyx21*metalscale;
				  camera2ydiv=worldy1-verifyy21*metalyscale;


           
			      progress=progress+1;
				}
			}
		
			}
	     if(progress==2)
		 {
			 
			 /*
			// d1000_start_t_move( 0,2000, 0, vexx, 0.3);
			 d1000_start_t_move( 1,4000, 0, vexy, 0.3);
			 progress=progress+1;
			
			 tempb=0;
			 servostarted=1;
		 }
				
			
		 
		 tempb=d1000_check_done(1);


		
	    if((tempb==1)&&(progress==3)&&(servostarted==1))
		{
			Sleep(800);
			progress=progress+1;
			servostarted=0;
		}
		if(progress==4)
		{

		startphoto2=0;
		overphoto2=0;
		OnStartCollection2(); 
		progress=progress+1;
		}

        if((overphoto2==1)&&(progress==5))
			{
			  secondcamerax=camera21centerx;
			  secondcameray=camera21centery;
			  secondrobotx=d1000_get_command_pos(0);
			  secondroboty=d1000_get_command_pos(1);
			
	          //metalscale=(secondrobotx-firstrobotx)/(secondcamerax-firstcamerax);
		      //metalyscale=(secondroboty-firstroboty)/(secondcameray-firstcameray);
			  photo2angle=atan((secondcameray-firstcameray)/(secondcamerax-firstcamerax));
				  if(photo2angle<0)
				  {photo2angle=photo2angle+3.141592653589793;}

				  photo2angle=photo2angle-3.141592653589793/2;
			  //xdiv=firstrobotx-firstcamerax*xscale;
			  //ydiv=firstroboty-firstcameray*yscale;
			  float firstcameraxtemp,firstcameraytemp,secondcameraxtemp,secondcameraytemp;

			  firstcameraxtemp=firstcamerax*cos(photo2angle)+firstcameray*sin(photo2angle);
              firstcameraytemp=firstcameray*cos(photo2angle)-firstcamerax*sin(photo2angle);

			  secondcameraxtemp=secondcamerax*cos(photo2angle)+secondcameray*sin(photo2angle);
              secondcameraytemp=secondcameray*cos(photo2angle)-secondcamerax*sin(photo2angle);


			 // metalscale=(secondrobotx-firstrobotx)/(secondcameraxtemp-firstcameraxtemp);
		      metalyscale=(secondroboty-firstroboty)/(secondcameraytemp-firstcameraytemp);
			  metalscale=metalyscale;
			  point1.x=camera21centerx;
			  point1.y=camera21centery;
			  
	          progress=2000;
			  



		}

				
	     if(progress==2000)
		 {
			// d1000_start_t_move( 0,2000, 0, vexx, 0.3);
			 d1000_start_t_move( 1,-4000, 0, vexy, 0.3);
			 progress=progress+1;
			 tempa=0;
			 tempb=0;
			 servostarted=1;
		 }
				
			
		 
		 tempb=d1000_check_done(1);


		
	    if((tempb==1)&&(progress==2001)&&(servostarted==1))
		{
			Sleep(500);
			servostarted=0;
		

		startphoto2=0;
		overphoto2=0;
		OnStartCollection2(); 
		progress=progress+1;
		}

        if((overphoto2==1)&&(progress==2002))

		 {
			 d1000_start_t_move( 3,4000, 0, vturnplate, 0.3);
			 Image2temp=Image2;
			 
			 progress=7;
		 }
	DWORD tempd=d1000_check_done(3);
	if((tempd==1)&&(progress==7))
		{
			Sleep(500);
			progress=progress+1;
		}
   if(progress==8)
		{

		startphoto2=0;
		overphoto2=0;
		OnStartCollection2(); 
		progress=progress+1;
		}
        if((overphoto2==1)&&(progress==9))
			{
			 
			  point2.x=camera21centerx;
			  point2.y=camera21centery;
			  
	          progress=14;
			  Herror error_num;
			  try
{
 

  // Local iconic variables 
  Hobject   VectorField, EdgeAmplitude1;
  Hobject  Region1, EdgeAmplitude2, Region2, RegionUnion, RegionDilation;
  Hobject  Rectangle, RegionIntersection, RegionGrid, VectorFieldReduced;
  Hobject  RowImage, ColImage;


  // Local control variables 
  HTuple   Rows, Columns;
  HTuple  RowDisplacement, ColumnDisplacement, HomMat2D, Sx;
  HTuple  Sy, Alpha, Theta, Tx, Ty, CosAlpha, SinAlpha, Temp;
  HTuple  RotationColumn, RotationRow, CenterRows, CenterColumns;


  //
  //calculate optical flow field
  optical_flow_mg(Image2temp, Image2, &VectorField, "fdrig", 0.8, 1, 20, 5, "default_parameters", 
      "fast_accurate");
  //
  //extract only significant points
  sobel_amp(Image2temp, &EdgeAmplitude1, "sum_abs", 3);
  threshold(EdgeAmplitude1, &Region1, 30, 255);
  sobel_amp(Image2, &EdgeAmplitude2, "sum_abs", 3);
  threshold(EdgeAmplitude2, &Region2, 30, 255);
  union2(Region1, Region2, &RegionUnion);
  dilation_circle(RegionUnion, &RegionDilation, 2.5);
  gen_rectangle1(&Rectangle,300,20,2592-300,1944-300);//left(&Rectangle,300,300,2592-300,1944-20);//right(&Rectangle,300,20,2592-300,1944-300);//left//
  disp_obj(Rectangle, m_Window2id);

  intersection(RegionDilation, Rectangle, &RegionIntersection);
  gen_grid_region(&RegionGrid, 5, 5, "points",1944, 2592);
 // disp_obj(RegionGrid, m_Window2id);

  intersection(RegionIntersection, RegionGrid, &RegionIntersection);
  reduce_domain(VectorField, RegionIntersection, &VectorFieldReduced);
  //
  //collect vectors and calculate transformation matrix
  get_region_points(RegionIntersection, &Rows, &Columns);
  vector_field_to_real(VectorFieldReduced, &RowImage, &ColImage);
  get_grayval(RowImage, Rows, Columns, &RowDisplacement);
  get_grayval(ColImage, Rows, Columns, &ColumnDisplacement);
  vector_to_rigid(Rows, Columns, Rows+RowDisplacement, Columns+ColumnDisplacement, 
      &HomMat2D);
  //
  //calculate rotation center
  //
  //the calculation is based on the assumption that the
  //real transformation is indeed a rotation with NO scaling or slanting.
  //HomMat2D is assumed to look like:
  //[ cos(Alpha), -sin(Alpha), -x*cos(Alpha)+y*sin(Alpha)+x,
  //  sin(Alpha), cos(Alpha), -x*sin(Alpha)-y*cos(Alpha)+y ]
  //for robustness, Alpha is estimated with vector_field_to_hom_mat2d,
  //and after that the rotation center can be easily calculated
  hom_mat2d_to_affine_par(HomMat2D, &Sx, &Sy, &Alpha, &Theta, &Tx, &Ty);
  CosAlpha = Alpha.Cos();
  SinAlpha = Alpha.Sin();
  Temp = (1-CosAlpha)/SinAlpha;
  RotationColumn = (HTuple(HomMat2D[2])+(Temp*HTuple(HomMat2D[5])))/((Temp*(1-CosAlpha))+SinAlpha);
  RotationRow = (((1-CosAlpha)*RotationColumn)-HTuple(HomMat2D[5]))/SinAlpha;
  CenterRows.Append(RotationRow);
  CenterColumns.Append(RotationColumn);

  opticalflowcenter.x=CenterColumns[0].D();
  opticalflowcenter.y=CenterRows[0].D();
  float tempx,tempy;
  flowx=opticalflowcenter.x;
  flowy=opticalflowcenter.y;
  	set_color(m_Window2id,"green");
	 disp_obj(VectorFieldReduced, m_Window2id);
		set_color(m_Window2id,"red");		
	disp_cross(m_Window2id,flowy,flowx,140,0);
  tempx=flowx;
  tempy=flowy;

  //

}
    catch (HException &except)
		 {
           error_num = except.err;
		   metalverify=false;
           	startphoto2=0;
	    	overphoto2=0;
		   progress=0;
		   return;
		  	 	   
          
		 }


		}
		if(progress==10)
		 {
			 d1000_start_t_move( 3,80000, 0, vturnplate, 0.3);
			 
			 progress=progress+1;
		 }
		DWORD tempf=d1000_check_done(3);
		if((tempf==1)&&(progress==11))
		{
			Sleep(500);
			progress=progress+1;
		}
        if(progress==12)
		{

		startphoto2=0;
		overphoto2=0;
		OnStartCollection2(); 
		progress=progress+1;
		}
        if((overphoto2==1)&&(progress==13))
			{
			 
			  point3.x=camera21centerx;
			  point3.y=camera21centery;
			  
	          progress=progress+1;



		}

		if((progress==14))
			{
			 // mypoint center;
			 // center=circle(point1,point2,point3);
			   //float x=d1000_get_command_pos(0);
			  float y=d1000_get_command_pos(1);
			  float rotatex,rotatey;
			  
			  rotatex=flowx*cos(photo2angle)+flowy*sin(photo2angle);
              rotatey=flowy*cos(photo2angle)-flowx*sin(photo2angle);
			  camera2xdiv=0-rotatex*metalscale;
			  camera2ydiv=y-rotatey*metalyscale;
			 // xcenterdiv=center.x-x;
			//  ycenterdiv=center.y-y;*/

              metalverify=false;
			  progress=0;
			  CFile scalenew;
         scalenew.Open(currentdir+"\\scale.txt",CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);
	     CArchive scalearnew(&scalenew,CArchive::store);
		 scalearnew<<xscale<<yscale<<xdiv<<ydiv<<camera2xdiv<<camera2ydiv<<metalscale<<metalyscale<<photo2angle<<photo1angle;
         scalearnew.Close();
   		 scalenew.Close();

		}
       
	}

		  
	



	if((run==true)||(mainstepp==true)||(mainstepm==true))
	{
  switch(machinestate)
	  {
		  
	  case state1:
		    d1000_out_bit( pusherout1, back);
			d1000_out_bit( pusherout2, back);
		    d1000_out_bit( vacuumout1, back);
			d1000_out_bit( vacuumout2, back);
			lastone=false;
			lastgoon=false;
		
			turnplatestarted=0;
			//disablemainstepm=true;
            machinestate=state1p0p0;
			times=0;
			if(run==false)
				{
					stateinfo="系统加电";
				}
			break;
	 case state1p0p0:
		   //  d1000_out_bit(breakvacuumout, front);
            if(times>10)
			{
				d1000_out_bit( servoenable, front);
				d1000_out_bit( stepenable, back);
			
			}

            times=times+1;
		   
			if((d1000_in_bit(servoxready)==0)&&(d1000_in_bit(servoyready)==0)&&(d1000_in_bit(servorready)==0)
			  	&&(times>20)&&(d1000_in_bit(pusherupin1)==0)&&(d1000_in_bit(pusherupin1)==0))
			{
				machinestate=state1p1;
			
			
				 servostarted=0;
			}
			if(run==false)
				{
					stateinfo="系统复位";
				}
			break;



				  
	  case state1p1:
		    xorgstate=d1000_get_axis_status(0);
			yorgstate=d1000_get_axis_status(1);
			xorgstate=xorgstate&0x00000004;
			yorgstate=yorgstate&0x00000004;
			turnplateorgstate=d1000_get_axis_status(3);
		    turnplateorgstate=turnplateorgstate&0x00000004;
			tempa=d1000_check_done(0);
		    tempb=d1000_check_done(1);
			tempd=d1000_check_done(3);
			if((tempd!=0)&&(servostarted==0)&&(turnplateorgstate!=0))
				{
					d1000_start_t_move( 3,10000, 0, 2000, 0.3);
			}

			if((tempa!=0)&&(servostarted==0)&&(xorgstate!=0))
			{
					d1000_start_t_move( 0,1000, 0, 1000, 0.3);
			}

            if((tempb!=0)&&(servostarted==0)&&(yorgstate!=0))
			{
					d1000_start_t_move( 1,1000, 0, 1000, 0.3);

			}
			servostarted=1;

			
			  if((tempa!=0)&&(tempb!=0)&&(tempd!=0))
			 {
				 mainstepp=false;
				 mainstepm=false;
				 machinestate=state2;
				 servostarted=0;
				 
				// disablemainstepm=true;
			 }



		   	if(run==false)
				{
					stateinfo="系统复位";
				}
			break;

		case state2:
		     //disablemainstepm=true;
		   
		    tempb=d1000_check_done(1);
		
			if((tempb!=0)&&(servostarted==0))
			{
				d1000_home_move( 1, 0, -1000, 0.3);
				servostarted=1;
			}
			  
		    
		     tempb=d1000_check_done(1);
			 if((tempb==4))
			 {
				
				 d1000_set_command_pos(1,0);
				 mainstepp=false;
				 mainstepm=false;
				 machinestate=state2p1;
				 servostarted=0;
				 turnplatestarted=0;
				 if(run==false)
				{
					stateinfo="运行到取片";
				}
			 }
			 
		    
			break;

	 case state2p1:
		  	
			
			tempd=d1000_check_done(3);
	

			if((tempd!=0)&&(turnplatestarted==0))
			{
					

					d1000_home_move( 3, 0, -10000, 0.3);
						turnplatestarted=1;
			}

           
		
			tempd=d1000_check_done(3);
			
			if((tempd==4)&&(turnplatestarted==1))
			 {
	             d1000_set_command_pos(3,0);
				 machinestate=state2p2;
				 turnplatestarted=0;
				 

						
			 }

             break;

	  case state2p2:
		     //disablemainstepm=true;
		    tempa=d1000_check_done(0);
		    //tempb=d1000_check_done(1);
			if((tempa!=0)&&(servostarted==0))
			{
				d1000_home_move( 0, 0, -1000, 0.3);
				servostarted=1;
			}
			//if((tempb!=0)&&(servostarted==0))
			//{
			//	d1000_home_move( 1, 0, -1000, 0.3);
				
			//}
			  
		     tempa=d1000_check_done(0);
		     //tempb=d1000_check_done(1);
			 if((tempa==4))//&&(tempb==4))
			 {
				 d1000_set_command_pos(0,0);
				 d1000_set_command_pos(1,0);
				 mainstepp=false;
				 mainstepm=false;
				 machinestate=state3;
				 servostarted=0;
				 turnplatestarted=0;
				 zstarted=0;
				 if(run==false)
				{
					stateinfo="运行到取片";
				}
			 }
			 
		    
			break;

	case state2p3:
		 
			 {
				 mainstepp=false;
				 mainstepm=false;
				 machinestate=state3;
				 
                 turnplatestarted=0;
				 zstarted=0;
				 servostarted=0;
			
			 }
			  if(run==false)
				{
					stateinfo="运行到取片";
				}

			  break;

    



	  case state3:
		    //disablemainstepm=true;
			d1000_out_bit(pusherout1, back);
		    d1000_out_bit(pusherout2, back);
				d1000_out_bit(flowout1, back);
					d1000_out_bit(flowout2, back);
		  
			tempa=d1000_check_done(0);
		    tempb=d1000_check_done(1);
			tempd=d1000_check_done(3);
		
			pushstate=(
				d1000_in_bit(pusherupin1)
				||(d1000_in_bit(pusherupin2)&&(repeat==1))
				);
           if((tempd!=0)&&(servostarted==0)&&(pushstate==0))
			 
		   {
			   d1000_start_ta_move( 3,pickangle, 0, vturnplate, 0.2);
		   linecango=true;
		   }

		      //long yposition;
			  //yposition=d1000_get_command_pos( 1 );
			 if((tempb!=0)&&(servostarted==0)&&(pushstate==0))
			 {
				 d1000_start_ta_move( 1,picky, 0, vexy, 0.2);
				 
				
			 }//T形
			 if((tempa!=0)&&(servostarted==0)&&(pushstate==0))//&&(yposition<25000))
			 {
				 d1000_start_ta_move( 0,pickx, 0, vexx, 0.2);
				 BeginTime();
				 
				servostarted=1;
			 }//T形
		

			
			tempa=d1000_check_done(0);
		    tempb=d1000_check_done(1);
			tempd=d1000_check_done(3);
		
			  if((tempa!=0)&&(tempb!=0)&&(tempd!=0)&&(servostarted==1))
			 {
				  
				  fixturecanphoto=true;
				 mainstepp=false;
				 mainstepm=false;
				 machinestate=state4;
				 turnplatestarted=0;
				 servostarted=0;
				 if(tapeready==false)
				 {disablemainstepp=true;}
				 disablelinestepp=false;
			 }
			  if(run==false)
				{
					stateinfo="等待料带准备好";
				}
              mainstepp=false;
			  break;

	  case state4:
		  if(wastetimes>fixtureouttime)
				  {
					  wastetimes=0;
					  wasteerror=true;
				  }
		     if((tapeready==true)&&(shieldpaste==0))
			 {
              disablelinestepm=true;
              tapeready=false;
//			  disablemainstepm=false;	 
		  
			  d1000_out_bit( vacuumout1, front);
			  if(repeat==1)
			  {
			  d1000_out_bit( vacuumout2, front);
			  }
			  halfdown=true;
              machinestate=state4p1;
			  servostarted=0;
			  zstarted=0;
			  times=0;
			  mainstepp=false;
			  mainstepm=false;

			 }
			 if(run==false)
				{
					stateinfo="提取料片";
				}
			break;

	case state4p1:
		 
		  
			  d1000_out_bit( pusherout1, front);
			  if(repeat==1)
			  {
			  d1000_out_bit( pusherout2, front);
			  }
		
			  //if((tempc==1)&&(zstarted==1))
			 {
				 mainstepp=false;
				 mainstepm=false;
				 machinestate=state5;
				 
                 turnplatestarted=0;
				 zstarted=0;
				 servostarted=0;
			
			 }
			  if(run==false)
				{
					stateinfo="等待料带准备好";
				}

		 break;
      case state5:
		    
           if((run==true)||(mainstepp==true))
		   {
			  d1000_out_bit( pusherout1, front);
			  
			    d1000_out_bit( vacuumout1, front);
				if(repeat==1)
			  {
				d1000_out_bit( pusherout2, front);
			  d1000_out_bit( vacuumout2, front);
				}
		   times=times+1;
			if((times>picktime)&&((run==true)||(mainstepp==true)))
			{
				times=0;
				machinestate=state6;
				halfready=true;
				disablemainstepp=true;
				disablelinestepp=false;
//				disablemainstepm=true;
				mainstepp=false;
			

			}
		   }
		  if(mainstepm==true)
			{
				times=0;
				machinestate=state2p3;
				mainstepm=false;
//				disablemainstepm=true;
				tapeready=true;
				zstarted=0;
				disablelinestepm=false;
				
				d1000_out_bit( pusherout1, back);
			    d1000_out_bit( vacuumout1, back);
				d1000_out_bit( pusherout2, back);
			    d1000_out_bit( vacuumout2, back);
		

		  }




           if(run==false)
				{
					stateinfo="等待料带单元回位";
				}


		    break;

	  case state6:
		     if(tonguehomed==true)
			 {
				tonguehomed=false;
				machinestate=state7;
				//d1000_out_bit( pusher, back);
				zstarted=0;

			
			 }
			 if(run==false)
				{
					stateinfo="料片提取检测";
				}
		     break;
	  case state7:

		  
		      times=times+1;

			    //d1000_out_bit( vacuumout1, back);
				
			    //d1000_out_bit( vacuumout2, back);
		
			 
		
			// if(times>fixtureouttime)
			 {
				 mainstepp=false;
				 mainstepm=false;
			
				 
                 turnplatestarted=0;
				 zstarted=0;
				 servostarted=0;
		
				 machinestate=state8;
				 vacuumcounter=0;
				 times=0;

			 }
			 //if(d1000_in_bit(vacuumin)==1)
			 //{machinestate=state30;
               // vacuumcounter=vacuumcounter+1;
               //}
		    if(run==false)
				{
					stateinfo="运行到拍照位置";
				}
		     break;
      case state8:
		   halfdown=false;
		     d1000_out_bit( vacuumout1, front);
				if(repeat==1)
			  {
			    d1000_out_bit( vacuumout2, front);
				}
			 tempa=d1000_check_done(0);
		     tempb=d1000_check_done(1);
			 tempd=d1000_check_done(3);
			   d1000_out_bit( pusherout1, back);
			  d1000_out_bit( pusherout2, back);
		     
			 if((tempa!=0)&&(servostarted==0))
			 {
				 d1000_start_ta_move( 0,photox, 0, vexx, 0.2);
				 tempa=0;
			      
			 }//T形
			  if((tempd!=0)&&(servostarted==0))
			 {
				 d1000_start_ta_move( 3,photor, 0, vturnplate, 0.2);
				 tempc=0;
			      
			 }//T形
			  if((tempb!=0)&&(servostarted==0))
			 {
				 d1000_start_ta_move( 1,photoy, 0, vexy, 0.2);
				 tempb=0;
				  servostarted=1;
			      
			 }//T形
			
			  if((tempa!=0)&&(tempb!=0)&&(tempd!=0)&&(d1000_in_bit(servoxcoin)==0)&&(d1000_in_bit(servoycoin)==0)&&(d1000_in_bit(servorcoin)==0)
				  &&(servostarted==1)&&(d1000_in_bit(pusherupin1)==0)&&((d1000_in_bit(pusherupin2)==0)||(repeat==0)))
			 {			    
				 disablelinestepp=false;
				times=times+1;
				if(times>photodelay)
				{
					 
				machinestate=state8p1;
					 mainstepp=false;
				 mainstepm=false;
				times=0;
				}
				 
				 
				 startphoto=0;
				 
				 servostarted=0;
			
			 }

			  if(run==false)
				{
					stateinfo="位置拍照";
				}
			  break;
	 
		case state8p1:
		    if(startphoto==0)
			{
				if(run==false)
				{
					stateinfo="拍照";
				}
				
				modalselect=0;
				startphoto=1;
				overphoto=0;
				OnStartCollection();
				
			} 

			
		
		
	
			{
				machinestate=state9p1;  
                
				servostarted=0;
				 mainstepp=false;
				 mainstepm=false;
				 times=0;
			
				
			}
				break;

		


		

	  case state9p1:
		      times=times+1;
			  if(times>90)
			  {
				  times=0;
				  startphoto=0;
				  overphoto=0;
				  machinestate=state8p1;

			  }
		      if(imagephotoover==true)
				{
				   //d1000_out_bit( halfout, back);
					imagephotoover=false;
	                	
	 
					OnSearchObject();

				 }
			  

			if((overphoto==1))//&&(d1000_in_bit(pusherup)==0))
			{
				tonguecanout=true;
				if(photoalreadyerror==false)
				{
					machinestate=state10; 
				
						if(fixtureready==false)
					{
						disablemainstepp=true;
					}
				}
				else
				{ 
					
					machinestate=state25;
					disablelinestepp=false;
					zstarted=0;
				
					
				
					//run=false;
				} 

				 startphoto=0;
				 overphoto=0;
                 servostarted=0;
				 mainstepp=false;
				 mainstepm=false;
//				 disablemainstepm=true;

				
			}

				if((run==false)&&(mainstepp==true))
				{
					stateinfo="运行到贴合位置";
				}
				break;
	  case state10:

		   
		         if((fixtureready==true)
					  &&(d1000_in_bit(vacuumin1)==0)&&((d1000_in_bit(vacuumin2)==0)||(repeat==0))
		 )
					 {
						  machinestate=state11;
						  fixtureready=false;
						  
			             caculated=false;
						
						servostarted=0;
					
						mainstepm=false;
						
						zstarted=0;

					}
				mainstepp=false;
				
			 
		 

			  break;

	  case state11:


		     	
		    
			 tempa=d1000_check_done(0);
		     tempb=d1000_check_done(1);
			
			 tempd=d1000_check_done(3);
             if(caculated==false)
			 {
				 caculated=true;


             //if(repeat==0)
			 {
			 float picturex,picturey;
			 picturex=centerx2*xscale+xdiv;//xDIV 相机原点的位置
			 picturey=centery2*yscale+ydiv;  //第二点机械手坐标系的Y
			 
			 float centerxdiv,centerydiv;//对角坐标偏差（第二点减去第一点）
			 
    		 centerxdiv=centerx2*xscale-centerx*xscale;
			 centerydiv=centery2*yscale-centery*yscale;
 	 	     float newmodel11x,newmodel11y,newmodel12x,newmodel12y;
			newmodel11x=model11x*cos(photo1angle)+model11y*sin(photo1angle);
            newmodel11y=model11y*cos(photo1angle)-model11x*sin(photo1angle);
			newmodel12x=model12x*cos(photo1angle)+model12y*sin(photo1angle);
             newmodel12y=model12y*cos(photo1angle)-model12x*sin(photo1angle);
			 
			////////////////////////////////////////////////////////////////////////////////
			 float photoangletemp1,photoangletemp1temp;
			 float fixangle,fixangletemp;
			 if((centerx2-centerx)==0)
			 {photoangletemp1temp=3.141592653589793/2;}
			 if(centerxdiv!=0)
			 photoangletemp1temp=atan((float)(centery2-centery)/(float)(centerx2-centerx));//已经旋转的角
			  if((newmodel12x-newmodel11x)==0)
			 {fixangletemp=3.141592653589793/2;}
			 if((newmodel12x-newmodel11x)!=0)
             fixangletemp=atan((float)(newmodel12y-newmodel11y)/(float)(newmodel12x-newmodel11x));//固定角度


			 if((photoangletemp1temp<0)&&(fixangletemp>0.8))
			 {photoangletemp1=3.141592653589793+photoangletemp1temp;}
			 else
			 {photoangletemp1=photoangletemp1temp;}
		 
			 if((fixangletemp<0)&&(photoangletemp1temp>0.8))
			 {fixangle=fixangletemp+3.141592653589793;}
			 else
			 {fixangle=fixangletemp;}
			 photoangle=photoangletemp1-fixangle;//已有的角度偏差
			 
			 if((modalorg11==0)&&(modalorg12==0)&&((abs(centerx-centerx2))<30)&&((abs(centery-centery2))<30))
			 {photoangle=0;}
////////////////////////////////////////////////////////////

             float ipiececenterx,ipiececentery,ircenter;
			 ipiececenterx=picturex-centerxdiv/2-photox;//中心点旋转前的及坐标
			 ipiececentery=picturey-centerydiv/2-photoy;

			 ircenter=sqrt(ipiececenterx*ipiececenterx+ipiececentery*ipiececentery);//中心点击坐标半径
              
			 float icenterangle;
			 if(ipiececenterx==0)
			 {
				 if(ipiececentery>=0)
				 {icenterangle=3.141592653589793/2;}
				 if(ipiececentery<0)
				 {icenterangle=-3.141592653589793/2;}
			 }
			 if(ipiececenterx!=0)
			 {
				
				icenterangle=atan(ipiececentery/ipiececenterx);
				if(ipiececenterx<0)
			 
				{icenterangle=3.141592653589793+icenterangle;}//中心点极坐标下的角度

			 }
		 
			 float inewcenterangle,inewcenterangle2;
			 float watchangle;
			 watchangle=camera2divangle;
			 watchangle=icenterangle;
			 watchangle=pasteangle;
			 
			 inewcenterangle=icenterangle+photoangle+(float)pasteangle/180*3.141592653589793/1000+camera2divangle;
			 //&&&&&&&&&&
			 float angletemp;
			 angletemp=+photoangle*180/3.141592653589793+camera2divangle*180/3.141592653589793;
			 //&&&&&&&&&&
			 float ipiececenternewx,ipiececenternewy;
			 ipiececenternewx=ircenter*cos(inewcenterangle);//???????中心点旋转后的及坐标
			 ipiececenternewy=ircenter*sin(inewcenterangle);
             float allchangex,allchangey;
			 allchangex=(ipiececenternewx-ipiececenterx);
			 allchangey=(ipiececenternewy-ipiececentery);
			 float x,y,watchx,watchy;
		
		
             x=-((centerx-newmodel11x-newmodel12x+centerx2)*xscale/2);
			 y=-((centery-newmodel11y-newmodel12y+centery2)*yscale/2);

            watchx=camera2divx;//*cos(photo2angle)+camera2divy*sin(photo2angle);
            watchy=camera2divy;//*cos(photo2angle)-camera2divx*sin(photo2angle);
	
			xa=pastex+x-allchangex+watchx;//fix
			ya=pastey+y-allchangey+watchy;//fix

			anglepluse=angletemp*1000+pasteangle;//补偿角度转化为脉冲
			 }

			if(repeat==1)
			{
			

			 float picturex,picturey;
			 picturex=recenterx2*xscale+xdiv;//xDIV 相机原点的位置
			 picturey=recentery2*yscale+ydiv;  //第二点机械手坐标系的Y
			 
			 float centerxdiv,centerydiv;//对角坐标偏差（第二点减去第一点）
			 
    		 centerxdiv=recenterx2*xscale-recenterx*xscale;
			 centerydiv=recentery2*yscale-recentery*yscale;
 	 	     float newmodel11x,newmodel11y,newmodel12x,newmodel12y;
			 newmodel11x=remodel11x*cos(photo1angle)+remodel11y*sin(photo1angle);
             newmodel11y=remodel11y*cos(photo1angle)-remodel11x*sin(photo1angle);
			 newmodel12x=remodel12x*cos(photo1angle)+remodel12y*sin(photo1angle);
             newmodel12y=remodel12y*cos(photo1angle)-remodel12x*sin(photo1angle);
			 
			////////////////////////////////////////////////////////////////////////////////
			 float photoangletemp1,photoangletemp1temp;
			 float fixangle,fixangletemp;
			 if((recenterx2-recenterx)==0)
			 {photoangletemp1temp=3.141592653589793/2;}
			 if(centerxdiv!=0)
			 photoangletemp1temp=atan((float)(recentery2-recentery)/(float)(recenterx2-recenterx));//已经旋转的角
			  if((newmodel12x-newmodel11x)==0)
			 {fixangletemp=3.141592653589793/2;}
			 if((newmodel12x-newmodel11x)!=0)
             fixangletemp=atan((float)(newmodel12y-newmodel11y)/(float)(newmodel12x-newmodel11x));//固定角度


			 if((photoangletemp1temp<0)&&(fixangletemp>0.8))
			 {photoangletemp1=3.141592653589793+photoangletemp1temp;}
			 else
			 {photoangletemp1=photoangletemp1temp;}
		 
			 if((fixangletemp<0)&&(photoangletemp1temp>0.8))
			 {fixangle=fixangletemp+3.141592653589793;}
			 else
			 {fixangle=fixangletemp;}
			 photoangle=photoangletemp1-fixangle;//已有的角度偏差

			 if((modalorg11==0)&&(modalorg12==0)&&((abs(recenterx-recenterx2))<30)&&((abs(recentery-recentery2))<30))
			 {photoangle=0;}
////////////////////////////////////////////////////////////

             float ipiececenterx,ipiececentery,ircenter;
			 ipiececenterx=picturex-centerxdiv/2-photox;//中心点旋转前的及坐标
			 ipiececentery=picturey-centerydiv/2-photoy;

			 ircenter=sqrt(ipiececenterx*ipiececenterx+ipiececentery*ipiececentery);//中心点击坐标半径
              
			 float icenterangle;
			 if(ipiececenterx==0)
			 {
				 if(ipiececentery>=0)
				 {icenterangle=3.141592653589793/2;}
				 if(ipiececentery<0)
				 {icenterangle=-3.141592653589793/2;}
			 }
			 if(ipiececenterx!=0)
			 {
				
				icenterangle=atan(ipiececentery/ipiececenterx);
				if(ipiececenterx<0)
			 
				{icenterangle=3.141592653589793+icenterangle;}//中心点极坐标下的角度

			 }
		 
			 float inewcenterangle,inewcenterangle2;
			 float watchangle;
			 watchangle=recamera2divangle;
			 watchangle=icenterangle;
			 watchangle=repasteangle;
			 
			 inewcenterangle=icenterangle+photoangle+(float)repasteangle/180*3.141592653589793/1000+recamera2divangle;
			 //&&&&&&&&&&
			 float angletemp;
			 angletemp=+photoangle*180/3.141592653589793+recamera2divangle*180/3.141592653589793;
			 //&&&&&&&&&&
			 float ipiececenternewx,ipiececenternewy;
			 ipiececenternewx=ircenter*cos(inewcenterangle);//???????中心点旋转后的及坐标
			 ipiececenternewy=ircenter*sin(inewcenterangle);
             float allchangex,allchangey;
			 allchangex=(ipiececenternewx-ipiececenterx);
			 allchangey=(ipiececenternewy-ipiececentery);
			 float x,y,watchx,watchy;
		
		
             x=-((recenterx-newmodel11x-newmodel12x+recenterx2)*xscale/2);
			 y=-((recentery-newmodel11y-newmodel12y+recentery2)*yscale/2);

            watchx=recamera2divx;//*cos(photo2angle)+recamera2divy*sin(photo2angle);
            watchy=recamera2divy;//*cos(photo2angle)-recamera2divx*sin(photo2angle);
	
			rexa=repastex+x-allchangex+watchx;//fix
			reya=repastey+y-allchangey+watchy;//fix

			reanglepluse=angletemp*1000+repasteangle;//补偿角度转化为脉冲

			}

			if((xa>18000)||(ya>48000)||(xa<0)||(ya<0)||((anglepluse-pasteangle)>40000)||((anglepluse-pasteangle)<-40000)
			   ||(((rexa>18000)||(reya>48000)||(rexa<0)||(reya<0)||((reanglepluse-repasteangle)>40000)||((reanglepluse-repasteangle)<-40000))&&(repeat==1))
				
				)
			{
			

			//	outofrange=true;
				if((xa<0)||(xa>18000))
				{xoutofrange=true;}
	
				
				if((ya<0)||(ya>48000))
				{youtofrange=true;}

				if(((anglepluse-pasteangle)<-40000)||((anglepluse-pasteangle)>40000))
				{routofrange=true;}

				if(((rexa<0)||(rexa>18000))&&(repeat==1))
				{xoutofrange=true;}
	
				
				if(((reya<0)||(reya>48000))&&(repeat==1))
				{youtofrange=true;}

				if((((reanglepluse-repasteangle)<-40000)||((reanglepluse-repasteangle)>40000))&&(repeat==1))
				{routofrange=true;}

				xa=photox2;
				ya=photoy2;
				anglepluse=0;
				machinestate=state25;
                fixtureready=true;

			}
			}

			if((d1000_in_bit(pusherupin1)==0)&&((d1000_in_bit(pusherupin2)==0)||(repeat==0))&&(servostarted==0)&&(machinestate!=state25))
			{
			if((tempd!=0))
			{
			
			
				 d1000_start_ta_move( 3, photor+anglepluse,0, vturnplate, 0.2);
     			  tempd=0;
			      
			 }//T形
	
			 if((tempa!=0))
			 {
				 d1000_start_ta_move( 0, xa,0, vexx, 0.2);
     			  tempa=0;
			      
			 }//T形
			  if((tempb!=0))
			 {

				 d1000_start_ta_move( 1,ya, 0, vexy, 0.2);
				  tempb=0;
				  
				  display();
				  display2();
			      
			 }//T形
			  servostarted=1;
			}

		   if((tempa!=0)&&(tempb!=0)&&(tempd!=0)&&(d1000_in_bit(servoxcoin)==0)
			   &&(d1000_in_bit(servoycoin)==0)&&(servostarted==1))//&&(d1000_in_bit(servorcoin)==0)
		   {   
				machinestate=state12; 
				servostarted=0;
				zstarted=0;
				times=0;
				mainstepp=false;
				mainstepm=false;
				caculated=false;


		
				
				
		   }
		
			if(run==false)
				{
					stateinfo="等待夹具进入，料片贴合";
				}
			 

		   break;


       case state12:
	   
			    d1000_out_bit(pusherout1, front); 
				throwcounter=0;
			     if((repeat==0)&&(carrytime==1))
				  {
					   d1000_out_bit(pusherout2, front); 
				  }       
				if(((repeat==1)||(repeat==0)&&(carrytime==0))&&(d1000_in_bit(pusherdownin1)==0)||
                   (repeat==0)&&(carrytime==1)&&(d1000_in_bit(pusherdownin1)==0)&&(d1000_in_bit(pusherdownin2)==0))
				{
				
			    machinestate=state13;
				servostarted=0;
				times=0;
				zstarted=0;
				 mainstepp=false;
				 mainstepm=false;
				}
		
			if(run==false)
				{
					stateinfo="贴合延时";
				}
			break;

      case state13:
		  if((run==true)||(mainstepp==true))
		  {
		    
              {
			    pastecounter=pastecounter+1;
				//totalcounter=pastecounter+castcounter;
				totalcounter=totalcounter+1;
				{
				 CFile counterfilenew;
				 counterfilenew.Open(counterfilename,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);
			     CArchive counterfilearnew(&counterfilenew,CArchive::store);
				 counterfilearnew<<pastecounter<<castcounter<<totalcounter;
				 counterfilearnew.Close();
				 counterfilenew.Close();
				}
			    machinestate=state14;
				servostarted=0;
				times=0;
			}
		  }

		break;

       case state14:     

		  times=times+1;
		  
            //if(fixturemove==0)
		  if((repeat==1)||(repeat==0)&&(carrytime==0))
		  {
		  		if(times>=(pushertime/2))
				{d1000_out_bit(flowout1, front);}
			{d1000_out_bit( vacuumout1, back);}
		  }
			if(times>=pushertime)			 
			{
				if((repeat==0)&&(carrytime==1))
				{
					machinestate=state15;
					{d1000_out_bit( vacuumout1, back);}
					{d1000_out_bit( vacuumout2, back);}
				}
				else
				{
				    machinestate=state16;
				}
				servostarted=0;
				times=0;
			}
			if(run==false)
				{
					stateinfo="贴合完成";
				}
			break;


		case state15:
			{d1000_out_bit( vacuumout1, back);}
			{d1000_out_bit( vacuumout2, back);}
			 short AxisArray[2];
             long DistArray[2];
		     AxisArray[0]=0; // 轴0、轴1直线差补
			 AxisArray[1]=1;
             
			 tempa=d1000_check_done(0);
		     tempb=d1000_check_done(1);
			 float angleroller;
			 float xroller;
			 
			 angleroller=anglepluse*3.14159265/1000/180;
			 xroller=tan(angleroller)*rollerfinished;
		     DistArray[0]=+xroller; // △X＝1000 脉冲
             DistArray[1]=-rollerfinished; // △Y＝2000脉冲
			
			  if((tempb!=0)&&(tempa!=0)&&(servostarted==0))
			 {
				 d1000_start_t_line(2,AxisArray,DistArray, 0, vexroller, 0.2);
				 tempb=0;
				 tempa=0;
				 servostarted=1;
			


			      
			 }//T形*/
		
			 if((tempb==1)&&(tempa==1)&&(servostarted==1))
			 {	  
			
				d1000_out_bit( vacuumout1, back);
					

				 
			     
				 machinestate=state16;
				 times=0;
				 servostarted=0;
				 mainstepp=false;
				 mainstepm=false;
//				 disablemainstepm=true;
				 zstarted=0;
			 }
			  if(run==false)
				{
					stateinfo="滚膜结束";
				}

			  break;
			   
		case state16:     
	  	
			d1000_out_bit(pusherout1, back);
          d1000_out_bit(pusherout2, back);
			if(d1000_in_bit(pusherdownin1)==1)
			{	d1000_out_bit(flowout1, back);}	
			
			if((d1000_in_bit(pusherupin1)==0)&&(d1000_in_bit(pusherupin2)==0))
			{
			
				mainstepp=false;
				mainstepm=false;
			    disablefixturestepp=false;
				fixturecanphoto=false;
				if(repeat==0)
				{
					pastefinished=true;
					machinestate=state3;
					//pastefinished=true;
					EndTime();
				}
				else
				{
					machinestate=state17;
					caculated=false;
				}
				zstarted=0;
				servostarted=0;
				times=0;
				
			}
			if(run==false)
				{
					stateinfo="运行到取片";
				}
			break;


		case state17:
   
			 tempa=d1000_check_done(0);
		     tempb=d1000_check_done(1);
			 d1000_out_bit(flowout1, back);
			 tempd=d1000_check_done(3);
            
	if((xa>18000)||(ya>48000)||(xa<0)||(ya<0)||((anglepluse-pasteangle)>40000)||((anglepluse-pasteangle)<-40000)
			   ||(rexa>18000)||(reya>48000)||(rexa<0)||(reya<0)||((reanglepluse-repasteangle)>40000)||((reanglepluse-repasteangle)<-40000)
				)
			{
			
				
				
				
		
				if((rexa<0)||(rexa>18000))
				{xoutofrange=true;}
	
				
				if((reya<0)||(reya>48000))
				{youtofrange=true;}

				if(((reanglepluse-repasteangle)<-40000)||((reanglepluse-repasteangle)>40000))
				{routofrange=true;}

				rexa=photox2;
				reya=photoy2;
				reanglepluse=0;
fixtureready=true;

			}
			

			if((d1000_in_bit(pusherupin1)==0)&&((d1000_in_bit(pusherupin2)==0)||(repeat==0))&&(servostarted==0))
			{
			if((tempd!=0))
			{
			
			
				 d1000_start_ta_move( 3, photor+reanglepluse,0, vturnplate, 0.2);
     			  tempd=0;
			      
			 }//T形
	
			 if((tempa!=0))
			 {
				 d1000_start_ta_move( 0, rexa,0, vexx, 0.2);
     			  tempa=0;
			      
			 }//T形
			  if((tempb!=0))
			 {

				 d1000_start_ta_move( 1,reya, 0, vexy, 0.2);
				  tempb=0;
				  
				  display();
				  display2();
			      
			 }//T形
			  servostarted=1;
			}

		   if((tempa!=0)&&(tempb!=0)&&(tempd!=0)&&(d1000_in_bit(servoxcoin)==0)
			   &&(d1000_in_bit(servoycoin)==0)&&(servostarted==1))//&&(d1000_in_bit(servorcoin)==0)
		   {   
				machinestate=state18; 
				servostarted=0;
				zstarted=0;
				times=0;
				mainstepp=false;
				mainstepm=false;
				caculated=false;


		
				
				
		   }
		
			if(run==false)
				{
					stateinfo="等待夹具进入，料片贴合";
				}
			 

		   break;


       case state18:
	   
			    d1000_out_bit(pusherout2, front); 
			            
				if(d1000_in_bit(pusherdownin2)==0)
				{
				
			    machinestate=state19;
				servostarted=0;
				times=0;
				zstarted=0;
				 mainstepp=false;
				 mainstepm=false;
				}
		
			if(run==false)
				{
					stateinfo="贴合延时";
				}
			break;



       case state19:     

		  times=times+1;
		
            if(times>=(pushertime/2))
			{	d1000_out_bit(flowout2, front);}	
			{d1000_out_bit( vacuumout2, back);}
			if(times>=pushertime)
			 
			{
				machinestate=state20;
				servostarted=0;
				times=0;
			}
			if(run==false)
				{
					stateinfo="贴合完成";
				}
			break;



			   
		case state20:  
			if(d1000_in_bit(pusherdownin1)==1)

			{	d1000_out_bit(flowout2, back);}	
	  	
			d1000_out_bit(pusherout2, back);
				
			if((d1000_in_bit(pusherupin2)==0))
			{
				pastefinished=true;
				EndTime();
					
				mainstepp=false;
				mainstepm=false;
			    disablefixturestepp=false;
			
				{machinestate=state3;}
				zstarted=0;
				servostarted=0;
				times=0;
				
			}
			if(run==false)
				{
					stateinfo="运行到取片";
				}
			break;

					



			
		
		case state25:
   
			 tempa=d1000_check_done(0);
		     tempb=d1000_check_done(1);
			 d1000_out_bit(flowout1, back);
			 tempd=d1000_check_done(3);
 	
		        vacuumerror=false;
			

				rexa=photox2;
				reya=photoy2;
				reanglepluse=0;


		
			

			if((d1000_in_bit(pusherupin1)==0)&&((d1000_in_bit(pusherupin2)==0)||(repeat==0))&&(servostarted==0))
			{
			if((tempd!=0))
			{
			
			
				 d1000_start_ta_move( 3, photor+reanglepluse,0, vturnplate, 0.2);
     			  tempd=0;
			      
			 }//T形
	
			 if((tempa!=0))
			 {
				 d1000_start_ta_move( 0, rexa,0, vexx, 0.2);
     			  tempa=0;
			      
			 }//T形
			  if((tempb!=0))
			 {

				 d1000_start_ta_move( 1,reya, 0, vexy, 0.2);
				  tempb=0;
				  
				  display();
				  //display2();
			      
			 }//T形
			  servostarted=1;
			}

		   if((tempa!=0)&&(tempb!=0)&&(tempd!=0)&&(d1000_in_bit(servoxcoin)==0)
			   &&(d1000_in_bit(servoycoin)==0)&&(servostarted==1))//&&(d1000_in_bit(servorcoin)==0)
		   {   
				machinestate=state26; 
				throwcounter=throwcounter+1;
				servostarted=0;
				zstarted=0;
				times=0;
				mainstepp=false;
				mainstepm=false;
		
				
		   }
		
		

		   break;


       case state26:
	   
			     d1000_out_bit(pusherout2, front); 
				 d1000_out_bit(pusherout1 ,front); 
			            
				//if(d1000_in_bit(pusherdownin2)==0)
				{
				
			    machinestate=state27;
				servostarted=0;
				times=0;
				zstarted=0;
				 mainstepp=false;
				 mainstepm=false;
				}
		
			if(run==false)
				{
					stateinfo="贴合延时";
				}
			break;



       case state27:     

		  times=times+1;
		  	     d1000_out_bit(pusherout2, front); 
				 d1000_out_bit(pusherout1 ,front); 
		
           if(times>zvex)
		   {
			d1000_out_bit(flowout1, front);	
			d1000_out_bit(flowout2, front);	
		   
			d1000_out_bit( vacuumout1, back);
			d1000_out_bit( vacuumout2, back);
			}
			if(times>zvex)
			 
			{
				castcounter=castcounter+1;
				//totalcounter=pastecounter+castcounter;
				totalcounter=totalcounter+1;
				{
				 CFile counterfilenew;
				 counterfilenew.Open(counterfilename,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);
			     CArchive counterfilearnew(&counterfilenew,CArchive::store);
				 counterfilearnew<<pastecounter<<castcounter<<totalcounter;
				 counterfilearnew.Close();
				 counterfilenew.Close();
				}
				machinestate=state28;
				servostarted=0;
				times=0;
			}
			if(run==false)
				{
					stateinfo="抛弃";
				}
			break;



			   
		case state28:  
			d1000_out_bit(flowout1, back);	
	  	
			d1000_out_bit(pusherout1, back);
				d1000_out_bit(flowout2, back);	
	  	
			d1000_out_bit(pusherout2, back);
				
			if((d1000_in_bit(pusherupin1)==0)&&((d1000_in_bit(pusherupin2)==0)||(repeat==0)))
			{
			
					
				mainstepp=false;
				mainstepm=false;
			    disablefixturestepp=false;
			    wastetimes+=1;
				{machinestate=state3;}
				zstarted=0;
				servostarted=0;
				times=0;
				
			}
			if(run==false)
				{
					stateinfo="运行到取片";
				}
			break;






		case state30:
           	d1000_out_bit(pusherout1, back);
			d1000_out_bit(pusherout2, back);

			{
				tonguecanout=true;
				machinestate=state2p3;
				servostarted=0;
				times=0;
				mainstepp=false;
				mainstepm=false;
			}


			break;





	  default:
		  machinestate=state1;

	}

   }



 




  
  //状态切换，故障处理

 


    if(startcomm==true)
	{
		commcounter=commcounter+1;
      if(commcounter>50)
	  {
		smallproblem=true;
		linetimes=0;
		//	d1000_out_bit(backlinemotor, back);
		if(showerr[motorcommerr]==false)
		{
			showerr[motorcommerr]=true;
			m_problemlist.AddString(err[motorcommerr]);
		}
	  }
	}
//	else
	{commcounter=0;}

    if(d1000_in_bit(emergencyin)==1)
	{
		bigproblem=true;
			if(showerr[emergencyerr]==false)
		{
			showerr[emergencyerr]=true;
			m_problemlist.AddString(err[emergencyerr]);
		}
		

	}

	if((d1000_in_bit(servorready)==1)&&(d1000_get_outbit(servoenable)==front))
	{
		
		zerrortime=zerrortime+1;
		if(zerrortime>4)
		{
		bigproblem=true;
		zerrortime=0;

		if(showerr[zerr]==false)
		{
			showerr[zerr]=true;
			m_problemlist.AddString(err[zerr]);
		}
		}
	}else{zerrortime=0;}


    if((d1000_in_bit(servoxready)==1)&&(d1000_get_outbit(servoenable)==front))
	{
		
		servoxtime=servoxtime+1;
		if(servoxtime>100)
		{
		bigproblem=true;
		servoxtime=0;

		if(showerr[xerr]==false)
		{
			showerr[xerr]=true;
			m_problemlist.AddString(err[xerr]);
		}
		}
	}else{servoxtime=0;}

	  if((d1000_in_bit(servoyready)==1)&&(d1000_get_outbit(servoenable)==front))
	{
		
		servoytime=servoytime+1;
		if(servoytime>100)
		{
		bigproblem=true;
		servoytime=0;

		if(showerr[yerr]==false)
		{
			showerr[yerr]=true;
			m_problemlist.AddString(err[yerr]);
		}
		}
	}else{servoytime=0;}


   if((d1000_in_bit(pusherupin1)==1)&&(d1000_get_outbit(pusherout1)==back))
	{
		
		errtime[pusherup1err]=errtime[pusherup1err]+1;
		if(errtime[pusherup1err]>100)
		{
		smallproblem=true;
		errtime[pusherup1err]=0;

		if(showerr[pusherup1err]==false)
		{
			showerr[pusherup1err]=true;
			m_problemlist.AddString(err[pusherup1err]);
		}
		}
	}else{errtime[pusherup1err]=0;}

	/* if((d1000_in_bit(tapecheckin)==1))
	{
		
		errtime[tapeerr]=errtime[tapeerr]+1;
		if(errtime[tapeerr]>40)
		{
	
		errtime[tapeerr]=0;
		tapeerror=true;

		if(showerr[tapeerr]==false)
		{
			showerr[tapeerr]=true;
			m_problemlist.AddString(err[tapeerr]);
		}
		}
	}
	 else
	 {
		 tapeerror=false;
		 if(showerr[tapeerr]==true)
		{
			int sposition;
		    sposition=m_problemlist.SelectString(-1,err[tapeerr]);
			m_problemlist.DeleteString(sposition);
			showerr[tapeerr]=false;
		}
		 errtime[tapeerr]=0;
	 }*/

	
   if((d1000_in_bit(pusherdownin1)==1)&&(d1000_get_outbit(pusherout1)==front)&&(machinestate!=state27)&&(halfdown==false))
	{
		
		errtime[pusherdown1err]=errtime[pusherdown1err]+1;
		if(errtime[pusherdown1err]>100)
		{
		smallproblem=true;
		errtime[pusherdown1err]=0;

		if(showerr[pusherdown1err]==false)
		{
			showerr[pusherdown1err]=true;
			m_problemlist.AddString(err[pusherdown1err]);
		}
		}
	}else{errtime[pusherdown1err]=0;}

	   if((d1000_in_bit(pusherupin2)==1)&&(d1000_get_outbit(pusherout2)==back)&&(repeat==1))
	{
		
		errtime[pusherup2err]=errtime[pusherup2err]+1;
		if(errtime[pusherup2err]>100)
		{
		smallproblem=true;
		errtime[pusherup2err]=0;

		if(showerr[pusherup2err]==false)
		{
			showerr[pusherup2err]=true;
			m_problemlist.AddString(err[pusherup2err]);
		}
		}
	}else{errtime[pusherup2err]=0;}

	
   if((d1000_in_bit(pusherdownin2)==1)&&(d1000_get_outbit(pusherout2)==front)&&(machinestate!=state27)&&(halfdown==false))
	{
		
		errtime[pusherdown2err]=errtime[pusherdown2err]+1;
		if(errtime[pusherdown2err]>100)
		{
		smallproblem=true;
		errtime[pusherdown2err]=0;

		if(showerr[pusherdown2err]==false)
		{
			showerr[pusherdown2err]=true;
			m_problemlist.AddString(err[pusherdown2err]);
		}
		}
	}else{errtime[pusherdown2err]=0;}

	   if((d1000_in_bit(loadupin1)==1)&&(d1000_get_outbit(loadout1)==front))
	{
		
		errtime[loadup1err]=errtime[loadup1err]+1;
		if(errtime[loadup1err]>100)
		{
			loadstepp=false;
		smallproblem=true;
		errtime[loadup1err]=0;

		if(showerr[loadup1err]==false)
		{
			showerr[loadup1err]=true;
			m_problemlist.AddString(err[loadup1err]);
		}
		}
	}else{errtime[loadup1err]=0;}

	
   if((d1000_in_bit(loaddownin1)==1)&&(d1000_get_outbit(loadout1)==back))
	{
		
		errtime[loaddown1err]=errtime[loaddown1err]+1;
		if(errtime[loaddown1err]>100)
		{
			loadstepp=false;
		smallproblem=true;
		errtime[loaddown1err]=0;

		if(showerr[loaddown1err]==false)
		{
			showerr[loaddown1err]=true;
			m_problemlist.AddString(err[loaddown1err]);
		}
		}
	}else{errtime[loaddown1err]=0;}

		   if((d1000_in_bit(loadupin2)==1)&&(d1000_get_outbit(loadout2)==front))
	{
		
		errtime[loadup2err]=errtime[loadup2err]+1;
		if(errtime[loadup2err]>100)
		{
			loadstepp=false;
		smallproblem=true;
		errtime[loadup2err]=0;

		if(showerr[loadup2err]==false)
		{
			showerr[loadup2err]=true;
			m_problemlist.AddString(err[loadup2err]);
		}
		}
	}else{errtime[loadup2err]=0;}

	
   if((d1000_in_bit(loaddownin2)==1)&&(d1000_get_outbit(loadout2)==back))
	{
		
		errtime[loaddown2err]=errtime[loaddown2err]+1;
		if(errtime[loaddown2err]>100)
		{
			loadstepp=false;
		smallproblem=true;
		errtime[loaddown2err]=0;

		if(showerr[loaddown2err]==false)
		{
			showerr[loaddown2err]=true;
			m_problemlist.AddString(err[loaddown2err]);
		}
		}
	}else{errtime[loaddown2err]=0;}
	 

if(zpick==1)
{
	    if((d1000_in_bit(rightpressdownin)==1)&&(d1000_get_outbit(rightpress)==front))
	{
		
		errtime[rightpressdownerr]=errtime[rightpressdownerr]+1;
		if(errtime[rightpressdownerr]>100)
		{
			loadstepp=false;
		smallproblem=true;
		errtime[rightpressdownerr]=0;

		if(showerr[rightpressdownerr]==false)
		{
			showerr[rightpressdownerr]=true;
			m_problemlist.AddString(err[rightpressdownerr]);
		}
		}
	}else{errtime[rightpressdownerr]=0;}

	
   if((d1000_in_bit(rightpressupin)==1)&&(d1000_get_outbit(rightpress)==back))
	{
		
		errtime[rightpressuperr]=errtime[rightpressuperr]+1;
		if(errtime[rightpressuperr]>100)
		{
			loadstepp=false;
		smallproblem=true;
		errtime[rightpressuperr]=0;

		if(showerr[rightpressuperr]==false)
		{
			showerr[rightpressuperr]=true;
			m_problemlist.AddString(err[rightpressuperr]);
		}
		}
	}else{errtime[rightpressuperr]=0;}

}


if((zpick==2)||(zpick==3))
{
	    if((d1000_in_bit(rightpressupin)==1)&&(d1000_get_outbit(rightpress)==back))
	{
		
		errtime[cliperr]=errtime[cliperr]+1;
		if(errtime[cliperr]>100)
		{
			loadstepp=false;
		smallproblem=true;
		errtime[cliperr]=0;

		if(showerr[cliperr]==false)
		{
			showerr[cliperr]=true;
			m_problemlist.AddString(err[cliperr]);
		}
		}
	}else{errtime[cliperr]=0;}

	
   if((d1000_in_bit(rightpressdownin)==1)&&(d1000_get_outbit(rightpress2)==back))
	{
		
		errtime[turnerr]=errtime[turnerr]+1;
		if(errtime[turnerr]>100)
		{
			loadstepp=false;
		smallproblem=true;
		errtime[turnerr]=0;

		if(showerr[turnerr]==false)
		{
			showerr[turnerr]=true;
			m_problemlist.AddString(err[turnerr]);
		}
		}
	}else{errtime[turnerr]=0;}

}

	 if((((d1000_in_bit(vacuumin1)==1)&&(d1000_get_outbit(vacuumout1)==front))
		|| ((d1000_in_bit(vacuumin2)==1)&&(d1000_get_outbit(vacuumout2)==front)&&(repeat==1)))

		 &&(machinestate==state10)&&(vacuumerror==false))
	{
	  
	    //vacuumtime=vacuumtime+1;
	//	if(vacuumtime>3)
		 if(throwcounter>=zpush)
		 {
		   vacuumerror=true;
			smallproblem=true;
		 }
		//	tonguecanout=true;
	
        vacuumtime=0;
			machinestate=state25;
	

		if(showerr[vacuumerr]==false)
		{
			showerr[vacuumerr]=true;
			m_problemlist.AddString(err[vacuumerr]);
		}
		
	}
	// else
	// {vacuumtime=0;}

	 

  
	if(mainmotortime>350)
		{
		
			//d1000_out_bit(backlinemotor, back);
			mainmotortime=0;
       
		smallproblem=true;
		d1000_decel_stop(5);
	
		linetimes=0;
		linestart=false;
		firstlinestart=false;
		linecango=true;
	
		linestepp=false;
	

		if(showerr[mainmotorerr]==false)
		{
			showerr[mainmotorerr]=true;
			m_problemlist.AddString(err[mainmotorerr]);
		}
	}


	 if(linestate==linestate2p1)
	{
	  
	    tonguetime=tonguetime+1;
		if(tonguetime>900)
		{
        tonguetime=0;
		smallproblem=true;
		
			//d1000_out_bit(backlinemotor, back);
			d1000_decel_stop(4);
				linestate=linestate1;
				linestepp=false;
		tonguestarted=0;

		if(showerr[tongueerr]==false)
		{
			showerr[tongueerr]=true;
			m_problemlist.AddString(err[tongueerr]);
		}
		}
	}
	 else
	 {tonguetime=0;}

 if(wasteerror==true)
	{
	  
	 //d1000_out_bit(backlinemotor, back);
	    wasteerror=false;
        
		smallproblem=true;

		if(showerr[wasteerr]==false)
		{
			showerr[wasteerr]=true;
			m_problemlist.AddString(err[wasteerr]);
		}
		
	}


 if(d1000_in_bit(doorin)==1)
	{
	  
	 //d1000_out_bit(backlinemotor, back);
	    doortime=doortime+1;
		if(doortime>20)
		{
        doortime=0;
		smallproblem=true;

		if(showerr[doorerr]==false)
		{
			showerr[doorerr]=true;
			m_problemlist.AddString(err[doorerr]);
		}
		}
	}
	 else
	 {doortime=0;}


	  if(loselockfileerr==true)
	{
	  
	 //d1000_out_bit(backlinemotor, back);
	    
		
		smallproblem=true;

		if(showerr[loaduperr]==false)
		{
			showerr[loaduperr]=true;
			m_problemlist.AddString(err[loaduperr]);
		}
		
	}

	   if(passtimeerr==true)
	{
	  
	 //d1000_out_bit(backlinemotor, back);
	    
		
		smallproblem=true;

		if(showerr[unloaduperr]==false)
		{
			showerr[unloaduperr]=true;
			m_problemlist.AddString(err[unloaduperr]);
		}
		
	}

	   if(dateovererr==true)
	{
	  
	 //d1000_out_bit(backlinemotor, back);
	    
		
		smallproblem=true;

		if(showerr[fixtureouterr]==false)
		{
			showerr[fixtureouterr]=true;
			m_problemlist.AddString(err[fixtureouterr]);
		}
		
	}
 if(d1000_in_bit(pressin)==1)
	{
	  
	    presserrortime=presserrortime+1;
		if(presserrortime>20)
		{
        presserrortime=0;
		smallproblem=true;

		if(showerr[presserr]==false)
		{
			showerr[presserr]=true;
			m_problemlist.AddString(err[presserr]);
		}
		}
	}
	 else
	 {presserrortime=0;}

  if((fixturestate==fixturestate3)&&(d1000_in_bit(fixturevacuumin)==1))
	 	{
	  
	    errtime[leftfixtureerr]=errtime[leftfixtureerr]+1;
		if(errtime[leftfixtureerr]>100)
		{
        errtime[leftfixtureerr]=0;
		smallproblem=true;

		if(showerr[leftfixtureerr]==false)
		{
			showerr[leftfixtureerr]=true;
			m_problemlist.AddString(err[leftfixtureerr]);
		}
		}
	}
else
{errtime[leftfixtureerr]=0;}





 if(xoutofrange==true)
	{
	  if(throwcounter>=zpush)
		 {
		 smallproblem=true;
		 }
		 startphoto=0;
	    


		//smallproblem=true;
		xoutofrange=false;
		machinestate=state25;

		if(showerr[xoutofrangeerr]==false)
		{
			showerr[xoutofrangeerr]=true;
			m_problemlist.AddString(err[xoutofrangeerr]);
		}
		
	}
  if(loadvacuum1error==true)
	{
	  
	  
		
		loadvacuum1error=false;
		loadstepp=false;

		if(showerr[loadvacuum1err]==false)
		{
			showerr[loadvacuum1err]=true;
			m_problemlist.AddString(err[loadvacuum1err]);
		}
		
	}
    if(loadvacuum2error==true)//&&(firstload==false))
	{
	  
	  
	   loadstepp=false;
		loadvacuum2error=false;

		if(showerr[loadvacuum2err]==false)
		{
			showerr[loadvacuum2err]=true;
			m_problemlist.AddString(err[loadvacuum2err]);
		}
		
	}

  if(leftfixtureerror==true)
	{
	  
	  
		smallproblem=true;
		leftfixtureerror=false;

		if(showerr[leftfixtureerr]==false)
		{
			showerr[leftfixtureerr]=true;
			m_problemlist.AddString(err[leftfixtureerr]);
		}
		
	}
  if(rightfixtureerror==true)
	{
	  
	  
		smallproblem=true;
		rightfixtureerror=false;

		if(showerr[rightfixtureerr]==false)
		{
			showerr[rightfixtureerr]=true;
			m_problemlist.AddString(err[rightfixtureerr]);
		}
		
	}


 if(youtofrange==true)
	{
	  
	  
		smallproblem=true;
		youtofrange=false;
		machinestate=state25;

		if(showerr[youtofrangeerr]==false)
		{
			showerr[youtofrangeerr]=true;
			m_problemlist.AddString(err[youtofrangeerr]);
		}
		
	}
		

 if(routofrange==true)
	{
	 if(throwcounter>=zpush)
		 {
		 smallproblem=true;
		 }
		 startphoto=0;
	  
	  
		//smallproblem=true;
		routofrange=false;
		machinestate=state25;
		if(showerr[routofrangeerr]==false)
		{
			showerr[routofrangeerr]=true;
			m_problemlist.AddString(err[routofrangeerr]);
		}
		
	}
	

	 if(photoproblem==true)
	 {
		 if(throwcounter>=zpush)
		 {
		 smallproblem=true;
		 }
		 startphoto=0;
		 
		 
		if(showerr[cameraerr]==false)
		{
			showerr[cameraerr]=true;
			m_problemlist.AddString(err[cameraerr]);
		}
		photoproblem=false;
	 }
	 
	 if(photoproblem2==true)
	 {
		 smallproblem=true;
		 
		 
		 
		if(showerr[cameraerr2]==false)
		{
			showerr[cameraerr2]=true;
			m_problemlist.AddString(err[cameraerr2]);
			
		}
			photoproblem2=false;
	 }

     if(lastgodis==true)
	 {
		   lastover=false;
		   lastgodis=false;
           m_problemlist.ResetContent();
		   /*
           int position;
		   
		   position=m_problemlist.SelectString(-1 , "尾片中");
           m_problemlist.DeleteString(position);*/

	 }








	/*if((d1000_in_bit(curtenin)==1)&&((fixturestate==fixturestate2)|| (fixturestate==fixturestate5)||(machinestate==state11)||(machinestate==state10)))
	{
		if(showerr[curtenerr]==false)
		{
			m_problemlist.AddString(err[curtenerr]);
			showerr[curtenerr]=true;
		}
	}
    if(d1000_in_bit(curtenin)==0) 
	{
		if(showerr[curtenerr]==true)
		{
			int sposition;
		    sposition=m_problemlist.SelectString(-1,err[curtenerr]);
			m_problemlist.DeleteString(sposition);
			showerr[curtenerr]=false;
		}
	}
    
    if(d1000_in_bit(protectline)==1)
	{d1000_out_bit(frontlinemotor, back);}
    if((d1000_in_bit(protectline)==0)&&(bigproblem==false))
	{d1000_out_bit(frontlinemotor, front);}*/

    if(run==true)
	{GetDlgItem(IDC_DEBUG)->EnableWindow(false);}
	if(stop==true)
	{GetDlgItem(IDC_DEBUG)->EnableWindow(true);}



	if(bigproblem==true)
	{
		//轴运行停止
			upfinishedbool=false;
		linecango=false;
		lastone=false;
		lastgoon=false;
		lastover=false;
		lastgodis=false;
	    secondload=false;
		firstload=false;
	
		fixturefree=false;
		loadfinished=false;
		fixturecanphoto=false;

	    uphandstart=false;
        downhandstart=false;
        	downhand=downhand1;
			uphand=uphand1;
	    Rfixturepress=false;

        poweronok=false;
        d1000_decel_stop(0);
		d1000_decel_stop(1);
		d1000_decel_stop(2);
		d1000_decel_stop(3);
		d1000_decel_stop(4);
		d1000_decel_stop(5);
		d1000_decel_stop(6);
		d1000_decel_stop(7);

		fixturestate=fixturestate1;
		linestate=linestate1;
		machinestate=state1;
		placestate=placestate1;
		replacestate=replacestate1;
		pressstate=pressstate1;
		overturn=overturn1;
		d1000_out_bit(pusherout1, back);
		d1000_out_bit(pusherout2, back);
		d1000_out_bit(servoenable, back);
		d1000_out_bit(stepenable, front);
		d1000_out_bit(loadout1, back);
		d1000_out_bit(loadout2, back);
		d1000_out_bit(flowout1, back);
		d1000_out_bit(flowout2, back);
		d1000_out_bit(vacuumout1, back);
		d1000_out_bit(vacuumout2, back);
    	d1000_out_bit(loadvacuumout1, back);
		d1000_out_bit(loadvacuumout2, back);

		d1000_out_bit(fixturevacuumout, back);
		d1000_out_bit(upfinishedout, back);
		d1000_out_bit(downstartout, back);
	
	   	//d1000_out_bit(backlinemotor, back);
		if((zpick==0)||(zpick==1))
		{
	    d1000_out_bit(rightpress,back);
		d1000_out_bit(rightpress2,back);
		}
		
		

		//状态复位
 
		servostarted=0;
		tonguestarted=0;
    	mainstepp=false;
		loadstepp=false;
		reloadstepp=false;
		mainstepm=false;
		linestepp=false;
		linestepm=false;
		fixturestepp=false;
	    tapeready=false;
		halfready=false;
		tonguecanout=false;
		pastefinished=false;
		fixtureready=false;
		tonguehomed=false;
		placeok=false;
		times=0;
		photoverify=false;
		fixturetimes=0;
		linetimes=0;
		footup=0;
		footdown=0;
		footold=1;
		footnew=1;
	    
		Rfixturepress=false;
        presstimes=0;


	}

	

	 if((bigproblem==true)||(smallproblem==true)||(tapeerror==true))
	 {
		 	

			
			if(lighttime<30)
			{d1000_out_bit(alarmlightout, front);}
            if(lighttime>30)
			{
				d1000_out_bit(alarmlightout, back);
				
			}
			if(lighttime>60)
			{
				lighttime=0;
			}
			if((withbeep==1)&&(alarmtime<230))
			{
				d1000_out_bit(alarmbeepout, front);
			}
			if((withbeep==0)||(alarmtime>=230))
			{
				d1000_out_bit(alarmbeepout, back);
			}
			alarmtime=alarmtime+1;
            lighttime=lighttime+1;
			
	 }
	 else
	 {
		 alarmtime=0;
		 	d1000_out_bit(alarmlightout, back);
			d1000_out_bit(alarmbeepout, back);
	 }

	 

	
    if((bigproblem==true)||(smallproblem==true))
	{
		GetDlgItem(IDC_START)->EnableWindow(false);
		GetDlgItem(IDC_STOP)->EnableWindow(false);
		GetDlgItem(IDC_RESET)->EnableWindow(true);
		//if(linestepp==false)
		//{d1000_out_bit(backlinemotor, back);}
		run=false;
		stop=true;
	

	}

    if(run==true)
	{
		GetDlgItem(IDC_START)->EnableWindow(false);
		GetDlgItem(IDC_STOP)->EnableWindow(true);
		GetDlgItem(IDC_RESET)->EnableWindow(false);
	}
     if((stop==true)&&(bigproblem==false)&&(smallproblem==false))
	{
		GetDlgItem(IDC_START)->EnableWindow(true);
		GetDlgItem(IDC_STOP)->EnableWindow(false);
		GetDlgItem(IDC_RESET)->EnableWindow(false);
	
	}
    }
break;
	case 2:
    if(lock==false)
	{

	{
					CString timepath;
					timepath="d:\\install.shm";

					short pass_year,pass_month,pass_day,pass_hour,pass_minute,pass_second;
					pass_year=0;
					pass_month=0;
					pass_day=0;
					pass_hour=0;
					pass_minute=0;
					pass_second=0;
					if(GetFileAttributes(timepath)==-1)
					{
						loselockfileerr=true;
						lock=true;
					}
					else
					{
						 CFile counterfile;
						 counterfile.Open(timepath,CFile::modeRead);

						 CArchive counterfilear(&counterfile,CArchive::load);
						 
						
						 counterfilear>>pass_year>>pass_month>>pass_day>>pass_hour>>pass_minute>>pass_second;
						 counterfilear.Close();
						 counterfile.Close();
						 UpdateData(false);
						 SYSTEMTIME systime;
						 ::GetLocalTime(&systime);
						
						 if(systime.wYear<pass_year)
						 {
							 passtimeerr=true;
							 lock=true;
						 }
						 if(systime.wYear==pass_year)
						 {
							
							 if(systime.wMonth<pass_month)
							 {
								 passtimeerr=true;
								 lock=true;
							 }
							 if(systime.wMonth==pass_month)
							 {
								 
								 if(systime.wDay<pass_day)
								 {
									 passtimeerr=true;
									 lock=true;
								 }
								 if(systime.wDay==pass_day)
								 {
									 
									 if(systime.wHour<pass_hour)
									 {
										 passtimeerr=true;
										 lock=true;
									 }
								 }
							 }
						 }
						 
					}
	}



	{
					//CString timepath;
					//timepath="c:\\passtime.lock";
                         
					
						 
						 SYSTEMTIME systime;
						 ::GetLocalTime(&systime);

						 short pass_year,pass_month,pass_day,pass_hour,pass_minute,pass_second;
					pass_year=systime.wYear;
					pass_month=systime.wMonth;
					pass_day=systime.wDay;
					pass_hour=systime.wHour;
					pass_minute=systime.wMinute;
					pass_second=systime.wSecond;

						 if(systime.wYear>2019)
						 {	
							 dateovererr=true;
							 lock=true;
						 }
						
						 if(systime.wYear==2019)
						 {
							 if(systime.wMonth>2)
							 {
								 dateovererr=true;
								 lock=true;
							 }
							
							 if(systime.wMonth==2)
							 {
								 if(systime.wDay>20)
								 {
									 dateovererr=true;
									 lock=true;
								 }
								 
								 if(systime.wDay==20)
								 {
									 if(systime.wHour>=12)
									 {
										 dateovererr=true;
										 lock=true;
									 }
									 
								 }
							 }
						 }
						 
					
	}
     

    if(lock==false)
	{
	// TODO: Add your control notification handler code here
	short s_year,s_month,s_day,s_hour,s_minute,s_second;
    s_year=0;
	s_month=0;
	s_day=0;
	s_hour=0;
	s_minute=0;
	s_second=0;
	SYSTEMTIME systime;
	::GetLocalTime(&systime);
	s_year=systime.wYear;
	s_month=systime.wMonth;
	s_day=systime.wDay;
	s_hour=systime.wHour;
	s_minute=systime.wMinute;
	s_second=systime.wSecond;
	CString timepath;
	timepath="d:\\install.shm";

	CFile counterfilenew;
		 counterfilenew.Open(timepath,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);

	     CArchive counterfilearnew(&counterfilenew,CArchive::store);
		 
		
		 counterfilearnew<<s_year<<s_month<<s_day<<s_hour<<s_minute<<s_second;
		 counterfilearnew.Close();
		 counterfilenew.Close();
	}
    }



    
    break;
	}





	
	CDialog::OnTimer(nIDEvent);
}






void CVAFS2Dlg::OnStart() 
{
	// TODO: Add your control notification handler code here

	if((bigproblem==false)&&(smallproblem==false))
	{
		if(d1000_in_bit(doorin)==0)
		{
		run=true;
		stop=false;
		}
	}
	
}



void CVAFS2Dlg::OnStop() 
{
	// TODO: Add your control notification handler code here
	run=false;
	stop=true;
	
}

void CVAFS2Dlg::OnReset() 
{
	// TODO: Add your control notification handler code here
	smallproblem=false;
	bigproblem=false;
	linestarted=0;
	int i;
	for(i=0;i<50;i++)
	{
		showerr[i]=false;
		errtime[i]=0;
		
	}
	throwcounter=0;
	m_problemlist.ResetContent();
	photoproblem=false;
	photoproblem2=false;
	loadvacuum1error=false;
	loadvacuum2error=false;
	vacuumerror=false;
	tapeerror=false;
	leftanglebig=false;
    rightanglebig=false;
    leftpositionbig=false;
	rightpositionbig=false;

	servoxtime=0;
	servoytime=0;
	pusheruptime=0;
	pusherdowntime=0;
    rollertime=0;
	vacuumtime=0;
	mainmotortime=0;
	tonguetime=0;
	fixtureintime=0;
	tonguehometime=0;
	startcomm=false;
	commcounter=0;


	shapematch=0;
	//overphoto=0;
	//overphoto2=0;
	cyclephoto=false;
	cyclephoto2=false;
			
	    disablemainstepp=false;
		disableplacestepp=false;
	
	    disablelinestepp=false;
		
		disablefixturestepp=false;
	
	

	
}



void CVAFS2Dlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	
	//CDialog::OnClose();
}






mypoint CVAFS2Dlg::circle(mypoint point1,mypoint point2,mypoint point3)
{
	float x1,x2,x3;
	float y1,y2,y3;
    float tempa,tempb,tempc,tempd;

	mypoint center;
	x1=point1.x;
	x2=point2.x;
	x3=point3.x;
	y1=point1.y;
	y2=point2.y;
	y3=point3.y;
    
	tempa=(x2*x2+y2*y2-x1*x1-y1*y1)*(-2*x1+2*x3)-(-x1*x1-y1*y1+x3*x3+y3*y3)*(-2*x1+2*x2);

	tempb=(-2*y1+2*y2)*(-2*x1+2*x3)-(-2*y1+2*y3)*(-2*x1+2*x2);
	center.y=tempa/tempb;

	tempc=(x2*x2+y2*y2-x1*x1-y1*y1)*(-2*y1+2*y3)-(-x1*x1-y1*y1+x3*x3+y3*y3)*(-2*y1+2*y2);


	tempd=(-2*x1+2*x2)*(-2*y1+2*y3)-(-2*x1+2*x3)*(-2*y1+2*y2);
   
	center.x=tempc/tempd;
	return center;
}


void CVAFS2Dlg::BeginTime()
{
	QueryPerformanceFrequency( &m_Frequency );

	QueryPerformanceCounter( &m_BeginTime );
	

}

void CVAFS2Dlg::EndTime()
{
	QueryPerformanceCounter(&m_EndTime);
	double fTime = double(m_EndTime.LowPart-m_BeginTime.LowPart)/double(m_Frequency.LowPart);
	CString strTime;
	strTime.Format( "时间 %0.3f", fTime * 1000.0 );
	SetDlgItemText( IDC_time, strTime );
}


BEGIN_EVENTSINK_MAP(CVAFS2Dlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CVAFS2Dlg)
	ON_EVENT(CVAFS2Dlg, IDC_MSCOMM1, 1 /* OnComm */, OnOnCommMscomm1, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CVAFS2Dlg::OnOnCommMscomm1() 
{
	// TODO: Add your control notification handler code here

	 
		VARIANT m_input; 
		COleSafeArray safearray_inp;

		    

		
		int len,nEvent; 
		 
		nEvent = m_serial.GetCommEvent(); 
		switch(nEvent)  
		{  
		case 2:  
				len=m_serial.GetInBufferCount();     //接收缓冲区的字符数目
  
				//if(len>7) 
                if(len=8) 
				{  
					startcomm=false;
					 commok=true;
					  m_serial.SetInputLen(len); 
					  //读取接收到的数据 
					m_input=m_serial.GetInput(); 

					safearray_inp=m_input; //VARIANT型变量转换为ColeSafeArray型变量
					long i,j;
					j=safearray_inp.GetOneDimSize(); //得到有效数据长度
					if(j>20)
					{j=20;}
					for(i=0; i<j;i++)
						{
							safearray_inp.GetElement(&i,datain+i); //转换为BYTE型数组
						}

				}
				else
				{commok=false;}
                

				if((commok==true)&&(datain[7]==calcrc(datain,7)%256)&&(datain[8]==calcrc(datain,7)/256))
				{
					commok=false;

					 if((datain[0]==0)||(datain[0]==(comno)))
					 {
						if(datain[1]==3)
						{
							/*int alarmmark[50];
							memset(&alarmmark,0,sizeof(alarmmark));
							for(int i=0;i<49;i++)
							{
								if(showerr[i]==true)
								{
									alarmmark[i]=1;
								}

							}
							if(run==false)
								alarmmark[45]=1;
							    errchar[4]=0;

								errchar[3]=0;
								errchar[6]=0;
								errchar[5]=0;
								errchar[8]=0;
								errchar[7]=0;
                            int j=0;
							for(j=0;j<8;j++)
							{
								errchar[4]=errchar[4]+alarmmark[j]*pow(2,j);
								errchar[3]=errchar[3]+alarmmark[j+8]*pow(2,j);
								errchar[6]=errchar[6]+alarmmark[j+16]*pow(2,j);
								errchar[5]=errchar[5]+alarmmark[j+24]*pow(2,j);
								errchar[8]=errchar[8]+alarmmark[j+32]*pow(2,j);
								errchar[7]=errchar[7]+alarmmark[j+40]*pow(2,j);

							}
                   
							

							errchar[0]=(comno);
							errchar[1]=0x03;       
							errchar[2]=0x06;
							
					
							errchar[10]=calcrc(errchar, 9)/256;
							errchar[9]=calcrc(errchar,9)%256;
							i=50;
							sendtomotor(errchar,11);*/
							


							if(smallproblem==true)
						   {
							   errchar[4]=3;
						   }
						   else
						   {
							   if(run==true)
							   {
								   errchar[4]=1;//0x01
							   }
							   else
							   {
								   errchar[4]=2;
							   }
						   }

							errchar[0]=comno;
							errchar[1]=0x03;       
							errchar[2]=0x02;
							errchar[3]=0x00;
					
							errchar[6]=calcrc(errchar, 5)/256;
							errchar[5]=calcrc(errchar,5)%256;
							//i=50;
							sendtomotor(errchar,7);
						}





						  if(datain[1]==6)
						  {
							  if(datain[5]==0x01)
							  {
								  
								  OnReset();
								  OnStart();
								  

							  }
								if(datain[5]==0x02)
							  {
						  			run=false;
                        			stop=true;
								  

							  }
							 if(datain[5]==0x03)
							  {
								  bigproblem=true;
						  				if(showerr[emergencyerr]==false)
										{
		                        			showerr[emergencyerr]=true;
		                        			m_problemlist.AddString(err[emergencyerr]);
										}
  

							  }

							 if(datain[5]==0x04)
							 {
								 shieldpaste=1;
							 }
							  if(datain[5]==0x05)
							  {
								 shieldpaste=0;
							  }

							  if(datain[5]==0x06)
							  {
								 lastone=true;
								 m_problemlist.AddString("尾片中");
								
							  }




						  }







			
						  }    
					 }

				
			
				break;
		
		}
	//	m_serial.SetInputLen(0); 
      //  m_serial.GetInput(); 

	 /*	if(commok==true)
		{
			commok=false;

			 if((datain[0]==0)||(datain[0]==comno))
			 {
                if(datain[1]==3)
				{
					int alarmmark[50];
					memset(&alarmmark,0,sizeof(alarmmark));
					for(int i=1;i<50;i++)
					{
						if(showerr[i]==true)
						{
							alarmmark[i]=1;
						}

					}
					if(run==false)
						alarmmark[45]=1;

					for(int j=0;j<8;j++)
					{
						errchar[4]+=alarmmark[j]*(2^j);
						errchar[3]+=alarmmark[j+8]*(2^j);
						errchar[6]+=alarmmark[j+16]*(2^j);
						errchar[5]+=alarmmark[j+24]*(2^j);
						errchar[8]+=alarmmark[j+32]*(2^j);
						errchar[7]+=alarmmark[j+40]*(2^j);

					}
                   
					

                    errchar[0]=comno;
					errchar[1]=0x03;       
					errchar[2]=0x06;
					
			
					errchar[10]=calcrc(errchar, 9)/256;
					errchar[9]=calcrc(errchar,9)%256;
					i=50;
					sendtomotor(errchar,11);
					
				}





                  if(datain[1]==6)
				  {
					  if(datain[5]==0x01)
					  {
						  OnReset();
						  OnStart();
						  

					  }
					    if(datain[5]==0x02)
					  {
						  	run=false;
                        	stop=true;
						  

					  }
					 if(datain[5]==0x03)
					  {
						  bigproblem=true;
						  		if(showerr[emergencyerr]==false)
								{
		                        	showerr[emergencyerr]=true;
		                        	m_problemlist.AddString(err[emergencyerr]);
								}
  

					  }

					 if(datain[5]==0x04)
					 {
						 shieldpaste=1;
					 }
                      if(datain[5]==0x05)
					  {
						 shieldpaste=0;
					  }

					  if(datain[5]==0x06)
					  {
						 lastone=true;
						 m_problemlist.AddString("尾片中");
						
					  }




				  }







			
			 }    
		}*/

	
}


DWORD WINAPI Funline(
					 LPVOID lpParameter
					 )
{

   
while(true)
{

	/*QueryPerformanceCounter( &linenewTime );
	double delaytime;
	delaytime=double(linenewTime.LowPart-lineoldTime.LowPart)/double(m_Frequency.LowPart);
if(delaytime>0.02)*/
	Sleep(20);

lineoldTime=linenewTime;

 if((run==true)||(linestepp==true)||(linestepm==true))
  {

      /*
 switch(linestate)
	  {
		  
	  case linestate1:
		    d1000_out_bit( stepenable, back);
			
		  	linestate=linestate1p1;
			disablelinestepm=true;
			tonguestarted=0;
		
			break;

	 case linestate1p1:
		    
			tongueorgstate=d1000_get_axis_status(4);
		    tongueorgstate=tongueorgstate&0x00000004;
			
			tempe=d1000_check_done(4);
	

			if((tempe!=0)&&(tonguestarted==0)&&(tongueorgstate!=0))
			{
					d1000_start_t_move( 4,1000, 0, 1000, 0.3);
			}

           
			tonguestarted=1;
			tempe=d1000_check_done(4);

			
			if(tempe!=0)
			 {
	
				 linestate=linestate2;;
				 tonguestarted=0;
						
			 }
			break;  

	  case linestate2:
		     tempe=d1000_check_done(4);
			 if((tempe!=0)&&(tonguestarted==0))
			 {		    
		          d1000_home_move( 4, 0, -1000, 0.3);
				  tonguestarted=1;
			 }

			  
		     tempe=d1000_check_done(4);
		     
			 if(tempe==4)
			 {
				 d1000_set_command_pos(4,0);
				 linestate=linestate3;
			     tonguestarted=0;
			 }
		    
			break;

	  case linestate3:

		  
			tempe=d1000_check_done(4);
		    		     
			 if((tempe!=0)&&(tonguestarted==0))
			 {
				 d1000_start_ta_move( 4,tongueout, 0, vextongueout, 0.3);
			
				 tonguestarted=1;
				
			 }
			tempe=d1000_check_done(4);
			if((tempe!=0)&&(shieldpaste==0))
			 {
				//	 if(d1000_in_bit(jogin)==1)
				 {
				 linestate=linestate4;
				 }
				 //	 if(d1000_in_bit(jogin)==0)
				 //{
				 //linestate=linestate3p1;
				 //}
				// d1000_out_bit( lock, back);
				 tonguestarted=0;
				 linestepp=false;
				 linestepm=false;
				  mainmotorstarted=0;
				   mainmotortime=0;
			 }
			

			  break;

		case linestate3p1:
		   
		    tempf=d1000_check_done(5);
		    		     
			 if((tempf!=0)&&(mainmotorstarted==0))
			 {
				
			     d1000_start_t_move( 5,mainmotorlength, 0, vexmainmotorhigh, 0.3);
				 mainmotorstarted=1;
				 //d1000_out_bit(backlinemotor, front);
				
			 }
			tempf=d1000_check_done(5);
		    //d1000_out_bit(backlinemotor, front);
		
			  if((tempf!=0)&&(mainmotorstarted==1))//&&((lowspeedcango==true)||(linestepp==true)))
			 {
				
				 //if(d1000_in_bit(jogin)==1)
				 //{
				 //linestate=linestate3p1;
				 //}
				 //if(d1000_in_bit(jogin)==0)
				 {
				 linestate=linestate4;
				 }
				 mainmotorstarted=0;
				  linestepp=false;
				 linestepm=false;
				 //d1000_out_bit(backlinemotor, back);
			
				 mainmotortime=0;
				 
			 }
			  	
             break;



       case linestate4:
		    
             mainmotortime=mainmotortime+1;
	         tempf=d1000_check_done(5);
			 // d1000_out_bit(backlinemotor, front);
			 if(tempf==2)
			{mainmotorstarted=0;}
		    		     
			 if((tempf!=0)&&(mainmotorstarted==0))
			 {
				 d1000_home_move( 5, 0, vexmainmotorlow, 0.3);
			
				 mainmotorstarted=1;
				 tempf=0;
				
			 }
			tempf=d1000_check_done(5);
		    
		
			  if(tempf==4)
			 {
				   //d1000_out_bit(backlinemotor, back);
			    d1000_set_command_pos(5,0);
				 linestate=linestate5;
				 mainmotorstarted=0;
				 tapeready=1;
//				 disablemainstepm=false;
				 disablemainstepp=false;
				
				 linestepp=false;
				 linestepm=false;
				 disablelinestepp=true;
				 disablelinestepm=false;
			 }
			  

			  break;


	  case linestate5:
		   //d1000_out_bit(backlinemotor, back);
		    if((linestepp==true)||(run==true))
			{if(halfready==true)
			 {
		  
			 
				 
				 linestate=linestate6;
				 halfready=false;
			 }
			}
			if(linestepm==true)
			{
				linestate=linestate9;
				 mainmotorstarted=0;
				 tapeready=false;
				 
				 linestepm=false;
				 disablelinestepm=true;
				 disablelinestepp=false;

                   

			}
			

			  break;
	  
	  case linestate6:
		   //d1000_out_bit(backlinemotor, back);
		    disablelinestepm=true;
//		    disablemainstepm=true;
		   	tempe=d1000_check_done(4);
	    		     
			 if((tempe!=0)&&(tonguestarted==0))
			 {
				 d1000_start_ta_move( 4,tonguein, 0, vextonguein, 0.3);
			
				 tonguestarted=1;
				
			 }
			tempe=d1000_check_done(4);
		    
		
			  if(tempe==1)
			 {
                 tonguehomed=true;
				 disablemainstepp=false;
			
				
				 linestate=linestate7;
				 tonguestarted=0;
				  linestepp=false;
				 linestepm=false;
				 disablelinestepp=true;
			 }
			  if(run==false)
				{
					stateinfo="运行到拍照位置";
				}
			  	
			break;

	  case linestate7:

		    if(tonguecanout==true)
			{
				linestate=linestate8;
				tonguecanout=false;
			}
					  if(run==false)
				{
					stateinfo="等待舌头回";
					linestepp=false;
				}
		  
			 break;

	  case linestate8:
		  
			
			tempe=d1000_check_done(4);
		    		     
			 if((tempe!=0)&&(tonguestarted==0))
			 {
				 d1000_start_ta_move( 4,tongueout, 0, vextongueout, 0.3);
				 tempe=0;
				 tonguestarted=1;
				
			 }
			tempe=d1000_check_done(4);
		    
		
			  if(tempe!=0)
			 {
				
				 linestate=linestate9;
				 tonguestarted=0;
				 //d1000_out_bit( lock, back);
				  linestepp=false;
				 linestepm=false;
				 mainmotorstarted=0;
			 }
			  	
			
			  break;


       case linestate9:
		   
		    tempf=d1000_check_done(5);
		    		     
			 if((tempf!=0)&&(mainmotorstarted==0))
			 {
				
			     d1000_start_t_move( 5,mainmotorlength, 0, vexmainmotorhigh, 0.3);
				 mainmotorstarted=1;
				 //d1000_out_bit(backlinemotor, front);
				
			 }
			 //d1000_out_bit(backlinemotor, front);
			tempf=d1000_check_done(5);
		    
		
			  if((tempf!=0)&&(mainmotorstarted==1))//&&((lowspeedcango==true)||(linestepp==true)))
			 {
			//	 if(d1000_in_bit(jogin)==1)
				 {
				 linestate=linestate10;
				 }
			//	 if(d1000_in_bit(jogin)==0)
			//	 {
			//	 linestate=linestate9;
			//	 }
				 mainmotorstarted=0;
				  linestepp=false;
				 linestepm=false;
				 //d1000_out_bit(backlinemotor, back);
			
				 mainmotortime=0;
				 
			 }
			  	
             break;
			  
       case linestate10:
		   mainmotortime=mainmotortime+1;

            tempf=d1000_check_done(5);
			  //d1000_out_bit(backlinemotor, front);
			 if(tempf==2)
			{mainmotorstarted=0;}
		    		     
			 if((tempf!=0)&&(mainmotorstarted==0))
			 {
				 d1000_home_move( 5, 0, vexmainmotorlow, 0.3);
			
				 mainmotorstarted=1;
				 tempf=0;
				
			 }
			tempf=d1000_check_done(5);
		    
		
			  if(tempf==4)
			 {
                  //d1000_out_bit(backlinemotor, back);
                 
				 disablelinestepm=false;
				 d1000_set_command_pos(5,0);
				 linestate=linestate5;
				 mainmotorstarted=0;
				 tapeready=1;
				 disablemainstepp=false;
				 disablelinestepp=true;
				 
				  linestepp=false;
				 linestepm=false;
				  
				 
			 }
			  if(run==false)
				{
					stateinfo="等待取片";
				}

			break;

     
	  default:
		  linestate=linestate1;

	  
	}
         */

  }//end if




  /* switch(uphand)
	  {
		  
	  case uphand1:
		   d1000_out_bit(upfinishedout, back);
		        if(uphandstart==true)
					uphand=uphand2;
		   break;



	  case uphand2:
			   
		        if(upfinishedbool==true)
				{
				upfinishedbool=false;
				 uphand=uphand3;
				}

			  break;
    case uphand3:
			    d1000_out_bit(upfinishedout, front);
		        if(d1000_in_bit(upstartin)==1)

				 uphand=uphand4;

			  break;
	case uphand4:
			   			   
            d1000_out_bit(upfinishedout, back);
		    // if(d1000_get_outbit(upfinishedout)==back)

				 uphand=uphand5;

			  break;
	case uphand5:
			 d1000_out_bit(upfinishedout, back);
		     if(d1000_get_outbit(upfinishedout)==back) 
			 {
				uphandstart=false;

				uphand=uphand1;
			 }

			break;

	 default:
		 uphand=uphand1;
	  
}*/

  
/* switch(downhand)
	  {
		  
	  case downhand1:
		  
		        if(downhandstart==true)
					downhand=downhand2;
		   break;



	  case downhand2:
		  	d1000_out_bit(downstartout, front);
		     if(d1000_get_outbit(downstartout)==front)

				 downhand=downhand3;
			   
		       // if(d1000_get_outbit(upfinishedout)==front)

			  break;
    case downhand3:
		      d1000_out_bit(downstartout, front);
			   
		        if(d1000_in_bit(downfinishedin)==0)

				 downhand=downhand4;

			  break;
	case downhand4:
			   			   
            	d1000_out_bit(downstartout, back);
		     if(d1000_get_outbit(downstartout)==back)

				 downhand=downhand5;

			  break;
	case downhand5:
			   	d1000_out_bit(downstartout, back);
		        if(d1000_in_bit(downfinishedin)==1)

				 downhand=downhand6;

			  break;
	case downhand6:
						   
            downhandstart=false;

		downhand=downhand1;

			break;

	 default:
		 downhand=downhand1;
	  
}*/


  if((run==true)||(loadstepp==true)||(placestate==placestate8p2)||(placestate==placestate3))
 {

#if 0
 switch(placestate)
	  {
		  
	  case placestate1:
		         placetimes=placetimes+1;
				 	
						d1000_out_bit(fixturevacuumout, front);
						//d1000_out_bit(loadvacuumout1, front);
						//d1000_out_bit(loadvacuumout2, front);

				if(d1000_in_bit(fixturevacuumin)==0)
				{
							smallproblem=true;
							leftfixtureerror=true;
				}
					if(d1000_in_bit(loadvacuumin1)==0)
				{
							smallproblem=true;
							loadvacuum1error=true;
				}
				   if(d1000_in_bit(loadvacuumin2)==0)
				{
							smallproblem=true;
							loadvacuum2error=true;
				}

				

				if((d1000_in_bit(fixturevacuumin)==1)&&(d1000_in_bit(loadvacuumin1)==1)&&(d1000_in_bit(loadvacuumin2)==1)&&(placetimes>50))
				{
					placestate=placestate1p1;
					leftfixtureerror=false;
					placetimes=0;
				
				}
				
				
            	  if(run==false)

				{
					stateinfo="搬运单元复位";
				}
		    
				
				
				

		  
		   break;

	  case placestate1p1:
				placetimes=0;
				d1000_out_bit( stepenable, back); 
				d1000_out_bit(fixturevacuumout, back);
				d1000_out_bit(loadvacuumout1, back);
				d1000_out_bit(loadvacuumout2, back);
				
							 
				if((d1000_in_bit(loaddownin2)==0)&&(d1000_in_bit(loaddownin1)==0))

				 { 
						firstload=true;
						secondload=true;
					 placestate=placestate1p2;
					 turnarrowservostarted=0;
					 loadservostarted=0;
					 loadstepp=false;

					  placetimes=0;
				 }
	
			
		   break;

	case placestate1p2:
		 
		     loadorgstate=d1000_get_axis_status(6);
			 turnarroworgstate=d1000_get_axis_status(7);
			loadorgstate=loadorgstate&0x00000004;
			turnarroworgstate=turnarroworgstate&0x00000004;
			d1000_out_bit(fixturevacuumout, back);
			
			tempg=d1000_check_done(6);
		    temph=d1000_check_done(7);
		
	

			if((tempg!=0)&&(loadservostarted==0)&&(loadorgstate!=0))
			{
					d1000_start_t_move( 6,1000, 0, 1000, 0.3);
				
					tempg=0;
			}		
			if((temph!=0)&&(loadservostarted==0)&&(turnarroworgstate!=0))
			{
					d1000_start_t_move( 7,1000, 0, 1000, 0.3);
					
					temph=0;
			}

           loadservostarted=1;
			
			  if((tempg!=0)&&(temph!=0))
			 {
				  //turnarrowservostarted=0;
					 loadservostarted=0;
					 	 placestate=placestate2;
					 
					  placetimes=0;
			 }



		   	if(run==false)
				{
					stateinfo="搬运复位";
				}
			break;

		case placestate2:
		    tempg=d1000_check_done(6);
		    temph=d1000_check_done(7);
			d1000_out_bit(fixturevacuumout, back);
		
			if((tempg!=0)&&(loadservostarted==0))
			{
				d1000_home_move( 6, 0, -1000, 0.3);
			
			}
		if((temph!=0)&&(loadservostarted==0))
			{
				d1000_home_move( 7, 0, -1000, 0.3);
				loadservostarted=1;
			}
		    //d1000_out_bit(breakvacuumout, front);
		     tempg=d1000_check_done(6);
		     temph=d1000_check_done(7);
			 if((tempg==4)&&(temph==4))
			 {
				 
			     d1000_out_bit(loadvacuumout2, back);
				 d1000_set_command_pos(6,0);
				 d1000_set_command_pos(7,0);
				
			
				 	 
					 loadservostarted=0;
					 	 placestate=placestate3;
					 loadstepp=false;
					  placetimes=0;
			
				 if(run==false)
				{
					stateinfo="运行到等待位";
				}
			 }
			 
		    
			break;
	



	  case placestate3:
		  	d1000_out_bit(loadout2, back);
			d1000_out_bit(loadout1, back);
			
		     d1000_out_bit(upfinishedout, back);
		   
		    tempg=d1000_check_done(6);
			temph=d1000_check_done(7);
		
		 		
           if((temph!=0)&&(tempg!=0)&&(loadservostarted==0))//&&(d1000_in_bit(loaddownin2)==0)&&(d1000_in_bit(loaddownin1)==0))
			 
		   {
			   d1000_start_ta_move( 6,loadwaiting, 0, vload, 0.2);
			   d1000_start_ta_move( 7,reloadwaiting, 0, vload, 0.2);
		      loadservostarted=1;
		   }
	
			 tempg=d1000_check_done(6);
			 temph=d1000_check_done(7);
		
		
			  if((temph==1)&&(tempg==1)&&(loadservostarted==1))
			 {
		
					 loadservostarted=0;
					 placestate=placestate4;
					 if((run==false)&&(loadstepp==true))
					  {AfxMessageBox("确认搬运到取片位无碰撞！");}
		
					 loadstepp=false;
					  placetimes=0;
					 
			 }
			  if(run==false)
				{
					stateinfo="等待启动搬运";

				}

			  break;
		   
	  case placestate4:
		  
	      
		  
			 if(d1000_in_bit(upstartin)==0)
			 {placetimes=placetimes+1;}
			 else
			 {placetimes=0;}

			if((placetimes>=2)||(loadstepp==true))//&&(uphandstart==false))
			 {
			 
				     //uphandstart=true;
					 turnarrowservostarted=0;
					 loadservostarted=0;
					 placestate=placestate5;
					 loadstepp=false;
					  placetimes=0;
				  

			     if(run==false)
				{
					stateinfo="运行搬运取片";
				}
			
			 }
			  break;

			case placestate5:
		 
	
		 		   
		    tempg=d1000_check_done(6);
			temph=d1000_check_done(7);
		
		 		
           if((temph!=0)&&(tempg!=0)&&(loadservostarted==0)&&(d1000_in_bit(loaddownin2)==0)&&(d1000_in_bit(loaddownin1)==0))//zpick--press  start
			 
		   {
			   d1000_start_ta_move( 6,loadpick, 0, vload, 0.2);
			   d1000_start_ta_move( 7,reloadpick, 0, vload, 0.2);
		      loadservostarted=1;
		   }
	
			 tempg=d1000_check_done(6);
			 temph=d1000_check_done(7);
		
		    
		
			  if((temph!=0)&&(tempg!=0)&&(loadservostarted==1))//&&(d1000_get_command_pos( 1)<(pastey-4000))&&((pastefinished==true)||(firstload==true)||(shieldpaste==1)))
			 {
				
				  
				 	  turnarrowservostarted=0;
					 loadservostarted=0;
					 placestate=placestate6;
					 
					  placetimes=0;
			 }
			  loadstepp=false;
			  if(run==false)
				{
					stateinfo="启动搬运取片";
				}

			  break;

	
			case placestate6:
				if(Rfixturepress==false)
				{
						d1000_out_bit(loadout2, front);
						if(firstload==false)
						{
						d1000_out_bit(loadvacuumout1, front);
						}
						d1000_out_bit(loadout1, front);
				
						{d1000_out_bit(loadvacuumout2, front);}
						//d1000_out_bit(loadvacuumout2, front);
						
			
					 if((d1000_in_bit(loadupin2)==0)&&(d1000_in_bit(loadupin1)==0))
					 {
					
						  turnarrowservostarted=0;
							 loadservostarted=0;
							 placestate=placestate7;
							 
							  placetimes=0;
						  

						 if(run==false)
						{
							stateinfo="搬运取片";
						}
					
					 }
				}
			  break;


	  case placestate7:
		      
				{d1000_out_bit(loadvacuumout2, front);}
			 if(firstload==false)
			 {
				 d1000_out_bit(loadvacuumout1, front);
			 }
				placetimes=placetimes+1;
           	
			 if((placetimes>loadtime))
			 {
			
				  turnarrowservostarted=0;
					 loadservostarted=0;
					 placestate=placestate8;
					 
					  placetimes=0;
				  

			     if(run==false)
				{
					stateinfo="搬运取片";
				}
			
			 }
			  break;

			 case placestate8:
			
				 
		
			   if((((d1000_in_bit(loadvacuumin2)==0)||(lastone==true))&&((d1000_in_bit(loadvacuumin1)==0)||(firstload==true)))
				   ||(loadstepp==true))
			   {
				 
					 loadservostarted=0;
					 placestate=placestate8p0;
					 if((lastone==true)&&(d1000_in_bit(loadvacuumin2)==1))
					 {
						 lastone=false;
						 lastgoon=true;
						 
					 }
					 

					 
					  placetimes=0;
			   }
			   else
			   {
				   	if((d1000_in_bit(loadvacuumin2)==1)&&(lastone==false))
					{loadvacuum2error=true;}
					
					if((d1000_in_bit(loadvacuumin1)==1)&&(firstload==false))
					{loadvacuum1error=true;}
					 loadservostarted=0;
					 placestate=placestate20;
					
					  placetimes=0;
				   
			   }
              /*  if((d1000_in_bit(loadvacuumin2)==0)&&((firstload==true)&&(lastone==true)))
				{
					loadservostarted=0;
					 placestate=placestate8;
					 smallproblem=true;
					 leftfixtureerror=true;
					 loadstepp=false;
					  placetimes=0;
				}*/
			

				  

			     if(run==false)
				{
					stateinfo="搬运放片";
				}
			
			 
			  break;
		case placestate8p0:
                  if(((loadfinished==false)||(firstload==true)||(secondload==true))&&(d1000_get_outbit(upfinishedout)==back))
			   {
					  tempg=d1000_check_done(6);
		         	temph=d1000_check_done(7);
		 		
				   if((temph!=0)&&(tempg!=0)&&(loadservostarted==0))
					 
				   {
					   d1000_start_ta_move( 6,loadpush, 0, vload, 0.2);
					   d1000_start_ta_move( 7,reloadpush, 0, vload, 0.2);
					   d1000_out_bit(upfinishedout, front);
					  loadservostarted=1;
				   }
			
					 tempg=d1000_check_done(6);
					 temph=d1000_check_done(7);
				
				 
				
					  if((temph!=0)&&(tempg!=0)&&(loadservostarted==1))
					 {
				   			
							  d1000_out_bit(upfinishedout, front);
				 			  turnarrowservostarted=0;
							 loadservostarted=0;
							 placestate=placestate8p0p0;
							 
							  placetimes=0;
					 }
					  if(run==false)
						{
							stateinfo="等待放片";
						}

                  
			   }
			   else
			   {
				   placestate=placestate8p1;
			   }
			   break;

            case placestate8p0p0:
                 d1000_out_bit(upfinishedout, front);
		     if((d1000_get_outbit(upfinishedout)==front)&&(d1000_in_bit(upstartin)==1))
	
			 {
			        //upfinishedbool=true;
				 d1000_out_bit(upfinishedout, back);
					 loadservostarted=0;
					 placestate=placestate11;
					
					
					 loadstepp=false;
					  placetimes=0;
			 }
			  if(run==false)
				{
					stateinfo="等待下料完成";
				}






				break;
			case placestate8p1:
		
	
		   
		    tempg=d1000_check_done(6);
			temph=d1000_check_done(7);
		 	
			        
           if((temph!=0)&&(tempg!=0)&&(loadservostarted==0))
			 
		   {
               
			   d1000_start_ta_move( 6,loadwaiting, 0, vload, 0.2);
			   d1000_start_ta_move( 7,reloadwaiting, 0, vload, 0.2);
		      loadservostarted=1;
			  d1000_out_bit(upfinishedout, front);
			   
		   }
	
			 tempg=d1000_check_done(6);
			 temph=d1000_check_done(7);
            
		
		
		if((temph==1)&&(tempg==1)&&(loadservostarted==1))
			 {
		             //pastefinished=false;
                    
					 loadservostarted=0;
					 placestate=placestate8p2;
					if((run==false)&&(loadstepp==true))
					  {AfxMessageBox("确认搬运到放片位无碰撞！");}
					 loadstepp=false;
					  placetimes=0;
					   
			 }
			  if(run==false)
				{
					stateinfo="等待下料完成";
				}

			  break;

			
			  
		case placestate8p2:
		
		
			d1000_out_bit(upfinishedout, front);
		     if((d1000_get_outbit(upfinishedout)==front)&&(d1000_in_bit(upstartin)==1))
	
			 {
			        //upfinishedbool=true;
				 d1000_out_bit(upfinishedout, back);
					 loadservostarted=0;
					 placestate=placestate8p3;
					
					
					 loadstepp=false;
					  placetimes=0;
			 }
			  if(run==false)
				{
					stateinfo="等待下料完成";
				}

			  break;

	


			  	case placestate8p3:
		
		 
		d1000_out_bit(upfinishedout, back);
		if(((loadfinished==false)||(firstload==true)||(secondload==true))&&(d1000_get_outbit(upfinishedout)==back))//&&(d1000_get_command_pos( 1)<(pastey-4000))&&((pastefinished==true)||(firstload==true)||(shieldpaste==1)))
			 {
			      
			       

					 loadservostarted=0;
					 placestate=placestate9;
					
					 loadstepp=false;
					  placetimes=0;
			 }
			  if(run==false)
				{
					stateinfo="等待下料完成";
				}

			  break;

	



	case placestate9:
		 
	
		   
			
			
           tempg=d1000_check_done(6);
			temph=d1000_check_done(7);
		 		
           if((temph!=0)&&(tempg!=0)&&(loadservostarted==0))
			 
		   {
			   d1000_start_ta_move( 6,loadpush, 0, vload, 0.2);
			   d1000_start_ta_move( 7,reloadpush, 0, vload, 0.2);
		      loadservostarted=1;
		   }
	
			 tempg=d1000_check_done(6);
			 temph=d1000_check_done(7);
		
		 
		
			  if((temph!=0)&&(tempg!=0)&&(loadservostarted==1))
			 {
				   	
				      
				 	  turnarrowservostarted=0;
					 loadservostarted=0;
					 placestate=placestate11;
					 
					  placetimes=0;
			 }
			  if(run==false)
				{
					stateinfo="等待放片";
				}

			  break;

			 
	
	    
			  case placestate11:
				d1000_out_bit(loadout2, back);
					if(d1000_in_bit(loadupin2)==1)
					{d1000_out_bit(loadvacuumout2, back);}
				   d1000_out_bit(loadout1, back);
				  if(d1000_in_bit(loadupin1)==1)
				  { d1000_out_bit(loadvacuumout1, back);}

		      
	
			 if((d1000_in_bit(loaddownin2)==0)&&(d1000_in_bit(loaddownin1)==0))
			 {
				
			      if(firstload==false)
				  {loadfinished=true;}
				 
			      if((zpick==1)||(zpick==3))
				  {
					  Rfixturepress=true;
				  }
				  turnarrowservostarted=0;
					 loadservostarted=0;
					 placestate=placestate12p0;
					
					 
					  placetimes=0;
				  

			     if(run==false)
				{
					stateinfo="到等待位";
				}
			
			 }
			  break;

			  case placestate12p0:
                   d1000_out_bit(loadout2, back);
		        	d1000_out_bit(loadout1, back);
                    if(d1000_in_bit(upstartin)==0)
					{
						placestate=placestate14;
					}
					else
					{
						placestate=placestate12;
					}


				  break;

			case placestate12:
		  	d1000_out_bit(loadout2, back);
			d1000_out_bit(loadout1, back);
		    
		   
		    tempg=d1000_check_done(6);
			temph=d1000_check_done(7);
		
		 		
           if((temph!=0)&&(tempg!=0)&&(loadservostarted==0))//&&(d1000_in_bit(loaddownin2)==0)&&(d1000_in_bit(loaddownin1)==0))
			 
		   {
			   d1000_start_ta_move( 6,loadwaiting, 0, vload, 0.2);
			   d1000_start_ta_move( 7,reloadwaiting, 0, vload, 0.2);
		      loadservostarted=1;
		   }
	
			 tempg=d1000_check_done(6);
			 temph=d1000_check_done(7);
		     
			  if((temph==1)&&(tempg==1)&&(loadservostarted==1))
			 {
		
					 loadservostarted=0;
					
					 
					  placestate=placestate14;
					 
					 
					 if((run==false)&&(loadstepp==true))
					  {AfxMessageBox("确认搬运到取片位无碰撞！");}
		
					 loadstepp=false;
					  //placetimes=0;
					 
			 }
			  if(run==false)
				{
					stateinfo="等待启动搬运";

				}

			  break;

			  
	  case placestate13:
		
		 
		 if(d1000_in_bit(pressvacuumin)==1)
		 {
             placetimes+=1;
			 
		 }
		 else
		 {
			 placetimes=0;
			 placestate=placestate14;
             loadstepp=false;
		 }

		

			  break;

	 case placestate14:
		
	            if(firstload==false)
				{secondload=false;}
				firstload=false;
				 

				 
				 if(lastgoon==true)
				 {
					 lastgoon=false;
					 lastover=true;
					 //placestate=placestate15;
				 }
                  placestate=placestate4; 


			

			  break;

			  case placestate15:
		
	           if(downhandstart==false)
			   {
				 placestate=placestate16;
			   }
			

			  break;

			   case placestate16:
		
	           downhandstart=true;
			   firstload=true;
			   secondload=true;

			   run=false;
			   stop=true;
			   lastover=true;
				 placestate=placestate4;
			   
			

			  break;




		
		case placestate20:
		 
		 
		  
	
	
		  
			 {
				  
					if((d1000_in_bit(loadvacuumin2)==1)&&(lastone==false))
					{loadvacuum2error=true;}
					
					if((d1000_in_bit(loadvacuumin1)==1)&&(firstload==false))
					{loadvacuum1error=true;}
				
					d1000_out_bit(loadvacuumout2, back);
					d1000_out_bit(loadvacuumout1, back);	
					 loadservostarted=0;
					 placestate=placestate21;
					 
					  placetimes=0;
			 }
			  if(run==false)
				{
					stateinfo="取片失败";
				}

			  break;


		 
		 
		  
	
	
		  
		
	  case placestate21:
		  	d1000_out_bit(loadout2, back);
			d1000_out_bit(loadout1, back);
			
		 
		   
		    tempg=d1000_check_done(6);
			temph=d1000_check_done(7);
		
		 		
           if((temph!=0)&&(tempg!=0)&&(loadservostarted==0)&&(d1000_in_bit(loaddownin2)==0)&&(d1000_in_bit(loaddownin1)==0))
			 
		   {
			   
			   d1000_start_ta_move( 6,loadwaiting, 0, vload, 0.2);
			   d1000_start_ta_move( 7,reloadwaiting, 0, vload, 0.2);
		      loadservostarted=1;
			  smallproblem=true;
		   }
	
			 tempg=d1000_check_done(6);
			 temph=d1000_check_done(7);
		
		
			  if((temph==1)&&(tempg==1)&&(loadservostarted==1))
			 {
		
					 loadservostarted=0;

					 placestate=placestate4;
					 uphandstart=false;
					 uphand=uphand1;
				
					 loadstepp=false;
					  placetimes=0;
			 }
			  if(run==false)
				{
					stateinfo="等待启动搬运";
				}

			  break;
       

	  default:
		  placestate=placestate1;
	  
	}
#endif

  }	


if((run==true)||(reloadstepp==true))
{
    if((zpick==2)||(zpick==3))
	{
		switch(overturn)
		 {
			 case overturn1:

					 d1000_out_bit(rightpress, back);

					 if(d1000_in_bit(rightpressupin)==0)
					 {
						 presstimes=0;
						 overturn=overturn1p1;
						 reloadstepp=false;
					 }
			 break;

			 case overturn1p1:

				 d1000_out_bit(rightpress2, back);
				 d1000_out_bit(rightpress, back);

				 d1000_out_bit( stepenable, back); 

				 overturnplace=false;
				 reloadservostarted=0;
             
				 if(d1000_in_bit(rightpressdownin)==0)
				 {
					 overturn=overturn2;
					 presstimes=0;
					 reloadstepp=false;
				 }

				 if(run==false)
						{
							stateinfo="翻转使能";
						}
				 break;

			 case overturn2:

				updownorgstate=d1000_get_axis_status(2);
				updownorgstate=updownorgstate&0x00000004;
				
				tempc=d1000_check_done(2);
			
				if((tempc!=0)&&(reloadservostarted==0)&&(updownorgstate!=0))
				{
						d1000_start_t_move( 2,1000, 0, 1000, 0.3);
						reloadservostarted=1;
				}		
		
				tempc=d1000_check_done(2);

				if(tempc!=0)
				 {
						reloadservostarted=0; 
						overturn=overturn2p1;
						presstimes=0;
						reloadstepp=false;
				 }

		   		if(run==false)
					{
						stateinfo="翻转复位";
					}
				 break;

			 case overturn2p1:

				 tempc=d1000_check_done(2);

				if((tempc!=0)&&(reloadservostarted==0))
				{
					d1000_home_move( 2, 0, -1000, 0.3);
					reloadservostarted=1;
				}
				  
				tempc=d1000_check_done(2);

				if((tempc!=0)&&(reloadservostarted==1))
				 {
						d1000_set_command_pos(2,0);
						reloadservostarted=0; 
						overturn=overturn3;
						presstimes=0;
						reloadstepp=false;
                   
						if(run==false)
						{
							 stateinfo="运动到翻转起始位";
						}
				}

				break;

			 case overturn3:

				 tempc=d1000_check_done(2);
			
				if((tempc!=0)&&(reloadservostarted==0))
				{
					d1000_start_ta_move( 2,100, 0, zphoto, 0.2);
					reloadservostarted=1;
					overturnplace=true;
				}		
		
				tempc=d1000_check_done(2);

				if((tempc!=0)&&(reloadservostarted==1))
				 {
						reloadservostarted=0; 
						overturn=overturn3p1;
						presstimes=0;
						reloadstepp=false;
                   
						if(run==false)
						{
							 stateinfo="松开夹子";
						}
				}
                 break;
			 case overturn3p1:

					  d1000_out_bit(rightpress2, front);
					  d1000_out_bit(rightpress, front);
                  
					  presstimes=presstimes+1;

					  if(presstimes>10)
					  {
							reloadservostarted=0; 
							presstimes=0;
							reloadstepp=false;

							if(zpick==3)
							{
								  overturn=overturn4;
							}
							if(zpick==2)
							{
								  overturn=overturn3p2;
							}
                   
							if((run==false)&&(zpick==3))
							{
								stateinfo="等待夹紧料片";
							} 

							if(zpick==2)
							{
								stateinfo="翻转已屏蔽";
							}
					  }

					  break;
             case overturn3p2:

				 break;
			 case overturn4:

				if((Rfixturepress==true)||(reloadstepp==true))
				 {
					 if(lastgoon==true)
					 {
						 Rfixturepress=false;
						 overturn=overturn4;
					 }
					 else
					 {
						 d1000_out_bit(rightpress,back);
						 if(d1000_in_bit(rightpressupin)==0)
						 {
							  reloadservostarted=0; 
							  presstimes=0;
							  reloadstepp=false;
							  overturn=overturn5;
                          
							 if(run==false)
							{
								stateinfo="料片抬起";
							}
						 }
					 }
				 }

				break;

			 case overturn5:

				 d1000_out_bit(rightpress,back);
				 d1000_out_bit(rightpress2,back);

				 if(d1000_in_bit(rightpressdownin)==0)
				 {
							  reloadservostarted=0; 
							  presstimes=0;
							  reloadstepp=false;
							  overturn=overturn6;
									  
							if(run==false)
							{
								stateinfo="料片翻转";
							}
				 }

				 break;

			 case overturn6:

				 tempc=d1000_check_done(2);
			
				if((tempc!=0)&&(reloadservostarted==0))
				{
			 		reloadservostarted=1;

					if(overturnplace==false)
						{
							overturnplace=true;
							d1000_start_ta_move( 2,100, 0, zphoto, 0.2);
						}
					  else 
						{
							overturnplace=false;
							d1000_start_ta_move( 2,5120, 0, zphoto, 0.2);
						}

				}		
		
				tempc=d1000_check_done(2);

				if((tempc!=0)&&(reloadservostarted==1))
				 {
						reloadservostarted=0; 
						overturn=overturn7;
						presstimes=0;
						reloadstepp=false;
                   
						if(run==false)
						{
							 stateinfo="松开夹子";
						}
				}

				break;

			 case overturn7:

					  d1000_out_bit(rightpress2, front);
					  //d1000_out_bit(rightpress, front);
                  
					  presstimes=presstimes+1;

					  if(presstimes>20)
					  {
							reloadservostarted=0; 
							presstimes=0;
							overturn=overturn7p1;

					   if(run==false)
						{
							 stateinfo="等待夹紧料片";
						}
					  }
					  break;

			 case overturn7p1:

					  d1000_out_bit(rightpress2, front);
					  d1000_out_bit(rightpress, front);
                  
					  presstimes=presstimes+1;

					  if(presstimes>10)
					  {
							reloadservostarted=0; 
							presstimes=0;
							reloadstepp=false;
							Rfixturepress=false;
							overturn=overturn4;

					   if(run==false)
						{
							 stateinfo="等待夹紧料片";
						}

					  }
					  break;

			 default:
				 overturn=overturn1;

			}
		}
		


     if(zpick==1)
	 {
		 switch(pressstate)
		 {
			 
			 case pressstate1:
				 if(Rfixturepress==true)
				 {
					 if(lastgoon==true)
					 {
						 Rfixturepress=false;
						 pressstate=pressstate1;
					 }
					 else
					 {
						 d1000_out_bit(rightpress,front);
						 if(d1000_in_bit(rightpressdownin)==0)
						 {
						 presstimes+=1;
						 }
						 if(presstimes>zphoto)
						 {
							 d1000_out_bit(rightpress2,front);
							 pressstate=pressstate2;
							 presstimes=0;
							 reloadstepp=false;
						 }
					 }
				 }
				 break;
				 case pressstate2:
					 d1000_out_bit(rightpress2,front);
						 
						 presstimes+=1;
						 
						 if(presstimes>zphoto)
						 {
							 d1000_out_bit(rightpress2,back);
							 pressstate=pressstate3;
							 presstimes=0;
							 reloadstepp=false;
						 }
					 break;
				 case pressstate3:
					 d1000_out_bit(rightpress,back);
					 d1000_out_bit(rightpress2,back);
					 if(d1000_in_bit(rightpressupin)==0)
					 {
						 Rfixturepress=false;
						 pressstate=pressstate1;
					 }
					 reloadstepp=false;
					 break;
				 default:
				 pressstate=pressstate1;
		 }

	 }
	  
}		  
	  







	//return true;
}//end while

}//end api


DWORD WINAPI Funfixture(
					 LPVOID lpParameter
					 )
{

   
while(true)
{
/*	QueryPerformanceCounter( &fixturenewTime );
	double delaytime;
	delaytime=double(fixturenewTime.LowPart-fixtureoldTime.LowPart)/double(m_Frequency.LowPart);
if(delaytime>0.02)*/
	Sleep(20);

fixtureoldTime=fixturenewTime;
	if((run==true)||(fixturestepp==true)|| (fixturestate==fixturestate7)|| (fixturestate==fixturestate6)|| (fixturestate==fixturestate6p1))
 {

 switch(fixturestate)
	  {
		  
	  case fixturestate1:
		         fixturetimes=0;
		         fixtureservostarted=0;
				 fixturestate=fixturestate1p1;;
				
				

		  
		   break;

	  case fixturestate1p1:
				 fixturetimes=0;
		    
				 fixturestate=fixturestate1p2;
				   if(run==false)
				{
					stateinfo="等待贴合完成";
				}
			    
	
			
		   break;

	case fixturestate1p2:


			if((loadfinished==true)||(fixturestepp==true))
			 {
				
				//if(shieldpaste==0)
				{fixturestate=fixturestate3;}
				//else
					//{fixturestate=fixturestate6;}
				
				 

				 //loadfinished=false;
				 fixturetimes=0;
				

			 }
				   if(run==false)
				{
					stateinfo="等待贴合完成";
					fixturestepp=false;
				}
			    

			break;
	  case fixturestate3:
		  
	       
		  	d1000_out_bit(fixturevacuumout, front);
		    
		
			 
				 fixturetimes=fixturetimes+1;
			 if((fixturetimes>fixturedelaytime)&&((fixturecanphoto==true)||(shieldpaste==1))&&(d1000_in_bit(fixturevacuumin)==0))
			 {
				 if(shieldpaste==0)
				{fixturestate=fixturestate4;}
				else
					{fixturestate=fixturestate6;}
				 //fixturestate=fixturestate4;
				 fixturecanphoto=false;
				  fixturestepp=false;
				 fixturetimes=0;
				 overphoto2=0;
			     startphoto2=0;

			 }
				  if(run==false)
				{
					stateinfo="夹具等待拍照允许";
				}
		
			  break;

       case fixturestate4:
		 if(startphoto2==0)
		{
		 
         startphoto2=1;
		 imagephotoover2=false;
	     CameraPlay(camera2);
		
		}
		if(overphoto2==1)
		{
			if(photoalreadyproblem2==false)
			{

			    overphoto2=0;
		    	startphoto2=0;
		
				 fixturestate=fixturestate5;
				 fixturetimes=0;
				 fixtureready=true;
				 fixturestepp=false;
				 disablefixturestepp=true;
				 //if(machinestate==state12)
				 {disablemainstepp=false;}
			}

			else
			{
				overphoto2=0;
		    	startphoto2=0;
				 fixturecanphoto=true;
				 //loadfinished=true;
	          
	             photoalreadyproblem2=false;
				 
				 fixturestate=fixturestate1p2;
				 fixturetimes=0;
				 //fixtureready=true;
				 fixturestepp=false;

			}


				 
		 }

			  break;


	  case fixturestate5:

			 if((pastefinished==true)||(shieldpaste==1)&&(d1000_get_command_pos(1)<(pastey-4000)))

		     
			 {
				//if(fixturestepp==true)
				{pastefinished=false;}
				 fixturestate=fixturestate6;
				 d1000_out_bit(fixturevacuumout, back);

				 
				 fixturetimes=0;
			 
			 }
		    fixturestepp=false;
			break;

		case fixturestate6:
			d1000_out_bit(fixturevacuumout, back);
		
		

		     
			 {
			     d1000_out_bit(downstartout, front);
				 fixturestate=fixturestate6p1;
				
				 fixturetimes=0;
			 
			 }
		    
			break;

					case fixturestate6p1:
			d1000_out_bit(fixturevacuumout, back);
		    d1000_out_bit(downstartout, front);
		

		     if((d1000_get_outbit(downstartout)==front)&&(d1000_in_bit(downfinishedin)==0)||(fixturestepp==true))
			 {
				 fixturefree=true;
				 //loadfinished=false;
				 //downhandstart=true;
				 d1000_out_bit(downstartout, back);
				
				 loadfinished=false;
				 fixturestate=fixturestate7;
				
				 fixturetimes=0;
			 
			 }
		    
			break;

			
		case fixturestate7:
			d1000_out_bit(fixturevacuumout, back);
		    d1000_out_bit(downstartout, back);
             if((d1000_get_outbit(downstartout)==back)&&(d1000_in_bit(downfinishedin)==1))
			 {
			
				 //loadfinished=false;
				 fixturestate=fixturestate9;
				
				 fixturetimes=0;
			 
			 }
		    
			break;





	  case fixturestate9:
			     if((lastover==true)&&(fixtureservostarted==0))
				 {
					 lastover==false;
					 fixtureservostarted=1;
					 fixturestate=fixturestate10;
					 Sleep(100);
				 }
				 else
				 {
				     fixturestate=fixturestate1p2;
				 }
				 {disablereloadstepp=false;}
				 
				 fixturestepp=false;

			  break;
			  case fixturestate10:
				  fixtureservostarted=0;
			     d1000_out_bit(downstartout, front);
                 if(d1000_get_outbit(downstartout)==front)
				 {
					 fixturestate=fixturestate11;
				 }
			  break;
			  case fixturestate11:
				  d1000_out_bit(downstartout, front);
			     if((d1000_get_outbit(downstartout)==front)&&(d1000_in_bit(downfinishedin)==0))
					 {
				 fixturefree=true;
				 //loadfinished=false;
				 //downhandstart=true;
				 d1000_out_bit(downstartout, back);
				
				 
				 fixturestate=fixturestate12;
				
				 fixturetimes=0;
			 
				 }
			  break;
			  case fixturestate12:
			
					if((d1000_get_outbit(downstartout)==back)&&(d1000_in_bit(downfinishedin)==1))
			 {
		    	
				 loadfinished=false;
				 run=false;
	             stop=true;
				 firstload=true;
                 lastgodis=true;
				 fixturestate=fixturestate1p2;
				
				 fixturetimes=0;
			 
			 }
			  break;

	  default:
		  fixturestate=fixturestate1;
	  
	}

  
  }//for if

  }//for wile
  }//for api

void CVAFS2Dlg::Onlastone() 
{
	// TODO: Add your control notification handler code here
 lastone=true;
  m_problemlist.AddString("尾片中");
	
	
}

void CVAFS2Dlg::Oncounterzero1() 
{
	// TODO: Add your control notification handler code here
	pastecounter=0;
	//castcounter=0;
	//totalcounter=0;
}
void CVAFS2Dlg::Oncounterzero2() 
{
	// TODO: Add your control notification handler code here
	//pastecounter=0;
	castcounter=0;
	//totalcounter=0;
}

void CVAFS2Dlg::Oncounterzero3() 
{
	// TODO: Add your control notification handler code here
	//pastecounter=0;
	//castcounter=0;
	totalcounter=0;
}




BOOL CVAFS2Dlg::OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
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
			if((LOWORD(wParam))==IDC_XP)
			{
				//SetTimer( IDC_TIMER, 100, NULL );
			    positionxp=true;
			}
			if((LOWORD(wParam))==IDC_XM)
			{
			    //SetTimer( IDC_TIMER, 100, NULL );
				positionxm=true;	
			}

			if((LOWORD(wParam))==IDC_YP)
			{
				//SetTimer( IDC_TIMER, 100, NULL );
			    positionyp=true;
			}
			if((LOWORD(wParam))==IDC_YM)
			{
			    //SetTimer( IDC_TIMER, 100, NULL );
				positionym=true;	
			}

			if((LOWORD(wParam))==IDC_ANGLEP)
			{
				//SetTimer( IDC_TIMER, 100, NULL );
			    positionrp=true;
			}
			if((LOWORD(wParam))==IDC_ANGLEM)
			{
			    //SetTimer( IDC_TIMER, 100, NULL );
				positionrm=true;	
			}


			if((LOWORD(wParam))==IDC_XPm)
			{
				//SetTimer( IDC_TIMER, 100, NULL );
			    repositionxp=true;
			}
			if((LOWORD(wParam))==IDC_XMm)
			{
			    //SetTimer( IDC_TIMER, 100, NULL );
				repositionxm=true;	
			}

			if((LOWORD(wParam))==IDC_YPm)
			{
				//SetTimer( IDC_TIMER, 100, NULL );
			    repositionyp=true;
			}
			if((LOWORD(wParam))==IDC_YMm)
			{
			    //SetTimer( IDC_TIMER, 100, NULL );
				repositionym=true;	
			}

			if((LOWORD(wParam))==IDC_ANGLEPm)
			{
				//SetTimer( IDC_TIMER, 100, NULL );
			    repositionrp=true;
			}
			if((LOWORD(wParam))==IDC_ANGLEMm)
			{
			    //SetTimer( IDC_TIMER, 100, NULL );
				repositionrm=true;	
			}

			

			
            
		}

		else if((HIWORD(wParam))==WM_LBUTTONUP) // 按钮被鼠标左键抬起

		{
            if(positiontimes<20)
			{
				/*CPoint point;//定义一个用于确定光标位置的位置 
				GetCursorPos(&point);//获取当前光标的位置，以便使得菜单可以跟随光标  
				//ScreenToClient(&point);
				//得到窗体的控件句柄
				CWnd* hControlWnd = (CWnd*)WindowFromPoint(point);
				UINT nID = hControlWnd->GetDlgCtrlID();*/
				if((LOWORD(wParam))==IDC_XP)
				{
					
					//if( !UpdateData( TRUE ) ) return CDialog::OnWndMsg(message, wParam, lParam, pResult);
					if(	pastex<20000)
					{
					m_pastex=m_pastex+1;
						pastex=m_pastex;
						UpdateData( false );


						CFile currentpara;
						currentpara.Open(currentparametername,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);

						CArchive currentparaar(&currentpara,CArchive::store);
						currentparaar<<PARAINPUT;
    
						currentparaar.Close();
						currentpara.Close();
						positionxp=false;
						positionxm=false;
					}
				}
				if((LOWORD(wParam))==IDC_XM)
				{
			    		
					//if( !UpdateData( TRUE ) ) return CDialog::OnWndMsg(message, wParam, lParam, pResult);
					if(pastex>=0)
					{
					m_pastex=m_pastex-1;
						pastex=m_pastex;
						UpdateData( false );


						CFile currentpara;
						currentpara.Open(currentparametername,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);

						CArchive currentparaar(&currentpara,CArchive::store);
						currentparaar<<PARAINPUT;
    
						currentparaar.Close();
						currentpara.Close();
						positionxp=false;
						positionxm=false;
					}
				}

				if((LOWORD(wParam))==IDC_YP)
				{
					
					//if( !UpdateData( TRUE ) ) return CDialog::OnWndMsg(message, wParam, lParam, pResult);
					if(	pastey<48000)
					{	
					m_pastey=m_pastey+1;
						pastey=m_pastey;
						UpdateData( false );


						CFile currentpara;
						currentpara.Open(currentparametername,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);

						CArchive currentparaar(&currentpara,CArchive::store);
						currentparaar<<PARAINPUT;
    
						currentparaar.Close();
						currentpara.Close();
						positionyp=false;
						positionym=false;
					}
				}
				if((LOWORD(wParam))==IDC_YM)
				{
			    	
					//if( !UpdateData( TRUE ) ) return CDialog::OnWndMsg(message, wParam, lParam, pResult);
					if(	pastey>=0)
					{	
					m_pastey=m_pastey-1;
						pastey=m_pastey;
						UpdateData( false );


						CFile currentpara;
						currentpara.Open(currentparametername,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);

						CArchive currentparaar(&currentpara,CArchive::store);
						currentparaar<<PARAINPUT;
    
						currentparaar.Close();
						currentpara.Close();
						positionyp=false;
						positionym=false;
					}
				}
				
				if((LOWORD(wParam))==IDC_ANGLEP)
				{
					
					//if( !UpdateData( TRUE ) ) return CDialog::OnWndMsg(message, wParam, lParam, pResult);
						m_pasteangle=m_pasteangle+1;
						pasteangle=m_pasteangle;
						UpdateData( false );


						CFile currentpara;
						currentpara.Open(currentparametername,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);

						CArchive currentparaar(&currentpara,CArchive::store);
						currentparaar<<PARAINPUT;
    
						currentparaar.Close();
						currentpara.Close();
						positionrp=false;
						positionrm=false;
				}
				if((LOWORD(wParam))==IDC_ANGLEM)
				{
			    	
					//if( !UpdateData( TRUE ) ) return CDialog::OnWndMsg(message, wParam, lParam, pResult);
						m_pasteangle=m_pasteangle-1;
						pasteangle=m_pasteangle;
						UpdateData( false );


						CFile currentpara;
						currentpara.Open(currentparametername,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);

						CArchive currentparaar(&currentpara,CArchive::store);
						currentparaar<<PARAINPUT;
    
						currentparaar.Close();
						currentpara.Close();
						positionrp=false;
						positionrm=false;
				}

				////////////////////////////////////////////////////
				if((LOWORD(wParam))==IDC_XPm)
				{
					
					//if( !UpdateData( TRUE ) ) return CDialog::OnWndMsg(message, wParam, lParam, pResult);
					if(repastex<20000)
					{
					m_repastex=m_repastex+1;
						repastex=m_repastex;
						UpdateData( false );


						CFile currentpara;
						currentpara.Open(currentparametername,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);

						CArchive currentparaar(&currentpara,CArchive::store);
						currentparaar<<PARAINPUT;
    
						currentparaar.Close();
						currentpara.Close();
						repositionxp=false;
						repositionxm=false;
					}
				}
				if((LOWORD(wParam))==IDC_XMm)
				{
			    		
					//if( !UpdateData( TRUE ) ) return CDialog::OnWndMsg(message, wParam, lParam, pResult);
					if(repastex>=0)
					{
					m_repastex=m_repastex-1;
						repastex=m_repastex;
						UpdateData( false );


						CFile currentpara;
						currentpara.Open(currentparametername,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);

						CArchive currentparaar(&currentpara,CArchive::store);
						currentparaar<<PARAINPUT;
    
						currentparaar.Close();
						currentpara.Close();
						repositionxp=false;
						repositionxm=false;
					}
				}

				if((LOWORD(wParam))==IDC_YPm)
				{
					
					//if( !UpdateData( TRUE ) ) return CDialog::OnWndMsg(message, wParam, lParam, pResult);
					if(repastey<48000)
					{	
					m_repastey=m_repastey+1;
						repastey=m_repastey;
						UpdateData( false );


						CFile currentpara;
						currentpara.Open(currentparametername,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);

						CArchive currentparaar(&currentpara,CArchive::store);
						currentparaar<<PARAINPUT;
    
						currentparaar.Close();
						currentpara.Close();
						repositionyp=false;
						repositionym=false;
					}
				}
				if((LOWORD(wParam))==IDC_YMm)
				{
			    	
					//if( !UpdateData( TRUE ) ) return CDialog::OnWndMsg(message, wParam, lParam, pResult);
					if(repastey>=0)
					{	
					m_repastey=m_repastey-1;
						repastey=m_repastey;
						UpdateData( false );


						CFile currentpara;
						currentpara.Open(currentparametername,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);

						CArchive currentparaar(&currentpara,CArchive::store);
						currentparaar<<PARAINPUT;
    
						currentparaar.Close();
						currentpara.Close();
						repositionyp=false;
						repositionym=false;
					}
				}
				
				if((LOWORD(wParam))==IDC_ANGLEPm)
				{
					
					//if( !UpdateData( TRUE ) ) return CDialog::OnWndMsg(message, wParam, lParam, pResult);
						m_repasteangle=m_repasteangle+1;
						repasteangle=m_repasteangle;
						UpdateData( false );


						CFile currentpara;
						currentpara.Open(currentparametername,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);

						CArchive currentparaar(&currentpara,CArchive::store);
						currentparaar<<PARAINPUT;
    
						currentparaar.Close();
						currentpara.Close();
						repositionrp=false;
						repositionrm=false;
				}
				if((LOWORD(wParam))==IDC_ANGLEMm)
				{
			    	
					//if( !UpdateData( TRUE ) ) return CDialog::OnWndMsg(message, wParam, lParam, pResult);
						m_repasteangle=m_repasteangle-1;
						repasteangle=m_repasteangle;
						UpdateData( false );


						CFile currentpara;
						currentpara.Open(currentparametername,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);

						CArchive currentparaar(&currentpara,CArchive::store);
						currentparaar<<PARAINPUT;
    
						currentparaar.Close();
						currentpara.Close();
						repositionrp=false;
						repositionrm=false;
				}

				
			}
			else
			{
				
				positionxp=false;
				positionxm=false;
				positionyp=false;
				positionym=false;
				positionzp=false;
				positionzm=false;
				positionrp=false;
				positionrm=false;
				repositionxp=false;
				repositionxm=false;
				repositionyp=false;
				repositionym=false;
				repositionzp=false;
				repositionzm=false;
				repositionrp=false;
				repositionrm=false;
				CFile currentpara;
						currentpara.Open(currentparametername,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);

						CArchive currentparaar(&currentpara,CArchive::store);
						currentparaar<<PARAINPUT;
    
						currentparaar.Close();
						currentpara.Close();
						positionxp=false;
						positionxm=false;
				//d1000_immediate_stop(0);
			}
           
			positiontimes=0;
		}

		break;

	default:

		break;

	}
	return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}



void CVAFS2Dlg::MainIOdeal(int id, DWORD out)
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

/*	if(id==2101)
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
	}*/
}
