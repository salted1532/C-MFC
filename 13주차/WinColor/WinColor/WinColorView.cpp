
// WinColorView.cpp: CWinColorView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "WinColor.h"
#endif

#include "WinColorDoc.h"
#include "WinColorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWinColorView

IMPLEMENT_DYNCREATE(CWinColorView, CView)

BEGIN_MESSAGE_MAP(CWinColorView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CWinColorView 생성/소멸

CWinColorView::CWinColorView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	BmInfo = (BITMAPINFO*)malloc(sizeof(BITMAPINFO) + 256 * sizeof(RGBQUAD));
	for (int i = 0; i < 256; i++)
	{
		BmInfo->bmiColors[i].rgbRed = BmInfo->bmiColors[i].rgbGreen = BmInfo->bmiColors[i].rgbBlue = i;
		BmInfo->bmiColors[i].rgbReserved = 0;
	}

}

CWinColorView::~CWinColorView()
{
	if (BmInfo) delete BmInfo;
}

BOOL CWinColorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CWinColorView 그리기

void CWinColorView::OnDraw(CDC* pDC)
{
	CWinColorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.

	if (pDoc->m_InImg == NULL) return;

	height = pDoc->dibHi.biHeight;
	width = pDoc->dibHi.biWidth;
	rwsize = WIDTHBYTES(pDoc->dibHi.biBitCount * pDoc->dibHi.biWidth);
	BmInfo->bmiHeader = pDoc->dibHi;

	SetDIBitsToDevice(pDC->GetSafeHdc(), 0, 0, width, height,
		0, 0, 0, height, pDoc->m_InImg, BmInfo, DIB_RGB_COLORS);
}


// CWinColorView 인쇄

BOOL CWinColorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CWinColorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CWinColorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CWinColorView 진단

#ifdef _DEBUG
void CWinColorView::AssertValid() const
{
	CView::AssertValid();
}

void CWinColorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWinColorDoc* CWinColorView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWinColorDoc)));
	return (CWinColorDoc*)m_pDocument;
}
#endif //_DEBUG


// CWinColorView 메시지 처리기
