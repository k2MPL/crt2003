// [!output WND_VIEW_IMPL] : [!output WND_VIEW_CLASS] �N���X�̎���
//

#include "stdafx.h"
#include "[!output APP_HEADER]"
#include "[!output WND_VIEW_HEADER]"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// [!output WND_VIEW_CLASS]

[!output WND_VIEW_CLASS]::[!output WND_VIEW_CLASS]()
{
[!if ACCESSIBILITY]
	EnableActiveAccessibility();
[!endif]
}

[!output WND_VIEW_CLASS]::~[!output WND_VIEW_CLASS]()
{
}


BEGIN_MESSAGE_MAP([!output WND_VIEW_CLASS], [!output WND_VIEW_BASE_CLASS])
	ON_WM_PAINT()
END_MESSAGE_MAP()



// [!output WND_VIEW_CLASS] ���b�Z�[�W �n���h��

BOOL [!output WND_VIEW_CLASS]::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void [!output WND_VIEW_CLASS]::OnPaint() 
{
	CPaintDC dc(this); // �`��̃f�o�C�X �R���e�L�X�g
	
	// TODO : �����Ƀ��b�Z�[�W �n���h�� �R�[�h��ǉ����܂��B
	
	// ���b�Z�[�W�̕`��̂��߂� CWnd::OnPaint() ���Ăяo���Ȃ��ł��������B
}

