// [!output CONTAINER_ITEM_IMPL] : Implementierung der Klasse [!output CONTAINER_ITEM_CLASS]
//

#include "stdafx.h"
#include "[!output APP_HEADER]"

[!if OLEDB_RECORD_VIEW || ODBC_RECORD_VIEW]
#include "[!output ROWSET_HEADER]"
[!endif]
#include "[!output DOC_HEADER]"
#include "[!output VIEW_HEADER]"
#include "[!output CONTAINER_ITEM_HEADER]"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// [!output CONTAINER_ITEM_CLASS]-Implementierung

IMPLEMENT_SERIAL([!output CONTAINER_ITEM_CLASS], [!output CONTAINER_ITEM_BASE_CLASS], 0)

[!if RICH_EDIT_VIEW]
[!output CONTAINER_ITEM_CLASS]::[!output CONTAINER_ITEM_CLASS](REOBJECT* preo, [!output DOC_CLASS]* pContainer)
	: [!output CONTAINER_ITEM_BASE_CLASS](preo, pContainer)
[!else]
[!output CONTAINER_ITEM_CLASS]::[!output CONTAINER_ITEM_CLASS]([!output DOC_CLASS]* pContainer)
	: [!output CONTAINER_ITEM_BASE_CLASS](pContainer)
[!endif]
{
	// TODO: Hier Code f�r One-Time-Konstruktion einf�gen
}

[!output CONTAINER_ITEM_CLASS]::~[!output CONTAINER_ITEM_CLASS]()
{
	// TODO: Hier Bereinigungscode hinzuf�gen
}
[!if !RICH_EDIT_VIEW]

void [!output CONTAINER_ITEM_CLASS]::OnChange(OLE_NOTIFICATION nCode, DWORD dwParam)
{
	ASSERT_VALID(this);

	[!output CONTAINER_ITEM_BASE_CLASS]::OnChange(nCode, dwParam);

	// Wird ein Element bearbeitet (entweder direkt oder voll ge�ffnet),
	//  sendet es OnChange-Benachrichtigungen f�r �nderungen des Elementstatus
	//  oder der visuellen Darstellung seines Inhalts.

	// TODO: Element ung�ltig machen, indem Sie UpdateAllViews aufrufen
	//  (mit auf Ihre Anwendung zugeschnittenen Tipps)

	GetDocument()->UpdateAllViews(NULL);
		// im Moment aktualisieren Sie einfach ALLE Ansichten/keine Tipps
}

BOOL [!output CONTAINER_ITEM_CLASS]::OnChangeItemPosition(const CRect& rectPos)
{
	ASSERT_VALID(this);

	// W�hrend einer direkten Aktivierung wird [!output CONTAINER_ITEM_CLASS]::OnChangeItemPosition
	//  vom Server aufgerufen, um die Position des In-Place-Fensters 
	//  zu �ndern. �blicherweise ist dies ein Ergebnis von Daten�nderungen 
	//  im Server-Dokument, etwa ein ge�ndertes Extent oder als Ergebnis
	//  direkter Gr��en�nderungen.
	//
	// Standardm��ig wird hier die Basisklasse aufgerufen, die wiederum 
	//  [!output CONTAINER_ITEM_BASE_CLASS]::SetItemRects zum Bewegen des Elements
	//  an die neue Position aufruft.

	if (![!output CONTAINER_ITEM_BASE_CLASS]::OnChangeItemPosition(rectPos))
		return FALSE;

	// TODO: Aktualisieren Sie alle f�r das Rechteck/das Extent dieses Elements angelegten Zwischenspeicher

	return TRUE;
}

[!if !ACTIVE_DOC_CONTAINER]
void [!output CONTAINER_ITEM_CLASS]::OnGetItemPosition(CRect& rPosition)
{
	ASSERT_VALID(this);

	// W�hrend der direkten Aktivierung, wird [!output CONTAINER_ITEM_CLASS]::OnGetItemPosition
	//  aufgerufen, um die Position des Elements zu bestimmen. Gew�hnlich gibt 
	//  dieses Rechteck die aktuelle Position des Elements relativ zur 
	//  verwendeten Ansicht an. Sie k�nnen die Ansicht mit 
	//  [!output CONTAINER_ITEM_CLASS]::GetActiveView aufrufen.

	// TODO: Geben Sie das korrekte Rechteck (in Pixeln) in rPosition zur�ck

	CSize size;
	rPosition.SetRectEmpty();
	if (SUCCEEDED(GetExtent(&size, m_nDrawAspect)))
	{
		[!output VIEW_CLASS]* pView = GetActiveView();
		ASSERT_VALID(pView);
		if (!pView)
			return;
		CDC *pDC = pView->GetDC();
		ASSERT(pDC);
		if (!pDC)
			return;
		pDC->HIMETRICtoLP(&size);
		rPosition.SetRect(10, 10, size.cx + 10, size.cy + 10);
	}
	else
		rPosition.SetRect(10, 10, 210, 210);
}
[!endif]

void [!output CONTAINER_ITEM_CLASS]::OnActivate()
{
[!if !ACTIVE_DOC_CONTAINER]
    // Nur Elemente mit direkter Aktivierung pro Rahmen zulassen
    [!output VIEW_CLASS]* pView = GetActiveView();
    ASSERT_VALID(pView);
	if (!pView)
		return;
    COleClientItem* pItem = GetDocument()->GetInPlaceActiveItem(pView);
    if (pItem != NULL && pItem != this)
        pItem->Close();
    
    [!output CONTAINER_ITEM_BASE_CLASS]::OnActivate();
[!endif]
}

void [!output CONTAINER_ITEM_CLASS]::OnDeactivateUI(BOOL bUndoable)
{
	[!output CONTAINER_ITEM_BASE_CLASS]::OnDeactivateUI(bUndoable);

    DWORD dwMisc = 0;
    m_lpObject->GetMiscStatus(GetDrawAspect(), &dwMisc);
    if (dwMisc & OLEMISC_INSIDEOUT)
        DoVerb(OLEIVERB_HIDE, NULL);
}

void [!output CONTAINER_ITEM_CLASS]::Serialize(CArchive& ar)
{
	ASSERT_VALID(this);

	// Vor dem Lesen von Daten aus [!output CONTAINER_ITEM_BASE_CLASS] zuerst Basisklasse aufrufen.
	// Da dies den von [!output CONTAINER_ITEM_BASE_CLASS]::GetDocument zur�ckgegebenen
	//  m_pDocument-Zeiger einrichtet, es ist ratsam, zuerst die Basisklasse 
	//  Serialize aufzurufen.
	[!output CONTAINER_ITEM_BASE_CLASS]::Serialize(ar);

	// F�r [!output CONTAINER_ITEM_CLASS] spezifische Daten speicher/abfragen
	if (ar.IsStoring())
	{
		// TODO: Hier Code zum Speichern einf�gen
	}
	else
	{
		// TODO: Hier Code zum Laden einf�gen
	}
}
[!if CONTAINER_SERVER]

BOOL [!output CONTAINER_ITEM_CLASS]::CanActivate()
{
	// Eine direkte Bearbeitung, w�hrend der Server selbst direkt bearbeitet wird,
	//  funktioniert nicht und wird nicht unterst�tzt. Deaktivieren Sie deshalb 
	//  in diesem Fall die direkte Aktivierung.
	[!output DOC_CLASS]* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return FALSE;
	ASSERT_KINDOF(COleServerDoc, pDoc);
	if (!pDoc->IsKindOf(RUNTIME_CLASS(COleServerDoc)))
	{
		return FALSE;
	}
	if (pDoc->IsInPlaceActive())
		return FALSE;

	// anderenfalls Standardverhalten akzeptieren
	return COleClientItem::CanActivate();
}
[!endif]
[!endif]


// [!output CONTAINER_ITEM_CLASS] Diagnose

#ifdef _DEBUG
void [!output CONTAINER_ITEM_CLASS]::AssertValid() const
{
	[!output CONTAINER_ITEM_BASE_CLASS]::AssertValid();
}

void [!output CONTAINER_ITEM_CLASS]::Dump(CDumpContext& dc) const
{
	[!output CONTAINER_ITEM_BASE_CLASS]::Dump(dc);
}
#endif

