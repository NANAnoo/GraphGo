#pragma once


// CT 对话框

class CT : public CDialogEx
{
	DECLARE_DYNAMIC(CT)

public:
	CT(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CT();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TIP_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
