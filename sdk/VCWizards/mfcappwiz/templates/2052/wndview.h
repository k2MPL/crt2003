// [!output WND_VIEW_HEADER] : [!output WND_VIEW_CLASS] 类的接口
//


#pragma once


// [!output WND_VIEW_CLASS] 窗口

class [!output WND_VIEW_CLASS] : public [!output WND_VIEW_BASE_CLASS]
{
// 构造
public:
	[!output WND_VIEW_CLASS]();

// 属性
public:

// 操作
public:

// 重写
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~[!output WND_VIEW_CLASS]();

	// 生成的消息映射函数
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

