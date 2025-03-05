// [!output DIALOG_AUTO_PROXY_HEADER]: file di intestazione
//

#pragma once

class [!output DIALOG_CLASS];


// destinazione del comando di [!output DIALOG_AUTO_PROXY_CLASS] 

class [!output DIALOG_AUTO_PROXY_CLASS] : public [!output DIALOG_AUTO_PROXY_BASE_CLASS]
{
	DECLARE_DYNCREATE([!output DIALOG_AUTO_PROXY_CLASS])

	[!output DIALOG_AUTO_PROXY_CLASS]();           // costruttore protetto utilizzato dalla creazione dinamica

// Attributi
public:
	[!output DIALOG_CLASS]* m_pDialog;

// Operazioni
public:

// Sostituzioni
	public:
	virtual void OnFinalRelease();

// Implementazione
protected:
	virtual ~[!output DIALOG_AUTO_PROXY_CLASS]();

	// Funzioni generate per la mappa dei messaggi

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE([!output DIALOG_AUTO_PROXY_CLASS])

	// Funzioni generate per la mappa di invio OLE

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

