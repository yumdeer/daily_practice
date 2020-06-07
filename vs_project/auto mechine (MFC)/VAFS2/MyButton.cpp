// MyButton.cpp : implementation file
//

#include "stdafx.h"
#include "VAFS2.h"
#include "MyButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyButton

CMyButton::CMyButton()
{
}

CMyButton::~CMyButton()
{
}


BEGIN_MESSAGE_MAP(CMyButton, CButton)
	//{{AFX_MSG_MAP(CMyButton)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyButton message handlers
BOOL CMyButton::OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	// TODO: 在此添加专用代码和/或调用基类

	WPARAM wParam1;

    switch(message)

	{

	case WM_LBUTTONDOWN:
        wParam1=(((DWORD)WM_LBUTTONDOWN)<<16)+((DWORD)GetDlgCtrlID());
		::SendMessage(this->GetParent()->m_hWnd, 9999, wParam1, 0);
		

		break;

	case WM_LBUTTONUP:
        wParam1=(((DWORD)WM_LBUTTONUP)<<16)+((DWORD)GetDlgCtrlID());
		::SendMessage(this->GetParent()->m_hWnd, 9999, wParam1, 0);
		

		break;

	default:

		break;

	}
	return CButton::OnWndMsg(message, wParam, lParam, pResult);
}
