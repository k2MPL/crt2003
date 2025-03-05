// [!output CONTAINER_ITEM_IMPL] : impl�mentation de la classe [!output CONTAINER_ITEM_CLASS]
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


// impl�mentation de [!output CONTAINER_ITEM_CLASS]

IMPLEMENT_SERIAL([!output CONTAINER_ITEM_CLASS], [!output CONTAINER_ITEM_BASE_CLASS], 0)

[!if RICH_EDIT_VIEW]
[!output CONTAINER_ITEM_CLASS]::[!output CONTAINER_ITEM_CLASS](REOBJECT* preo, [!output DOC_CLASS]* pContainer)
	: [!output CONTAINER_ITEM_BASE_CLASS](preo, pContainer)
[!else]
[!output CONTAINER_ITEM_CLASS]::[!output CONTAINER_ITEM_CLASS]([!output DOC_CLASS]* pContainer)
	: [!output CONTAINER_ITEM_BASE_CLASS](pContainer)
[!endif]
{
	// TODO : ajoutez ici le code d'une construction unique
}

[!output CONTAINER_ITEM_CLASS]::~[!output CONTAINER_ITEM_CLASS]()
{
	// TODO : ajoutez ici le code de nettoyage
}
[!if !RICH_EDIT_VIEW]

void [!output CONTAINER_ITEM_CLASS]::OnChange(OLE_NOTIFICATION nCode, DWORD dwParam)
{
	ASSERT_VALID(this);

	[!output CONTAINER_ITEM_BASE_CLASS]::OnChange(nCode, dwParam);

	// Lorsqu'un �l�ment est en cours de modification (soit sur place soit enti�rement ouvert),
	//  il envoie des notifications OnChange relatives aux modifications de l'�tat
	//  de l'�l�ment ou de l'apparence de son contenu.

	// TODO : rendez l'�l�ment non valide en appelant UpdateAllViews
	//  (avec des indicateurs appropri�s � votre application)

	GetDocument()->UpdateAllViews(NULL);
		// mettre � jour uniquement TOUTES les vues, pas les indicateurs
}

BOOL [!output CONTAINER_ITEM_CLASS]::OnChangeItemPosition(const CRect& rectPos)
{
	ASSERT_VALID(this);

	// Lors d'une activation sur place, [!output CONTAINER_ITEM_CLASS]::OnChangeItemPosition
	//  est appel� par le serveur pour modifier la position de la fen�tre
	//  sur place. En r�gle g�n�rale, cela est d� � un changement des donn�es
	//  du document serveur, modifiant ainsi l'�tendue, ou bien �
	//  un redimensionnement sur place.
	//
	// Par d�faut ici, la classe de base est appel�e, laquelle va appeler
	//  [!output CONTAINER_ITEM_BASE_CLASS]::SetItemRects pour d�placer l'�l�ment
	//  � sa nouvelle position.

	if (![!output CONTAINER_ITEM_BASE_CLASS]::OnChangeItemPosition(rectPos))
		return FALSE;

	// TODO : mettez � jour tout cache associ� � l'�tendue ou au rectangle de l'�l�ment

	return TRUE;
}

[!if !ACTIVE_DOC_CONTAINER]
void [!output CONTAINER_ITEM_CLASS]::OnGetItemPosition(CRect& rPosition)
{
	ASSERT_VALID(this);

	// Lors d'une activation sur place, [!output CONTAINER_ITEM_CLASS]::OnGetItemPosition
	//  sera appel� pour d�terminer l'emplacement de cet �l�ment.  En r�gle g�n�rale, 
	//  ce rectangle refl�te la position actuelle de l'�l�ment par rapport � la 
	//  vue utilis�e pour l'activation.  Vous pouvez obtenir la vue en appelant 
	//  [!output CONTAINER_ITEM_CLASS]::GetActiveView.

	// TODO : retournez un rectangle correct (en pixels) dans rPosition

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
    // Autoriser un seul �l�ment activ� sur place par frame
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

	// Appeler d'abord la classe de base pour lire les donn�es de [!output CONTAINER_ITEM_BASE_CLASS].
	// Dans la mesure o� cela configure le pointeur m_pDocument retourn� par
	//  [!output CONTAINER_ITEM_CLASS]::GetDocument, il est pr�f�rable d'appeler
	//  en premier la classe de base Serialize.
	[!output CONTAINER_ITEM_BASE_CLASS]::Serialize(ar);

	// enregistrer/extraire maintenant les donn�es sp�cifiques � [!output CONTAINER_ITEM_CLASS]
	if (ar.IsStoring())
	{
		// TODO�: ajoutez ici le code de stockage
	}
	else
	{
		// TODO�: ajoutez ici le code de chargement
	}
}
[!if CONTAINER_SERVER]

BOOL [!output CONTAINER_ITEM_CLASS]::CanActivate()
{
	// La modification sur place alors que le serveur est lui-m�me modifi� sur place
	//  ne fonctionne pas et n'est pas prise en charge. L'activation sur place
	//  doit donc �tre d�sactiv�e dans ce cas.
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

	// sinon, le comportement par d�faut est utilis�
	return COleClientItem::CanActivate();
}
[!endif]
[!endif]


// diagnostics pour [!output CONTAINER_ITEM_CLASS]

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

