// [!output DIALOG_AUTO_PROXY_HEADER] : fichier d'en-tête
//

#pragma once

class [!output DIALOG_CLASS];


// cible de la commande [!output DIALOG_AUTO_PROXY_CLASS]

class [!output DIALOG_AUTO_PROXY_CLASS] : public [!output DIALOG_AUTO_PROXY_BASE_CLASS]
{
	DECLARE_DYNCREATE([!output DIALOG_AUTO_PROXY_CLASS])

	[!output DIALOG_AUTO_PROXY_CLASS]();           // constructeur protégé utilisé par la création dynamique

// Attributs
public:
	[!output DIALOG_CLASS]* m_pDialog;

// Opérations
public:

// Substitutions
	public:
	virtual void OnFinalRelease();

// Implémentation
protected:
	virtual ~[!output DIALOG_AUTO_PROXY_CLASS]();

	// Fonctions générées de la table des messages

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE([!output DIALOG_AUTO_PROXY_CLASS])

	// Fonctions générées de la table des répartitions OLE

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

