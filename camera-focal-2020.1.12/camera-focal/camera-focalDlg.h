
// camera-focalDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "mscomm1.h"


// CcamerafocalDlg �Ի���
class CcamerafocalDlg : public CDialogEx
{
// ����
public:
	CcamerafocalDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CAMERAFOCAL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_comboCOM;
	CComboBox m_comboDirection;
	afx_msg void OnCbnSelchangeCombo2();
	CMscomm1 m_ctrlComm;
private:
	bool m_setOk;
public:
//	CString m_strRXData;
	DECLARE_EVENTSINK_MAP()
	void OnComm();
	afx_msg void OnBnClickedButtonSend();
	afx_msg void OnCbnSelchangeCombo1();
	BOOL PreTranslateMessage(MSG* pMsg);
	int m_strRXData;
	
	CComboBox m_sudu;
//	CButton IDC_BUTTON_2;
	CButton idc_button3;
	afx_msg void OnBnClickedButton2();

	CString m_recieve;
	
};
