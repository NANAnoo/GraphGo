
// interface.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CinterfaceApp: 
// �йش����ʵ�֣������ interface.cpp
//

class CinterfaceApp : public CWinApp
{
public:
	CinterfaceApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CinterfaceApp theApp;
