// [!output VIEW_IMPL] : [!output VIEW_CLASS] Ŭ������ ����
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
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, [!output VIEW_BASE_CLASS]::OnFilePrint)
[!endif]
[!endif]
[!else]
[!if PRINTING]
	// ǥ�� �μ� ����Դϴ�.
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
// [!output VIEW_CLASS] ����/�Ҹ�

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
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

[!output VIEW_CLASS]::~[!output VIEW_CLASS]()
{
}
[!if FORM_VIEW || OLEDB_RECORD_VIEW || ODBC_RECORD_VIEW]

void [!output VIEW_CLASS]::DoDataExchange(CDataExchange* pDX)
{
	[!output VIEW_BASE_CLASS]::DoDataExchange(pDX);
[!if ODBC_RECORD_VIEW]
	// ��Ʈ���� �����ͺ��̽� �ʵ忡 '����'�ϱ� ���� ���⿡ DDX_Field* �Լ��� ������ �� �ֽ��ϴ�. ��:
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �ڼ��� ������ MSDN �� ODBC ������ �����Ͻʽÿ�.
[!endif]
[!if OLEDB_RECORD_VIEW]
	// SetDlgItem*/GetDlgItem* API ȣ��� �ƴ϶� DDX_* �Լ��� �����Ͽ� �����ͺ��̽��� �信 ������ �� �ֽ��ϴ�.
	// ��: ::SetDlgItemText(m_hWnd, IDC_MYCONTROL, m_pSet->m_MyColumn);
	// �ڼ��� ������ MSDN �� OLEDB ������ �����Ͻʽÿ�.
[!endif]
}
[!endif]

BOOL [!output VIEW_CLASS]::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	// Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

[!if EDIT_VIEW]
	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// �ڵ� �ٹٲ��� ����մϴ�.

	return bPreCreated;
[!else]
	return [!output VIEW_BASE_CLASS]::PreCreateWindow(cs);
[!endif]
}
[!if !TREE_VIEW && !LIST_VIEW && !HTML_VIEW && !HTML_EDITVIEW && !RICH_EDIT_VIEW && !EDIT_VIEW && !FORM_VIEW && !OLEDB_RECORD_VIEW && !ODBC_RECORD_VIEW]

// [!output VIEW_CLASS] �׸���
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

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	// TODO: ������ ��� OLE �׸� �׸��ϴ�.

	// ������ ��ġ�� ���� ������ �׸��ϴ�. �� �ڵ�� ���� �׸��� �ڵ尡 �����Ǹ�
	// �����ؾ� �մϴ�. �� ��ġ�� [!output CONTAINER_ITEM_CLASS]���� ��ȯ�ϴ� �簢���� ��Ȯ�� �����ϸ�
	// ���� ���� ȿ���� �����մϴ�.

	// TODO: ������ �׸��� �ڵ尡 �Ϸ�Ǹ� �� �ڵ带 �����մϴ�.
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

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}[!endif]
[!else]

void [!output VIEW_CLASS]::OnDraw(CDC* /*pDC*/)
{
	[!output DOC_CLASS]* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}
[!endif]
[!endif] 
[!if PRINTING]
[!if TREE_VIEW || LIST_VIEW]


void [!output VIEW_CLASS]::OnDraw(CDC* /*pDC*/)
{
	[!output DOC_CLASS]* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
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
			// ���ڵ� ������ ���� ���߽��ϴ�. ���ڵ� ������ ����
			// ���ν����� ��� OpenAll()�� ȣ���ϱ� ���� �Է�
			// �Ű� ������ ����� �ʱ�ȭ�ߴ��� Ȯ���Ͻʽÿ�.

			AfxMessageBox(_T("���ڵ� ������ ���� ���߽��ϴ�."), MB_OK);
			// ���� RowSet ���� ���� ���ڵ��� ������ �õ��ϸ� �浹�� ��
			// �ֱ� ������ ���� �� ���� ���ڵ� ����� ��Ȱ��ȭ�մϴ�.
			m_bOnFirstRecord = TRUE;
			m_bOnLastRecord = TRUE;
		}
		if( hr == DB_S_ENDOFROWSET )
		{
			// �� ������ ��� �ֽ��ϴ�(���� ���ԵǾ� ���� ����).
			AfxMessageBox(_T("���ڵ� ������ �������� ��ȯ�� ���� �������ϴ�."), MB_OK);
			// ���� �� ���� ���ڵ� ����� ��Ȱ��ȭ�մϴ�.
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

	// TODO: GetListCtrl()�� ȣ���Ͽ� �ش� list ��Ʈ���� ���� �׼��������ν�
	// ListView�� �׸����� ä�� �� �ֽ��ϴ�.
[!if TREE_VIEW]

	// TODO: GetTreeCtrl()�� ȣ���Ͽ� �ش� tree ��Ʈ���� ���� �׼����ϸ�
	// TreeView�� �׸����� ä�� �� �ֽ��ϴ�.
[!if HTML_VIEW]
	// TODO: �� �ڵ�� �� ���� �α��ִ� ����Ʈ�� Ž���մϴ�.
	// ���ϴ� ����Ʈ�� ������ �ڵ带 �����Ͻʽÿ�.
[!endif]
[!endif]
[!endif]
[!if HTML_VIEW]
	Navigate2(_T("http://www.msdn.microsoft.com/visualc/"),NULL,NULL);
[!endif]
[!if CONTAINER || CONTAINER_SERVER]
[!if !RICH_EDIT_VIEW]

	// TODO: ������ ���� �� �ڵ尡 �ۼ��Ǹ� �� �ڵ带 �����մϴ�.
	m_pSelection = NULL;    //���� ������ �ʱ�ȭ�մϴ�.

[!endif]
[!if RICH_EDIT_VIEW]

	// �μ� ����(720 twips = 1/2 inch)�� �����մϴ�.
	SetMargins(CRect(720, 720, 720, 720));
[!endif]
[!endif]
[!if SCROLL_VIEW]
	CSize sizeTotal;
	// TODO: �� ���� ��ü ũ�⸦ ����մϴ�.
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
[!endif]
}
[!endif]
[!if PRINTING]


// [!output VIEW_CLASS] �μ�

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
	// �⺻���� CEditView �غ�
	return CEditView::OnPreparePrinting(pInfo);
[!else]
[!if ACTIVE_DOC_CONTAINER]
	if (!CView::DoPreparePrinting(pInfo))
		return FALSE;
	
	if (!COleDocObjectItem::OnPreparePrinting(this, pInfo))
		return FALSE;

	return TRUE;
[!else]
	// �⺻���� �غ�
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
	// �⺻ CEditView ���� �μ�
	CEditView::OnBeginPrinting(pDC, pInfo);
[!else]
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
[!endif]
}

[!if EDIT_VIEW]
void [!output VIEW_CLASS]::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
[!else]
void [!output VIEW_CLASS]::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
[!endif]
{
[!if EDIT_VIEW]
	// �⺻ CEditView ���� �μ�
	CEditView::OnEndPrinting(pDC, pInfo);
[!else]
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
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
	// TODO: ���⿡ ����� ���� �μ� �ڵ带 �߰��մϴ�.
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
	// �Ҹ� ���� �׸��� ��Ȱ��ȭ�մϴ�.
	// ���� â�� ���� ��� �� �۾��� �߿��մϴ�.
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
   [!output VIEW_BASE_CLASS]::OnDestroy();
}

[!if !RICH_EDIT_VIEW]


// OLE Ŭ���̾�Ʈ ���� �� ���

BOOL [!output VIEW_CLASS]::IsSelected(const CObject* pDocItem) const
{
	// �Ʒ� ������ ������ [!output CONTAINER_ITEM_CLASS] ��ü�θ�
	// �̷���� ��� �����մϴ�. �ٸ� ���� ��Ŀ������
	// ó���Ϸ��� �� ������ �ٲ�� �մϴ�.

	// TODO: ���õ� OLE Ŭ���̾�Ʈ �׸��� �׽�Ʈ�ϴ� �� �Լ��� �����մϴ�.

	return pDocItem == m_pSelection;
}

void [!output VIEW_CLASS]::OnInsertObject()
{
	// ǥ�� ��ü ���� ��ȭ ���ڸ� ȣ���Ͽ� �� [!output CONTAINER_ITEM_CLASS] ��ü�� ���� ������ ����ϴ�.
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
		// �� ������ ����� �� �׸��� ����ϴ�.
		[!output DOC_CLASS]* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pItem = new [!output CONTAINER_ITEM_CLASS](pDoc);
		ASSERT_VALID(pItem);

		// ��ȭ ���ڿ� �ִ� ������ �׸��� �ʱ�ȭ�մϴ�.
		if (!dlg.CreateItem(pItem))
			AfxThrowMemoryException();  // ��� ���ܿ��� ����˴ϴ�.
		ASSERT_VALID(pItem);
		
[!if ACTIVE_DOC_CONTAINER]
		pItem->DoVerb(OLEIVERB_SHOW, this);
[!else]
        if (dlg.GetSelectionType() == COleInsertDialog::createNewItem)
			pItem->DoVerb(OLEIVERB_SHOW, this);
[!endif]

		ASSERT_VALID(pItem);
		// ������ ����� �������̽� ����������, ���� ������ ���Ե� ������ �׸�����
		// �����մϴ�.

		// TODO: ���� ���α׷��� �°� ���� ������ �ٽ� �����մϴ�.
		m_pSelection = pItem;   // ���� ������ ���������� ���Ե� �׸����� �����մϴ�.
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

// ���� ��� ó����� ǥ�� Ű���� ����� �������̽��� �����Ͽ�
// ���� ���� ������ ����մϴ�. �׷���
// �����̳�(������ �ƴ�)�� ��Ȱ��ȭ�˴ϴ�.
void [!output VIEW_CLASS]::OnCancelEditCntr()
{
	// �� �信 �ִ� ���� Ȱ�� �׸��� �ݽ��ϴ� .
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
	{
		pActiveItem->Close();
	}
	ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
}

// ��ü�� ���� �����Ϸ��� �� ��� �����̳ʿ��� OnSetFocus ��
// OnSize�� ���� Ư���� ó���� �ʿ��մϴ�.
void [!output VIEW_CLASS]::OnSetFocus(CWnd* pOldWnd)
{
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL &&
		pActiveItem->GetItemState() == COleClientItem::activeUIState)
	{
		// ���� �信 ���� ��� �� �׸� ��Ŀ���� �����ؾ� �մϴ�.
		CWnd* pWnd = pActiveItem->GetInPlaceWindow();
		if (pWnd != NULL)
		{
			pWnd->SetFocus();   // �⺻ Ŭ������ ȣ������ �ʽ��ϴ�.
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
	//�⺻������ ��Ƽ�� ������
	// IOleCommandTarget�� ����Ͽ� ��ü������ �μ�ǵ��� ��û�մϴ�. �� ������ ������ ���� ���
	// COleDocObjectItem::DoDefaultPrinting�� ���� ȣ���� �����Ͻʽÿ�.
	// � ������ ���� ȣ���� �����ϸ� 
	//IPrint �������̽��� ����Ͽ� docobject�� �μ⸦ �õ��� �� �ֽ��ϴ�.
	CPrintInfo printInfo;
	ASSERT(printInfo.m_pPD != NULL); 
	if (S_OK == COleDocObjectItem::DoDefaultPrinting(this, &printInfo))
		return;
	
	CView::OnFilePrint();

}

[!endif]
[!endif]
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]


// OLE ���� ����

// ���� ��� ó����� ǥ�� Ű���� ����� �������̽��� �����Ͽ�
// ���� ���� ������ ����մϴ�. �׷���
// ����(�����̳ʰ� �ƴ�)�� ��Ȱ��ȭ�˴ϴ�.
void [!output VIEW_CLASS]::OnCancelEditSrvr()
{
	GetDocument()->OnDeactivateUI(FALSE);
}
[!endif]


// [!output VIEW_CLASS] ����

#ifdef _DEBUG
void [!output VIEW_CLASS]::AssertValid() const
{
	[!output VIEW_BASE_CLASS]::AssertValid();
}

void [!output VIEW_CLASS]::Dump(CDumpContext& dc) const
{
	[!output VIEW_BASE_CLASS]::Dump(dc);
}

[!output DOC_CLASS]* [!output VIEW_CLASS]::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS([!output DOC_CLASS])));
	return ([!output DOC_CLASS]*)m_pDocument;
}
#endif //_DEBUG
[!if OLEDB_RECORD_VIEW]


// [!output VIEW_CLASS] �����ͺ��̽� ����
CRowset<>* [!output VIEW_CLASS]::OnGetRowset()
{
	return m_pSet->GetRowsetBase();
}

[!endif]
[!if ODBC_RECORD_VIEW]


// [!output VIEW_CLASS] �����ͺ��̽� ����
CRecordset* [!output VIEW_CLASS]::OnGetRecordset()
{
	return m_pSet;
}

[!endif]


// [!output VIEW_CLASS] �޽��� ó����
[!if PROJECT_STYLE_EXPLORER]
[!if LIST_VIEW]
void [!output VIEW_CLASS]::OnStyleChanged(int /*nStyleType*/, LPSTYLESTRUCT /*lpStyleStruct*/)
{
	//TODO: ����ڰ� â�� �� ��Ÿ���� �������� �� �����ϴ� �ڵ带 �߰��մϴ�.
	
	Default();
}
[!endif]
[!endif]
