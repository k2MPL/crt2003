// [!output TREE_VIEW_HEADER]: interfaz de la clase [!output TREE_VIEW_CLASS]
//


#pragma once

class [!output DOC_CLASS];

class [!output TREE_VIEW_CLASS] : public CTreeView
{
protected: // Crear s�lo a partir de serializaci�n
	[!output TREE_VIEW_CLASS]();
	DECLARE_DYNCREATE([!output TREE_VIEW_CLASS])

// Atributos
public:
	[!output DOC_CLASS]* GetDocument();

// Operaciones
public:

// Reemplazos
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
[!if PRINTING]
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnDraw(CDC* pDC);
[!endif]
	virtual void OnInitialUpdate(); // Se llama la primera vez despu�s de la construcci�n

// Implementaci�n
public:
	virtual ~[!output TREE_VIEW_CLASS]();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Funciones de asignaci�n de mensajes generadas
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Versi�n de depuraci�n en [!output TREE_VIEW_IMPL]
inline [!output DOC_CLASS]* [!output TREE_VIEW_CLASS]::GetDocument()
   { return reinterpret_cast<[!output DOC_CLASS]*>(m_pDocument); }
#endif

