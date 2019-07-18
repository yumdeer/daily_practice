// vc_c++Dlg.cpp: 实现文件
//

#include "stdafx.h"
#include "vc_c++.h"
#include "vc_c++Dlg.h"
#include "CUIThreadApp.h"
#include "afxdialogex.h"
<<<<<<< HEAD
#include "CTestClass.h"
=======
>>>>>>> temp
#include <process.h> 
#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CvccDlg 对话框
<<<<<<< HEAD
=======



>>>>>>> temp
CvccDlg::CvccDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_VC_C_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CvccDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CvccDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN, &CvccDlg::OnBnClickedBtn)
<<<<<<< HEAD
	ON_BN_CLICKED(IDC_SUSPEND_BTN, &CvccDlg::OnBnClickedSuspendBtn)
	ON_BN_CLICKED(IDC_RESUME_BTN, &CvccDlg::OnBnClickedResumeBtn)
	ON_BN_CLICKED(IDC_ExitCode_BTN, &CvccDlg::OnBnClickedExitcodeBtn)
=======
>>>>>>> temp
END_MESSAGE_MAP()


// CvccDlg 消息处理程序

BOOL CvccDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CvccDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CvccDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CvccDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//第一课：认识和创建线程
////DWORD WINAPI ThreadProc(LPVOID lpParameter)				//CreateThread
//UINT _cdecl ThreadProc(LPVOID lpParameter)					//AfxBeginThread方式
////unsigned int __stdcall ThreadProc(LPVOID lpParameter)     //_beginthreadex方式
//{
//	//VC驿站多线程第一课：认识和创建线程
//	//int tipMsg = (int)lpParameter;
//	//CString strMsg;
//	//strMsg.Format(_T("%d"), tipMsg); //将int转换为CSString
//	//AfxMessageBox(strMsg);  //_T("Hello")是一个宏,他的作用是让你的程序支持Unicode编码
//	
//	return 0;
//}

//第二课：线程的运行状态
//UINT _cdecl CvccDlg::ThreadProc(LPVOID lpParameter){
//	//Sleep(10000);									//分线程睡眠，不影响主线程对话框
//	//分线程调用主线程函数中的变量
//	CvccDlg *pThisDlg = (CvccDlg*)lpParameter;		//通过主对话框类指针调用主线程函数中的成员变量
//	int tipMsg = pThisDlg->m_Num;					
//	CString strTipMsg;
//	while (TRUE) {
//		strTipMsg.Format(_T("num=%d"), tipMsg++);
//		OutputDebugString(strTipMsg);				//将字符串输出到日志,使用DebugView可以观察输出
//		Sleep(50);
//	}
//
//	return 0;
//}

//第三课：工作线程和界面线程

//工作线程
//UINT _cdecl CvccDlg::ThreadProc(LPVOID lpParameter) {
//	CvccDlg *pThisDlg = (CvccDlg*)lpParameter;
//
//	//CTESTDlg dlg;
//	//dlg.DoModal();							  //模态对话框的弹出(阻塞)，只有线程函数返回了，DoModal（）退出了，才会继续向下走。但在工作线程不建议使用这种方法
//
//	CTESTDlg *pTestDlg = new CTESTDlg();
//	pTestDlg->Create(IDD_DIALOG1, pTestDlg);
//	pTestDlg->ShowWindow(SW_SHOW);                //非模态对话框，程序执行完继续向下走（没有阻塞），直到return 返回退出了。
//	//Sleep(1000 * 5);							 //工作线程没有消息循环，对话框界面刷新工作和鼠标键盘等都不会响应
//	MSG msg = { 0 };						      //为工作线程添加消息循环
//	while (GetMessage(&msg, NULL, 0, 0)) {		  //从当前线程的消息队列取消息，并进行转换与分发
//		TranslateMessage(&msg);
//		DispatchMessage(&msg);
//	}
//
//	return 0;
//}

<<<<<<< HEAD

//第四课：线程的挂起与恢复
HANDLE hThread = NULL;
//UINT _cdecl CvccDlg::ThreadProc(LPVOID lpParameter) {
//	int tipMsg = (int)lpParameter;
//	CString strTipMsg;
//	while (TRUE) {
//		strTipMsg.Format(_T("num=%d"), tipMsg);
//		OutputDebugString(strTipMsg);				//将字符串输出到日志,使用DebugView可以观察输出
//		Sleep(50);
//	}
//
//	return 100;
//}

//线程的优先级
//UINT __cdecl ThreadProc1(LPVOID lpParameter)
//{
//	CStdioFile mFile;
//	mFile.Open(_T("D:\\123.txt"), CFile::modeCreate | CFile::modeReadWrite);
//	int tipMsg = (int)lpParameter;
//	CString strTipMsg;
//	while (TRUE) {
//		strTipMsg.Format(_T("%d\r"), tipMsg);
//		mFile.WriteString(strTipMsg);
//	}
//
//	mFile.Close();
//
//	return 0;
//}
//
//UINT __cdecl ThreadProc2(LPVOID lpParameter)
//{
//	CStdioFile mFile;
//	mFile.Open(_T("D:\\456.txt"), CFile::modeCreate | CFile::modeReadWrite);
//	int tipMsg = (int)lpParameter;
//	CString strTipMsg;
//	while (TRUE) {
//		strTipMsg.Format(_T("%d\r"), tipMsg);
//		mFile.WriteString(strTipMsg);
//	}
//
//	mFile.Close();
//
//	return 0;
//}

UINT _cdecl CvccDlg::ThreadProc(LPVOID lpParameter) {
	CTestClass m_Obj;
	//ExitThread(0);  //线程主动退出，线程函数里面对象的析构函数不会被调用，线程申请的空间被释放，C++不推荐使用
	
	return 100;
}

=======
>>>>>>> temp
void CvccDlg::OnBnClickedBtn()
{
	//// TODO: 在此添加控件通知处理程序代码
	//	https://qimo601.iteye.com/blog/1726262

	//实验，弹出文字
	//CString str("boom");
	//AfxMessageBox(str);

	//*************VC驿站多线程第一课：认识和创建线程
	//创建线程的三种方法

	//方法一：CreateThread
	//DWORD dwThreadID = 0;	//获取线程ID
	//HANDLE hThread = CreateThread(NULL,0,ThreadProc,(LPVOID)123,0, &dwThreadID); //新线程的句柄 , 工作线程
	//CloseHandle(hThread);	//关闭线程

	//方法二：AfxBeginThread
	//CWinThread *pThread = AfxBeginThread(ThreadProc, (LPVOID)123);

	//方法三：_beginthreadex
	//DWORD dwThreadID = 0;
	//HANDLE hThread = (HANDLE)_beginthreadex(NULL,0, ThreadProc,(LPVOID)123,0,(unsigned int *)dwThreadID);
	//_endthread();
	
	//*************第二课：线程的运行状态
	//Sleep(10000); //主线程进行睡眠被堵塞，主对话框界面将会卡住
	/*m_Num = 123;
	CWinThread *pThread = AfxBeginThread(ThreadProc, this);*/ //工作线程，不涉及界面的操作：数据的处理，网络通信等

	//*************第三课：工作线程和界面线程
	//区别：界面实际就是一个线程画出来的东西，这个线程维护一个“消息队列”，“消息队列”也是界面线程和工作者线程的最大区别
	//关于UI（界面）线程和工作者线程的分配，最好的做法是：将所有与UI相关的操作放入主线程，其它的纯粹的运算工作交给独立的数个工作者线程。
	//界面线程:主要是用于处理用户的输入并响应各种事件和消息，他是由CWinThread派生出来的
	//资源视图添加Dialog，并鼠标右键添加类（CWinThread派生）

	//在MFC程序中创建一个线程，宜调用AfxBeginThread函数。该函数因参数不同而具有两种重载版本，分别对应工作者线程和界面线程, 
	// CWinThread *pThread = AfxBeginThread(RUNTIME_CLASS(CUIThreadApp)); //界面线程，VS2017报错：内存不足
<<<<<<< HEAD
	 //CUIThreadApp* pthread = new CUIThreadApp();
	 //pthread->CreateThread(); //还需要CloseHandle()
	 //CloseHandle(pthread);

	//*************第四课：线程的相关操作
	//线程的挂起与恢复
	//CWinThread *pThread = AfxBeginThread(ThreadProc, (LPVOID)123);
	// hThread = pThread->m_hThread; 

	//线程的优先级
	//CWinThread *pThread = AfxBeginThread(ThreadProc1, (LPVOID)111,THREAD_PRIORITY_LOWEST);
	//SetThreadPriority(pThread->m_hThread, THREAD_PRIORITY_LOWEST);
	//pThread = AfxBeginThread(ThreadProc2, (LPVOID)789, THREAD_PRIORITY_HIGHEST);
	//SetThreadPriority(pThread->m_hThread, THREAD_PRIORITY_HIGHEST);

	//线程的退出与终结
	CWinThread *pThread = AfxBeginThread(ThreadProc, (LPVOID)123); //AfxBeginThread()会自动释放句柄
	pThread->m_bAutoDelete=false; //防止AfxBeginThread自动释放句柄,因此后面要手动关闭句柄
	hThread = pThread->m_hThread; 
}

//第四课：线程的挂起与恢复
void CvccDlg::OnBnClickedSuspendBtn()
{
	SuspendThread(hThread);
}

void CvccDlg::OnBnClickedResumeBtn()
{
	ResumeThread(hThread);
}

//获取退出码
void CvccDlg::OnBnClickedExitcodeBtn()
{
	DWORD dwExitCode = 0;                 
	GetExitCodeThread(hThread, &dwExitCode);		//监视菜单打上@err 看到错误码。在工具-错误查找 可以看到对应的错误。
	CloseHandle(hThread);							//手动释放句柄
=======
	 CUIThreadApp* pthread = new CUIThreadApp();
	 pthread->CreateThread(); //还需要CloseHandle()
	 CloseHandle(pthread);

	//第四课：线程的相关操作
	//CWinThread *pThread = AfxBeginThread(ThreadProc, (LPVOID)123);

>>>>>>> temp
}
