// [!output DIALOG_AUTO_PROXY_HEADER]: ��� ����
//

#pragma once

class [!output DIALOG_CLASS];


// [!output DIALOG_AUTO_PROXY_CLASS] ��� ���

class [!output DIALOG_AUTO_PROXY_CLASS] : public [!output DIALOG_AUTO_PROXY_BASE_CLASS]
{
	DECLARE_DYNCREATE([!output DIALOG_AUTO_PROXY_CLASS])

	[!output DIALOG_AUTO_PROXY_CLASS]();           // ���� ����⿡ ���Ǵ� protected ������

// Ư��
public:
	[!output DIALOG_CLASS]* m_pDialog;

// �۾�
public:

// ������
	public:
	virtual void OnFinalRelease();

// ����
protected:
	virtual ~[!output DIALOG_AUTO_PROXY_CLASS]();

	// �޽��� �� �Լ��� �����߽��ϴ�.

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE([!output DIALOG_AUTO_PROXY_CLASS])

	// OLE ����ġ �� �Լ��� �����߽��ϴ�.

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

