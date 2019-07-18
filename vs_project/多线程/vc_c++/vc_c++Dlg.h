
// vc_c++Dlg.h: 头文件
//

#pragma once
#include "CTESTDlg.h"

// CvccDlg 对话框
class CvccDlg : public CDialogEx
{
// 构造
public:
	CvccDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VC_C_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtn();

	//VC驿站 第二课
	//类成员函数作为线程函数：https://www.cctry.com/thread-19591-1-1.html
	int m_Num;
	static UINT _cdecl ThreadProc(LPVOID lpParameter);
<<<<<<< HEAD
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedSuspendBtn();
	afx_msg void OnBnClickedResumeBtn();
	afx_msg void OnBnClickedExitcodeBtn();
=======
>>>>>>> temp
};
