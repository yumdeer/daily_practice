#include "stdafx.h"
#include "CUIThreadApp.h"
#include <iostream>
#include <memory.h>


CUIThreadApp::CUIThreadApp()
{
}


CUIThreadApp::~CUIThreadApp()
{
	
}

//第三课
//添加重载：类视图选择对应的类，属性面板-重写（绿色小按钮）
BOOL CUIThreadApp::InitInstance()
{
	// TODO: 在此添加专用代码和/或调用基类
	
	//添加模块对话款
	//CTESTDlg dlg; 
	//dlg.DoModal();
	//return FALSE;

	//添加非模块对话框
	//CTESTDlg *pTestDlg = new CTESTDlg();
	std::unique_ptr<CTESTDlg> pTestDlg(new CTESTDlg());
	pTestDlg->Create(IDD_DIALOG1);
	pTestDlg->ShowWindow(SW_SHOW);
	//return TRUE;
	pTestDlg->RunModalLoop(); //执行模态交易循环
	return FALSE;


}


int CUIThreadApp::ExitInstance()
{
	// TODO: 在此添加专用代码和/或调用基类
	return CWinThread::ExitInstance();
}


