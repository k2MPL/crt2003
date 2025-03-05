// [!output VIEW_HEADER]: interfaz de la clase [!output VIEW_CLASS]
//


#pragma once

[!if CONTAINER || CONTAINER_SERVER]
class [!output CONTAINER_ITEM_CLASS];
[!endif]
[!if OLEDB_RECORD_VIEW || ODBC_RECORD_VIEW]
class [!output ROWSET_CLASS];
[!endif]

class [!output VIEW_CLASS] : public [!output VIEW_BASE_CLASS]
{
protected: // Crear s�lo a partir de serializaci�n
	[!output VIEW_CLASS]();
	DECLARE_DYNCREATE([!output VIEW_CLASS])
[!if OLEDB_RECORD_VIEW || FORM_VIEW || ODBC_RECORD_VIEW]

public:
	enum{ IDD = IDD_[!output UPPER_CASE_SAFE_PROJECT_NAME]_FORM };
[!if OLEDB_RECORD_VIEW || ODBC_RECORD_VIEW]
	[!output ROWSET_CLASS]* m_pSet;
[!endif]
[!endif]

// Atributos
public:
	[!output DOC_CLASS]* GetDocument() const;
[!if CONTAINER || CONTAINER_SERVER]
[!if !RICH_EDIT_VIEW]
	// m_pSelection mantiene la selecci�n en la clase [!output CONTAINER_ITEM_CLASS] actual.
	// Para muchas aplicaciones, tal variable miembro no es adecuada
	//  para representar a una selecci�n, como una selecci�n m�ltiple o una selecci�n de
	//  objetos que no son objetos [!output CONTAINER_ITEM_CLASS]. Este mecanismo
	//  de selecci�n se proporciona para empezar

	// TODO: reemplazar este mecanismo de selecci�n con uno apropiado para la aplicaci�n
	[!output CONTAINER_ITEM_CLASS]* m_pSelection;
[!endif]
[!endif]

// Operaciones
public:

// Reemplazos
	public:
[!if OLEDB_RECORD_VIEW]
	virtual CRowset<>* OnGetRowset();
[!endif]
[!if ODBC_RECORD_VIEW]
	virtual CRecordset* OnGetRecordset();
[!endif]
[!if !TREE_VIEW && !LIST_VIEW && !HTML_VIEW && !HTML_EDITVIEW && !RICH_EDIT_VIEW && !EDIT_VIEW && !FORM_VIEW && !OLEDB_RECORD_VIEW && !ODBC_RECORD_VIEW]
	virtual void OnDraw(CDC* pDC);  // Reemplazado para dibujar esta vista
[!endif] 
[!if PRINTING]
[!if TREE_VIEW || LIST_VIEW]
	virtual void OnDraw(CDC* pDC);  // Reemplazado para dibujar esta vista
[!endif]
[!endif]
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
[!if FORM_VIEW || OLEDB_RECORD_VIEW || ODBC_RECORD_VIEW]
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV
[!endif] 
[!if SCROLL_VIEW || CONTAINER || CONTAINER_SERVER || OLEDB_RECORD_VIEW || TREE_VIEW || LIST_VIEW || FORM_VIEW || HTML_VIEW || ODBC_RECORD_VIEW]
	virtual void OnInitialUpdate(); // Se llama la primera vez despu�s de la construcci�n
[!endif]
[!if PRINTING]
[!if !HTML_VIEW && !HTML_EDITVIEW]
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
[!endif]
[!if !RICH_EDIT_VIEW && !HTML_VIEW && !HTML_EDITVIEW]
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
[!endif]
[!if FORM_VIEW || ACTIVE_DOC_CONTAINER]
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
[!endif]
[!endif]
[!if CONTAINER || CONTAINER_SERVER]
[!if !RICH_EDIT_VIEW]
	virtual BOOL IsSelected(const CObject* pDocItem) const;// Compatibilidad con contenedores
[!endif]
[!endif]

// Implementaci�n
public:
	virtual ~[!output VIEW_CLASS]();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Funciones de asignaci�n de mensajes generadas
protected:
[!if CONTAINER || CONTAINER_SERVER]
	afx_msg void OnDestroy();
[!if !RICH_EDIT_VIEW]
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnInsertObject();
	afx_msg void OnCancelEditCntr();
	afx_msg void OnFilePrint();
[!endif]
[!endif]
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]
	afx_msg void OnCancelEditSrvr();
[!endif]
[!if PROJECT_STYLE_EXPLORER]
[!if LIST_VIEW]
	afx_msg void OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
[!endif]
[!endif]
[!if ACTIVE_DOC_CONTAINER]
	afx_msg void OnFilePrintPreview();
	afx_msg void OnFilePrintPreviewUIUpdate(CCmdUI* pCmdUI);
[!endif]
[!if HTML_EDITVIEW]
	DECLARE_DHTMLEDITING_CMDMAP([!output VIEW_CLASS])
[!endif]
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Versi�n de depuraci�n en [!output VIEW_IMPL]
inline [!output DOC_CLASS]* [!output VIEW_CLASS]::GetDocument() const
   { return reinterpret_cast<[!output DOC_CLASS]*>(m_pDocument); }
#endif

