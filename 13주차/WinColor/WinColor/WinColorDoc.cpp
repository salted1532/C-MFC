
// WinColorDoc.cpp: CWinColorDoc 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "WinColor.h"
#endif

#include "WinColorDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CWinColorDoc

IMPLEMENT_DYNCREATE(CWinColorDoc, CDocument)

BEGIN_MESSAGE_MAP(CWinColorDoc, CDocument)
END_MESSAGE_MAP()


// CWinColorDoc 생성/소멸

CWinColorDoc::CWinColorDoc() noexcept
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.
	m_InImg = NULL; //입력 영상버퍼 초기화
	m_OutImg = NULL; //출력 영상버퍼 초기화
	for (int i = 0; i < 256; i++) //RGB값 모두 같게 B 값 대입
	{
		palRGB[i].rgbBlue = palRGB[i].rgbGreen = palRGB[i].rgbRed = i;
		palRGB[i].rgbReserved = 0;
	}

}

CWinColorDoc::~CWinColorDoc()
{
	if (m_InImg) delete[]m_InImg;	//입력 영상버퍼 해제
	if (m_OutImg) delete[]m_OutImg;	//출력 영상버퍼 해제
}

BOOL CWinColorDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CWinColorDoc serialization

void CWinColorDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CWinColorDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
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

// 검색 처리기를 지원합니다.
void CWinColorDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CWinColorDoc::SetSearchContent(const CString& value)
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

// CWinColorDoc 진단

#ifdef _DEBUG
void CWinColorDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWinColorDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CWinColorDoc 명령


BOOL CWinColorDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	CFile hFile;
	hFile.Open(lpszPathName, CFile::modeRead | CFile::typeBinary);
	hFile.Read(&dibHf, sizeof(BITMAPFILEHEADER)); // 파일 헤드를 읽음 
	if (dibHf.bfType != 0x4D42) { AfxMessageBox(_T("Not BMP file!!")); return FALSE; } //이 파일이 BMP파일인지 검사. 0x4d42=='BM'
	hFile.Read(&dibHi, sizeof(BITMAPINFOHEADER)); //"영상정보의 Header"를 읽는다.  
	if (dibHi.biBitCount != 8 && dibHi.biBitCount != 24) { AfxMessageBox(_T("Gray/True Color Possible!!")); return FALSE; }
	if (dibHi.biBitCount == 8) hFile.Read(palRGB, sizeof(RGBQUAD) * 256);

	// 메모리 할당 (8bit : 흑백 영상, 24bit : 컬러영상)
	int ImgSize;
	if (dibHi.biBitCount == 8) ImgSize = hFile.GetLength() - sizeof(BITMAPFILEHEADER) - sizeof(BITMAPINFOHEADER) - 256 * sizeof(RGBQUAD);
	else if (dibHi.biBitCount == 24) ImgSize = hFile.GetLength() - sizeof(BITMAPFILEHEADER) - sizeof(BITMAPINFOHEADER);
	m_InImg = new unsigned char[ImgSize]; //dibHi.biSizeImage
	m_OutImg = new unsigned char[ImgSize];
	hFile.Read(m_InImg, ImgSize);
	hFile.Close();
	height = dibHi.biHeight; width = dibHi.biWidth;

	if (dibHi.biBitCount == 24) return TRUE;

	// 영상데이터 대입 
	int i, j, index;
	int rwsize = WIDTHBYTES(dibHi.biBitCount * width);
	for (i = 0; i < height; i++)
	{
		index = i * rwsize;
		for (j = 0; j < width; j++)
			m_InImg[index + j] = (unsigned char)palRGB[(int)m_InImg[index + j]].rgbBlue;
	}

	return TRUE;
}


BOOL CWinColorDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	CFile hFile;
	if (!hFile.Open(lpszPathName, CFile::modeCreate | CFile::modeWrite | CFile::typeBinary)) return FALSE;
	hFile.Write(&dibHf, sizeof(BITMAPFILEHEADER));
	hFile.Write(&dibHi, sizeof(BITMAPINFOHEADER));
	if (dibHi.biBitCount == 8) hFile.Write(palRGB, sizeof(RGBQUAD) * 256);
	hFile.Write(m_InImg, dibHi.biSizeImage);
	hFile.Close();
	return TRUE;

	return CDocument::OnSaveDocument(lpszPathName);
}
