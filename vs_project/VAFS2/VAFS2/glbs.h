#if !defined(GLASH)
#define GLASH
#include "stdafx.h"


//using namespace RCAPINet;
//gcroot< RCAPINet::Spel ^>m_spel;

using namespace Halcon;
int fixturestarted=0;
bool debugcase=false;
bool leftload=true;
bool testone=false;
long fixturex=0;
long fixturey=0;
long numberx=0;
long numbery=0;
long stepx=0;
long stepy=0;
long specialx=0;
long specialy=0;
long coverx=0;
long covery=0;
long vexfixturex=0;
long vexfixturey=0;

bool camera1firstphoto=false;
bool camera2firstphoto=false;
long camera1width= 1944;
long camera1height=2592;
long camera2width=2592;
long camera2height=1944;

 int modalorg11=0;
 int modalorg12=0;
 int modalorg21=0;
 int modalorg22=0;
 long verifypastex=0;
 long verifypastey=0;
 long shieldpaste=0;

	LARGE_INTEGER m_BeginTime;
	LARGE_INTEGER m_EndTime;
	LARGE_INTEGER linenewTime;
	LARGE_INTEGER lineoldTime;
	LARGE_INTEGER fixturenewTime;
	LARGE_INTEGER fixtureoldTime;
	LARGE_INTEGER m_Frequency;
	double fTime;
#define PARAINPUT tongueout<<tonguein<<vextongueout<<vextonguein<< vexmainmotorlow<<vexmainmotorhigh<<  mainmotorlength<< fixturedelaytime <<picktime<< pickx<< picky<<photox<< photoy<<photox2<< photoy2<< pastex<< pastey<< rollerfinished<< vexx<< vexy<< vexroller<<vturnplate<<withbeep<<carrytime<<pasteangle<<pickangle<<keypastextemp<<keypasteytemp<<pushertime<<minscore11<<minscore12<<minscore21<<minscore22<<comno<<photodelay<<loadtime<<unloadtime<<searchrange<<zpick<<zpush<<zphoto<<zvex<<shieldpaste<<searchrange2<<photor<<repeat<<repasteangle<<repastex<<repastey<<reloadwaiting<<reloadpush<<reloadpick<<loadpush<<loadpick<<loadwaiting<<vload<<fixturex<<fixturey<<numberx<<numbery<<stepx<<stepy<<specialx<<specialy<<coverx<<covery<<vexfixturex<<vexfixturey<<loadx<<loady<<unloadx<<unloady<<films<<filml<<vexload<<vexunload<<load0<<load1<<load2<<unload0<<unload1<<unload2
#define PARAOUTPUT tongueout>>tonguein>>vextongueout>>vextonguein>> vexmainmotorlow>>vexmainmotorhigh>>  mainmotorlength>> fixturedelaytime>>picktime>>pickx>> picky>>photox>> photoy>>photox2>> photoy2>>pastex>>pastey>>rollerfinished>>vexx>>vexy>>vexroller>>vturnplate>>withbeep>>carrytime>>pasteangle>>pickangle>>keypastextemp>>keypasteytemp>>pushertime>>minscore11>>minscore12>>minscore21>>minscore22>>comno>>photodelay>>loadtime>>unloadtime>>searchrange>>zpick>>zpush>>zphoto>>zvex>>shieldpaste>>searchrange2>>photor>>repeat>>repasteangle>>repastex>>repastey>>reloadwaiting>>reloadpush>>reloadpick>>loadpush>>loadpick>>loadwaiting>>vload>>fixturex>>fixturey>>numberx>>numbery>>stepx>>stepy>>specialx>>specialy>>coverx>>covery>>vexfixturex>>vexfixturey>>loadx>>loady>>unloadx>>unloady>>films>>filml>>vexload>>vexunload>>load0>>load1>>load2>>unload0>>unload1>>unload2

HANDLE  m_hDevice=NULL;
BOOL                  m_bStartCapture= false; 

//系统状态
bool run=false;
bool stop=true;

bool smallproblem=false;
bool bigproblem=false;
bool photoverify=false;
bool metalverify=false;
bool cyclephoto=false;
bool cyclephoto2=false;
bool cyclephoto3=false;
bool cyclephoto4=false;
bool initposition=false;
int modalselect=0;
int cameraselect=0;
float xscale=0.01;
float metalscale=0.01;
float metalyscale=0.01;


float xdiv=0;
float photo2angle=0;
float photo1angle=0;
float photo4angle=0;
float photo3angle=0;
float ydiv=0;
float xdiv2=0;
float ydiv2=0;
float xdiv1=0;
float ydiv1=0;
float yscale=1;

float keypastex=0;
float keypastey=0;
float keypastextemp=972;
float keypasteytemp=1296;
float camera2xdiv;
float camera2ydiv;


long pastecounter=0;

bool updowninreset=false;
bool updownoutreset=false;

CString stateinfo;
CString verifyinfo;
CString fixtureinfo;


bool linready=false;
bool loutready=false;
bool leftloadupready=false;
bool rightloadupready=false;
bool leftpeelready=false;
bool rightpeelready=false;
bool leftunloadready=false;
bool rightunloadready=false;
bool photoready=false;
bool platformready=false;



int loadservostarted=0;
int loadservostarted2=0;
long correcttime=0;
long fibrechecktime=0;
long loadpickr=0; 
long loadpushr=0; 
long vloadr=0; 


bool mainstepp=false;
bool mainstepm=false;
bool linstepp=false;
bool loutstepp=false;
bool llstepp=false;
bool leftstepp=false;
bool rightstepp=false;
bool peelstepp=false;
bool unloadstepp=false;


bool fixturestepp=false;
bool pressstepp=false;
bool loadstepp=false;

bool disablelinestepm=false;
bool disablelinestepp=false;
bool disablefixturestepp=false;
bool disablefixturestepm=false;

bool disableloadstepp=false;
bool disablemainstepp=false;
bool disablelinstepp=false;
bool disableloutstepp=false;
bool disablellstepp=false;
bool disableleftstepp=false;
bool disablerightstepp=false;
bool disablepeelstepp=false;
bool disableunloadstepp=false;
bool reloadmod=false;

bool disablepressstepp=false;

//输出IO定义
//dmc1000b-1
const short  stepenableout=1;
const short  robotemergencyout=2;
const short  correctout=3;
const short  fibreout=4;
const short  loadout=5;
const short  loadvacuumout=6;
const short  turnplateout=7;
const short  turnvacuumout1=8;
const short  turnvacuumout2=9;
const short  fpcout=10;
const short  Probotvacuumout=11;


////dmc1000-2
const short  beltout=35;// 第二张板卡输出从33开始编号
const short  alarmlightout=36;
const short  alarmbeepout=37;

const short  front=0;
const short  back=1;

//输入IO定义
//dmc1000b-1
const short  loadhomein=5;
const short  loadoutin=6;
const short  loadvacuumin=7;
const short  turnvacuumin1=8;
const short  turnvacuumin2=9;
const short  robotvacuumin=10;
const short  turnhomein=11;
const short  turnoutin=12;
const short  fpchomein=13;
const short  fpcoutin=14;
const short  doorin=15;

////dmc1000-2
const short  fibrecheckin=37;
const short  unloadfibrecheckin=38;
const short  emergencyin=39;
const short  startin=40;
const short  stopin=41;
const short  presshomein=42;
const short  pressoutin=43;
const short  correcthomein=44;
const short  correctoutin=45;
const short  fibrehomein=46;
const short  fibreoutin=47;

const int  loadaxy=0;
const int  loadaxr=1;


//系统故障处理
#define ERROR_LIST(F)       \
	F(emergency, "急停开关断开")   \
	F(loadhome, "上料本位")   \
	F(loadout, "上料出位")   \
	F(loadvacu, "上料真空")   \
	F(turnhomevacu, "转盘本位真空")   \
	F(turnoutvacu, "转盘出位真空")   \
	F(robotvacu, "ROBOT真空")   \
	F(turnhome, "转盘本位")   \
	F(turnout, "转盘出位")   \
	F(fpchome, "fpc本位")   \
	F(fpcout, "fpc出位")   \
	F(door, "门锁开关断开")   \
	F(glasscamera, "屏拍照错误")   \
	F(traycamera, "盘拍照错误")   \
	F(commun, "机器人通信错误")   


enum error_list {
#define DEFINE(a,b) a##err,
    ERROR_LIST(DEFINE)
#undef DEFINE
        TOTAL_ERR_NUM
};

bool showerr[TOTAL_ERR_NUM];
int errtime[TOTAL_ERR_NUM];

const CString err[TOTAL_ERR_NUM]=
{   
#define DEFINE(a,b) b,
    ERROR_LIST(DEFINE)
#undef DEFINE
};

long photor=0;
long repeat=1;
long repasteangle=0;
long repastex=0;
long repastey=0;
long reloadwaiting=0;
long reloadpush=0;
long reloadpick=0;
long loadpush=0;
long loadpick=0;
long loadwaiting=0;
long vload=0;


long tongueout=100;
long tonguein=1000;
long vextongueout=30000;
long vextonguein=30000;

long vexmainmotorlow=4;
long vexmainmotorhigh=60000;
long mainmotorlength=1000;

int fixturedelaytime=2;
int picktime=10;
int loadtime=30;
int photodelay=10;
int unloadtime=30;
int fixtureouttime=10;
int pushertime=1;


long pickx=14000;
long picky=10000;
long photox=6000;
long photoy=6000;
long photox2=7000;
long photoy2=7000;
long pastex=0;

long pastey=0;

long rollerfinished=9000;
long pasteangle=0;
long pickangle=10000;
long searchrange=200;
long searchrange2=200;
long loadx=0;
long loady=0;
long unloadx=0;
long unloady=0;
long vexload,vexunload,load0,load1,load2,unload0,unload1,unload2;
long vexx=0;
long vexy=60000;
long films=4;
long filml=0;
long vexroller=60000;
long carrytime=10;
long vturnplate=20000;

int withbeep=1;

float minscore11=0;
float minscore12=0;
float minscore21=0;
float minscore22=0;
long   comno=1;
float minscore32=0;

CString 	currentregionsname1="\\current1.reg";
CString 	currentregionsname2="\\current2.reg";
CString 	currentregionsname3="\\current3.reg";
CString 	currentregionsname4="\\current4.reg";

CString    currentrcpname="\\current.rcp";
CString 	currentparametername="\\current.para";
CString 	currentmodelname="\\current.shm";
CString 	currentmodelname2="\\current2.shm";
CString 	currentmodelname21="\\current21.shm";
CString 	currentmodelname22="\\current22.shm";
CString 	currentmodelname31="\\current31.shm";
CString 	currentmodelname32="\\current32.shm";
CString 	currentmodelname41="\\current41.shm";
CString 	currentmodelname42="\\current42.shm";


CString     currentphotoname="\\current.photo";
CString     listrcpname="\\listrcp.txt";
CString     rcpname="current";
CString     counterfilename="counter.txt";
CString currentdir;
CString passwordname;
CString password;


int startphoto=0;
int overphoto=0;
int startphoto2=0;
int overphoto2=0;
int startphoto3=0;
int overphoto3=0;
int startphoto4=0;
int overphoto4=0;
bool visionphoto=false;

float matchscore=0;
float matchscore2=0;
float matchscore21=0;
float matchscore22=0;
float rematchscore=0;
float rematchscore2=0;
float rematchscore21=0;
float rematchscore22=0;
float newmatchscore1[6]={0,0,0};
float newmatchscore2[6]={0,0,0};
float newrematchscore1[6]={0,0,0};
float newrematchscore2[6]={0,0,0};
float newcenterx1[6]={0,0,0};
float newcentery1[6]={0,0,0};
float newcenterx2[6]={0,0,0};
float newcentery2[6]={0,0,0};
float disnewcenterx1[6];//={0,0,0};
float disnewcentery1[6]={0,0,0};
float disnewcenterx2[6]={0,0,0};
float disnewcentery2[6]={0,0,0};
float centerx=0;
float centery=0;
float centerx2=0;
float centery2=0;
float recenterx=0;
float recentery=0;
float recenterx2=0;
float recentery2=0;
float camera21centerx=0;
float camera21centery=0;
float camera22centerx=0;
float camera22centery=0;


float newrecenterx1[6]={0,0,0};
float newrecentery1[6]={0,0,0};
float newrecenterx2[6]={0,0,0};
float newrecentery2[6]={0,0,0};
float disnewrecenterx1[6]={0,0,0};
float disnewrecentery1[6]={0,0,0};
float disnewrecenterx2[6]={0,0,0};
float disnewrecentery2[6]={0,0,0};
float recamera21centerx=0;
float recamera21centery=0;
float recamera22centerx=0;
float recamera22centery=0;
float camera3centerx=0;
float camera3centery=0;
float camera4centerx=0;
float camera4centery=0;


float newphotoangle[6]={0,0,0};
float newrephotoangle[6]={0,0,0};
float photoangle=0;
float rephotoangle=0;

 DWORD tempinax,tempoutax,temppdownax,tempppax,temprightax,templeftax,templzax,templxax,templupax,templdownax;

int servostarted=0;
int xtarted=0;
int zstarted=0;
int linstarted=0;
int loutstarted=0;
int llstarted=0;
int leftservostarted=0;
int rightservostarted=0;
int peelservostarted=0;
int unloadservostarted=0;
typedef enum{
	loadstate1,
	loadstate1p1,
	loadstate1p2,
	loadstate1p3,
	loadstate1p4,
	loadstate1p5,
	loadstate1p6,
	loadstate1p7,
	loadstate2,
	loadstate2p1,
	loadstate3,
	loadstate3p1,
	loadstate4,
	loadstate4p1,
	loadstate5,
	loadstate6,
	loadstate7,
	loadstate8,
	loadstate8p1,
	loadstate8p2,
	loadstate8p3,
	loadstate9,
	loadstate10,
	loadstate11,
	loadstate12,
	loadstate13,
	loadstate14,
	loadstate15,
	loadstate16,
	loadstate17,
	loadstate18,
	loadstate19,
	loadstate20,
	loadstate21

}loadstates;
loadstates loadstate=loadstate1;
//main loop state
typedef enum{
	state1,
	state1p0p0,
	state1p0p1,
	state1p0p2,
	state1p1,
	state1p2,
	state1p3,
	state1p4,
	state2,
    state2p1,
	state2p2,
	state2p2p1,
	state2p3,
	state3,
	state3p1,
	state4,
	state4p1,
	state4p1p5,
	state4p2,
	state4p3,
	state4p4,
	state5,
	state5p1,
	state6,
	state6p1,
	state7,
	state7p1,
	state8,
	state8p0p1,
	state8p0p2,
	state8p0p3,
	state8p1,
	state8p1p5,
	state8p2,
	state8p3,
	state9,
	state9p1,
	state10,
	state11,
	state12,
	state13,
	state14,
	state15,
	state16,
	state17,
	state18,
	state19,
	state20,
	state21,
	state22,
	state23,
	state24,
	state25,
	state25p1,
	state26,
	state27,
	state28,
	state29,
	state30,
	state31,
	state32,
	state33,
	state34,
	state35,
	state36,
	state37,
	state38,
	state39,
	state40,

}state;


state machinestate=state1;


typedef enum{
	pressstate1,
	pressstate1p1,
	pressstate1p2,
	pressstate2,
	pressstate2p1,
	pressstate2p2,
	pressstate3,
	pressstate3p0,
	pressstate3p1,
	pressstate3p2,
    pressstate4,
	pressstate5,
	pressstate6,
	pressstate6p1,
	pressstate7,
	pressstate8,
	pressstate9,
	pressstate10,
	pressstate11,
	pressstate12,
	pressstate13,
	pressstate14,
	pressstate15,
	pressstate16,
	pressstate17,
	pressstate18,
	pressstate19

}pressstates;
pressstates pressstate=pressstate1;

//backline  loop state
//backline  loop state
typedef enum{
	linstate1,
	//linstate1p1p1,
	linstate1p1,
	linstate1p2,
	linstate2,
	linstate2p1,
	linstate2p2,
	linstate3,
	linstate3p1,
	linstate3p2,
	linstate3p3,
	linstate4,
	linstate5,
	linstate6,
	linstate6p1,
	linstate7,
	linstate8,
	linstate8p1,
	linstate8p2,
	linstate8p3,
	linstate9,
	linstate9p1,
	linstate10,
	linstate11,
	linstate12,
	linstate13,
	linstate14,
	linstate15,
	linstate16,
	linstate17,
	linstate18,
	linstate19

}linstates;
linstates linstate=linstate1;

typedef enum{
	loutstate1,
	loutstate1p1p1,
	loutstate1p1,
	loutstate1p2,
	loutstate1p3,
	loutstate1p4,
	loutstate2,
	loutstate2p1,
	loutstate2p2,
	loutstate3,
	loutstate3p1,
	loutstate3p2,
	loutstate3p3,
	loutstate4,
	loutstate5,
	loutstate6,
	loutstate6p1,
	loutstate7,
	loutstate8,
	loutstate8p1,
	loutstate8p2,
	loutstate8p3,
	loutstate9,
	loutstate9p1,
	loutstate10,
	loutstate11,
	loutstate12,
	loutstate13,
	loutstate14,
	loutstate15,
	loutstate16,
	loutstate17,
	loutstate18,
	loutstate19

}loutstates;
loutstates loutstate=loutstate1;

typedef enum{
	llstate1,
	llstate1p1,
	llstate2,
	llstate2p1,
	llstate2p2,
	llstate3,
	llstate3p1,
	llstate3p2,
	llstate3p3,
	llstate4,
	llstate5,
	llstate6,
	llstate6p1,
	llstate7,
	llstate8,
	llstate9,
	llstate9p1,
	llstate10,
	llstate11,
	llstate12,
	llstate13,
	llstate14,
	llstate15,
	llstate16,
	llstate16p1,
	llstate16p2,
	llstate16p3,
	llstate16p4,
	llstate16p5,
	llstate17,
	llstate18,
	llstate18p1,
	llstate19,
	llstate20,
	llstate21,
	llstate22,
	llstate23,
	llstate24,
	llstate25,
	llstate26,
	llstate27

}llstates;
llstates llstate=llstate1;

typedef enum{
	loadup,
	peelup,
	peeldown,
	unloadup,
	unloaddown,
	loaddown,
	none

}peelpositons;
peelpositons leftposition=none;
peelpositons rightposition=none;


typedef enum{
	leftstate1,
	leftstate1p1,
	leftstate1p2,
	leftstate1p2p0,
	leftstate1p2p1,
	leftstate1p2p2,
	leftstate1p2p3,
	leftstate1p2p4,
	leftstate1p3,
	leftstate1p4,
	leftstate2,
	leftstate2p1,
	leftstate2p2,
	leftstate2p1p5,
	leftstate2p3,
	leftstate2p4,
	leftstate2p4p1,
	leftstate2p4p2,
	leftstate2p5,
	leftstate2p6,
	leftstate2p7,
	leftstate2p8,
	leftstate3,
	leftstate3p0,
	leftstate3p1,
	leftstate3p2,
    leftstate4,
	leftstate5,
	leftstate6,
	leftstate6p1,
	leftstate7,
	leftstate7p1,
	leftstate7p2,
	leftstate7p3,
	leftstate7p4,
	leftstate8,
	leftstate8p1,
	leftstate8p1p5,
	leftstate8p1p6,
	leftstate8p2,
	leftstate8p3,
	leftstate8p4,
	leftstate8p5,
	leftstate9,
	leftstate10,
	leftstate10p1,
	leftstate11,
	leftstate12,
	leftstate12p1,
	leftstate13,
	leftstate14,
	leftstate15,
	leftstate16,
	leftstate17,
	leftstate18,
	leftstate19

}leftstates;
leftstates leftstate=leftstate1;

typedef enum{
	rightstate1,
	rightstate2,
	rightstate2p1,
	rightstate3,
    rightstate4,
	rightstate5,
	rightstate6,
	rightstate6p1,
	rightstate7,
	rightstate8,
	rightstate9,
	rightstate10,
	rightstate10p1,
	rightstate11,
	rightstate12,
	rightstate12p1,
	rightstate13,
	rightstate14,
	rightstate15,
	rightstate16,
	rightstate17,
	rightstate18,
	rightstate19

}rightstates;
rightstates rightstate=rightstate1;

typedef enum{
	peelstate1,
	peelstate1p1,
	peelstate1p2,
	peelstate1p2p0,
	peelstate1p2p1,
	peelstate1p2p2,
	peelstate1p2p3,
	peelstate1p2p4,
	peelstate1p3,
	peelstate1p4,
	peelstate2,
	peelstate2p1,
	peelstate2p2,
	peelstate2p1p5,
	peelstate2p3,
	peelstate2p4,
	peelstate2p4p1,
	peelstate2p4p2,
	peelstate2p5,
	peelstate2p6,
	peelstate2p7,
	peelstate2p8,
	peelstate3,
	peelstate3p0,
	peelstate3p1,
	peelstate3p2,
    peelstate4,
	peelstate5,
	peelstate6,
	peelstate6p1,
	peelstate7,
	peelstate7p1,
	peelstate7p2,
	peelstate7p3,
	peelstate7p4,
	peelstate8,
	peelstate8p1,
	peelstate8p1p5,
	peelstate8p1p6,
	peelstate8p2,
	peelstate8p3,
	peelstate8p4,
	peelstate8p5,
	peelstate9,
	peelstate10,
	peelstate11,
	peelstate12,
	peelstate13,
	peelstate14,
	peelstate15,
	peelstate16,
	peelstate17,
	peelstate18,
	peelstate19

}peelstates;
peelstates peelstate=peelstate1;

typedef enum{
	unloadstate1,
	unloadstate1p1,
	unloadstate2,
	unloadstate3,
	unloadstate3p0,
	unloadstate3p1,
	
    unloadstate4,
	unloadstate5,
	unloadstate5p1,
	unloadstate5p2,
	unloadstate6,
	unloadstate6p1,
	unloadstate7,

	unloadstate8,

	unloadstate9,
	unloadstate10,
	unloadstate11,
	unloadstate12,
	unloadstate13,
	unloadstate14,
	unloadstate15,
	unloadstate16,
	unloadstate17,
	unloadstate18,
	unloadstate19

}unloadstates;
unloadstates unloadstate=unloadstate1;

typedef enum{
	fixturestate1,
	fixturestate1p1,
	fixturestate1p2,
	fixturestate2,
	fixturestate2p1,
	fixturestate2p2,
	fixturestate2p3,
	fixturestate3,
	fixturestate3p0,
	fixturestate3p1,
	fixturestate3p2,
    fixturestate4,
	fixturestate5,
	fixturestate6,
	fixturestate6p1,
	fixturestate7,
	fixturestate8,
	fixturestate9,
	fixturestate10,
	fixturestate11,
	fixturestate12,
	fixturestate13,
	fixturestate14,
	fixturestate15,
	fixturestate16,
	fixturestate17,
	fixturestate18,
	fixturestate19

}fixturestates;
fixturestates fixturestate=fixturestate1;

int	 bright = 20;
int gain = 30;
int	shutter = -4;
int shutter2 =-4;
int	shutter3 = -4;
int shutter4 =-4;
int	shutter5 = -2;
int gain2 =-2;
float	contrast1 = 0;
float contrast2=0;

float contrast11;
float contrast12;
float contrast21;
float contrast22;


 
bool imagephotoover=false;

unsigned char * pImageData;



 
bool imagephotoover2=false;
unsigned char * pImageData2;



bool imagephotoover3=false;
BYTE* pImageData3;

bool imagephotoover4=false;
BYTE* pImageData4;


	
Hobject Image1,Image2,Image2temp;
//HWindow m_Window,m_Window2;	
Hlong m_Windowid,m_Window2id;
HTuple ShapeModel11,ShapeModel12,ShapeModel21 ,ShapeModel22;
Hobject Regions1,Regions2,Regions3,Regions4; 
float zoomfactor=1;	
int zoomupdown=0;
int zoomleftright=0;


float model1x[6]={1,1,1,1,1,1};
float model1y[6]={1,1,1,1,1,1};
float model2x[6]={2,2,2,1,1,1};
float model2y[6]={2,2,2,1,1,1};
float remodel1x[6]={1,1,1,1,1,1};
float remodel1y[6]={1,1,1,1,1,1};
float remodel2x[6]={2,2,2,1,1,1};
float remodel2y[6]={2,2,2,1,1,1};
//int modelcount=0;

 float model11x=1;
 float model11y=1;
 float model12x=2;
 float model12y=2;
 float model21x=1;
 float model21y=1;
 float model22x=2;
 float model22y=2;
 
 float remodel11x=1;
 float remodel11y=1;
 float remodel12x=2;
 float remodel12y=2;
 float remodel21x=1;
 float remodel21y=1;
 float remodel22x=2;
 float remodel22y=2;

 float model11halfx=0;
 float model11halfy=0;
  float model12halfx=0;
 float model12halfy=0;
  float model21halfx=0;
 float model21halfy=0;
  float model22halfx=0;
 float model22halfy=0;

 float camera1divx;
 float camera1divy;
 float camera1divangle;
 float camera1r;
 float camera2divx;
 float camera2divy;
 float camera2divangle;

  float recamera2divx;
 float recamera2divy;
 float recamera2divangle;

 bool notphoto=false;

void MyHalconExceptionHandler(const Halcon::HException& except)
{
  throw except;	
}




float visionx,visiony;
float revisionx,revisiony;


long zpick=0;
long zpush=0;
long zphoto=0;
long zvex=0;



INT camera1,camera2;
INT CALLBACK SnapCallBack1(INT iCamID, BYTE *pImageBuffer, tDSFrameInfo *pFrInfo)
{  
	CameraPause(camera1);
	if(imagephotoover==false)
	{	
	/*	BYTE* blue=  new BYTE[4384 * 3288 ];
	BYTE* green=  new BYTE[4384 * 3288  ];
	BYTE* red= new BYTE[4384 * 3288  ];
	BYTE* byImageBuf = new BYTE[4384 * 3288 * 3];*/


  
	BYTE* pBmp24 = CameraISP(camera1,pImageBuffer, pFrInfo);




	 
	try
	{
	
				
					int sensorx=2592;
					int sensory=1944;
			
					gen_image_interleaved(&Image1,(long)pBmp24,"bgr",sensorx,sensory,-1,"byte",0,0,0,0,-1,0);
					//gen_image_interleaved(&imagergb1,(long)pBmp24,"bgr",sensorx,sensory,-1,"byte",0,0,0,0,-1,0);
                   // rgb1_to_gray(Image1, &Image1);
				   //rotate_image(Image1,&Image1,270,"constant");
				    //rotate_image(imagergb1,&imagergb1,270,"constant");
					/*  HTuple  CameraParameters, CameraPose;*/
  //Code generated by Calibration 01
;
  // CameraParameters.Reset();
  //CameraParameters[0] = 0.0160121;
  //CameraParameters[1] = -301.001;
  //CameraParameters[2] = 2.2006e-006;
  //CameraParameters[3] = 2.2e-006;
  //CameraParameters[4] = 1295.87;
  //CameraParameters[5] = 972.047;
  //CameraParameters[6] = 2592;
  //CameraParameters[7] = 1944;
  //CameraPose.Reset();
  //CameraPose[0] = 0.00270462;
  //CameraPose[1] = -0.00416919;
  //CameraPose[2] = 0.509239;
  //CameraPose[3] = 0.114074;
  //CameraPose[4] = 359.491;
  //CameraPose[5] = 358.874;
  //CameraPose[6] = 0;
  //set_origin_pose(CameraPose, -0.5*0.2, -0.4*0.2, 0, &CameraPose);

  //  Hobject  Map; 
  //gen_image_to_world_plane_map(&Map, CameraParameters, CameraPose, 
  //  1944  ,2592 ,1944 ,2592 ,0.2/2592, "bilinear");
  ////Now, images can be rectified using the rectification map
  //map_image(Image1, Map, &Image1);
	
	               // disp_color(Image2,m_Window2id);
	}
	
		catch (HException &except)
	{	
		Herror error_num;
	
		 error_num= except.err;
		 return 0;
		 //photo2problem=true;
        	//MessageBox(error_num);
		 
	}
    imagephotoover=true;



}	
	return 0;
}

INT CALLBACK SnapCallBack2(INT iCamID, BYTE *pImageBuffer, tDSFrameInfo *pFrInfo)
{  
    CameraPause(camera2);
    if(imagephotoover2==false)
    {	
        /*	BYTE* blue=  new BYTE[4384 * 3288 ];
            BYTE* green=  new BYTE[4384 * 3288  ];
            BYTE* red= new BYTE[4384 * 3288  ];
            BYTE* byImageBuf = new BYTE[4384 * 3288 * 3];*/

        BYTE* pBmp24 = CameraISP(camera2,pImageBuffer, pFrInfo);
        try
        {
            int sensorx=1944;
            int sensory=2592;

            gen_image_interleaved(&Image2,(long)pBmp24,"bgr",sensorx,sensory,-1,"byte",0,0,0,0,-1,0);
            //gen_image_interleaved(&imagergb1,(long)pBmp24,"bgr",sensorx,sensory,-1,"byte",0,0,0,0,-1,0);
            // rgb1_to_gray(Image1, &Image1);
            //rotate_image(Image1,&Image1,270,"constant");
            //rotate_image(imagergb1,&imagergb1,270,"constant");

            // disp_color(Image2,m_Window2id);
        }
        catch (HException &except)
        {	
            Herror error_num;

            error_num= except.err;
            return 0;
            //photo2problem=true;
            //MessageBox(error_num);
        }
        imagephotoover2=true;
    }	
    return 0;
}
#endif





//////////////////////////////C4ROBOT
float C4cpx=0;
float C4cpy=0;
float C4cpz=0;
float C4cpu=0;
float C4jogv=0;

bool C4xjogadd=false;
bool C4xjogsub=false;
bool C4yjogadd=false;
bool C4yjogsub=false;
bool C4zjogadd=false;
bool C4zjogsub=false;
bool C4ujogadd=false;
bool C4ujogsub=false;
bool C4b_ready=false;
bool C4b_running=false;
bool C4b_safeguard=false;
bool C4b_pause=false;
bool C4b_error=false;
bool C4b_stop=false;
bool C4commerror=false;
bool C4getPover=false;
bool C4verifyP=false;
