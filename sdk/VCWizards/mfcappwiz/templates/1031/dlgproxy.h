// [!output DIALOG_AUTO_PROXY_HEADER]: Headerdatei
//

#pragma once

class [!output DIALOG_CLASS];


// [!output DIALOG_AUTO_PROXY_CLASS] Befehlsziel

class [!output DIALOG_AUTO_PROXY_CLASS] : public [!output DIALOG_AUTO_PROXY_BASE_CLASS]
{
	DECLARE_DYNCREATE([!output DIALOG_AUTO_PROXY_CLASS])

	[!output DIALOG_AUTO_PROXY_CLASS]();           // Dynamische Erstellung verwendet geschützten Konstruktor

// Attribute
public:
	[!output DIALOG_CLASS]* m_pDialog;

// Operationen
public:

// Überschreibungen
	public:
	virtual void OnFinalRelease();

// Implementierung
protected:
	virtual ~[!output DIALOG_AUTO_PROXY_CLASS]();

	// Generierte Funktionen für die Meldungstabellen

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE([!output DIALOG_AUTO_PROXY_CLASS])

	// Generierte OLE-Dispatchzuordnungsfunktionen

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

