// [!output WND_VIEW_HEADER] : interface de la classe [!output WND_VIEW_CLASS]
//


#pragma once


// fen�tre [!output WND_VIEW_CLASS]

class [!output WND_VIEW_CLASS] : public [!output WND_VIEW_BASE_CLASS]
{
// Construction
public:
	[!output WND_VIEW_CLASS]();

// Attributs
public:

// Op�rations
public:

// Substitutions
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Impl�mentation
public:
	virtual ~[!output WND_VIEW_CLASS]();

	// Fonctions g�n�r�es de la table des messages
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

