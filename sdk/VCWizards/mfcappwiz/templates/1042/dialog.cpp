// [!output DIALOG_IMPL] : 구현 파일
//

#include "stdafx.h"
#include "[!output APP_HEADER]"
#include "[!output DIALOG_HEADER]"
[!if AUTOMATION]
#include "[!output DIALOG_AUTO_PROXY_HEADER]"
[!endif]

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

[!if ABOUT_BOX]

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 대화 상자 데이터
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원

// 구현
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
[!if ACCESSIBILITY]
	EnableActiveAccessibility();
[!endif]
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

[!endif]

// [!output DIALOG_CLASS] 대화 상자

[!if HTML_DIALOG]
BEGIN_DHTML_EVENT_MAP([!output DIALOG_CLASS])
	DHTML_EVENT_ONCLICK(_T("ButtonOK"), OnButtonOK)
	DHTML_EVENT_ONCLICK(_T("ButtonCancel"), OnButtonCancel)
[!if CONTEXT_HELP]
	DHTML_EVENT_ONCLICK(_T("ButtonHelp"), OnButtonHelp)
[!endif]
END_DHTML_EVENT_MAP()
[!endif]


[!if AUTOMATION]

IMPLEMENT_DYNAMIC([!output DIALOG_CLASS], [!output DIALOG_BASE_CLASS]);
[!endif] 

[!output DIALOG_CLASS]::[!output DIALOG_CLASS](CWnd* pParent /*=NULL*/)
[!if HTML_DIALOG]
	: CDHtmlDialog([!output DIALOG_CLASS]::IDD, [!output DIALOG_CLASS]::IDH, pParent)
[!else]
	: [!output DIALOG_BASE_CLASS]([!output DIALOG_CLASS]::IDD, pParent)
[!endif]
{
[!if ACCESSIBILITY]
	EnableActiveAccessibility();
[!endif]
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
[!if AUTOMATION]
	m_pAutoProxy = NULL;
[!endif]
}
[!if AUTOMATION]

[!output DIALOG_CLASS]::~[!output DIALOG_CLASS]()
{
	// 이 대화 상자에 대한 자동화 프록시가 있을 경우 이 대화 상자에 대한
	// 후방 포인터를 NULL로 설정하여
	// 대화 상자가 삭제되었음을 알 수 있게 합니다.
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}
[!endif]

void [!output DIALOG_CLASS]::DoDataExchange(CDataExchange* pDX)
{
	[!output DIALOG_BASE_CLASS]::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP([!output DIALOG_CLASS], [!output DIALOG_BASE_CLASS])
[!if ABOUT_BOX]
	ON_WM_SYSCOMMAND()
[!endif]
[!if CONTEXT_HELP && HELPSTYLE_WINHELP]
	ON_WM_DESTROY()
[!endif]
[!if AUTOMATION]
	ON_WM_CLOSE()
[!endif]
[!if !HTML_DIALOG]
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
[!endif]
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// [!output DIALOG_CLASS] 메시지 처리기

BOOL [!output DIALOG_CLASS]::OnInitDialog()
{
	[!output DIALOG_BASE_CLASS]::OnInitDialog();
[!if ABOUT_BOX]

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
[!endif]

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	// 프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

[!if MAIN_FRAME_MAXIMIZED]
	ShowWindow(SW_MAXIMIZE);

[!endif]
[!if MAIN_FRAME_MINIMIZED]
	ShowWindow(SW_MINIMIZE);

[!endif]
	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	
	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
}
[!if ABOUT_BOX]

void [!output DIALOG_CLASS]::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		[!output DIALOG_BASE_CLASS]::OnSysCommand(nID, lParam);
	}
}
[!endif]
[!if CONTEXT_HELP && HELPSTYLE_WINHELP]

void [!output DIALOG_CLASS]::OnDestroy()
{
	WinHelp(0L, HELP_QUIT);
	[!output DIALOG_BASE_CLASS]::OnDestroy();
}
[!endif]

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면 
// 아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
// 프레임워크에서 이 작업을 자동으로 수행합니다.

void [!output DIALOG_CLASS]::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		[!output DIALOG_BASE_CLASS]::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다. 
HCURSOR [!output DIALOG_CLASS]::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
[!if AUTOMATION]

// 컨트롤러에서 해당 개체 중 하나를 계속 사용하고 있을 경우
// 사용자가 UI를 닫을 때 자동화 서버를 종료하면 안 됩니다. 이들
// 메시지 처리기는 프록시가 아직 사용 중인 경우 UI는 숨기지만,
// UI가 표시되지 않아도 대화 상자는 남겨 둡니다.

void [!output DIALOG_CLASS]::OnClose() 
{
	if (CanExit())
		[!output DIALOG_BASE_CLASS]::OnClose();
}

void [!output DIALOG_CLASS]::OnOK() 
{
	if (CanExit())
		[!output DIALOG_BASE_CLASS]::OnOK();
}

void [!output DIALOG_CLASS]::OnCancel() 
{
	if (CanExit())
		[!output DIALOG_BASE_CLASS]::OnCancel();
}

BOOL [!output DIALOG_CLASS]::CanExit()
{
	// 프록시 개체가 계속 남아 있으면 자동화 컨트롤러에서는
	// 이 응용 프로그램을 계속 사용합니다. 대화 상자는 남겨 두지만
	// 해당 UI는 숨깁니다.
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}
[!endif]

[!if HTML_DIALOG]
HRESULT [!output DIALOG_CLASS]::OnButtonOK(IHTMLElement* /*pElement*/)
{
	OnOK();
	return S_OK;
}

HRESULT [!output DIALOG_CLASS]::OnButtonCancel(IHTMLElement* /*pElement*/)
{
	OnCancel();
	return S_OK;
}
[!if CONTEXT_HELP]

HRESULT [!output DIALOG_CLASS]::OnButtonHelp(IHTMLElement* /*pElement*/)
{
	OnHelp();
	return S_OK;
}
[!endif]
[!endif]
