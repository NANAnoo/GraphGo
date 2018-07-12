#pragma once


// CResultDlg 对话框

class CResultDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CResultDlg)

public:
	CResultDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CResultDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RESULT_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
