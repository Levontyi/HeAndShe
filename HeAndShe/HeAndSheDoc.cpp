// HeAndSheDoc.cpp : implementation of the CHeAndSheDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "HeAndShe.h"
#endif
#include "He.h"
#include "HeAndSheDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CHeAndSheDoc

IMPLEMENT_DYNCREATE(CHeAndSheDoc, CDocument)

BEGIN_MESSAGE_MAP(CHeAndSheDoc, CDocument)
	ON_COMMAND(ID_HE, &CHeAndSheDoc::OnHe)
END_MESSAGE_MAP()


// CHeAndSheDoc construction/destruction

CHeAndSheDoc::CHeAndSheDoc() noexcept
{
	// TODO: add one-time construction code here

}

CHeAndSheDoc::~CHeAndSheDoc()
{
}

BOOL CHeAndSheDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CHeAndSheDoc serialization

void CHeAndSheDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CHeAndSheDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CHeAndSheDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CHeAndSheDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CHeAndSheDoc diagnostics

#ifdef _DEBUG
void CHeAndSheDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHeAndSheDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CHeAndSheDoc commands


void CHeAndSheDoc::OnHe()
{
	He dlgHe;
	dlgHe.m_nWeight = 80;
	dlgHe.m_nHeight = 185;
	dlgHe.m_nQI = 50;
	if (dlgHe.DoModal() == IDOK)
		TRACE("Диалог окончен нажатием ОК");
	else
		TRACE("Диалог окончен нажатием Cancle");
	TRACE("Характеристики героя:\n Рост - %u \nВес -%u \n КИ =%u \n",
		dlgHe.m_nHeight, dlgHe.m_nWeight, dlgHe.m_nQI);
	TRACE("Профессия - %s\n Главное качество - %s\n", dlgHe.m_strProf, dlgHe.m_strQuality);
}
