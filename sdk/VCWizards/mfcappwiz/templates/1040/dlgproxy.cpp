// [!output DIALOG_AUTO_PROXY_IMPL] : file di implementazione
//

#include "stdafx.h"
#include "[!output APP_HEADER]"
#include "[!output DIALOG_AUTO_PROXY_HEADER]"
#include "[!output DIALOG_HEADER]"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// [!output DIALOG_AUTO_PROXY_CLASS]

IMPLEMENT_DYNCREATE([!output DIALOG_AUTO_PROXY_CLASS], [!output DIALOG_AUTO_PROXY_BASE_CLASS])

[!output DIALOG_AUTO_PROXY_CLASS]::[!output DIALOG_AUTO_PROXY_CLASS]()
{
	EnableAutomation();
	
	// Per tenere in esecuzione l'applicazione finché rimane attivo un oggetto di 
	//	 automazione, il costruttore richiama AfxOleLockApp.
	AfxOleLockApp();

	// Accedere alla finestra di dialogo tramite il puntatore della
	//  finestra principale dell'applicazione. Impostare il puntatore interno del proxy
	//  in modo da selezionare la finestra di dialogo e impostare il puntatore all'indietro della finestra di dialogo 
	//  sul proxy.
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF([!output DIALOG_CLASS], AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS([!output DIALOG_CLASS])))
		{
			m_pDialog = reinterpret_cast<[!output DIALOG_CLASS]*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

[!output DIALOG_AUTO_PROXY_CLASS]::~[!output DIALOG_AUTO_PROXY_CLASS]()
{
	// Per terminare l'applicazione quando tutti gli oggetti sono creati tramite l'automazione, 
	// 	il distruttore richiama AfxOleUnlockApp.
	//  Questa operazione eliminerà la finestra di dialogo principale.
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void [!output DIALOG_AUTO_PROXY_CLASS]::OnFinalRelease()
{
	// Quando viene rilasciato l'ultimo riferimento relativo a un oggetto di automazione,
	// viene richiamato OnFinalRelease. La classe di base eliminerà
	// automaticamente l'oggetto. Inserire la pulitura aggiuntiva richiesta per
	// l'oggetto prima di richiamare la classe di base.

	[!output DIALOG_AUTO_PROXY_BASE_CLASS]::OnFinalRelease();
}

BEGIN_MESSAGE_MAP([!output DIALOG_AUTO_PROXY_CLASS], [!output DIALOG_AUTO_PROXY_BASE_CLASS])
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP([!output DIALOG_AUTO_PROXY_CLASS], [!output DIALOG_AUTO_PROXY_BASE_CLASS])
END_DISPATCH_MAP()

// Nota: viene aggiunto il supporto per IID_I[!output SAFE_PROJECT_NAME] in modo da supportare il binding indipendente dai tipi
//  di VBA. Questo IID deve corrispondere al GUID che è collegato all'interfaccia di invio 
//  contenuta nel file .IDL.

// {[!output DISPIID_REGISTRY_FORMAT]}
static const IID IID_I[!output SAFE_PROJECT_NAME] =
[!output DISPIID_STATIC_CONST_GUID_FORMAT];

BEGIN_INTERFACE_MAP([!output DIALOG_AUTO_PROXY_CLASS], [!output DIALOG_AUTO_PROXY_BASE_CLASS])
	INTERFACE_PART([!output DIALOG_AUTO_PROXY_CLASS], IID_I[!output SAFE_PROJECT_NAME], Dispatch)
END_INTERFACE_MAP()

// La macro IMPLEMENT_OLECREATE2 viene definita in StdAfx.h di questo progetto.
// {[!output APP_CLSID_REGISTRY_FORMAT]}
IMPLEMENT_OLECREATE2([!output DIALOG_AUTO_PROXY_CLASS], "[!output SAFE_PROJECT_NAME].Applicazione", [!output APP_CLSID_IMPLEMENT_OLECREATE_FORMAT])


// gestori di messaggi di [!output DIALOG_AUTO_PROXY_CLASS]
