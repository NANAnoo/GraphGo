#pragma once


// CResultDlg �Ի���

class CResultDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CResultDlg)

public:
	CResultDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CResultDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RESULT_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
