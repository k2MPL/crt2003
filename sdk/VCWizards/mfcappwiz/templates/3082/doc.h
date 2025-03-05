// [!output DOC_HEADER]: interfaz de la clase [!output DOC_CLASS]
//


#pragma once
[!if OLEDB_RECORD_VIEW || ODBC_RECORD_VIEW]
#include "[!output ROWSET_HEADER]"
[!endif]

[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]

class [!output SERVER_ITEM_CLASS];
[!endif]

class [!output DOC_CLASS] : public [!output DOC_BASE_CLASS]
{
protected: // Crear s�lo a partir de serializaci�n
	[!output DOC_CLASS]();
	DECLARE_DYNCREATE([!output DOC_CLASS])

// Atributos
public:
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]
	[!output SERVER_ITEM_CLASS]* GetEmbeddedItem()
		{ return reinterpret_cast<[!output SERVER_ITEM_CLASS]*>([!output DOC_BASE_CLASS]::GetEmbeddedItem()); }
[!endif]
[!if OLEDB_RECORD_VIEW || ODBC_RECORD_VIEW]
	[!output ROWSET_CLASS] [!output ROWSET_CLASS_VARIABLE_NAME];
[!endif]

// Operaciones
public:

// Reemplazos
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]
	protected:
	virtual COleServerItem* OnGetEmbeddedItem();
[!endif]
	public:
	virtual BOOL OnNewDocument();
[!if !DB_VIEW_NO_FILE && !HTML_EDITVIEW]
	virtual void Serialize(CArchive& ar);
[!endif]
[!if RICH_EDIT_VIEW]
	virtual [!output CONTAINER_ITEM_BASE_CLASS]* CreateClientItem(REOBJECT* preo) const;
[!endif]

// Implementaci�n
public:
	virtual ~[!output DOC_CLASS]();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
[!if ACTIVE_DOC_SERVER]
	virtual CDocObjectServer* GetDocObjectServer(LPOLEDOCUMENTSITE pDocSite);
[!endif]

// Funciones de asignaci�n de mensajes generadas
protected:
	DECLARE_MESSAGE_MAP()
[!if AUTOMATION]

	// Funciones de asignaci�n de env�o OLE generadas

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
[!endif]
};


