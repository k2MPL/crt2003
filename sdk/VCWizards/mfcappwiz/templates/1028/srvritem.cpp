// [!output SERVER_ITEM_IMPL] : [!output SERVER_ITEM_CLASS] ���O����@
//

#include "stdafx.h"
#include "[!output APP_HEADER]"

#include "[!output DOC_HEADER]"
#include "[!output SERVER_ITEM_HEADER]"
[!if CONTAINER_SERVER]
#include "[!output CONTAINER_ITEM_HEADER]"
[!endif]

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// [!output SERVER_ITEM_CLASS] ��@

IMPLEMENT_DYNAMIC([!output SERVER_ITEM_CLASS], [!output SERVER_ITEM_BASE_CLASS])

[!output SERVER_ITEM_CLASS]::[!output SERVER_ITEM_CLASS]([!output DOC_CLASS]* pContainerDoc)
	: [!output SERVER_ITEM_BASE_CLASS](pContainerDoc, TRUE)
{
	// TODO: �b���[�J�@���غc�{���X (�Ҧp�A�N��L�ŶKï�榡�[�J���ت���ƨӷ�)
}

[!output SERVER_ITEM_CLASS]::~[!output SERVER_ITEM_CLASS]()
{
	// TODO: �b���[�J�M���{���X
}

void [!output SERVER_ITEM_CLASS]::Serialize(CArchive& ar)
{
	// [!output SERVER_ITEM_CLASS]::�p�G�N���ؽƻs��ŶKï�A�[�c�|�I�s�ǦC�ơC
	// �o�|�g�� OLE �^�I OnGetClipboardData �Ӧ۰ʵo�͡C���O���ت��̦n�w�]��
	// �e�U����󪺧ǦC�ƨ禡�C�p�G�z�䴩�s���A�h�z�i�ȧǦC�Ƥ�󪺤@�����C

	if (!IsLinkedItem())
	{
		[!output DOC_CLASS]* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (pDoc)
			pDoc->Serialize(ar);
	}
}

BOOL [!output SERVER_ITEM_CLASS]::OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize)
{
	// �������j�������ε{���ȳB�z�yø���ؤ譱�����e�C�p�G�z�Q�䴩��L�譱�A
	// �p DVASPECT_THUMBNAIL (�g���мg OnDrawEx)�A�h���ק� OnGetExtent ��
	// ��@�H�B�z��L�譱�C

	if (dwDrawAspect != DVASPECT_CONTENT)
		return [!output SERVER_ITEM_BASE_CLASS]::OnGetExtent(dwDrawAspect, rSize);

	// �I�s [!output SERVER_ITEM_CLASS]::OnGetExtent �Ө��o��Ӷ��� 
	// HIMETRIC ��줤�������C���B�w�]����@�ȶǦ^�椸���w���s�X�ƥءC

	// TODO: ���N�����N�j�p

	rSize = CSize(3000, 3000);   // 3000 x 3000 HIMETRIC �椸

	return TRUE;
}

BOOL [!output SERVER_ITEM_CLASS]::OnDraw(CDC* pDC, CSize& rSize)
{
	if (!pDC)
		return FALSE;

	// �p�G�z�ϥ� rSize �h����
	UNREFERENCED_PARAMETER(rSize);

	// TODO: �]�w�����Ҧ��P���� (�����q�`�P�q OnGetExtent �Ǧ^���j�p�ۦP)
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowOrg(0,0);
	pDC->SetWindowExt(3000, 3000);

	// TODO: �b���[�J�yø�{���X�C�ﶵ�ʪ��A�b HIMETRIC ����g���e�C
	// �Ҧ����yø���o�ͩ��~�ɸ˸m���e (pDC)�C

[!if CONTAINER_SERVER]
	// TODO: ���yø���O�� [!output CONTAINER_ITEM_CLASS] ����C

[!endif]
[!if CONTAINER_SERVER]
	// �U�C�{���X�yø�����m�W���Ĥ@�����ءC

	// TODO: �����z����ڴyø�{���X�ɡA�������{���X

	[!output DOC_CLASS]* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return FALSE;

	POSITION pos = pDoc->GetStartPosition();
	[!output CONTAINER_ITEM_CLASS]* pItem = DYNAMIC_DOWNCAST([!output CONTAINER_ITEM_CLASS], pDoc->GetNextClientItem(pos));
	if (pItem != NULL)
		pItem->Draw(pDC, CRect(10, 10, 1010, 1010));
[!endif]
	return TRUE;
}


// [!output SERVER_ITEM_CLASS] �E�_

#ifdef _DEBUG
void [!output SERVER_ITEM_CLASS]::AssertValid() const
{
	[!output SERVER_ITEM_BASE_CLASS]::AssertValid();
}

void [!output SERVER_ITEM_CLASS]::Dump(CDumpContext& dc) const
{
	[!output SERVER_ITEM_BASE_CLASS]::Dump(dc);
}
#endif

