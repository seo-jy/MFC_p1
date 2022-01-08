
// MFC_p1View.cpp: CMFCp1View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFC_p1.h"
#endif

#include "MFC_p1Doc.h"
#include "MFC_p1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCp1View

IMPLEMENT_DYNCREATE(CMFCp1View, CView)

BEGIN_MESSAGE_MAP(CMFCp1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CMFCp1View 생성/소멸

CMFCp1View::CMFCp1View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	x = 0;
	y = 0;
	w = 720;
	z = 20;
	step = 10;
	count = 0;
	flag = 0;
}

CMFCp1View::~CMFCp1View()
{
}

BOOL CMFCp1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFCp1View 그리기

void CMFCp1View::OnDraw(CDC* pDC)
{
	CMFCp1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	CDC memDC;
	CBitmap bmp, * ob;
	memDC.CreateCompatibleDC(pDC);
	bmp.LoadBitmap(IDB_BITMAP1);
	ob = memDC.SelectObject(&bmp);
	BITMAP bmpInfo;
	bmp.GetBitmap(&bmpInfo);
	pDC->TransparentBlt(x + m_winright, y + m_winbottom, bmpInfo.bmWidth, bmpInfo.bmHeight, &memDC, 0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, RGB(255, 255, 255));

	memDC.SelectObject(ob);
	bmp.DeleteObject();
	memDC.DeleteDC();


	/*--------사각형-------------------------------------------------------------------*/
	/*
	CBrush bs1, * pbs1;
	CPen pen, * oldpen;
	// test_brush(RGB(0, 0, 0));

	bs1.CreateStockObject(NULL_BRUSH); //투명 사각형
	pen.CreatePen(PS_NULL, 0, RGB(255, 255, 255)); //선
	pbs1 = dc.SelectObject(&bs1);
	//pbs1 = dc.SelectObject(&test_brush);

	oldpen = dc.SelectObject(&pen);
	dc.Rectangle(x + m_winright + 10, y + m_winbottom, x + m_winright + 35, y + m_winbottom + 50);
	dc.SelectObject(pbs1);
	dc.SelectObject(oldpen);
	pen.DeleteObject();
	*/
	/*
	CDC memDc;
	CBitmap *pbmP, oldb;

	memDc.CreateCompatibleDC(&dc);
	oldb.CreateCompatibleBitmap(&dc, m_winright+35, m_winbottom+50);
	pbmP = memDc.SelectObject(&oldb);

	CBrush bs1(NULL_BRUSH);
	memDc.SelectObject(&bs1);
	memDc.Rectangle(m_winright + 10, m_winbottom, m_winright + 35, m_winbottom + 50);

	CPen pen(PS_NULL, 0, RGB(255, 255, 255));
	memDc.SelectObject(&pen);
	CBrush bs2(NULL_BRUSH);
	memDc.SelectObject(&bs2);
	memdc.Rectangle(x + m_winright + 10, y + m_winbottom, x + m_winright + 35, y + m_winbottom + 50);
	*/
	/*
	bs1.CreateStockObject(NULL_BRUSH); //투명 사각형
	pen.CreatePen(PS_NULL, 0, RGB(255, 255, 255)); //선
	pbs1 = dc.SelectObject(&bs1);
	//pbs1 = dc.SelectObject(&test_brush);

	oldpen = dc.SelectObject(&pen);
	dc.Rectangle(x + m_winright + 10, y + m_winbottom, x + m_winright + 35, y + m_winbottom + 50);
	dc.SelectObject(pbs1);
	dc.SelectObject(oldpen);
	pen.DeleteObject();
	*/
	/*
	if (x + m_winright > m_winright && x > m_winright)
		x = x * -1;
	else if (x + m_winright < m_winright && x < -m_winright)
		x = x * -1;
	*/
	if (x + m_winright > m_winright && x > m_winright) {
		x = x * -1;
		return;
	}
	if (x + m_winright < m_winright && x < -m_winright) {
		x = x * -1;
		return;
	}
}


// CMFCp1View 인쇄

BOOL CMFCp1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFCp1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFCp1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMFCp1View 진단

#ifdef _DEBUG
void CMFCp1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCp1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCp1Doc* CMFCp1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCp1Doc)));
	return (CMFCp1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCp1View 메시지 처리기


void CMFCp1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nChar == VK_RIGHT)
		x += step;
	if (nChar == VK_LEFT)
		x -= step;
	Invalidate();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMFCp1View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	m_winright = cx / 2;
	m_winbottom = cy - 50;
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}
