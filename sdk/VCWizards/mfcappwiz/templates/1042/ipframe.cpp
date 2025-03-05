// [!output INPLACE_FRAME_IMPL] : [!output INPLACE_FRAME_CLASS] Ŭ������ ����
//

#include "stdafx.h"
#include "[!output APP_HEADER]"

#include "[!output INPLACE_FRAME_HEADER]"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// [!output INPLACE_FRAME_CLASS]

IMPLEMENT_DYNCREATE([!output INPLACE_FRAME_CLASS], [!output INPLACE_FRAME_BASE_CLASS])

BEGIN_MESSAGE_MAP([!output INPLACE_FRAME_CLASS], [!output INPLACE_FRAME_BASE_CLASS])
	ON_WM_CREATE()
[!if CONTEXT_HELP]
	// ���� ���� ���
	ON_COMMAND(ID_HELP_FINDER, [!output INPLACE_FRAME_BASE_CLASS]::OnHelpFinder)
	ON_COMMAND(ID_HELP, [!output INPLACE_FRAME_BASE_CLASS]::OnHelp)
	ON_COMMAND(ID_DEFAULT_HELP, [!output INPLACE_FRAME_BASE_CLASS]::OnHelpFinder)
	ON_COMMAND(ID_CONTEXT_HELP, [!output INPLACE_FRAME_BASE_CLASS]::OnContextHelp)
[!endif]
END_MESSAGE_MAP()


// [!output INPLACE_FRAME_CLASS] ����/�Ҹ�

[!output INPLACE_FRAME_CLASS]::[!output INPLACE_FRAME_CLASS]()
{
[!if ACCESSIBILITY]
	EnableActiveAccessibility();
[!endif]
}

[!output INPLACE_FRAME_CLASS]::~[!output INPLACE_FRAME_CLASS]()
{
}

int [!output INPLACE_FRAME_CLASS]::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if ([!output INPLACE_FRAME_BASE_CLASS]::OnCreate(lpCreateStruct) == -1)
		return -1;

	// CResizeBar�� ���� ũ�� ������ �����մϴ�.
	if (!m_wndResizeBar.Create(this))
	{
		TRACE0("ũ�� ���� ���븦 ������ ���߽��ϴ�.\n");
		return -1;      // ������ ���߽��ϴ�.
	}

	// �⺻������, ���� ����� ������� â �����Ӱ� ������ ���� ������
	// ����ϴ� ���� �����ϴ�. �̷��� �ϸ� ��� ���⸦ �����ϴ�
	// �����̳ʿ� ���� �۾��� "����"���� �ʽ��ϴ�.
	m_dropTarget.Register(this);

	return 0;
}

[!if DOCKING_TOOLBAR]
// �����̳� ���� ���α׷��� â�� ��Ʈ�� ������ ����� ���� �����ӿ�ũ����
// OnCreateControlBars�� ȣ���մϴ�. pWndFrame�� �����̳��� �ֻ��� ���� ������ â�̸�
// �׻� NULL�� �ƴ� ���� �����ϴ�. pWndDoc�� ���� ���� ������ â����
// �����̳ʰ� SDI ���� ���α׷��� ���
// NULL�� �˴ϴ�. ���� ���� ���α׷��� �� â �� �ϳ��� MFC ��Ʈ�� ������
// ��ġ�� �� �ֽ��ϴ�.
BOOL [!output INPLACE_FRAME_CLASS]::OnCreateControlBars(CFrameWnd* pWndFrame, CFrameWnd* pWndDoc)
{
	// pWndDoc�� ����� ��쿡�� �� ���� �����Ͻʽÿ�.
	UNREFERENCED_PARAMETER(pWndDoc);

	// �� â�� ���� �����ڸ� �����ϹǷ� �޽����� �ùٸ� ���� ���α׷��� ���޵˴ϴ�.
	m_wndToolBar.SetOwner(this);

	// Ŭ���̾�Ʈ�� ������ â�� ���� ������ ����ϴ�.
[!if TOOLBAR_STYLE_REBAR]
	if (!m_wndToolBar.CreateEx(pWndFrame) ||
[!else]
	if (!m_wndToolBar.CreateEx(pWndFrame, TBSTYLE_FLAT,WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
[!endif]
[!if APP_TYPE_MDI]
		!m_wndToolBar.LoadToolBar(IDR_[!output SAFE_DOC_TYPE_NAME]TYPE_SRVR_IP))
[!else]
		!m_wndToolBar.LoadToolBar(IDR_SRVR_INPLACE))
[!endif]
	{
		TRACE0("���� ������ ������ ���߽��ϴ�.\n");
		return FALSE;
	}

[!if TOOLBAR_STYLE_REBAR]
	// �� â�� ���� �����ڸ� �����ϹǷ� �޽����� �ùٸ� ���� ���α׷��� ���޵˴ϴ�.
	m_wndDlgBar.SetOwner(this);

	// Ŭ���̾�Ʈ�� ������ â�� ��ȭ ���� ������ ����ϴ�.
[!if APP_TYPE_MDI]
	if (!m_wndDlgBar.Create(pWndFrame, IDR_[!output SAFE_DOC_TYPE_NAME]TYPE_SRVR_IP, 
[!else]
	if (!m_wndDlgBar.Create(pWndFrame, IDR_SRVR_INPLACE,
[!endif]
		CBRS_ALIGN_TOP, AFX_IDW_DIALOGBAR))
	{
		TRACE0("��ȭ ���� ������ ������ ���߽��ϴ�.\n");
		return FALSE;
	}

	// �� â�� �����ڸ� �����ϹǷ� �޽����� �ùٸ� ���� ���α׷��� ���޵˴ϴ�.
	m_wndReBar.SetOwner(this);

	// Ŭ���̾�Ʈ�� ������ â�� ũ�� ���� ���븦 ����ϴ�.
	if (!m_wndReBar.Create(pWndFrame) ||
		!m_wndReBar.AddBar(&m_wndToolBar) ||
		!m_wndReBar.AddBar(&m_wndDlgBar))
	{
		TRACE0("ũ�� ���� ���븦 ������ ���߽��ϴ�.\n");
		return FALSE;
	}

	// TODO: ���� ������ ǥ������ �������� �� ���� �����Ͻʽÿ�.
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY);
	m_wndDlgBar.SetBarStyle(m_wndDlgBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY);
[!else]
	// TODO: ���� ������ ��ŷ�� �� ���� �Ϸ��� �� �� ���� �����Ͻʽÿ�.
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	pWndFrame->EnableDocking(CBRS_ALIGN_ANY);
	pWndFrame->DockControlBar(&m_wndToolBar);
[!endif]

	return TRUE;
}

[!endif]
BOOL [!output INPLACE_FRAME_CLASS]::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡�� Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return [!output INPLACE_FRAME_BASE_CLASS]::PreCreateWindow(cs);
}


// [!output INPLACE_FRAME_CLASS] ����

#ifdef _DEBUG
void [!output INPLACE_FRAME_CLASS]::AssertValid() const
{
	[!output INPLACE_FRAME_BASE_CLASS]::AssertValid();
}

void [!output INPLACE_FRAME_CLASS]::Dump(CDumpContext& dc) const
{
	[!output INPLACE_FRAME_BASE_CLASS]::Dump(dc);
}
#endif //_DEBUG


// [!output INPLACE_FRAME_CLASS] ���
