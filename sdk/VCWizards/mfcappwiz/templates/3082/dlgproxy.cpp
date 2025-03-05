// [!output DIALOG_AUTO_PROXY_IMPL]: archivo de implementaci�n
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
	
	// Para que la aplicaci�n se ejecute durante el tiempo de que un objeto de 
	//	 automatizaci�n est� activo, el constructor llama a AfxOleLockApp.
	AfxOleLockApp();

	// Obtener acceso al cuadro de di�logo a trav�s del puntero
	//  de la ventana principal de la aplicaci�n. Establecer el puntero interno del servidor proxy
	//  para que apunte al cuadro de di�logo y volver a establecer el puntero
	//  del cuadro de di�logo a este servidor proxy.
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
	// Para terminar la aplicaci�n cuando terminen todos los objetos creados con
	// 	automatizaci�n, el destructor llama a AfxOleUnlockApp.
	//  Entre otras cosas, esta operaci�n destruir� el cuadro de di�logo principal
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void [!output DIALOG_AUTO_PROXY_CLASS]::OnFinalRelease()
{
	// Cuando se libera la �ltima referencia para un objeto de automatizaci�n,
	// se llama a OnFinalRelease. La clase base eliminar� autom�ticamente
	// el objeto. Se requiere limpieza adicional para el
	// objeto antes de llamar a la clase base.

	[!output DIALOG_AUTO_PROXY_BASE_CLASS]::OnFinalRelease();
}

BEGIN_MESSAGE_MAP([!output DIALOG_AUTO_PROXY_CLASS], [!output DIALOG_AUTO_PROXY_BASE_CLASS])
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP([!output DIALOG_AUTO_PROXY_CLASS], [!output DIALOG_AUTO_PROXY_BASE_CLASS])
END_DISPATCH_MAP()

// Nota: se agrega compatibilidad para IID_I[!output SAFE_PROJECT_NAME] para admitir enlaces con seguridad de tipos
//  desde VBA. IID debe coincidir con el id. GUID adjuntado a 
//  la interfaz dispinterface del archivo .IDL.

// {[!output DISPIID_REGISTRY_FORMAT]}
static const IID IID_I[!output SAFE_PROJECT_NAME] =
[!output DISPIID_STATIC_CONST_GUID_FORMAT];

BEGIN_INTERFACE_MAP([!output DIALOG_AUTO_PROXY_CLASS], [!output DIALOG_AUTO_PROXY_BASE_CLASS])
	INTERFACE_PART([!output DIALOG_AUTO_PROXY_CLASS], IID_I[!output SAFE_PROJECT_NAME], Dispatch)
END_INTERFACE_MAP()

// La macro IMPLEMENT_OLECREATE2 se define en el archivo StdAfx.h de este proyecto
// {[!output APP_CLSID_REGISTRY_FORMAT]}
IMPLEMENT_OLECREATE2([!output DIALOG_AUTO_PROXY_CLASS], "[!output SAFE_PROJECT_NAME].Application", [!output APP_CLSID_IMPLEMENT_OLECREATE_FORMAT])


// Controladores de mensaje de [!output DIALOG_AUTO_PROXY_CLASS]
