// [!output WND_VIEW_HEADER] : [!output WND_VIEW_CLASS] 類別的介面
//


#pragma once


// [!output WND_VIEW_CLASS] 視窗

class [!output WND_VIEW_CLASS] : public [!output WND_VIEW_BASE_CLASS]
{
// 建構
public:
	[!output WND_VIEW_CLASS]();

// 屬性
public:

// 作業
public:

// 覆寫
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 程式碼實作
public:
	virtual ~[!output WND_VIEW_CLASS]();

	// 產生的訊息對應函式
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

