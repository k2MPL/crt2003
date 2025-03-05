// [!output SERVER_ITEM_IMPL] : impl�mentation de la classe [!output SERVER_ITEM_CLASS]
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


// impl�mentation de [!output SERVER_ITEM_CLASS]

IMPLEMENT_DYNAMIC([!output SERVER_ITEM_CLASS], [!output SERVER_ITEM_BASE_CLASS])

[!output SERVER_ITEM_CLASS]::[!output SERVER_ITEM_CLASS]([!output DOC_CLASS]* pContainerDoc)
	: [!output SERVER_ITEM_BASE_CLASS](pContainerDoc, TRUE)
{
	// TODO : ajoutez ici le code d'une construction unique
	//  (par exemple, en ajoutant d'autres formats de Presse-papiers dans la source de donn�es de l'�l�ment)
}

[!output SERVER_ITEM_CLASS]::~[!output SERVER_ITEM_CLASS]()
{
	// TODO : ajoutez ici le code de nettoyage
}

void [!output SERVER_ITEM_CLASS]::Serialize(CArchive& ar)
{
	// [!output SERVER_ITEM_CLASS]::Serialize sera appel� par l'infrastructure si
	//  l'�l�ment est copi� dans le Presse-papiers. Cette action peut �tre automatis�e
	//  via le rappel OLE de OnGetClipboardData. Pour l'�l�ment incorpor�, il est conseill�
	//  de d�l�guer � la fonction Serialize
	//  du document. Si votre application prend en charge les liens, vous pouvez ne s�rialiser
	//  qu'une partie du document.

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
	// De nombreuses applications, telles que celle-ci, ne g�rent que le dessin de l'aspect du contenu
	//  de l'�l�ment. Pour prendre en charge d'autres aspects, par exemple
	//  DVASPECT_THUMBNAIL (par substitution de OnDrawEx), cette
	//  impl�mentation de OnGetExtent doit �tre modifi�e afin de g�rer les
	//  aspects suppl�mentaires.

	if (dwDrawAspect != DVASPECT_CONTENT)
		return [!output SERVER_ITEM_BASE_CLASS]::OnGetExtent(dwDrawAspect, rSize);

	// [!output SERVER_ITEM_CLASS]::OnGetExtent est appel� pour obtenir l'�tendue, en
	//  unit�s HIMETRIC, de l'�l�ment entier. L'impl�mentation par d�faut
	//  retourne ici un nombre d'unit�s cod� de mani�re irr�versible.

	// TODO : remplacez cette taille arbitraire

	rSize = CSize(3000, 3000);   // unit�s 3000 x 3000 (format HIMETRIC)

	return TRUE;
}

BOOL [!output SERVER_ITEM_CLASS]::OnDraw(CDC* pDC, CSize& rSize)
{
	if (!pDC)
		return FALSE;

	// Supprimez ceci si vous utilisez rSize
	UNREFERENCED_PARAMETER(rSize);

	// TODO : d�finissez le mode et l'�tendue du mappage
	//  (l'�tendue est g�n�ralement identique � la taille retourn�e par OnGetExtent)
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowOrg(0,0);
	pDC->SetWindowExt(3000, 3000);

	// TODO : ajoutez ici le code du dessin. Renseignez si n�cessaire l'�tendue HIMETRIC.
	//  Tout le dessin prend place dans le contexte de p�riph�rique de m�tafichier (pDC).

[!if CONTAINER_SERVER]
	// TODO : dessinez aussi les objets incorpor�s [!output CONTAINER_ITEM_CLASS].

[!endif]
[!if CONTAINER_SERVER]
	// Le code suivant dessine le premier �l�ment � une position arbitraire.

	// TODO : supprimez ce code lorsque votre code de dessin final est complet

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


// diagnostics pour [!output SERVER_ITEM_CLASS]

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

