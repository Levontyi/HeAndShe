// He.cpp : implementation file
//

#include "pch.h"
#include "HeAndShe.h"
#include "afxdialogex.h"
#include "He.h"


// He dialog

IMPLEMENT_DYNAMIC(He, CDialog)

He::He(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_He, pParent)
	, m_nWeight(0)
	, m_nHeight(0)
	, m_strProf(_T(""))
	, m_strQuality(_T(""))
	, m_nColor(0)
	, m_nQI(0)
{

}

He::~He()
{
}

void He::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Answer, m_ctrlAnswer);
	DDX_Text(pDX, IDC_Weight, m_nWeight);
	DDV_MinMaxInt(pDX, m_nWeight, 40, 100);
	DDX_Text(pDX, IDC_Height, m_nHeight);
	DDV_MinMaxInt(pDX, m_nHeight, 165, 200);
	DDX_CBString(pDX, IDC_Prof, m_strProf);
	DDX_CBString(pDX, IDC_Quality, m_strQuality);
	DDX_Radio(pDX, IDC_Color1, m_nColor);
	DDX_Control(pDX, IDC_Inf, m_ctrlInf);
	DDX_Control(pDX, IDC_SPIN1, m_ctrlSpin);
	DDX_Control(pDX, IDC_QI, m_ctrlQI);
	DDX_Slider(pDX, IDC_QI, m_nQI);
}


BEGIN_MESSAGE_MAP(He, CDialog)
	ON_BN_CLICKED(IDC_WhoIsHe, &He::OnWhoIsHe)
	ON_WM_HSCROLL()
	ON_EN_CHANGE(IDC_Inf, &He::OnEnChangeInf)
END_MESSAGE_MAP()


// He message handlers


void He::OnWhoIsHe()
{
	const int n = 5;
	CString Ans[n];
	CString Answer;
	Ans[0] = "Марс - покровитель героя \r\n Ваш герой подобен своему покровителю.";
	Ans[1] = "Гермес - покровитель героя \r\n Ваш герой подобен своему покровителю.";
	Ans[2] = "Аполлон - покровитель героя \r\n Ваш герой подобен своему покровителю.";
	Ans[3] = "Мы не знаем, кто ваш герой, но наш герой - это Вы.";
	Ans[4] = "Дать ответ мы не можем. \r\n Рекомендуем обратиться к профессиональным психологам.";
	UpdateData(TRUE);
	if (m_strProf == "Воин") Answer = Ans[0];
	else if (m_strProf == "Предприниматель") Answer = Ans[1];
	else if (m_strProf == "Художник") Answer = Ans[2];
	else if (m_strProf == "Программист") Answer = Ans[3];
	else Answer = Ans[4];
	m_ctrlAnswer.SetWindowTextW(Answer);
}


BOOL He::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_ctrlInf.SetWindowTextW(_T("Хотите знать, кто ваш герой? Задайте его характеристики и нажмите кнопку: Кто он?"));
	m_ctrlSpin.SetRange(50, 150);

	CString strQI;
	m_ctrlQI.SetRange(0, 100);
	m_ctrlQI.SetPos(50);
	strQI.Format(_T("%d"), m_ctrlQI.GetPos());
	SetDlgItemText(IDC_STATIC_QI, strQI);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void He::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CString strQI;
	strQI.Format(_T("%d"), m_ctrlQI.GetPos());
	SetDlgItemText(IDC_STATIC_QI, strQI);

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}


void He::OnEnChangeInf()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
