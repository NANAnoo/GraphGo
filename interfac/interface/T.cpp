// T.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "interface.h"
#include "T.h"
#include "afxdialogex.h"


// CT �Ի���

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


// CT ��Ϣ�������
