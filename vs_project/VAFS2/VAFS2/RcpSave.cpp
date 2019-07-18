// RcpSave.cpp : implementation file
//

#include "stdafx.h"
#include "VAFS2.h"
#include "RcpSave.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// RcpSave dialog


RcpSave::RcpSave(CWnd* pParent /*=NULL*/)
	: CDialog(RcpSave::IDD, pParent)
{
	//{{AFX_DATA_INIT(RcpSave)
	m_newrcpname = _T("");
	//}}AFX_DATA_INIT
}


void RcpSave::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(RcpSave)
	DDX_Text(pDX, IDC_EDIT1, m_newrcpname);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(RcpSave, CDialog)
	//{{AFX_MSG_MAP(RcpSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// RcpSave message handlers

void RcpSave::OnOK() 
{
	// TODO: Add extra validation here
		UpdateData(true);
	
	CDialog::OnOK();
}
