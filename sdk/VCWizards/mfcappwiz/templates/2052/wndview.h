// [!output WND_VIEW_HEADER] : [!output WND_VIEW_CLASS] ��Ľӿ�
//


#pragma once


// [!output WND_VIEW_CLASS] ����

class [!output WND_VIEW_CLASS] : public [!output WND_VIEW_BASE_CLASS]
{
// ����
public:
	[!output WND_VIEW_CLASS]();

// ����
public:

// ����
public:

// ��д
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~[!output WND_VIEW_CLASS]();

	// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

