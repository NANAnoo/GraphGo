#pragma once


// CT �Ի���

class CT : public CDialogEx
{
	DECLARE_DYNAMIC(CT)

public:
	CT(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CT();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TIP_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
