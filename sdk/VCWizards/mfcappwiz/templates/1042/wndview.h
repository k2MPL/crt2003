// [!output WND_VIEW_HEADER] : [!output WND_VIEW_CLASS] Ŭ������ �������̽�
//


#pragma once


// [!output WND_VIEW_CLASS] â

class [!output WND_VIEW_CLASS] : public [!output WND_VIEW_BASE_CLASS]
{
// ����
public:
	[!output WND_VIEW_CLASS]();

// Ư��
public:

// �۾�
public:

// ������
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ����
public:
	virtual ~[!output WND_VIEW_CLASS]();

	// �޽��� �� �Լ��� �����߽��ϴ�.
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

