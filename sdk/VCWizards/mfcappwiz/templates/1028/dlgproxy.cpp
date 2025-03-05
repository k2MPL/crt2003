// [!output DIALOG_AUTO_PROXY_IMPL] : ��@��
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
	
	// �Y�n�O�����ε{�����檺�ɶ��P Automation ����@�Ϊ��ɶ��@�˪��A
	//	�غc�禡�n�I�s AfxOleLockApp�C
	AfxOleLockApp();

	// �g�����ε{���D�������СA���o���ܤ�����s���C�N Proxy ������
	// ���г]�w�����V��ܤ���A�ó]�w���V�� Proxy ����ܤ����^���СC
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
	// ��Ҧ����󳣬O�ϥ� Automation �إ߮ɡA�Y�n�������ε{���A
	// 	�ϥθѺc�禡�I�s AfxOleUnlockApp�C���~�A�o�|�R���D��ܤ��
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void [!output DIALOG_AUTO_PROXY_CLASS]::OnFinalRelease()
{
	// ������ Automation ����̫᪺�ѦҮɡA�|�I�s OnFinalRelease�C
	// �����O�|�۰ʧR������C�I�s�����O�e�A�Х��[�J�z����һ�
	// �B�~���M�� (cleanup) �{���X�C

	[!output DIALOG_AUTO_PROXY_BASE_CLASS]::OnFinalRelease();
}

BEGIN_MESSAGE_MAP([!output DIALOG_AUTO_PROXY_CLASS], [!output DIALOG_AUTO_PROXY_BASE_CLASS])
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP([!output DIALOG_AUTO_PROXY_CLASS], [!output DIALOG_AUTO_PROXY_BASE_CLASS])
END_DISPATCH_MAP()

// �`�N: �ڭ̥[�J�� IID_I[!output SAFE_PROJECT_NAME] ���䴩�H�K�q VBA �䴩���O�w��ô���C
// �� IID �����P .IDL �ɤ��A���[�ܤ��t�{�������� GUID �۲šC

// {[!output DISPIID_REGISTRY_FORMAT]}
static const IID IID_I[!output SAFE_PROJECT_NAME] =
[!output DISPIID_STATIC_CONST_GUID_FORMAT];

BEGIN_INTERFACE_MAP([!output DIALOG_AUTO_PROXY_CLASS], [!output DIALOG_AUTO_PROXY_BASE_CLASS])
	INTERFACE_PART([!output DIALOG_AUTO_PROXY_CLASS], IID_I[!output SAFE_PROJECT_NAME], Dispatch)
END_INTERFACE_MAP()

// �b�����~ {[!output APP_CLSID_REGISTRY_FORMAT]} �� StdAfx.h ���w�q
// IMPLEMENT_OLECREATE2 ����
IMPLEMENT_OLECREATE2([!output DIALOG_AUTO_PROXY_CLASS], "[!output SAFE_PROJECT_NAME].Application", [!output APP_CLSID_IMPLEMENT_OLECREATE_FORMAT])


// [!output DIALOG_AUTO_PROXY_CLASS] �T���B�z�`��
