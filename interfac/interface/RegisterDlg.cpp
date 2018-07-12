// RegisterDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "interface.h"
#include "RegisterDlg.h"
#include "afxdialogex.h"


// CRegisterDlg 对话框

IMPLEMENT_DYNAMIC(CRegisterDlg, CDialogEx)

CRegisterDlg::CRegisterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_REGISTER_DIALOG, pParent)
{

}

CRegisterDlg::~CRegisterDlg()
{
}

void CRegisterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRegisterDlg, CDialogEx)
	ON_BN_CLICKED(IDC_REGIST_BUTTON, &CRegisterDlg::OnBnClickedRegistButton)
END_MESSAGE_MAP()


// CRegisterDlg 消息处理程序


