// [!output DIALOG_AUTO_PROXY_HEADER]: �w�b�_�[ �t�@�C��
//

#pragma once

class [!output DIALOG_CLASS];


// [!output DIALOG_AUTO_PROXY_CLASS] �R�}���h �^�[�Q�b�g

class [!output DIALOG_AUTO_PROXY_CLASS] : public [!output DIALOG_AUTO_PROXY_BASE_CLASS]
{
	DECLARE_DYNCREATE([!output DIALOG_AUTO_PROXY_CLASS])

	[!output DIALOG_AUTO_PROXY_CLASS]();           // ���I�����Ŏg�p����� protected �R���X�g���N�^

// ����
public:
	[!output DIALOG_CLASS]* m_pDialog;

// ����
public:

// �I�[�o�[���C�h
	public:
	virtual void OnFinalRelease();

// ����
protected:
	virtual ~[!output DIALOG_AUTO_PROXY_CLASS]();

	// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE([!output DIALOG_AUTO_PROXY_CLASS])

	// �������ꂽ OLE �f�B�X�p�b�`���蓖�Ċ֐�

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

