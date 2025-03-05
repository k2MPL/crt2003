// [!output VIEW_IMPL] : [!output VIEW_CLASS] �N���X�̎���
//

#include "stdafx.h"
#include "[!output APP_HEADER]"

[!if OLEDB_RECORD_VIEW || ODBC_RECORD_VIEW]
#include "[!output ROWSET_HEADER]"
[!endif]
#include "[!output DOC_HEADER]"
[!if CONTAINER || CONTAINER_SERVER]
#include "[!output CONTAINER_ITEM_HEADER]"
[!endif]
#include "[!output VIEW_HEADER]"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// [!output VIEW_CLASS]

IMPLEMENT_DYNCREATE([!output VIEW_CLASS], [!output VIEW_BASE_CLASS])

BEGIN_MESSAGE_MAP([!output VIEW_CLASS], [!output VIEW_BASE_CLASS])
[!if PROJECT_STYLE_EXPLORER]
[!if LIST_VIEW]
	ON_WM_STYLECHANGED()
[!endif]
[!endif]
[!if CONTAINER || CONTAINER_SERVER]
	ON_WM_DESTROY()
[!if !RICH_EDIT_VIEW]
	ON_WM_SETFOCUS()
	ON_WM_SIZE()
	ON_COMMAND(ID_OLE_INSERT_NEW, OnInsertObject)
	ON_COMMAND(ID_CANCEL_EDIT_CNTR, OnCancelEditCntr)
	ON_COMMAND(ID_FILE_PRINT, OnFilePrint)
[!else]
[!if PRINTING]
	// �W������R�}���h
	ON_COMMAND(ID_FILE_PRINT, [!output VIEW_BASE_CLASS]::OnFilePrint)
[!endif]
[!endif]
[!else]
[!if PRINTING]
	// �W������R�}���h
	ON_COMMAND(ID_FILE_PRINT, [!output VIEW_BASE_CLASS]::OnFilePrint)
[!endif]
[!endif]
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]
	ON_COMMAND(ID_CANCEL_EDIT_SRVR, OnCancelEditSrvr)
[!endif]
[!if PRINTING]
[!if !HTML_VIEW && !HTML_EDITVIEW && !ACTIVE_DOC_CONTAINER]
	ON_COMMAND(ID_FILE_PRINT_DIRECT, [!output VIEW_BASE_CLASS]::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, [!output VIEW_BASE_CLASS]::OnFilePrintPreview)
[!endif]
[!if ACTIVE_DOC_CONTAINER]
	ON_COMMAND(ID_FILE_PRINT_DIRECT, [!output VIEW_BASE_CLASS]::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, OnFilePrintPreview)
	ON_UPDATE_COMMAND_UI(ID_FILE_PRINT_PREVIEW, OnFilePrintPreviewUIUpdate)
[!endif]
[!endif]
END_MESSAGE_MAP()

[!if HTML_EDITVIEW]
BEGIN_DHTMLEDITING_CMDMAP([!output VIEW_CLASS])
	DHTMLEDITING_CMD_ENTRY(ID_EDIT_COPY, IDM_COPY)
	DHTMLEDITING_CMD_ENTRY(ID_EDIT_CUT, IDM_CUT)
	DHTMLEDITING_CMD_ENTRY(ID_EDIT_PASTE, IDM_PASTE)
	DHTMLEDITING_CMD_ENTRY(ID_EDIT_UNDO, IDM_UNDO)
END_DHTMLEDITING_CMDMAP()
[!endif]
// [!output VIEW_CLASS] �R���X�g���N�V����/�f�X�g���N�V����

[!output VIEW_CLASS]::[!output VIEW_CLASS]()
[!if FORM_VIEW || OLEDB_RECORD_VIEW || ODBC_RECORD_VIEW]
	: [!output VIEW_BASE_CLASS]([!output VIEW_CLASS]::IDD)
[!endif]
{
[!if ACCESSIBILITY]
	EnableActiveAccessibility();
[!endif]
[!if FORM_VIEW || OLEDB_RECORD_VIEW || ODBC_RECORD_VIEW]
[!if OLEDB_RECORD_VIEW || ODBC_RECORD_VIEW]
	m_pSet = NULL;
[!endif]
[!endif]
[!if CONTAINER || CONTAINER_SERVER]
[!if !RICH_EDIT_VIEW]
	m_pSelection = NULL;
[!endif]
[!endif]
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

[!output VIEW_CLASS]::~[!output VIEW_CLASS]()
{
}
[!if FORM_VIEW || OLEDB_RECORD_VIEW || ODBC_RECORD_VIEW]

void [!output VIEW_CLASS]::DoDataExchange(CDataExchange* pDX)
{
	[!output VIEW_BASE_CLASS]::DoDataExchange(pDX);
[!if ODBC_RECORD_VIEW]
	// �R���g���[�����f�[�^�x�[�X �t�B�[���h�ɐڑ����邽�߂� DDX_Field* �֐��������ɑ}���ł��܂��B
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �ڍׂɂ��ẮAMSDN ����� ODBC �T���v�����Q�Ƃ��Ă��������B
[!endif]
[!if OLEDB_RECORD_VIEW]
	// �f�[�^�x�[�X���r���[�Ƀ����N���� SetDlgItem*/GetDlgItem* API �Ăяo���Ɠ��l�ɁADDX_* �֐���}�����邱�Ƃ��ł��܂��B
	//�� : ::SetDlgItemText(m_hWnd, IDC_MYCONTROL, m_pSet->m_MyColumn);
	// �ڍׂɂ��Ă� MSDN ����� OLEDB �T���v�����Q�Ƃ��Ă��������B
[!endif]
}
[!endif]

BOOL [!output VIEW_CLASS]::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

[!if EDIT_VIEW]
	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// ���[�h ���b�v���g�p�\�ɂ��܂�

	return bPreCreated;
[!else]
	return [!output VIEW_BASE_CLASS]::PreCreateWindow(cs);
[!endif]
}
[!if !TREE_VIEW && !LIST_VIEW && !HTML_VIEW && !HTML_EDITVIEW && !RICH_EDIT_VIEW && !EDIT_VIEW && !FORM_VIEW && !OLEDB_RECORD_VIEW && !ODBC_RECORD_VIEW]

// [!output VIEW_CLASS] �`��
[!if CONTAINER || CONTAINER_SERVER]
[!if !ACTIVE_DOC_CONTAINER]

void [!output VIEW_CLASS]::OnDraw(CDC* pDC)
{
	if (!pDC)
		return;

	[!output DOC_CLASS]* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
	// TODO: �܂��A�h�L�������g�̂��ׂĂ� OLE ���ڂ��`�悵�܂��B

	// �I��͈͂�K���Ȉʒu�ɕ`�悵�܂��B���̃R�[�h�͎��ۂ̕`��p�̃R�[�h��
	//  ��������Ă���폜���Ă��������B�g�ݍ��ݐ�ҏW��L���ɂ���
	//  ���߂ɁA���̈ʒu�� [!output CONTAINER_ITEM_CLASS],
	//  ���܂��B

	// TODO: �ŏI�I�ȕ`��p�̃R�[�h���m�肵���Ƃ��ɂ͂��̃R�[�h�͍폜���Ă��������B
	if (m_pSelection != NULL)
	{
		CSize size;
		CRect rect(10, 10, 210, 210);
		
		if (SUCCEEDED(m_pSelection->GetExtent(&size, m_pSelection->m_nDrawAspect)))
		{
			pDC->HIMETRICtoLP(&size);
			rect.right = size.cx + 10;
			rect.bottom = size.cy + 10;
		}
		m_pSelection->Draw(pDC, rect);
	}
}
[!else]

void [!output VIEW_CLASS]::OnDraw(CDC* /*pDC*/)
{
	[!output DOC_CLASS]* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
}[!endif]
[!else]

void [!output VIEW_CLASS]::OnDraw(CDC* /*pDC*/)
{
	[!output DOC_CLASS]* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
}
[!endif]
[!endif] 
[!if PRINTING]
[!if TREE_VIEW || LIST_VIEW]


void [!output VIEW_CLASS]::OnDraw(CDC* /*pDC*/)
{
	[!output DOC_CLASS]* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
}

[!endif]
[!endif]
[!if SCROLL_VIEW || CONTAINER || CONTAINER_SERVER || OLEDB_RECORD_VIEW || LIST_VIEW || TREE_VIEW || FORM_VIEW || HTML_VIEW || ODBC_RECORD_VIEW]

void [!output VIEW_CLASS]::OnInitialUpdate()
{
[!if ODBC_RECORD_VIEW]
	m_pSet = &GetDocument()->[!output ROWSET_CLASS_VARIABLE_NAME];
[!endif]
[!if OLEDB_RECORD_VIEW]
	m_pSet = &GetDocument()->[!output ROWSET_CLASS_VARIABLE_NAME];
	{
		CWaitCursor wait;
		HRESULT hr = m_pSet->OpenAll();
		if (FAILED(hr))
		{
			// ���R�[�h�Z�b�g���J���܂���ł����B���̃��R�[�h�Z�b�g��
			// �X�g�A�h �v���V�[�W���̏ꍇ�AOpenAll() ���\�b�h���Ăяo���O�ɁA
			// ���̓p�����[�^������������������Ă��邩�ǂ���i
			// �m�F���Ă��������B

			AfxMessageBox(_T("���R�[�h�Z�b�g���J���܂���ł����B"), MB_OK);
			// Recordet ���J�����Ɍ��݂̃��R�[�h��ύX���悤�Ƃ����
			// �N���b�V���̌����ƂȂ邽�߁A�� ����� �O �̃��R�[�h
			// �R�}���h���g�p�s�\�ɂ��܂��B
			m_bOnFirstRecord = TRUE;
			m_bOnLastRecord = TRUE;
		}
		if( hr == DB_S_ENDOFROWSET )
		{
			// �s�Z�b�g����ł��B�s���܂܂�Ă��܂���B
			AfxMessageBox(_T("���R�[�h �Z�b�g���J����܂������A�Ԃ��s������܂���B"), MB_OK);
			// [���̃��R�[�h] ����� [�O�̃��R�[�h] �R�}���h�𖳌��ɂ��܂��B
			m_bOnFirstRecord = TRUE;
			m_bOnLastRecord = TRUE;
		}
	}
[!endif]
	[!output VIEW_BASE_CLASS]::OnInitialUpdate();
[!if FORM_VIEW]
[!if APP_TYPE_SDI]
	GetParentFrame()->RecalcLayout();
[!endif]
	ResizeParentToFit();
[!endif]

[!if LIST_VIEW]

	// TODO: GetListCtrl() �����o�֐��̌Ăяo����ʂ��Ē��ڂ��̃��X�g �R���g���[����
	//  �A�N�Z�X���邱�Ƃɂ���� ListView ���A�C�e���ŌŒ�ł��܂��B
[!if TREE_VIEW]

	// TODO:  GetTreeCtrl() �����o�֐��̌Ăяo����ʂ��Ē��ڂ��̃��X�g �R���g���[����
	//  �A�N�Z�X���邱�Ƃɂ���� TreeView ���A�C�e���ŌŒ�ł��܂��B
[!if HTML_VIEW]
	// TODO: ���̃R�[�h�̓|�s�����[�ȃE�F�b�u �T�C�g�փi�r�Q�[�g���܂�
	// �C�ӂ̃E�F�b�u �T�C�g�ɕύX���Ă�������
[!endif]
[!endif]
[!endif]
[!if HTML_VIEW]
	Navigate2(_T("http://www.msdn.microsoft.com/visualc/"),NULL,NULL);
[!endif]
[!if CONTAINER || CONTAINER_SERVER]
[!if !RICH_EDIT_VIEW]

	// TODO: �ŏI�I�ȑI������̃R�[�h���m�肵���Ƃ��ɂ͂��̃R�[�h�͍폜���Ă��������B
	m_pSelection = NULL;    // �I��͈͂����������܂��B

[!endif]
[!if RICH_EDIT_VIEW]

	// ������̗]����ݒ肵�܂� (720 twips = 1/2 inch).
	SetMargins(CRect(720, 720, 720, 720));
[!endif]
[!endif]
[!if SCROLL_VIEW]
	CSize sizeTotal;
	// TODO: ���̃r���[�̃T�C�Y�̍��v���v�Z���܂��B
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
[!endif]
}
[!endif]
[!if PRINTING]


// [!output VIEW_CLASS] ���

[!if ACTIVE_DOC_CONTAINER]
void [!output VIEW_CLASS]::OnFilePrintPreviewUIUpdate(CCmdUI* pCmdUI)
{
	if (!pCmdUI)
		return;

	if (m_pSelection != NULL)
	{
		DWORD dwStatus = 0;
		if (SUCCEEDED(m_pSelection->QueryCommand(OLECMDID_PRINTPREVIEW, &dwStatus)) &&
			dwStatus & OLECMDF_ENABLED)
		{
				pCmdUI->Enable(TRUE);
				return;
		}
	}
	pCmdUI->Enable(FALSE);

}

void [!output VIEW_CLASS]::OnFilePrintPreview()
{
	if (!m_pSelection)
		return;
	m_pSelection->ExecCommand(OLECMDID_PRINTPREVIEW);

}

[!endif]
[!if !HTML_VIEW && !HTML_EDITVIEW]
BOOL [!output VIEW_CLASS]::OnPreparePrinting(CPrintInfo* pInfo)
{
[!if EDIT_VIEW]
	// �f�t�H���g�� CEditView �̈������
	return CEditView::OnPreparePrinting(pInfo);
[!else]
[!if ACTIVE_DOC_CONTAINER]
	if (!CView::DoPreparePrinting(pInfo))
		return FALSE;
	
	if (!COleDocObjectItem::OnPreparePrinting(this, pInfo))
		return FALSE;

	return TRUE;
[!else]
	// �f�t�H���g�̈������
	return DoPreparePrinting(pInfo);
[!endif]
[!endif]
}

[!if !RICH_EDIT_VIEW]
[!if EDIT_VIEW]
void [!output VIEW_CLASS]::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
[!else]
void [!output VIEW_CLASS]::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
[!endif]
{
[!if EDIT_VIEW]
	// �f�t�H���g�� CEditView �ň�����J�n���܂��B
	CEditView::OnBeginPrinting(pDC, pInfo);
[!else]
	// TODO: ����O�̓��ʂȏ�����������ǉ����Ă��������B
[!endif]
}

[!if EDIT_VIEW]
void [!output VIEW_CLASS]::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
[!else]
void [!output VIEW_CLASS]::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
[!endif]
{
[!if EDIT_VIEW]
	// �f�t�H���g�� CEditView �̈����̌㏈��
	CEditView::OnEndPrinting(pDC, pInfo);
[!else]
	// TODO: �����̌㏈����ǉ����Ă��������B
[!endif]
}
[!endif]
[!endif]
[!if FORM_VIEW || ACTIVE_DOC_CONTAINER]

[!if ACTIVE_DOC_CONTAINER]
void [!output VIEW_CLASS]::OnPrint(CDC* pDC, CPrintInfo* pInfo)
[!else]
void [!output VIEW_CLASS]::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
[!endif]
{
	// TODO: ����p�̃R�[�h�������ɒǉ����Ă��������B
[!if ACTIVE_DOC_CONTAINER]
	if(pInfo->m_bDocObject)
		COleDocObjectItem::OnPrint(this, pInfo, TRUE);
	else
		CView::OnPrint(pDC, pInfo);
[!endif]
}
[!endif]
[!endif]
[!if CONTAINER || CONTAINER_SERVER]

void [!output VIEW_CLASS]::OnDestroy()
{
	// ���Ŏ��ɃA�C�e�����A�N�e�B�x�[�g���܂�; ����͕����r���[��
	// �g�p����Ă���ꍇ�ɂ͏d�v�ł��B
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
   [!output VIEW_BASE_CLASS]::OnDestroy();
}

[!if !RICH_EDIT_VIEW]


// OLE �N���C�A���g �T�|�[�g����уR�}���h

BOOL [!output VIEW_CLASS]::IsSelected(const CObject* pDocItem) const
{
	// [!output CONTAINER_ITEM_CLASS] �I�u�W�F�N�g�����ō\������Ă��鎞�ɂ� 
	//  [!output CONTAINER_ITEM_CLASS] �ȉ��Ɏ������@�ŏ\���ł��B�قȂ�I���������������Ƃ��ɂ�
	//  ���̏ꏊ�����������Ă��������B

	// TODO: ���̊֐��͑I�����ꂽ OLE �N���C�A���g�̃A�C�e���ɑ΂���e�X�g���������܂��B

	return pDocItem == m_pSelection;
}

void [!output VIEW_CLASS]::OnInsertObject()
{
	// �V�K�� [!output CONTAINER_ITEM_CLASS] �I�u�W�F�N�g�̏��𓾂邽�߂�
	//  �W���I�ȃI�u�W�F�N�g�}���_�C�A���O �{�b�N�X���Ăяo���܂��B
	COleInsertDialog dlg;
[!if ACTIVE_DOC_CONTAINER]
	if (dlg.DoModal(COleInsertDialog::DocObjectsOnly) != IDOK)
		return;
[!else]
	if (dlg.DoModal() != IDOK)
		return;
[!endif]

	BeginWaitCursor();

	[!output CONTAINER_ITEM_CLASS]* pItem = NULL;
	TRY
	{
		// ���̃h�L�������g�ɐڑ����ꂽ�V�K�̍��ڂ��쐬���܂��B
		[!output DOC_CLASS]* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pItem = new [!output CONTAINER_ITEM_CLASS](pDoc);
		ASSERT_VALID(pItem);

		// �_�C�A���O �f�[�^���獀�ڂ����������܂��B
		if (!dlg.CreateItem(pItem))
			AfxThrowMemoryException();  // ��O�������s���܂��B
		ASSERT_VALID(pItem);
		
[!if ACTIVE_DOC_CONTAINER]
		pItem->DoVerb(OLEIVERB_SHOW, this);
[!else]
        if (dlg.GetSelectionType() == COleInsertDialog::createNewItem)
			pItem->DoVerb(OLEIVERB_SHOW, this);
[!endif]

		ASSERT_VALID(pItem);
		// �b��I�ȃ��[�U�[ �C���^�[�t�F�C�X�̃f�U�C���Ƃ��čŌ�ɑ}�����ꂽ
		// �A�C�e����I�����Ă��܂��B

		// TODO: �A�v���P�[�V�����ɓK���ȑI������ɂ��킹�ď��������Ă��������B
		m_pSelection = pItem;   // �Ō�ɑ}�����ꂽ�A�C�e����I��
		pDoc->UpdateAllViews(NULL);
	}
	CATCH(CException, e)
	{
		if (pItem != NULL)
		{
			ASSERT_VALID(pItem);
			pItem->Delete();
		}
		AfxMessageBox(IDP_FAILED_TO_CREATE);
	}
	END_CATCH

	EndWaitCursor();
}

// �ȉ��Ɏ����R�}���h �n���h���͑g�ݍ��ݐ�ҏW�𒆎~���邽�߂̕W���I��
// �L�[�{�[�h ���[�U�[ �C���^�[�t�F�C�X��p�ӂ��Ă��܂��B�����ł̓R���e�i
// (�T�[�o�[�ł͂Ȃ�)����A�N�e�B�u���������N�����܂��B
void [!output VIEW_CLASS]::OnCancelEditCntr()
{
	// ���̃r���[��ɂ���g�ݍ��ݐ�ŗL���ȃA�C�e������܂��B
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
	{
		pActiveItem->Close();
	}
	ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
}

// �I�u�W�F�N�g���g�ݍ��ݐ�ŕҏW����͂��߂��Ƃ��ɂ� OnSetFocus �� OnSize �̓��ʂ�
// �n���h�����O�ɂ̓R���e�i���K�v�ł��B
void [!output VIEW_CLASS]::OnSetFocus(CWnd* pOldWnd)
{
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL &&
		pActiveItem->GetItemState() == COleClientItem::activeUIState)
	{
		// �����r���[�ɂ���A�C�e���ɂ̓t�H�[�J�X��ݒ肷��K�v������܂��B
		CWnd* pWnd = pActiveItem->GetInPlaceWindow();
		if (pWnd != NULL)
		{
			pWnd->SetFocus();   // ��{�N���X���Ăяo���܂���B
			return;
		}
	}

	[!output VIEW_BASE_CLASS]::OnSetFocus(pOldWnd);
}

void [!output VIEW_CLASS]::OnSize(UINT nType, int cx, int cy)
{
	[!output VIEW_BASE_CLASS]::OnSize(nType, cx, cy);
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
		pActiveItem->SetItemRects();
}

void [!output VIEW_CLASS]::OnFilePrint()
{
	//����ł́AActive �h�L�������g�́AIOleCommandTarget ���g����
	//�������܂��B���̓��삪�s�v�ȏꍇ�́A
	//COleDocObjectItem::DoDefaultPrinting �ւ̌Ăяo�����폜���Ă��������B
	//�Ăяo�������s�����ꍇ�́AIPrint �C���^�[�t�F�C�X���g����
	//docobject ��������܂��B
	CPrintInfo printInfo;
	ASSERT(printInfo.m_pPD != NULL); 
	if (S_OK == COleDocObjectItem::DoDefaultPrinting(this, &printInfo))
		return;
	
	CView::OnFilePrint();

}

[!endif]
[!endif]
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]


// OLE Server �T�|�[�g

// �ȉ��Ɏ����R�}���h �n���h���͑g�ݍ��ݐ�ҏW�𒆎~���邽�߂̕W���I��
// �L�[�{�[�h ���[�U�[ �C���^�[�t�F�C�X��p�ӂ��Ă��܂��B�����ł̓R���e�i
// (�T�[�o�[�ł͂Ȃ�)����A�N�e�B�u���������N�����܂��B
void [!output VIEW_CLASS]::OnCancelEditSrvr()
{
	GetDocument()->OnDeactivateUI(FALSE);
}
[!endif]


// [!output VIEW_CLASS] �f�f

#ifdef _DEBUG
void [!output VIEW_CLASS]::AssertValid() const
{
	[!output VIEW_BASE_CLASS]::AssertValid();
}

void [!output VIEW_CLASS]::Dump(CDumpContext& dc) const
{
	[!output VIEW_BASE_CLASS]::Dump(dc);
}

[!output DOC_CLASS]* [!output VIEW_CLASS]::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS([!output DOC_CLASS])));
	return ([!output DOC_CLASS]*)m_pDocument;
}
#endif //_DEBUG
[!if OLEDB_RECORD_VIEW]


// [!output VIEW_CLASS] �f�[�^�x�[�X �T�|�[�g
CRowset<>* [!output VIEW_CLASS]::OnGetRowset()
{
	return m_pSet->GetRowsetBase();
}

[!endif]
[!if ODBC_RECORD_VIEW]


// [!output VIEW_CLASS] �f�[�^�x�[�X �T�|�[�g
CRecordset* [!output VIEW_CLASS]::OnGetRecordset()
{
	return m_pSet;
}

[!endif]


// [!output VIEW_CLASS] ���b�Z�[�W �n���h��
[!if PROJECT_STYLE_EXPLORER]
[!if LIST_VIEW]
void [!output VIEW_CLASS]::OnStyleChanged(int /*nStyleType*/, LPSTYLESTRUCT /*lpStyleStruct*/)
{
	// TODO: ���[�U�[�ɂ��E�C���h�E�̃r���[ �X�^�C���ύX�ɑΉ�����R�[�h��ǉ����Ă�������
	
	Default();
}
[!endif]
[!endif]
