// [!output SERVER_ITEM_IMPL] : [!output SERVER_ITEM_CLASS] �N���X�̎���
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
	// TODO: ���̈ʒu�ɂP�x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B
	//  (�Ⴆ�΁A�A�C�e�� �f�[�^ �\�[�X�p�̓��ʂȃN���b�v�{�[�h�`���̒ǉ�)
}

[!output SERVER_ITEM_CLASS]::~[!output SERVER_ITEM_CLASS]()
{
	// TODO: ���̏ꏊ�Ɍ㏈���p�R�[�h��ǉ����Ă��������B
}

void [!output SERVER_ITEM_CLASS]::Serialize(CArchive& ar)
{
	// $$SRVRITEM_CLASS$$::Serialize �̓A�C�e�����N���b�v�{�[�h�ɃR�s�[��
	// ��Ă���Ƃ��ɂ́A�t���[�����[�N�ɂ���ČĂ΂�܂��B����� OLE �R�[��
	// �o�b�N OnGetClipboardData ��ʂ�z���Ď����I�ɍs�킹�邱�Ƃ��ł��܂��B
	// ���ߍ��݃A�C�e���̃f�t�H���g�͊ȒP�ȃh�L�������g�̃V���A���C�Y�֐��̑�
	// �������܂��B
	// �����N���T�|�[�g���Ă���Ƃ��́A�h�L�������g�̈ꕔ���V���A���C�Y���܂��B

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
	// �����̃A�v���P�[�V�����ł́A�A�C�e���̃R���e���c �A�X�y�N�g�̕`�悾�����n���h�����܂��B
	//  OnDrawEx ���I�[�o�[���C�h���Ă��� DVASPECT_THUMBNAIL �ő��̃A�X�y�N�g���T�|�[�g����
	// ���ɂ́AOnGetExtent ��ǉ�����A�X�y�N�g���n���h������悤�ɕύX���Ă��������B
	//
	//

	if (dwDrawAspect != DVASPECT_CONTENT)
		return [!output SERVER_ITEM_BASE_CLASS]::OnGetExtent(dwDrawAspect, rSize);

	// [!output SERVER_ITEM_CLASS]::OnGetExtent �́A���ڑS�̂�
	//  HIMETRIC �P�ʂ͈̔͂��擾���邽�߂ɌĂяo����܂��B
	//  ����l�ł́A�P���Ƀn�[�h�R�[�f�B���O���ꂽ�l��Ԃ��܂��B

	// TODO: �K���ȃT�C�Y�ɒu�������Ă��������B

	rSize = CSize(3000, 3000);   // 3000 x 3000 HIMETRIC ���j�b�g

	return TRUE;
}

BOOL [!output SERVER_ITEM_CLASS]::OnDraw(CDC* pDC, CSize& rSize)
{
	if (!pDC)
		return FALSE;

	// rSize ���g���ꍇ�͂�����폜���܂��B
	UNREFERENCED_PARAMETER(rSize);

	// TODO: �}�b�s���O ���[�h�Ɣ͈͂̐ݒ�B
	//  (�͈͂͒ʏ� OnGetExtent ����Ԃ��ꂽ�T�C�Y�Ɠ����ł�)
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowOrg(0,0);
	pDC->SetWindowExt(3000, 3000);

	// TODO: ���̏ꏊ�ɕ`��p�̃R�[�h��ǉ����܂��B�C�ӂ� HIMETRIC �͈̔͂�h��Ԃ��Ă��������B
	//       ���^�t�@�C�� �f�o�C�X �R���e�L�X�g (pDC) �̂��ׂĂ�`�悵�܂��B

[!if CONTAINER_SERVER]
	// TODO: ���ߍ��� [!output CONTAINER_ITEM_CLASS] �I�u�W�F�N�g���`�悵�Ă��������B

[!endif]
[!if CONTAINER_SERVER]
	// �ȉ��̃R�[�h�́A�C�ӂ̈ʒu�ɁA�ŏ��̍��ڂ�`�悵�܂��B

	// TODO: ���ۂ̕`��R�[�h�����������Ƃ��ɂ��̃R�[�h���폜���܂��B

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


// [!output SERVER_ITEM_CLASS] �f�f

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

