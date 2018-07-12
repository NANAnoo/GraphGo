// LoginDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "interface.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "HomeDlg.h"
#include "RegistDlg.h"


// CLoginDlg �Ի���

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LOGIN_DIALOG, pParent)
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_LOGIN_BUTTON, &CLoginDlg::OnBnClickedLoginButton)
	ON_BN_CLICKED(IDC_REGIST_BUTTON, &CLoginDlg::OnBnClickedRegistButton)
END_MESSAGE_MAP()


// CLoginDlg ��Ϣ�������


void CLoginDlg::OnBnClickedLoginButton()
{
	INT_PTR nRes;
	CHomeDlg homeDlg;
	nRes = homeDlg.DoModal();// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CLoginDlg::OnBnClickedRegistButton()
{
	INT_PTR nRes;
	CRegistDlg  registDlg;
	nRes = registDlg.DoModal();// TODO: �ڴ���ӿؼ�֪ͨ����������
}
