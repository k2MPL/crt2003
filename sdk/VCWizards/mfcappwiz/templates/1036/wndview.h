// [!output WND_VIEW_HEADER] : interface de la classe [!output WND_VIEW_CLASS]
//


#pragma once


// fenêtre [!output WND_VIEW_CLASS]

class [!output WND_VIEW_CLASS] : public [!output WND_VIEW_BASE_CLASS]
{
// Construction
public:
	[!output WND_VIEW_CLASS]();

// Attributs
public:

// Opérations
public:

// Substitutions
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implémentation
public:
	virtual ~[!output WND_VIEW_CLASS]();

	// Fonctions générées de la table des messages
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

