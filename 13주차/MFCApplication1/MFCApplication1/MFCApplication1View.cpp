
// MFCApplication1View.cpp: CMFCApplication1View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication1View 생성/소멸

CMFCApplication1View::CMFCApplication1View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFCApplication1View 그리기

void CMFCApplication1View::OnDraw(CDC* pDC)
{
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.

	//배열로 저장된 값 출력
	for (int i = 0; i < pDoc->m_nCount; i++)
		DrawX(pDoc->m_ptData[i]);
}


// CMFCApplication1View 인쇄

BOOL CMFCApplication1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFCApplication1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFCApplication1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMFCApplication1View 진단

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View 메시지 처리기


void CMFCApplication1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//// CFile을 통한 파일 생성
	//int data1 = 10;
	//double data2 = 12.5;
	//char data3[64] = "문자열입니다!";

	//CFile file;

	//// 파일을 쓰기모드로 연다.
	//if (file.Open(_T("exam.txt"), CFile::modeCreate | CFile::modeWrite)) {
	//	// int 형 데이터를 저장한다.
	//	file.Write(&data1, sizeof(int));
	//	// double 형 데이터를 저장한다.
	//	file.Write(&data2, sizeof(double));

	//	// 문자열 길이를 얻는다.
	//	int data_size = strlen(data3);
	//	// 문자열 길이를 저장한다.
	//	file.Write(&data_size, sizeof(int));
	//	// 문자열 데이터를 저장한다.
	//	file.Write(data3, data_size);

	//	// 파일을 닫는다.
	//	file.Close();
	//}

	////CString 타입으로 char -> string 변경
	//int data1 = 10;
	//double data2 = 12.5;
	//char data3[64] = "문자열입니다!";

	//CFile  file;
	//// 파일을 쓰기모드로 연다.
	//if (file.Open(_T("File.dat"), CFile::modeCreate | CFile::modeWrite)) {
	//	// 정상적으로 열린 파일을 CArchive 에 저장하기 모드로 전달한다.
	//	CArchive ar(&file, CArchive::store);
	//	// char 배열에 저장된 데이터를 << 연산자에서 사용가능한 CString 타입으로 복사한다.
	//	CString str = CString(data3);

	//	// 상수를 저장한다.
	//	ar << 123;
	//	// int 형 데이터를 저장한다.
	//	ar << data1;
	//	// double 형 데이터를 저장한다.
	//	ar << data2;
	//	// 문자열 데이터를 저장한다.
	//	ar << str;

	//	// CArchive 를 닫는다.
	//	ar.Close();
	//	// 파일을 닫는다.
	//	file.Close();
	//}

	//DOC에 있는 글자 출력해보기
	//CMFCApplication1Doc* pDoc = GetDocument();

	//pDoc->str;

	//CClientDC dc(this);

	//dc.TextOut(100, 100, pDoc->str);

	//DrawX(point);  // 확인

	//DrawX 를 저장하고 출력하기 배열 형식으로 저장
	CMFCApplication1Doc* pDoc = GetDocument();

	if (pDoc->m_nCount < 100)
	{
		pDoc -> m_ptData[pDoc->m_nCount] = point;
		pDoc -> m_nCount++;
		DrawX(point);
	}

	CView::OnLButtonDown(nFlags, point);
}
//DrawX X 그리기
void CMFCApplication1View::DrawX(CPoint point)
{
	CClientDC dc(this);

	dc.MoveTo(point.x - 10, point.y - 10);
	dc.LineTo(point.x + 10, point.y + 10);
	dc.MoveTo(point.x - 10, point.y + 10);
	dc.LineTo(point.x + 10, point.y - 10);
}