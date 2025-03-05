// [!output APP_IMPL] : define los comportamientos de las clases para la aplicaci�n.
//

#include "stdafx.h"
#include "[!output APP_HEADER]"
#include "[!output MAIN_FRAME_HEADER]"

[!if APP_TYPE_MDI]
#include "[!output CHILD_FRAME_HEADER]"
[!endif]
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]
#include "[!output INPLACE_FRAME_HEADER]"
[!endif]
[!if OLEDB_RECORD_VIEW || ODBC_RECORD_VIEW]
#include "[!output ROWSET_HEADER]"
[!endif]
[!if DOCVIEW]
#include "[!output DOC_HEADER]"
[!if PROJECT_STYLE_EXPLORER]
#include "[!output TREE_VIEW_HEADER]"
[!else]
#include "[!output VIEW_HEADER]"
[!endif]
[!endif]

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// [!output APP_CLASS]

BEGIN_MESSAGE_MAP([!output APP_CLASS], [!output APP_BASE_CLASS])
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
[!if APP_TYPE_MTLD]
	ON_COMMAND(ID_FILE_NEW_FRAME, OnFileNewFrame)
[!if DOCVIEW]
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
[!endif]
[!endif]
[!if !DOCVIEW]
[!if APP_TYPE_MDI]
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
[!endif]
[!endif]
[!if DOCVIEW]
[!if !DB_VIEW_NO_FILE]
	// Comandos de documento est�ndar basados en archivo
[!if !APP_TYPE_MTLD]
	ON_COMMAND(ID_FILE_NEW, [!output APP_BASE_CLASS]::OnFileNew)
[!endif]
	ON_COMMAND(ID_FILE_OPEN, [!output APP_BASE_CLASS]::OnFileOpen)
[!endif]
[!endif]
[!if PRINTING && DOCVIEW]
	// Comando de configuraci�n de impresi�n est�ndar
	ON_COMMAND(ID_FILE_PRINT_SETUP, [!output APP_BASE_CLASS]::OnFilePrintSetup)
[!endif]
END_MESSAGE_MAP()


// Construcci�n de [!output APP_CLASS]

[!output APP_CLASS]::[!output APP_CLASS]()
{
[!if CONTEXT_HELP && HELPSTYLE_HTML]
	EnableHtmlHelp();

[!endif]
	// TODO: agregar aqu� el c�digo de construcci�n,
	// Colocar toda la inicializaci�n importante en InitInstance
}
[!if ATL_SUPPORT]
// Objeto de m�dulo ATL
CComModule _Module;
[!endif]


// El �nico objeto [!output APP_CLASS]

[!output APP_CLASS] theApp;
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER || AUTOMATION]
// Este identificador se gener� para que sea �nico para la aplicaci�n desde el punto de vista estad�stico
// Puede cambiarlo si prefiere elegir un identificador espec�fico

// {[!output APP_CLSID_REGISTRY_FORMAT]}
static const CLSID clsid =
[!output APP_CLSID_STATIC_CONST_GUID_FORMAT];
[!endif]

[!if AUTOMATION]
const GUID CDECL BASED_CODE _tlid =
		[!output LIBID_STATIC_CONST_GUID_FORMAT];
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;

[!endif]

// Inicializaci�n de [!output APP_CLASS]

BOOL [!output APP_CLASS]::InitInstance()
{
[!if MANIFEST]
	// Windows XP requiere InitCommonControls() si un manifiesto de 
	// aplicaci�n especifica el uso de ComCtl32.dll versi�n 6 o posterior para habilitar
	// estilos visuales. De lo contrario, se generar� un error al crear ventanas.
	InitCommonControls();

[!endif]
	[!output APP_BASE_CLASS]::InitInstance();

[!if OLEDB]
	CoInitialize(NULL);
[!endif]
[!if SOCKETS]
	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

[!endif]
[!if CONTAINER || MINI_SERVER || FULL_SERVER || CONTAINER_SERVER || AUTOMATION || OLEDB || ACTIVEX_CONTROLS || ACCESSIBILITY]
	// Inicializar bibliotecas OLE
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
[!endif]
[!if ACTIVEX_CONTROLS]
	AfxEnableControlContainer();
[!endif]
	// Inicializaci�n est�ndar
	// Si no utiliza estas caracter�sticas y desea reducir el tama�o
	// del archivo ejecutable final, debe quitar
	// las rutinas de inicializaci�n espec�ficas que no necesite
	// Cambie la clave del Registro en la que se almacena la configuraci�n
	// TODO: debe modificar esta cadena para que contenga informaci�n correcta
	// como el nombre de su compa��a u organizaci�n
	SetRegistryKey(_T("Aplicaciones generadas con el Asistente para aplicaciones local"));
[!if DOCVIEW]
	LoadStdProfileSettings([!output MRU_SIZE]);  // Cargar opciones de archivo INI est�ndar (incluidas las de la lista MRU)
[!endif]
[!if !DOCVIEW]
	// Para crear la ventana principal, este c�digo crea un nuevo objeto de ventana
	// de marco y, a continuaci�n, lo establece como el objeto de ventana principal de la aplicaci�n
[!if  APP_TYPE_MDI]
	CMDIFrameWnd* pFrame = new [!output MAIN_FRAME_CLASS];
[!else]
[!if !DOCVIEW]
	CMainFrame* pFrame = new [!output MAIN_FRAME_CLASS];
[!else]
	CRuntimeClass* pClass = RUNTIME_CLASS(CMainFrame);
	CFrameWnd* pFrame = (CFrameWnd*) pClass->CreateObject();
	ASSERT_KINDOF(CFrameWnd, pFrame);
[!endif]
[!endif]
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
[!if APP_TYPE_SDI]
[!if DOCVIEW]
	// Cargar el marco en un contexto vac�o
	CCreateContext context;
[!else]
	// Crear y cargar el marco con sus recursos
[!endif]
	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
[!if DOCVIEW]
		&context);
[!else]
		NULL);
[!endif]
[!else]
	// Crear ventana de marco principal MDI
	if (!pFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	// Intentar cargar tabla de aceleradores y men�s MDI compartidos
	//TODO: agregar variables de miembro adicionales y cargar llamadas para
	//	tipos de men� adicionales que pueda necesitar la aplicaci�n
	HINSTANCE hInst = AfxGetResourceHandle();
	m_hMDIMenu  = ::LoadMenu(hInst, MAKEINTRESOURCE(IDR_[!output SAFE_DOC_TYPE_NAME]TYPE));
	m_hMDIAccel = ::LoadAccelerators(hInst, MAKEINTRESOURCE(IDR_[!output SAFE_DOC_TYPE_NAME]TYPE));
[!endif]
[!else]
	// Registrar las plantillas de documento de la aplicaci�n. Las plantillas de documento
	//  sirven como conexi�n entre documentos, ventanas de marco y vistas
[!if APP_TYPE_MDI]
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_[!output SAFE_DOC_TYPE_NAME]TYPE,
[!else]
[!if APP_TYPE_MTLD]
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(
		IDR_MAINFRAME,
[!else]
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
[!endif]
[!endif]
		RUNTIME_CLASS([!output DOC_CLASS]),
[!if APP_TYPE_MDI]
		RUNTIME_CLASS([!output CHILD_FRAME_CLASS]), // Marco MDI secundario personalizado
[!else]
		RUNTIME_CLASS([!output MAIN_FRAME_CLASS]),       // Ventana de marco MDI principal
[!endif]
[!if PROJECT_STYLE_EXPLORER]
		RUNTIME_CLASS([!output TREE_VIEW_CLASS]));
[!else]
		RUNTIME_CLASS([!output VIEW_CLASS]));
[!endif]
	if (!pDocTemplate)
		return FALSE;
[!if CONTAINER || CONTAINER_SERVER]
[!if APP_TYPE_MDI]
	pDocTemplate->SetContainerInfo(IDR_[!output SAFE_DOC_TYPE_NAME]TYPE_CNTR_IP);
[!else]
	pDocTemplate->SetContainerInfo(IDR_CNTR_INPLACE);
[!endif]
[!endif]
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]
	pDocTemplate->SetServerInfo(
[!if APP_TYPE_MDI]
		IDR_[!output SAFE_DOC_TYPE_NAME]TYPE_SRVR_EMB, IDR_[!output SAFE_DOC_TYPE_NAME]TYPE_SRVR_IP,
[!else]
		IDR_SRVR_EMBEDDED, IDR_SRVR_INPLACE,
[!endif]
		RUNTIME_CLASS([!output INPLACE_FRAME_CLASS]));
[!endif]
[!if APP_TYPE_MTLD]
	m_pDocTemplate = pDocTemplate;
[!endif]
	AddDocTemplate(pDocTemplate);
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER || AUTOMATION]
	// Conectar COleTemplateServer con la plantilla de documento
	//  COleTemplateServer crea nuevos documentos
	//  en nombre de contenedores  OLE de solicitud utilizando informaci�n
	//  especificada en la plantilla de documento
[!if APP_TYPE_MDI || APP_TYPE_MTLD]
	m_server.ConnectTemplate(clsid, pDocTemplate, FALSE);
	// Registrar todos los generadores de servidores OLE mientras se ejecutan. De este modo se habilitan
	//  las bibliotecas OLE para crear objetos desde otras aplicaciones
	COleTemplateServer::RegisterAll();
		// Nota: las aplicaciones MDI registran todos los objetos de servidor independientemente de
		//  los modificadores /Embedding o /Automation de la l�nea de comandos
[!else]
	m_server.ConnectTemplate(clsid, pDocTemplate, TRUE);
		// Nota: las aplicaciones SDI s�lo registran los objetos de servidor si el modificador
		//  /Embedding o /Automation est� presente en la l�nea de comandos
[!endif]
[!endif]
[!endif]

[!if APP_TYPE_MDI && DOCVIEW]
	// Crear ventana de marco principal MDI
	[!output MAIN_FRAME_CLASS]* pMainFrame = new [!output MAIN_FRAME_CLASS];
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;
[!if !MINI_SERVER]
	// Llamar a DragAcceptFiles s�lo si existe un sufijo
	//  En una aplicaci�n MDI, esto debe ocurrir inmediatamente despu�s de establecer m_pMainWnd
[!if HAS_SUFFIX && !HTML_EDITVIEW]
	// Habilitar apertura de arrastrar y colocar
	m_pMainWnd->DragAcceptFiles();
[!endif]
[!endif]
[!endif]

[!if !MINI_SERVER]
[!if HAS_SUFFIX && !HTML_EDITVIEW]
	// Habilitar apertura de ejecuci�n DDE
	EnableShellOpen();
	RegisterShellFileTypes(TRUE);
[!endif]
[!endif]

[!if DOCVIEW]
	// Analizar l�nea de comandos para comandos Shell est�ndar, DDE, Archivo Abrir
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);
[!endif]

[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER || AUTOMATION]
	// La aplicaci�n se inici� con el modificador /Embedding o /Automation.
	// Ejecutar la aplicaci�n como servidor de automatizaci�n.
	if (cmdInfo.m_bRunEmbedded || cmdInfo.m_bRunAutomated)
	{
[!if !APP_TYPE_MDI && !APP_TYPE_MTLD]
		// Registrar todos los generadores del servidor OLE al ejecutarse. De esta forma, las bibliotecas OLE
		//  pueden crear objetos a partir de otras aplicaciones
		COleTemplateServer::RegisterAll();

[!endif]
		// No mostrar la ventana principal
		return TRUE;
	}
	// La aplicaci�n se inici� con el modificador /Unregserver o /Unregister. Anular el registro de
	// la biblioteca de tipos. Se producir�n otras cancelaciones de registro en ProcessShellCommand().
	else if (cmdInfo.m_nShellCommand == CCommandLineInfo::AppUnregister)
	{
[!if !MINI_SERVER]
[!if HAS_SUFFIX && !HTML_EDITVIEW]
		UnregisterShellFileTypes();
[!endif]
[!endif]
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]
[!if ACTIVE_DOC_SERVER]
		m_server.UpdateRegistry(OAT_DOC_OBJECT_SERVER, NULL, NULL, FALSE);
[!else]
		m_server.UpdateRegistry(OAT_INPLACE_SERVER, NULL, NULL, FALSE);
[!endif]
[!else]
[!if AUTOMATION]
		m_server.UpdateRegistry(OAT_DISPATCH_OBJECT, NULL, NULL, FALSE);
[!endif]
[!endif]
[!if AUTOMATION]
		AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor);
[!endif]
[!if MINI_SERVER]
		return FALSE;
[!endif]
	}
	// La aplicaci�n se inici� en modo independiente o con otros modificadores (por ejemplo /Register
	// o /Regserver). Actualizar entradas de Registro, incluida typelibrary.
	else
	{
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]
[!if ACTIVE_DOC_SERVER]
		m_server.UpdateRegistry(OAT_DOC_OBJECT_SERVER);
[!else]
		m_server.UpdateRegistry(OAT_INPLACE_SERVER);
[!endif]
[!else]
[!if AUTOMATION]
		m_server.UpdateRegistry(OAT_DISPATCH_OBJECT);
[!endif]
[!endif]
[!if AUTOMATION]
		COleObjectFactory::UpdateRegistryAll();
		AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid);
[!endif]
[!if MINI_SERVER]
		if (cmdInfo.m_nShellCommand == CCommandLineInfo::AppRegister)
			return FALSE;
[!endif]
	}
[!endif]

[!if MINI_SERVER]
	// Cuando un miniservidor se ejecuta en modo independiente se actualiza el Registro y
	//  se indica al usuario que utilice el cuadro de di�logo Insertar objeto en un contenedor
	//  para utilizar el servidor. Los miniservidores no tienen interfaces de usuario independientes
	AfxMessageBox(IDP_USE_INSERT_OBJECT);
	return FALSE;
[!else]
[!if DOCVIEW]
	// Enviar comandos especificados en la l�nea de comandos. Devolver� FALSE si
	// la aplicaci�n se inici� con los modificadores /RegServer, /Register, /Unregserver o /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
[!endif]
[!if APP_TYPE_MDI]
	// La ventana principal se ha inicializado; mostrarla y actualizarla
[!if DOCVIEW]
[!if MAIN_FRAME_MAXIMIZED]
	pMainFrame->ShowWindow(SW_SHOWMAXIMIZED);
[!else]
[!if MAIN_FRAME_MINIMIZED]
	pMainFrame->ShowWindow(SW_SHOWMINIMIZED);
[!else]
[!if APP_TYPE_SDI || APP_TYPE_MTLD]
	pMainFrame->ShowWindow(SW_SHOW);
[!else]
	pMainFrame->ShowWindow(m_nCmdShow);
[!endif]
[!endif]
[!endif]
	pMainFrame->UpdateWindow();
[!else]
[!if MAIN_FRAME_MAXIMIZED]
	pFrame->ShowWindow(SW_SHOWMAXIMIZED);
[!else]
[!if MAIN_FRAME_MINIMIZED]
	pFrame->ShowWindow(SW_SHOWMINIMIZED);
[!else]
[!if APP_TYPE_SDI || APP_TYPE_MTLD]
	pFrame->ShowWindow(SW_SHOW);
[!else]
	pFrame->ShowWindow(m_nCmdShow);
[!endif]
[!endif]
[!endif]
	pFrame->UpdateWindow();
[!endif]
[!endif]

[!if APP_TYPE_SDI || APP_TYPE_MTLD]
	// Se ha inicializado la �nica ventana; mostrarla y actualizarla
[!if DOCVIEW]
[!if MAIN_FRAME_MAXIMIZED]
	m_pMainWnd->ShowWindow(SW_SHOWMAXIMIZED);
[!else]
[!if MAIN_FRAME_MINIMIZED]
	m_pMainWnd->ShowWindow(SW_SHOWMINIMIZED);
[!else]
[!if APP_TYPE_SDI || APP_TYPE_MTLD]
	m_pMainWnd->ShowWindow(SW_SHOW);
[!else]
	m_pMainWnd->ShowWindow(m_nCmdShow);
[!endif]
[!endif]
[!endif]
	m_pMainWnd->UpdateWindow();
[!else]
[!if MAIN_FRAME_MAXIMIZED]
	pFrame->ShowWindow(SW_SHOWMAXIMIZED);
[!else]
[!if MAIN_FRAME_MINIMIZED]
	pFrame->ShowWindow(SW_SHOWMINIMIZED);
[!else]
[!if APP_TYPE_SDI || APP_TYPE_MTLD]
	pFrame->ShowWindow(SW_SHOW);
[!else]
	pFrame->ShowWindow(m_nCmdShow);
[!endif]
[!endif]
[!endif]
	pFrame->UpdateWindow();
[!endif]
	// Llamar a DragAcceptFiles s�lo si existe un sufijo
	//  En una aplicaci�n SDI, esto debe ocurrir despu�s de ProcessShellCommand
[!if HAS_SUFFIX && !HTML_EDITVIEW]
	// Habilitar apertura de arrastrar y colocar
	m_pMainWnd->DragAcceptFiles();
[!endif]
[!endif]
	return TRUE;
[!endif]
}

[!if !DOCVIEW]

// Controladores de mensaje de [!output APP_CLASS]

[!if APP_TYPE_MDI]
[!if !DOCVIEW]
int [!output APP_CLASS]::ExitInstance() 
{
	//TODO: controlar recursos adicionales que se hayan podido agregar
	if (m_hMDIMenu != NULL)
		FreeResource(m_hMDIMenu);
	if (m_hMDIAccel != NULL)
		FreeResource(m_hMDIAccel);

	return CWinApp::ExitInstance();
}
[!endif]
[!endif]

[!if APP_TYPE_MDI || DOCVIEW]
void [!output APP_CLASS]::OnFileNew() 
{
[!if APP_TYPE_SDI]
	CString strUntitled;
	CFrameWnd* pFrameWnd = DYNAMIC_DOWNCAST(CFrameWnd, m_pMainWnd);
	if (pFrameWnd != NULL)
	{
		//TODO: cerrar y destruir cualquier dato espec�fico de archivo que existe en
		// memoria. A continuaci�n, ejecutar la siguiente instrucci�n if
		// para restablecer el t�tulo de la ventana de marco
		if (strUntitled.LoadString(AFX_IDS_UNTITLED))
			pFrameWnd->UpdateFrameTitleForDocument(strUntitled);
		else
			pFrameWnd->UpdateFrameTitleForDocument(NULL);
	}
[!else]
	[!output MAIN_FRAME_CLASS]* pFrame = STATIC_DOWNCAST([!output MAIN_FRAME_CLASS], m_pMainWnd);
	// Crear una nueva ventana MDI secundaria
	pFrame->CreateNewChild(
		RUNTIME_CLASS(CChildFrame), IDR_[!output SAFE_DOC_TYPE_NAME]TYPE, m_hMDIMenu, m_hMDIAccel);
[!endif]
}
[!endif]
[!endif]


// Cuadro de di�logo CAboutDlg utilizado para el comando Acerca de

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Datos del cuadro de di�logo
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

// Implementaci�n
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

// Comando de la aplicaci�n para ejecutar el cuadro de di�logo
void [!output APP_CLASS]::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


// Controladores de mensaje de [!output APP_CLASS]

[!if APP_TYPE_MTLD]
[!if DOCVIEW]
void [!output APP_CLASS]::OnFileNewFrame() 
{
	ASSERT(m_pDocTemplate != NULL);

	CDocument* pDoc = NULL;
	CFrameWnd* pFrame = NULL;

	// Crear una nueva instancia del documento al que hace referencia
	// el miembro m_pDocTemplate. 
	pDoc = m_pDocTemplate->CreateNewDocument();
	if (pDoc != NULL)
	{
		// Si la creaci�n funcion�, cree un nuevo marco
		// para ese documento.
		pFrame = m_pDocTemplate->CreateNewFrame(pDoc, NULL);
		if (pFrame != NULL)
		{
			// Establecer el t�tulo e inicializar el documento.
			// Si la inicializaci�n del documento falla, limpiar
			// la ventana de marco y el documento.

			m_pDocTemplate->SetDefaultTitle(pDoc);
			if (!pDoc->OnNewDocument())
			{
				pFrame->DestroyWindow();
				pFrame = NULL;
			}
			else
			{
				// De lo contrario, actualizar el marco
				m_pDocTemplate->InitialUpdateFrame(pFrame, pDoc, TRUE);
			}
		}
	}

	// Si hay alg�n error, limpiar el documento y mostrar
	// un mensaje al usuario.

	if (pFrame == NULL || pDoc == NULL)
	{
		delete pDoc;
		AfxMessageBox(AFX_IDP_FAILED_TO_CREATE_DOC);
	}
}

void [!output APP_CLASS]::OnFileNew() 
{
	CDocument* pDoc = NULL;
	CFrameWnd* pFrame;
	pFrame = DYNAMIC_DOWNCAST(CFrameWnd, CWnd::GetActiveWindow());
	
	if (pFrame != NULL)
		pDoc = pFrame->GetActiveDocument();

	if (pFrame == NULL || pDoc == NULL)
	{
		// Si es el primer documento, crear como normal
		CWinApp::OnFileNew();
	}
	else
	{
		// De lo contrario, ver si se deben guardar los cambios, y
		// pedir al documento que se reinicialice.
		if (!pDoc->SaveModified())
			return;

		CDocTemplate* pTemplate = pDoc->GetDocTemplate();
		ASSERT(pTemplate != NULL);

		pTemplate->SetDefaultTitle(pDoc);
		pDoc->OnNewDocument();
	}
}
[!else]
void [!output APP_CLASS]::OnFileNewFrame() 
{
	CMainFrame* pFrame = new CMainFrame;
	pFrame->LoadFrame(IDR_MAINFRAME, WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, 
					  NULL, NULL);
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	m_aryFrames.Add(pFrame->GetSafeHwnd());
}
[!endif]
[!endif]
