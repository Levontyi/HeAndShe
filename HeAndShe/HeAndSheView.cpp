
// HeAndSheView.cpp : implementation of the CHeAndSheView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "HeAndShe.h"
#endif

#include "HeAndSheDoc.h"
#include "HeAndSheView.h"
#include "CSheDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHeAndSheView

IMPLEMENT_DYNCREATE(CHeAndSheView, CView)

BEGIN_MESSAGE_MAP(CHeAndSheView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_SHE, &CHeAndSheView::OnShe)
	ON_MESSAGE(WM_ENDOFDIAL, OnEndOfDialog)
	ON_UPDATE_COMMAND_UI(ID_SHE, &CHeAndSheView::OnUpdateShe)
END_MESSAGE_MAP()

// CHeAndSheView construction/destruction

CHeAndSheView::CHeAndSheView() noexcept
{
	// TODO: add construction code here
	m_bEnableShe = TRUE;
	m_pSheDialog = new CSheDialog(this);
	
}

CHeAndSheView::~CHeAndSheView()
{
	delete m_pSheDialog;
}

BOOL CHeAndSheView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CHeAndSheView drawing

void CHeAndSheView::OnDraw(CDC* /*pDC*/)
{
	CHeAndSheDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CHeAndSheView printing

BOOL CHeAndSheView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CHeAndSheView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CHeAndSheView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CHeAndSheView diagnostics

#ifdef _DEBUG
void CHeAndSheView::AssertValid() const
{
	CView::AssertValid();
}

void CHeAndSheView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHeAndSheDoc* CHeAndSheView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHeAndSheDoc)));
	return (CHeAndSheDoc*)m_pDocument;
}
#endif //_DEBUG


// CHeAndSheView message handlers


void CHeAndSheView::OnShe()
{
	TRACE("Обработчик OnShe\n");
	m_pSheDialog->m_bBeauty = TRUE;
	m_pSheDialog->m_bChild = FALSE;
	m_pSheDialog->m_bGoodness = FALSE;
	m_pSheDialog->m_bLove = TRUE;
	m_pSheDialog->m_bMind = FALSE;
	m_pSheDialog->m_strMain = "";
	m_pSheDialog->m_strAnswerShe = "";
	m_pSheDialog->Create();
	m_bEnableShe = FALSE;
}

LRESULT CHeAndSheView::OnEndOfDialog(WPARAM wParam, LPARAM lParam)
{
	m_pSheDialog->DestroyWindow();
	m_bEnableShe = TRUE;
	return 0L;
}


void CHeAndSheView::OnUpdateShe(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_bEnableShe);
}
