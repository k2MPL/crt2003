// [!output WND_VIEW_HEADER] : [!output WND_VIEW_CLASS] ���O������
//


#pragma once


// [!output WND_VIEW_CLASS] ����

class [!output WND_VIEW_CLASS] : public [!output WND_VIEW_BASE_CLASS]
{
// �غc
public:
	[!output WND_VIEW_CLASS]();

// �ݩ�
public:

// �@�~
public:

// �мg
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// �{���X��@
public:
	virtual ~[!output WND_VIEW_CLASS]();

	// ���ͪ��T�������禡
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

