// CTESTDlg.cpp: 实现文件

#include "stdafx.h"
#include "vc_c++.h"
#include "CTESTDlg.h"
#include "afxdialogex.h"


// CTESTDlg 对话框

IMPLEMENT_DYNAMIC(CTESTDlg, CDialog)

CTESTDlg::CTESTDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
{

}

CTESTDlg::~CTESTDlg()
{
}

void CTESTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTESTDlg, CDialog)
	ON_BN_CLICKED(IDCANCEL, &CTESTDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CTESTDlg 消息处理程序


void CTESTDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	PostQuitMessage(0);
	CDialog::OnCancel();
}
