// VAFS2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "VAFS2.h"
#include "VAFS2Dlg.h"
#include "DebugDlg.h"
#include "glbs.h"
#include "login.h"
float showx,showy,showu,showz;
HTuple   HomMat2Dforinit;
//#include "formforrobot.h"
//void CVAFS2Dlg::m_spel_EventReceived(System::Object^  sender, RCAPINet::SpelEventArgs^ e)
//{
//	if (e->Event == SpelEvents::AllTasksStopped) 
//	{
//	
//		MessageBox::Show(e->Message);
//	}
//
//}
HTuple  CameraParameters, CameraPose;
bool robotfirstll=false;
bool withbeeptemp=false;
bool allowpick=false;
int llnRes=0;					
bool peelerror=false;
bool communicateerror=false;
bool clipready=false;
bool lloadvacuumerror=false;
bool lloaduperror=false;
bool lunloaduperror=false;
bool loadtrayerror=false;
bool notrayerror=false;
bool unloadtrayerror=false;
bool alltrayover=false;
bool unloadorgfinished=false;

bool xzorgfinished=false;
bool robotfirst=false;
bool robotlast=false;
bool     safeguardold=false;
bool loadalarm=false;
bool turnvacu1error=false;
bool turnvacu2error=false;
bool preturnvacu1error=false;
bool preturnvacu2error=false;

bool pdownvacuumerror=false;
bool filmover=true;
long currentfilms=0;
bool turnon=false;
long alarmtime=0;
bool fixtureempty=false;
int flx=0;
int fly=0;
bool picktray=false;
long specialstepx=0;
long specialfixturex=0;
float a1x, b2x, a1y, b2y;

bool beltstop=false;
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



float centery2temp,centerx2temp;
float centerytemp,centerxtemp;
float recentery2temp,recenterx2temp;
float recenterytemp,recenterxtemp;
int camera2counter=0;
float showtranskeyx,showtranskeyy;
float reshowtranskeyx,reshowtranskeyy;



bool vacuumerror=false;

int emptycounter=0;
float xa,ya;
float rexa,reya;
float newxa[6]={0,0,0};
float newya[6]={0,0,0};
float newrexa[6]={0,0,0};
float newreya[6]={0,0,0};
float gdnewxa[6]={-270,-190,-105};
float gdnewya[6]={318,318,318};
float gdnewanglepluse[3]={0,0,0};
float gdnewrexa[6]={-270,-190,-105};
float gdnewreya[6]={482,482,482};
float gdnewreanglepluse[3]={180,180,180};
int BYnum;

//bool firstbigproblem=false;
bool photoalreadyerror=false;

bool poweronok=false;

float rollerxlength,rollerylength;
float metalverifyx,metalverifyy;

CFont fontbig;
CFont fontsmall;
CFont fontsmaller;
int progress=0;
bool caculated=false;

float angle=0;
float angle2=0;
float angle21=0;
float angle22=0;
float reangle=0;
float reangle2=0;
float reangle21=0;
float reangle22=0;
float newangle1[6]={0,0,0};
float newangle2[6]={0,0,0};
float newreangle1[6]={0,0,0};
float newreangle2[6]={0,0,0};
float newanglepluse[6]={0,0,0};
float newreanglepluse[6]={0,0,0};
float anglepluse=0;
//int reanglepluse;
float firstrobotx,secondrobotx;
float firstroboty,secondroboty;
float firstcamerax,secondcamerax;
float firstcameray,secondcameray;
float camerax1,cameray1,camerax2,cameray2,servox1,servoy1,servox2,servoy2;
DWORD lxorgstate;
DWORD lzorgstate;
DWORD luporgstate;
DWORD ldownorgstate;
DWORD linorgstate;
DWORD loutorgstate;
DWORD llorgstate;
DWORD leftorgstate;
DWORD rightorgstate;
DWORD peelorgstate;
DWORD unloadorgstate;
DWORD loadorgstate,reloadorgstate,loadorgstater,loadorgstatez,reloadorgstatez,reloadorgstater;
DWORD temploadax,tempreloadax, temploadaxz,tempreloadaxz, temploadaxr,tempreloadaxr;

mypoint centera, centerb;
mypoint point1,point2,point3,point21,point22,point23;
HTuple   Rows1,Cols1;
HTuple   Rows2,Cols2;
HTuple   CountNum;


bool linecango=false;

int times=0;
int louttimes=0;
int vacuumcounter=0;

bool correctready=false;
int loadtimes;
bool outofrange=false;
int glassbuffer=0;
int buffertime=0;
int presstimes;
bool willlastone=false;
int currentposition=0;
bool firstload=false;
bool glassclearerror=false;
bool lastone=false;
bool canload=false;
bool canunload=false;
bool lastoneover=false;
unsigned char glassloop=0;
int fixturetimes;
int maintimes=0;
int lltimes=0;
int lefttimes=0;
int righttimes=0;
int peeltimes=0;
int doublecheckdelay=0;

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


int tonguehometime;
int fixtureerrtime=0;

int servoxtime;
int servoytime;
int zerrortime=0;
int presserrortime=0;
int pusheruptime;
int pusherdowntime;
int rollertime;
int vacuumtime;

float rekeypastex,rekeypastey;

int mainmotortime;

int fixtureintime;
//	int fixtureouttimeforerr;

bool fixtureoutofrange=false;
bool xoutofrange=false;
bool youtofrange=false;
bool routofrange=false;
bool photoproblem=false;
bool photoproblem2=false;

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
ON_BN_CLICKED(IDC_XP, OnXp)
ON_BN_CLICKED(IDC_XM, OnXm)
ON_BN_CLICKED(IDC_YP, OnYp)
ON_BN_CLICKED(IDC_YM, OnYm)
ON_BN_CLICKED(IDC_ANGLEP, OnAnglep)
ON_BN_CLICKED(IDC_ANGLEM, OnAnglem)
ON_BN_CLICKED(IDC_counterzero1, Oncounterzero1)
ON_BN_CLICKED(IDC_light, Onlight)
    //}}AFX_MSG_MAP
ON_BN_CLICKED(IDC_light2, &CVAFS2Dlg::OnBnClickedlight2)
ON_BN_CLICKED(IDC_BELT, &CVAFS2Dlg::OnBnClickedBelt)
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



    Sleep(100);

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


    currentregionsname1=currentdir+"\\current1.reg";
    currentregionsname2=currentdir+"\\current2.reg";
    currentregionsname3=currentdir+"\\current3.reg";
    currentregionsname4=currentdir+"\\current4.reg";

    currentparametername=currentdir+"\\current.para";
    currentmodelname=currentdir+"\\current.shm";
    currentmodelname2=currentdir+"\\current2.shm";
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


        counterfilearnew<<pastecounter;
        counterfilearnew.Close();
        counterfilenew.Close();
    }
    {
        CFile counterfile;
        counterfile.Open(counterfilename,CFile::modeRead);

        CArchive counterfilear(&counterfile,CArchive::load);


        counterfilear>>pastecounter;
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

    currentregionsname1=currentdir+"\\"+rcpname+"1.reg";
    currentregionsname2=currentdir+"\\"+rcpname+"2.reg";
    currentregionsname3=currentdir+"\\"+rcpname+"3.reg";
    currentregionsname4=currentdir+"\\"+rcpname+"4.reg";

    currentparametername=currentdir+"\\"+rcpname+".para";
    currentmodelname=currentdir+"\\"+rcpname+".shm";
    currentmodelname2=currentdir+"\\"+rcpname+"2.shm";
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
        currentphotoarnew<<shutter<<bright<<gain<<shutter2<<shutter3<<shutter4<<shutter5<<gain2<<contrast1<<contrast2<<model1x[0]<<model1x[1]<<model1x[2]<<model1x[3]<<model1x[4]<<model1x[5]<<model1y[0]<<model1y[1]<<model1y[2]<<model1y[3]<<model1y[4]<<model1y[5]<<model2x[0]<<model2x[1]<<model2x[2]<<model2x[3]<<model2x[4]<<model2x[5]<<model2y[0]<<model2y[1]<<model2y[2]<<model2y[3]<<model2y[4]<<model2y[5]
            <<model11halfx<<model11halfy<<model12halfx<<model12halfy<<model21halfx<<model21halfy<<model22halfx<<model22halfy<<modalorg11<<modalorg12<<modalorg21<<modalorg22
            <<remodel1x[0]<<remodel1x[1]<<remodel1x[2]<<remodel1x[3]<<remodel1x[4]<<remodel1x[5]<<remodel1y[0]<<remodel1y[1]<<remodel1y[2]<<remodel1y[3]<<remodel1y[4]<<remodel1y[5]<<remodel2x[0]<<remodel2x[1]<<remodel2x[2]<<remodel2x[3]<<remodel2x[4]<<remodel2x[5]<<remodel2y[0]<<remodel2y[1]<<remodel2y[2]<<remodel2y[3]<<remodel2y[4]<<remodel2y[5];
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
    currentphotoar>>shutter>>bright>>gain>>shutter2>>shutter3>>shutter4>>shutter5>>gain2>>contrast1>>contrast2>>model1x[0]>>model1x[1]>>model1x[2]>>model1x[3]>>model1x[4]>>model1x[5]>>model1y[0]>>model1y[1]>>model1y[2]>>model1y[3]>>model1y[4]>>model1y[5]>>model2x[0]>>model2x[1]>>model2x[2]>>model2x[3]>>model2x[4]>>model2x[5]>>model2y[0]>>model2y[1]>>model2y[2]>>model2y[3]>>model2y[4]>>model2y[5]
        >>model11halfx>>model11halfy>>model12halfx>>model12halfy>>model21halfx>>model21halfy>>model22halfx>>model22halfy>>modalorg11>>modalorg12>>modalorg21>>modalorg22
        >>remodel1x[0]>>remodel1x[1]>>remodel1x[2]>>remodel1x[3]>>remodel1x[4]>>remodel1x[5]>>remodel1y[0]>>remodel1y[1]>>remodel1y[2]>>remodel1y[3]>>remodel1y[4]>>remodel1y[5]>>remodel2x[0]>>remodel2x[1]>>remodel2x[2]>>remodel2x[3]>>remodel2x[4]>>remodel2x[5]>>remodel2y[0]>>remodel2y[1]>>remodel2y[2]>>remodel2y[3]>>remodel2y[4]>>remodel2y[5];
    currentphotoar.Close();
    currentphoto.Close();









    fontbig.CreatePointFont(240,"黑体",NULL);
    m_start.SetFont(&fontbig);
    m_stop.SetFont(&fontbig);
    m_reset.SetFont(&fontbig);
    m_debug.SetFont(&fontbig);


    fontsmall.CreatePointFont(160,"黑体",NULL);
    fontsmaller.CreatePointFont(120,"宋体",NULL);

    m_problemlist.SetFont(&fontsmall);
    m_list1.SetFont(&fontsmaller);
    m_list2.SetFont(&fontsmaller);

    CWnd *cwnd=GetDlgItem(IDC_STATICminder);
    cwnd->SetFont(&fontsmall);

    cwnd=GetDlgItem(IDC_STATICcounter);
    cwnd->SetFont(&fontsmall);

    cwnd=GetDlgItem(IDC_PASTECOUNTER);
    cwnd->SetFont(&fontsmall);
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



    m_XP.SetFont(&fontsmall);
    m_XM.SetFont(&fontsmall);
    m_YP.SetFont(&fontsmall);
    m_YM.SetFont(&fontsmall);
    m_pasteanglep.SetFont(&fontsmall);
    m_pasteanglem.SetFont(&fontsmall);






    cwnd=GetDlgItem(IDC_dot1);
    cwnd->SetFont(&fontsmall);
    cwnd=GetDlgItem(IDC_dot2);
    cwnd->SetFont(&fontsmall);

    CString currentexe;
    currentexe=currentdir+"\\Release\\vafs2.exe";
    WritePrivateProfileString(_T("windows"),_T("run"),currentexe,_T("c:/windows/win.ini"));
    m_pastex=pastex;
    m_pastey=pastey;

    m_pasteangle=pasteangle;




    /* m_serial.SetCommPort(1); //选择串4?

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
       m_serial.GetInput(); */

    int nCard(0);
    nCard = d1000_board_init();
    if( nCard <= 0 )//控制卡初始化
        MessageBox("未找到控制卡1000!","警告");
    d1000_set_sd(0,0);
    d1000_set_pls_outmode(0,1);

    d1000_set_sd(1,0);
    d1000_set_pls_outmode(1,1);

    d1000_set_sd(2,0);
    d1000_set_pls_outmode(2,1);

    d1000_set_sd(3,0);
    d1000_set_pls_outmode(3,1);

    // d1000_set_sd(4,0);
    //d1000_set_pls_outmode(4,1);

    //d1000_set_sd(5,0);
    //d1000_set_pls_outmode(5,1);

    //d1000_set_sd(6,0);
    //d1000_set_pls_outmode(6,1);

    //d1000_set_sd(7,0);
    //d1000_set_pls_outmode(7,1);

    WORD My_CardNum ;      //定义卡数
    WORD My_CardList[8];   //定义卡号数组
    DWORD My_CardTypeList[8];   //定义各卡类型

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


        //CameraSetWBWindow(camera1,0,0,4384,3288);
        //CameraSetRotation(camera1,2);
        CameraSetOnceWB(camera1);
        //	CameraSetRotation(camera1,2);
        //CameraSetOnceWB(camera2);

        //CameraSetRotation(camera1,1);
        CameraSetMirror(camera1,MIRROR_DIRECTION_VERTICAL,true);
        CameraSetMirror(camera1,MIRROR_DIRECTION_HORIZONTAL,true);



        InitDeviceFunction();


    }






    // LINETHREAD=CreateThread(NULL,0,Funline,NULL,0,NULL);
    FIXTURETHREAD=CreateThread(NULL,0,Funfixture,NULL,0,NULL);
    QueryPerformanceFrequency( &m_Frequency );



    m_list1.SetExtendedStyle( 0x22 );
    m_list1.InsertColumn( 0, "编号", LVCFMT_LEFT, 50 );
    m_list1.InsertColumn( 1, "相似度", LVCFMT_LEFT, 80 );
    m_list1.InsertColumn( 2, "角度", LVCFMT_LEFT, 100 );
    //	m_list1.InsertColumn( 3, "比例", LVCFMT_LEFT, 60 );
    m_list1.InsertColumn( 3, "中心x", LVCFMT_LEFT, 100);
    m_list1.InsertColumn( 4, "中心y", LVCFMT_LEFT, 120 );
    //m_list1.InsertColumn( 6, "X", LVCFMT_LEFT, 120 );
    //m_list1.InsertColumn( 7, "Y", LVCFMT_LEFT, 120 );
    //m_list1.InsertColumn( 8, "U", LVCFMT_LEFT, 120 );


    //	m_list2.SetExtendedStyle( 0x22 );
    ////	m_list1.InsertColumn( 0, "编号", LVCFMT_LEFT, 50 );
    //	m_list2.InsertColumn( 1, "相似度", LVCFMT_LEFT, 80 );
    //	m_list2.InsertColumn( 2, "角度", LVCFMT_LEFT, 100 );
    ////	m_list1.InsertColumn( 3, "比例", LVCFMT_LEFT, 60 );
    //	m_list2.InsertColumn( 4, "中心x", LVCFMT_LEFT, 100);
    //	m_list2.InsertColumn( 5, "中心y", LVCFMT_LEFT, 120 );

    SetTimer( 1, 10, NULL );




    //initdio();

    ShowWindow(SW_SHOWMAXIMIZED);




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

    OnLoadModel();
    try
    {
        //	gen_image_const(&Image1,"byte",1000,1000);
        HTuple mtxdir;
        CString tempC,tempA;
        char temps[100];
        tempC=currentdir+"\\1.mtx";
        strcpy(temps,tempC);
        mtxdir[0]=temps;
        tempA=mtxdir[0].S();

        read_tuple(mtxdir,&HomMat2Dforinit);
        //read_tuple("C:/1.mtx",&HomMat2Dforinit);
        read_image(&Image1,"1.bmp");//test count
        read_image(&Image2,"1.bmp");
        //	gen_image_const(&Image2,"byte",1000,1000);//ReadImage("1.bmp");
        disp_image(Image1,m_Windowid);
        disp_image(Image2,m_Window2id);

        //  set_color(m_Window2id,"red");

        //disp_cross(m_Window2id,keypastey,keypastex,80,0);

        //OnLoadModel(); 
        set_shape_model_param(ShapeModel11,"timeout",3500);
        set_shape_model_param(ShapeModel12,"timeout",3500);
        set_shape_model_param(ShapeModel21,"timeout",3500);
        set_shape_model_param(ShapeModel22,"timeout",3500);

    }
    catch (HException &except)
    {	
        Herror error_num;
        error_num= except.err;
        //MessageBox(error_num);


    }


    shieldpaste=0;
    /////////////////////////C4ROBOT
    d1000_out_bit(robotemergencyout,front);
    if (!C4pSocket.Create())
    {
        C4pSocket.Close();	
        MessageBox(_T("Create socket failed!"));

    }

    CString strIP = _T("192.168.0.1");
    int  nPort = 5000;

    while(!C4pSocket.Connect(strIP,nPort))
    {
        if(AfxMessageBox("TCP ERROR",MB_YESNO)==IDYES)
        {

            C4pSocket.Close();


        }
    }

    CString tempstr = _T("$login,a\r\n");
    C4TcpSend(tempstr);
    CString tempstr1 = _T("$reset\r\n");
    C4TcpSend(tempstr1);
    CString tempstr2;
    tempstr2.Format("$execute,\"speedpara=%d;speedSpara=%d\"\r\n",vexy,vturnplate);
    C4TcpSend(tempstr2);
    C4commerror=false;
    //if (!C4pSocket.Create())
    //{
    //	C4pSocket.Close();	
    //	MessageBox(_T("Create socket failed!"));
    //	return FALSE;
    //}

    //CString strIP = _T("192.168.0.1");
    //int  nPort = 5000;
    //	
    //while(!C4pSocket.Connect(strIP,nPort))
    //{
    //	if(AfxMessageBox("TCP ERROR",MB_YESNO)==IDYES)
    //	{
    //		
    //		C4pSocket.Close();
    //		//return TRUE; 
    //		
    //	}
    //}

    //CString tempstr = _T("$login,a\r\n");
    //C4TcpSend(tempstr);
    //CString tempstr1 = _T("$reset\r\n");
    //C4TcpSend(tempstr1);
    //CString tempstr2;
    //tempstr2.Format("$execute,\"speedpara=%d;speedSpara=%d\"\r\n",vexy,vturnplate);
    //C4TcpSend(tempstr2);


    //tempstr.Format("$execute,\"jogP(0)=%0.3f;jogP(1)=%0.3f;jogP(2)=%0.3f;jogP(3)=%0.3f\"\r\n",C4cpx,jog,C4cpz,C4cpu);	

    //float pra[10],pose[10];
    {
        HTuple mtxdir;
        CString tempC,tempA;
        char temps[100];
        tempC=currentdir+"\\campar.dat";
        strcpy(temps,tempC);
        mtxdir[0]=temps;
        tempA=mtxdir[0].S();

        CameraParameters.Reset();
        read_cam_par(mtxdir,&CameraParameters);
        //read_cam_par("D:\campar.dat",&CameraParameters);
    }
    //CameraParameters[0] = 0.0160121;
    //CameraParameters[1] = -301.001;
    //CameraParameters[2] = 2.2006e-006;
    //CameraParameters[3] = 2.2e-006;
    //CameraParameters[4] = 1295.87;
    //CameraParameters[5] = 972.047;
    //CameraParameters[6] = 2592;
    //CameraParameters[7] = 1944;
    {
        HTuple mtxdir;
        CString tempC,tempA;
        char temps[100];
        tempC=currentdir+"\\campose.dat";
        strcpy(temps,tempC);
        mtxdir[0]=temps;
        tempA=mtxdir[0].S();

        CameraPose.Reset();
        read_pose(mtxdir,&CameraPose);
    }

    //CameraPose[0] = 0.00540923;
    //CameraPose[1] = -0.00833837;
    //CameraPose[2] = 1.01848;
    //CameraPose[3] = 0.114074;
    //CameraPose[4] = 359.491;
    //CameraPose[5] = 358.874;
    //CameraPose[6] = 0;

    BYnum=0;
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
    // Now, it must be checked whether the CListener object has been unregistered
    // for all events.

    CameraStop(camera1);
    CameraUnInit(camera1);

    //   CameraStop(camera2);
    //CameraUnInit(camera2);

    KillTimer(1);

    {
        CFile counterfilenew;
        counterfilenew.Open(counterfilename,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);

        CArchive counterfilearnew(&counterfilenew,CArchive::store);


        counterfilearnew<<pastecounter;
        counterfilearnew.Close();
        counterfilenew.Close();
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

    //   CameraSetAeState(camera2, FALSE);
    //      CameraSetExposureTime(camera2, shutter3*10000);
    // 	
    //CameraSetAnalogGain(camera2,gain2);
    CameraSetContrast(camera1, contrast1);
    //CameraSetContrast(camera2, contrast2);




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
        debugcase=true;
        CDebugDlg dlg;
        dlg.DoModal();

        CString tempstr2;
        tempstr2.Format("$execute,\"speedpara=%d;speedSpara=%d\"\r\n",vexy,vturnplate);
        C4TcpSend(tempstr2);

        debugcase=false;
        set_part_style(m_Windowid,0);
        //	set_part_style(m_Window2id,0);
        InitDeviceFunction();
        OnLoadModel(); 
        zoomfactor=1;
        zoomupdown=0;
        zoomleftright=0;
        set_part(m_Windowid,0,0,camera1width,camera1height);
        //set_part(m_Window2id,0,0,camera2width,camera2height);

        m_pastex=pastex;
        m_pastey=pastey;
        m_pasteangle=pasteangle;
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
            read_region(&Regions1,currentregionsname1);

        }
        catch (HException &except)
        {
            error_num = except.err;
            AfxMessageBox("读Regions1失败！");
            return;
        }
    }
    {
        Herror error_num;

        try
        { 
            read_region(&Regions2,currentregionsname2);

        }
        catch (HException &except)
        {
            error_num = except.err;
            AfxMessageBox("读Regions2失败！");
            return;
        }
    }
    {
        Herror error_num;

        try
        { 
            read_region(&Regions3,currentregionsname3);

        }
        catch (HException &except)
        {
            error_num = except.err;
            AfxMessageBox("读Regions3失败！");
            return;
        }
    }
    {
        Herror error_num;

        try
        { 
            read_region(&Regions4,currentregionsname4);

        }
        catch (HException &except)
        {
            error_num = except.err;
            AfxMessageBox("读Regions4失败！");
            return;
        }
    }

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
    memset(newmatchscore1,0,sizeof(newmatchscore1));
    memset(newmatchscore2,0,sizeof(newmatchscore2));
    memset(newrematchscore1,0,sizeof(newrematchscore1));
    memset(newrematchscore2,0,sizeof(newrematchscore2));

    memset(disnewcenterx1,0,sizeof(disnewcenterx1));
    memset(disnewcentery1,0,sizeof(disnewcentery1));
    memset(disnewcenterx2,0,sizeof(disnewcenterx2));
    memset(disnewcentery2,0,sizeof(disnewcentery2));
    memset(disnewrecenterx1,0,sizeof(disnewrecenterx1));
    memset(disnewrecentery1,0,sizeof(disnewrecentery1));
    memset(disnewrecenterx2,0,sizeof(disnewrecenterx2));
    memset(disnewrecentery2,0,sizeof(disnewrecentery2));

    HTuple		htRowCheck, htColumnCheck, htAngleCheck, htScore;
    HTuple		htRowCheck1, htColumnCheck1, htAngleCheck1, htScore1;
    HTuple	    Transformation;
    //	Hobject		ContourTrans,m_ShapeModelContours; 
    Herror error_num;

    {
        try
        {
            {
                Hobject model11roi;
                Hobject roiimage11;
                Hobject remodel11roi;
                Hobject reroiimage11;

                gen_rectangle1(&model11roi,model11y-model11halfx-searchrange,model11x-model11halfy-searchrange,model11y+model11halfx+searchrange,model11x+model11halfy+searchrange);//查找范围
                reduce_domain(Image1,model11roi,&roiimage11);//缩减查找ROI

                if(photoverify==true)
                {roiimage11=Image1;}

                set_shape_model_param(ShapeModel11,"timeout",4000);

                /*find_shape_model(roiimage11,ShapeModel11,-0.1, 0.2,minscore11,1,0.5,"interpolation",
                  0,0.9,&htRowCheck,&htColumnCheck,&htAngleCheck,&htScore);*/
                find_shape_model(roiimage11,ShapeModel11,-0.5, 1.0,minscore11,1,0.5,"interpolation",
                        0,0.9,&htRowCheck,&htColumnCheck,&htAngleCheck,&htScore);
                centerytemp = htRowCheck[0].D();
                centerxtemp =htColumnCheck[0].D();

                matchscore=htScore[0].D();
                angle=htAngleCheck[0].D();
                HTuple worldx0,worldy0;
                image_points_to_world_plane(CameraParameters, CameraPose, htRowCheck, htColumnCheck, "mm", &worldx0, &worldy0);
                centerx=worldx0[0].D();
                centery=worldy0[0].D();
            }

            if(photoverify==true)
            {
                if(htScore[0].D()>0)
                {
                    ;

                    //centery= htRowCheck[0].D();
                    //centerx =htColumnCheck[0].D();
                    //matchscore=htScore[0].D();
                    //	centerytemp = htRowCheck[0].D();
                    //		centerxtemp =htColumnCheck[0].D();
                    //		angle=htAngleCheck[0].D();
                }
                else
                {
                    MessageBox("标定失败");
                    photoverify=FALSE;
                }
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
                sprintf( s, "%i", i );
                m_list1.SetItemText( item, 0, s );
                sprintf( s, "%0.3f", matchscore );
                m_list1.SetItemText( item, 1, s );
                sprintf( s, "%f", angle*180/PI );
                m_list1.SetItemText( item, 2, s );

                sprintf( s, "%f", centerx );
                m_list1.SetItemText( item, 3, s );
                sprintf( s, "%f", centery);
                m_list1.SetItemText( item, 4, s );
            }
        } 
        if(matchscore>=minscore11)
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
            overphoto=1;
            progress=0;
            display();
            MessageBox("标定失败");
            //photoverify=FALSE;
        }
        return 0;
    }
}
Herror  CVAFS2Dlg::OnSearchObject2()
{
    matchscore=0;
    matchscore2=0;
    rematchscore=0;
    rematchscore2=0;
    centerx=0;
    centery=0;
    centerx2=0;
    centery2=0;
    memset(newmatchscore1,0,sizeof(newmatchscore1));
    memset(newmatchscore2,0,sizeof(newmatchscore2));
    memset(newrematchscore1,0,sizeof(newrematchscore1));
    memset(newrematchscore2,0,sizeof(newrematchscore2));

    memset(disnewcenterx1,0,sizeof(disnewcenterx1));
    memset(disnewcentery1,0,sizeof(disnewcentery1));
    memset(disnewcenterx2,0,sizeof(disnewcenterx2));
    memset(disnewcentery2,0,sizeof(disnewcentery2));
    memset(disnewrecenterx1,0,sizeof(disnewrecenterx1));
    memset(disnewrecentery1,0,sizeof(disnewrecentery1));
    memset(disnewrecenterx2,0,sizeof(disnewrecenterx2));
    memset(disnewrecentery2,0,sizeof(disnewrecentery2));

    HTuple		htRowCheck, htColumnCheck, htAngleCheck, htScore;
    HTuple		htRowCheck1, htColumnCheck1, htAngleCheck1, htScore1;
    HTuple	    Transformation;
    //	Hobject		ContourTrans,m_ShapeModelContours; 
    Herror error_num;
    {
        try
        {
            {
                Hobject model11roi;
                Hobject roiimage11;
                Hobject remodel11roi;
                Hobject reroiimage11;

                gen_rectangle1(&model11roi,model11y-model11halfx-searchrange,model11x-model11halfy-searchrange,model11y+model11halfx+searchrange,model11x+model11halfy+searchrange);//查找范围
                reduce_domain(Image1,model11roi,&roiimage11);//缩减查找ROI

                if(photoverify==true)
                {roiimage11=Image1;}

                set_shape_model_param(ShapeModel11,"timeout",4000);

                /*find_shape_model(roiimage11,ShapeModel11,-0.1, 0.2,minscore11,1,0.5,"interpolation",
                  0,0.9,&htRowCheck,&htColumnCheck,&htAngleCheck,&htScore);*/
                find_shape_model(roiimage11,ShapeModel11,-0.5, 1.0,minscore11,1,0.5,"interpolation",
                        0,0.9,&htRowCheck,&htColumnCheck,&htAngleCheck,&htScore);
                centerytemp = htRowCheck[0].D();
                centerxtemp =htColumnCheck[0].D();

                matchscore=htScore[0].D();
                angle=htAngleCheck[0].D();
                HTuple worldx0,worldy0;
                image_points_to_world_plane(CameraParameters, CameraPose, htRowCheck, htColumnCheck, "mm", &worldx0, &worldy0);
                centerx=worldx0[0].D();
                centery=worldy0[0].D();
            }

            if(photoverify==true)
            {
                if(htScore[0].D()>0)
                {
                    ;

                    //centery= htRowCheck[0].D();
                    //centerx =htColumnCheck[0].D();
                    //matchscore=htScore[0].D();
                    //	centerytemp = htRowCheck[0].D();
                    //		centerxtemp =htColumnCheck[0].D();
                    //		angle=htAngleCheck[0].D();
                }
                else
                {
                    MessageBox("标定失败");
                    photoverify=FALSE;
                }
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
                sprintf( s, "%i", i );
                m_list1.SetItemText( item, 0, s );
                sprintf( s, "%0.3f", matchscore );
                m_list1.SetItemText( item, 1, s );
                sprintf( s, "%f", angle*180/PI );
                m_list1.SetItemText( item, 2, s );

                sprintf( s, "%f", centerx );
                m_list1.SetItemText( item, 3, s );
                sprintf( s, "%f", centery);
                m_list1.SetItemText( item, 4, s );
            }
        } 
        if(matchscore>=minscore11)
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
            overphoto=1;
            progress=0;
            display();
            MessageBox("标定失败");
            //photoverify=FALSE;
        }
        return 0;
    }
}

void CVAFS2Dlg::display2()
{
    HTuple	    Transformation;
    Hobject		ContourTrans,m_ShapeModelContours; 
    Herror error_num;
    set_draw(m_Window2id,"margin"); 
    set_color(m_Window2id,"green");
    {
        try
        {
            if(zoomfactor!=1)
            {
                Hobject imagezoom;
                zoom_image_factor(Image2,&imagezoom,zoomfactor,zoomfactor,"constant");

                set_part(m_Window2id,zoomupdown,zoomleftright,camera1width+zoomupdown,camera1height+zoomleftright );

                disp_obj(imagezoom,m_Window2id);
            }
            else	
                disp_obj(Image2,m_Window2id);
            //if(modalselect==0)
            {
                Hobject model21roi;
                Hobject remodel21roi;

                gen_rectangle1(&model21roi,remodel21y-model21halfx-searchrange2,remodel21x-model21halfy-searchrange2,remodel21y+model21halfx+searchrange2,remodel21x+model21halfy+searchrange2);
                disp_obj(model21roi,m_Windowid);//model21y-model21halfx-100,model21x-model21halfy-100,model21y+model21halfx+100,model21x+model21halfy+100);
                gen_rectangle1(&model21roi,model21y-model21halfx-searchrange2,model21x-model21halfy-searchrange2,model21y+model21halfx+searchrange2,model21x+model21halfy+searchrange2);

                disp_obj(model21roi,m_Window2id);          
            }

            if((photoverify==false))//&&(modalselect==1))
            {
                Hobject model22roi;

                gen_rectangle1(&model22roi,remodel22y-model22halfx-searchrange2,remodel22x-model22halfy-searchrange2,remodel22y+model22halfx+searchrange2,remodel22x+model22halfy+searchrange2);
                disp_obj(model22roi,m_Windowid);
                gen_rectangle1(&model22roi,model22y-model22halfx-searchrange2,model22x-model22halfy-searchrange2,model22y+model22halfx+searchrange2,model22x+model22halfy+searchrange2);
                disp_obj(model22roi,m_Window2id);
            }

            if((photoverify==false)&&( matchscore2>0 ))//&&(modalselect==1))
            {
                set_color(m_Window2id,"red");
                get_shape_model_contours(&m_ShapeModelContours,ShapeModel22,1);
                vector_angle_to_rigid(0,0,0,camera22centery,camera22centerx,angle22,&Transformation);

                affine_trans_contour_xld(m_ShapeModelContours,&ContourTrans,Transformation);
                disp_obj(ContourTrans,m_Window2id);
            }

            if(( matchscore2>0 ))//&&(modalselect==1))
            {
                set_color(m_Window2id,"green");
                disp_cross(m_Window2id,centery2temp,centerx2temp,40,0);
                disp_cross(m_Window2id,recentery2temp,recenterx2temp,40,0);
            } 
        }
        catch (HException &except)
        {
            error_num = except.err;
        }
    }
}

void CVAFS2Dlg::display()
{
    HTuple	    Transformation;
    Hobject		ContourTrans,m_ShapeModelContours; 
    Herror error_num;
    set_draw(m_Windowid,"margin"); 
    set_color(m_Windowid,"green");
    {
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

                //gen_rectangle1(&model11roi,remodel11y-model11halfx-searchrange,remodel11x-model11halfy-searchrange,remodel11y+model11halfx+searchrange,remodel11x+model11halfy+searchrange);
                //disp_obj(model11roi,m_Windowid);//model11y-model11halfx-100,model11x-model11halfy-100,model11y+model11halfx+100,model11x+model11halfy+100);
                gen_rectangle1(&model11roi,model11y-model11halfx-searchrange,model11x-model11halfy-searchrange,model11y+model11halfx+searchrange,model11x+model11halfy+searchrange);

                disp_obj(model11roi,m_Windowid);          
            }

            if((photoverify==false))//&&(modalselect==1))
            {
                Hobject model12roi;

                /* gen_rectangle1(&model12roi,remodel12y-model12halfx-searchrange,remodel12x-model12halfy-searchrange,remodel12y+model12halfx+searchrange,remodel12x+model12halfy+searchrange);
                   disp_obj(model12roi,m_Windowid);*/
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
            }
            if((photoverify==false)&&( matchscore2>0 ))//&&(modalselect==1))
            {
                set_color(m_Windowid,"red");
                get_shape_model_contours(&m_ShapeModelContours,ShapeModel12,1);
                vector_angle_to_rigid(0,0,0,centery2temp,centerx2temp,angle2,&Transformation);

                affine_trans_contour_xld(m_ShapeModelContours,&ContourTrans,Transformation);
                disp_obj(ContourTrans,m_Windowid);
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
}

void CVAFS2Dlg::OnTimer(UINT nIDEvent) 
{
    // TODO: Add your message handler code here and/or call default

    SYSTEMTIME systime;
    ::GetLocalTime(&systime);
    m_hour=systime.wHour;
    m_minute=systime.wMinute;
    m_second=systime.wSecond;
    m_pastecounter=pastecounter;

    CString strTime;
    strTime.Format( "时间 %0.3f", fTime * 1000.0 );
    SetDlgItemText( IDC_time, strTime );

    UpdateData( false );

	/*
    if(dmc_read_inbit(0,reset)==0)
    {

        updowninreset=false;
        updownoutreset=false;
        OnReset() ;
    }*/

    //if(((bigproblem==true)||(smallproblem==true))&&((dmc_read_inbit(0,reset)==0)))
    //{
        /*if(showerr[doorerr]==true)
          {
          CString tempstr1 = _T("$reset\r\n");
          C4TcpSend(tempstr1);
          if(C4getPover==true)
          {
          C4TcpSend( _T("$setmotorson,1\r\n"));
          C4getPover=false;
          }
          }*/

        //OnReset() ;
    //}
    if(((bigproblem==false)&&(smallproblem==false))&&((d1000_in_bit(startin)==0)))
    {
        OnStart() ;
    }


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

    if((imagephotoover==true)&&((cyclephoto==true)||(photoverify==true))||(run==true)||(llstepp==true))
    {
        OnSearchObject();
        display();
        imagephotoover=false;
    }

    if((imagephotoover2==true)&&((cyclephoto2==true)||(metalverify==true)||(run==true)/*||(fixturestepp==true)*/))//&&((cyclephoto2==true)||(run==true)||(fixturestepp==true)))
    {
        imagephotoover2=false;
        OnSearchObject2();
        display2();
    }

    //{{{ 相机1标定
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
            // firstcamerax=centerx;
            // firstcameray=centery;
            firstrobotx=C4cpx;
            firstroboty=C4cpy;
            point1.x=centerx;
            point1.y=centery;
            progress=progress+1;
            //servostarted=0;
        }
        if((progress==2)&&(C4getPover==true))
        {
            float rotate45;
            rotate45=C4cpu-45;
            CString tempstr;		 
            tempstr.Format("$execute,\"jogP(0)=%0.3f;jogP(1)=%0.3f;jogP(2)=%0.3f;jogP(3)=%0.3f\"\r\n",C4cpx,C4cpy,C4cpz,rotate45);
            C4TcpSend(tempstr);			 
            C4TcpSend(_T("$start,3\r\n"));
            C4getPover=false;
            progress=progress+1;

            //tempa=0;
            //tempb=0;
            //servostarted=1;
        }

        if((progress==3)&&(C4getPover==true))
        {

            Sleep(1000);
            progress=progress+1;
            //servostarted=0;

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


            point2.x=centerx;
            point2.y=centery;

            progress=511;



        }
        if((progress==511)&&(C4getPover==true))
        {



            float rotate45;
            rotate45=C4cpu-45;
            CString tempstr;		 
            tempstr.Format("$execute,\"jogP(0)=%0.3f;jogP(1)=%0.3f;jogP(2)=%0.3f;jogP(3)=%0.3f\"\r\n",C4cpx,C4cpy,C4cpz,rotate45);
            C4TcpSend(tempstr);			 
            C4TcpSend(_T("$start,3\r\n"));
            C4getPover=false;
            progress=512;



        }

        if((progress==512)&&(C4getPover==true))
        {
            Sleep(1000);
            progress=6;
            //servostarted=0;
        }


        if((progress==6)&&(C4getPover==true))
        {

            startphoto=0;
            overphoto=0;
            OnStartCollection(); 
            progress=progress+1;
        }
        if((overphoto==1)&&(progress==7))
        {

            point3.x=centerx;
            point3.y=centery;

            progress=progress+1;
            Sleep(1000);


        }
        if((progress==8)&&(C4getPover==true))
        {
            float xline100,yline100;
            xline100=C4cpx+100;
            yline100=C4cpy+100;
            CString tempstr;		 
            tempstr.Format("$execute,\"jogP(0)=%0.3f;jogP(1)=%0.3f;jogP(2)=%0.3f;jogP(3)=%0.3f\"\r\n",xline100,yline100,C4cpz,C4cpu);
            C4TcpSend(tempstr);			 
            C4TcpSend(_T("$start,3\r\n"));
            C4getPover=false;
            progress=9;
        }

        if((progress==9)&&(C4getPover==true))
        {

            Sleep(1000);
            progress=progress+1;
        }
        if(progress==10)
        {

            startphoto=0;
            overphoto=0;
            OnStartCollection(); 
            progress=progress+1;
        }
        if((overphoto==1)&&(progress==11))
        {		 
            secondrobotx=C4cpx;
            secondroboty=C4cpy;
            point21.x=centerx;
            point21.y=centery;
            progress=progress+1;
        }
        if((progress==12)&&(C4getPover==true))
        {
            float rotate45;
            rotate45=C4cpu+45;
            CString tempstr;		 
            tempstr.Format("$execute,\"jogP(0)=%0.3f;jogP(1)=%0.3f;jogP(2)=%0.3f;jogP(3)=%0.3f\"\r\n",C4cpx,C4cpy,C4cpz,rotate45);
            C4TcpSend(tempstr);			 
            C4TcpSend(_T("$start,3\r\n"));
            C4getPover=false;
            progress=progress+1;

            //tempa=0;
            //tempb=0;
            //servostarted=1;
        }






        if((progress==13)&&(C4getPover==true))
        {

            Sleep(1000);
            progress=progress+1;
            //servostarted=0;

        }

        if(progress==14)
        {

            startphoto=0;
            overphoto=0;
            OnStartCollection(); 
            progress=progress+1;
        }

        if((overphoto==1)&&(progress==15))
        {


            point22.x=centerx;
            point22.y=centery;

            progress=progress+1;



        }
        if((progress==16)&&(C4getPover==true))
        {



            float rotate45;
            rotate45=C4cpu+45;
            CString tempstr;		 
            tempstr.Format("$execute,\"jogP(0)=%0.3f;jogP(1)=%0.3f;jogP(2)=%0.3f;jogP(3)=%0.3f\"\r\n",C4cpx,C4cpy,C4cpz,rotate45);
            C4TcpSend(tempstr);			 
            C4TcpSend(_T("$start,3\r\n"));
            C4getPover=false;
            progress=progress+1;



        }

        if((progress==17)&&(C4getPover==true))
        {
            Sleep(1000);
            progress=progress+1;
            //servostarted=0;
        }

        if((progress==18)&&(C4getPover==true))
        {

            startphoto=0;
            overphoto=0;
            OnStartCollection(); 
            progress=progress+1;
        }
        if((overphoto==1)&&(progress==19))
        {

            point23.x=centerx;
            point23.y=centery;

            progress=progress+1;
            Sleep(1000);


        }

        if((overphoto==1)&&(progress==20))
        {

            centera=circle(point1,point2,point3);
            centerb=circle(point21,point22,point23);
            // 	disp_cross(m_Windowid,centera.y,centera.x,80,0);
            //disp_cross(m_Windowid,centerb.y,centerb.x,80,0);



            a1x=centera.x;
            b2x=centerb.x;
            a1y=centera.y;
            b2y=centerb.y;
            /*Row1[0]=centera.y;
              Row1[1]=centerb.y;
              Col1[0]=centera.x;
              Col1[1]=centerb.x;*/
            Rows1[0]=centera.y;
            Rows1[1]=centerb.y;
            Cols1[0]=centera.x;
            Cols1[1]=centerb.x;

            //Rows2[0]=firstroboty;
            //Rows2[1]=secondroboty;
            //Cols2[0]=firstrobotx;
            //Cols2[1]=secondrobotx;

            Rows2[0]=firstroboty;
            Rows2[1]=secondroboty;
            Cols2[0]=firstrobotx;
            Cols2[1]=secondrobotx;


            hom_mat2d_identity(&HomMat2Dforinit);
            vector_to_similarity(Rows1,Cols1,Rows2,Cols2,&HomMat2Dforinit);
            HTuple mtxdir;
            CString tempC,tempA;
            char temps[100];
            tempC=currentdir+"\\1.mtx";
            strcpy(temps,tempC);
            mtxdir[0]=temps;
            tempA=mtxdir[0].S();
            write_tuple(HomMat2Dforinit,mtxdir);
            //write_tuple(HomMat2Dforinit,"C:/1.mtx");
            HTuple Sx,Sy,Phi,Theta,Tx,Ty;
            hom_mat2d_to_affine_par(HomMat2Dforinit,&Sx,&Sy,&Phi,&Theta,&Tx,&Ty);
            photo1angle=Phi[0].D();
            photo2angle=Theta[0].D();
            xscale=Sx[0].D();
            yscale=Sy[0].D();
            xdiv=Tx[0].D();
            ydiv=Ty[0].D();

            photoverify=false;
            progress=0;
            CFile scalenew;
            scalenew.Open(currentdir+"\\scale.txt",CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);
            CArchive scalearnew(&scalenew,CArchive::store);
            scalearnew<<xscale<<yscale<<xdiv<<ydiv<<camera2xdiv<<camera2ydiv<<metalscale<<metalyscale<<photo2angle<<photo1angle<<photo4angle<<photo3angle;
            scalearnew.Close();
            scalenew.Close();
            verifyinfo="相机1标定ok";
        }
    }
    //}}}

    //{{{ 相机2标定
    if(metalverify==true)
    {
        if(progress==0)
        {
            startphoto2=0;
            overphoto2=0;
            OnStartCollection2(); 
            progress=progress+1;
        }

        if((overphoto2==1)&&(progress==1))
        {
            // firstcamerax=centerx;
            // firstcameray=centery;
            firstrobotx=C4cpx;
            firstroboty=C4cpy;
            point1.x=centerx;
            point1.y=centery;
            progress=progress+1;
            //servostarted=0;
        }
        if((progress==2)&&(C4getPover==true))
        {
            float rotate45;
            rotate45=C4cpu-45;
            CString tempstr;		 
            tempstr.Format("$execute,\"jogP(0)=%0.3f;jogP(1)=%0.3f;jogP(2)=%0.3f;jogP(3)=%0.3f\"\r\n",C4cpx,C4cpy,C4cpz,rotate45);
            C4TcpSend(tempstr);			 
            C4TcpSend(_T("$start,3\r\n"));
            C4getPover=false;
            progress=progress+1;
            //tempa=0;
            //tempb=0;
            //servostarted=1;
        }

        if((progress==3)&&(C4getPover==true))
        {
            Sleep(1000);
            progress=progress+1;
            //servostarted=0;
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
            point2.x=centerx;
            point2.y=centery;
            progress=511;
        }
        if((progress==511)&&(C4getPover==true))
        {
            float rotate45;
            rotate45=C4cpu-45;
            CString tempstr;		 
            tempstr.Format("$execute,\"jogP(0)=%0.3f;jogP(1)=%0.3f;jogP(2)=%0.3f;jogP(3)=%0.3f\"\r\n",C4cpx,C4cpy,C4cpz,rotate45);
            C4TcpSend(tempstr);			 
            C4TcpSend(_T("$start,3\r\n"));
            C4getPover=false;
            progress=512;
        }

        if((progress==512)&&(C4getPover==true))
        {
            Sleep(1000);
            progress=6;
            //servostarted=0;
        }

        if((progress==6)&&(C4getPover==true))
        {
            startphoto2=0;
            overphoto2=0;
            OnStartCollection2(); 
            progress=progress+1;
        }
        if((overphoto2==1)&&(progress==7))
        {
            point3.x=centerx;
            point3.y=centery;

            progress=progress+1;
            Sleep(1000);
        }
        if((progress==8)&&(C4getPover==true))
        {
            float xline100,yline100;
            xline100=C4cpx+100;
            yline100=C4cpy+100;
            CString tempstr;		 
            tempstr.Format("$execute,\"jogP(0)=%0.3f;jogP(1)=%0.3f;jogP(2)=%0.3f;jogP(3)=%0.3f\"\r\n",xline100,yline100,C4cpz,C4cpu);
            C4TcpSend(tempstr);			 
            C4TcpSend(_T("$start,3\r\n"));
            C4getPover=false;
            progress=9;
        }

        if((progress==9)&&(C4getPover==true))
        {
            Sleep(1000);
            progress=progress+1;
        }
        if(progress==10)
        {
            startphoto2=0;
            overphoto2=0;
            OnStartCollection2(); 
            progress=progress+1;
        }
        if((overphoto2==1)&&(progress==11))
        {		 
            secondrobotx=C4cpx;
            secondroboty=C4cpy;
            point21.x=centerx;
            point21.y=centery;
            progress=progress+1;
        }
        if((progress==12)&&(C4getPover==true))
        {
            float rotate45;
            rotate45=C4cpu+45;
            CString tempstr;		 
            tempstr.Format("$execute,\"jogP(0)=%0.3f;jogP(1)=%0.3f;jogP(2)=%0.3f;jogP(3)=%0.3f\"\r\n",C4cpx,C4cpy,C4cpz,rotate45);
            C4TcpSend(tempstr);			 
            C4TcpSend(_T("$start,3\r\n"));
            C4getPover=false;
            progress=progress+1;

            //tempa=0;
            //tempb=0;
            //servostarted=1;
        }
        if((progress==13)&&(C4getPover==true))
        {
            Sleep(1000);
            progress=progress+1;
            //servostarted=0;
        }

        if(progress==14)
        {
            startphoto2=0;
            overphoto2=0;
            OnStartCollection2(); 
            progress=progress+1;
        }

        if((overphoto2==1)&&(progress==15))
        {
            point22.x=centerx;
            point22.y=centery;
            progress=progress+1;
        }
        if((progress==16)&&(C4getPover==true))
        {
            float rotate45;
            rotate45=C4cpu+45;
            CString tempstr;		 
            tempstr.Format("$execute,\"jogP(0)=%0.3f;jogP(1)=%0.3f;jogP(2)=%0.3f;jogP(3)=%0.3f\"\r\n",C4cpx,C4cpy,C4cpz,rotate45);
            C4TcpSend(tempstr);			 
            C4TcpSend(_T("$start,3\r\n"));
            C4getPover=false;
            progress=progress+1;
        }

        if((progress==17)&&(C4getPover==true))
        {
            Sleep(1000);
            progress=progress+1;
            //servostarted=0;
        }

        if((progress==18)&&(C4getPover==true))
        {
            startphoto2=0;
            overphoto2=0;
            OnStartCollection2(); 
            progress=progress+1;
        }
        if((overphoto2==1)&&(progress==19))
        {
            point23.x=centerx;
            point23.y=centery;
            progress=progress+1;
            Sleep(1000);
        }

        if((overphoto2==1)&&(progress==20))
        {
            centera=circle(point1,point2,point3);
            centerb=circle(point21,point22,point23);
            // 	disp_cross(m_Windowid,centera.y,centera.x,80,0);
            //disp_cross(m_Windowid,centerb.y,centerb.x,80,0);
            a1x=centera.x;
            b2x=centerb.x;
            a1y=centera.y;
            b2y=centerb.y;
            /*Row1[0]=centera.y;
              Row1[1]=centerb.y;
              Col1[0]=centera.x;
              Col1[1]=centerb.x;*/
            Rows1[0]=centera.y;
            Rows1[1]=centerb.y;
            Cols1[0]=centera.x;
            Cols1[1]=centerb.x;

            //Rows2[0]=firstroboty;
            //Rows2[1]=secondroboty;
            //Cols2[0]=firstrobotx;
            //Cols2[1]=secondrobotx;

            Rows2[0]=firstroboty;
            Rows2[1]=secondroboty;
            Cols2[0]=firstrobotx;
            Cols2[1]=secondrobotx;

            hom_mat2d_identity(&HomMat2Dforinit);
            vector_to_similarity(Rows1,Cols1,Rows2,Cols2,&HomMat2Dforinit);
            HTuple mtxdir;
            CString tempC,tempA;
            char temps[100];
            tempC=currentdir+"\\1.mtx";
            strcpy(temps,tempC);
            mtxdir[0]=temps;
            tempA=mtxdir[0].S();
            write_tuple(HomMat2Dforinit,mtxdir);
            //write_tuple(HomMat2Dforinit,"C:/1.mtx");
            HTuple Sx,Sy,Phi,Theta,Tx,Ty;
            hom_mat2d_to_affine_par(HomMat2Dforinit,&Sx,&Sy,&Phi,&Theta,&Tx,&Ty);
            photo3angle=Phi[0].D();
            photo4angle=Theta[0].D();
            metalscale=Sx[0].D();
            metalyscale=Sy[0].D();
            camera2xdiv=Tx[0].D();
            camera2ydiv=Ty[0].D();

            metalverify=false;
            progress=0;
            CFile scalenew;
            scalenew.Open(currentdir+"\\scale.txt",CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);
            CArchive scalearnew(&scalenew,CArchive::store);
            scalearnew<<xscale<<yscale<<xdiv<<ydiv<<camera2xdiv<<camera2ydiv<<metalscale<<metalyscale<<photo2angle<<photo1angle<<photo4angle<<photo3angle;
            scalearnew.Close();
            scalenew.Close();
            verifyinfo="相机2标定ok";
        }
    }
    //}}}

    HTuple mtxdir;

    if((run==true)||(mainstepp==true)||(mainstepm==true))
    {
        switch(machinestate)
        {
        case state1:
            // if(xzorgfinished==true)
            /*if(safeguardold==false)
              {*/
            machinestate=state1p0p0;
            times=0;
            xzorgfinished=false;
            turnon=false;
            // } 
            robotfirstll=true;

            if(run==false)
            {
                stateinfo="等待上料机复位";
            }
            break;
        case state1p0p0:
            C4TcpSend( _T("$setmotorson,1\r\n"));
            C4getPover=false;
            mainstepp=false;
            mainstepm=false;
            machinestate=state1p1;
            servostarted=0;
            if(run==false)
            {
                stateinfo="系统复位";
            }
            break;

        case state1p1:
            if(times>150)
            {
                machinestate=state1p2;
            }
            times=times+1; 

            if(run==false)
            {
                stateinfo="系统复位";
            }
            break;
        case state1p2:
            times=0;
            if((C4getPover==true)&&(servostarted==0))
            {
                C4TcpSend(_T("$start,0\r\n"));
                C4getPover=false;
                servostarted=1;
            }
            if(C4getPover==true)
            {
                mainstepp=false;
                mainstepm=false;
                machinestate=state1p3;
                servostarted=0;
                if(run==false)
                {
                    stateinfo="去等待位";
                }
            }
            break;
        case state1p3:
            if((C4getPover==true)&&(servostarted==0))
            {
                robotfirst=true;
                float x,y,z,u;
                x=(float)pickx/100;
                y=(float)picky/100;
                z=(float)zphoto/100;
                u=(float)pickangle/1000;
                CString tempstr;
                tempstr.Format("$execute,\"jogP(0)=%0.3f;jogP(1)=%0.3f;jogP(2)=%0.3f;jogP(3)=%0.3f\"\r\n",x,y,z,u);
                C4TcpSend(tempstr);
                C4TcpSend(_T("$start,3\r\n"));
                C4getPover=false;
                servostarted=1;
            }
            if((C4getPover==true)&&(servostarted==1))
            {
                // mainstepp=false;
                mainstepm=false;
                if(robotlast==true)
                {
                    if(leftloadupready==true)
                    {
                        leftloadupready=false;
                        disableleftstepp=false;
                    }
                    if(rightloadupready==true)
                    {
                        rightloadupready=false;
                        disablerightstepp=false;
                    }
                    robotlast=false;
                }
                machinestate=state1p4;
                times=0;
                //imagephotoover=false;				 
                //startphoto=0;				 
                servostarted=0;
                if(robotfirstll==true)
                {
                    platformready=true;
                    robotfirstll=false;
                }
            }

            if(run==false)
            {
                stateinfo="等待拍照";
            }
            break;
        case state1p4:
            if(allowpick==true)
            {
                machinestate=state4;
                allowpick=false;
                mainstepp=false;
                mainstepm=false;
            }
            if(run==false)
            {
                stateinfo="等待拍照成功";
            }
            break;
        case state4:
                if((C4getPover==true)&&(servostarted==0))
                {
                    float x,y,z,u;
                    x=newxa[BYnum];
                    y=newya[BYnum];
                    z=(float)zpush/100;
                    u=newanglepluse[BYnum];
                    showx=x;
                    showy=y;
                    showu=u;
                    showz=z;
                    //x=-270;
                    //y=180;
                    CString tempstr;
                    tempstr.Format("$execute,\"startP(0)=%0.3f;startP(1)=%0.3f;startP(2)=%0.3f;startP(3)=%0.3f\"\r\n",x,y,z,u);
                    C4TcpSend(tempstr);
                    C4TcpSend(_T("$start,1\r\n"));
                    C4getPover=false;
                    servostarted=1;
                    machinestate=state4p1p5;
                }	   
                mainstepp=false;
                mainstepm=false;

                if(run==false)
                {
                    stateinfo="ROBOT拾取";
                }
            break;
        case state4p1p5:
            {
                if(robotfirst==false)
                {
                    if(leftloadupready==true)
                    {
                        leftloadupready=false;
                        disableleftstepp=false;
                    }
                    if(rightloadupready==true)
                    {
                        rightloadupready=false;
                        disablerightstepp=false;
                    } 
                    times=0;
                    machinestate=state4p1;
                }
                else
                {
                    times=0;
                    machinestate=state4p1;
                }
            }
            break;
        case state4p1:
            if(C4getPover==true)
            {
                d1000_out_bit(Probotvacuumout,front);
                mainstepp=false;
                times=times+1;
                if(times>fixturedelaytime)//取延时
                {
                    machinestate=state5;
                    robotfirst=false;
                    times=0;
                }
                servostarted=0;
                if(run==false)
                {
                    stateinfo="ROBOT jump抓取";
                }
            }
            break;
        case state5:
            if((leftloadupready==true)||(rightloadupready==true))
            {
                if((C4getPover==true)&&(servostarted==0))
                {
                        float x,y,z,u;
                        x=(float)pickx/100;
                        y=(float)picky/100;
                        z=(float)zpick/100;
                        u=(float)pickangle/1000;
                        showx=x;
                        showy=y;
                        showu=u;
                        showz=z;
                        CString tempstr;
                        tempstr.Format("$execute,\"goalP(0)=%0.3f;goalP(1)=%0.3f;goalP(2)=%0.3f;goalP(3)=%0.3f\"\r\n",x,y,z,u);
                        C4TcpSend(tempstr);
                        C4TcpSend(_T("$start,2\r\n"));
                        //C4getPover=false;
                    C4getPover=false;
                    servostarted=1;
                    BYnum=BYnum+1;
                    mainstepp=false;
                    machinestate=state6;

                    if(BYnum>=2*comno)
                    {
                        platformready=true;
                    }
                    //d1000_in_bit(Pleftdownin)==0
                }
            }
            else
            {
                if((C4getPover==true)&&(servostarted==0))
                {
                        float x,y,z,u;
                        x=(float)pickx/100;
                        y=(float)picky/100;
                        z=(float)zphoto/100;
                        u=(float)pickangle/1000;
                        showx=x;
                        showy=y;
                        showu=u;
                        showz=z;
                        CString tempstr;
                        tempstr.Format("$execute,\"goalP(0)=%0.3f;goalP(1)=%0.3f;goalP(2)=%0.3f;goalP(3)=%0.3f\"\r\n",x,y,z,u);
                        C4TcpSend(tempstr);
                        C4TcpSend(_T("$start,2\r\n"));
                        //C4getPover=false;
                    C4getPover=false;
                    servostarted=1;
                    BYnum=BYnum+1;
                    mainstepp=false;
                    machinestate=state5p1;

                    if(BYnum>=2*comno)
                    {
                        platformready=true;
                    }
                    //d1000_in_bit(Pleftdownin)==0
                }
            }

            break;
        case state5p1:
            if((leftloadupready==true)||(rightloadupready==true))
            {
                if((C4getPover==true)&&(servostarted==1))
                {
                        float x,y,z,u;
                        x=(float)pickx/100;
                        y=(float)picky/100;
                        z=(float)zpick/100;
                        u=(float)pickangle/1000;
                        showx=x;
                        showy=y;
                        showu=u;
                        showz=z;
                        CString tempstr;
                        tempstr.Format("$execute,\"jogP(0)=%0.3f;jogP(1)=%0.3f;jogP(2)=%0.3f;jogP(3)=%0.3f\"\r\n",x,y,z,u);
                        C4TcpSend(tempstr);
                        C4TcpSend(_T("$start,3\r\n"));
                        //C4getPover=false;
                    C4getPover=false;
                    servostarted=0;
                    mainstepp=false;
                    machinestate=state6;
                    //d1000_in_bit(Pleftdownin)==0
                }
            }
            break;
        case state6:
            if((leftloadupready==true)||(rightloadupready==true))
            {
                if(C4getPover==true)
                {
                    d1000_out_bit(Probotvacuumout,back);
                    //if(leftload==true)
                    //{d1000_out_bit(Pleftvacuumout,front);}
                    //if(leftload==false)
                    //{d1000_out_bit(Prightvacuumout,front);}

                    times=times+1;
                    if(times>pushertime)//机器人放料延时
                    {
                        mainstepp=false; 
                        servostarted=0;
                        times=0;
                        if(BYnum>=2*comno)
                        {
                            //allowpick=false;
                            BYnum=0;
                            machinestate=state1p3;
                            photoready=false;
                            disablellstepp=false;
                            robotlast=true;
                        }
                        else
                        {
                            machinestate=state4;
                        }
                    }
                    //imagephotoover=false;				 
                    //startphoto=0;				 
                }
            }
            break;
        default:
            machinestate=state1;
        }
    }

//状态切换，故障处理
if(d1000_in_bit(emergencyin)==1)
{
    bigproblem=true;
    if(showerr[emergencyerr]==false)
    {
        showerr[emergencyerr]=true;
        m_problemlist.AddString(err[emergencyerr]);
    }
}

if((d1000_in_bit(doorin)==1))
{
    if ((C4b_safeguard==false)&&(C4b_running==true)&&(run==true))
    {
        CString tempstr1 = _T("$pause\r\n");
        C4TcpSend(tempstr1);
    }

    errtime[doorerr]=errtime[doorerr]+1;
    //d1000_out_bit(robotdoorout,back);
    if(errtime[doorerr]>20)
    {
        errtime[doorerr]=0;
        smallproblem=true;

        if(showerr[doorerr]==false)
        {
            showerr[doorerr]=true;
            m_problemlist.AddString(err[doorerr]);
        }
    }
}
else
{
    errtime[doorerr]=0;
}

    if(turnvacu1error==true)
    {
        turnvacu1error=false;

        if(showerr[turnhomevacuerr]==false)
        {
            showerr[turnhomevacuerr]=true;
            m_problemlist.AddString(err[turnhomevacuerr]);
        }

    }
    if(turnvacu2error==true)
    {
        turnvacu2error=false;

        if(showerr[turnoutvacuerr]==false)
        {
            showerr[turnoutvacuerr]=true;
            m_problemlist.AddString(err[turnoutvacuerr]);
        }

    }
    if(loadalarm==true)
    {
        loadalarm=false;

        if(showerr[loadvacuerr]==false)
        {
            showerr[loadvacuerr]=true;
            m_problemlist.AddString(err[loadvacuerr]);
        }

    }
    if((d1000_get_outbit(turnplateout)==0)&&(d1000_in_bit(turnoutin)==1))
    {
        errtime[turnouterr]=errtime[turnouterr]+1;
        if(errtime[turnouterr]>100)
        {
            smallproblem=true;
            errtime[turnouterr]=0;

            if(showerr[turnouterr]==false)
            {
                showerr[turnouterr]=true;
                m_problemlist.AddString(err[turnouterr]);
            }
        }
    }else{errtime[turnouterr]=0;}

    if((d1000_get_outbit(turnplateout)==1)&&(d1000_in_bit(turnhomein)==1))
    {
        errtime[turnhomeerr]=errtime[turnhomeerr]+1;
        if(errtime[turnhomeerr]>100)
        {
            smallproblem=true;
            errtime[turnhomeerr]=0;

            if(showerr[turnhomeerr]==false)
            {
                showerr[turnhomeerr]=true;
                m_problemlist.AddString(err[turnhomeerr]);
            }
        }
    }else{errtime[turnhomeerr]=0;}

    if((d1000_get_outbit(fpcout)==0)&&(d1000_in_bit(fpcoutin)==1))
    {
        errtime[fpcouterr]=errtime[fpcouterr]+1;
        if(errtime[fpcouterr]>100)
        {
            smallproblem=true;
            errtime[fpcouterr]=0;

            if(showerr[fpcouterr]==false)
            {
                showerr[fpcouterr]=true;
                m_problemlist.AddString(err[fpcouterr]);
            }
        }
    }else{errtime[fpcouterr]=0;}

    if((d1000_get_outbit(fpcout)==1)&&(d1000_in_bit(fpchomein)==1))
    {

        errtime[fpchomeerr]=errtime[fpchomeerr]+1;
        if(errtime[fpchomeerr]>100)
        {
            smallproblem=true;
            errtime[fpchomeerr]=0;

            if(showerr[fpchomeerr]==false)
            {
                showerr[fpchomeerr]=true;
                m_problemlist.AddString(err[fpchomeerr]);
            }
        }
    }else{errtime[fpchomeerr]=0;}

    if((d1000_get_outbit(loadout)==0)&&(d1000_in_bit(loadoutin)==1))
    {

        errtime[loadouterr]=errtime[loadouterr]+1;
        if(errtime[loadouterr]>100)
        {
            smallproblem=true;
            errtime[loadouterr]=0;

            if(showerr[loadouterr]==false)
            {
                showerr[loadouterr]=true;
                m_problemlist.AddString(err[loadouterr]);
            }
        }
    }else{errtime[loadouterr]=0;}

    if((d1000_get_outbit(loadout)==1)&&(d1000_in_bit(loadhomein)==1))
    {

        errtime[loadhomeerr]=errtime[loadhomeerr]+1;
        if(errtime[loadhomeerr]>100)
        {
            smallproblem=true;
            errtime[loadhomeerr]=0;

            if(showerr[loadhomeerr]==false)
            {
                showerr[loadhomeerr]=true;
                m_problemlist.AddString(err[loadhomeerr]);
            }
        }
    }else{errtime[loadhomeerr]=0;}

if(communicateerror==true)
{

    bigproblem=true;
    communicateerror=false;

    if(showerr[communerr]==false)
    {
        showerr[communerr]=true;
        m_problemlist.AddString(err[communerr]);
    }

}

if(photoproblem==true)
{
    startphoto=0;

    if(showerr[glasscameraerr]==false)
    {
        showerr[glasscameraerr]=true;
        m_problemlist.AddString(err[glasscameraerr]);
    }
    photoproblem=false;
}
if(photoproblem2==true)
{
    startphoto2=0;

    if(showerr[traycameraerr]==false)
    {
        showerr[traycameraerr]=true;
        m_problemlist.AddString(err[traycameraerr]);
    }
    photoproblem2=false;
}

if(run==true)
{
    GetDlgItem(IDC_DEBUG)->EnableWindow(false);
    turnon=false;
}
if(stop==true)
{GetDlgItem(IDC_DEBUG)->EnableWindow(true);}

if(bigproblem==true)
{
    allowpick=false;
    llnRes=0;


    //轴运行停止,
    BYnum=0;
    /*if(C4b_stop==false)
      {
      C4TcpSend(_T("$stop\r\n"));
      }*/
    d1000_out_bit(robotemergencyout,back);


    C4pSocket.Close();

    alltrayover=false;
    robotfirst=false;
    robotlast=false;
    rightloadupready=false;
    rightunloadready=false;
    rightpeelready=false;
    leftloadupready=false;
    leftunloadready=false;
    leftpeelready=false;
    unloadorgfinished=false;

    leftposition=none;
    rightposition=none;
    poweronok=false;

    clipready=false;

    linstate=linstate1;
    loutstate=loutstate1;
    llstate=llstate1;
    leftstate=leftstate1;
    rightstate=rightstate1;
    peelstate=peelstate1;
    unloadstate=unloadstate1;
    machinestate=state1;

    d1000_decel_stop(0);
    d1000_decel_stop(1);
    d1000_decel_stop(2);
    d1000_decel_stop(3);

    d1000_out_bit(Probotvacuumout,back);

    //状态复位

    xtarted=0;
    zstarted=0;
    linstarted=0;
    loutstarted=0;
    llstarted=0;
    leftservostarted=0;
    rightservostarted=0;
    peelservostarted=0;
    unloadservostarted=0;
    mainstepp=false;

    unloadstepp=false;
    mainstepm=false;
    linstepp=false;
    loutstepp=false;
    llstepp=false;
    rightstepp=false;
    leftstepp=false;
    peelstepp=false;


    linready=false;
    loutready=false;

    photoready=false;

    times=0;
    photoverify=false;

    if(beltstop==false)	d1000_out_bit(beltout, front);
}



if((bigproblem==true)||(smallproblem==true))
{

    if((alarmtime<30))
    {d1000_out_bit(alarmlightout, front);}
    if((alarmtime>=30))
    {d1000_out_bit(alarmlightout, back);}

    if((withbeep==1)&&(withbeeptemp==false))
    {d1000_out_bit(alarmbeepout, front);}
    if((withbeep==0)||(withbeeptemp==true))
    {d1000_out_bit(alarmbeepout, back);}
    alarmtime=alarmtime+1;
    if(alarmtime>60)
        alarmtime=0;

    if(beltstop==false) d1000_out_bit(beltout, front);

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
    if(beltstop==false) d1000_out_bit(beltout, front);
    GetDlgItem(IDC_START)->EnableWindow(true);
    GetDlgItem(IDC_STOP)->EnableWindow(false);
    GetDlgItem(IDC_RESET)->EnableWindow(false);

}




///////////////////////////////C4ROBOT
if(C4xjogadd==true)
{
    C4xjogadd=false;
    double jog;
    jog=C4cpx+C4jogv;
    CString tempstr;
    tempstr.Format("$execute,\"jogP(0)=%0.3f;jogP(1)=%0.3f;jogP(2)=%0.3f;jogP(3)=%0.3f\"\r\n",jog,C4cpy,C4cpz,C4cpu);
    C4TcpSend(tempstr);
    C4TcpSend(_T("$start,3\r\n"));
    C4getPover=false;
}
if(C4xjogsub==true)
{
    C4xjogsub=false;
    double jog;
    jog=C4cpx-C4jogv;
    CString tempstr;
    tempstr.Format("$execute,\"jogP(0)=%0.3f;jogP(1)=%0.3f;jogP(2)=%0.3f;jogP(3)=%0.3f\"\r\n",jog,C4cpy,C4cpz,C4cpu);
    C4TcpSend(tempstr);
    C4TcpSend(_T("$start,3\r\n"));
    C4getPover=false;
}
if(C4yjogadd==true)
{
    C4yjogadd=false;
    UpdateData(true);
    double jog;
    jog=C4cpy+C4jogv;
    CString tempstr;
    tempstr.Format("$execute,\"jogP(0)=%0.3f;jogP(1)=%0.3f;jogP(2)=%0.3f;jogP(3)=%0.3f\"\r\n",C4cpx,jog,C4cpz,C4cpu);
    C4TcpSend(tempstr);
    C4TcpSend(_T("$start,3\r\n"));
    C4getPover=false;
}
if(C4yjogsub==true)
{
    C4yjogsub=false;
    UpdateData(true);
    double jog;
    jog=C4cpy-C4jogv;
    CString tempstr;
    tempstr.Format("$execute,\"jogP(0)=%0.3f;jogP(1)=%0.3f;jogP(2)=%0.3f;jogP(3)=%0.3f\"\r\n",C4cpx,jog,C4cpz,C4cpu);
    C4TcpSend(tempstr);
    C4TcpSend(_T("$start,3\r\n"));
    C4getPover=false;
}
if(C4zjogadd==true)
{
    C4zjogadd=false;
    UpdateData(true);
    double jog;
    jog=C4cpz+C4jogv;
    CString tempstr;
    tempstr.Format("$execute,\"jogP(0)=%0.3f;jogP(1)=%0.3f;jogP(2)=%0.3f;jogP(3)=%0.3f\"\r\n",C4cpx,C4cpy,jog,C4cpu);
    C4TcpSend(tempstr);
    C4TcpSend(_T("$start,3\r\n"));
    C4getPover=false;
}
if(C4zjogsub==true)
{
    C4zjogsub=false;
    UpdateData(true);
    double jog;
    jog=C4cpz-C4jogv;
    CString tempstr;
    tempstr.Format("$execute,\"jogP(0)=%0.3f;jogP(1)=%0.3f;jogP(2)=%0.3f;jogP(3)=%0.3f\"\r\n",C4cpx,C4cpy,jog,C4cpu);
    C4TcpSend(tempstr);
    C4TcpSend(_T("$start,3\r\n"));
    C4getPover=false;
}
if(C4ujogadd==true)
{
    C4ujogadd=false;
    UpdateData(true);
    double jog;
    jog=C4cpu+C4jogv;
    CString tempstr;
    tempstr.Format("$execute,\"jogP(0)=%0.3f;jogP(1)=%0.3f;jogP(2)=%0.3f;jogP(3)=%0.3f\"\r\n",C4cpx,C4cpy,C4cpz,jog);
    C4TcpSend(tempstr);
    C4TcpSend(_T("$start,3\r\n"));
    C4getPover=false;
}
if(C4ujogsub==true)
{
    C4ujogsub=false;
    UpdateData(true);
    double jog;
    jog=C4cpu-C4jogv;
    CString tempstr;
    tempstr.Format("$execute,\"jogP(0)=%0.3f;jogP(1)=%0.3f;jogP(2)=%0.3f;jogP(3)=%0.3f\"\r\n",C4cpx,C4cpy,C4cpz,jog);
    C4TcpSend(tempstr);
    C4TcpSend(_T("$start,3\r\n"));
    C4getPover=false;
}

if(C4verifyP==1)
{
    //robotfirst=true;
    float x,y,z,u;
    x=-471;
    y=-31;
    z=350;
    u=0;
    CString tempstr;
    tempstr.Format("$execute,\"jogP(0)=%0.3f;jogP(1)=%0.3f;jogP(2)=%0.3f;jogP(3)=%0.3f\"\r\n",x,y,z,u);
    C4TcpSend(tempstr);
    C4TcpSend(_T("$start,3\r\n"));
    C4getPover=false;
    C4verifyP=0;
}

/*if((cpx!=m_cpx)||(cpy!=m_cpy)||(cpz!=m_cpz)||(cpu!=m_cpu))
  {
  UpdateData( true );
  m_cpx=cpx;
  m_cpy=cpy;
  m_cpz=cpz;
  m_cpu=cpu;
  UpdateData( false );
  }*/
/*if((m_display1!=disp1)||(m_display!=disp2))
  {
  m_display1=disp1;
  m_display=disp2;
  UpdateData( false );
  }*/

//m_display1=pSocket.display;
//m_display=pSocket.display;


//if(C4b_safeguard==true)
//{
//	safeguardold=true;
//}
//            if((safeguardold==true)&&(C4b_safeguard==false))
//			{
//				safeguardold=false;
//				if(C4b_safeguard==false)
//			   {
//				   /*CString tempstr = _T("$login,a\r\n");
//				   C4TcpSend(tempstr);*/
//				   CString tempstr1 = _T("$reset\r\n");
//                   C4TcpSend(tempstr1);
//	              //C4TcpSend( _T("$setmotorson,1\r\n"));
//	  
//			   }
//			}
if((C4commerror==false)&&(bigproblem==false))
{
    C4TcpSend(_T("$getstatus\r\n"));
    if((C4b_ready==true)&&(C4b_safeguard==false))
    {

        C4TcpSend(_T("$execute,\"print here\"\r\n"));
        C4getPover=true;
    }
}

    if(run==true)
    {
        GetDlgItem(IDC_BELT)->EnableWindow(false);
        beltstop=false;
        SetDlgItemText(IDC_BELT,"传送带关");
    }
    if(stop==true)
    {
        GetDlgItem(IDC_BELT)->EnableWindow(true); 

        if(beltstop==true)  
        {
            d1000_out_bit(beltout, back);
            SetDlgItemText(IDC_BELT,"传送带开");
        }

        else if(beltstop==false) 
        {
            SetDlgItemText(IDC_BELT,"传送带关");
        }
    }

//$setmotorson,1\r\n
CDialog::OnTimer(nIDEvent);
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

    d1000_out_bit(robotemergencyout,front);



    if(bigproblem==true)
    {
        if (!C4pSocket.Create())
        {
            C4pSocket.Close();	
            MessageBox(_T("Create socket failed!"));

        }

        CString strIP = _T("192.168.0.1");
        int  nPort = 5000;

        while(!C4pSocket.Connect(strIP,nPort))
        {
            if(AfxMessageBox("TCP ERROR",MB_YESNO)==IDYES)
            {

                C4pSocket.Close();


            }
        }

        CString tempstr = _T("$login,a\r\n");
        C4TcpSend(tempstr);
        CString tempstr1 = _T("$reset\r\n");
        C4TcpSend(tempstr1);
        CString tempstr2;
        tempstr2.Format("$execute,\"speedpara=%d;speedSpara=%d\"\r\n",vexy,vturnplate);
        C4TcpSend(tempstr2);
    }		
    C4commerror=false;
    /////////////////////////////////////////////////////////




    /*if((bigproblem==true)&&(C4b_safeguard==false))
      {
      CString tempstr = _T("$login,a\r\n");
      C4TcpSend(tempstr);
      CString tempstr1 = _T("$reset\r\n");
      C4TcpSend(tempstr1);


      }*/

    smallproblem=false;
    bigproblem=false;




    int i;
    for(i=0;i<TOTAL_ERR_NUM;i++)
    {
        showerr[i]=false;
        errtime[i]=0;

    }
    camera2counter=0;

    emptycounter=0;

    m_problemlist.ResetContent();
    photoproblem=false;
    photoproblem2=false;

    vacuumerror=false;



    servoxtime=0;
    servoytime=0;
    pusheruptime=0;
    pusherdowntime=0;
    rollertime=0;
    vacuumtime=0;
    mainmotortime=0;

    fixtureintime=0;
    tonguehometime=0;



    updowninreset=false;
    updownoutreset=false;
    //overphoto=0;
    //overphoto2=0;

    disablemainstepp=false;
    disablelinstepp=false;
    disableloutstepp=false;
    disablellstepp=false;
    disableleftstepp=false;
    disablerightstepp=false;
    disablepeelstepp=false;
    disableunloadstepp=false;


    withbeeptemp=true;

}
void CVAFS2Dlg::OnStart() 
{
    // TODO: Add your control notification handler code here

    if((bigproblem==false)&&(smallproblem==false))
    {
        if((d1000_in_bit(doorin)==0))
        {
            Sleep(100);
            run=true;
            stop=false;
            if(C4b_pause==true)
            {
                CString tempstr1 = _T("$continue\r\n");
                C4TcpSend(tempstr1);
            }
        }
    }
    withbeeptemp=false;
}


void CVAFS2Dlg::OnClose() 
{
    // TODO: Add your message handler code here and/or call default

    //CDialog::OnClose();
}

void CVAFS2Dlg::OnXp() 
{
    // TODO: Add your control notification handler code here
    m_pastex=m_pastex+1;
    pastex=m_pastex;
    UpdateData( false );


    CFile currentpara;
    currentpara.Open(currentparametername,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);

    CArchive currentparaar(&currentpara,CArchive::store);
    currentparaar<<PARAINPUT;

    currentparaar.Close();
    currentpara.Close();

}

void CVAFS2Dlg::OnXm() 
{
    // TODO: Add your control notification handler code here
    m_pastex=m_pastex-1;
    pastex=m_pastex;
    UpdateData( false );


    CFile currentpara;
    currentpara.Open(currentparametername,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);

    CArchive currentparaar(&currentpara,CArchive::store);
    currentparaar<<PARAINPUT;

    currentparaar.Close();
    currentpara.Close();

}

void CVAFS2Dlg::OnYp() 
{
    // TODO: Add your control notification handler code here

    m_pastey=m_pastey+1;
    pastey=m_pastey;
    UpdateData( false );


    CFile currentpara;
    currentpara.Open(currentparametername,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);

    CArchive currentparaar(&currentpara,CArchive::store);
    currentparaar<<PARAINPUT;

    currentparaar.Close();
    currentpara.Close();

}

void CVAFS2Dlg::OnYm() 
{
    // TODO: Add your control notification handler code here
    m_pastey=m_pastey-1;
    pastey=m_pastey;
    UpdateData( false );


    CFile currentpara;
    currentpara.Open(currentparametername,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);

    CArchive currentparaar(&currentpara,CArchive::store);
    currentparaar<<PARAINPUT;

    currentparaar.Close();
    currentpara.Close();

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

void CVAFS2Dlg::OnAnglep() 
{
    // TODO: Add your control notification handler code here
    m_pasteangle=m_pasteangle+1;
    pasteangle=m_pasteangle;
    UpdateData( false );


    CFile currentpara;
    currentpara.Open(currentparametername,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);

    CArchive currentparaar(&currentpara,CArchive::store);
    currentparaar<<PARAINPUT;

    currentparaar.Close();
    currentpara.Close();

}

void CVAFS2Dlg::OnAnglem() 
{
    // TODO: Add your control notification handler code here
    m_pasteangle=m_pasteangle-1;
    pasteangle=m_pasteangle;
    UpdateData( false );


    CFile currentpara;
    currentpara.Open(currentparametername,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);

    CArchive currentparaar(&currentpara,CArchive::store);
    currentparaar<<PARAINPUT;

    currentparaar.Close();
    currentpara.Close();

}
void BeginTime()
{
    QueryPerformanceFrequency( &m_Frequency );

    QueryPerformanceCounter( &m_BeginTime );


}

void EndTime()
{
    QueryPerformanceCounter(&m_EndTime);
    fTime = double(m_EndTime.LowPart-m_BeginTime.LowPart)/double(m_Frequency.LowPart);

}


BEGIN_EVENTSINK_MAP(CVAFS2Dlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CVAFS2Dlg)

    //}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()







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
        Sleep(10);

        //{{{ 转盘
        if((run==true)||(llstepp==true))
        {
            switch(fixturestate)
            {
            case fixturestate1:
                fixturetimes=0;
                //glassloop=0x00;
                fixturestate=fixturestate1p1;

                disablefixturestepm=true;
                fixturestarted=0;
                break;
            case fixturestate1p1:
                firstload=true;
                fixturetimes=fixturetimes+1;
                d1000_out_bit( turnvacuumout2, 0);
                if(fixturetimes==1)
                {
                    d1000_out_bit( turnvacuumout1, 0);
                    if(d1000_in_bit(turnvacuumin1)==0)
                    {
                        glassclearerror=true;
                        smallproblem=true;
                    }
                }
                if((fixturetimes>1)&&(fixturetimes<25))
                {
                    d1000_out_bit( turnvacuumout1, 0);
                    if(d1000_in_bit(turnvacuumin1)==0)
                    {
                        glassclearerror=true;
                        smallproblem=true;
                    }
                }
                if((fixturetimes>25)&&(fixturetimes<50))
                {
                    d1000_out_bit( turnvacuumout2, front);
                    if(d1000_in_bit(turnvacuumin2)==0)
                    {
                        glassclearerror=true;
                        smallproblem=true;
                    }
                }
                if((fixturetimes>100))
                {
                    // d1000_out_bit( fixturevacuumout4, back);
                    fixturestate=fixturestate2;
                    d1000_out_bit( turnvacuumout1, back);
                    d1000_out_bit( turnvacuumout2, back);

                    fixturestarted=0;
                    fixturetimes=0;
                    llstepp=false;
                    //fixturestepm=false;
                }
                if(run==false)
                {
                    stateinfo="转盘复位";
                }
                break;
            case fixturestate2:
                //temp1d=d1000_check_done(3);
                if((fixturestarted==0))
                {
                    d1000_out_bit( turnplateout, front);
                    fixturestarted=1;
                }
                if((d1000_in_bit(turnoutin)==0))
                {
                    llstepp=false;
                    fixturestate=fixturestate3;
                    fixturestarted=0;

                    if(run==false)
                    {
                        stateinfo="转盘到初始位";
                    }
                }
                break;
            case fixturestate3:
                if(lastone==false) 
                {
                    canload=true;
                    disableleftstepp=false;
                }
                if((glassloop&0x04)==0x04)
                {
                    //canunload=true;
                    //disablereloadstepp=false;
                }
                llstepp=false;
                fixturestarted=0;
                if(((glassloop&0x02)==0x02)&&(shieldpaste==0))
                {fixturestate=fixturestate3p1;}
                else
                {fixturestate=fixturestate7;}
                if(run==false)
                {
                    stateinfo="启动上料";
                }
                break;
            case fixturestate3p1:
                fixturetimes=fixturetimes+1;
                if((fixturetimes>fixturedelaytime))
                {
                    fixturestate=fixturestate4;
                    llstepp=false;
                    fixturetimes=0;
                    overphoto=0;
                    startphoto=0;
                }
                if(run==false)
                {
                    stateinfo="夹具拍照";
                }
                break;
            case fixturestate4:
                if(startphoto==0)
                {
                    startphoto=1;
                    overphoto=0;
                    imagephotoover=false;
                    CameraPlay(camera1);
                    
                }
                if(overphoto==1)
                {
                    if(photoalreadyerror==false)
                    {
                        overphoto=0;
                        startphoto=0;
                        fixturestate=fixturestate7;
                        fixturetimes=0;
                        allowpick=true;
                        llstepp=false;
                        disablemainstepp=false;
                        disablellstepp=true;
                    }
                    else
                    {
                        overphoto=0;
                        startphoto=0;
                        fixturestate=fixturestate7;
                        fixturetimes=0;
                        //fixturecanphoto=true;
                        llstepp=false;
                    }
                }
                break;
            case fixturestate7:
                if((d1000_get_outbit(loadvacuumout)==back)&&((willlastone==true))&&((glassloop&0x01)==0x00))
                {
                    lastone=true;
                    willlastone=false;
                    canload=false;
                }
                if(lastone==true)
                {
                    canload=false;
                }
                ///if((canload==true)||(canunload==true)||
                 //       ((photoalreadyproblem2==false)&&(pastefinished==false)&&((glassloop&0x02)==0x02)&&(firstload==false)))
                {disablellstepp=true;}
                llstepp=false;
                //if((canload==false)&&(canunload==false)&&
                //        ((outofrange==true)||(pastefinished==true)||(photoalreadyproblem2==true)||((glassloop&0x02)==0x00)||(firstload==true)||(shieldpaste==1)))
                {
                    firstload=false;
                    //outofrange=false;
                    //photoalreadyproblem2=false;
                    ////pastefinished=false;
                    fixturestate=fixturestate8;
                    fixturestarted=0;
                    llstepp=false;
                }
                if(run==false)
                {
                    stateinfo="各个工位完成";
                }
                break;
            case fixturestate8:
                if((fixturestarted==0))
                {
                    d1000_out_bit(turnplateout, 1-d1000_get_outbit(turnplateout));
                    fixturestarted=1;
                }
                if( ((d1000_in_bit(turnhomein)==0)||(d1000_in_bit(turnoutin)==0))
                        &&(fixturestarted==1)) 
                {
                    glassloop=glassloop*2;
                    currentposition=currentposition+1;
                    if((lastone==true)&&((glassloop&0x04)==0x00))
                    {
                        lastone=false;
                        lastoneover=true;
                    }
                    if(currentposition==3)
                    {
                        currentposition=1;
                    }
                    llstepp=false;
                    fixturestate=fixturestate3;
                    fixturestarted=0;
                    if(run==false)
                    {
                        stateinfo="转盘运行";
                    }
                }
                break;
            default:
                fixturestate=fixturestate1;
            }
        }//for if
        //}}}

        //{{{ 靠片
        if((run==true)||(linstepp==true))
        {
            switch(pressstate)
            {
            case pressstate1:
                presstimes=presstimes+1;
                // d1000_out_bit(stepenable2, back);
                if(presstimes>20)
                {pressstate=pressstate2;}
                break;
            case pressstate2:
                d1000_out_bit(correctout, back);// 靠片本位
                d1000_out_bit(beltout, back);// 开传送带
                d1000_out_bit(fibreout, front);// 光纤出位
                if((d1000_in_bit(fibreoutin)==0)||(linstepp==true))
                {
                    pressstate=pressstate3;
                    linstepp=false;
                    presstimes=0;
                }
                if(run==false)
                {
                    stateinfo="光纤检测出";
                }
                break;
            case pressstate3:
                if(lastone==true)
                {d1000_out_bit(beltout, front);}
                else
                {d1000_out_bit(beltout, back);}
                if((d1000_in_bit(fibrecheckin)==0)&&(lastone==false)&&(willlastone==false))
                {presstimes=presstimes+1;}
                else
                {presstimes=0;}
                buffertime=buffertime+1;
                if((buffertime>250)&&((glassloop&0x04)==0x04))
                {
                    buffertime=0;
                    glassbuffer=2;
                }
                if((presstimes>picktime)||(linstepp==true))
                {
                    buffertime=0;
                    // if(d1000_in_bit(prefibrecheckin)==1)
                        // d1000_out_bit(beltout, back);
                    // else
                        d1000_out_bit(beltout, front);

                    glassbuffer=glassbuffer+1;
                    pressstate=pressstate6;
                    linstepp=false;
                    presstimes=0;
                }
                if(run==false)
                {
                    stateinfo="靠片";
                }
                break;
            case pressstate6:
                d1000_out_bit(correctout, front);
                d1000_out_bit(fibreout, back);
                // if(d1000_in_bit(prefibrecheckin)==0)
                    // d1000_out_bit(beltout, front);
                if((d1000_in_bit(correctoutin)==0)||(linstepp==true))
                {
                    pressstate=pressstate7;
                    linstepp=false;
                    presstimes=0;
                }
                if(run==false)
                {
                    stateinfo="靠片完成";
                }
                break;
            case pressstate7:
                // if(d1000_in_bit(prefibrecheckin)==0)
                    // d1000_out_bit(beltout, front);
                presstimes=presstimes+1;
                if(((presstimes>photodelay)&&(d1000_in_bit(fibrehomein)==0))||(linstepp==true))
                {
                    correctready=true;
                    disableleftstepp=false;
                    d1000_out_bit(beltout, front);
                    pressstate=pressstate8;
                    linstepp=false;
                    presstimes=0;
                }
                if(run==false)
                {
                    stateinfo="靠片";
                }
                break;
            case pressstate8:
                d1000_out_bit(correctout, back);
                // if(d1000_in_bit(prefibrecheckin)==0)
                    // d1000_out_bit(beltout, front);
                if((d1000_in_bit(correcthomein)==0)||(linstepp==true))
                {
                    d1000_out_bit(beltout, front);
                    pressstate=pressstate9;
                    linstepp=false;
                    presstimes=0;
                    if(correctready==true)
                        disablelinstepp=true;
                }
                if(run==false)
                {
                    stateinfo="等待取片完成";
                }
                break;
            case pressstate9:
                // if(d1000_in_bit(prefibrecheckin)==0)
                    // d1000_out_bit(beltout, front);
                if(correctready==false)
                {
                    d1000_out_bit(correctout, back);
                    d1000_out_bit(beltout, back);
                    d1000_out_bit(fibreout, front);
                    pressstate=pressstate2;
                    linstepp=false;
                    presstimes=0;
                }

                break;
            default:
                pressstate=pressstate1;
            }
        }//end if
        //}}}

        //{{{  上料
        if((leftstepp==true)||(run==true)||(loadstate==loadstate5)
                ||(loadstate==loadstate6)||(loadstate==loadstate9)||(loadstate==loadstate10))
        {
            switch(loadstate)
            {

            case loadstate1:
                loadtimes=0;
                loadstate=loadstate1p1;
                break;
            case loadstate1p1:
                loadtimes=loadtimes+1;
                d1000_out_bit(stepenableout, 1);
                d1000_out_bit(loadout, 1);

                if((loadtimes>20))
                { 
                    loadstate=loadstate1p4;
                    loadservostarted=0;
                    loadservostarted2=0;
                    leftstepp=false;
                    loadtimes=0;
                }
                break;
            case loadstate1p4:
                loadorgstate=d1000_get_axis_status(loadaxy);
                loadorgstate=loadorgstate&0x00000004;
                temploadax=d1000_check_done(loadaxy);

                loadorgstater=d1000_get_axis_status(loadaxr);
                loadorgstater=loadorgstater&0x00000004;
                temploadaxr=d1000_check_done(loadaxr);

                if((temploadax!=0)&&(loadservostarted==0)&&(loadorgstate!=0))
                {
                    d1000_start_t_move(loadaxy,1000, 0, 1000, 0.3);

                    temploadax=0;
                }
                if((temploadaxr!=0)&&(loadservostarted==0)&&(loadorgstater!=0))
                {
                    d1000_start_t_move(loadaxr,1000, 0, 1000, 0.6);
                    loadservostarted=1;
                    temploadaxr=0;
                }

                if((temploadax!=0)&&(temploadaxr!=0))
                {
                    loadservostarted=0;
                    loadstate=loadstate2;

                    loadtimes=0;
                }

                if(run==false)
                {
                    stateinfo="上料搬运YR复位";
                }
                break;

            case loadstate2:
                temploadax=d1000_check_done(loadaxy);
                temploadaxr=d1000_check_done(loadaxr);

                if((temploadax!=0)&&(loadservostarted==0))
                {
                    d1000_home_move( loadaxy, 0, -1000, 0.3);
                }
                if((temploadaxr!=0)&&(loadservostarted==0))
                {
                    d1000_home_move( loadaxr, 0, -1000, 0.6);
                    loadservostarted=1;
                }
                if((temploadax==2)||(temploadaxr==2))
                {loadservostarted=0;}
                temploadax=d1000_check_done(loadaxy);
                temploadaxr=d1000_check_done(loadaxr);
                if((temploadax==4)&&(temploadaxr==4))
                {
                    d1000_out_bit(loadvacuumout, back);

                    d1000_set_command_pos(loadaxy,0);
                    d1000_set_command_pos(loadaxr,0);

                    loadservostarted=0;
                    loadstate=loadstate3;
                    leftstepp=false;
                    loadtimes=0;

                    if(run==false)
                    {
                        stateinfo="上料运行取片位";
                    }
                }
                break;
            case loadstate3:
                temploadax=d1000_check_done(loadaxy);
                temploadaxr=d1000_check_done(loadaxr);
                if((temploadax!=0)&&(loadservostarted==0))
                {
                    d1000_start_ta_move( loadaxy,coverx, 0, vexx, 0.3);
                    loadservostarted=1;
                }
                if((temploadaxr!=0)&&(loadservostarted2==0)/*&&(d1000_get_command_pos(loadaxy)<vexhigh)*/)
                {
                    d1000_start_ta_move( loadaxr,loadwaiting, 0, zvex, 0.6);
                    loadservostarted2=1;
                }

                temploadax=d1000_check_done(loadaxy);
                temploadaxr=d1000_check_done(loadaxr);

                if((temploadax!=0)&&(temploadaxr!=0)&&(loadservostarted==1)&&(loadservostarted2==1))
                {
                    loadservostarted=0;
                    loadservostarted2=0;
                    loadstate=loadstate4;
                    leftstepp=false;
                    loadtimes=0;

                    if(run==false)
                    {
                        stateinfo="上料等待取片";
                    }
                }
                break;

            case loadstate4:

                if(correctready==false)
                {disableleftstepp=true;}
                if((correctready==true))
                {
                    loadservostarted=0;

                    loadstate=loadstate4p1;
                    loadtimes=0;

                    if(run==false)
                    {
                        stateinfo="上料等待取片";
                    }
                }	 

                break;

            case loadstate4p1:

                if(loadservostarted==0)
                {
                    d1000_out_bit(loadout, 0);
                    loadservostarted=1;
                }

                if((d1000_in_bit(loadoutin)==0)&&(loadservostarted==1))
                {
                    loadservostarted=0;
                    loadstate=loadstate5;
                    leftstepp=false;
                    loadtimes=0;

                    if(run==false)
                    {
                        stateinfo="上料取片";
                    }
                }
                break;

            case loadstate5:
                d1000_out_bit(loadvacuumout, front);
                loadtimes=loadtimes+1;
                if(loadtimes>loadtime)
                {
                    loadservostarted=0;
                    loadstate=loadstate6;
                    loadtimes=0;
                    if(run==false)
                    {
                        stateinfo="传送带取片";
                    }
                }
                break;
            case loadstate6:
                if(loadservostarted==0)
                {
                    d1000_out_bit(loadout, 1);
                    loadservostarted=1;
                }
                if((d1000_in_bit(loadhomein)==0)&&(loadservostarted==1))
                {
                    if(((d1000_in_bit(loadvacuumin)==0)||(leftstepp==true)))
                    {
                        correctready=false;
                        disablelinstepp=false;
                        loadvacuumcounter=0;
                        loadservostarted=0;
                        loadstate=loadstate7;
                        leftstepp=false;
                        loadtimes=0;
                    }
                    else
                    {
                        loadvacuumcounter=loadvacuumcounter+1;
                        //if(loadvacuumcounter<=2)
                        //	loadstate=loadstate4;
                        //else
                        {
                            correctready=false;
                            disablelinstepp=false;

                            smallproblem=true;
                            loadalarm=true;
                            loadstate=loadstate4;

                            loadvacuumcounter=0;
                        }
                        loadservostarted=0;

                        leftstepp=false;
                        loadtimes=0;
                    }
                    if(run==false)
                    {
                        stateinfo="搬运上料取片";
                    }
                }
                break;

            case loadstate7:
                temploadaxr=d1000_check_done(loadaxr);
                temploadax=d1000_check_done(loadaxy);
                if((temploadax!=0)&&(loadservostarted==0))
                {
                    d1000_start_ta_move( loadaxy,photox, 0, vexx, 0.3);
                    loadservostarted=1;
                }
                if((temploadaxr!=0)&&(loadservostarted2==0)&&(d1000_get_command_pos( 0 )>repastey))
                {
                    d1000_start_ta_move( loadaxr,numberx, 0, zvex, 0.6);
                    loadservostarted2=1;
                }
                temploadaxr=d1000_check_done(loadaxr);
                temploadax=d1000_check_done(loadaxy);

                if((temploadax!=0)&&(temploadaxr!=0)&&(loadservostarted==1)&&(loadservostarted2==1))
                {
                    loadservostarted=0;
                    loadservostarted2=0;
                    loadstate=loadstate8;
                    leftstepp=false;
                    if(canload==false)
                    {disableleftstepp=true;}
                    loadtimes=0;

                    if(run==false)
                    {
                        stateinfo="等待上料放片";
                    }
                }
                break;
            case loadstate8:
                if(canload==true)
                {
                    loadservostarted=0;
                    loadstate=loadstate8p1;

                    loadtimes=0;

                    if(run==false)
                    {
                        stateinfo="上料放片";
                    }
                }
                break;
            case loadstate8p1:
                if((loadservostarted==0))
                {
                    d1000_out_bit(loadout, 0);
                    loadservostarted=1;
                }
                if((d1000_in_bit(loadoutin)==0)&&(loadservostarted==1))
                {
                    loadservostarted=0;
                    loadstate=loadstate9;
                    leftstepp=false;
                    loadtimes=0;

                    if(run==false)
                    {
                        stateinfo="上料放片";
                    }
                }
                break;

            case loadstate9:
                loadtimes=loadtimes+1;
                if(currentposition==1)
                {
                    {d1000_out_bit(turnvacuumout2, front);}
                    if(loadtimes>picktime)
                    {
                        if(d1000_in_bit(turnvacuumin2)==1)
                        {
                            preturnvacu2error=true;
                        }
                    }
                }
                if(currentposition==2)
                {
                    d1000_out_bit(turnvacuumout1, front);
                    if(loadtimes>picktime)
                    {
                        if(d1000_in_bit(turnvacuumin1)==1)
                        {
                            preturnvacu1error=true;
                        }
                    }
                }
                d1000_out_bit(loadvacuumout, back);

                if(loadtimes>picktime)
                {
                    loadservostarted=0;
                    loadstate=loadstate10;
                    loadtimes=0;
                    if(run==false)
                    {
                        stateinfo="上料取取片";
                    }
                }
                break;

            case loadstate10:
                if((loadservostarted==0))
                {
                    d1000_out_bit(loadout, 1);
                    loadservostarted=1;
                }
                if((d1000_in_bit(loadhomein)==0)&&(loadservostarted==1))
                {
                    if(preturnvacu1error==true)
                    {
                        preturnvacu1error=false;
                        turnvacu1error=true;
                        smallproblem=true;
                    }
                    if(preturnvacu2error==true)
                    {
                        preturnvacu2error=false;
                        turnvacu2error=true;
                        smallproblem=true;
                    }
                    // glassloop=glassloop+1;
                    canload=false;
                    loadservostarted=0;
                    loadstate=loadstate3;
                    leftstepp=false;
                    // if((canload==false)&&(canunload==false)&&((photoalreadyproblem2==true)||(pastefinished==true)||((glassloop&0x02)==0x00)))
                    // {disablellstepp=false;}
                    loadtimes=0;

                    if(run==false)
                    {
                        stateinfo="上料放片回";
                    }
                }
                break;
            default:
                loadstate=loadstate1;
            }//switch
        }
        //}}}
    }//for while
}//for api

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
        Sleep(10);

        lineoldTime=linenewTime;

    }//for wile
}//for api


void CVAFS2Dlg::Oncounterzero1() 
{
    // TODO: Add your control notification handler code here
    pastecounter=0;

}

void CVAFS2Dlg::Onlight() 
{
    // TODO: Add your control notification handler code here
    bool temp;
    temp=turnon;
    if(temp==true)
    {
        turnon=false;

        SetDlgItemText(IDC_light,"照明关");

    }
    if(temp==false)
    {
        turnon=true;

        SetDlgItemText(IDC_light,"照明开");
    }

}



void CVAFS2Dlg::C4TcpSend(CString str)
{
    char m_SBuf[100];
    char m_RBuf[200];///////////////////////////////


    for(int i=0;i<100;i++){m_SBuf[i]=0;}
    for(int i=0;i<200;i++) m_RBuf[i] = 0;

    strcpy(m_SBuf,str);

    C4pSocket.Send(m_SBuf,strlen(str),0);

    C4pSocket.Receive(m_RBuf,200,0);////////////////////////
    CString display;
    display=m_RBuf;
    if(display!="")
    {
        if(display.Left(1)=="!")
        {

            display="";
            C4commerror=true;
            communicateerror=true;
            //MessageBox("通讯错误");

        }
        else
        {


            int a=display.Find(",",0);
            CString order1=display.Mid(1,a-1);

            if(order1=="getstatus")
            {
                if((display.Mid(22,4)!="0000")&&(display.Mid(22,4)!="1504"))
                {
                    display="";
                    C4commerror=true;
                    communicateerror=true;
                }
                else
                {
                    C4b_ready=atoi(display.Mid(20,1));
                    C4b_running=atoi(display.Mid(19,1));
                    C4b_pause=atoi(display.Mid(18,1));
                    C4b_error=atoi(display.Mid(17,1));
                    C4b_stop=atoi(display.Mid(16,1));
                    C4b_safeguard=atoi(display.Mid(15,1));
                }


            }
            else if(order1=="execute")
            {
                if(display.Mid(11,1)=="X")
                {
                    C4cpx=atof(display.Mid(13,10));
                    C4cpy=atof(display.Mid(25,10));
                    C4cpz=atof(display.Mid(37,10));
                    C4cpu=atof(display.Mid(49,10));

                }
                else
                {
                }


            }
            else
            {

            }




        }


    }

}

void CVAFS2Dlg::OnBnClickedlight2()
{
    // TODO: 在此添加控件通知处理程序代码
    int temp;
    temp=withbeep;
    if(temp==0)
    {
        withbeep=1;

        SetDlgItemText(IDC_withbeep,"启用蜂鸣");

    }
    if(temp!=0)
    {
        withbeep=0;

        SetDlgItemText(IDC_withbeep,"屏蔽蜂鸣");
    }
}


void CVAFS2Dlg::OnBnClickedBelt()
{
	// TODO: 在此添加控件通知处理程序代码
	if((beltstop==false)&&(d1000_in_bit(fibrecheckin)==1))
	{
	     beltstop=true;
	}
	else if(beltstop==true)
	{
		beltstop=false;
	}
}
