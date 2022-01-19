
// camera-focalDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "camera-focal.h"
#include "camera-focalDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CcamerafocalDlg 对话框



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


// CcamerafocalDlg 消息处理程序

BOOL CcamerafocalDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);


	// TODO: 在此添加额外的初始化代码
	m_comboCOM.AddString(_T("COM1")); // 为组合框控件的列表框添加列表项
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


	m_comboDirection.AddString(_T("正转"));
	m_comboDirection.AddString(_T("反转"));

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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CcamerafocalDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CcamerafocalDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcamerafocalDlg::OnCbnSelchangeCombo2()
{
	// TODO:  在此添加控件通知处理程序代码
	int nSel;
	nSel = m_comboCOM.GetCurSel();//获取组合框控件的列表框中选中项的索引
	
	m_ctrlComm.put_CommPort(nSel + 1);//选择串口号(这里因为列表框的索引号是从0开始，所以(nSel+1)对应的才是我们所选的串口号)
	m_ctrlComm.put_PortOpen(TRUE);//打开串口
	m_ctrlComm.put_RThreshold(2);//收到两个字节引发OnComm事件	
	m_ctrlComm.put_InputMode(1);//输入模式选为二进制	
	m_ctrlComm.put_Settings(_T("9600,n,8,1"));//设置串口参数，波特率，无奇偶校验，位停止位，位数据位
	m_ctrlComm.put_InputMode(1);  // 以二进制方式检取数据 
	m_ctrlComm.put_RThreshold(1); //参数1表示每当串口接收缓冲区中有多于或等于1个字符时将引发一个接收数据的OnComm事件 
	m_ctrlComm.put_InputLen(0); //设置当前接收区数据长度为0 
	m_ctrlComm.get_Input();//先预读缓冲区以清除残留数据  

	m_setOk = true;		//标记串口设置OK

}
BEGIN_EVENTSINK_MAP(CcamerafocalDlg, CDialogEx)
	ON_EVENT(CcamerafocalDlg, IDC_MSCOMM1, 1, CcamerafocalDlg::OnComm, VTS_NONE)
END_EVENTSINK_MAP()


void CcamerafocalDlg::OnComm()
{
	// TODO:  在此处添加消息处理程序代码

	VARIANT variant_inp;   //Variant 是一种特殊的数据类型，除了定长String数据及用户定义类型外，可以包含任何种类的数据。
	COleSafeArray safearray_inp;
	LONG len, k;
	BYTE rxdata[2048]; //设置BYTE数组 An 8-bit integer that is not signed.     
	CString strtemp;
	if (m_ctrlComm.get_CommEvent() == 2) //事件值为2表示接收缓冲区内有字符     
	{
		//以下你可以根据自己的通信协议加入处理代码
		variant_inp = m_ctrlComm.get_Input();		//读缓冲区  
		safearray_inp = variant_inp;				//VARIANT型变量转换为ColeSafeArray型变量
		len = safearray_inp.GetOneDimSize();		//得到有效数据长度        
		for (k = 0; k<len; k++)
			safearray_inp.GetElement(&k, rxdata + k);//转换为BYTE型数组         
		for (k = 0; k<len; k++)                    //将数组转换为Cstring型变量    
		{
			BYTE bt = *(char*)(rxdata + k);//字符型      
			strtemp.Format(_T("%c"), bt); //将字符送入临时变量strtemp存放   
			m_recieve = strtemp; //加入接收编辑框对应字符串      
		}
		
		
	}
	//UpdateData(false);
	
	

}


void CcamerafocalDlg::OnBnClickedButtonSend()
{
	// TODO:  在此添加控件通知处理程序代码

	int nSel_direction;
	nSel_direction = m_comboDirection.GetCurSel();
	int nSel_sudu;
	nSel_sudu = m_sudu.GetCurSel();
	BYTE data[8];
	int steps;
	CByteArray array;
	data[0] = 0x12;
	data[6] = 0x00;
	//方向
	if (nSel_direction == 0)
	{
		if (m_recieve == 0x01)
		{
			::MessageBox(NULL, _T("当前已经到达正限位"), _T("提示"), MB_ICONEXCLAMATION | MB_OKCANCEL);
			data[6] = 0x01;
		}
		data[1] = 0x51;
	}
	else if (nSel_direction == 1)
	{
		if (m_recieve == 0x03)
		{
			::MessageBox(NULL, _T("当前已经到达反限位"), _T("提示"), MB_ICONEXCLAMATION | MB_OKCANCEL);
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
	//速度
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
	

	if (m_setOk == true)	//判断是否打开并初始化串口
	{
		//UpdateData(TRUE);  //读取编辑框内容
		m_ctrlComm.put_Output(COleVariant(array));//发送数据
	}
	else
	{
		MessageBox(_T("请先选择COM口"));
	}

}


void CcamerafocalDlg::OnCbnSelchangeCombo1()
{
	// TODO:  在此添加控件通知处理程序代码
	


}

BOOL CcamerafocalDlg::PreTranslateMessage(MSG* pMsg)
{
	int nSel_direction;
	nSel_direction = m_comboDirection.GetCurSel();
	int nSel_sudu;
	nSel_sudu = m_sudu.GetCurSel();
	BYTE data[8];
	CByteArray array;
	if (pMsg->message == WM_LBUTTONDOWN && pMsg->hwnd == GetDlgItem(IDC_BUTTON3)->m_hWnd)//拦截鼠标左键按下消息 判断按下的位置是否为目标button
	{
		
		data[0] = 0x12;
		//方向
		data[6] = 0x00;
		if (nSel_direction == 0)
		{
			if (m_recieve == 0x01)
			{
				::MessageBox(NULL, _T("当前已经到达正限位"), _T("提示"), MB_ICONEXCLAMATION | MB_OKCANCEL);
				
			}
			data[1] = 0x51;
		}
		else if (nSel_direction == 1)
		{
			if (m_recieve == 0x03)
			{
				::MessageBox(NULL, _T("当前已经到达反限位"), _T("提示"), MB_ICONEXCLAMATION | MB_OKCANCEL);
				
			}
			data[1] = 0x50;
		}

		data[2] = 0xFF;
		data[3] = 0xFF;
		data[4] = 0xFF;
		data[5] = 0xFF;

		//速度
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

		if (m_setOk == true)	//判断是否打开并初始化串口
		{
			//UpdateData(TRUE);  //读取编辑框内容
			//m_ctrlComm.put_Output(COleVariant(m_strRXData)); 
			m_ctrlComm.put_Output(COleVariant(array));//发送数据
			return true;
		}
		
		
	}
	else if (pMsg->message == WM_LBUTTONUP && pMsg->hwnd == GetDlgItem(IDC_BUTTON3)->m_hWnd)
	{
		data[0] = 0x12;
		//方向
		data[6] = 0x01;
		

		data[2] = 0x00;
		data[3] = 0x00;
		data[4] = 0x00;
		data[5] = 0x00;

		//方向 速度 松手停止，对速度没有要求 
		data[7] = 0x01;
		data[1] = 0x50;
		array.SetSize(8);
		for (UINT k = 0; k<8; k++)
			array.SetAt(k, data[k]);
		if (m_setOk == true)	//判断是否打开并初始化串口
		{
			//UpdateData(TRUE);  //读取编辑框内容
			//m_ctrlComm.put_Output(COleVariant(m_strRXData)); 
			
			array.SetSize(8);
			for (UINT k = 0; k<8; k++)
				array.SetAt(k, data[k]);
			m_ctrlComm.put_Output(COleVariant(array));//发送数据
			return true;
		}	
	}

	return CDialog::PreTranslateMessage(pMsg); //一定要有，其他消息系统默认处理

}


void CcamerafocalDlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	int nSel_direction;
	nSel_direction = m_comboDirection.GetCurSel();
	int nSel_sudu;
	nSel_sudu = m_sudu.GetCurSel();
	BYTE data[8];
	int steps;
	CByteArray array;
	data[0] = 0x12;
	data[6] = 0x01;
	//方向
	if (nSel_direction == 0)
	{
		if (m_recieve == 0x01)
		{
			::MessageBox(NULL, _T("当前已经到达正限位"), _T("提示"), MB_ICONEXCLAMATION | MB_OKCANCEL);
			data[6] = 0x01;
		}
		data[1] = 0x51;
	}
	else if (nSel_direction == 1)
	{
		if (m_recieve == 0x03)
		{
			::MessageBox(NULL, _T("当前已经到达反限位"), _T("提示"), MB_ICONEXCLAMATION | MB_OKCANCEL);
			data[6] = 0x01;
		}
		data[1] = 0x50;
	}
	data[2] = 0x00;
	data[3] = 0x00;
	data[4] = 0x00;
	data[5] = 0x00;

	
	//速度
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


	if (m_setOk == true)	//判断是否打开并初始化串口
	{
		//UpdateData(TRUE);  //读取编辑框内容
		//m_ctrlComm.put_Output(COleVariant(m_strRXData)); 
		m_ctrlComm.put_Output(COleVariant(array));//发送数据
	}
	else
	{
		MessageBox(_T("请先选择COM口"));
	}

}
