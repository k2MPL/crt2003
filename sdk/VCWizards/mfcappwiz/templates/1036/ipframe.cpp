// [!output INPLACE_FRAME_IMPL] : impl�mentation de la classe [!output INPLACE_FRAME_CLASS]
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
	// Commandes d'aide globales
	ON_COMMAND(ID_HELP_FINDER, [!output INPLACE_FRAME_BASE_CLASS]::OnHelpFinder)
	ON_COMMAND(ID_HELP, [!output INPLACE_FRAME_BASE_CLASS]::OnHelp)
	ON_COMMAND(ID_DEFAULT_HELP, [!output INPLACE_FRAME_BASE_CLASS]::OnHelpFinder)
	ON_COMMAND(ID_CONTEXT_HELP, [!output INPLACE_FRAME_BASE_CLASS]::OnContextHelp)
[!endif]
END_MESSAGE_MAP()


// construction ou destruction�de [!output INPLACE_FRAME_CLASS]

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

	// CResizeBar impl�mente le redimensionnement sur place.
	if (!m_wndResizeBar.Create(this))
	{
		TRACE0("Impossible de cr�er la barre de redimensionnement\n");
		return -1;      // �chec de la cr�ation
	}

	// Par d�faut, il est conseill� d'inscrire une cible de d�p�t strictement
	//  ind�pendante de votre fen�tre frame. Cela permet d'�viter que les objets d�pos�s ne
	//  "tombent" dans un conteneur qui prend en charge les op�rations glisser-d�placer.
	m_dropTarget.Register(this);

	return 0;
}

[!if DOCKING_TOOLBAR]
// OnCreateControlBars est appel� par l'infrastructure pour cr�er des barres de contr�le dans
//  les fen�tres de l'application conteneur. pWndFrame est la fen�tre frame de niveau sup�rieur�; elle est toujours non NULL. pWndDoc est la fen�tre frame de niveau document�;
//  elle est NULL si le conteneur est une application SDI. Une application
//  serveur peut placer des barres de contr�le MFC sur l'une ou l'autre de ces deux fen�tres.
BOOL [!output INPLACE_FRAME_CLASS]::OnCreateControlBars(CFrameWnd* pWndFrame, CFrameWnd* pWndDoc)
{
	// Supprimez ceci si vous utilisez pWndDoc
	UNREFERENCED_PARAMETER(pWndDoc);

	// D�finir le propri�taire de cette fen�tre afin que les messages soient remis � l'application appropri�e
	m_wndToolBar.SetOwner(this);

	// Cr�er une barre d'outils dans la fen�tre frame du client
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
		TRACE0("Impossible de cr�er toolbar\n");
		return FALSE;
	}

[!if TOOLBAR_STYLE_REBAR]
	// D�finir le propri�taire de cette fen�tre afin que les messages soient remis � l'application appropri�e
	m_wndDlgBar.SetOwner(this);

	// Cr�er une barre de bo�te de dialogue dans la fen�tre frame du client
[!if APP_TYPE_MDI]
	if (!m_wndDlgBar.Create(pWndFrame, IDR_[!output SAFE_DOC_TYPE_NAME]TYPE_SRVR_IP, 
[!else]
	if (!m_wndDlgBar.Create(pWndFrame, IDR_SRVR_INPLACE,
[!endif]
		CBRS_ALIGN_TOP, AFX_IDW_DIALOGBAR))
	{
		TRACE0("Impossible de cr�er dialogbar\n");
		return FALSE;
	}

	// D�finir le propri�taire de cette fen�tre afin que les messages soient remis � l'application appropri�e
	m_wndReBar.SetOwner(this);

	// Cr�er un contr�le rebar dans la fen�tre frame du client
	if (!m_wndReBar.Create(pWndFrame) ||
		!m_wndReBar.AddBar(&m_wndToolBar) ||
		!m_wndReBar.AddBar(&m_wndDlgBar))
	{
		TRACE0("Impossible de cr�er rebar\n");
		return FALSE;
	}

	// TODO : Supprimez ceci si vous ne souhaitez pas afficher les info-bulles
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY);
	m_wndDlgBar.SetBarStyle(m_wndDlgBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY);
[!else]
	// TODO : Supprimez ces trois lignes si vous ne souhaitez pas que la barre d'outils soit ancrable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	pWndFrame->EnableDocking(CBRS_ALIGN_ANY);
	pWndFrame->DockControlBar(&m_wndToolBar);
[!endif]

	return TRUE;
}

[!endif]
BOOL [!output INPLACE_FRAME_CLASS]::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO : Changez ici la classe ou les styles Window en modifiant CREATESTRUCT cs

	return [!output INPLACE_FRAME_BASE_CLASS]::PreCreateWindow(cs);
}


// diagnostics pour [!output INPLACE_FRAME_CLASS]

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


// commandes pour [!output INPLACE_FRAME_CLASS]
