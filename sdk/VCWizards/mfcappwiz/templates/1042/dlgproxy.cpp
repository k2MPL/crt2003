// [!output DIALOG_AUTO_PROXY_IMPL] : ���� ����
//

#include "stdafx.h"
#include "[!output APP_HEADER]"
#include "[!output DIALOG_AUTO_PROXY_HEADER]"
#include "[!output DIALOG_HEADER]"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// [!output DIALOG_AUTO_PROXY_CLASS]

IMPLEMENT_DYNCREATE([!output DIALOG_AUTO_PROXY_CLASS], [!output DIALOG_AUTO_PROXY_BASE_CLASS])

[!output DIALOG_AUTO_PROXY_CLASS]::[!output DIALOG_AUTO_PROXY_CLASS]()
{
	EnableAutomation();
	
	// �ڵ�ȭ ��ü�� Ȱ��ȭ�Ǿ� �ִ� ���� ���� ���α׷��� ���
	// ����ǵ��� �ϱ� ���� �����ڰ� AfxOleLockApp�� ȣ���մϴ�.
	AfxOleLockApp();

	// ���� ���α׷��� �� â �����͸� ���� ��ȭ ���ڿ� ����
	// �׼����� �����ɴϴ�. ���Ͻ��� ���� �����͸� �����Ͽ�
	// ��ȭ ���ڸ� ����Ű�� ��ȭ ������ �Ĺ� �����͸� �� ���Ͻ÷�
	// �����մϴ�.
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF([!output DIALOG_CLASS], AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS([!output DIALOG_CLASS])))
		{
			m_pDialog = reinterpret_cast<[!output DIALOG_CLASS]*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

[!output DIALOG_AUTO_PROXY_CLASS]::~[!output DIALOG_AUTO_PROXY_CLASS]()
{
	// �ڵ�ȭ�� ����Ͽ� ��� ��ü�� �����Ǹ� ���� ���α׷��� ������ ����
	// �Ҹ��ڰ� AfxOleUnlockApp�� ȣ���մϴ�.
	// �̷��� ȣ��� �� ��ȭ ���ڰ� ������ �� �ֽ��ϴ�.
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void [!output DIALOG_AUTO_PROXY_CLASS]::OnFinalRelease()
{
	// �ڵ�ȭ ��ü�� ���� ������ ������ �����Ǹ� OnFinalRelease��
	// ȣ��˴ϴ�. �⺻ Ŭ������ �ڵ����� ��ü�� �����մϴ�.
	// �⺻ Ŭ������ ȣ���ϱ� ���� ��ü�� �ʿ��� �߰� ���� �۾���
	// �߰��մϴ�.

	[!output DIALOG_AUTO_PROXY_BASE_CLASS]::OnFinalRelease();
}

BEGIN_MESSAGE_MAP([!output DIALOG_AUTO_PROXY_CLASS], [!output DIALOG_AUTO_PROXY_BASE_CLASS])
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP([!output DIALOG_AUTO_PROXY_CLASS], [!output DIALOG_AUTO_PROXY_BASE_CLASS])
END_DISPATCH_MAP()

// ����: VBA������ ���� ���� ���ε��� �����ϱ� ���� IID_I[!output SAFE_PROJECT_NAME]�� ���� ������ �߰��߽��ϴ�.
// �� IID�� .IDL ������ dispinterface�� ÷�ε� 
// GUID�� ��ġ�ؾ� �մϴ�.

// {[!output DISPIID_REGISTRY_FORMAT]}
static const IID IID_I[!output SAFE_PROJECT_NAME] =
[!output DISPIID_STATIC_CONST_GUID_FORMAT];

BEGIN_INTERFACE_MAP([!output DIALOG_AUTO_PROXY_CLASS], [!output DIALOG_AUTO_PROXY_BASE_CLASS])
	INTERFACE_PART([!output DIALOG_AUTO_PROXY_CLASS], IID_I[!output SAFE_PROJECT_NAME], Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 ��ũ�ΰ� �� ������Ʈ�� StdAfx.h�� ���ǵ˴ϴ�.
// {[!output APP_CLSID_REGISTRY_FORMAT]}
IMPLEMENT_OLECREATE2([!output DIALOG_AUTO_PROXY_CLASS], "[!output SAFE_PROJECT_NAME].Application", [!output APP_CLSID_IMPLEMENT_OLECREATE_FORMAT])


// [!output DIALOG_AUTO_PROXY_CLASS] �޽��� ó����
