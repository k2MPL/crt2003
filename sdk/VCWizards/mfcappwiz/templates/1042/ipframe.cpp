// [!output INPLACE_FRAME_IMPL] : [!output INPLACE_FRAME_CLASS] 클래스의 구현
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
	// 전역 도움말 명령
	ON_COMMAND(ID_HELP_FINDER, [!output INPLACE_FRAME_BASE_CLASS]::OnHelpFinder)
	ON_COMMAND(ID_HELP, [!output INPLACE_FRAME_BASE_CLASS]::OnHelp)
	ON_COMMAND(ID_DEFAULT_HELP, [!output INPLACE_FRAME_BASE_CLASS]::OnHelpFinder)
	ON_COMMAND(ID_CONTEXT_HELP, [!output INPLACE_FRAME_BASE_CLASS]::OnContextHelp)
[!endif]
END_MESSAGE_MAP()


// [!output INPLACE_FRAME_CLASS] 생성/소멸

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

	// CResizeBar는 내부 크기 조정을 구현합니다.
	if (!m_wndResizeBar.Create(this))
	{
		TRACE0("크기 조정 막대를 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}

	// 기본적으로, 놓기 대상이 사용자의 창 프레임과 관련이 없는 것으로
	// 등록하는 것이 좋습니다. 이렇게 하면 끌어서 놓기를 지원하는
	// 컨테이너에 놓는 작업이 "실패"하지 않습니다.
	m_dropTarget.Register(this);

	return 0;
}

[!if DOCKING_TOOLBAR]
// 컨테이너 응용 프로그램의 창에 컨트롤 모음을 만들기 위해 프레임워크에서
// OnCreateControlBars를 호출합니다. pWndFrame은 컨테이너의 최상위 수준 프레임 창이며
// 항상 NULL이 아닌 값을 가집니다. pWndDoc는 문서 수준 프레임 창으로
// 컨테이너가 SDI 응용 프로그램일 경우
// NULL이 됩니다. 서버 응용 프로그램은 두 창 중 하나에 MFC 컨트롤 모음을
// 배치할 수 있습니다.
BOOL [!output INPLACE_FRAME_CLASS]::OnCreateControlBars(CFrameWnd* pWndFrame, CFrameWnd* pWndDoc)
{
	// pWndDoc를 사용할 경우에는 이 줄을 제거하십시오.
	UNREFERENCED_PARAMETER(pWndDoc);

	// 이 창에 대한 소유자를 설정하므로 메시지가 올바른 응용 프로그램에 전달됩니다.
	m_wndToolBar.SetOwner(this);

	// 클라이언트의 프레임 창에 도구 모음을 만듭니다.
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
		TRACE0("도구 모음을 만들지 못했습니다.\n");
		return FALSE;
	}

[!if TOOLBAR_STYLE_REBAR]
	// 이 창에 대한 소유자를 설정하므로 메시지가 올바른 응용 프로그램에 전달됩니다.
	m_wndDlgBar.SetOwner(this);

	// 클라이언트의 프레임 창에 대화 상자 모음을 만듭니다.
[!if APP_TYPE_MDI]
	if (!m_wndDlgBar.Create(pWndFrame, IDR_[!output SAFE_DOC_TYPE_NAME]TYPE_SRVR_IP, 
[!else]
	if (!m_wndDlgBar.Create(pWndFrame, IDR_SRVR_INPLACE,
[!endif]
		CBRS_ALIGN_TOP, AFX_IDW_DIALOGBAR))
	{
		TRACE0("대화 상자 모음을 만들지 못했습니다.\n");
		return FALSE;
	}

	// 이 창의 소유자를 설정하므로 메시지가 올바른 응용 프로그램에 전달됩니다.
	m_wndReBar.SetOwner(this);

	// 클라이언트의 프레임 창에 크기 조정 막대를 만듭니다.
	if (!m_wndReBar.Create(pWndFrame) ||
		!m_wndReBar.AddBar(&m_wndToolBar) ||
		!m_wndReBar.AddBar(&m_wndDlgBar))
	{
		TRACE0("크기 조정 막대를 만들지 못했습니다.\n");
		return FALSE;
	}

	// TODO: 도구 설명을 표시하지 않으려면 이 줄을 제거하십시오.
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY);
	m_wndDlgBar.SetBarStyle(m_wndDlgBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY);
[!else]
	// TODO: 도구 모음을 도킹할 수 없게 하려면 이 세 줄을 삭제하십시오.
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	pWndFrame->EnableDocking(CBRS_ALIGN_ANY);
	pWndFrame->DockControlBar(&m_wndToolBar);
[!endif]

	return TRUE;
}

[!endif]
BOOL [!output INPLACE_FRAME_CLASS]::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서 Window 클래스 또는 스타일을 수정합니다.

	return [!output INPLACE_FRAME_BASE_CLASS]::PreCreateWindow(cs);
}


// [!output INPLACE_FRAME_CLASS] 진단

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


// [!output INPLACE_FRAME_CLASS] 명령
