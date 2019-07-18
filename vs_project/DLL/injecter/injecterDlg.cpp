
// injecterDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "injecter.h"
#include "injecterDlg.h"
#include "afxdialogex.h"
#include "tlhelp32.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CinjecterDlg 对话框




CinjecterDlg::CinjecterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CinjecterDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CinjecterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CinjecterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_BN_CLICKED(IDC_BUTTON1, &CinjecterDlg::OnBnClickedButton1)
	//ON_BN_CLICKED(IDC_BUTTON2, &CinjecterDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_OPEN, &CinjecterDlg::OnBnClickedOpen)
	ON_EN_CHANGE(IDC_EDIT2, &CinjecterDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_INJECT, &CinjecterDlg::OnBnClickedInject)
END_MESSAGE_MAP()


// CinjecterDlg 消息处理程序

BOOL CinjecterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CinjecterDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CinjecterDlg::OnPaint()
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
HCURSOR CinjecterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//typedef int (*ADD)(int a ,int b);
//typedef int (*SUB)(int a ,int b);
//
//void CinjecterDlg::OnBnClickedButton1()
//{
//	HMODULE hModule = LoadLibraryW(_T("F:\\vs project\\DLL\\Debug\\DLL.dll") );// TODO: 在此添加控件通知处理程序代码
//	if (!hModule)
//	{
//	 return ;
//	}
//	ADD Add;
//	SUB Sub;
//	Add = (ADD)GetProcAddress(hModule, "Add");
//	Sub = (SUB)GetProcAddress(hModule, "Sub");
//	if ( !Add || !Sub )
//	{
//	 return;
//	}
//	int Result;
//	Result =0;
//	Result =Add(10,5);
//	CString result;
//	result.Format(_T("%d"),Result);
//	MessageBox(result);
//    Result = Sub(10,5);
//	result.Format(_T("%d"),Result);
//	MessageBox(result);
//	FreeLibrary(hModule);
//}


void CinjecterDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CinjecterDlg::OnBnClickedOpen()
{
	
  	CFileDialog filedialog(TRUE,0,0,6UL,_T("DLL Files|*.dll|"));
	if (filedialog.DoModal()==IDOK)
	{
		CString Dllpath;
		Dllpath=filedialog.GetPathName();
		SetDlgItemText(IDC_DLLPATH,Dllpath);
	}
	// TODO: 在此添加控件通知处理程序代码
}


void CinjecterDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

DWORD ProcessFind(LPCTSTR Exename)
{
	HANDLE hProcess=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,NULL);
	if(!hProcess)
	{
	  return FALSE;
	}
	PROCESSENTRY32 info;
	info.dwFlags = sizeof(PROCESSENTRY32);
	if(!Process32First(hProcess,&info))
	{
	 return FALSE;
	}
	while(true)
	{
		if (_tcscmp(info.szExeFile,Exename)==0)
		{
			return info.th32ProcessID;
		}
		if (!Process32Next(hProcess,&info))
		{
		    return FALSE;
		}
	}
	return FALSE;
}

BOOL Inject(LPCTSTR DLLPath,DWORD ProcessID)
{
	HANDLE hProcess=OpenProcess(PROCESS_ALL_ACCESS,TRUE,ProcessID);
	if (!hProcess)
	{
	 return FALSE;
	}
	SIZE_T PathSize=(_tcslen(DLLPath)+1)*sizeof(TCHAR);
	LPVOID StartAddress=VirtualAllocEx(hProcess,NULL,PathSize,MEM_COMMIT,PAGE_READWRITE);
	if(!StartAddress)
	{	
	 return FALSE;
	}
	if(!WriteProcessMemory(hProcess,StartAddress,DLLPath,PathSize,NULL))
	{
	 return FALSE;
	}
	PTHREAD_START_ROUTINE pfnStartAddress=(PTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandle(_T("kernel32.dll")), "LoadLibraryW");
	if (!pfnStartAddress)
	{
	 return FALSE;
	}
	HANDLE hThread=CreateRemoteThreadEx(hProcess,NULL,NULL,pfnStartAddress,StartAddress,NULL,NULL,NULL);
	if(!hThread)
	{
		return FALSE;
	}
	WaitForSingleObject(hThread,INFINITE);
	CloseHandle(hThread);
    CloseHandle(hProcess);
	return TRUE;
}
void CinjecterDlg::OnBnClickedInject()
{
	CString Dllpath;
	CString	Exename;
	GetDlgItemText(IDC_EXENAME, Exename);
	GetDlgItemText(IDC_DLLPATH, Dllpath);
	if(Exename.GetAllocLength()==0)
	{
	  MessageBox(_T("Please input exe name"));
	  return;
	}
	DWORD ProcessID=ProcessFind(Exename);
	if(!ProcessID)
	{
	 MessageBox(_T("Can't find the process!"));
	 return;
	}
	BOOL IsInjected=Inject(Dllpath,ProcessID);
	if(IsInjected)
	{
	 MessageBox(_T("Inject Sucess!"));
	}
	else 
	{
	 MessageBox(_T("Inject Failed!"));
	}
	// TODO: 在此添加控件通知处理程序代码
}
