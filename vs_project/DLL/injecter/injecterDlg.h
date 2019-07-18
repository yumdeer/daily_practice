
// injecterDlg.h : 头文件
//

#pragma once


// CinjecterDlg 对话框
class CinjecterDlg : public CDialogEx
{
// 构造
public:
	CinjecterDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_INJECTER_DIALOG };

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
//public:
//	afx_msg void OnBnClickedButton1();
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedOpen();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedInject();
};
