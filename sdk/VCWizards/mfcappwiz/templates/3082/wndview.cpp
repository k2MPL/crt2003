// [!output WND_VIEW_IMPL]: implementación de la clase [!output WND_VIEW_CLASS]
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



// Controladores de mensaje de [!output WND_VIEW_CLASS]

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
	CPaintDC dc(this); // Contexto de dispositivo para dibujo
	
	// TODO: agregue aquí su código de controlador de mensajes
	
	// No llamar a CWnd::OnPaint() para dibujar mensajes
}

