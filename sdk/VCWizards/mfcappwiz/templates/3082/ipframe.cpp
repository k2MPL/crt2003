// [!output INPLACE_FRAME_IMPL]: implementación de la clase [!output INPLACE_FRAME_CLASS]
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
	// Comandos de ayuda globales
	ON_COMMAND(ID_HELP_FINDER, [!output INPLACE_FRAME_BASE_CLASS]::OnHelpFinder)
	ON_COMMAND(ID_HELP, [!output INPLACE_FRAME_BASE_CLASS]::OnHelp)
	ON_COMMAND(ID_DEFAULT_HELP, [!output INPLACE_FRAME_BASE_CLASS]::OnHelpFinder)
	ON_COMMAND(ID_CONTEXT_HELP, [!output INPLACE_FRAME_BASE_CLASS]::OnContextHelp)
[!endif]
END_MESSAGE_MAP()


// Construcción o destrucción de [!output INPLACE_FRAME_CLASS]

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

	// CResizeBar implementa el cambio de tamaño en contexto.
	if (!m_wndResizeBar.Create(this))
	{
		TRACE0("No se pudo crear la barra de cambio de tamaño\n");
		return -1;      // No se pudo crear
	}

	// De forma predeterminada, es una buena idea registrar un destino de colocación que no
	//  haga nada con la ventana de marco. De esta forma se impide a las colocaciones que
	//  "pasen" por un contenedor que admita operaciones de arrastrar y colocar.
	m_dropTarget.Register(this);

	return 0;
}

[!if DOCKING_TOOLBAR]
// El marco de trabajo llama a OnCreateControlBars para crear barras de control
//  en las ventanas de la aplicación contenedora. pWndFrame es la ventana de marco de nivel superior del
//  contenedor y es siempre no NULL. pWndDoc es la ventana de marco de nivel de documento
//  y será NULL cuando el contenedor sea una aplicación SDI. Una aplicación
//  de servidor puede insertar barras de control MFC en cualquier ventana.
BOOL [!output INPLACE_FRAME_CLASS]::OnCreateControlBars(CFrameWnd* pWndFrame, CFrameWnd* pWndDoc)
{
	// Quitar esto si se utiliza pWndDoc
	UNREFERENCED_PARAMETER(pWndDoc);

	// Establecer el propietario de esta ventana, de forma que los mensajes se entreguen a la aplicación correcta
	m_wndToolBar.SetOwner(this);

	// Crear barra de herramientas en la ventana de marco del cliente
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
		TRACE0("No se pudo crear la barra de herramientas\n");
		return FALSE;
	}

[!if TOOLBAR_STYLE_REBAR]
	// Establecer el propietario de esta ventana, de forma que los mensajes se entreguen a la aplicación correcta
	m_wndDlgBar.SetOwner(this);

	// Crear barra de diálogo en la ventana de marco del cliente
[!if APP_TYPE_MDI]
	if (!m_wndDlgBar.Create(pWndFrame, IDR_[!output SAFE_DOC_TYPE_NAME]TYPE_SRVR_IP, 
[!else]
	if (!m_wndDlgBar.Create(pWndFrame, IDR_SRVR_INPLACE,
[!endif]
		CBRS_ALIGN_TOP, AFX_IDW_DIALOGBAR))
	{
		TRACE0("No se pudo crear el control dialogbar\n");
		return FALSE;
	}

	// Establecer el propietario de esta ventana, de forma que los mensajes se entreguen a la aplicación correcta
	m_wndReBar.SetOwner(this);

	// Crear un control rebar en la ventana de marco del cliente
	if (!m_wndReBar.Create(pWndFrame) ||
		!m_wndReBar.AddBar(&m_wndToolBar) ||
		!m_wndReBar.AddBar(&m_wndDlgBar))
	{
		TRACE0("No se pudo crear el control rebar\n");
		return FALSE;
	}

	// TODO: quitarlo si no desea información sobre herramientas
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY);
	m_wndDlgBar.SetBarStyle(m_wndDlgBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY);
[!else]
	// TODO: eliminar estas tres líneas si no desea que la barra de herramientas se pueda acoplar
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	pWndFrame->EnableDocking(CBRS_ALIGN_ANY);
	pWndFrame->DockControlBar(&m_wndToolBar);
[!endif]

	return TRUE;
}

[!endif]
BOOL [!output INPLACE_FRAME_CLASS]::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: modificar aquí la clase Window o los estilos cambiando CREATESTRUCT cs

	return [!output INPLACE_FRAME_BASE_CLASS]::PreCreateWindow(cs);
}


// Diagnósticos de [!output INPLACE_FRAME_CLASS]

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


// Comandos de [!output INPLACE_FRAME_CLASS]
