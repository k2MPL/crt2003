// [!output WND_VIEW_HEADER] : interfaccia della classe [!output WND_VIEW_CLASS]
//


#pragma once


// finestra di [!output WND_VIEW_CLASS]

class [!output WND_VIEW_CLASS] : public [!output WND_VIEW_BASE_CLASS]
{
// Costruzione
public:
	[!output WND_VIEW_CLASS]();

// Attributi
public:

// Operazioni
public:

// Sostituzioni
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementazione
public:
	virtual ~[!output WND_VIEW_CLASS]();

	// Funzioni generate per la mappa dei messaggi
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

