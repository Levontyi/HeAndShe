
// HeAndSheView.h : interface of the CHeAndSheView class
//

#pragma once

class CSheDialog;


class CHeAndSheView : public CView
{
protected: // create from serialization only
	CHeAndSheView() noexcept;
	DECLARE_DYNCREATE(CHeAndSheView)

// Attributes
public:
	CHeAndSheDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CHeAndSheView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShe();
	LRESULT OnEndOfDialog(WPARAM wParam, LPARAM lParam);
	CSheDialog* m_pSheDialog;
	afx_msg void OnUpdateShe(CCmdUI* pCmdUI);
	bool m_bEnableShe;
};

#ifndef _DEBUG  // debug version in HeAndSheView.cpp
inline CHeAndSheDoc* CHeAndSheView::GetDocument() const
   { return reinterpret_cast<CHeAndSheDoc*>(m_pDocument); }
#endif

