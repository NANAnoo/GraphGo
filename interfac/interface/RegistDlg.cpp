// RegistDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "interface.h"
#include "RegistDlg.h"
#include "afxdialogex.h"


// CRegistDlg 对话框

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


// CRegistDlg 消息处理程序


void CRegistDlg::OnBnClickedRegisterButton()
{
	UpdateData(TRUE);
	INT_PTR nRes;
	if (m_username != "" && m_password!=""){
		// 显示消息对话框   
		nRes = MessageBox(_T("注册成功"), _T("提示"), MB_OKCANCEL | MB_ICONINFORMATION);// TODO: 在此添加控件通知处理程序代码
	}
	if (m_username==""|| m_password==""){
	nRes = MessageBox(_T("注册失败"), _T("提示"), MB_OKCANCEL | MB_ICONWARNING);
 }
}
