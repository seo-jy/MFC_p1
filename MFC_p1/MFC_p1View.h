
// MFC_p1View.h: CMFCp1View 클래스의 인터페이스
//

#pragma once


class CMFCp1View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMFCp1View() noexcept;
	DECLARE_DYNCREATE(CMFCp1View)

// 특성입니다.
public:
	CMFCp1Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMFCp1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	int x;
	int count;
	int y;
	int w;
	int z;
	int step;
	int m_winright;
	int m_winbottom;
	int flag;
};

#ifndef _DEBUG  // MFC_p1View.cpp의 디버그 버전
inline CMFCp1Doc* CMFCp1View::GetDocument() const
   { return reinterpret_cast<CMFCp1Doc*>(m_pDocument); }
#endif

