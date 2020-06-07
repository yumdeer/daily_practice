// DELETERCP.cpp : implementation file
//

#include "stdafx.h"
#include "VAFS2.h"
#include "DELETERCP.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DELETERCP dialog


DELETERCP::DELETERCP(CWnd* pParent /*=NULL*/)
	: CDialog(DELETERCP::IDD, pParent)
{
	//{{AFX_DATA_INIT(DELETERCP)
	m_selectrcp = _T("");
	//}}AFX_DATA_INIT
}


void DELETERCP::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DELETERCP)
	DDX_Text(pDX, IDC_selectrcp, m_selectrcp);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DELETERCP, CDialog)
	//{{AFX_MSG_MAP(DELETERCP)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DELETERCP message handlers

BOOL DELETERCP::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	    
	
		GetDlgItem( IDC_selectrcp )->SetWindowText(m_selectrcp );
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
