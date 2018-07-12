// RegistDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "interface.h"
#include "RegistDlg.h"
#include "afxdialogex.h"


// CRegistDlg �Ի���

IMPLEMENT_DYNAMIC(CRegistDlg, CDialogEx)

CRegistDlg::CRegistDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_REGISTER_DIALOG, pParent)
	, m_username(_T(""))
	, m_password(_T(""))
{

}

CRegistDlg::~CRegistDlg()
{
}

void CRegistDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_USERNAME_EDIT, m_username);
	DDX_Text(pDX, IDC_PASSWORD_EDIT, m_password);
}


BEGIN_MESSAGE_MAP(CRegistDlg, CDialogEx)
	ON_BN_CLICKED(IDC_REGISTER_BUTTON, &CRegistDlg::OnBnClickedRegisterButton)
END_MESSAGE_MAP()


// CRegistDlg ��Ϣ�������


void CRegistDlg::OnBnClickedRegisterButton()
{
	UpdateData(TRUE);
	INT_PTR nRes;
	if (m_username != "" && m_password!=""){
		// ��ʾ��Ϣ�Ի���   
		nRes = MessageBox(_T("ע��ɹ�"), _T("��ʾ"), MB_OKCANCEL | MB_ICONINFORMATION);// TODO: �ڴ���ӿؼ�֪ͨ����������
	}
	if (m_username==""|| m_password==""){
	nRes = MessageBox(_T("ע��ʧ��"), _T("��ʾ"), MB_OKCANCEL | MB_ICONWARNING);
 }
}
