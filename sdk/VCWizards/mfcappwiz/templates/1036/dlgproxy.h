// [!output DIALOG_AUTO_PROXY_HEADER]�: fichier d'en-t�te
//

#pragma once

class [!output DIALOG_CLASS];


// cible de la commande [!output DIALOG_AUTO_PROXY_CLASS]

class [!output DIALOG_AUTO_PROXY_CLASS] : public [!output DIALOG_AUTO_PROXY_BASE_CLASS]
{
	DECLARE_DYNCREATE([!output DIALOG_AUTO_PROXY_CLASS])

	[!output DIALOG_AUTO_PROXY_CLASS]();           // constructeur prot�g� utilis� par la cr�ation dynamique

// Attributs
public:
	[!output DIALOG_CLASS]* m_pDialog;

// Op�rations
public:

// Substitutions
	public:
	virtual void OnFinalRelease();

// Impl�mentation
protected:
	virtual ~[!output DIALOG_AUTO_PROXY_CLASS]();

	// Fonctions g�n�r�es de la table des messages

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE([!output DIALOG_AUTO_PROXY_CLASS])

	// Fonctions g�n�r�es de la table des r�partitions OLE

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

