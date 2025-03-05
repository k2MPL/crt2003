// [!output SERVER_ITEM_IMPL]: implementaci�n de la clase [!output SERVER_ITEM_CLASS]
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


// Implementaci�n de [!output SERVER_ITEM_CLASS]

IMPLEMENT_DYNAMIC([!output SERVER_ITEM_CLASS], [!output SERVER_ITEM_BASE_CLASS])

[!output SERVER_ITEM_CLASS]::[!output SERVER_ITEM_CLASS]([!output DOC_CLASS]* pContainerDoc)
	: [!output SERVER_ITEM_BASE_CLASS](pContainerDoc, TRUE)
{
	// TODO: agregar aqu� el c�digo de construcci�n �nico
	//  (por ejemplo, agregar formatos adicionales del Portapapeles al origen de datos del elemento)
}

[!output SERVER_ITEM_CLASS]::~[!output SERVER_ITEM_CLASS]()
{
	// TODO: agregar aqu� el c�digo de limpieza
}

void [!output SERVER_ITEM_CLASS]::Serialize(CArchive& ar)
{
	// [!output SERVER_ITEM_CLASS]::el marco de trabajo llamar� a la funci�n Serialize si
	//  el elemento se copia en el Portapapeles. Esto puede ocurrir autom�ticamente
	//  a trav�s de la devoluci�n de llamada OLE OnGetClipboardData. Una buena opci�n predeterminada para
	//  el elemento incrustado es simplemente delegar en la funci�n Serialize
	//  del documento. Si admite v�nculos, querr� serializar
	//  s�lo una parte del documento.

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
	// La mayor�a de las aplicaciones, como �sta, s�lo controlan el dibujo de la apariencia
	//  del contenido del elemento. Si desea admitir otros aspectos, como
	//  DVASPECT_THUMBNAIL (reemplazando OnDrawEx), esta
	//  implementaci�n de OnGetExtent se debe modificar para controlar los
	//  aspectos adicionales.

	if (dwDrawAspect != DVASPECT_CONTENT)
		return [!output SERVER_ITEM_BASE_CLASS]::OnGetExtent(dwDrawAspect, rSize);

	// [!output SERVER_ITEM_CLASS]::se llama a OnGetExtent para obtener la extensi�n en
	//  unidades HIMETRIC del elemento completo. La implementaci�n
	//  predeterminada aqu� simplemente devuelve un n�mero de unidades incluido en el c�digo.

	// TODO: reemplazar este tama�o arbitrario

	rSize = CSize(3000, 3000);   // Unidades 3000 x 3000 HIMETRIC

	return TRUE;
}

BOOL [!output SERVER_ITEM_CLASS]::OnDraw(CDC* pDC, CSize& rSize)
{
	if (!pDC)
		return FALSE;

	// Quitarlo si utiliza rSize
	UNREFERENCED_PARAMETER(rSize);

	// TODO: establecer el modo de asignaci�n y extensi�n
	//  (La extensi�n normalmente es la misma que el tama�o devuelto de OnGetExtent)
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowOrg(0,0);
	pDC->SetWindowExt(3000, 3000);

	// TODO: agregar aqu� el c�digo de dibujo.  Opcionalmente, rellenar la extensi�n HIMETRIC.
	//  Todo el dibujo tiene lugar en el contexto de dispositivo de metarchivo (pDC).

[!if CONTAINER_SERVER]
	// TODO: dibujar tambi�n objetos [!output CONTAINER_ITEM_CLASS] incrustados.

[!endif]
[!if CONTAINER_SERVER]
	// El siguiente c�digo dibuja el primer elemento en una posici�n arbitraria.

	// TODO: quitar este c�digo cuando el c�digo de dibujo real est� completo

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


// Diagn�sticos de [!output SERVER_ITEM_CLASS]

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

