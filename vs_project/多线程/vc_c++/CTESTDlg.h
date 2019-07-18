#pragma once

// CTESTDlg 对话框 关联的类

class CTESTDlg : public CDialog
{
	DECLARE_DYNAMIC(CTESTDlg)

public:
	CTESTDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTESTDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
};
