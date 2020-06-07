// VAFS2.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "VAFS2.h"
#include "VAFS2Dlg.h"
#include   <afxsock.h> 
#include <initguid.h>
#include "VAFS2_i.c"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
struct static_init
{
static_init() { CoUninitialize(); OleInitialize( 0 ); }
};

#pragma init_seg( user )
static_init sys_init;




/////////////////////////////////////////////////////////////////////////////
// CVAFS2App

BEGIN_MESSAGE_MAP(CVAFS2App, CWinApp)
	//{{AFX_MSG_MAP(CVAFS2App)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVAFS2App construction

CVAFS2App::CVAFS2App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CVAFS2App object

CVAFS2App theApp;

/////////////////////////////////////////////////////////////////////////////
// CVAFS2App initialization

BOOL CVAFS2App::InitInstance()
{
/*	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}*/
//	_CrtSetBreakAlloc(467);

	/*if( !DShowLib::InitLibrary( "ISB3200016679" ) )
	{
		AfxMessageBox( "The library could not be initialized.\n(invalid license key?)" );
		exit( 1 );
	}*/
	if (!InitATL())
		return FALSE;

	AfxEnableControlContainer();

	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	if (cmdInfo.m_bRunEmbedded || cmdInfo.m_bRunAutomated)
	{
		return TRUE;
	}




	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CVAFS2Dlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

	
CVAFS2Module _Module;

BEGIN_OBJECT_MAP(ObjectMap)
END_OBJECT_MAP()

LONG CVAFS2Module::Unlock()
{
	AfxOleUnlockApp();
	return 0;
}

LONG CVAFS2Module::Lock()
{
	AfxOleLockApp();
	return 1;
}
LPCTSTR CVAFS2Module::FindOneOf(LPCTSTR p1, LPCTSTR p2)
{
	while (*p1 != NULL)
	{
		LPCTSTR p = p2;
		while (*p != NULL)
		{
			if (*p1 == *p)
				return CharNext(p1);
			p = CharNext(p);
		}
		p1++;
	}
	return NULL;
}


int CVAFS2App::ExitInstance()
{
	if (m_bATLInited)
	{
		_Module.RevokeClassObjects();
		_Module.Term();
		CoUninitialize();
	}

	return CWinApp::ExitInstance();

}

BOOL CVAFS2App::InitATL()
{
	m_bATLInited = TRUE;

#if _WIN32_WINNT >= 0x0400
	HRESULT hRes = CoInitializeEx(NULL, COINIT_MULTITHREADED);
#else
	HRESULT hRes = CoInitialize(NULL);
#endif

	if (FAILED(hRes))
	{
		m_bATLInited = FALSE;
		return FALSE;
	}

	_Module.Init(ObjectMap, AfxGetInstanceHandle());
	_Module.dwThreadID = GetCurrentThreadId();

	LPTSTR lpCmdLine = GetCommandLine(); //this line necessary for _ATL_MIN_CRT
	TCHAR szTokens[] = _T("-/");

	BOOL bRun = TRUE;
	LPCTSTR lpszToken = _Module.FindOneOf(lpCmdLine, szTokens);
	while (lpszToken != NULL)
	{
		if (lstrcmpi(lpszToken, _T("UnregServer"))==0)
		{
			_Module.UpdateRegistryFromResource(IDR_VAFS2, FALSE);
			_Module.UnregisterServer(TRUE); //TRUE means typelib is unreg'd
			bRun = FALSE;
			break;
		}
		if (lstrcmpi(lpszToken, _T("RegServer"))==0)
		{
			_Module.UpdateRegistryFromResource(IDR_VAFS2, TRUE);
			_Module.RegisterServer(TRUE);
			bRun = FALSE;
			break;
		}
		lpszToken = _Module.FindOneOf(lpszToken, szTokens);
	}

	if (!bRun)
	{
		m_bATLInited = FALSE;
		_Module.Term();
		CoUninitialize();
		return FALSE;
	}

	hRes = _Module.RegisterClassObjects(CLSCTX_LOCAL_SERVER, 
		REGCLS_MULTIPLEUSE);
	if (FAILED(hRes))
	{
		m_bATLInited = FALSE;
		CoUninitialize();
		return FALSE;
	}	

	return TRUE;

}
