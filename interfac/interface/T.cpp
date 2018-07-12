// T.cpp : 实现文件
//

#include "stdafx.h"
#include "interface.h"
#include "T.h"
#include "afxdialogex.h"


// CT 对话框

IMPLEMENT_DYNAMIC(CT, CDialogEx)

CT::CT(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TIP_DIALOG, pParent)
{

}

CT::~CT()
{
}

void CT::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CT, CDialogEx)
END_MESSAGE_MAP()


// CT 消息处理程序
