// [!output APP_IMPL] : �w�q���ε{�������O�欰�C
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
	// �̾ڤ��R�O���з��ɮ�
[!if !APP_TYPE_MTLD]
	ON_COMMAND(ID_FILE_NEW, [!output APP_BASE_CLASS]::OnFileNew)
[!endif]
	ON_COMMAND(ID_FILE_OPEN, [!output APP_BASE_CLASS]::OnFileOpen)
[!endif]
[!endif]
[!if PRINTING && DOCVIEW]
	// �зǦC�L�]�w�R�O
	ON_COMMAND(ID_FILE_PRINT_SETUP, [!output APP_BASE_CLASS]::OnFilePrintSetup)
[!endif]
END_MESSAGE_MAP()


// [!output APP_CLASS] �غc

[!output APP_CLASS]::[!output APP_CLASS]()
{
[!if CONTEXT_HELP && HELPSTYLE_HTML]
	EnableHtmlHelp();

[!endif]
	// TODO: �b���[�J�غc�{���X�A
	// �N�Ҧ����n����l�]�w�[�J InitInstance ��
}
[!if ATL_SUPPORT]
// ATL �Ҳժ���
CComModule _Module;
[!endif]


// �Ȧ����@�� [!output APP_CLASS] ����

[!output APP_CLASS] theApp;
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER || AUTOMATION]
// ��z�����ε{�����Ͳέp�W�ߤ@���ѧO�X�A�p�G�z�Q��ܯS�w���ѧO�X�A
// �i�H�ܧ��ѧO�X

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

// [!output APP_CLASS] ��l�]�w

BOOL [!output APP_CLASS]::InitInstance()
{
[!if MANIFEST]
	// ���p���ε{����T�M����w�ϥ� ComCtl32.dll 6.0 (�t) �H�᪩��
	// �H�ҥε�ı�Ƽ˦��A�h Windows XP �ݭn InitCommonControls()�C�_�h���ܡA
	// ����������إ߱N���ѡC
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
	// ��l�� OLE �{���w
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
[!endif]
[!if ACTIVEX_CONTROLS]
	AfxEnableControlContainer();
[!endif]
	// �зǪ�l�]�w
	// �p�G�z���ϥγo�ǥ\��åB�Q��ֳ̫᧹�����i�����ɤj�p�A�z�i�H�q�U�C
	// �{���X�������ݭn����l�Ʊ`���A�ܧ��x�s�]�w�Ȫ��n�����X
	// TODO: �z���ӾA�׭ק惡�r�� (�Ҧp�A���q�W�٩β�´�W��)
	SetRegistryKey(_T("���� AppWizard �Ҳ��ͪ����ε{��"));
[!if DOCVIEW]
	LoadStdProfileSettings([!output MRU_SIZE]);  // ���J�з� INI �ɿﶵ (�]�t MRU)
[!endif]
[!if !DOCVIEW]
	// �Y�n�إߥD�����A���{���X�إ߷s���ج[��������A�B�N��]�w��
	// ���ε{�����D��������
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
	// ���J�ج[�A����Ť��e
	CCreateContext context;
[!else]
	// �ϥΨ�귽�إߨø��J�ج[
[!endif]
	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
[!if DOCVIEW]
		&context);
[!else]
		NULL);
[!endif]
[!else]
	// �إߥD MDI �ج[����
	if (!pFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	// ���ո��J�@�Ϊ� MDI �\���P�����������
	//TODO: �[�J��L�����ܼƨø��J���L�z�{���һݥ\����������I�s
	HINSTANCE hInst = AfxGetResourceHandle();
	m_hMDIMenu  = ::LoadMenu(hInst, MAKEINTRESOURCE(IDR_[!output SAFE_DOC_TYPE_NAME]TYPE));
	m_hMDIAccel = ::LoadAccelerators(hInst, MAKEINTRESOURCE(IDR_[!output SAFE_DOC_TYPE_NAME]TYPE));
[!endif]
[!else]
	// �n�����ε{�������d���C���d���t�d�b���B�ج[�����P�˵����i��s��
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
		RUNTIME_CLASS([!output CHILD_FRAME_CLASS]), // �ۭq MDI �l�ج[
[!else]
		RUNTIME_CLASS([!output MAIN_FRAME_CLASS]),       // �D SDI �ج[����
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
	// �N COleTemplateServer �s���ܤ��d��
	// COleTemplateServer �ϥΤ��d�����ҫ��w����T�A�إ߷s�����
	// �@���n�D OLE �e�����N��
[!if APP_TYPE_MDI || APP_TYPE_MTLD]
	m_server.ConnectTemplate(clsid, pDocTemplate, FALSE);
	// �n���Ҧ� OLE ���A���]�Ƭ����椤�C�o�� OLE �{���w�i�H�q��L���ε{���إߪ���
	COleTemplateServer::RegisterAll();
		// �`�N: MDI ���ε{�����שR�O�C�W���O�_�� /Embedding �� /Automation�A
		// �|�n���Ҧ������A������
[!else]
	m_server.ConnectTemplate(clsid, pDocTemplate, TRUE);
		// �`�N: SDI ���ε{���u�n���R�O�C�W�� /Embedding �� /Automation
		// �����A������
[!endif]
[!endif]
[!endif]

[!if APP_TYPE_MDI && DOCVIEW]
	// �إߥD MDI �ج[����
	[!output MAIN_FRAME_CLASS]* pMainFrame = new [!output MAIN_FRAME_CLASS];
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;
[!if !MINI_SERVER]
	// �u���b MDI ���ε{��������m�r���ɡA�~�I�s DragAcceptFiles
	// �o�|�ߧY�o�ͦb�]�w m_pMainWnd ����
[!if HAS_SUFFIX && !HTML_EDITVIEW]
	// �ҥΩ��}��
	m_pMainWnd->DragAcceptFiles();
[!endif]
[!endif]
[!endif]

[!if !MINI_SERVER]
[!if HAS_SUFFIX && !HTML_EDITVIEW]
	// �ҥ� DDE ����}��
	EnableShellOpen();
	RegisterShellFileTypes(TRUE);
[!endif]
[!endif]

[!if DOCVIEW]
	// ��R�з� Shell �R�O�BDDE�B�ɮ׶}�����ɪ��R�O�C
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);
[!endif]

[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER || AUTOMATION]
	// �w�ϥ� /Embedding �� /Automation �ѼƱҰ����ε{���C
	// �N���ε{����@ Automation ���A������C
	if (cmdInfo.m_bRunEmbedded || cmdInfo.m_bRunAutomated)
	{
[!if !APP_TYPE_MDI && !APP_TYPE_MTLD]
		// ���U�Ҧ� OLE ���A�{�� Factory �����b����C�o�˥i�H��
		//  OLE �{���w�ۨ�L�����ε{���إߪ���
		COleTemplateServer::RegisterAll();

[!endif]
		// ���n��ܥD�n����
		return TRUE;
	}
	// �w�ϥ� /Unregserver �� /Unregister �ѼƱҰ����ε{���C�Ѱ��n��
	// ���O�{���w�C��L�Ѱ��n���o�ͩ� ProcessShellCommand()�C
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
	// �w��W�ηf�t��L�Ѽ� (�p /Register �� /Regserver) �Ұ����ε{���C
	// ��s�n�����ءA�]�A���O�{���w�C
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
	// ���W����g�A���A���ɡA��s�n���B���ܨϥΪ̦b�e�����ϥ� [���J����] ��ܤ��
	// �Y�n�ϥΦ��A���C�g�A���A���S���W�ߪ��ϥΪ̤���
	AfxMessageBox(IDP_USE_INSERT_OBJECT);
	return FALSE;
[!else]
[!if DOCVIEW]
	// �b�R�O�C�����w�������R�O�C�p�G�w�ϥ� /RegServer�B/Register�B/Unregserver
	// �� /Unregister �Ұ����ε{���A�N�Ǧ^ FALSE
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
[!endif]
[!if APP_TYPE_MDI]
	// �w�g��l�]�w�D�����A�ҥH��ܨç�s�ӵ���
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
	// �Ȫ�l�Ƥ@�ӵ����A�ҥH��ܨç�s�ӵ���
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
	// �u���b SDI ���ε{��������m�r���ɡA�~�I�s DragAcceptFiles
	// �o�|�o�ͩ� ProcessShellCommand ����
[!if HAS_SUFFIX && !HTML_EDITVIEW]
	// �ҥΩ��}��
	m_pMainWnd->DragAcceptFiles();
[!endif]
[!endif]
	return TRUE;
[!endif]
}

[!if !DOCVIEW]

// [!output APP_CLASS] �T���B�z�`��

[!if APP_TYPE_MDI]
[!if !DOCVIEW]
int [!output APP_CLASS]::ExitInstance() 
{
	//TODO: �B�z��L�z�w�g�[�J���귽
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
		//TODO: �����úR������z�q�O����Ҩ��o�����S�w�ɮת���ơC
		// �@�������A�p�G���z�����]�ج[���������D�h����U�C
		if (strUntitled.LoadString(AFX_IDS_UNTITLED))
			pFrameWnd->UpdateFrameTitleForDocument(strUntitled);
		else
			pFrameWnd->UpdateFrameTitleForDocument(NULL);
	}
[!else]
	[!output MAIN_FRAME_CLASS]* pFrame = STATIC_DOWNCAST([!output MAIN_FRAME_CLASS], m_pMainWnd);
	// �إ߷s�� MDI �l����
	pFrame->CreateNewChild(
		RUNTIME_CLASS(CChildFrame), IDR_[!output SAFE_DOC_TYPE_NAME]TYPE, m_hMDIMenu, m_hMDIAccel);
[!endif]
}
[!endif]
[!endif]


// �� App About �ϥ� CAboutDlg ��ܤ��

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// ��ܤ�����
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

// �{���X��@
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

// �����ܤ�������ε{���R�O
void [!output APP_CLASS]::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


// [!output APP_CLASS] �T���B�z�`��

[!if APP_TYPE_MTLD]
[!if DOCVIEW]
void [!output APP_CLASS]::OnFileNewFrame() 
{
	ASSERT(m_pDocTemplate != NULL);

	CDocument* pDoc = NULL;
	CFrameWnd* pFrame = NULL;

	// �إ� m_pDocTemplate �����ҰѦҤ�󪺷s�������C
	pDoc = m_pDocTemplate->CreateNewDocument();
	if (pDoc != NULL)
	{
		// �p�G�إߥͮġA��Ӥ�����إ߷s���ج[�C
		pFrame = m_pDocTemplate->CreateNewFrame(pDoc, NULL);
		if (pFrame != NULL)
		{
			// �]�w���D�A�ê�l�]�w���C
			// �p�G����l�]�w���ѡA�M���ج[�����P���C

			m_pDocTemplate->SetDefaultTitle(pDoc);
			if (!pDoc->OnNewDocument())
			{
				pFrame->DestroyWindow();
				pFrame = NULL;
			}
			else
			{
				// �_�h�A��s�ج[
				m_pDocTemplate->InitialUpdateFrame(pFrame, pDoc, TRUE);
			}
		}
	}

	// �p�G�ڭ̥��ѡA�M�����æV�ϥΪ���ܰT���C

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
		// �p�G�O�Ĥ@�����A�إߦ��@����
		CWinApp::OnFileNew();
	}
	else
	{
		// �_�h�A�˵��O�_�x�s�w�ק諸�����A�M��n�D���s��l�����C
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
