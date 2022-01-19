
// camera-focalDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "mscomm1.h"


// CcamerafocalDlg 对话框
class CcamerafocalDlg : public CDialogEx
{
// 构造
public:
	CcamerafocalDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CAMERAFOCAL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
