// [!output WND_VIEW_HEADER] : Schnittstelle der Klasse [!output WND_VIEW_CLASS]
//


#pragma once


// [!output WND_VIEW_CLASS]-Fenster

class [!output WND_VIEW_CLASS] : public [!output WND_VIEW_BASE_CLASS]
{
// Konstruktion
public:
	[!output WND_VIEW_CLASS]();

// Attribute
public:

// Operationen
public:

// Überschreibungen
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementierung
public:
	virtual ~[!output WND_VIEW_CLASS]();

	// Generierte Funktionen für die Meldungstabellen
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

