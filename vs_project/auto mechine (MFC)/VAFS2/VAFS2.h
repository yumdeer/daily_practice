// VAFS2.h : main header file for the VAFS2 application
//


#if !defined(AFX_VAFS2_H__2480ED15_5910_40C6_ACDD_78EBE683E354__INCLUDED_)
#define AFX_VAFS2_H__2480ED15_5910_40C6_ACDD_78EBE683E354__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "VAFS2_i.h"

/////////////////////////////////////////////////////////////////////////////
// CVAFS2App:
// See VAFS2.cpp for the implementation of this class
//

class CVAFS2App : public CWinApp
{
public:
	CVAFS2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVAFS2App)
	public:
	virtual BOOL InitInstance();
		virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CVAFS2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
 
    
private:
	BOOL m_bATLInited;
private:
	BOOL InitATL();
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VAFS2_H__2480ED15_5910_40C6_ACDD_78EBE683E354__INCLUDED_)
