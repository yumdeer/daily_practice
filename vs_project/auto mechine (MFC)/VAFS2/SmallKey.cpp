// SmallKey.cpp : implementation file
//

#include "stdafx.h"
#include "VAFS2.h"
#include "SmallKey.h"
#include "externs.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//////////////////////////////////////////colorvariable
HBRUSH keyfixcolor;
HBRUSH keywhitecolor;
/////////////////////////////////////////////////////////////////////////////
// CSmallKey dialog


CSmallKey::CSmallKey(CWnd* pParent /*=NULL*/)
	: CDialog(CSmallKey::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSmallKey)
	m_maximum = (0);
	m_minimum = (0);
	m_prompt = _T("");
	//}}AFX_DATA_INIT
}


void CSmallKey::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSmallKey)
	DDX_Control(pDX, IDC_Input, m_cinput);
	DDX_Text(pDX, IDC_Maximum, m_maximum);
	DDX_Text(pDX, IDC_Minimum, m_minimum);
	DDX_Text(pDX, IDC_Prompt, m_prompt);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSmallKey, CDialog)
	//{{AFX_MSG_MAP(CSmallKey)
	ON_WM_CTLCOLOR()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSmallKey message handlers

void CSmallKey::OnOK() 
{
	// TODO: Add extra validation here
	
	m_inputfloat = inputftemp;
	//UpdateData(true);
	CDialog::OnOK();
}

BOOL CSmallKey::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (pMsg->message == WM_LBUTTONUP)
	{
		OnBtnClick(pMsg->hwnd);
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CSmallKey::OnBtnClick(HWND hButton)
{
    CButton *pButton = (CButton*)CButton::FromHandle(hButton);
	if ((pButton==GetDlgItem(IDC_Num0))||(pButton == GetDlgItem(IDC_Num1))||(pButton == GetDlgItem(IDC_Num2))||(pButton == GetDlgItem(IDC_Num3))||
		(pButton == GetDlgItem(IDC_Num4))|| (pButton == GetDlgItem(IDC_Num5))|| (pButton == GetDlgItem(IDC_Num6))|| (pButton == GetDlgItem(IDC_Num7))||
		(pButton == GetDlgItem(IDC_Num8))|| (pButton == GetDlgItem(IDC_Num9))|| (pButton == GetDlgItem(IDC_Num10))|| (pButton == GetDlgItem(IDC_Num11))||
		(pButton == GetDlgItem(IDC_Num12))|| (pButton == GetDlgItem(IDC_Num13)))
	{
		CString str;
		pButton->GetWindowText(str);
		CString text;
		m_cinput.GetWindowText(text);
		if (str == "<-")
		{
			text = text.Left(text.GetLength() - 1);
			
		}
		else if(str == "C")
		{
			text = "";
			
		}
		else
		{
			text.Insert(text.GetLength(), str);			
		}
		m_cinput.SetWindowText(text);		
		//UpdateData(true);
					
			inputftemp = atof(text);
			if ((inputftemp < m_minimum) || (inputftemp > (m_maximum)))
			{
				GetDlgItem(IDOK)->EnableWindow(false);
				GetDlgItem(IDC_Prompt)->SetWindowText(_T("输入值超限"));
				
			}
			else
			{
				GetDlgItem(IDOK)->EnableWindow(true);
				GetDlgItem(IDC_Prompt)->SetWindowText(_T("请输入"));
			}
		Updateinput();
	}
}

HBRUSH CSmallKey::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	

	
	// TODO: Return a different brush if the default is not desired
	long lstyle = GetWindowLong(GetDlgItem(IDOK)->m_hWnd, GWL_STYLE);
	
	if ((pWnd->GetDlgCtrlID() == IDC_Input) && (lstyle & WS_DISABLED))
	{
		pDC->SetBkMode(TRANSPARENT);		
		//HBRUSH B = CreateSolidBrush(RGB(255, 0, 0));
		//return (HBRUSH)B;
		DeleteObject(keyfixcolor);
		keyfixcolor=CreateSolidBrush(RGB(255, 0, 0));
		return (HBRUSH)keyfixcolor;
	}
	if(((lstyle & WS_DISABLED)!=1)&&(pWnd->GetDlgCtrlID() == IDC_Input))
	{
        pDC->SetBkMode(TRANSPARENT);		
		//HBRUSH B = CreateSolidBrush(RGB(255, 255, 255));
		//return (HBRUSH)B;
		DeleteObject(keywhitecolor);
		keywhitecolor=CreateSolidBrush(RGB(255, 255, 255));
		return (HBRUSH)keywhitecolor;
	}
	return hbr;
}

BOOL CSmallKey::OnInitDialog() 
{
	CDialog::OnInitDialog();
    
	//ModifyStyle(0,WS_CLIPSIBLINGS); 
	//ModifyStyle(0,WS_CLIPCHILDREN);
	// TODO: Add extra initialization here
	if(smallkeyFontinit==false)
	{
		smallkeyFontinit=true;
	CFont* Font1 = new CFont;
	Font1->CreatePointFont(180, _T("黑体"), NULL);
	GetDlgItem(IDC_Input)->SetFont(Font1);
    CFont* Font2 = new CFont;
	Font2->CreatePointFont(120, _T("宋体"), NULL);
	GetDlgItem(IDCANCEL)->SetFont(Font2);
	GetDlgItem(IDOK)->SetFont(Font2);
	}

	CRect rectdlg;
	this->GetWindowRect(&rectdlg);
	ScreenToClient(&rectdlg);
	//rectdlg.SetRect(ctlposL, rectdlg.top);

	int nScreenWidth, nScreenHeight;  
    nScreenWidth = GetSystemMetrics(SM_CXSCREEN);  
    nScreenHeight = GetSystemMetrics(SM_CYSCREEN);

	if((ctlposL.x-rectdlg.left+rectdlg.right>nScreenWidth)&&(ctlposL.y - rectdlg.top + rectdlg.bottom<nScreenHeight))
	{
		MoveWindow(CRect(ctlposL.x+rectdlg.left-rectdlg.right, ctlposL.y,ctlposL.x ,ctlposL.y - rectdlg.top + rectdlg.bottom));
	}
	if((ctlposL.x-rectdlg.left+rectdlg.right<nScreenWidth)&&(ctlposL.y - rectdlg.top + rectdlg.bottom>nScreenHeight))
	{
		MoveWindow(CRect(ctlposL.x, ctlposL.y + rectdlg.top - rectdlg.bottom,ctlposL.x-rectdlg.left+rectdlg.right ,ctlposL.y));
	}
	if((ctlposL.x-rectdlg.left+rectdlg.right>nScreenWidth)&&(ctlposL.y - rectdlg.top + rectdlg.bottom>nScreenHeight))
	{
		MoveWindow(CRect(ctlposL.x+rectdlg.left-rectdlg.right-50, ctlposL.y+ rectdlg.top - rectdlg.bottom-25,ctlposL.x-50 ,ctlposL.y-25 ));
	}
	if((ctlposL.x-rectdlg.left+rectdlg.right<nScreenWidth)&&(ctlposL.y - rectdlg.top + rectdlg.bottom<nScreenHeight))
	{
		MoveWindow(CRect(ctlposL.x, ctlposL.y,ctlposL.x-rectdlg.left+rectdlg.right ,ctlposL.y - rectdlg.top + rectdlg.bottom));
	}


	if (m_intype == inlong)
	{
		GetDlgItem(IDC_Num12)->EnableWindow(false);
		CString aaa;
		long bbb;
		bbb = m_inputfloat;
		aaa.Format(_T("%d"), bbb);
		m_cinput.SetWindowText(aaa);
		
	}
	else if (m_intype == infloat)
	{
		GetDlgItem(IDC_Num12)->EnableWindow(true);
		
		CString aaa;
		aaa.Format(_T("%0.1f"), m_inputfloat);
		m_cinput.SetWindowText(aaa);
		
	}
    inputftemp = m_inputfloat;
	return TRUE;
	// return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSmallKey::Updateinput()
{
    CRect rect;
	GetDlgItem(IDC_Input)->GetWindowRect(&rect);
	ScreenToClient(&rect);
	InvalidateRect(rect);
}

void CSmallKey::OnDestroy() 
{
	CDialog::OnDestroy();
	

	DeleteObject(keyfixcolor);
	DeleteObject(keywhitecolor);
	// TODO: Add your message handler code here
	
}
