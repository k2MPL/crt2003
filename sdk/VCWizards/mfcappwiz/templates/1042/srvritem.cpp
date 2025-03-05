// [!output SERVER_ITEM_IMPL] : [!output SERVER_ITEM_CLASS] Ŭ������ ����
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


// [!output SERVER_ITEM_CLASS] ����

IMPLEMENT_DYNAMIC([!output SERVER_ITEM_CLASS], [!output SERVER_ITEM_BASE_CLASS])

[!output SERVER_ITEM_CLASS]::[!output SERVER_ITEM_CLASS]([!output DOC_CLASS]* pContainerDoc)
	: [!output SERVER_ITEM_BASE_CLASS](pContainerDoc, TRUE)
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.
	// (��: �׸��� ������ �ҽ��� �߰� Ŭ������ ���� �߰�)
}

[!output SERVER_ITEM_CLASS]::~[!output SERVER_ITEM_CLASS]()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
}

void [!output SERVER_ITEM_CLASS]::Serialize(CArchive& ar)
{
	// �׸��� Ŭ�����忡 ����Ǹ� �����ӿ�ũ����
	// [!output SERVER_ITEM_CLASS]::Serialize�� ȣ���մϴ�. �̷��� ȣ����
	// OLE �ݹ� OnGetClipboardData�� ���� �ڵ����� �߻���ų �� �ֽ��ϴ�.
	// ���� �׸��� ��� �⺻������ �ش� ������
	// Serialize �Լ��� �����ϴ� ���� �����ϴ�.
	// ������ ������ ��쿡�� ������ �Ϻθ� serialization�� �� �ֽ��ϴ�.
	//

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
	// �� ���� ���α׷��� ���� ��κ��� ���� ���α׷��� �׸��� ���� ��� �׸��⸸ ó���մϴ�.
	// OnDrawEx�� �������Ͽ� DVASPECT_THUMBNAIL�� ���� �ٸ� ����� �����Ϸ���
	// �� OnGetExtent�� ������ �����Ͽ� �߰� ����� ó���ϵ���
	// �ؾ� �մϴ�.

	if (dwDrawAspect != DVASPECT_CONTENT)
		return [!output SERVER_ITEM_BASE_CLASS]::OnGetExtent(dwDrawAspect, rSize);

	// ��ü �׸��� ������ HIMETRIC ������ �������� ����
	// [!output SERVER_ITEM_CLASS]::OnGetExtent�� ȣ���մϴ�.
	// ���⿡���� �⺻ ������ �ܼ���
	// �ϵ� �ڵ�� �ۼ��� ���� ���� ��ȯ�ϴ� ���Դϴ�.

	// TODO: �� ������ ũ�⸦ �ٲߴϴ�.

	rSize = CSize(3000, 3000);   // 3000 x 3000 HIMETRIC ����

	return TRUE;
}

BOOL [!output SERVER_ITEM_CLASS]::OnDraw(CDC* pDC, CSize& rSize)
{
	if (!pDC)
		return FALSE;

	// rSize�� ����� ��� �� ���� �����Ͻʽÿ�.
	UNREFERENCED_PARAMETER(rSize);

	// TODO: ���� ���� ������ �����մϴ�.
	// ������ ���� OnGetExtent���� ��ȯ�� ũ��� �����ϴ�.
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowOrg(0,0);
	pDC->SetWindowExt(3000, 3000);

	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�. �ɼ����� HIMETRIC ������ ä�� ���� �ֽ��ϴ�.
	// ��� �׸��� �۾��� ��Ÿ ���� ����̽� ���ؽ�Ʈ(pDC)���� �߻��մϴ�.

[!if CONTAINER_SERVER]
	// TODO: ���Ե� [!output CONTAINER_ITEM_CLASS] ��ü�� �׸��ϴ�.

[!endif]
[!if CONTAINER_SERVER]
	// ���� �ڵ�� ù° �׸��� ������ ��ġ�� �׸��ϴ�.

	// TODO: ���� �׸��� �ڵ尡 �Ϸ�Ǹ� �� �ڵ带 �����մϴ�.

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


// [!output SERVER_ITEM_CLASS] ����

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

