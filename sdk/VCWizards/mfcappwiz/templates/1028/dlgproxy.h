// [!output DIALOG_AUTO_PROXY_HEADER]: ���Y��
//

#pragma once

class [!output DIALOG_CLASS];


// [!output DIALOG_AUTO_PROXY_CLASS] �R�O�ؼ�

class [!output DIALOG_AUTO_PROXY_CLASS] : public [!output DIALOG_AUTO_PROXY_BASE_CLASS]
{
	DECLARE_DYNCREATE([!output DIALOG_AUTO_PROXY_CLASS])

	[!output DIALOG_AUTO_PROXY_CLASS]();           // �ʺA�إߩҨϥΪ��O�@�غc�禡

// �ݩ�
public:
	[!output DIALOG_CLASS]* m_pDialog;

// �@�~
public:

// �мg
	public:
	virtual void OnFinalRelease();

// �{���X��@
protected:
	virtual ~[!output DIALOG_AUTO_PROXY_CLASS]();

	// ���ͪ��T�������禡

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE([!output DIALOG_AUTO_PROXY_CLASS])

	// ���ͪ� OLE ���������禡

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

