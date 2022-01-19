
// camera-focalDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "camera-focal.h"
#include "camera-focalDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcamerafocalDlg �Ի���



CcamerafocalDlg::CcamerafocalDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CcamerafocalDlg::IDD, pParent)
	, m_setOk(false)
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcamerafocalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO2, m_comboCOM);
	DDX_Control(pDX, IDC_COMBO1, m_comboDirection);
	DDX_Control(pDX, IDC_MSCOMM1, m_ctrlComm);
	//  DDX_Text(pDX, IDC_EDIT1, m_strRXData);
	DDX_Text(pDX, IDC_EDIT1, m_strRXData);
	DDX_Control(pDX, IDC_COMBO3, m_sudu);
	//DDX_Control(pDX, IDC_BUTTON3, IDC_BUTTON_3);
	DDX_Control(pDX, IDC_BUTTON3, idc_button3);
}

BEGIN_MESSAGE_MAP(CcamerafocalDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO2, &CcamerafocalDlg::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_BUTTON1, &CcamerafocalDlg::OnBnClickedButtonSend)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CcamerafocalDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON2, &CcamerafocalDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CcamerafocalDlg ��Ϣ�������

BOOL CcamerafocalDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);


	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_comboCOM.AddString(_T("COM1")); // Ϊ��Ͽ�ؼ����б������б���
	m_comboCOM.AddString(_T("COM2"));
	m_comboCOM.AddString(_T("COM3"));
	m_comboCOM.AddString(_T("COM4"));
	m_comboCOM.AddString(_T("COM5"));
	m_comboCOM.AddString(_T("COM6"));
	m_comboCOM.AddString(_T("COM7"));
	m_comboCOM.AddString(_T("COM8"));
	m_comboCOM.AddString(_T("COM9"));
	m_comboCOM.AddString(_T("COM10"));
	m_sudu.AddString(_T("01"));
	m_sudu.AddString(_T("02"));
	m_sudu.AddString(_T("03"));
	m_sudu.AddString(_T("04"));


	m_comboDirection.AddString(_T("��ת"));
	m_comboDirection.AddString(_T("��ת"));

	m_comboCOM.SetCurSel(0);
	m_sudu.SetCurSel(0);
	m_comboDirection.SetCurSel(0);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CcamerafocalDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CcamerafocalDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CcamerafocalDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcamerafocalDlg::OnCbnSelchangeCombo2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	int nSel;
	nSel = m_comboCOM.GetCurSel();//��ȡ��Ͽ�ؼ����б����ѡ���������
	
	m_ctrlComm.put_CommPort(nSel + 1);//ѡ�񴮿ں�(������Ϊ�б����������Ǵ�0��ʼ������(nSel+1)��Ӧ�Ĳ���������ѡ�Ĵ��ں�)
	m_ctrlComm.put_PortOpen(TRUE);//�򿪴���
	m_ctrlComm.put_RThreshold(2);//�յ������ֽ�����OnComm�¼�	
	m_ctrlComm.put_InputMode(1);//����ģʽѡΪ������	
	m_ctrlComm.put_Settings(_T("9600,n,8,1"));//���ô��ڲ����������ʣ�����żУ�飬λֹͣλ��λ����λ
	m_ctrlComm.put_InputMode(1);  // �Զ����Ʒ�ʽ��ȡ���� 
	m_ctrlComm.put_RThreshold(1); //����1��ʾÿ�����ڽ��ջ��������ж��ڻ����1���ַ�ʱ������һ���������ݵ�OnComm�¼� 
	m_ctrlComm.put_InputLen(0); //���õ�ǰ���������ݳ���Ϊ0 
	m_ctrlComm.get_Input();//��Ԥ���������������������  

	m_setOk = true;		//��Ǵ�������OK

}
BEGIN_EVENTSINK_MAP(CcamerafocalDlg, CDialogEx)
	ON_EVENT(CcamerafocalDlg, IDC_MSCOMM1, 1, CcamerafocalDlg::OnComm, VTS_NONE)
END_EVENTSINK_MAP()


void CcamerafocalDlg::OnComm()
{
	// TODO:  �ڴ˴������Ϣ����������

	VARIANT variant_inp;   //Variant ��һ��������������ͣ����˶���String���ݼ��û����������⣬���԰����κ���������ݡ�
	COleSafeArray safearray_inp;
	LONG len, k;
	BYTE rxdata[2048]; //����BYTE���� An 8-bit integer that is not signed.     
	CString strtemp;
	if (m_ctrlComm.get_CommEvent() == 2) //�¼�ֵΪ2��ʾ���ջ����������ַ�     
	{
		//��������Ը����Լ���ͨ��Э����봦�����
		variant_inp = m_ctrlComm.get_Input();		//��������  
		safearray_inp = variant_inp;				//VARIANT�ͱ���ת��ΪColeSafeArray�ͱ���
		len = safearray_inp.GetOneDimSize();		//�õ���Ч���ݳ���        
		for (k = 0; k<len; k++)
			safearray_inp.GetElement(&k, rxdata + k);//ת��ΪBYTE������         
		for (k = 0; k<len; k++)                    //������ת��ΪCstring�ͱ���    
		{
			BYTE bt = *(char*)(rxdata + k);//�ַ���      
			strtemp.Format(_T("%c"), bt); //���ַ�������ʱ����strtemp���   
			m_recieve = strtemp; //������ձ༭���Ӧ�ַ���      
		}
		
		
	}
	//UpdateData(false);
	
	

}


void CcamerafocalDlg::OnBnClickedButtonSend()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	int nSel_direction;
	nSel_direction = m_comboDirection.GetCurSel();
	int nSel_sudu;
	nSel_sudu = m_sudu.GetCurSel();
	BYTE data[8];
	int steps;
	CByteArray array;
	data[0] = 0x12;
	data[6] = 0x00;
	//����
	if (nSel_direction == 0)
	{
		if (m_recieve == 0x01)
		{
			::MessageBox(NULL, _T("��ǰ�Ѿ���������λ"), _T("��ʾ"), MB_ICONEXCLAMATION | MB_OKCANCEL);
			data[6] = 0x01;
		}
		data[1] = 0x51;
	}
	else if (nSel_direction == 1)
	{
		if (m_recieve == 0x03)
		{
			::MessageBox(NULL, _T("��ǰ�Ѿ����ﷴ��λ"), _T("��ʾ"), MB_ICONEXCLAMATION | MB_OKCANCEL);
			data[6] = 0x01;
		}
		data[1] = 0x50;
	}

	steps = GetDlgItemInt(IDC_EDIT1);
	if (steps<65536)
	{
		data[2] = 0x00;
		data[3] = 0x00;
		data[4] = HIBYTE(steps);
		data[5] = LOBYTE(steps);

	}
	else
	{
		int s = steps / 65535;
		UINT t = steps - (s * 65536);
		data[2] = 0x00;
		data[3] = LOBYTE(s);
		data[4] = HIBYTE(t);
		data[5] = LOBYTE(t);
	}
	//
	//�ٶ�
	if (nSel_sudu == 0)
	{
		data[7] = 0x01;
	}
	else if (nSel_sudu == 1)
	{
		data[7] = 0x02;
	}
	else if (nSel_sudu == 2)
	{
		data[7] = 0x03;
	}
	else if (nSel_sudu == 3)
	{
		data[7] = 0x04;
	}
	array.SetSize(8);
	for (UINT k = 0; k<8; k++)
		array.SetAt(k, data[k]);
	

	if (m_setOk == true)	//�ж��Ƿ�򿪲���ʼ������
	{
		//UpdateData(TRUE);  //��ȡ�༭������
		m_ctrlComm.put_Output(COleVariant(array));//��������
	}
	else
	{
		MessageBox(_T("����ѡ��COM��"));
	}

}


void CcamerafocalDlg::OnCbnSelchangeCombo1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	


}

BOOL CcamerafocalDlg::PreTranslateMessage(MSG* pMsg)
{
	int nSel_direction;
	nSel_direction = m_comboDirection.GetCurSel();
	int nSel_sudu;
	nSel_sudu = m_sudu.GetCurSel();
	BYTE data[8];
	CByteArray array;
	if (pMsg->message == WM_LBUTTONDOWN && pMsg->hwnd == GetDlgItem(IDC_BUTTON3)->m_hWnd)//����������������Ϣ �жϰ��µ�λ���Ƿ�ΪĿ��button
	{
		
		data[0] = 0x12;
		//����
		data[6] = 0x00;
		if (nSel_direction == 0)
		{
			if (m_recieve == 0x01)
			{
				::MessageBox(NULL, _T("��ǰ�Ѿ���������λ"), _T("��ʾ"), MB_ICONEXCLAMATION | MB_OKCANCEL);
				
			}
			data[1] = 0x51;
		}
		else if (nSel_direction == 1)
		{
			if (m_recieve == 0x03)
			{
				::MessageBox(NULL, _T("��ǰ�Ѿ����ﷴ��λ"), _T("��ʾ"), MB_ICONEXCLAMATION | MB_OKCANCEL);
				
			}
			data[1] = 0x50;
		}

		data[2] = 0xFF;
		data[3] = 0xFF;
		data[4] = 0xFF;
		data[5] = 0xFF;

		//�ٶ�
		if (nSel_sudu == 0)
		{
			data[7] = 0x01;
		}
		else if (nSel_sudu == 1)
		{
			data[7] = 0x02;
		}
		else if (nSel_sudu == 2)
		{
			data[7] = 0x03;
		}
		else if (nSel_sudu == 3)
		{
			data[7] = 0x04;
		}
		array.SetSize(8);
		for (UINT k = 0; k<8; k++)
			array.SetAt(k, data[k]);

		if (m_setOk == true)	//�ж��Ƿ�򿪲���ʼ������
		{
			//UpdateData(TRUE);  //��ȡ�༭������
			//m_ctrlComm.put_Output(COleVariant(m_strRXData)); 
			m_ctrlComm.put_Output(COleVariant(array));//��������
			return true;
		}
		
		
	}
	else if (pMsg->message == WM_LBUTTONUP && pMsg->hwnd == GetDlgItem(IDC_BUTTON3)->m_hWnd)
	{
		data[0] = 0x12;
		//����
		data[6] = 0x01;
		

		data[2] = 0x00;
		data[3] = 0x00;
		data[4] = 0x00;
		data[5] = 0x00;

		//���� �ٶ� ����ֹͣ�����ٶ�û��Ҫ�� 
		data[7] = 0x01;
		data[1] = 0x50;
		array.SetSize(8);
		for (UINT k = 0; k<8; k++)
			array.SetAt(k, data[k]);
		if (m_setOk == true)	//�ж��Ƿ�򿪲���ʼ������
		{
			//UpdateData(TRUE);  //��ȡ�༭������
			//m_ctrlComm.put_Output(COleVariant(m_strRXData)); 
			
			array.SetSize(8);
			for (UINT k = 0; k<8; k++)
				array.SetAt(k, data[k]);
			m_ctrlComm.put_Output(COleVariant(array));//��������
			return true;
		}	
	}

	return CDialog::PreTranslateMessage(pMsg); //һ��Ҫ�У�������ϢϵͳĬ�ϴ���

}


void CcamerafocalDlg::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	int nSel_direction;
	nSel_direction = m_comboDirection.GetCurSel();
	int nSel_sudu;
	nSel_sudu = m_sudu.GetCurSel();
	BYTE data[8];
	int steps;
	CByteArray array;
	data[0] = 0x12;
	data[6] = 0x01;
	//����
	if (nSel_direction == 0)
	{
		if (m_recieve == 0x01)
		{
			::MessageBox(NULL, _T("��ǰ�Ѿ���������λ"), _T("��ʾ"), MB_ICONEXCLAMATION | MB_OKCANCEL);
			data[6] = 0x01;
		}
		data[1] = 0x51;
	}
	else if (nSel_direction == 1)
	{
		if (m_recieve == 0x03)
		{
			::MessageBox(NULL, _T("��ǰ�Ѿ����ﷴ��λ"), _T("��ʾ"), MB_ICONEXCLAMATION | MB_OKCANCEL);
			data[6] = 0x01;
		}
		data[1] = 0x50;
	}
	data[2] = 0x00;
	data[3] = 0x00;
	data[4] = 0x00;
	data[5] = 0x00;

	
	//�ٶ�
	if (nSel_sudu == 0)
	{
		data[7] = 0x01;
	}
	else if (nSel_sudu == 1)
	{
		data[7] = 0x02;
	}
	else if (nSel_sudu == 2)
	{
		data[7] = 0x03;
	}
	else if (nSel_sudu == 3)
	{
		data[7] = 0x04;
	}
	array.SetSize(8);
	for (UINT k = 0; k<8; k++)
		array.SetAt(k, data[k]);


	if (m_setOk == true)	//�ж��Ƿ�򿪲���ʼ������
	{
		//UpdateData(TRUE);  //��ȡ�༭������
		//m_ctrlComm.put_Output(COleVariant(m_strRXData)); 
		m_ctrlComm.put_Output(COleVariant(array));//��������
	}
	else
	{
		MessageBox(_T("����ѡ��COM��"));
	}

}
