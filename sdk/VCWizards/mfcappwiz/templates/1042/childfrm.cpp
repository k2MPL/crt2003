// [!output CHILD_FRAME_IMPL] : [!output CHILD_FRAME_CLASS] Ŭ������ ����
//
#include "stdafx.h"
#include "[!output APP_HEADER]"

#include "[!output CHILD_FRAME_HEADER]"
[!if PROJECT_STYLE_EXPLORER]
#include "[!output TREE_VIEW_HEADER]"
#include "[!output VIEW_HEADER]"
[!endif]

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// [!output CHILD_FRAME_CLASS]

IMPLEMENT_DYNCREATE([!output CHILD_FRAME_CLASS], [!output CHILD_FRAME_BASE_CLASS])

BEGIN_MESSAGE_MAP([!output CHILD_FRAME_CLASS], [!output CHILD_FRAME_BASE_CLASS])
[!if !DOCVIEW]
	ON_COMMAND(ID_FILE_CLOSE, OnFileClose)
	ON_WM_SETFOCUS()
	ON_WM_CREATE()
[!endif]
[!if PROJECT_STYLE_EXPLORER]
[!if LIST_VIEW]
	ON_UPDATE_COMMAND_UI_RANGE(AFX_ID_VIEW_MINIMUM, AFX_ID_VIEW_MAXIMUM, OnUpdateViewStyles)
	ON_COMMAND_RANGE(AFX_ID_VIEW_MINIMUM, AFX_ID_VIEW_MAXIMUM, OnViewStyle)
[!endif]
[!endif]
END_MESSAGE_MAP()


// [!output CHILD_FRAME_CLASS] ����/�Ҹ�

[!output CHILD_FRAME_CLASS]::[!output CHILD_FRAME_CLASS]()
{
[!if ACCESSIBILITY]
	EnableActiveAccessibility();
[!endif]
	// TODO: ���⿡ ��� �ʱ�ȭ �ڵ带 �߰��մϴ�.
}

[!output CHILD_FRAME_CLASS]::~[!output CHILD_FRAME_CLASS]()
{
}

[!if APP_TYPE_MDI && SPLITTER]
BOOL [!output CHILD_FRAME_CLASS]::OnCreateClient(LPCREATESTRUCT /*lpcs*/, CCreateContext* pContext)
{
[!if PROJECT_STYLE_EXPLORER]
	// ���� â�� ����ϴ�.
	if (!m_wndSplitter.CreateStatic(this, 1, 2))
		return FALSE;

	if (!m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS([!output TREE_VIEW_CLASS]), CSize(100, 100), pContext) ||
		!m_wndSplitter.CreateView(0, 1, RUNTIME_CLASS([!output VIEW_CLASS]), CSize(100, 100), pContext))
	{
		m_wndSplitter.DestroyWindow();
		return FALSE;
	}
	return TRUE;
[!else]
[!if HTML_VIEW || HTML_EDITVIEW]
	return m_wndSplitter.Create(this,
		2, 2,			// TODO: �� �� ���� ������ �����մϴ�.
		CSize(10, 10),	// TODO: �ּ� â ũ�⸦ �����մϴ�.
		pContext, WS_CHILD | WS_VISIBLE | SPLS_DYNAMIC_SPLIT);
[!else]
	return m_wndSplitter.Create(this,
		2, 2,			// TODO: �� �� ���� ������ �����մϴ�.
		CSize(10, 10),	// TODO: �ּ� â ũ�⸦ �����մϴ�.
		pContext);
[!endif]
[!endif]
}
[!else]
[!if PROJECT_STYLE_EXPLORER]
BOOL [!output CHILD_FRAME_CLASS]::OnCreateClient(LPCREATESTRUCT /*lpcs*/, CCreateContext* pContext)
{
	// ���� â�� ����ϴ�.
	if (!m_wndSplitter.CreateStatic(this, 1, 2))
		return FALSE;

	if (!m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS([!output TREE_VIEW_CLASS]), CSize(100, 100), pContext) ||
		!m_wndSplitter.CreateView(0, 1, RUNTIME_CLASS([!output VIEW_CLASS]), CSize(100, 100), pContext))
	{
		m_wndSplitter.DestroyWindow();
		return FALSE;
	}
	return TRUE;
}
[!endif]
[!endif]

BOOL [!output CHILD_FRAME_CLASS]::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡�� Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.
	if( ![!output CHILD_FRAME_BASE_CLASS]::PreCreateWindow(cs) )
		return FALSE;

[!if !CHILD_FRAME_DEFAULT_STYLES]
	cs.style = WS_CHILD | WS_VISIBLE | WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU
		| FWS_ADDTOTITLE[!output CHILD_FRAME_STYLE_FLAGS];

[!endif]
[!if !DOCVIEW]
	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
[!endif]
	return TRUE;
}


// [!output CHILD_FRAME_CLASS] ����

#ifdef _DEBUG
void [!output CHILD_FRAME_CLASS]::AssertValid() const
{
	[!output CHILD_FRAME_BASE_CLASS]::AssertValid();
}

void [!output CHILD_FRAME_CLASS]::Dump(CDumpContext& dc) const
{
	[!output CHILD_FRAME_BASE_CLASS]::Dump(dc);
}

#endif //_DEBUG


// [!output CHILD_FRAME_CLASS] �޽��� ó����
[!if PROJECT_STYLE_EXPLORER]
[!if LIST_VIEW]
[!output VIEW_CLASS]* [!output CHILD_FRAME_CLASS]::GetRightPane()
{
	CWnd* pWnd = m_wndSplitter.GetPane(0, 1);
	[!output VIEW_CLASS]* pView = DYNAMIC_DOWNCAST([!output VIEW_CLASS], pWnd);
	return pView;
}

void [!output CHILD_FRAME_CLASS]::OnUpdateViewStyles(CCmdUI* pCmdUI)
{
	if (!pCmdUI)
		return;

	// TODO: �� �ڵ带 ����� �����ϰų� Ȯ���Ͽ� [����] �޴������� ������ ó���մϴ�.
	[!output VIEW_CLASS]* pView = GetRightPane(); 

	// ������ â�� ��������� �ʾҰų� �䰡 �ƴ� ��� �ش� ������ �ִ� ����� ��Ȱ��ȭ�մϴ�.
	if (pView == NULL)
		pCmdUI->Enable(FALSE);
	else
	{
		DWORD dwStyle = pView->GetStyle() & LVS_TYPEMASK;
		// ����� ID_VIEW_LINEUP�̸� LVS_ICON �Ǵ� LVS_SMALLICON ����� ��쿡��
		// �� ����� Ȱ��ȭ�մϴ�.
		if (pCmdUI->m_nID == ID_VIEW_LINEUP)
		{
			if (dwStyle == LVS_ICON || dwStyle == LVS_SMALLICON)
				pCmdUI->Enable();
			else
				pCmdUI->Enable(FALSE);
		}
		else
		{
			// �׷��� ������ ���� ����Ͽ� ���� ��Ÿ���� �ݿ��մϴ�.
			pCmdUI->Enable();
			BOOL bChecked = FALSE;

			switch (pCmdUI->m_nID)
			{
			case ID_VIEW_DETAILS:
				bChecked = (dwStyle == LVS_REPORT);
				break;

			case ID_VIEW_SMALLICON:
				bChecked = (dwStyle == LVS_SMALLICON);
				break;

			case ID_VIEW_LARGEICON:
				bChecked = (dwStyle == LVS_ICON);
				break;

			case ID_VIEW_LIST:
				bChecked = (dwStyle == LVS_LIST);
				break;

			default:
				bChecked = FALSE;
				break;
			}

			pCmdUI->SetRadio(bChecked ? 1 : 0);
		}
	}
}

void [!output CHILD_FRAME_CLASS]::OnViewStyle(UINT nCommandID)
{
	// TODO: �� �ڵ带 ����� �����ϰų� Ȯ���Ͽ� [����] �޴������� ������ ó���մϴ�.
	[!output VIEW_CLASS]* pView = GetRightPane();

	// ������ â�� ��������� [!output VIEW_CLASS]�̸� �޴� ����� ó���մϴ�.
	if (pView != NULL)
	{
		int nStyle = -1;

		switch (nCommandID)
		{
		case ID_VIEW_LINEUP:
			{
				// list ��Ʈ���� �𴫿� ����ϴ�.
				CListCtrl& refListCtrl = pView->GetListCtrl();
				refListCtrl.Arrange(LVA_SNAPTOGRID);
			}
			break;

		// �ٸ� ��ɿ��� list ��Ʈ���� ��Ÿ���� �����մϴ�.
		case ID_VIEW_DETAILS:
			nStyle = LVS_REPORT;
			break;

		case ID_VIEW_SMALLICON:
			nStyle = LVS_SMALLICON;
			break;

		case ID_VIEW_LARGEICON:
			nStyle = LVS_ICON;
			break;

		case ID_VIEW_LIST:
			nStyle = LVS_LIST;
			break;
		}

		// ��Ÿ���� �����մϴ�. â�� �ڵ����� �ٽ� �׷����ϴ�.
		if (nStyle != -1)
			pView->ModifyStyle(LVS_TYPEMASK, nStyle);
	}
}
[!endif]
[!endif]
[!if !DOCVIEW]
void [!output CHILD_FRAME_CLASS]::OnFileClose() 
{
	// �������� �������� WM_CLOSE�� ������ �˴ϴ�. �ý��� �޴����� �ݱ⸦ �����ϴ� �Ͱ� 
	// �����մϴ�.
	SendMessage(WM_CLOSE);
}

int [!output CHILD_FRAME_CLASS]::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CMDIChildWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// �������� Ŭ���̾�Ʈ ������ �����ϴ� �並 ����ϴ�.
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW, 
		CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("���� â�� ������ ���߽��ϴ�.\n");
		return -1;
	}

	return 0;
}

void [!output CHILD_FRAME_CLASS]::OnSetFocus(CWnd* pOldWnd) 
{
	CMDIChildWnd::OnSetFocus(pOldWnd);

	m_wndView.SetFocus();
}

BOOL [!output CHILD_FRAME_CLASS]::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) 
{
	// �信�� ù° ũ���� �ش� ��ɿ� ��Ÿ������ �մϴ�.
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;
	
	// �׷��� ������ �⺻ ó���մϴ�.
	return CMDIChildWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}
[!endif]
