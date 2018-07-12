// HomeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "interface.h"
#include "HomeDlg.h"
#include "afxdialogex.h"
#include "ResultDlg.h"


// CHomeDlg �Ի���

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


// CHomeDlg ��Ϣ�������


void CHomeDlg::OnBnClickedAddpictureButton()
{
	
		//��������Ϊ��
		//CProgressCtrl  *prgs = (CProgressCtrl *)GetDlgItem(IDC_PROGRESS);
		//prgs->SetPos(0);
		//ѡ��ͼƬ

		CFileDialog fileDlg(TRUE, _T("png"), NULL, 0, _T("image Files(*.bmp; *.jpg;*.png)|*.JPG;*.PNG;*.BMP|All Files (*.*) |*.*||"), this);
		fileDlg.DoModal();
		//��ȡͼƬ·����ͼƬ����

		CString strFilePath = fileDlg.GetPathName();
		CString strFileName = fileDlg.GetFileName();
		//�ж�·����Ϊ��
		if (strFilePath == _T(""))
		{
			return;
		}
		CImage image;
		image.Load(strFilePath);

		//��������������Ҫ�����ǣ���ȡ�Ի��������Picture Control��width��height��
		//�����õ�ͼƬ����rectPicture������ͼƬ����rectPicture��ͼƬ���д���
		//������ͼƬ���Ի�����Picture Control����
		CRect rectControl;                        //�ؼ����ζ���
		CRect rectPicture;                        //ͼƬ���ζ���


		int x = image.GetWidth();
		int y = image.GetHeight();
		//Picture Control��IDΪIDC_IMAGE
		CWnd  *pWnd = GetDlgItem(IDC_STATIC);
		pWnd->GetClientRect(rectControl);


		CDC *pDc = GetDlgItem(IDC_STATIC)->GetDC();
		SetStretchBltMode(pDc->m_hDC, STRETCH_HALFTONE);

		rectPicture = CRect(rectControl.TopLeft(), CSize((int)rectControl.Width(), (int)rectControl.Height()));

		((CStatic*)GetDlgItem(IDC_STATIC))->SetBitmap(NULL);

		//�������ַ������ɻ���ͼƬ
		//image.StretchBlt(pDc->m_hDC, rectPicture, SRCCOPY); //��ͼƬ���Ƶ�Picture�ؼ���ʾ�ľ�������
		image.Draw(pDc->m_hDC, rectPicture);                //��ͼƬ���Ƶ�Picture�ؼ���ʾ�ľ�������

		image.Destroy();
		pWnd->ReleaseDC(pDc);
	}


	// TODO: �ڴ���ӿؼ�֪ͨ����������

	// TODO: �ڴ���ӿؼ�֪ͨ����������



void CHomeDlg::OnBnClickedShowButton()
{
	INT_PTR nRes;
	CResultDlg resultDlg;
	nRes = resultDlg.DoModal();// TODO: �ڴ���ӿؼ�֪ͨ����������
}
