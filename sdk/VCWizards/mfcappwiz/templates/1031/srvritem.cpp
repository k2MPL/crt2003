// [!output SERVER_ITEM_IMPL] : Implementierung der Klasse [!output SERVER_ITEM_CLASS]
//

#include "stdafx.h"
#include "[!output APP_HEADER]"

#include "[!output DOC_HEADER]"
#include "[!output SERVER_ITEM_HEADER]"
[!if CONTAINER_SERVER]
#include "[!output CONTAINER_ITEM_HEADER]"
[!endif]

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// [!output SERVER_ITEM_CLASS] Implementierung

IMPLEMENT_DYNAMIC([!output SERVER_ITEM_CLASS], [!output SERVER_ITEM_BASE_CLASS])

[!output SERVER_ITEM_CLASS]::[!output SERVER_ITEM_CLASS]([!output DOC_CLASS]* pContainerDoc)
	: [!output SERVER_ITEM_BASE_CLASS](pContainerDoc, TRUE)
{
	// TODO: Hier Code f�r One-Time-Konstruktion einf�gen
	//  (z.B. Hinzuf�gen von zus�tzlichen Zwischenablageformaten zur Datenquelle des Elements)
}

[!output SERVER_ITEM_CLASS]::~[!output SERVER_ITEM_CLASS]()
{
	// TODO: Hier Bereinigungscode hinzuf�gen
}

void [!output SERVER_ITEM_CLASS]::Serialize(CArchive& ar)
{
	// [!output SERVER_ITEM_CLASS]::Serialize wird automatisch aufgerufen, wenn
	//  das Element in die Zwischenablage kopiert wird. Dies kann automatisch 
	//  �ber die OLE-R�ckruffunktion OnGetClipboardData geschehen. Ein Standardwert f�r
	//  das eingebundene Element dient einfach zur Delegierung der Serialisierungsfunktion des 
	//  Dokuments. Wenn Sie Verweise unterst�tzen, m�chten Sie vielleicht nur einen Teil des
	//  Dokuments serialisieren.

	if (!IsLinkedItem())
	{
		[!output DOC_CLASS]* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (pDoc)
			pDoc->Serialize(ar);
	}
}

BOOL [!output SERVER_ITEM_CLASS]::OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize)
{
	// Die meisten Anwendungen (wie auch diese) unterst�tzen als einzigen Aspekt das Zeichnen
	//  des Elementinhalts. Wollen Sie andere Aspekte unterst�tzen, wie z.B.
	//  DVASPECT_THUMBNAIL (durch �berladen von OnDrawEx), so sollte diese
	//  Implementierung von OnGetExtent dahingehend modifiziert werden, dass sie
	//  zus�tzliche Aspekte verarbeiten kann.

	if (dwDrawAspect != DVASPECT_CONTENT)
		return [!output SERVER_ITEM_BASE_CLASS]::OnGetExtent(dwDrawAspect, rSize);

	// [!output SERVER_ITEM_CLASS]::OnGetExtent wird aufgerufen, um das Extent in 
	//  HIMETRIC-Einheiten des gesamten Elements zu ermitteln. Die Standardimplementierung
	//  liefert hier einfach eine fest programmierte Einheitenanzahl zur�ck.

	// TODO: Ersetzen Sie diese willk�rlich gew�hlte Gr��e

	rSize = CSize(3000, 3000);   // 3000 x 3000 HIMETRIC Einheiten

	return TRUE;
}

BOOL [!output SERVER_ITEM_CLASS]::OnDraw(CDC* pDC, CSize& rSize)
{
	if (!pDC)
		return FALSE;

	// Entfernen Sie dies, wenn Sie rSize verwenden
	UNREFERENCED_PARAMETER(rSize);

	// TODO: Setzen Sie den Zuordnungsmodus und Extent
	//  (Das Extent stimmt �blicherweise mit der von OnGetExtent zur�ckgelieferten Gr��e �berein)
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowOrg(0,0);
	pDC->SetWindowExt(3000, 3000);

	// TODO: Hier Code zum Zeichnen einf�gen. F�llen Sie wahlweise das HIMETRIC-Extent aus.
	//  Alle Zeichenoperationen finden innerhalb des Metadatei-Ger�tekontexts (pDC) statt.

[!if CONTAINER_SERVER]
	// TODO: Auch eingebettete [!output CONTAINER_ITEM_CLASS]-Objekte zeichnen.

[!endif]
[!if CONTAINER_SERVER]
	// Der folgende Code zeichnet das erste Element an einer willk�rlich gew�hlten Position.

	// TODO: Entfernen Sie diesen Code, sobald die richtige Zeichenroutine vollst�ndig ist

	[!output DOC_CLASS]* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return FALSE;

	POSITION pos = pDoc->GetStartPosition();
	[!output CONTAINER_ITEM_CLASS]* pItem = DYNAMIC_DOWNCAST([!output CONTAINER_ITEM_CLASS], pDoc->GetNextClientItem(pos));
	if (pItem != NULL)
		pItem->Draw(pDC, CRect(10, 10, 1010, 1010));
[!endif]
	return TRUE;
}


// [!output SERVER_ITEM_CLASS] Diagnose

#ifdef _DEBUG
void [!output SERVER_ITEM_CLASS]::AssertValid() const
{
	[!output SERVER_ITEM_BASE_CLASS]::AssertValid();
}

void [!output SERVER_ITEM_CLASS]::Dump(CDumpContext& dc) const
{
	[!output SERVER_ITEM_BASE_CLASS]::Dump(dc);
}
#endif

