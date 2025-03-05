// [!output CONTAINER_ITEM_IMPL] : [!output CONTAINER_ITEM_CLASS] �N���X�̎���
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
	// TODO: ���̈ʒu�ɂP�x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B
}

[!output CONTAINER_ITEM_CLASS]::~[!output CONTAINER_ITEM_CLASS]()
{
	// TODO: ���̏ꏊ�Ɍ㏈���p�R�[�h��ǉ����Ă��������B
}
[!if !RICH_EDIT_VIEW]

void [!output CONTAINER_ITEM_CLASS]::OnChange(OLE_NOTIFICATION nCode, DWORD dwParam)
{
	ASSERT_VALID(this);

	[!output CONTAINER_ITEM_BASE_CLASS]::OnChange(nCode, dwParam);

	// �A�C�e�����ҏW����Ă��鎞�ɂ� (�g�ݍ��ݐ�ł� �J���Ă��Ă�)
	// �A�C�e���̏�Ԃ܂��͂��̓��e�̉�ʕ\���̕ύX�ɑ΂��AOnChange
	// �ʒm�𑗂�܂��B

	// TODO: UpdateAllViews ���Ăяo���ăA�C�e���𖳌��ɂ��Ă��������B
	//  (�A�v���P�[�V�������L�̃q���g��Y����)

	GetDocument()->UpdateAllViews(NULL);
		// ���ׂẴr���[���q���g���Ȃ��ŃA�b�v�f�[�g���܂����B
}

BOOL [!output CONTAINER_ITEM_CLASS]::OnChangeItemPosition(const CRect& rectPos)
{
	ASSERT_VALID(this);

	// ���ߍ��ݐ�A�N�e�B�u������ [!output CONTAINER_ITEM_CLASS]::OnChangeItemPosition
	//  ���A���ߍ��ݐ�E�B���h�E�̈ʒu��ύX���邽�߂ɃT�[�o�[�ɂ����
	//  �Ăяo����܂��B�ʏ�A����́A�T�[�o�[ �h�L�������g�͈̔͂��ύX���ꂽ��A
	//  ���ߍ��ݐ�T�C�Y���ύX���ꂽ���ʂƂ��ăf�[�^���ς����
	//  �ꍇ�ɋN����܂��B
	//
	// �����ł̊��蓮��́A��{�N���X���Ăяo���āA
	//  ���̌��� [!output CONTAINER_ITEM_BASE_CLASS]::SetItemRects ���Ăяo���A
	//  ���ڂ�V�����ʒu�Ɉړ����܂��B

	if (![!output CONTAINER_ITEM_BASE_CLASS]::OnChangeItemPosition(rectPos))
		return FALSE;

	// TODO: �A�C�e���̎l�p�`/�͈͂̃L���b�V�����X�V���Ă��������B

	return TRUE;
}

[!if !ACTIVE_DOC_CONTAINER]
void [!output CONTAINER_ITEM_CLASS]::OnGetItemPosition(CRect& rPosition)
{
	ASSERT_VALID(this);

	// ���ߍ��ݐ悪�N�����Ă���ԁA [!output CONTAINER_ITEM_CLASS]::OnGetItemPosition
	//  ���Ăяo����Ă��̍��ڂ̏ꏊ�����肵�܂��B�ʏ�A���̎l�p�`�́A 
	//  �A�N�e�B�u���Ɏg��ꂽ�r���[�Ɋ֘A���鍀�ڂ̌��݈ʒu�𔽉f���܂��B
	//  [!output CONTAINER_ITEM_CLASS]::GetActiveView ���Ăяo�����Ƃɂ���āA�r���[���擾���邱�Ƃ��ł��܂��B

	// TODO: rPosition �ɂ̓s�N�Z���P�ʂŐ������l�p�`��Ԃ��Ă��������B

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
    // �t���[�����ƂɈ�����A�C�e���̃r�W���A���ҏW���\�ɂ��܂��B
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

	// �ŏ��̊�{�N���X�̌Ăяo���� [!output CONTAINER_ITEM_BASE_CLASS] �f�[�^�֓ǂݍ��܂�܂��B
	// ����ɂ��A[!output CONTAINER_ITEM_CLASS]::GetDocument ����Ԃ��ꂽ
	//  m_pDocument �|�C���^���Z�b�g�A�b�v����邽�߁A
	//  ��{�N���X Serialize ���ŏ��ɌĂяo�����Ƃ𐄏����܂��B
	[!output CONTAINER_ITEM_BASE_CLASS]::Serialize(ar);

	// [!output CONTAINER_ITEM_CLASS] �ɑ΂��ăf�[�^�̕ۑ�/�ǂݍ��݂��s���܂��B
	if (ar.IsStoring())
	{
		// TODO: �i�[����R�[�h�������ɒǉ����Ă��������B
	}
	else
	{
		// TODO: �ǂݍ��ރR�[�h�������ɒǉ����Ă��������B
	}
}
[!if CONTAINER_SERVER]

BOOL [!output CONTAINER_ITEM_CLASS]::CanActivate()
{
	// �T�[�o�[�ŕҏW����Ă���Ƃ��ɂ͑g�ݍ��ݐ�ł̕ҏW��
	// �T�|�[�g����Ă��܂���B ���̏ꍇ�͑g�ݍ��ݐ�̋N��  
	// �𖳌��ɂ��Ă��������B
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

	// ���̑��̓f�t�H���g�̏����ɔC���܂��B
	return COleClientItem::CanActivate();
}
[!endif]
[!endif]


// [!output CONTAINER_ITEM_CLASS] �f�f

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

