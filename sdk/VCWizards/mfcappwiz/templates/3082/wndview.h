// [!output WND_VIEW_HEADER]: interfaz de la clase [!output WND_VIEW_CLASS]
//


#pragma once


// Ventana de [!output WND_VIEW_CLASS]

class [!output WND_VIEW_CLASS] : public [!output WND_VIEW_BASE_CLASS]
{
// Construcci�n
public:
	[!output WND_VIEW_CLASS]();

// Atributos
public:

// Operaciones
public:

// Reemplazos
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementaci�n
public:
	virtual ~[!output WND_VIEW_CLASS]();

	// Funciones de asignaci�n de mensajes generadas
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

