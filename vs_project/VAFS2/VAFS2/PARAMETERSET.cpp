// PARAMETERSET.cpp : implementation file
//

#include "stdafx.h"
#include "VAFS2.h"
#include "PARAMETERSET.h"
#include "RcpSave.h"
#include "DELETERCP.h"
#include "externs.h"
#include "paraproduce.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
int listrcpcounter;
HWND focushwnd;
/////////////////////////////////////////////////////////////////////////////
// PARAMETERSET dialog


PARAMETERSET::PARAMETERSET(CWnd* pParent /*=NULL*/)
: CDialog(PARAMETERSET::IDD, pParent)
    , m_vexload(0)
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
    m_pickx = 0;
    m_picky = 0;
    m_pushertime = 0;
    m_rollerfinished = 0;
    m_vexmainmotorhigh = 0;
    m_vexmainmotorlow = 0;
    m_vturnplate = 0;
    m_vexx = 0;
    m_repeat=1;
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
    m_photo3angle = 0.0f;
    m_photo4angle = 0.0f;
    m_carrytime = 0;
    m_comno = 3;
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
    m_fixturex = 0;
    m_fixturey = 0;
    m_coverx = 0;
    m_covery = 0;
    m_stepx = 0;
    m_stepy = 0;
    m_specialx = 0;
    m_specialy = 0;
    m_vexfixturex = 0;
    m_vexfixturey = 0;
    m_numberx = 0;
    m_numbery = 0;
    m_loadx = 0;
    m_loady = 0;
    m_unloadx = 0;
    m_unloady = 0;
    m_films = 0;
    m_filml = 0;
    //}}AFX_DATA_INIT
    m_vexunload = 0;
    m_load0 = 0;
    m_load1 = 0;
    m_load2 = 0;
    m_unload0 = 0;
    m_unload1 = 0;
    m_unload2 = 0;
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
    DDV_MinMaxLong(pDX, m_mainmotorlength, -0, 3000);
    DDX_Text(pDX, IDC_pasteangle, m_pasteangle);
    DDX_Text(pDX, IDC_pastex, m_pastex);
    DDV_MinMaxLong(pDX, m_pastex, -10000, 50000);
    DDX_Text(pDX, IDC_pastey, m_pastey);
    DDV_MinMaxLong(pDX, m_pastey, -10000, 50000);
    DDX_Text(pDX, IDC_photox, m_photox);
    DDX_Text(pDX, IDC_photoy, m_photoy);
    DDX_Text(pDX, IDC_picktime, m_picktime);
    DDX_Text(pDX, IDC_pickx, m_pickx);
    DDV_MinMaxLong(pDX, m_pickx, -10000, 50000);
    DDX_Text(pDX, IDC_picky, m_picky);
    DDV_MinMaxLong(pDX, m_picky, -10000, 50000);
    DDX_Text(pDX, IDC_pushertime, m_pushertime);
    DDX_Text(pDX, IDC_rollerfinished, m_rollerfinished);
    DDX_Text(pDX, IDC_vexmainmotorhigh, m_vexmainmotorhigh);
    DDV_MinMaxLong(pDX, m_vexmainmotorhigh, 0, 80000);
    DDX_Text(pDX, IDC_vexmainmotorlow, m_vexmainmotorlow);
    DDV_MinMaxLong(pDX, m_vexmainmotorlow, 0, 30000);
    DDX_Text(pDX, IDC_vturnplate, m_vturnplate);
    DDV_MinMaxLong(pDX, m_vturnplate, 0, 2000);
    DDX_Text(pDX, IDC_vexx, m_vexx);
    DDX_Text(pDX, IDC_vexy, m_vexy);
    DDV_MinMaxLong(pDX, m_vexy, 0, 100);
    DDX_Text(pDX, IDC_pickangle, m_pickangle);
    DDX_Text(pDX, IDC_photo2angle, m_photo2angle);
    DDX_Text(pDX, IDC_metalscale, m_metalscale);
    DDX_Text(pDX, IDC_ydiv, m_ydiv);
    DDX_Text(pDX, IDC_minscore11, m_minscore11);
    DDV_MinMaxFloat(pDX, m_minscore11, 0.f, 1.f);
    DDX_Text(pDX, IDC_minscore21, m_minscore21);
    DDV_MinMaxFloat(pDX, m_minscore21, 0.f, 1.f);
    DDX_Text(pDX, IDC_photox2, m_photox2);
    DDX_Text(pDX, IDC_photoy2, m_photoy2);
    DDX_Text(pDX, IDC_tonguein, m_tonguein);
    DDV_MinMaxLong(pDX, m_tonguein, 0, 60000);
    DDX_Text(pDX, IDC_vextonguein, m_vextonguein);
    DDX_Text(pDX, IDC_tongueout, m_tongueout);
    DDV_MinMaxLong(pDX, m_tongueout, 0, 60000);
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
    DDV_MinMaxLong(pDX, m_comno, 1, 50);
    DDX_Text(pDX, IDC_vexroller2, m_vexroller2);
    DDX_Text(pDX, IDC_searchrange, m_searchrange);
    DDX_Text(pDX, IDC_zvex, m_zvex);
    DDV_MinMaxLong(pDX, m_zvex, 0,820000);
    DDX_Text(pDX, IDC_zphoto, m_zphoto);
    DDV_MinMaxLong(pDX, m_zphoto, 33000, 50000);
    DDX_Text(pDX, IDC_zpicks, m_zpick);
    DDV_MinMaxLong(pDX, m_zpick, 30000, 50000);
    DDX_Text(pDX, IDC_zpush, m_zpush);
    DDV_MinMaxLong(pDX, m_zpush, 24400, 50000);
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
    DDV_MinMaxLong(pDX, m_repastex, 0, 50000);
    DDX_Text(pDX, IDC_repastey, m_repastey);
    DDV_MinMaxLong(pDX, m_repastey, 0, 50000);
    DDX_Text(pDX, IDC_loadpick, m_loadpick);
    DDX_Text(pDX, IDC_loadwaiting, m_loadwaiting);
    DDX_Text(pDX, IDC_loadpush, m_loadpush);
    DDV_MinMaxLong(pDX, m_loadpush, 0, 7000);
    DDX_Text(pDX, IDC_photor, m_photor);
    DDX_Text(pDX, IDC_fixturex, m_fixturex);
    DDX_Text(pDX, IDC_fixturey, m_fixturey);
    DDV_MinMaxLong(pDX, m_fixturey, 0, 800);
    DDX_Text(pDX, IDC_coverx, m_coverx);
    DDV_MinMaxLong(pDX, m_coverx, 0, 1500);
    DDX_Text(pDX, IDC_covery, m_covery);
    DDV_MinMaxLong(pDX, m_covery, 16800, 22000);
    DDX_Text(pDX, IDC_stepx, m_stepx);
    DDX_Text(pDX, IDC_stepy, m_stepy);
    DDX_Text(pDX, IDC_specialx, m_specialx);
    DDX_Text(pDX, IDC_specialy, m_specialy);
    DDX_Text(pDX, IDC_vexfixturex, m_vexfixturex);
    DDX_Text(pDX, IDC_vexfixturey, m_vexfixturey);
    DDX_Text(pDX, IDC_numberx, m_numberx);
    DDV_MinMaxLong(pDX, m_numberx, 48400, 60000);
    DDX_Text(pDX, IDC_numbery, m_numbery);
    DDX_Text(pDX, IDC_loadx, m_loadx);
    DDX_Text(pDX, IDC_loady, m_loady);
    DDX_Text(pDX, IDC_unloadx, m_unloadx);
    DDX_Text(pDX, IDC_unloady, m_unloady);
    DDX_Text(pDX, IDC_films, m_films);
    DDX_Text(pDX, IDC_filml, m_filml);
    //}}AFX_DATA_MAP
    DDX_Text(pDX, IDC_vexlaod, m_vexload);
    DDV_MinMaxLong(pDX, m_vexload, 0, 90000);
    DDX_Text(pDX, IDC_vexunlaod, m_vexunload);
    DDV_MinMaxLong(pDX, m_vexunload, 0, 90000);
    DDX_Text(pDX, IDC_load0, m_load0);
    DDX_Text(pDX, IDC_load1, m_load1);
    DDX_Text(pDX, IDC_load2, m_load2);
    DDX_Text(pDX, IDC_unload0, m_unload0);
    DDX_Text(pDX, IDC_unload1, m_unload1);
    DDX_Text(pDX, IDC_unload2, m_unload2);
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
ON_EN_SETFOCUS(IDC_fixturedelaytime, OnSetfocusfixturedelaytime)
ON_EN_KILLFOCUS(IDC_fixturedelaytime, OnKillfocusfixturedelaytime)
ON_EN_SETFOCUS(IDC_fixtureouttime, OnSetfocusfixtureouttime)
ON_EN_KILLFOCUS(IDC_fixtureouttime, OnKillfocusfixtureouttime)
ON_EN_SETFOCUS(IDC_mainmotorlength, OnSetfocusmainmotorlength)
ON_EN_KILLFOCUS(IDC_mainmotorlength, OnKillfocusmainmotorlength)
ON_EN_SETFOCUS(IDC_pasteangles, OnSetfocuspasteangle)
ON_EN_KILLFOCUS(IDC_pasteangles, OnKillfocuspasteangle)
ON_EN_SETFOCUS(IDC_pastex, OnSetfocuspastex)
ON_EN_KILLFOCUS(IDC_pastex, OnKillfocuspastex)
ON_EN_SETFOCUS(IDC_pastey, OnSetfocuspastey)
ON_EN_KILLFOCUS(IDC_pastey, OnKillfocuspastey)
ON_EN_SETFOCUS(IDC_photox, OnSetfocusphotox)
ON_EN_KILLFOCUS(IDC_photox, OnKillfocusphotox)
ON_EN_SETFOCUS(IDC_photoy, OnSetfocusphotoy)
ON_EN_KILLFOCUS(IDC_photoy, OnKillfocusphotoy)
ON_EN_SETFOCUS(IDC_picktime, OnSetfocuspicktime)
ON_EN_KILLFOCUS(IDC_picktime, OnKillfocuspicktime)
ON_EN_SETFOCUS(IDC_pickx, OnSetfocuspickx)
ON_EN_KILLFOCUS(IDC_pickx, OnKillfocuspickx)
ON_EN_SETFOCUS(IDC_picky, OnSetfocuspicky)
ON_EN_KILLFOCUS(IDC_picky, OnKillfocuspicky)
ON_EN_SETFOCUS(IDC_pushertime, OnSetfocuspushertime)
ON_EN_KILLFOCUS(IDC_pushertime, OnKillfocuspushertime)
ON_EN_SETFOCUS(IDC_rollerfinished, OnSetfocusrollerfinished)
ON_EN_KILLFOCUS(IDC_rollerfinished, OnKillfocusrollerfinished)
ON_EN_SETFOCUS(IDC_vexmainmotorhigh, OnSetfocusvexmainmotorhigh)
ON_EN_KILLFOCUS(IDC_vexmainmotorhigh, OnKillfocusvexmainmotorhigh)
ON_EN_SETFOCUS(IDC_vexmainmotorlow, OnSetfocusvexmainmotorlow)
ON_EN_KILLFOCUS(IDC_vexmainmotorlow, OnKillfocusvexmainmotorlow)
ON_EN_SETFOCUS(IDC_vexx, OnSetfocusvexx)
ON_EN_KILLFOCUS(IDC_vexx, OnKillfocusvexx)
ON_EN_SETFOCUS(IDC_vexy, OnSetfocusvexy)
ON_EN_KILLFOCUS(IDC_vexy, OnKillfocusvexy)
ON_EN_SETFOCUS(IDC_vturnplate, OnSetfocusvturnplate)
ON_EN_KILLFOCUS(IDC_vturnplate, OnKillfocusvturnplate)
ON_MESSAGE(OPEN_SOFTKEY,opensoftkey)
ON_MESSAGE(CLOSE_SOFTKEY,closesoftkey)
ON_EN_SETFOCUS(IDC_pickangle, OnSetfocuspickangle)
ON_EN_KILLFOCUS(IDC_pickangle, OnKillfocuspickangle)
ON_BN_CLICKED(IDC_metalverify, Onmetalverify)
ON_EN_SETFOCUS(IDC_minscore11, OnSetfocusminscore11)
ON_EN_KILLFOCUS(IDC_minscore11, OnKillfocusminscore11)
ON_EN_SETFOCUS(IDC_minscore21, OnSetfocusminscore21)
ON_EN_KILLFOCUS(IDC_minscore21, OnKillfocusminscore21)
ON_EN_SETFOCUS(IDC_photox2, OnSetfocusphotox2)
ON_EN_KILLFOCUS(IDC_photox2, OnKillfocusphotox2)
ON_EN_SETFOCUS(IDC_photoy2, OnSetfocusphotoy2)
ON_EN_KILLFOCUS(IDC_photoy2, OnKillfocusphotoy2)
ON_EN_SETFOCUS(IDC_tonguein, OnSetfocustonguein)
ON_EN_KILLFOCUS(IDC_tonguein, OnKillfocustonguein)
ON_EN_SETFOCUS(IDC_tongueout, OnSetfocustongueout)
ON_EN_KILLFOCUS(IDC_tongueout, OnKillfocustongueout)
ON_EN_SETFOCUS(IDC_vextonguein, OnSetfocusvextonguein)
ON_EN_KILLFOCUS(IDC_vextonguein, OnKillfocusvextonguein)
ON_EN_SETFOCUS(IDC_vextongueout, OnSetfocusvextongueout)
ON_EN_KILLFOCUS(IDC_vextongueout, OnKillfocusvextongueout)
ON_EN_SETFOCUS(IDC_loadtime, OnSetfocusloadtime)
ON_EN_KILLFOCUS(IDC_loadtime, OnKillfocusloadtime)
ON_EN_SETFOCUS(IDC_unloadtime, OnSetfocusunloadtime)
ON_EN_KILLFOCUS(IDC_unloadtime, OnKillfocusunloadtime)
ON_EN_SETFOCUS(IDC_metalscale, OnSetfocusmetalscale)
ON_EN_KILLFOCUS(IDC_metalscale, OnKillfocusmetalscale)
ON_EN_SETFOCUS(IDC_metalscaley, OnSetfocusmetalscaley)
ON_EN_KILLFOCUS(IDC_metalscaley, OnKillfocusmetalscaley)
ON_EN_SETFOCUS(IDC_photodelay, OnSetfocusphotodelay)
ON_EN_KILLFOCUS(IDC_photodelay, OnKillfocusphotodelay)
ON_EN_SETFOCUS(IDC_carrytime, OnSetfocuscarrytime)
ON_EN_KILLFOCUS(IDC_carrytime, OnKillfocuscarrytime)
ON_EN_SETFOCUS(IDC_comno, OnSetfocuscomno)
ON_EN_KILLFOCUS(IDC_comno, OnKillfocuscomno)
ON_EN_SETFOCUS(IDC_vexroller2, OnSetfocusvexroller2)
ON_EN_KILLFOCUS(IDC_vexroller2, OnKillfocusvexroller2)
ON_EN_SETFOCUS(IDC_searchrange, OnSetfocussearchrange)
ON_EN_KILLFOCUS(IDC_searchrange, OnKillfocussearchrange)
ON_EN_SETFOCUS(IDC_zphoto, OnSetfocuszphoto)
ON_EN_KILLFOCUS(IDC_zphoto, OnKillfocuszphoto)
ON_EN_SETFOCUS(IDC_zpicks, OnSetfocuszpicks)
ON_EN_KILLFOCUS(IDC_zpicks, OnKillfocuszpicks)
ON_EN_SETFOCUS(IDC_zpush, OnSetfocuszpush)
ON_EN_KILLFOCUS(IDC_zpush, OnKillfocuszpush)
ON_EN_SETFOCUS(IDC_zvex, OnSetfocuszvex)
ON_EN_KILLFOCUS(IDC_zvex, OnKillfocuszvex)
ON_EN_SETFOCUS(IDC_verifypastex, OnSetfocusverifypastex)
ON_EN_KILLFOCUS(IDC_verifypastex, OnKillfocusverifypastex)
ON_EN_SETFOCUS(IDC_verifypastey, OnSetfocusverifypastey)
ON_EN_KILLFOCUS(IDC_verifypastey, OnKillfocusverifypastey)
ON_EN_SETFOCUS(IDC_searchrange2, OnSetfocussearchrange2)
ON_EN_KILLFOCUS(IDC_searchrange2, OnKillfocussearchrange2)
ON_EN_SETFOCUS(IDC_reloadpick, OnSetfocusreloadpick)
ON_EN_KILLFOCUS(IDC_reloadpick, OnKillfocusreloadpick)
ON_EN_SETFOCUS(IDC_reloadpush, OnSetfocusreloadpush)
ON_EN_KILLFOCUS(IDC_reloadpush, OnKillfocusreloadpush)
ON_EN_SETFOCUS(IDC_reloadwaiting, OnSetfocusreloadwaiting)
ON_EN_KILLFOCUS(IDC_reloadwaiting, OnKillfocusreloadwaiting)
ON_EN_SETFOCUS(IDC_repasteangle, OnSetfocusrepasteangle)
ON_EN_KILLFOCUS(IDC_repasteangle, OnKillfocusrepasteangle)
ON_EN_SETFOCUS(IDC_repastex, OnSetfocusrepastex)
ON_EN_KILLFOCUS(IDC_repastex, OnKillfocusrepastex)
ON_EN_SETFOCUS(IDC_repastey, OnSetfocusrepastey)
ON_EN_KILLFOCUS(IDC_repastey, OnKillfocusrepastey)
ON_EN_SETFOCUS(IDC_loadpick, OnSetfocusloadpick)
ON_EN_KILLFOCUS(IDC_loadpick, OnKillfocusloadpick)
ON_EN_SETFOCUS(IDC_loadpush, OnSetfocusloadpush)
ON_EN_KILLFOCUS(IDC_loadpush, OnKillfocusloadpush)
ON_EN_SETFOCUS(IDC_loadwaiting, OnSetfocusloadwaiting)
ON_EN_KILLFOCUS(IDC_loadwaiting, OnKillfocusloadwaiting)
ON_EN_SETFOCUS(IDC_photor, OnSetfocusphotor)
ON_EN_KILLFOCUS(IDC_photor, OnKillfocusphotor)
ON_EN_SETFOCUS(IDC_vload, OnSetfocusvload)
ON_EN_KILLFOCUS(IDC_vload, OnKillfocusvload)
ON_BN_CLICKED(IDC_shieldpaste, Onshieldpaste)
ON_BN_CLICKED(IDC_withbeep, Onwithbeep)
ON_EN_SETFOCUS(IDC_fixturex, OnSetfocusfixturex)
ON_EN_KILLFOCUS(IDC_fixturex, OnKillfocusfixturex)
ON_EN_SETFOCUS(IDC_fixturey, OnSetfocusfixturey)
ON_EN_KILLFOCUS(IDC_fixturey, OnKillfocusfixturey)
ON_EN_SETFOCUS(IDC_numberx, OnSetfocusnumberx)
ON_EN_KILLFOCUS(IDC_numberx, OnKillfocusnumberx)
ON_EN_SETFOCUS(IDC_numbery, OnSetfocusnumbery)
ON_EN_KILLFOCUS(IDC_numbery, OnKillfocusnumbery)
ON_EN_SETFOCUS(IDC_stepx, OnSetfocusstepx)
ON_EN_KILLFOCUS(IDC_stepx, OnKillfocusstepx)
ON_EN_SETFOCUS(IDC_stepy, OnSetfocusstepy)
ON_EN_KILLFOCUS(IDC_stepy, OnKillfocusstepy)
ON_EN_SETFOCUS(IDC_specialx, OnSetfocusspecialx)
ON_EN_KILLFOCUS(IDC_specialx, OnKillfocusspecialx)
ON_EN_SETFOCUS(IDC_specialy, OnSetfocusspecialy)
ON_EN_KILLFOCUS(IDC_specialy, OnKillfocusspecialy)
ON_EN_SETFOCUS(IDC_vexfixturex, OnSetfocusvexfixturex)
ON_EN_KILLFOCUS(IDC_vexfixturex, OnKillfocusvexfixturex)
ON_EN_SETFOCUS(IDC_vexfixturey, OnSetfocusvexfixturey)
ON_EN_KILLFOCUS(IDC_vexfixturey, OnKillfocusvexfixturey)
ON_EN_SETFOCUS(IDC_loadx, OnSetfocusloadx)
ON_EN_KILLFOCUS(IDC_loadx, OnKillfocusloadx)
ON_EN_SETFOCUS(IDC_loady, OnSetfocusloady)
ON_EN_KILLFOCUS(IDC_loady, OnKillfocusloady)
ON_EN_SETFOCUS(IDC_unloadx, OnSetfocusunloadx)
ON_EN_KILLFOCUS(IDC_unloadx, OnKillfocusunloadx)
ON_EN_SETFOCUS(IDC_unloady, OnSetfocusunloady)
ON_EN_KILLFOCUS(IDC_unloady, OnKillfocusunloady)
ON_BN_CLICKED(IDC_testone, Ontestone)
ON_EN_SETFOCUS(IDC_films, OnSetfocusfilms)
ON_EN_KILLFOCUS(IDC_films, OnKillfocusfilms)
ON_EN_SETFOCUS(IDC_filml, OnSetfocusfilml)
ON_EN_KILLFOCUS(IDC_filml, OnKillfocusfilml)
    //}}AFX_MSG_MAP

ON_EN_SETFOCUS(IDC_vexlaod, &PARAMETERSET::OnSetfocusVexlaod)
ON_EN_KILLFOCUS(IDC_vexlaod, &PARAMETERSET::OnKillfocusVexlaod)
ON_EN_SETFOCUS(IDC_vexunlaod, &PARAMETERSET::OnSetfocusVexunlaod)
ON_EN_KILLFOCUS(IDC_vexunlaod, &PARAMETERSET::OnKillfocusVexunlaod)
ON_EN_SETFOCUS(IDC_load0, &PARAMETERSET::OnSetfocusLoad0)
ON_EN_KILLFOCUS(IDC_load0, &PARAMETERSET::OnKillfocusLoad0)
ON_EN_SETFOCUS(IDC_load1, &PARAMETERSET::OnSetfocusLoad1)
ON_EN_KILLFOCUS(IDC_load1, &PARAMETERSET::OnKillfocusLoad1)
ON_EN_SETFOCUS(IDC_load2, &PARAMETERSET::OnSetfocusLoad2)
ON_EN_KILLFOCUS(IDC_load2, &PARAMETERSET::OnKillfocusLoad2)
ON_EN_SETFOCUS(IDC_unload0, &PARAMETERSET::OnSetfocusUnload0)
ON_EN_KILLFOCUS(IDC_unload0, &PARAMETERSET::OnKillfocusUnload0)
ON_EN_SETFOCUS(IDC_unload1, &PARAMETERSET::OnSetfocusUnload1)
ON_EN_KILLFOCUS(IDC_unload1, &PARAMETERSET::OnKillfocusUnload1)
ON_EN_SETFOCUS(IDC_unload2, &PARAMETERSET::OnSetfocusUnload2)
ON_EN_KILLFOCUS(IDC_unload2, &PARAMETERSET::OnKillfocusUnload2)
ON_EN_CHANGE(IDC_pickx, &PARAMETERSET::OnEnChangepickx)
ON_EN_CHANGE(IDC_covery, &PARAMETERSET::OnEnChangecovery)
    //	ON_BN_CLICKED(IDC_shieldpaste2, &PARAMETERSET::OnBnClickedshieldpaste2)
ON_BN_CLICKED(IDC_traymode, &PARAMETERSET::OnBnClickedtraymode)
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
    fixturex=m_fixturex;
    fixturey=m_fixturey;
    numberx=m_numberx;
    numbery=m_numbery;
    stepx=m_stepx;
    stepy=m_stepy;
    specialx=m_specialx;
    specialy=m_specialy;
    coverx=m_coverx;
    covery=m_covery;
    vexfixturex=m_vexfixturex;
    vexfixturey=m_vexfixturey;

    vexx=m_vexx;
    vexload=m_vexload;
    vexunload=m_vexunload;
    load0=m_load0;
    load1=m_load1;
    load2=m_load2;
    unload0=m_unload0;
    unload1=m_unload1;
    unload2=m_unload2;

    films=m_films;
    filml=m_filml;
    loadx=m_loadx;
    loady=m_loady;
    unloadx=m_unloadx;
    unloady=m_unloady;
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
    zpick=m_zpick;
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
    m_photo3angle=photo3angle;
    m_photo4angle=photo4angle;

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


    m_vexload=vexload;
    m_vexunload=vexunload;
    m_load0=load0;
    m_load1=load1;
    m_load2=load2;
    m_unload0=unload0;
    m_unload1=unload1;
    m_unload2=unload2;

    m_films=films;
    m_filml=filml;
    m_loadx=loadx;
    m_loady=loady;
    m_unloadx=unloadx;
    m_unloady=unloady;

    m_fixturex=fixturex;
    m_fixturey=fixturey;
    m_numberx=numberx;
    m_numbery=numbery;
    m_stepx=stepx;
    m_stepy=stepy;
    m_specialx=specialx;
    m_specialy=specialy;
    m_coverx=coverx;
    m_covery=covery;
    m_vexfixturex=vexfixturex;
    m_vexfixturey=vexfixturey;

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
    m_zpick=zpick;
    m_zphoto=zphoto;
    m_zvex=zvex;
    m_comno=comno;
    m_vexy=vexy;
    m_carrytime=carrytime;
    m_pickangle=pickangle;
    m_pasteangle=pasteangle;
    m_minscore11=minscore11;
    m_minscore21=minscore21;

    HWND h=::FindWindow(NULL,"屏幕键盘");
    if(h!=NULL)
    {
        ::SendMessage(h,WM_CLOSE,0,0);
        SetDlgItemText(IDC_softkey,"键盘");

    }
    if(withbeep==1)
    {	SetDlgItemText(IDC_withbeep,"启用蜂鸣");}


    if(withbeep==0)	
    {SetDlgItemText(IDC_withbeep,"屏蔽蜂鸣");}
    if(repeat==0)
    {
        SetDlgItemText(IDC_fixturemove,"标定模式");
        GetDlgItem(IDC_testone)->EnableWindow(true);
    }
    if(repeat==1)
    {
        SetDlgItemText(IDC_fixturemove,"多片模式");
        GetDlgItem(IDC_testone)->EnableWindow(false);
    }

    if(shieldpaste==0)
    {SetDlgItemText(IDC_shieldpaste,"撕膜压合关");}
    else
    {SetDlgItemText(IDC_shieldpaste,"撕膜压合开");}

    if(carrytime==0)
    {
        SetDlgItemText(IDC_traymode,"TRAY模式1");

    }
    else
    {
        SetDlgItemText(IDC_traymode,"TRAY模式2");
    }
    if(testone==true)
    {SetDlgItemText(IDC_testone,"揭盖屏蔽");}
    //{SetDlgItemText(IDC_testone,"单片测试");}

    else
    {SetDlgItemText(IDC_testone,"揭盖启用");}
    //{SetDlgItemText(IDC_testone,"正常运行");}



    UpdateData( false );

    return TRUE;  // return TRUE unless you set the focus to a control
    // EXCEPTION: OCX Property Pages should return FALSE
}

void PARAMETERSET::Onsaveas() 
{
    // TODO: Add your control notification handler code here
    RcpSave dlg;
    bool repeatfile=false;
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
            {repeatfile=true;}



        }

        listrcpar.Close();
        listrcp.Close();


        if(repeatfile==false)
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


        CopyFile(currentregionsname1,(currentdir+"\\"+filename+"1.reg"),false);
        CopyFile(currentregionsname2,(currentdir+"\\"+filename+"2.reg"),false);
        CopyFile(currentregionsname3,(currentdir+"\\"+filename+"3.reg"),false);
        CopyFile(currentregionsname4,(currentdir+"\\"+filename+"4.reg"),false);

        //CopyFile(currentparametername,(currentdir+"\\"+filename+".para"),false);
        CopyFile(currentmodelname,(currentdir+"\\"+filename+"1.shm"),false);
        CopyFile(currentmodelname2,(currentdir+"\\"+filename+"2.shm"),false);
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
        vexx=m_vexx;
        vexload=m_vexload;
        vexunload=m_vexunload;
        load0=m_load0;
        load1=m_load1;
        load2=m_load2;
        unload0=m_unload0;
        unload1=m_unload1;
        unload2=m_unload2;
        films=m_films;
        filml=m_filml;
        loadx=m_loadx;
        loady=m_loady;
        unloadx=m_unloadx;
        unloady=m_unloady;
        fixturex=m_fixturex;
        fixturey=m_fixturey;
        numberx=m_numberx;
        numbery=m_numbery;
        stepx=m_stepx;
        stepy=m_stepy;
        specialx=m_specialx;
        specialy=m_specialy;
        coverx=m_coverx;
        covery=m_covery;
        vexfixturex=m_vexfixturex;
        vexfixturey=m_vexfixturey;
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
        zpick=m_zpick;
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



        currentregionsname1=currentdir+"\\"+selectrcp+"1.reg";
        currentregionsname2=currentdir+"\\"+selectrcp+"2.reg";
        currentregionsname3=currentdir+"\\"+selectrcp+"3.reg";
        currentregionsname4=currentdir+"\\"+selectrcp+"4.reg";

        currentparametername=currentdir+"\\"+selectrcp+".para";
        currentmodelname=currentdir+"\\"+selectrcp+".shm";
        currentmodelname2=currentdir+"\\"+selectrcp+"2.shm";
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
        currentphotoar>>shutter>>bright>>gain>>shutter2>>shutter3>>shutter4>>shutter5>>gain2>>contrast1>>contrast2>>model1x[0]>>model1x[1]>>model1x[2]>>model1x[3]>>model1x[4]>>model1x[5]>>model1y[0]>>model1y[1]>>model1y[2]>>model1y[3]>>model1y[4]>>model1y[5]>>model2x[0]>>model2x[1]>>model2x[2]>>model2x[3]>>model2x[4]>>model2x[5]>>model2y[0]>>model2y[1]>>model2y[2]>>model2y[3]>>model2y[4]>>model2y[5]
            >>model11halfx>>model11halfy>>model12halfx>>model12halfy>>model21halfx>>model21halfy>>model22halfx>>model22halfy>>modalorg11>>modalorg12>>modalorg21>>modalorg22
            >>remodel1x[0]>>remodel1x[1]>>remodel1x[2]>>remodel1x[3]>>remodel1x[4]>>remodel1x[5]>>remodel1y[0]>>remodel1y[1]>>remodel1y[2]>>remodel1y[3]>>remodel1y[4]>>remodel1y[5]>>remodel2x[0]>>remodel2x[1]>>remodel2x[2]>>remodel2x[3]>>remodel2x[4]>>remodel2x[5]>>remodel2y[0]>>remodel2y[1]>>remodel2y[2]>>remodel2y[3]>>remodel2y[4]>>remodel2y[5];


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
        m_vexload=vexload;
        m_vexunload=vexunload;
        m_load0=load0;
        m_load1=load1;
        m_load2=load2;
        m_unload0=unload0;
        m_unload1=unload1;
        m_unload2=unload2;
        m_films=films;
        m_filml=filml;
        m_loadx=loadx;
        m_loady=loady;
        m_unloadx=unloadx;
        m_unloady=unloady;

        m_fixturex=fixturex;
        m_fixturey=fixturey;
        m_numberx=numberx;
        m_numbery=numbery;
        m_stepx=stepx;
        m_stepy=stepy;
        m_specialx=specialx;
        m_specialy=specialy;
        m_coverx=coverx;
        m_covery=covery;
        m_vexfixturex=vexfixturex;
        m_vexfixturey=vexfixturey;
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
        m_zpick=zpick;
        m_zphoto=zphoto;
        m_zvex=zvex;
        m_comno=comno;
        m_vexy=vexy;
        m_carrytime=carrytime;
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
    {MessageBox("请选择配方");}

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
            {MessageBox("不能删除当前配方!");}
        }//IDOK
    }//LB_ERR
    if(i==LB_ERR)
    {MessageBox("请选择配方");}

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
        m_photo3angle=photo3angle;
        m_photo4angle=photo4angle;

        m_metalscaley=metalyscale;
        m_verifyinfo=verifyinfo;

        if(repeat==1)
        {
            GetDlgItem(IDC_testone)->EnableWindow(false);
        }
        if(repeat==0)
        {
            GetDlgItem(IDC_testone)->EnableWindow(true);
        }
    }

    UpdateData( false );
    KillTimer(1);
    CDialog::OnTimer(nIDEvent);
}

void PARAMETERSET::Onsoftkey() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    if(h!=NULL)
    {
        ::SendMessage(h,WM_CLOSE,0,0);
        SetDlgItemText(IDC_softkey,"键盘");
    }
    else
    {
        WinExec("c:\\windows\\system32\\osk.exe",SW_SHOWNORMAL);
        SetDlgItemText(IDC_softkey,"键盘");
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
    m_vexload=vexload;
    m_vexunload=vexunload;
    m_load0=load0;
    m_load1=load1;
    m_load2=load2;
    m_unload0=unload0;
    m_unload1=unload1;
    m_unload2=unload2;
    m_films=films;
    m_filml=filml;
    m_loadx=loadx;
    m_loady=loady;
    m_unloadx=unloadx;
    m_unloady=unloady;
    m_fixturex=fixturex;
    m_fixturey=fixturey;
    m_numberx=numberx;
    m_numbery=numbery;
    m_stepx=stepx;
    m_stepy=stepy;
    m_specialx=specialx;
    m_specialy=specialy;
    m_coverx=coverx;
    m_covery=covery;
    m_vexfixturex=vexfixturex;
    m_vexfixturey=vexfixturey;
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
    m_zpick=zpick;
    m_zphoto=zphoto;
    m_zvex=zvex;
    m_comno=comno;
    m_vexy=vexy;
    m_carrytime=carrytime;
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

void PARAMETERSET::Onfixturemove() 
{
    // TODO: Add your control notification handler code here
    int temp;
    temp=repeat;
    if(temp==0)
    {
        repeat=1;
        m_repeat=1;
        SetDlgItemText(IDC_fixturemove,"多片模式");
        //GetDlgItem(IDC_shieldpaste)->EnableWindow(false);

    }
    if(temp==1)
    {
        repeat=0;
        m_repeat=0;
        SetDlgItemText(IDC_fixturemove,"标定模式");

    }
    SetTimer(1,100,NULL);

}


void PARAMETERSET::OnLButtonDown(UINT nFlags, CPoint point) 
{
    // TODO: Add your message handler code here and/or call default
    HWND h=::FindWindow(NULL,"屏幕键盘");
    if(h!=NULL)
    {::SendMessage(h,WM_CLOSE,0,0);}

    CDialog::OnLButtonDown(nFlags, point);
}

void PARAMETERSET::OnSetfocusfixturedelaytime() 
{
    // TODO: Add your control notification handler code here

    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocusfixturedelaytime() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}

void PARAMETERSET::OnSetfocusfixtureouttime() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocusfixtureouttime() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}

void PARAMETERSET::OnSetfocusmainmotorlength() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocusmainmotorlength() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}

void PARAMETERSET::OnSetfocuspasteangle() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocuspasteangle() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}

void PARAMETERSET::OnSetfocuspastex() 

{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();


    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocuspastex() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}


void PARAMETERSET::OnSetfocuspastey() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocuspastey() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}




void PARAMETERSET::OnSetfocusphotox() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocusphotox() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}

void PARAMETERSET::OnSetfocusphotoy() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocusphotoy() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}


void PARAMETERSET::OnSetfocuspicktime() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocuspicktime() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}

void PARAMETERSET::OnSetfocuspickx() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocuspickx() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}

void PARAMETERSET::OnSetfocuspicky() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocuspicky() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}

void PARAMETERSET::OnSetfocuspushertime() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocuspushertime() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}

void PARAMETERSET::OnSetfocusrollerfinished() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocusrollerfinished() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}


void PARAMETERSET::OnSetfocusvexmainmotorhigh() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocusvexmainmotorhigh() 
{
    // TODO: Add your control notification handler code here
    PostMessage(CLOSE_SOFTKEY);	
}

void PARAMETERSET::OnSetfocusvexmainmotorlow() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocusvexmainmotorlow() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}




void PARAMETERSET::OnSetfocusvexx() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocusvexx() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}

void PARAMETERSET::OnSetfocusvexy() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocusvexy() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);		
}

void PARAMETERSET::OnSetfocusvturnplate() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocusvturnplate() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}

LRESULT PARAMETERSET::opensoftkey(WPARAM wParam,LPARAM lParam) 
{
    // TODO: Add your control notification handler code here
    RECT r;
    ::GetWindowRect(focushwnd,&r);
    HWND h=::FindWindow(NULL,"屏幕键盘");
    if(h!=NULL)
    {::SendMessage(h,WM_CLOSE,0,0);}
    WinExec("c:\\windows\\system32\\osk.exe",SW_SHOWNORMAL);
    h=::FindWindow(NULL,"屏幕键盘");
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

void PARAMETERSET::OnSetfocuspickangle() 
{
    // TODO: Add your control notification handler code here
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }


}

void PARAMETERSET::OnKillfocuspickangle() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	

}

void PARAMETERSET::Onmetalverify() 
{
    // TODO: Add your control notification handler code here
    cyclephoto=false;
    cyclephoto2=false;
    photoverify=false;

    m_verifypastex=verifypastex;
    m_verifypastey=verifypastey;
    m_verifyinfo="两个摸板对应，切居中";
    UpdateData(false);


    metalverify=true;

    initposition=false;
    SetTimer(1,500,NULL);

}





void PARAMETERSET::OnSetfocusminscore11() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocusminscore11() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	

}

void PARAMETERSET::OnSetfocusminscore21() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }
}

void PARAMETERSET::OnKillfocusminscore21() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	

}



void PARAMETERSET::OnSetfocusphotox2() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocusphotox2() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	

}

void PARAMETERSET::OnSetfocusphotoy2() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocusphotoy2() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	

}


void PARAMETERSET::OnSetfocustonguein() 
{
    // TODO: Add your control notification handler code here

    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocustonguein() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	

}

void PARAMETERSET::OnSetfocustongueout() 
{
    // TODO: Add your control notification handler code here

    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocustongueout() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	

}

void PARAMETERSET::OnSetfocusvextonguein() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocusvextonguein() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	

}

void PARAMETERSET::OnSetfocusvextongueout() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocusvextongueout() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	

}

void PARAMETERSET::OnSetfocusloadtime() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocusloadtime() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	

}

void PARAMETERSET::OnSetfocusunloadtime() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocusunloadtime() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	

}

void PARAMETERSET::OnSetfocusmetalscale() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
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
    HWND h=::FindWindow(NULL,"屏幕键盘");
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

void PARAMETERSET::OnSetfocusphotodelay() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }


}

void PARAMETERSET::OnKillfocusphotodelay() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	

}

void PARAMETERSET::OnSetfocuscarrytime() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
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

void PARAMETERSET::OnSetfocuscomno() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocuscomno() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	

}

void PARAMETERSET::OnSetfocusvexroller2() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }


}

void PARAMETERSET::OnKillfocusvexroller2() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	

}

void PARAMETERSET::OnSetfocussearchrange() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }


}

void PARAMETERSET::OnKillfocussearchrange() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	

}

void PARAMETERSET::OnSetfocuszphoto() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocuszphoto() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	

}

void PARAMETERSET::OnSetfocuszpicks() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
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

void PARAMETERSET::OnSetfocuszpush() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocuszpush() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	

}

void PARAMETERSET::OnSetfocuszvex() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocuszvex() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	

}


void PARAMETERSET::OnSetfocusverifypastex() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
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
    HWND h=::FindWindow(NULL,"屏幕键盘");
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

void PARAMETERSET::OnSetfocussearchrange2() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }


}

void PARAMETERSET::OnKillfocussearchrange2() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	

}

void PARAMETERSET::OnSetfocusreloadpick() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }	
}

void PARAMETERSET::OnKillfocusreloadpick() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}

void PARAMETERSET::OnSetfocusreloadpush() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }
}

void PARAMETERSET::OnKillfocusreloadpush() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}

void PARAMETERSET::OnSetfocusreloadwaiting() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }
}

void PARAMETERSET::OnKillfocusreloadwaiting() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}

void PARAMETERSET::OnSetfocusrepasteangle() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }
}

void PARAMETERSET::OnKillfocusrepasteangle() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}

void PARAMETERSET::OnSetfocusrepastex() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }
}

void PARAMETERSET::OnKillfocusrepastex() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}

void PARAMETERSET::OnSetfocusrepastey() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }
}

void PARAMETERSET::OnKillfocusrepastey() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}

void PARAMETERSET::OnSetfocusloadpick() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }
}

void PARAMETERSET::OnKillfocusloadpick() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}

void PARAMETERSET::OnSetfocusloadpush() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }
}

void PARAMETERSET::OnKillfocusloadpush() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}

void PARAMETERSET::OnSetfocusloadwaiting() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }
}

void PARAMETERSET::OnKillfocusloadwaiting() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}

void PARAMETERSET::OnSetfocusphotor() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }
}

void PARAMETERSET::OnKillfocusphotor() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}

void PARAMETERSET::OnSetfocusvload() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }
}

void PARAMETERSET::OnKillfocusvload() 
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
        //m_shieldpaste=1;
        SetDlgItemText(IDC_shieldpaste,"撕膜压合开");

    }
    else
    {
        shieldpaste=0;
        //m_shieldpaste=0;
        SetDlgItemText(IDC_shieldpaste,"撕膜压合关");
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

        SetDlgItemText(IDC_withbeep,"启用蜂鸣");

    }
    if(temp!=0)
    {
        withbeep=0;

        SetDlgItemText(IDC_withbeep,"屏蔽蜂鸣");
    }

}

void PARAMETERSET::OnSetfocusfixturex() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocusfixturex() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);		
}

void PARAMETERSET::OnSetfocusfixturey() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }	
}

void PARAMETERSET::OnKillfocusfixturey() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}

void PARAMETERSET::OnSetfocusnumberx() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }	
}

void PARAMETERSET::OnKillfocusnumberx() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}

void PARAMETERSET::OnSetfocusnumbery() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }	
}

void PARAMETERSET::OnKillfocusnumbery() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}

void PARAMETERSET::OnSetfocusstepx() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }
}

void PARAMETERSET::OnKillfocusstepx() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}

void PARAMETERSET::OnSetfocusstepy() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }	
}

void PARAMETERSET::OnKillfocusstepy() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);		
}

void PARAMETERSET::OnSetfocusspecialx() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }
}

void PARAMETERSET::OnKillfocusspecialx() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);		
}

void PARAMETERSET::OnSetfocusspecialy() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }	
}

void PARAMETERSET::OnKillfocusspecialy() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);		
}

void PARAMETERSET::OnSetfocusvexfixturex() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }
}

void PARAMETERSET::OnKillfocusvexfixturex() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);		
}

void PARAMETERSET::OnSetfocusvexfixturey() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }
}

void PARAMETERSET::OnKillfocusvexfixturey() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);		
}

void PARAMETERSET::OnSetfocusloadx() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }	
}

void PARAMETERSET::OnKillfocusloadx() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}

void PARAMETERSET::OnSetfocusloady() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }	
}

void PARAMETERSET::OnKillfocusloady() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);		
}

void PARAMETERSET::OnSetfocusunloadx() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }	
}

void PARAMETERSET::OnKillfocusunloadx() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}

void PARAMETERSET::OnSetfocusunloady() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }	
}

void PARAMETERSET::OnKillfocusunloady() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	
}

void PARAMETERSET::Ontestone() 
{
    // TODO: Add your control notification handler code here
    if(C4getPover==true)
    {
        C4verifyP=1;
    }


}

void PARAMETERSET::OnSetfocusfilms() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocusfilms() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	

}

void PARAMETERSET::OnSetfocusfilml() 
{
    // TODO: Add your control notification handler code here
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }

}

void PARAMETERSET::OnKillfocusfilml() 
{
    // TODO: Add your control notification handler code here
    SendMessage(CLOSE_SOFTKEY);	

}


void PARAMETERSET::OnEnChangevexy2()
{
    // TODO:  如果该控件是 RICHEDIT 控件，它将不
    // 发送此通知，除非重写 CDialog::OnInitDialog()
    // 函数并调用 CRichEditCtrl().SetEventMask()，
    // 同时将 ENM_CHANGE 标志“或”运算到掩码中。

    // TODO:  在此添加控件通知处理程序代码
}


void PARAMETERSET::OnSetfocusVexlaod()
{
    // TODO: 在此添加控件通知处理程序代码
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }
}


void PARAMETERSET::OnKillfocusVexlaod()
{
    // TODO: 在此添加控件通知处理程序代码
    SendMessage(CLOSE_SOFTKEY);
}


void PARAMETERSET::OnSetfocusVexunlaod()
{
    // TODO: 在此添加控件通知处理程序代码
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }
}


void PARAMETERSET::OnKillfocusVexunlaod()
{
    // TODO: 在此添加控件通知处理程序代码
    SendMessage(CLOSE_SOFTKEY);
}


void PARAMETERSET::OnSetfocusLoad0()
{
    // TODO: 在此添加控件通知处理程序代码
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }
}


void PARAMETERSET::OnKillfocusLoad0()
{
    // TODO: 在此添加控件通知处理程序代码
    SendMessage(CLOSE_SOFTKEY);
}


void PARAMETERSET::OnSetfocusLoad1()
{
    // TODO: 在此添加控件通知处理程序代码
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }
}


void PARAMETERSET::OnKillfocusLoad1()
{
    // TODO: 在此添加控件通知处理程序代码
    SendMessage(CLOSE_SOFTKEY);
}


void PARAMETERSET::OnSetfocusLoad2()
{
    // TODO: 在此添加控件通知处理程序代码
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }
}


void PARAMETERSET::OnKillfocusLoad2()
{
    // TODO: 在此添加控件通知处理程序代码
    SendMessage(CLOSE_SOFTKEY);
}


void PARAMETERSET::OnSetfocusUnload0()
{
    // TODO: 在此添加控件通知处理程序代码
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }
}


void PARAMETERSET::OnKillfocusUnload0()
{
    // TODO: 在此添加控件通知处理程序代码
    SendMessage(CLOSE_SOFTKEY);
}


void PARAMETERSET::OnSetfocusUnload1()
{
    // TODO: 在此添加控件通知处理程序代码
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }
}


void PARAMETERSET::OnKillfocusUnload1()
{
    // TODO: 在此添加控件通知处理程序代码
    SendMessage(CLOSE_SOFTKEY);
}


void PARAMETERSET::OnSetfocusUnload2()
{
    // TODO: 在此添加控件通知处理程序代码
    HWND h=::FindWindow(NULL,"屏幕键盘");
    focushwnd=::GetFocus();

    {
        PostMessage(OPEN_SOFTKEY);
    }
}


void PARAMETERSET::OnKillfocusUnload2()
{
    // TODO: 在此添加控件通知处理程序代码
    SendMessage(CLOSE_SOFTKEY);
}


void PARAMETERSET::OnEnChangepickx()
{
    // TODO:  如果该控件是 RICHEDIT 控件，它将不
    // 发送此通知，除非重写 CDialog::OnInitDialog()
    // 函数并调用 CRichEditCtrl().SetEventMask()，
    // 同时将 ENM_CHANGE 标志“或”运算到掩码中。

    // TODO:  在此添加控件通知处理程序代码
}


void PARAMETERSET::OnEnChangecovery()
{
    // TODO:  如果该控件是 RICHEDIT 控件，它将不
    // 发送此通知，除非重写 CDialog::OnInitDialog()
    // 函数并调用 CRichEditCtrl().SetEventMask()，
    // 同时将 ENM_CHANGE 标志“或”运算到掩码中。

    // TODO:  在此添加控件通知处理程序代码
}





void PARAMETERSET::OnBnClickedtraymode()
{
    // TODO: 在此添加控件通知处理程序代码
    int temp;
    temp=carrytime;
    if(temp==0)
    {
        carrytime=1;
        SetDlgItemText(IDC_traymode,"TRAY模式2");

    }
    else
    {
        carrytime=0;
        SetDlgItemText(IDC_traymode,"TRAY模式1");
    }
}
