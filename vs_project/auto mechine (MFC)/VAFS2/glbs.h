#include "stdafx.h"
//using namespace _DSHOWLIB_NAMESPACE;
using namespace Halcon;
//#include "listener.h"

//#include "ISIDll.h"
bool smallkeyFontinit=false;

long camera1width= 1944;
long camera1height=2592;
long camera2width=1944;
long camera2height=2592;
 int modalorg11=0;
 int modalorg12=0;
  int modalorg13=0;
 int modalorg14=0;
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

#define PARAINPUT tongueout<<tonguein<<vextongueout<<vextonguein<< vexmainmotorlow<<vexmainmotorhigh<<  mainmotorlength<< fixturedelaytime <<picktime<< pickx<< picky<<photox<< photoy<<photox2<< photoy2<< pastex<< pastey<< rollerfinished<< vexx<< vexy<< vexroller<<vturnplate<<withbeep<<carrytime<<pasteangle<<pickangle<<keypastextemp<<keypasteytemp<<pushertime<<minscore11<<minscore12<<minscore21<<minscore22<<comno<<photodelay<<loadtime<<unloadtime<<searchrange<<zpick<<zpush<<zphoto<<zvex<<shieldpaste<<searchrange2<<photor<<repeat<<repasteangle<<repastex<<repastey<<reloadwaiting<<reloadpush<<reloadpick<<loadpush<<loadpick<<loadwaiting<<vload
#define PARAOUTPUT tongueout>>tonguein>>vextongueout>>vextonguein>> vexmainmotorlow>>vexmainmotorhigh>>  mainmotorlength>> fixturedelaytime>>picktime>>pickx>> picky>>photox>> photoy>>photox2>> photoy2>>pastex>>pastey>>rollerfinished>>vexx>>vexy>>vexroller>>vturnplate>>withbeep>>carrytime>>pasteangle>>pickangle>>keypastextemp>>keypasteytemp>>pushertime>>minscore11>>minscore12>>minscore21>>minscore22>>comno>>photodelay>>loadtime>>unloadtime>>searchrange>>zpick>>zpush>>zphoto>>zvex>>shieldpaste>>searchrange2>>photor>>repeat>>repasteangle>>repastex>>repastey>>reloadwaiting>>reloadpush>>reloadpick>>loadpush>>loadpick>>loadwaiting>>vload

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

long totalcounter=0;
long castcounter=0;
long pastecounter=0;
long commcounter=0;
bool startcomm=false;
//bool disablestart=false;
//bool disablestop=false;
//bool disablereset=false;
CString stateinfo;
CString verifyinfo;
CString fixtureinfo;


bool tapeready=false;
bool halfready=false;
bool tonguecanout=false;
bool pastefinished=false;
bool fixtureready=false;
bool tonguehomed=false;
bool placeok=false;




bool mainstepp=false;
bool mainstepm=false;
bool linestepp=false;
bool linestepm=false;
bool loadstepp=false;
bool reloadstepp=false;

bool fixturestepp=false;
bool disablereloadstepp=false;
bool disablemainstepp=false;
bool disableplacestepp=false;
bool disablelinestepm=false;
bool disablelinestepp=false;
bool disablefixturestepp=false;
bool reloadmod=false;

int lighttime=0;






//输出IO定义
const short  servoenable=1;
const short  servoresetout=2;
const short  pusherout1=3;
const short  pusherout2=4;
const short  loadout1=5;
const short  loadout2=6;
const short  flowout1=7;
const short  flowout2=8;
const short  rightpress=9;
const short  rightpress2=10;
//const short  alarmout=11;
//const short  pastefinishout=12;
//const short  canloadout=12;
//const short  flashled=12;
const short  front=0;
const short  back=1;

const short  stepenable=33;
//const short  loadfinishout=34;
const short  vacuumout1=35;
const short  vacuumout2=36;
const short  loadvacuumout1=37;
const short  loadvacuumout2=38;
const short  fixturevacuumout=39;
const short upfinishedout=40;
const short  downstartout=41;
const short  alarmbeepout=42;
const short  alarmlightout=43;
//const short  breakvacuumout=44;


//输入IO定义
const short  servoxready=1;
const short  servoxcoin=2;
const short  servoyready=3;
const short  servoycoin=4;
const short  pusherupin1=5;
const short  reset=6;
const short  tapecheckin=7;
const short  vacuumin1=8;
const short  pusherupin2=9;
const short  emergencyin=10;
const short  pusherdownin1=11;
const short  pusherdownin2=12;
const short  vacuumin2=13;
const short  loadupin2=14;
const short  doorin=15;
const short  loaddownin2=16;

const short  servorready=33;
const short  servorcoin=34;
const short  rightpressupin=35;
const short  rightpressdownin=36;
const short  loadvacuumin1=37;
const short  loadupin1=38;
const short  loaddownin1=39;
const short  loadvacuumin2=40;
const short  fixturevacuumin=41;
const short  upstartin=42;
const short  downfinishedin=43;
const short  pressvacuumin=44;
const short  pressin=45;
//const short  pressupin=46;
const short  jogin=47;
const short  stopin=48;




//系统故障处理
const short  emergencyerr=1;
const short  doorerr=2;
const short  turnerr=3;
const short  rightpressuperr=4;
const short  rightpressdownerr=5;
const short  cliperr=6;
const short  vacuumerr=7;
const short  mainmotorerr=8;
const short  tongueerr=9;
const short  xerr=10;
const short  yerr=11;
const short  cameraerr=12;
const short  wasteerr=13;
const short  outofrangeerr=14;
const short  tonguehomeerr=15;
const short  cameraerr2=16;
const short  loadvacuumerr=17;
const short  unloadvacuumerr=18;
const short  carrylefterr=19;
const short  carryrighterr=20;
const short  loaduperr=21;
const short unloaduperr=22;
const short fixtureouterr=23;
const short  xoutofrangeerr=24;
const short  youtofrangeerr=25;
const short  routofrangeerr=26;
const short  motorcommerr=27;
const short  zerr=28;
const short  presserr=29;
const short  pusherup1err=30;
const short  pusherdown1err=31;
const short  loadup1err=32;
const short  loaddown1err=33;
const short  vacuum1err=34;
const short  vacuum2err=35;
const short  loadvacuum1err=36;
const short  loadvacuum2err=37;
const short  pusherup2err=38;
const short  pusherdown2err=39;
const short  loadup2err=40;
const short  loaddown2err=41;
const short  leftfixtureerr=42;
const short  rightfixtureerr=43;
const short  tapeerr=44;




int errtime[50];
const CString err[50]=
{   
    "",
	"急停开关断开",
	"门锁开关断开",
	"翻转上",
	"右压合上",
	"右压合下",
	"夹子合",
	"提取真空错误",
	"主轴运行时间长",
	"舌头电机无原点",
	"X伺服报警",
	"Y伺服报警",
	"膜相机定位报警",
	"请清理弃料",
	"贴合超限",
	"舌头本位",
	"夹具相机定位报警",
	"上料真空错误",
	"下料真空错误",
	"搬运左",
	"搬运右",
	"请联系厂家",
	"请联系厂家",
	"请联系厂家",
	"X贴合超限",
	"Y贴合超限",
	"角度贴合超限",
	"串口通讯错误",
	"角度伺服报警",
	"主气压低",
	"左贴合上",
	"左贴合下",
	"左搬运上",
	"左搬运下",
	"左贴合真空",
	"右贴合真空",
	"左搬运真空",
	"右搬运真空",
	"右贴合上",
	"右贴合下",
	"右搬运上",
	"右搬运下",
	"左夹具真空",
	"取下右夹具机壳",
	"料带缺少"


		
};

bool showerr[50];



long photor=0;
long repeat=0;
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

long vexx=60000;
long vexy=60000;
long vexroller=60000;
long carrytime=0;
long vturnplate=20000;

int withbeep=1;

float minscore11=0;
float minscore12=0;
float minscore21=0;
float minscore22=0;
long   comno=1;
float minscore32=0;



CString    currentrcpname="\\current.rcp";
CString 	currentparametername="\\current.para";
CString 	currentmodelname="\\current.shm";
CString 	currentmodelname2="\\current2.shm";
CString 	currentmodelname3="\\current3.shm";
CString 	currentmodelname4="\\current4.shm";
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
float centerx=0;
float centery=0;
float centerx2=0;
float centery2=0;
float camera21centerx=0;
float camera21centery=0;
float camera22centerx=0;
float camera22centery=0;


float recenterx=0;
float recentery=0;
float recenterx2=0;
float recentery2=0;
float recamera21centerx=0;
float recamera21centery=0;
float recamera22centerx=0;
float recamera22centery=0;
float camera3centerx=0;
float camera3centery=0;
float camera4centerx=0;
float camera4centery=0;


float photoangle=0;

 DWORD tempa,tempb,tempc,tempd,tempe,tempf,tempg,temph;
int servostarted=0;
//int servoystarted=0;
//int servoturnstarted=0;
//int servoupdownstarted=0;
//int rollerservostarted=0;
int mainmotorstarted=0;
int loadservostarted=0;
int reloadservostarted=0;
int turnarrowservostarted=0;
int fixtureservostarted=0;

int turnplatestarted=0;
int zstarted=0;
int tonguestarted=0;
int linestarted=0;
//main loop state
typedef enum{
	state1,
	state1p0p0,
	state1p0p1,
	state1p0p2,
	state1p1,
	state1p2,
	state2,
    state2p1,
	state2p2,
	state2p3,
	state3,
	state4,
	state4p1,
	state5,
	state6,
	state6p1,
	state7,
	state7p1,
	state8,
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
	uphand1,
	uphand2,
	uphand3,
	uphand4,
	uphand5,
	uphand6,
}uphandshake;

uphandshake uphand=uphand1;

typedef enum{
	downhand1,
	downhand2,
	downhand3,
	downhand4,
	downhand5,
	downhand6,
}downhandshake;

downhandshake downhand=downhand1;







//backline  loop state
//backline  loop state
typedef enum{
	linestate1,
	linestate1p1,
	linestate1p1p1,
	linestate1p1p5,
	linestate1p1p6,
	linestate1p1p7,
	linestate1p1p8,
	linestate1p1p9,
	linestate2,
	linestate2p1,
	linestate2p2,
	linestate3,
	linestate3p1,
	linestate3p2,
	linestate3p3,
	linestate4,
	linestate5,
	linestate6,
	linestate6p1,
	linestate7,
	linestate8,
	linestate8p1,
	linestate8p2,
	linestate8p3,
	linestate9,
	linestate9p1,
	linestate10,
	linestate11,
	linestate12,
	linestate13,
	linestate14,
	linestate15,
	linestate16,
	linestate17,
	linestate18,
	linestate19

}linestates;
linestates linestate=linestate1;

typedef enum{
	placestate1,
	placestate1p1,
	placestate1p2,
	placestate2,
	placestate2p1,
	placestate3,
	placestate3p1,
	placestate4,
	placestate5,
	placestate6,
	placestate7,
	placestate8,
	placestate8p0,
	placestate8p0p0,
	placestate8p1,
	placestate8p2,
	placestate8p3,
	placestate9,
	placestate10,
	placestate11,
	placestate12,
	placestate12p0,
	placestate13,
	placestate14,
	placestate15,
	placestate16,
	placestate17,
	placestate18,
	placestate19,
	placestate20,
	placestate21

}placestates;
placestates placestate=placestate1;

typedef enum{
	pressstate1,
	pressstate2,
	pressstate3,
	pressstate4,
	pressstate5,
	pressstate6,
	pressstate7,

}pressstates;
pressstates pressstate=pressstate1;

typedef enum{
	overturn1,
	overturn1p1,
	overturn2,
	overturn2p1,
	overturn3,
	overturn3p1,
	overturn3p2,
	overturn4,
	overturn5,
	overturn6,
	overturn7,
	overturn7p1
}overturns;
overturns overturn=overturn1;

typedef enum{
	replacestate1,
	replacestate1p1,
	replacestate1p2,
	replacestate2,
	replacestate2p1,
	replacestate3,
	replacestate3p1,
	replacestate4,
	replacestate5,
	replacestate6,
	replacestate7,
	replacestate8,
	replacestate8p1,
	replacestate8p2,
	replacestate9,
	replacestate10,
	replacestate11,
	replacestate12,
	replacestate13,
	replacestate14,
	replacestate15,
	replacestate16,
	replacestate17,
	replacestate18,
	replacestate19,
	replacestate20,
	replacestate21

}replacestates;
replacestates replacestate=replacestate1;

typedef enum{
	fixturestate1,
	fixturestate1p1,
	fixturestate1p2,
	fixturestate2,
	fixturestate2p1,
	fixturestate2p2,
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
	HTuple ShapeModel11,ShapeModel12,ShapeModel13,ShapeModel14,ShapeModel21 ,ShapeModel22;

float zoomfactor=1;	
int zoomupdown=0;
int zoomleftright=0;






 int verifytimes=0;

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
 float model13halfx=0;
 float model13halfy=0;
  float model14halfx=0;
 float model14halfy=0;



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


 float piecex=0;
 float piecey=0;
 bool notphoto=false;

void MyHalconExceptionHandler(const Halcon::HException& except)
{
  throw except;	
}


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
	
				
					int sensorx=2592;
					int sensory=1944;
			
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


 int calcrc(unsigned char *ptr, int count)
{
        unsigned short reg_crc;
        unsigned short s_crcchk;
        s_crcchk = 0;
        reg_crc = 0xffff;
        while(count--)
                {
                reg_crc ^= *ptr++;
                for(s_crcchk = 0; s_crcchk < 8; s_crcchk ++)
                        {
                        if(reg_crc & 0x01)
                                {
                                reg_crc = (reg_crc >> 1) ^ 0xa001;
                                }
                        else
                                {
                                reg_crc = reg_crc >> 1;
                                }
                        }
                }
		//unsigned char high,low;
		//high=reg_crc/256;
		//low=reg_crc%256;
        return reg_crc;
}

CMSComm	m_serial;
unsigned char datain[80]; 

void sendtomotor(unsigned char *sendchar,int count)
 {
		   
		   
		CByteArray sendArr;
 
		sendArr.SetSize(count);
		for(int i =0; i<count; i++)
		{
			sendArr.SetAt(i,sendchar[i]);
			
		}
		m_serial.SetOutput(COleVariant(sendArr));
        
        startcomm=true;
	
 }

bool commok=false;
/*unsigned char outspeedchar[8];
unsigned char inspeedchar[8];
unsigned char zlowspeedchar[8];
unsigned char zhighspeedchar[8];
long tonguepositionsave=0;
unsigned char speedchar[8]={0x01, 0x06 ,0x00 ,0x07 ,0x00 ,0x32 ,0xB9 ,0xDE}; // 50 r/min
unsigned char positionfrontchar[8]={0x01,0x06,0x00,0x0B,0x00,0x01,0x39,0xC8 };//正转

unsigned char zspeedchar[8]={0x02, 0x06 ,0x00 ,0x07 ,0x00 ,0x32 ,0xB9 ,0xED}; // 50 r/min
unsigned char zpositionfrontchar[8]={0x02,0x06,0x00,0x0B,0x00,0x01,0x39,0xFB };//正转

unsigned char positionbackchar[8]={0x01,0x06,0x00,0x0B ,0xFF ,0x01 ,0x78 ,0x38 };//反转
unsigned char highpositionchar[8]={0x01,0x06,0x00,0x08,0x00,0x00,0x08,0x08};//高位0
unsigned char lowpositionchar[8]={0x01, 0x06 ,0x00 ,0x09 ,0x00 ,0x64 ,0x58 ,0x23}; // 100个脉冲 

unsigned char zhighpositionchar[8]={0x02,0x06,0x00,0x08,0x00,0x00,0x08,0x08};//高位0
unsigned char zlowpositionchar[8]={0x02, 0x06 ,0x00 ,0x09 ,0x00 ,0x64 ,0x58 ,0x23}; // 100个脉冲 */
unsigned char errchar[11]={0x01,0x03,0x02,0x00,0x01,0x00,0x00};

float visionx,visiony;
float revisionx,revisiony;


long zpick=0;
long zpush=0;
long zphoto=0;
long zvex=0;

