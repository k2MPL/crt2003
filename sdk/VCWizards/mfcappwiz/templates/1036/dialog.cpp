// [!output DIALOG_IMPL] : fichier d'impl�mentation
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

// bo�te de dialogue CAboutDlg utilis�e pour la bo�te de dialogue '� propos de' pour votre application

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Donn�es de bo�te de dialogue
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge DDX/DDV

// Impl�mentation
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

// bo�te de dialogue [!output DIALOG_CLASS]

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
	// S'il existe un proxy Automation pour cette bo�te de dialogue, d�finir
	//  la valeur NULL pour son pointeur de retour vers cette bo�te de dialogue, afin qu'il sache
	//  que celle-ci a �t� supprim�e.
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


// gestionnaires de messages pour [!output DIALOG_CLASS]

BOOL [!output DIALOG_CLASS]::OnInitDialog()
{
	[!output DIALOG_BASE_CLASS]::OnInitDialog();
[!if ABOUT_BOX]

	// Ajouter l'�l�ment de menu "� propos de..." au menu Syst�me.

	// IDM_ABOUTBOX doit se trouver dans la plage des commandes syst�me.
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

	// D�finir l'ic�ne de cette bo�te de dialogue. L'infrastructure effectue cela automatiquement
	//  lorsque la fen�tre principale de l'application n'est pas une bo�te de dialogue
	SetIcon(m_hIcon, TRUE);			// D�finir une grande ic�ne
	SetIcon(m_hIcon, FALSE);		// D�finir une petite ic�ne

[!if MAIN_FRAME_MAXIMIZED]
	ShowWindow(SW_MAXIMIZE);

[!endif]
[!if MAIN_FRAME_MINIMIZED]
	ShowWindow(SW_MINIMIZE);

[!endif]
	// TODO : ajoutez ici une initialisation suppl�mentaire
	
	return TRUE;  // retourne TRUE, sauf si vous avez d�fini le focus sur un contr�le
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

// Si vous ajoutez un bouton R�duire � votre bo�te de dialogue, vous devez utiliser le code ci-dessous
//  pour dessiner l'ic�ne. Pour les applications MFC utilisant le mod�le Document/Vue,
//  cela est fait automatiquement par l'infrastructure.

void [!output DIALOG_CLASS]::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // contexte de p�riph�rique pour la peinture

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrer l'ic�ne dans le rectangle client
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dessiner l'ic�ne
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		[!output DIALOG_BASE_CLASS]::OnPaint();
	}
}

// Le syst�me appelle cette fonction pour obtenir le curseur � afficher lorsque l'utilisateur fait glisser
//  la fen�tre r�duite.
HCURSOR [!output DIALOG_CLASS]::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
[!if AUTOMATION]

// Les serveurs Automation ne doivent pas quitter lorsqu'un utilisateur ferme l'interface utilisateur
//  alors qu'un contr�leur est encore plac� sur l'un de ses objets. Ces
//  gestionnaires de messages s'assurent que 
//  l'interface utilisateur est masqu�e si le proxy est en cours d'utilisation, mais que la bo�te de dialogue demeure s'il est
//  ferm�.

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
	// Si l'objet proxy est encore pr�sent, le contr�leur
	//  Automation reste plac� sur cette application. Conserver
	//  la bo�te de dialogue, mais masquer l'interface utilisateur associ�e.
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
