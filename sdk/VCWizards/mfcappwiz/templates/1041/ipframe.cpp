// [!output INPLACE_FRAME_IMPL] : [!output INPLACE_FRAME_CLASS] �N���X�̎���
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
	// �O���[�o�� �w���v �R�}���h
	ON_COMMAND(ID_HELP_FINDER, [!output INPLACE_FRAME_BASE_CLASS]::OnHelpFinder)
	ON_COMMAND(ID_HELP, [!output INPLACE_FRAME_BASE_CLASS]::OnHelp)
	ON_COMMAND(ID_DEFAULT_HELP, [!output INPLACE_FRAME_BASE_CLASS]::OnHelpFinder)
	ON_COMMAND(ID_CONTEXT_HELP, [!output INPLACE_FRAME_BASE_CLASS]::OnContextHelp)
[!endif]
END_MESSAGE_MAP()


// [!output INPLACE_FRAME_CLASS] �R���X�g���N�V����/�f�X�g���N�V����

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

	// CResizeBar �͖��ߍ��ݐ�ł̃T�C�Y�̕ύX���������܂��B
	if (!m_wndResizeBar.Create(this))
	{
		TRACE0("�T�C�Y�ύX�o�[�̍쐬�Ɏ��s���܂����B\n");
		return -1;      // �쐬�ł��܂���ł����B
	}

	// �f�t�H���g�ŁA�h���b�v �^�[�Q�b�g���t���[���E�B���h�E�Ƌ��ɓo�^��
	// �Ȃ��̂́A�ǂ��l���ł��B����� "falling through" �h���b�v����R
	// ���e�i�̃h���b�O �A���h �h���b�v �T�|�[�g��ی삵�܂��B
	m_dropTarget.Register(this);

	return 0;
}

[!if DOCKING_TOOLBAR]
// OnCreateControlBars �̓R���e�i �A�v���P�[�V�����̃E�B���h�E��Ƀc�[�� �o�[���쐬���邽�߂ɁA
// �t���[�����[�N����Ă΂�܂��BpWndFrame �̓R���e�i�̃g�b�v ���x���̃t���[�� �E�B���h�E�ŁA
// ��� NULL �ł͂���܂���BpWndDoc �̓h�L�������g ���x���̃t���[�� �E�B���h�E�ŃR���e�i�� SDI
// �A�v���P�[�V�����̂Ƃ��� NULL �ɂȂ�܂��B�T�[�o�[ �A�v���P�[�V�����͑��̃E�B���h�E�� MFC ��
// �R���g���[�� �o�[��z�u�ł��܂��B
BOOL [!output INPLACE_FRAME_CLASS]::OnCreateControlBars(CFrameWnd* pWndFrame, CFrameWnd* pWndDoc)
{
	// pWndDoc ���g�p����ꍇ�͂��̃R�[�h���폜���܂��B
	UNREFERENCED_PARAMETER(pWndDoc);

	// ���b�Z�[�W���������A�v���P�[�V�����ɓn�����悤�ɁA���̃E�B���h�E�ɃI�[�i�[��ݒ肵�܂��B
	m_wndToolBar.SetOwner(this);

	// �N���C�A���g�̃t���[�� �E�B���h�E�Ƀc�[�� �o�[���쐬���܂��B
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
		TRACE0("�c�[�� �o�[�̍쐬�Ɏ��s���܂����B\n");
		return FALSE;
	}

[!if TOOLBAR_STYLE_REBAR]
	// ���b�Z�[�W���������A�v���P�[�V�����ɓn�����悤�ɁA���̃E�B���h�E�ɃI�[�i�[��ݒ肵�܂��B
	m_wndDlgBar.SetOwner(this);

	// �N���C�A���g�̃t���[�� �E�C���h�E�Ƀ_�C�A���O �o�[���쐬���܂��B
[!if APP_TYPE_MDI]
	if (!m_wndDlgBar.Create(pWndFrame, IDR_[!output SAFE_DOC_TYPE_NAME]TYPE_SRVR_IP, 
[!else]
	if (!m_wndDlgBar.Create(pWndFrame, IDR_SRVR_INPLACE,
[!endif]
		CBRS_ALIGN_TOP, AFX_IDW_DIALOGBAR))
	{
		TRACE0("�_�C�A���O�o�[�̍쐬�Ɏ��s���܂����B\n");
		return FALSE;
	}

	// ���̃E�B���h�E�̃I�[�i�[��ݒ肷�邱�Ƃɂ��A���b�Z�[�W���������A�v���P�[�V�����ɔz�M����܂��B
	m_wndReBar.SetOwner(this);

	// �N���C�A���g�̃t���[���� rebar ���쐬���܂��B
	if (!m_wndReBar.Create(pWndFrame) ||
		!m_wndReBar.AddBar(&m_wndToolBar) ||
		!m_wndReBar.AddBar(&m_wndDlgBar))
	{
		TRACE0("rebar �̍쐬�Ɏ��s���܂����B\n");
		return FALSE;
	}

	// TODO: �c�[�� �q���g��\�����Ȃ��ꍇ�́A�폜���Ă��������B
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY);
	m_wndDlgBar.SetBarStyle(m_wndDlgBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY);
[!else]
	// TODO: �c�[�� �o�[���h�b�L���O�\�ɂ��Ȃ��ꍇ�́A������ 3 �s���폜���Ă��������B
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	pWndFrame->EnableDocking(CBRS_ALIGN_ANY);
	pWndFrame->DockControlBar(&m_wndToolBar);
[!endif]

	return TRUE;
}

[!endif]
BOOL [!output INPLACE_FRAME_CLASS]::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs ��ύX���āAWindow �N���X�܂��̓X�^�C����ύX���܂��B

	return [!output INPLACE_FRAME_BASE_CLASS]::PreCreateWindow(cs);
}


// [!output INPLACE_FRAME_CLASS] �f�f

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


// [!output INPLACE_FRAME_CLASS] �R�}���h
