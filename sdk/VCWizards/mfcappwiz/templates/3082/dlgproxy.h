// [!output DIALOG_AUTO_PROXY_HEADER]: archivo de encabezado
//

#pragma once

class [!output DIALOG_CLASS];


// Destino del comando de [!output DIALOG_AUTO_PROXY_CLASS]

class [!output DIALOG_AUTO_PROXY_CLASS] : public [!output DIALOG_AUTO_PROXY_BASE_CLASS]
{
	DECLARE_DYNCREATE([!output DIALOG_AUTO_PROXY_CLASS])

	[!output DIALOG_AUTO_PROXY_CLASS]();           // Constructor protegido utilizado por la creación dinámica

// Atributos
public:
	[!output DIALOG_CLASS]* m_pDialog;

// Operaciones
public:

// Reemplazos
	public:
	virtual void OnFinalRelease();

// Implementación
protected:
	virtual ~[!output DIALOG_AUTO_PROXY_CLASS]();

	// Funciones de asignación de mensajes generadas

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE([!output DIALOG_AUTO_PROXY_CLASS])

	// Funciones de asignación de envío OLE generadas

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

