// [!output INPLACE_FRAME_IMPL] : [!output INPLACE_FRAME_CLASS] ���O����@
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
	// ���컡���R�O
	ON_COMMAND(ID_HELP_FINDER, [!output INPLACE_FRAME_BASE_CLASS]::OnHelpFinder)
	ON_COMMAND(ID_HELP, [!output INPLACE_FRAME_BASE_CLASS]::OnHelp)
	ON_COMMAND(ID_DEFAULT_HELP, [!output INPLACE_FRAME_BASE_CLASS]::OnHelpFinder)
	ON_COMMAND(ID_CONTEXT_HELP, [!output INPLACE_FRAME_BASE_CLASS]::OnContextHelp)
[!endif]
END_MESSAGE_MAP()


// [!output INPLACE_FRAME_CLASS] �غc/�Ѻc

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

	// CResizeBar ��@�{�νվ�j�p�C
	if (!m_wndResizeBar.Create(this))
	{
		TRACE0("�إ߽վ�j�p�C����\n");
		return -1;      // �L�k�إ�
	}

	// �̷ӹw�]�A�n���P�ج[�����L�����m��ؼЬO�ܦn���@�k�C
	// ���i����N "falling through" �m���䴩��񪺮e���C
	m_dropTarget.Register(this);

	return 0;
}

[!if DOCKING_TOOLBAR]
// �[�c�ҩI�s�� OnCreateControlBars �|�b�e�����ε{���������إ߱���C�C
// pWndFrame �O�e�����W�h�ج[�����A�B�û��O�D NULL�CpWndDoc �O doc ���h
// �ج[�����A�B��e���O SDI ���ε{���ɬO NULL�C���A�����ε{���i�H�b�䤤
// �@�ӵ�����m MFC ����C�C
BOOL [!output INPLACE_FRAME_CLASS]::OnCreateControlBars(CFrameWnd* pWndFrame, CFrameWnd* pWndDoc)
{
	// �p�G�z�ϥ� pWndDoc�A�в���
	UNREFERENCED_PARAMETER(pWndDoc);

	// �]�w�֦��H�ܦ������A�ҥH�|�N�T���ǻ��쥿�T�����ε{��
	m_wndToolBar.SetOwner(this);

	// �b�Τ�ݪ��ج[�����W�إߤu��C
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
		TRACE0("�L�k�إߤu��C\n");
		return FALSE;
	}

[!if TOOLBAR_STYLE_REBAR]
	// �]�w�֦��H�ܦ������A�ҥH�|�N�T���ǻ��쥿�T�����ε{��
	m_wndDlgBar.SetOwner(this);

	// �b�Τ�ݮج[�����W�إ߹�ܤ���C
[!if APP_TYPE_MDI]
	if (!m_wndDlgBar.Create(pWndFrame, IDR_[!output SAFE_DOC_TYPE_NAME]TYPE_SRVR_IP, 
[!else]
	if (!m_wndDlgBar.Create(pWndFrame, IDR_SRVR_INPLACE,
[!endif]
		CBRS_ALIGN_TOP, AFX_IDW_DIALOGBAR))
	{
		TRACE0("�L�k�إ߹�ܤ���C\n");
		return FALSE;
	}

	// �]�w���������֦��H�A�ҥH�|�N�T���ǻ��쥿�T�����ε{��
	m_wndReBar.SetOwner(this);

	// �b�Τ�ݮج[�����W�إ� Rebar
	if (!m_wndReBar.Create(pWndFrame) ||
		!m_wndReBar.AddBar(&m_wndToolBar) ||
		!m_wndReBar.AddBar(&m_wndDlgBar))
	{
		TRACE0("�L�k�إ� Rebar\n");
		return FALSE;
	}

	// TODO: �p�G�z���ݭn�u�㴣�ܡA�в���������
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY);
	m_wndDlgBar.SetBarStyle(m_wndDlgBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY);
[!else]
	// TODO: �p�G�z���n�i�H�T�w�u��C�A�ЧR���o�T��
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	pWndFrame->EnableDocking(CBRS_ALIGN_ANY);
	pWndFrame->DockControlBar(&m_wndToolBar);
[!endif]

	return TRUE;
}

[!endif]
BOOL [!output INPLACE_FRAME_CLASS]::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �b���g�ѭק� CREATESTRUCT cs �F��ק�������O�μ˦����ت�

	return [!output INPLACE_FRAME_BASE_CLASS]::PreCreateWindow(cs);
}


// [!output INPLACE_FRAME_CLASS] �E�_

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


// [!output INPLACE_FRAME_CLASS] �R�O
