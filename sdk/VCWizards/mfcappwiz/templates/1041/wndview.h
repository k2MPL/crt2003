// [!output WND_VIEW_HEADER] : [!output WND_VIEW_CLASS] �N���X�̃C���^�[�t�F�C�X
//


#pragma once


// [!output WND_VIEW_CLASS] �E�B���h�E

class [!output WND_VIEW_CLASS] : public [!output WND_VIEW_BASE_CLASS]
{
// �R���X�g���N�V����
public:
	[!output WND_VIEW_CLASS]();

// ����
public:

// ����
public:

// �I�[�o�[���C�h
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ����
public:
	virtual ~[!output WND_VIEW_CLASS]();

	// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

