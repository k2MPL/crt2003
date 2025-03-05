// [!output CONTAINER_ITEM_IMPL] : [!output CONTAINER_ITEM_CLASS] ���O����@
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


// [!output CONTAINER_ITEM_CLASS] ��@

IMPLEMENT_SERIAL([!output CONTAINER_ITEM_CLASS], [!output CONTAINER_ITEM_BASE_CLASS], 0)

[!if RICH_EDIT_VIEW]
[!output CONTAINER_ITEM_CLASS]::[!output CONTAINER_ITEM_CLASS](REOBJECT* preo, [!output DOC_CLASS]* pContainer)
	: [!output CONTAINER_ITEM_BASE_CLASS](preo, pContainer)
[!else]
[!output CONTAINER_ITEM_CLASS]::[!output CONTAINER_ITEM_CLASS]([!output DOC_CLASS]* pContainer)
	: [!output CONTAINER_ITEM_BASE_CLASS](pContainer)
[!endif]
{
	// TODO: �b���[�J�@���غc�{���X
}

[!output CONTAINER_ITEM_CLASS]::~[!output CONTAINER_ITEM_CLASS]()
{
	// TODO: �b���[�J�M���{���X
}
[!if !RICH_EDIT_VIEW]

void [!output CONTAINER_ITEM_CLASS]::OnChange(OLE_NOTIFICATION nCode, DWORD dwParam)
{
	ASSERT_VALID(this);

	[!output CONTAINER_ITEM_BASE_CLASS]::OnChange(nCode, dwParam);

	// ���b�s�趵�خ� (�����Χ����}��)�A�Ӷ��ط|�ǰe����
	// �ثe���A�� OnChange �ܧ�q���A�Ψ䤺�e����ı�ƥ~�[�C

	// TODO: �϶��إ��ġA�ǥѩI�s UpdateAllViews (�f�t���ܨӨϥαz�����ε{��)

	GetDocument()->UpdateAllViews(NULL);
		// �{�b�u�ݧ�s [�Ҧ�] �˵���/�S������
}

BOOL [!output CONTAINER_ITEM_CLASS]::OnChangeItemPosition(const CRect& rectPos)
{
	ASSERT_VALID(this);

	// ��N�a�Ұ� [!output CONTAINER_ITEM_CLASS]::OnChangeItemPosition
	// �Q���A���I�s���ܧ�N�a��������m�C�q�`�A�o�O���A��
	// ��󤤸���ܧ�y�������G�A�o���ܧ󬰤��e�ܧ�δN�a
	// �վ�j�p�����G�����C
	//
	// ���B���w�]�O�I�s�����O�A�����O�|�I�s
	// [!output CONTAINER_ITEM_BASE_CLASS]::SetItemRects
	// �ӱN���ز��ʦܷs��m�C

	if (![!output CONTAINER_ITEM_BASE_CLASS]::OnChangeItemPosition(rectPos))
		return FALSE;

	// TODO: ��s�z�֦��֨����ت��x��/���e

	return TRUE;
}

[!if !ACTIVE_DOC_CONTAINER]
void [!output CONTAINER_ITEM_CLASS]::OnGetItemPosition(CRect& rPosition)
{
	ASSERT_VALID(this);

	// �b�N�a�Ұ� (In-place Activation) �����A�I�s [!output CONTAINER_ITEM_CLASS]
	// :OnGetItemPosition �H�M�w�����ت���m�C�q�`����إΥH�������إثe��m 
	// �P�ҰʨϥΪ��˵��������Y�C�z�i�I�s [!output CONTAINER_ITEM_CLASS]::
	// GetActiveView ��o���˵��C

	// TODO: �Ǧ^ rPosition �����T�����x�� (�H���������)

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
    // �C�ج[�Ȥ��\�@�ӴN�a�Ұ�
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

	// ���I�s�����OŪ�� [!output CONTAINER_ITEM_BASE_CLASS] ������ơC
	// �]���o�|�]�w m_pDocument ���СA�ӫ��ЬO�q
	// [!output CONTAINER_ITEM_CLASS]::GetDocument �Ǧ^�A���I�s�����O
	// �ǦC�ƬO�ܦn���@�k�C
	[!output CONTAINER_ITEM_BASE_CLASS]::Serialize(ar);

	// �{�b�x�s/�^���S�w�� [!output CONTAINER_ITEM_CLASS] �����
	if (ar.IsStoring())
	{
		// TODO: �b���[�J�x�s�{���X
	}
	else
	{
		// TODO: �b���[�J���J�{���X
	}
}
[!if CONTAINER_SERVER]

BOOL [!output CONTAINER_ITEM_CLASS]::CanActivate()
{
	// ��N�a�s����A�������ɡA�N�a�s�褣�|�o�ͧ@�ΡA�B���Q�䴩�C
	// �ҥH�A�����p�U�|���δN�a�ҰʡC
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

	// �_�h�A�̾a�w�]���欰
	return COleClientItem::CanActivate();
}
[!endif]
[!endif]


// [!output CONTAINER_ITEM_CLASS] �E�_

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

