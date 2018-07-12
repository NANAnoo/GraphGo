#pragma once


// CRegistDlg 对话框

class CRegistDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CRegistDlg)

public:
	CRegistDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRegistDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_REGISTER_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRegisterButton();
	CString m_username;
	CString m_password;
};
