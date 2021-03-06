
// MycalculatorDlg.h: 头文件
//

#pragma once


// CMycalculatorDlg 对话框
class CMycalculatorDlg : public CDialogEx
{
// 构造
public:
	CMycalculatorDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYCALCULATOR_DIALOG };
#endif

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
	// 弧度还是角度判定
	int m_angleType;
	// 第一个操作数
	double m_first;
	// 第二个操作数
	double m_second;
	// 运算符
	CString m_operator;
	// 小数点的系数权值
	double m_coff;
	CString m_display;
	afx_msg void OnBnClickedJiaodu();
	afx_msg void OnBnClickedHudu();
	void UpdateDisplay(double dck);
	void Calculate(void);
	void onButton(int n);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButtonSign();
	afx_msg void OnBnClickedButtonPoint();
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonMutiply();
	afx_msg void OnBnClickedButtonDiv();
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonEqual();
	afx_msg void OnBnClickedButtonSqrt();
	afx_msg void OnBnClickedButtonReci();
	afx_msg void OnBnClickedButtonExp();
	afx_msg void OnBnClickedButton10x();
	void sanjiaohanshu(void);
	afx_msg void OnBnClickedButtonSin();
	afx_msg void OnBnClickedButtonCos();
	afx_msg void OnBnClickedButtonTan();
	afx_msg void OnBnClickedButtonArctan();
	afx_msg void OnBnClickedButtonArcsin();
	afx_msg void OnBnClickedButtonArccos();
	afx_msg void OnBnClickedButtonLn();
	afx_msg void OnBnClickedButtonLog();
	afx_msg void OnBnClickedButtonNjc();
	double jiecheng(int n);
	afx_msg void OnBnClickedButtonXdey();
	void xdey(void);
};
