#pragma once
#include "afxdialogex.h"

#define WM_ENDOFDIAL WM_USER +7


// CSheDialog dialog

class CSheDialog : public CDialog
{
	DECLARE_DYNAMIC(CSheDialog)

public:
	CSheDialog(CWnd* pParent = nullptr);
	CSheDialog(CView* pView);
	virtual ~CSheDialog();

//Dialog Data

enum { IDD = IDD_She };


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_bBeauty;
	BOOL m_bMind;
	BOOL m_bGoodness;
	BOOL m_bLove;
	BOOL m_bChild;
	CString m_strMain;
	CString m_strAnswerShe;
	afx_msg void OnOk();
	afx_msg void OnCancel();
	CView* m_pView;
	bool Create();
};
