// [!output INPLACE_FRAME_IMPL] : implementazione della classe [!output INPLACE_FRAME_CLASS]
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
	// Comandi globali della Guida
	ON_COMMAND(ID_HELP_FINDER, [!output INPLACE_FRAME_BASE_CLASS]::OnHelpFinder)
	ON_COMMAND(ID_HELP, [!output INPLACE_FRAME_BASE_CLASS]::OnHelp)
	ON_COMMAND(ID_DEFAULT_HELP, [!output INPLACE_FRAME_BASE_CLASS]::OnHelpFinder)
	ON_COMMAND(ID_CONTEXT_HELP, [!output INPLACE_FRAME_BASE_CLASS]::OnContextHelp)
[!endif]
END_MESSAGE_MAP()


// costruzione/distruzione di [!output INPLACE_FRAME_CLASS]

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

	// CResizeBar implementa il ridimensionamento sul posto.
	if (!m_wndResizeBar.Create(this))
	{
		TRACE0("Impossibile creare la barra di ridimensionamento.\n");
		return -1;      // impossibile creare
	}

	// Per impostazione predefinita, è opportuno registrare la destinazione di un trascinamento che 
	//  non interessa la finestra cornice. Questo impedisce che i rilasci 
	//  "passino" a un contenitore che supporta il trascinamento della selezione.
	m_dropTarget.Register(this);

	return 0;
}

[!if DOCKING_TOOLBAR]
// OnCreateControlBars viene richiamato dal framework per creare le barre di controllo nelle 
//  finestre dell'applicazione contenitore. pWndFrame è la finestra cornice di primo livello del
//  contenitore ed è sempre non NULL. pWndDoc è la finestra di cornice a livello
//  di documento e sarà sempre NULL se il contenitore è un'applicazione SDI.  Un'applicazione
//  server può inserire le barre di controllo MFC in entrambe le finestre.
BOOL [!output INPLACE_FRAME_CLASS]::OnCreateControlBars(CFrameWnd* pWndFrame, CFrameWnd* pWndDoc)
{
	// Rimuovere l'elemento se si utilizza pWndDoc.
	UNREFERENCED_PARAMETER(pWndDoc);

	// Impostare il proprietario di questa finestra, in modo che i messaggi vengano recapitati all'applicazione corretta.
	m_wndToolBar.SetOwner(this);

	// Creare una barra degli strumenti nella finestra cornice del client.
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
		TRACE0("Impossibile creare la barra degli strumenti.\n");
		return FALSE;
	}

[!if TOOLBAR_STYLE_REBAR]
	// Impostare il proprietario di questa finestra, in modo che i messaggi vengano recapitati all'applicazione corretta.
	m_wndDlgBar.SetOwner(this);

	// Creare una barra della finestra di dialogo nella finestra cornice del client.
[!if APP_TYPE_MDI]
	if (!m_wndDlgBar.Create(pWndFrame, IDR_[!output SAFE_DOC_TYPE_NAME]TYPE_SRVR_IP, 
[!else]
	if (!m_wndDlgBar.Create(pWndFrame, IDR_SRVR_INPLACE,
[!endif]
		CBRS_ALIGN_TOP, AFX_IDW_DIALOGBAR))
	{
		TRACE0("Impossibile creare la barra della finestra di dialogo.\n");
		return FALSE;
	}

	// Impostare il proprietario di questa finestra, in modo che i messaggi vengano recapitati all'applicazione corretta.
	m_wndReBar.SetOwner(this);

	// Creare un controllo Rebar nella finestra cornice del client.
	if (!m_wndReBar.Create(pWndFrame) ||
		!m_wndReBar.AddBar(&m_wndToolBar) ||
		!m_wndReBar.AddBar(&m_wndDlgBar))
	{
		TRACE0("Impossibile creare il controllo Rebar.\n");
		return FALSE;
	}

	// TODO: rimuovere l'elemento se non si desidera visualizzare le descrizioni dei comandi.
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY);
	m_wndDlgBar.SetBarStyle(m_wndDlgBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY);
[!else]
	// TODO: eliminare queste tre righe se si desidera che la barra degli strumenti non sia ancorabile.
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	pWndFrame->EnableDocking(CBRS_ALIGN_ANY);
	pWndFrame->DockControlBar(&m_wndToolBar);
[!endif]

	return TRUE;
}

[!endif]
BOOL [!output INPLACE_FRAME_CLASS]::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: modificare qui la classe o gli stili Window modificando CREATESTRUCT cs.

	return [!output INPLACE_FRAME_BASE_CLASS]::PreCreateWindow(cs);
}


// diagnostica di [!output INPLACE_FRAME_CLASS]

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


// comandi di [!output INPLACE_FRAME_CLASS]
