
// OpenHoloWRP.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// OPHWRPApp:
// �� Ŭ������ ������ ���ؼ��� OpenHoloWRP.cpp�� �����Ͻʽÿ�.
//

class OPHWRPApp : public CWinApp
{
public:
	OPHWRPApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern OPHWRPApp theApp;