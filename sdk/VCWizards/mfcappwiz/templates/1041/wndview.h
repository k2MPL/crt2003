// [!output WND_VIEW_HEADER] : [!output WND_VIEW_CLASS] クラスのインターフェイス
//


#pragma once


// [!output WND_VIEW_CLASS] ウィンドウ

class [!output WND_VIEW_CLASS] : public [!output WND_VIEW_BASE_CLASS]
{
// コンストラクション
public:
	[!output WND_VIEW_CLASS]();

// 属性
public:

// 操作
public:

// オーバーライド
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 実装
public:
	virtual ~[!output WND_VIEW_CLASS]();

	// 生成された、メッセージ割り当て関数
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

