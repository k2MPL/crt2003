// [!output CONTAINER_ITEM_IMPL]: implementaci�n de la clase [!output CONTAINER_ITEM_CLASS]
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


// Implementaci�n de [!output CONTAINER_ITEM_CLASS]

IMPLEMENT_SERIAL([!output CONTAINER_ITEM_CLASS], [!output CONTAINER_ITEM_BASE_CLASS], 0)

[!if RICH_EDIT_VIEW]
[!output CONTAINER_ITEM_CLASS]::[!output CONTAINER_ITEM_CLASS](REOBJECT* preo, [!output DOC_CLASS]* pContainer)
	: [!output CONTAINER_ITEM_BASE_CLASS](preo, pContainer)
[!else]
[!output CONTAINER_ITEM_CLASS]::[!output CONTAINER_ITEM_CLASS]([!output DOC_CLASS]* pContainer)
	: [!output CONTAINER_ITEM_BASE_CLASS](pContainer)
[!endif]
{
	// TODO: agregar aqu� el c�digo de construcci�n �nico
}

[!output CONTAINER_ITEM_CLASS]::~[!output CONTAINER_ITEM_CLASS]()
{
	// TODO: agregar aqu� el c�digo de limpieza
}
[!if !RICH_EDIT_VIEW]

void [!output CONTAINER_ITEM_CLASS]::OnChange(OLE_NOTIFICATION nCode, DWORD dwParam)
{
	ASSERT_VALID(this);

	[!output CONTAINER_ITEM_BASE_CLASS]::OnChange(nCode, dwParam);

	// Cuando se edita un elemento (en contexto o completamente abierto)
	//  env�a notificaciones OnChange para cambios en el estado del
	//  elemento o apariencia visual de su contenido.

	// TODO: invalidar el elemento llamando a UpdateAllViews
	//  (con sugerencias apropiadas a la aplicaci�n)

	GetDocument()->UpdateAllViews(NULL);
		// Por ahora actualizar s�lo TODAS las vistas, no las sugerencias
}

BOOL [!output CONTAINER_ITEM_CLASS]::OnChangeItemPosition(const CRect& rectPos)
{
	ASSERT_VALID(this);

	// Durante la activaci�n en contexto, el servidor llama a [!output CONTAINER_ITEM_CLASS]::OnChangeItemPosition
	//  para cambiar la posici�n de la ventana
	//  en contexto. Normalmente, es el resultado de los datos en el cambio
	//  de documentos del servidor como el cambio de extensi�n o como resultado
	//  del cambio de tama�o en contexto.
	//
	// El valor predeterminado es llamar a la clase base, que llamar� a
	//  [!output CONTAINER_ITEM_BASE_CLASS]::SetItemRects para mover el elemento
	//  a la nueva posici�n.

	if (![!output CONTAINER_ITEM_BASE_CLASS]::OnChangeItemPosition(rectPos))
		return FALSE;

	// TODO: actualizar cualquier cach� que pueda tener del rect�ngulo o extensi�n del elemento

	return TRUE;
}

[!if !ACTIVE_DOC_CONTAINER]
void [!output CONTAINER_ITEM_CLASS]::OnGetItemPosition(CRect& rPosition)
{
	ASSERT_VALID(this);

	// Durante la activaci�n en contexto, se llamar� a [!output CONTAINER_ITEM_CLASS]::OnGetItemPosition
	//  para determinar la ubicaci�n de este elemento.  Normalmente, este 
	//  rect�ngulo reflejar�a la posici�n actual del elemento relativa a la 
	//  vista utilizada para la activaci�n. Puede obtener la vista llamando a 
	//  [!output CONTAINER_ITEM_CLASS]::GetActiveView.

	// TODO: devolver el rect�ngulo correcto (en p�xeles) en rPosition

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
    // Permitir s�lo un elemento activo en contexto por marco
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

	// Llamar a la clase base primero para leer en los datos de [!output CONTAINER_ITEM_BASE_CLASS].
	// Dado que esta operaci�n configura el puntero m_pDocument devuelto desde
	//  [!output CONTAINER_ITEM_CLASS]::GetDocument, es buena idea llamar en
	//  primer lugar a la clase base Serialize.
	[!output CONTAINER_ITEM_BASE_CLASS]::Serialize(ar);

	// Ahora almacenar en o recuperar datos espec�ficos de [!output CONTAINER_ITEM_CLASS]
	if (ar.IsStoring())
	{
		// TODO: agregar aqu� el c�digo de almacenamiento
	}
	else
	{
		// TODO: agregar aqu� el c�digo de carga
	}
}
[!if CONTAINER_SERVER]

BOOL [!output CONTAINER_ITEM_CLASS]::CanActivate()
{
	// La edici�n en contexto mientras el propio servidor se edita en contexto
	//  no funciona y no se admite. Por tanto, deshabilitar
	//  la activaci�n en contexto en este caso.
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

	// De lo contrario, confiar en el comportamiento predeterminado
	return COleClientItem::CanActivate();
}
[!endif]
[!endif]


// Diagn�sticos de [!output CONTAINER_ITEM_CLASS]

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

