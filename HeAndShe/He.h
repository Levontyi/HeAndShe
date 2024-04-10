#pragma once
#include "afxdialogex.h"


// He dialog

class He : public CDialog
{
	DECLARE_DYNAMIC(He)

public:
	He(CWnd* pParent = nullptr);   // standard constructor
	virtual ~He();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_He };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_ctrlAnswer;
	int m_nWeight;
	int m_nHeight;
	CString m_strProf;
	CString m_strQuality;
	int m_nColor;
	CEdit m_ctrlInf;
	CSpinButtonCtrl m_ctrlSpin;
	CSliderCtrl m_ctrlQI;
	int m_nQI;
	afx_msg void OnWhoIsHe();
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnEnChangeInf();
};
