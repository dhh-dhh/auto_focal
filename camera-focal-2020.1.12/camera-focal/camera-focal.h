
// camera-focal.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CcamerafocalApp: 
// �йش����ʵ�֣������ camera-focal.cpp
//

class CcamerafocalApp : public CWinApp
{
public:
	CcamerafocalApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CcamerafocalApp theApp;