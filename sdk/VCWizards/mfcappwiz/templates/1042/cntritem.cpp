// [!output CONTAINER_ITEM_IMPL] : [!output CONTAINER_ITEM_CLASS] Ŭ������ ����
//

#include "stdafx.h"
#include "[!output APP_HEADER]"

[!if OLEDB_RECORD_VIEW || ODBC_RECORD_VIEW]
#include "[!output ROWSET_HEADER]"
[!endif]
#include "[!output DOC_HEADER]"
#include "[!output VIEW_HEADER]"
#include "[!output CONTAINER_ITEM_HEADER]"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// [!output CONTAINER_ITEM_CLASS] ����

IMPLEMENT_SERIAL([!output CONTAINER_ITEM_CLASS], [!output CONTAINER_ITEM_BASE_CLASS], 0)

[!if RICH_EDIT_VIEW]
[!output CONTAINER_ITEM_CLASS]::[!output CONTAINER_ITEM_CLASS](REOBJECT* preo, [!output DOC_CLASS]* pContainer)
	: [!output CONTAINER_ITEM_BASE_CLASS](preo, pContainer)
[!else]
[!output CONTAINER_ITEM_CLASS]::[!output CONTAINER_ITEM_CLASS]([!output DOC_CLASS]* pContainer)
	: [!output CONTAINER_ITEM_BASE_CLASS](pContainer)
[!endif]
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.
}

[!output CONTAINER_ITEM_CLASS]::~[!output CONTAINER_ITEM_CLASS]()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
}
[!if !RICH_EDIT_VIEW]

void [!output CONTAINER_ITEM_CLASS]::OnChange(OLE_NOTIFICATION nCode, DWORD dwParam)
{
	ASSERT_VALID(this);

	[!output CONTAINER_ITEM_BASE_CLASS]::OnChange(nCode, dwParam);

	// �׸��� ����(���� ���� �Ǵ� ���� ���� ����)�� ��
	// �ش� �׸��� ���³� ������ ����� ����Ǹ� 
	// OnChange �˸��� �����ϴ�.

	// TODO: UpdateAllViews�� ȣ���Ͽ� �׸��� ��ȿȭ�մϴ�
	//���� ���α׷��� ������ ��Ʈ�� �����մϴ�.

	GetDocument()->UpdateAllViews(NULL);
		// ���⼭�� ��Ʈ ���� ��� ALL �並 ������Ʈ�մϴ�.
}

BOOL [!output CONTAINER_ITEM_CLASS]::OnChangeItemPosition(const CRect& rectPos)
{
	ASSERT_VALID(this);

	// ���� Ȱ��ȭ ���� �������� [!output CONTAINER_ITEM_CLASS]::OnChangeItemPosition��
	// ȣ���Ͽ� ���� â�� ��ġ�� �����մϴ�.
	// �Ϲ�������, �̷��� �۾��� ������ ����ǰų�
	// ���� ũ�Ⱑ ��������ν�
	// ���� ������ �����Ͱ� ����Ǿ� ��Ÿ���� ����Դϴ�.
	//
	// ���⼭ �⺻���� �⺻ Ŭ������ ȣ���ϴ� ���̸�
	// [!output CONTAINER_ITEM_BASE_CLASS]::SetItemRects�� ȣ���Ͽ� �׸���
	// �� ��ġ�� �̵��մϴ�.

	if (![!output CONTAINER_ITEM_BASE_CLASS]::OnChangeItemPosition(rectPos))
		return FALSE;

	// TODO: �׸��� �簢��/������ �ش��ϴ� ��� ĳ�ø� ������Ʈ�մϴ�.

	return TRUE;
}

[!if !ACTIVE_DOC_CONTAINER]
void [!output CONTAINER_ITEM_CLASS]::OnGetItemPosition(CRect& rPosition)
{
	ASSERT_VALID(this);

	// ���� Ȱ��ȭ ���� �������� [!output CONTAINER_ITEM_CLASS]::OnGetItemPosition��
	// ȣ���Ͽ� �� �׸��� ��ġ�� �����մϴ�.  �Ϲ�������, �� �簢����
	//  �ش� �׸��� ���� ��ġ�� �ݿ��ϴµ�, �� ��ġ�� Ȱ��ȭ�� ���Ǵ� �信 ����
	//  ����� ��ġ�Դϴ�.  [!output CONTAINER_ITEM_CLASS]::GetActiveView�� 
	//  ȣ���ϸ� �並 ���� �� �ֽ��ϴ�.

	// TODO: rPosition�� �ùٸ� �簢���� �ȼ� ������ ��ȯ�մϴ�.

	CSize size;
	rPosition.SetRectEmpty();
	if (SUCCEEDED(GetExtent(&size, m_nDrawAspect)))
	{
		[!output VIEW_CLASS]* pView = GetActiveView();
		ASSERT_VALID(pView);
		if (!pView)
			return;
		CDC *pDC = pView->GetDC();
		ASSERT(pDC);
		if (!pDC)
			return;
		pDC->HIMETRICtoLP(&size);
		rPosition.SetRect(10, 10, size.cx + 10, size.cy + 10);
	}
	else
		rPosition.SetRect(10, 10, 210, 210);
}
[!endif]

void [!output CONTAINER_ITEM_CLASS]::OnActivate()
{
[!if !ACTIVE_DOC_CONTAINER]
    // �����Ӹ��� ���� Ȱ��ȭ �׸��� �ϳ��� ����մϴ�.
    [!output VIEW_CLASS]* pView = GetActiveView();
    ASSERT_VALID(pView);
	if (!pView)
		return;
    COleClientItem* pItem = GetDocument()->GetInPlaceActiveItem(pView);
    if (pItem != NULL && pItem != this)
        pItem->Close();
    
    [!output CONTAINER_ITEM_BASE_CLASS]::OnActivate();
[!endif]
}

void [!output CONTAINER_ITEM_CLASS]::OnDeactivateUI(BOOL bUndoable)
{
	[!output CONTAINER_ITEM_BASE_CLASS]::OnDeactivateUI(bUndoable);

    DWORD dwMisc = 0;
    m_lpObject->GetMiscStatus(GetDrawAspect(), &dwMisc);
    if (dwMisc & OLEMISC_INSIDEOUT)
        DoVerb(OLEIVERB_HIDE, NULL);
}

void [!output CONTAINER_ITEM_CLASS]::Serialize(CArchive& ar)
{
	ASSERT_VALID(this);

	// [!output CONTAINER_ITEM_BASE_CLASS] �����Ϳ��� �б� ���� �⺻ Ŭ������ �� ó�� ȣ���մϴ�.
	// �̷��� �ϸ� [!output CONTAINER_ITEM_CLASS]::GetDocument���� ��ȯ��
	// m_pDocument �����Ͱ� �����Ǳ� ������ �⺻ Ŭ���� Serialize�� ���� ȣ���ϴ� ����
	// �����ϴ�.
	[!output CONTAINER_ITEM_BASE_CLASS]::Serialize(ar);

	// ���� [!output CONTAINER_ITEM_CLASS]�� ���õ� �����͸� ����/�˻��մϴ�.
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}
[!if CONTAINER_SERVER]

BOOL [!output CONTAINER_ITEM_CLASS]::CanActivate()
{
	// ���� ��ü�� ���� �����Ǵ� ���ȿ��� ���� ������ �۵����� ������
	// ���������� �ʽ��ϴ�. ���� �� ��쿡�� ���� Ȱ��ȭ��
	// ��Ȱ��ȭ�մϴ�.
	[!output DOC_CLASS]* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return FALSE;
	ASSERT_KINDOF(COleServerDoc, pDoc);
	if (!pDoc->IsKindOf(RUNTIME_CLASS(COleServerDoc)))
	{
		return FALSE;
	}
	if (pDoc->IsInPlaceActive())
		return FALSE;

	// �׷��� ������ �⺻ ������ ����մϴ�.
	return COleClientItem::CanActivate();
}
[!endif]
[!endif]


// [!output CONTAINER_ITEM_CLASS] ����

#ifdef _DEBUG
void [!output CONTAINER_ITEM_CLASS]::AssertValid() const
{
	[!output CONTAINER_ITEM_BASE_CLASS]::AssertValid();
}

void [!output CONTAINER_ITEM_CLASS]::Dump(CDumpContext& dc) const
{
	[!output CONTAINER_ITEM_BASE_CLASS]::Dump(dc);
}
#endif

