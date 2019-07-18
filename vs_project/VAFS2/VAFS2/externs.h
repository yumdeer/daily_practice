#include "stdafx.h"
#define _WIN32_WINNT 0x0500
//using namespace _DSHOWLIB_NAMESPACE;
//HMODULE hmode=::LoadLibrary( "C:\\EpsonRC70\\exe\\RCAPINet.dll" );
//using namespace RCAPINet;
using namespace Halcon;
//extern RCAPINet::Spel m_spel;
//extern gcroot< RCAPINet::Spel ^>m_spel;
extern bool camera1firstphoto;
extern bool camera2firstphoto;
extern float metalyscale;
extern bool testone;

extern INT camera1,camera2;

extern long camera1width;
extern long camera1height;
extern long camera2width;
extern long camera2height;
extern int modalorg11;
extern int modalorg12;
extern int modalorg21;
extern int modalorg22;
extern long verifypastex;
extern long verifypastey;
extern long shieldpaste;


#define PARAINPUT tongueout<<tonguein<<vextongueout<<vextonguein<< vexmainmotorlow<<vexmainmotorhigh<<  mainmotorlength<< fixturedelaytime <<picktime<< pickx<< picky<<photox<< photoy<<photox2<< photoy2<< pastex<< pastey<< rollerfinished<< vexx<< vexy<< vexroller<<vturnplate<<withbeep<<carrytime<<pasteangle<<pickangle<<keypastextemp<<keypasteytemp<<pushertime<<minscore11<<minscore12<<minscore21<<minscore22<<comno<<photodelay<<loadtime<<unloadtime<<searchrange<<zpick<<zpush<<zphoto<<zvex<<shieldpaste<<searchrange2<<photor<<repeat<<repasteangle<<repastex<<repastey<<reloadwaiting<<reloadpush<<reloadpick<<loadpush<<loadpick<<loadwaiting<<vload<<fixturex<<fixturey<<numberx<<numbery<<stepx<<stepy<<specialx<<specialy<<coverx<<covery<<vexfixturex<<vexfixturey<<loadx<<loady<<unloadx<<unloady<<films<<filml<<vexload<<vexunload<<load0<<load1<<load2<<unload0<<unload1<<unload2
#define PARAOUTPUT tongueout>>tonguein>>vextongueout>>vextonguein>> vexmainmotorlow>>vexmainmotorhigh>>  mainmotorlength>> fixturedelaytime>>picktime>>pickx>> picky>>photox>> photoy>>photox2>> photoy2>>pastex>>pastey>>rollerfinished>>vexx>>vexy>>vexroller>>vturnplate>>withbeep>>carrytime>>pasteangle>>pickangle>>keypastextemp>>keypasteytemp>>pushertime>>minscore11>>minscore12>>minscore21>>minscore22>>comno>>photodelay>>loadtime>>unloadtime>>searchrange>>zpick>>zpush>>zphoto>>zvex>>shieldpaste>>searchrange2>>photor>>repeat>>repasteangle>>repastex>>repastey>>reloadwaiting>>reloadpush>>reloadpick>>loadpush>>loadpick>>loadwaiting>>vload>>fixturex>>fixturey>>numberx>>numbery>>stepx>>stepy>>specialx>>specialy>>coverx>>covery>>vexfixturex>>vexfixturey>>loadx>>loady>>unloadx>>unloady>>films>>filml>>vexload>>vexunload>>load0>>load1>>load2>>unload0>>unload1>>unload2

extern bool run;
extern bool stop;
extern bool mainstepp;
extern bool mainstepm;
extern bool loadstepp;
extern bool reloadstepp;

extern bool reloadmod;
extern bool photoverify;
extern bool metalverify;
extern bool cyclephoto;
extern bool cyclephoto2;
extern bool cyclephoto3;
extern bool cyclephoto4;
extern bool visionphoto;
extern bool initposition;
extern float xscale;
extern float yscale;
extern float metalscale;
extern float glasscale;
extern float xdiv;
extern float photo4angle;
extern float photo3angle;
extern float photo2angle;
extern float photo1angle;
extern float ydiv;
extern float xdiv1;
extern float ydiv1;
extern float xdiv2;
extern float ydiv2;
extern float keypastex;
extern float keypastey;
extern float keypastextemp;
extern float keypasteytemp;
extern int modalselect;
extern int cameraselect;

extern float camera2xdiv;
extern float camera2ydiv;

extern long pastecounter;
extern CString stateinfo;
extern CString verifyinfo;
extern CString fixtureinfo;
extern int startphoto;
extern int overphoto;
extern int startphoto2;
extern int overphoto2;
extern int startphoto3;
extern int overphoto3;
extern int startphoto4;
extern int overphoto4;


extern int fixturestarted;
extern bool pressstepp;
extern bool loadstepp;
extern bool fixturestepp;
extern bool mainstepp;
extern bool mainstepm;
extern bool linstepp;
extern bool loutstepp;
extern bool llstepp;
extern bool leftstepp;
extern bool rightstepp;
extern bool peelstepp;
extern bool unloadstepp;

extern bool disablemainstepp;
extern bool disablemainstepm;
extern bool disablelinstepp;
extern bool disableloutstepp;
extern bool disablellstepp;
extern bool disableleftstepp;
extern bool disablerightstepp;
extern bool disablepeelstepp;
extern bool disableunloadstepp;

extern bool disableloadstepp;

extern bool disablepressstepp;

extern long correcttime;
extern long fibrechecktime;
extern int loadservostarted;
extern int loadservostarted2;
extern long loadpickr; 
extern long loadpushr; 
extern long vloadr; 

extern long tongueout;
extern long tonguein;
extern long vextongueout;
extern long vextonguein;

extern long vexmainmotorlow;
extern long vexmainmotorhigh;
extern long mainmotorlength;

extern int fixturedelaytime;
extern int picktime;
extern int loadtime;
extern int photodelay;
extern int unloadtime;
extern int fixtureouttime;
extern int pushertime;


extern long pickx;
extern long picky;
extern long photox;
extern long photoy;
extern long photox2;
extern long photoy2;

extern long pastex;

extern long pastey;

extern long rollerfinished;
extern long pasteangle;
extern long pickangle;

extern long vexx;
extern long films;
extern long filml;
extern long vexload,vexunload,load0,load1,load2,unload0,unload1,unload2;

extern long loadx;
extern long loady;
extern long unloadx;
extern long unloady;
extern long searchrange;
extern long searchrange2;
extern long vexy;
extern long vexroller;
extern long carrytime;
extern long vturnplate;
extern float minscore11;
extern float minscore12;
extern float minscore21;
extern float minscore22;
extern long comno;
extern float minscore32;


extern CString 	currentregionsname1;
extern CString 	currentregionsname2;
extern CString 	currentregionsname3;
extern CString 	currentregionsname4;

extern CString  currentrcpname;
extern CString 	currentparametername;
extern CString 	currentmodelname;
extern CString 	currentmodelname2;
extern CString 	currentmodelname21;
extern CString 	currentmodelname22;
extern CString 	currentmodelname31;
extern CString 	currentmodelname32;
extern CString 	currentmodelname41;
extern CString 	currentmodelname42;

extern CString  currentphotoname;
extern CString     listrcpname;
extern CString     rcpname;
extern CString currentdir;
extern CString passwordname;
extern CString password;
extern CString     counterfilename;
extern int withbeep;


extern int	 bright;
extern int gain;
extern int	shutter;
extern int  shutter2;
extern int	shutter3;
extern int  shutter4;
extern int	shutter5;
extern int  gain2;
extern float	contrast1;
extern float  contrast2;


extern float contrast11;
extern float contrast12;
extern float contrast21;
extern float contrast22;

extern bool imagephotoover;
extern unsigned char* pImageData;

extern bool imagephotoover2;
extern unsigned char * pImageData2;



extern Hobject Image1,Image2;
//extern HWindow m_Window,m_Window2;
extern Hlong m_Windowid,m_Window2id;	
extern HTuple ShapeModel11,ShapeModel12,ShapeModel21,ShapeModel22;
extern Hobject Regions1,Regions2,Regions3,Regions4; 
extern float zoomfactor;
extern int zoomupdown;
extern int zoomleftright;



 extern float model1x[6];
 extern float model1y[6];
 extern float model2x[6];
 extern float model2y[6];
 extern float remodel1x[6];
 extern float remodel1y[6];
 extern float remodel2x[6];
 extern float remodel2y[6];
 //extern int modelcount;

 extern float model11x;
 extern float model11y;
 extern float model12x;
 extern float model12y;
 extern float model21x;
 extern float model21y;
 extern float model22x;
 extern float model22y;

 extern float remodel11x;
 extern float remodel11y;
 extern float remodel12x;
 extern float remodel12y;
 extern float remodel21x;
 extern float remodel21y;
 extern float remodel22x;
 extern float remodel22y;

 extern bool notphoto;
 extern float model11halfx;
 extern float model11halfy;
 extern  float model12halfx;
 extern float model12halfy;
 extern  float model21halfx;
 extern float model21halfy;
 extern  float model22halfx;
extern  float model22halfy;


 


extern float visionx,visiony;
extern float revisionx,revisiony;

extern long zpick;
extern long zpush;
extern long zphoto;
extern long zvex;
extern long fixturex;
extern long fixturey;
extern long numberx;
extern long numbery;
extern long stepx;
extern long stepy;
extern long specialx;
extern long specialy;
extern long coverx;
extern long covery;
extern long vexfixturex;
extern long vexfixturey;

extern long photor;
extern long repeat;
extern long repasteangle;
extern long repastex;
extern long repastey;
extern long reloadwaiting;
extern long reloadpush;
extern long reloadpick;
extern long loadpush;
extern long loadpick;
extern long loadwaiting;
extern long vload;



////////////////////C4ROBOT
extern float C4cpx;
extern float C4cpy;
extern float C4cpz;
extern float C4cpu;
extern float C4jogv;
extern bool C4xjogadd;
extern bool C4xjogsub;
extern bool C4yjogadd;
extern bool C4yjogsub;
extern bool C4zjogadd;
extern bool C4zjogsub;
extern bool C4ujogadd;
extern bool C4ujogsub;
extern bool C4b_ready;
extern bool C4b_running;
extern bool C4b_safeguard;
extern bool C4b_pause;
extern bool C4b_error;
extern bool C4b_stop;
extern bool C4commerror;
extern bool C4getPover;
extern bool C4verifyP;


