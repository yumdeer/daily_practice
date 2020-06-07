/// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__FB3CD660_CB87_4BA1_99CB_A8C7FFD4FD23__INCLUDED_)
#define AFX_STDAFX_H__FB3CD660_CB87_4BA1_99CB_A8C7FFD4FD23__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers
#include <iostream>


#include<math.h>

#include "AAFStage.h"


#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls

#include "DVP_SDK\\Include\\DVP_CamAPI.h"
#pragma comment(lib, "DVP_SDK\\Lib\\DVP_CAMSDK.lib")

#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT
typedef struct
{
	float x;
	float y;
}mypoint;

typedef struct
{
	float x;
	float y;
	float theta;
	float score;
}metalpoint;


#include "HalconCpp.h"

using namespace Halcon;
using namespace std;



	#define _ATL_APARTMENT_THREADED
#include <atlbase.h>
//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module
class CVAFS2Module : public CComModule
{
public:
	LONG Unlock();
	LONG Lock();
	LPCTSTR FindOneOf(LPCTSTR p1, LPCTSTR p2);
	DWORD dwThreadID;
};
extern CVAFS2Module _Module;

//smallkey input type
typedef enum 
{
	inlong,
	infloat,
}intype;
#include <atlcom.h>

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
//#include "tisudshl.h" 
#include <algorithm>

#endif // !defined(AFX_STDAFX_H__FB3CD660_CB87_4BA1_99CB_A8C7FFD4FD23__INCLUDED_)

