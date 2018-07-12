// HomeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "interface.h"
#include "HomeDlg.h"
#include "afxdialogex.h"
#include "ResultDlg.h"


// CHomeDlg 对话框

IMPLEMENT_DYNAMIC(CHomeDlg, CDialogEx)

CHomeDlg::CHomeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_HOME_DIALOG, pParent)
{

}

CHomeDlg::~CHomeDlg()
{
}

void CHomeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CHomeDlg, CDialogEx)
	ON_BN_CLICKED(IDC_ADDPICTURE_BUTTON, &CHomeDlg::OnBnClickedAddpictureButton)
	ON_BN_CLICKED(IDC_SHOW_BUTTON, &CHomeDlg::OnBnClickedShowButton)
END_MESSAGE_MAP()


// CHomeDlg 消息处理程序


void CHomeDlg::OnBnClickedAddpictureButton()
{
	
		//进度条置为零
		//CProgressCtrl  *prgs = (CProgressCtrl *)GetDlgItem(IDC_PROGRESS);
		//prgs->SetPos(0);
		//选择图片

		CFileDialog fileDlg(TRUE, _T("png"), NULL, 0, _T("image Files(*.bmp; *.jpg;*.png)|*.JPG;*.PNG;*.BMP|All Files (*.*) |*.*||"), this);
		fileDlg.DoModal();
		//获取图片路径和图片名称

		CString strFilePath = fileDlg.GetPathName();
		CString strFileName = fileDlg.GetFileName();
		//判断路径不为空
		if (strFilePath == _T(""))
		{
			return;
		}
		CImage image;
		image.Load(strFilePath);

		//以下两个矩形主要作用是，获取对话框上面的Picture Control的width和height，
		//并设置到图片矩形rectPicture，根据图片矩形rectPicture对图片进行处理，
		//最后绘制图片到对话框上Picture Control上面
		CRect rectControl;                        //控件矩形对象
		CRect rectPicture;                        //图片矩形对象


		int x = image.GetWidth();
		int y = image.GetHeight();
		//Picture Control的ID为IDC_IMAGE
		CWnd  *pWnd = GetDlgItem(IDC_STATIC);
		pWnd->GetClientRect(rectControl);


		CDC *pDc = GetDlgItem(IDC_STATIC)->GetDC();
		SetStretchBltMode(pDc->m_hDC, STRETCH_HALFTONE);

		rectPicture = CRect(rectControl.TopLeft(), CSize((int)rectControl.Width(), (int)rectControl.Height()));

		((CStatic*)GetDlgItem(IDC_STATIC))->SetBitmap(NULL);

		//以下两种方法都可绘制图片
		//image.StretchBlt(pDc->m_hDC, rectPicture, SRCCOPY); //将图片绘制到Picture控件表示的矩形区域
		image.Draw(pDc->m_hDC, rectPicture);                //将图片绘制到Picture控件表示的矩形区域

		image.Destroy();
		pWnd->ReleaseDC(pDc);
	}


	// TODO: 在此添加控件通知处理程序代码

	// TODO: 在此添加控件通知处理程序代码



void CHomeDlg::OnBnClickedShowButton()
{
	INT_PTR nRes;
	CResultDlg resultDlg;
	nRes = resultDlg.DoModal();// TODO: 在此添加控件通知处理程序代码
}
