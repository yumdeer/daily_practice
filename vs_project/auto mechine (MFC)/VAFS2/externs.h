#include "stdafx.h"
//using namespace _DSHOWLIB_NAMESPACE;
using namespace Halcon;
//#include "listener.h"

extern bool smallkeyFontinit;



extern float metalyscale;

extern INT camera1,camera2;

extern long camera1width;
extern long camera1height;
extern long camera2width;
extern long camera2height;
extern int modalorg11;
extern int modalorg12;
extern int modalorg13;
extern int modalorg14;
extern int modalorg21;
extern int modalorg22;
extern long verifypastex;
extern long verifypastey;
extern long shieldpaste;


#define PARAINPUT tongueout<<tonguein<<vextongueout<<vextonguein<< vexmainmotorlow<<vexmainmotorhigh<<  mainmotorlength<< fixturedelaytime <<picktime<< pickx<< picky<<photox<< photoy<<photox2<< photoy2<< pastex<< pastey<< rollerfinished<< vexx<< vexy<< vexroller<<vturnplate<<withbeep<<carrytime<<pasteangle<<pickangle<<keypastextemp<<keypasteytemp<<pushertime<<minscore11<<minscore12<<minscore21<<minscore22<<comno<<photodelay<<loadtime<<unloadtime<<searchrange<<zpick<<zpush<<zphoto<<zvex<<shieldpaste<<searchrange2<<photor<<repeat<<repasteangle<<repastex<<repastey<<reloadwaiting<<reloadpush<<reloadpick<<loadpush<<loadpick<<loadwaiting<<vload
#define PARAOUTPUT tongueout>>tonguein>>vextongueout>>vextonguein>> vexmainmotorlow>>vexmainmotorhigh>>  mainmotorlength>> fixturedelaytime>>picktime>>pickx>> picky>>photox>> photoy>>photox2>> photoy2>>pastex>>pastey>>rollerfinished>>vexx>>vexy>>vexroller>>vturnplate>>withbeep>>carrytime>>pasteangle>>pickangle>>keypastextemp>>keypasteytemp>>pushertime>>minscore11>>minscore12>>minscore21>>minscore22>>comno>>photodelay>>loadtime>>unloadtime>>searchrange>>zpick>>zpush>>zphoto>>zvex>>shieldpaste>>searchrange2>>photor>>repeat>>repasteangle>>repastex>>repastey>>reloadwaiting>>reloadpush>>reloadpick>>loadpush>>loadpick>>loadwaiting>>vload


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

extern long totalcounter;
extern long castcounter;
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


extern bool fixturestepp;
extern bool linestepp;
extern bool linestepm;
extern bool loadstepp;
extern bool reloadstepp;

extern bool disablereloadstepp;
extern bool disablemainstepp;
extern bool disablelinestepm;
extern bool disablelinestepp;
extern bool disableplacestepp;
extern bool disablefixturestepp;


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



extern CString  currentrcpname;
extern CString 	currentparametername;
extern CString 	currentmodelname;
extern CString 	currentmodelname2;
extern CString 	currentmodelname3;
extern CString 	currentmodelname4;
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
extern HTuple ShapeModel11,ShapeModel12,ShapeModel13,ShapeModel14,ShapeModel21,ShapeModel22;
extern float zoomfactor;
extern int zoomupdown;
extern int zoomleftright;





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
extern float model13halfx;
 extern float model13halfy;
 extern  float model14halfx;
 extern float model14halfy;





 extern  float model21halfx;
 extern float model21halfy;
 extern  float model22halfx;
extern  float model22halfy;


/*extern bool commok;
extern unsigned char outspeedchar[8];
extern unsigned char inspeedchar[8];
extern void sendtomotor(unsigned char *sendchar);
extern long tonguepositionsave;
extern unsigned char positionfrontchar[8];//正转
extern unsigned char positionbackchar[8];//反转
extern unsigned char highpositionchar[8];//高位0
extern unsigned char lowpositionchar[8]; // 100个脉冲 
extern unsigned char speedchar[8];//={0x01, 0x06 ,0x00 ,0x07 ,0x00 ,0x32 ,0xB9 ,0xDE}; // 50 r/min*/
extern int calcrc(unsigned char *ptr, int count);
extern unsigned char datain[80]; 


extern float visionx,visiony;
extern float revisionx,revisiony;

extern long zpick;
extern long zpush;
extern long zphoto;
extern long zvex;


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



