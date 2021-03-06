
// MycalculatorDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "Mycalculator.h"
#include "MycalculatorDlg.h"
#include "afxdialogex.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define m_PI 3.14159265358979323846


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMycalculatorDlg 对话框



CMycalculatorDlg::CMycalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MYCALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_angleType = 0;
	m_first = 0.0;
	m_second = 0.0;
	m_operator = _T("+");
	m_coff = 1.0;
	m_display = _T("0");

}

void CMycalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DISPLAY, m_display);	//绑定编辑框和结果变量，DDX机制
}

BEGIN_MESSAGE_MAP(CMycalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_JIAODU, &CMycalculatorDlg::OnBnClickedJiaodu)
	ON_BN_CLICKED(IDC_HUDU, &CMycalculatorDlg::OnBnClickedHudu)
	ON_BN_CLICKED(IDC_BUTTON1, &CMycalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMycalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CMycalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMycalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMycalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMycalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMycalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON0, &CMycalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_SIGN, &CMycalculatorDlg::OnBnClickedButtonSign)
	ON_BN_CLICKED(IDC_BUTTON_POINT, &CMycalculatorDlg::OnBnClickedButtonPoint)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CMycalculatorDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON2, &CMycalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CMycalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CMycalculatorDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_MUTIPLY, &CMycalculatorDlg::OnBnClickedButtonMutiply)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &CMycalculatorDlg::OnBnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CMycalculatorDlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_EQUAL, &CMycalculatorDlg::OnBnClickedButtonEqual)
	ON_BN_CLICKED(IDC_BUTTON_SQRT, &CMycalculatorDlg::OnBnClickedButtonSqrt)
	ON_BN_CLICKED(IDC_BUTTON_RECI, &CMycalculatorDlg::OnBnClickedButtonReci)
	ON_BN_CLICKED(IDC_BUTTON_EXP, &CMycalculatorDlg::OnBnClickedButtonExp)
	ON_BN_CLICKED(IDC_BUTTON_10X, &CMycalculatorDlg::OnBnClickedButton10x)
	ON_BN_CLICKED(IDC_BUTTON_SIN, &CMycalculatorDlg::OnBnClickedButtonSin)
	ON_BN_CLICKED(IDC_BUTTON_COS, &CMycalculatorDlg::OnBnClickedButtonCos)
	ON_BN_CLICKED(IDC_BUTTON_TAN, &CMycalculatorDlg::OnBnClickedButtonTan)
	ON_BN_CLICKED(IDC_BUTTON_ARCTAN, &CMycalculatorDlg::OnBnClickedButtonArctan)
	ON_BN_CLICKED(IDC_BUTTON_ARCSIN, &CMycalculatorDlg::OnBnClickedButtonArcsin)
	ON_BN_CLICKED(IDC_BUTTON_ARCCOS, &CMycalculatorDlg::OnBnClickedButtonArccos)
	ON_BN_CLICKED(IDC_BUTTON_LN, &CMycalculatorDlg::OnBnClickedButtonLn)
	ON_BN_CLICKED(IDC_BUTTON_LOG, &CMycalculatorDlg::OnBnClickedButtonLog)
	ON_BN_CLICKED(IDC_BUTTON_NJC, &CMycalculatorDlg::OnBnClickedButtonNjc)
	ON_BN_CLICKED(IDC_BUTTON_XDEY, &CMycalculatorDlg::OnBnClickedButtonXdey)
END_MESSAGE_MAP()


// CMycalculatorDlg 消息处理程序

BOOL CMycalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMycalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMycalculatorDlg::OnPaint()
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
HCURSOR CMycalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMycalculatorDlg::OnBnClickedJiaodu()
{
	// TODO: 在此添加控件通知处理程序代码
	m_angleType = 1;
}


void CMycalculatorDlg::OnBnClickedHudu()
{
	// TODO: 在此添加控件通知处理程序代码
	m_angleType = 0;
}

void CMycalculatorDlg::UpdateDisplay(double dck)
{
	m_display.Format(_T("%lf"), dck);
	int i = m_display.GetLength();
	while (m_display.GetAt(i - 1) == '0')
	{
		m_display.Delete(i - 1, 1);
		i--;
	}
	if(m_display.GetAt(i - 1) == '.')
	{
		m_display.Delete(i - 1, 1);
	}
	UpdateData(false);
}

void CMycalculatorDlg::Calculate(void)
{
	switch (m_operator.GetAt(0))
	{
	case '+':m_first += m_second; break;
	case '-':m_first -= m_second; break;
	case '*':m_first *= m_second; break;
	case '/':
	
		if (fabs(m_second <= 0.000001))
		{
			m_display = "除数不能等于0";
			UpdateData(false);
			return;
		}
		m_first /= m_second; break;
	}
	m_second = 0.0;
	m_coff = 1.0;
	m_operator = _T("+");
	UpdateDisplay(m_first);
}

void CMycalculatorDlg::onButton(int n)
{
	if (m_coff == 1.0)
		m_second = m_second * 10 + n;
	else
	{
		m_second = m_second + n * m_coff;
		m_coff *= 0.1;
	}
	UpdateDisplay(m_second);
}

void CMycalculatorDlg::OnBnClickedButton1()
{
	onButton(1);
}


void CMycalculatorDlg::OnBnClickedButton2()
{
	onButton(2);
}


void CMycalculatorDlg::OnBnClickedButton3()
{
	onButton(3);
}


void CMycalculatorDlg::OnBnClickedButton4()
{
	onButton(4);
}

void CMycalculatorDlg::OnBnClickedButton5()
{
	onButton(5);
}


void CMycalculatorDlg::OnBnClickedButton6()
{
	onButton(6);
}


void CMycalculatorDlg::OnBnClickedButton7()
{
	onButton(7);
}


void CMycalculatorDlg::OnBnClickedButton8()
{
	onButton(8);
}


void CMycalculatorDlg::OnBnClickedButton9()
{
	onButton(9);
}


void CMycalculatorDlg::OnBnClickedButton0()
{
	onButton(0);
}


void CMycalculatorDlg::OnBnClickedButtonSign()
{
	m_second = -m_second;
	UpdateDisplay(m_second);
}


void CMycalculatorDlg::OnBnClickedButtonPoint()
{
	m_coff = 0.1;
}


void CMycalculatorDlg::OnBnClickedButtonAdd()
{
	Calculate();
	m_operator = '+';
}


void CMycalculatorDlg::OnBnClickedButtonMinus()
{
	Calculate();
	m_operator = '-';
}


void CMycalculatorDlg::OnBnClickedButtonMutiply()
{
	Calculate();
	m_operator = '*';
}


void CMycalculatorDlg::OnBnClickedButtonDiv()
{
	Calculate();
	m_operator = '/';
}


void CMycalculatorDlg::OnBnClickedButtonClear()
{
	m_first = 0.0;
	m_second = 0.0;
	m_operator = "+";
	m_coff = 1.0;
	m_display = _T("0");
	UpdateDisplay(0);
}


void CMycalculatorDlg::OnBnClickedButtonEqual()
{
	xdey();
	Calculate();
}


void CMycalculatorDlg::OnBnClickedButtonSqrt()
{
	if (m_second == 0)
	{
		m_first = sqrt(m_first);
		UpdateDisplay(m_first);
	}
	else
	{
		m_second = sqrt(m_second);
		UpdateDisplay(m_second);
	}
}


void CMycalculatorDlg::OnBnClickedButtonReci()
{
	if (fabs(m_first) <= 0.000001 && fabs(m_second) <= 0.000001)
	{
		m_display = "除数不能等于0";
		UpdateData(false);
		return;
	}
	if (fabs(m_second) <= 0.000001)
	{
		m_first = 1.0 / m_first;
		UpdateDisplay(m_first);
	}
	else
	{
		m_second = 1.0 / m_second;
		UpdateDisplay(m_second);
	}
}


void CMycalculatorDlg::OnBnClickedButtonExp()
{
	m_second = exp(m_second);
	UpdateDisplay(m_second);
}


void CMycalculatorDlg::OnBnClickedButton10x()
{
	m_second = pow(10, m_second);
	UpdateDisplay(m_second);

}


void CMycalculatorDlg::sanjiaohanshu(void)
{
	switch (m_angleType)
	{
	case 0: break;
	case 1: m_second = m_second * m_PI / 180; break;
	}
}


void CMycalculatorDlg::OnBnClickedButtonSin()
{
	sanjiaohanshu();
	m_second =sin(m_second);
	UpdateDisplay(m_second);
}


void CMycalculatorDlg::OnBnClickedButtonCos()
{
	sanjiaohanshu();
	m_second = cos(m_second);
	UpdateDisplay(m_second);
}


void CMycalculatorDlg::OnBnClickedButtonTan()
{
	sanjiaohanshu();
	m_second = tan(m_second);
	UpdateDisplay(m_second);
}


void CMycalculatorDlg::OnBnClickedButtonArctan()
{
	sanjiaohanshu();
	m_second = atan(m_second);
	UpdateDisplay(m_second);
}


void CMycalculatorDlg::OnBnClickedButtonArcsin()
{
	sanjiaohanshu();
	m_second = asin(m_second);
	UpdateDisplay(m_second);
}


void CMycalculatorDlg::OnBnClickedButtonArccos()
{
	sanjiaohanshu();
	m_second = acos(m_second);
	UpdateDisplay(m_second);
}


void CMycalculatorDlg::OnBnClickedButtonLn()
{
	m_second = log(m_second);
	UpdateDisplay(m_second);
}


void CMycalculatorDlg::OnBnClickedButtonLog()
{
	m_second = log10(m_second);
	UpdateDisplay(m_second);
}


void CMycalculatorDlg::OnBnClickedButtonNjc()
{
	if (m_second - (int)m_second > 0)
	{
		m_display = _T("请输入整数");
		UpdateData(false);
		return;
	}
	else if (m_second > 170)
	{
		m_display = _T("我看你就是刁难我胖虎");
		UpdateData(false);
		return;
	}
	else
	{
		m_second = (double)jiecheng(m_second);
		UpdateDisplay(m_second);
	}
}

double CMycalculatorDlg::jiecheng(int n)
{
	int i = 1; double s = 1;
	for (i = 1; i <= n; i++)
		s = s * i;
	return s;
}

bool isxy = false;
double temp;
void CMycalculatorDlg::OnBnClickedButtonXdey()
{
	temp = m_second;
	m_second = 0.0;
	isxy = true;
}


void CMycalculatorDlg::xdey(void)
{
	if (isxy) 
	{
		m_second = pow(temp, m_second);
	}
}
