// [!output APP_IMPL] : D�finit les comportements de classe pour l'application.
//

#include "stdafx.h"
#include "[!output APP_HEADER]"
#include "[!output DIALOG_HEADER]"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// [!output APP_CLASS]

BEGIN_MESSAGE_MAP([!output APP_CLASS], [!output APP_BASE_CLASS])
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


// construction [!output APP_CLASS]

[!output APP_CLASS]::[!output APP_CLASS]()
{
[!if CONTEXT_HELP && HELPSTYLE_HTML]
	EnableHtmlHelp();

[!endif]
	// TODO�: ajoutez ici du code de construction,
	// Placez toutes les initialisations significatives dans InitInstance
}


// Seul et unique objet [!output APP_CLASS]

[!output APP_CLASS] theApp;

[!if AUTOMATION]
const GUID CDECL BASED_CODE _tlid =
		[!output LIBID_STATIC_CONST_GUID_FORMAT];
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;

[!endif]

// initialisation [!output APP_CLASS]

BOOL [!output APP_CLASS]::InitInstance()
{
[!if MANIFEST]
	// InitCommonControls() est requis sur Windows�XP si le manifeste de l'application
	// sp�cifie l'utilisation de ComCtl32.dll version�6 ou ult�rieure pour activer les
	// styles visuels.  Dans le cas contraire, la cr�ation de fen�tres �chouera.
	InitCommonControls();

[!endif]
	[!output APP_BASE_CLASS]::InitInstance();

[!if SOCKETS]
	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

[!endif]
[!if AUTOMATION || ACCESSIBILITY]
	// Initialiser les biblioth�ques OLE
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

[!endif]
[!if ACTIVEX_CONTROLS]
	AfxEnableControlContainer();

[!endif]
	// Initialisation standard
	// Si vous n'utilisez pas ces fonctionnalit�s et que vous souhaitez r�duire la taille
	// de votre ex�cutable final, vous devez supprimer ci-dessous
	// les routines d'initialisation sp�cifiques dont vous n'avez pas besoin.
	// Changez la cl� de Registre sous laquelle nos param�tres sont enregistr�s.
	// TODO : Modifiez cette cha�ne avec des informations appropri�es,
	// telles que le nom de votre soci�t� ou organisation
	SetRegistryKey(_T("Applications locales g�n�r�es par AppWizard"));
[!if AUTOMATION]
	// Analyser la ligne de commande pour rechercher les commutateurs automation ou reg/unreg.
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// L'application a �t� d�marr�e avec le commutateur /Embedding ou /Automation.
	// Ex�cutez-la en tant que serveur Automation.
	if (cmdInfo.m_bRunEmbedded || cmdInfo.m_bRunAutomated)
	{
		// Inscrire les fabriques de classes via CoRegisterClassObject().
		COleTemplateServer::RegisterAll();
	}
	// L'application a �t� lanc�e avec le commutateur /Unregserver ou /Unregister. Supprimez
	// les entr�es dans la base de registres.
	else if (cmdInfo.m_nShellCommand == CCommandLineInfo::AppUnregister)
	{
		COleObjectFactory::UpdateRegistryAll(FALSE);
		AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor);
		return FALSE;
	}
	// L'application a �t� d�marr�e en mode autonome ou avec d'autres commutateurs (par exemple, /Register
	// ou /Regserver). Mettez � jour les entr�es de la base de registres, y compris typelibrary.
	else
	{
		COleObjectFactory::UpdateRegistryAll();
		AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid);
		if (cmdInfo.m_nShellCommand == CCommandLineInfo::AppRegister)
			return FALSE;
	}
[!endif]

	[!output DIALOG_CLASS] dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO : Placez ici le code d�finissant le comportement lorsque la bo�te de dialogue est
		//  ferm�e avec OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO : Placez ici le code d�finissant le comportement lorsque la bo�te de dialogue est
		//  ferm�e avec Annuler
	}

	// Lorsque la bo�te de dialogue est ferm�e, retourner FALSE afin de quitter
	//  l'application, plut�t que de d�marrer la pompe de messages de l'application.
	return FALSE;
}
