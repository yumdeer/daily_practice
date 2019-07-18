#pragma once

#include <afxwin.h>
#include "CTESTDlg.h"
#include "vc_c++.h"


class CUIThreadApp :
	public CWinThread
{
public:
	CUIThreadApp();
	~CUIThreadApp();
	virtual int ExitInstance();
	virtual BOOL InitInstance();
};

