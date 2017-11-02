
// OpenHoloWRPDlg.h : ��� ����
//

#pragma once

#include "cwo.h"
#include "WRP.h"
#pragma comment(lib, "cwo.lib")
// OPHWRPDlg ��ȭ ����
class OPHWRPDlg : public CDialogEx
{
// �����Դϴ�.
public:
	OPHWRPDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_OPENHOLOWRP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedImgbtn();
	CString m_editstr;
	string m_imgPath;
	OHWRP oh_wrp;

//	void DisplayImage(string filepath);
};
