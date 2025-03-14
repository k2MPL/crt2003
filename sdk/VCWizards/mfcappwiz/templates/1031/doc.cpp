// [!output DOC_IMPL] : Implementierung der Klasse [!output DOC_CLASS]
//

#include "stdafx.h"
#include "[!output APP_HEADER]"

[!if OLEDB_RECORD_VIEW || ODBC_RECORD_VIEW]
#include "[!output ROWSET_HEADER]"
[!endif]
#include "[!output DOC_HEADER]"
[!if CONTAINER || CONTAINER_SERVER]
#include "[!output CONTAINER_ITEM_HEADER]"
[!endif]
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]
#include "[!output SERVER_ITEM_HEADER]"
[!endif]

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// [!output DOC_CLASS]

IMPLEMENT_DYNCREATE([!output DOC_CLASS], [!output DOC_BASE_CLASS])

BEGIN_MESSAGE_MAP([!output DOC_CLASS], [!output DOC_BASE_CLASS])
[!if CONTAINER || CONTAINER_SERVER]
	// Zulassen der Standardimplementierung f�r OLE-Container
[!if !RICH_EDIT_VIEW]
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, [!output DOC_BASE_CLASS]::OnUpdatePasteMenu)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE_LINK, [!output DOC_BASE_CLASS]::OnUpdatePasteLinkMenu)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_CONVERT, [!output DOC_BASE_CLASS]::OnUpdateObjectVerbMenu)
	ON_COMMAND(ID_OLE_EDIT_CONVERT, [!output DOC_BASE_CLASS]::OnEditConvert)
[!endif]
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, [!output DOC_BASE_CLASS]::OnUpdateEditLinksMenu)
	ON_COMMAND(ID_OLE_EDIT_LINKS, [!output DOC_BASE_CLASS]::OnEditLinks)
	ON_UPDATE_COMMAND_UI_RANGE(ID_OLE_VERB_FIRST, ID_OLE_VERB_LAST, [!output DOC_BASE_CLASS]::OnUpdateObjectVerbMenu)
[!endif]
[!if MAPI]
	ON_COMMAND(ID_FILE_SEND_MAIL, OnFileSendMail)
	ON_UPDATE_COMMAND_UI(ID_FILE_SEND_MAIL, OnUpdateFileSendMail)
[!endif]
END_MESSAGE_MAP()

[!if AUTOMATION]
BEGIN_DISPATCH_MAP([!output DOC_CLASS], [!output DOC_BASE_CLASS])
END_DISPATCH_MAP()

// Hinweis: Wir stellen Unterst�tzung f�r IID_I[!output SAFE_PROJECT_NAME] zur Verf�gung, um typsicheres Binden 
//  von VBA zu unterst�tzen. Diese IID muss mit der GUID �bereinstimmen, die bei der 
//  Disp-Schnittstelle in der .IDL-Datei angegeben ist.

// {[!output DISPIID_REGISTRY_FORMAT]}
static const IID IID_I[!output SAFE_PROJECT_NAME] =
[!output DISPIID_STATIC_CONST_GUID_FORMAT];

BEGIN_INTERFACE_MAP([!output DOC_CLASS], [!output DOC_BASE_CLASS])
	INTERFACE_PART([!output DOC_CLASS], IID_I[!output SAFE_PROJECT_NAME], Dispatch)
END_INTERFACE_MAP()

[!endif]

// [!output DOC_CLASS] Erstellung/Zerst�rung

[!output DOC_CLASS]::[!output DOC_CLASS]()
{
[!if SUPPORT_COMPOUND_FILES && !COMPOUND_DOC_NONE]
	// Verwenden Sie OLE-Compound-Dateien
	EnableCompoundFile();

[!endif]
	// TODO: Hier Code f�r One-Time-Konstruktion einf�gen

[!if AUTOMATION]
	EnableAutomation();

	AfxOleLockApp();
[!endif]
}

[!output DOC_CLASS]::~[!output DOC_CLASS]()
{
[!if AUTOMATION]
	AfxOleUnlockApp();
[!endif]
}

BOOL [!output DOC_CLASS]::OnNewDocument()
{
	if (![!output DOC_BASE_CLASS]::OnNewDocument())
		return FALSE;
[!if APP_TYPE_SDI]
[!if EDIT_VIEW]

	reinterpret_cast<CEditView*>(m_viewList.GetHead())->SetWindowText(NULL);
[!endif] 
[!endif] 

	// TODO: Hier Code zur Reinitialisierung einf�gen
	// (SDI-Dokumente verwenden dieses Dokument)

	return TRUE;
}
[!if RICH_EDIT_VIEW]

[!output CONTAINER_ITEM_BASE_CLASS]* [!output DOC_CLASS]::CreateClientItem(REOBJECT* preo) const
{
	return new [!output CONTAINER_ITEM_CLASS](preo, const_cast<[!output DOC_CLASS]*>(this));
}
[!endif]
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]


// [!output DOC_CLASS] Serverimplementierung

COleServerItem* [!output DOC_CLASS]::OnGetEmbeddedItem()
{
	// OnGetEmbeddedItem wird automatisch aufgerufen, um COleServerItem zu erhalten,
	//  das mit dem Dokument verkn�pft ist. Die Funktion wird nur bei Bedarf aufgerufen.

	[!output SERVER_ITEM_CLASS]* pItem = new [!output SERVER_ITEM_CLASS](this);
	ASSERT_VALID(pItem);
	return pItem;
}
[!endif]
[!if ACTIVE_DOC_SERVER]


// [!output DOC_CLASS] Active Document-Serverimplementierung

CDocObjectServer *[!output DOC_CLASS]::GetDocObjectServer(LPOLEDOCUMENTSITE pDocSite)
{
	return new CDocObjectServer(this, pDocSite);
}
[!endif]


[!if !DB_VIEW_NO_FILE && !HTML_EDITVIEW]


// [!output DOC_CLASS] Serialisierung

void [!output DOC_CLASS]::Serialize(CArchive& ar)
{
[!if EDIT_VIEW]
	// CEditView enth�lt ein Edit-Steuerelement, das die Serialisierung automatisch erledigt
	reinterpret_cast<CEditView*>(m_viewList.GetHead())->SerializeRaw(ar);
[!else]
	if (ar.IsStoring())
	{
		// TODO: Hier Code zum Speichern einf�gen
	}
	else
	{
		// TODO: Hier Code zum Laden einf�gen
	}
[!if CONTAINER || CONTAINER_SERVER]

	// Ein Aufruf der Basisklasse [!output DOC_BASE_CLASS] erm�glicht die Serialisierung
	//  des Objekts COleClientItem des Containerdokuments.
[!if RICH_EDIT_VIEW]
	// TODO: CRichEditDoc::m_bRTF = FALSE setzen, wenn Sie als Text serialisieren
[!endif] 
	[!output DOC_BASE_CLASS]::Serialize(ar);
[!if ACTIVE_DOC_CONTAINER]
	// activate the first one
	if (!ar.IsStoring())
	{
		POSITION posItem = GetStartPosition();
		if (posItem != NULL)
		{
			CDocItem* pItem = GetNextItem(posItem);
			POSITION posView = GetFirstViewPosition();
			COleDocObjectItem *pDocObjectItem = DYNAMIC_DOWNCAST(COleDocObjectItem, pItem);
			if (posView != NULL && pDocObjectItem != NULL)
			{
				CView* pView = GetNextView(posView);
				pDocObjectItem->DoVerb(OLEIVERB_SHOW, pView);
			}
		}
	}
[!endif]
[!endif]
[!endif]
}
[!endif]


// [!output DOC_CLASS] Diagnose

#ifdef _DEBUG
void [!output DOC_CLASS]::AssertValid() const
{
	[!output DOC_BASE_CLASS]::AssertValid();
}

void [!output DOC_CLASS]::Dump(CDumpContext& dc) const
{
	[!output DOC_BASE_CLASS]::Dump(dc);
}
#endif //_DEBUG


// [!output DOC_CLASS]-Befehle
