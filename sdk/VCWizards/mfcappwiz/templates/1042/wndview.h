// [!output WND_VIEW_HEADER] : [!output WND_VIEW_CLASS] 클래스의 인터페이스
//


#pragma once


// [!output WND_VIEW_CLASS] 창

class [!output WND_VIEW_CLASS] : public [!output WND_VIEW_BASE_CLASS]
{
// 생성
public:
	[!output WND_VIEW_CLASS]();

// 특성
public:

// 작업
public:

// 재정의
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 구현
public:
	virtual ~[!output WND_VIEW_CLASS]();

	// 메시지 맵 함수를 생성했습니다.
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

