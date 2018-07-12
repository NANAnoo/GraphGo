#pragma once


// CHomeDlg 对话框

class CHomeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CHomeDlg)

public:
	CHomeDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CHomeDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HOME_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAddpictureButton();
	afx_msg void OnBnClickedShowButton();
};
