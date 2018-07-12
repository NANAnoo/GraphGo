// ResultDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "interface.h"
#include "ResultDlg.h"
#include "afxdialogex.h"


// CResultDlg 对话框

IMPLEMENT_DYNAMIC(CResultDlg, CDialogEx)

CResultDlg::CResultDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_RESULT_DIALOG, pParent)
{

}

CResultDlg::~CResultDlg()
{
}

void CResultDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CResultDlg, CDialogEx)
END_MESSAGE_MAP()


// CResultDlg 消息处理程序
