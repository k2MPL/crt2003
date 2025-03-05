// [!output CONTAINER_ITEM_IMPL] : implementazione della classe [!output CONTAINER_ITEM_CLASS]
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


// implementazione di [!output CONTAINER_ITEM_CLASS]

IMPLEMENT_SERIAL([!output CONTAINER_ITEM_CLASS], [!output CONTAINER_ITEM_BASE_CLASS], 0)

[!if RICH_EDIT_VIEW]
[!output CONTAINER_ITEM_CLASS]::[!output CONTAINER_ITEM_CLASS](REOBJECT* preo, [!output DOC_CLASS]* pContainer)
	: [!output CONTAINER_ITEM_BASE_CLASS](preo, pContainer)
[!else]
[!output CONTAINER_ITEM_CLASS]::[!output CONTAINER_ITEM_CLASS]([!output DOC_CLASS]* pContainer)
	: [!output CONTAINER_ITEM_BASE_CLASS](pContainer)
[!endif]
{
	// TODO: aggiungere qui il codice di costruzione unico.
}

[!output CONTAINER_ITEM_CLASS]::~[!output CONTAINER_ITEM_CLASS]()
{
	// TODO: aggiungere qui il codice di pulitura.
}
[!if !RICH_EDIT_VIEW]

void [!output CONTAINER_ITEM_CLASS]::OnChange(OLE_NOTIFICATION nCode, DWORD dwParam)
{
	ASSERT_VALID(this);

	[!output CONTAINER_ITEM_BASE_CLASS]::OnChange(nCode, dwParam);

	// Quando un elemento viene modificato (sul posto o completamente aperto)
	// invia notifiche OnChange per le modifiche apportate allo stato
	//  dell'elemento o all'aspetto visivo del contenuto.

	// TODO: invalidare l'elemento richiamando UpdateAllViews
	// (con suggerimenti appropriati all'applicazione).

	GetDocument()->UpdateAllViews(NULL);
		// per il momento aggiornare semplicemente TUTTE le viste/nessun suggerimento.
}

BOOL [!output CONTAINER_ITEM_CLASS]::OnChangeItemPosition(const CRect& rectPos)
{
	ASSERT_VALID(this);

	// Durante l'attivazione sul posto viene richiamata dal server la classe 
	// [!output CONTAINER_ITEM_CLASS]::OnChangeItemPosition per modificare la posizione della finestra sul posto. In genere, questo è il risultato della modifica dei dati nel documento del server
	//  per cui l'ambito viene modificato
	//  o è il risultato di un ridimensionamento sul posto.
	//
	// L'operazione predefinita consiste nel richiamare la classe di base, che richiamerà 
	//  [!output CONTAINER_ITEM_BASE_CLASS]::SetItemRects per spostare l'elemento
	//  nella nuova posizione.

	if (![!output CONTAINER_ITEM_BASE_CLASS]::OnChangeItemPosition(rectPos))
		return FALSE;

	// TODO: aggiornare l'eventuale cache relativa al rettangolo o all'ambito dell'elemento.

	return TRUE;
}

[!if !ACTIVE_DOC_CONTAINER]
void [!output CONTAINER_ITEM_CLASS]::OnGetItemPosition(CRect& rPosition)
{
	ASSERT_VALID(this);

	// Durante l'attivazione sul posto, verrà chiamata [!output CONTAINER_ITEM_CLASS]::OnGetItemPosition
	//  per determinare la posizione dell'elemento. In genere, il 
	//  rettangolo restituisce la posizione corrente dell'elemento relativo alla 
	//  visualizzazione utilizzata per l'attivazione. È possibile ottenere la la visualizzazione chiamando 
	//  [!output CONTAINER_ITEM_CLASS]::GetActiveView.

	// TODO: restituire il rettangolo corretto (in pixel) in rPosition.

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
    // Consentire un solo elemento attivato sul posto per frame
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

	// Richiamare innanzitutto la classe di base per leggere i dati di [!output CONTAINER_ITEM_BASE_CLASS].
	// Poiché in questo modo viene impostato il puntatore m_pDocument restituito da
	//  [!output CONTAINER_ITEM_CLASS]::GetDocument, si consiglia di richiamare
	//  innanzitutto la classe di base Serialize.
	[!output CONTAINER_ITEM_BASE_CLASS]::Serialize(ar);

	// memorizzare/recuperare dati specifici in [!output CONTAINER_ITEM_CLASS].
	if (ar.IsStoring())
	{
		// TODO: aggiungere qui il codice di archiviazione.
	}
	else
	{
		// TODO: aggiungere qui il codice di caricamento.
	}
}
[!if CONTAINER_SERVER]

BOOL [!output CONTAINER_ITEM_CLASS]::CanActivate()
{
	// Durante la modifica del server stesso sul posto 
	//  la modifica sul posto non funziona e non è supportata. In questo caso quindi, disattivare 
	//  l'attivazione sul posto.
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

	// altrimenti, utilizzare il comportamento predefinito.
	return COleClientItem::CanActivate();
}
[!endif]
[!endif]


// diagnostica di [!output CONTAINER_ITEM_CLASS]

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

