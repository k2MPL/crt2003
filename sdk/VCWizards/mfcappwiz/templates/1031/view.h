// [!output VIEW_HEADER] : Schnittstelle der Klasse [!output VIEW_CLASS]
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
protected: // Nur aus Serialisierung erstellen
	[!output VIEW_CLASS]();
	DECLARE_DYNCREATE([!output VIEW_CLASS])
[!if OLEDB_RECORD_VIEW || FORM_VIEW || ODBC_RECORD_VIEW]

public:
	enum{ IDD = IDD_[!output UPPER_CASE_SAFE_PROJECT_NAME]_FORM };
[!if OLEDB_RECORD_VIEW || ODBC_RECORD_VIEW]
	[!output ROWSET_CLASS]* m_pSet;
[!endif]
[!endif]

// Attribute
public:
	[!output DOC_CLASS]* GetDocument() const;
[!if CONTAINER || CONTAINER_SERVER]
[!if !RICH_EDIT_VIEW]
	// m_pSelection enth�lt die Auswahl des aktuellen [!output CONTAINER_ITEM_CLASS]-Objekts.
	// F�r viele Anwendungen ist eine derartige Membervariable nicht angemessen, um
	//  z.B. eine Mehrfachauswahl oder eine Auswahl von Objekten zu repr�sentieren,
	//  die keine [!output CONTAINER_ITEM_CLASS]-Objekte sind. Dieser Auswahlmechanismus
	//  dient nur dazu, Ihnen bei den ersten Schritten zu helfen.

	// TODO: Ersetzen Sie diesen Auswahlmechanismus durch einen f�r Ihre Anwendung geeigneten.
	[!output CONTAINER_ITEM_CLASS]* m_pSelection;
[!endif]
[!endif]

// Operationen
public:

// �berschreibungen
	public:
[!if OLEDB_RECORD_VIEW]
	virtual CRowset<>* OnGetRowset();
[!endif]
[!if ODBC_RECORD_VIEW]
	virtual CRecordset* OnGetRecordset();
[!endif]
[!if !TREE_VIEW && !LIST_VIEW && !HTML_VIEW && !HTML_EDITVIEW && !RICH_EDIT_VIEW && !EDIT_VIEW && !FORM_VIEW && !OLEDB_RECORD_VIEW && !ODBC_RECORD_VIEW]
	virtual void OnDraw(CDC* pDC);  // �berladen, um diese Ansicht darzustellen
[!endif] 
[!if PRINTING]
[!if TREE_VIEW || LIST_VIEW]
	virtual void OnDraw(CDC* pDC);  // �berladen, um diese Ansicht darzustellen
[!endif]
[!endif]
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
[!if FORM_VIEW || OLEDB_RECORD_VIEW || ODBC_RECORD_VIEW]
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterst�tzung
[!endif] 
[!if SCROLL_VIEW || CONTAINER || CONTAINER_SERVER || OLEDB_RECORD_VIEW || TREE_VIEW || LIST_VIEW || FORM_VIEW || HTML_VIEW || ODBC_RECORD_VIEW]
	virtual void OnInitialUpdate(); // Erster Aufruf nach Erstellung
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
	virtual BOOL IsSelected(const CObject* pDocItem) const;// Container-Unterst�tzung
[!endif]
[!endif]

// Implementierung
public:
	virtual ~[!output VIEW_CLASS]();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generierte Funktionen f�r die Meldungstabellen
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

#ifndef _DEBUG  // Debugversion in [!output VIEW_IMPL]
inline [!output DOC_CLASS]* [!output VIEW_CLASS]::GetDocument() const
   { return reinterpret_cast<[!output DOC_CLASS]*>(m_pDocument); }
#endif

