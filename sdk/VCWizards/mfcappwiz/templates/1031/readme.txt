================================================================================
    MICROSOFT FOUNDATION CLASS LIBRARY : [!output PROJECT_NAME] Projektübersicht
================================================================================

Der Anwendungs-Assistent hat diese [!output PROJECT_NAME]-Anwendung erstellt. 
Diese Anwendung zeigt die prinzipielle Anwendung der Microsoft Foundation Classes 
und dient als Ausgangspunkt für die Erstellung Ihrer eigenen Anwendungen.

Diese Datei enthält die Zusammenfassung der Bestandteile aller Dateien, die 
Ihre [!output PROJECT_NAME]-Anwendung bilden.

[!output PROJECT_NAME].vcproj
    Dies ist die Hauptprojektdatei für VC++-Projekte, die vom Anwendungs-Assistenten 
    erstellt wird. Sie enthält Informationen über die Version von Visual C++, mit der
    die Datei generiert wurde, über die Plattformen, Konfigurationen und Projektfeatures,
    die mit dem Anwendungs-Assistenten ausgewählt wurden.

[!output APP_HEADER]
    Hierbei handelt es sich um die Haupt-Headerdatei der Anwendung. Diese enthält 
    andere projektspezifische Header (einschließlich Resource.h) und deklariert die
    [!output APP_CLASS]-Anwendungsklasse.

[!output APP_IMPL]
    Hierbei handelt es sich um die Haupt-Quellcodedatei der Anwendung. Diese enthält die
    Anwendungsklasse [!output APP_CLASS].

[!output PROJECT_NAME].rc
    Hierbei handelt es sich um eine Auflistung aller Ressourcen von Microsoft Windows, die 
    vom Programm verwendet werden. Sie enthält die Symbole, Bitmaps und Cursors, die im 
    Unterverzeichnis RES gespeichert sind. Diese Datei lässt sich direkt in Microsoft
    Visual C++ bearbeiten. Ihre Projektressourcen befinden sich in [!output LCID].

res\[!output SAFE_PROJECT_NAME].ico
    Dies ist eine Symboldatei, die als Symbol für die Anwendung verwendet wird. Dieses 
    Symbol wird durch die Haupt-Ressourcendatei [!output PROJECT_NAME].rc eingebunden.

res\[!output SAFE_PROJECT_NAME].rc2
    Diese Datei enthält Ressourcen, die nicht von Microsoft Visual C++ bearbeitet wurden.
    In dieser Datei werden alle Ressourcen gespeichert, die vom Ressourcen-Editor nicht bearbeitet 
    werden können.
[!if CONTAINER_SERVER || FULL_SERVER || MINI_SERVER || AUTOMATION || HAS_SUFFIX]
[!if !HTML_EDITVIEW]
[!output PROJECT_NAME].reg
    Dies ist eine REG-Beispieldatei, die anzeigt, welche Registrierungseinstellungen
    von Framework festgelegt werden. Diese können Sie als .REG-
[!if APP_TYPE_DLG]
    -Datei für Ihre Anwendung festlegen.
[!else]
    -Datei für Ihre Anwendung festlegen, oder diese löschen und die Standardregistrierung 
    RegisterShellFileTypes verwenden.
[!endif]

[!if AUTOMATION]
[!output PROJECT_NAME].idl
    Diese Datei enthält den "Interface Description Language"-Quellcode für die
    Typbibliothek der Anwendung.
[!endif]
[!endif]
[!endif]

[!if !APP_TYPE_DLG]
/////////////////////////////////////////////////////////////////////////////

Für das Hauptfenster:
[!if PROJECT_STYLE_EXPLORER]
    Windows Explorer-Stil: Das Projekt enthält eine Windows Explorer-Schnittstelle mit zwei Rahmen.
[!else]
    Das Projekt enthält eine MFC-Standardschnittstelle.
[!endif]

[!output MAIN_FRAME_HEADER], [!output MAIN_FRAME_IMPL]
    Diese Dateien enthalten die Frame-Klasse [!output MAIN_FRAME_CLASS], die von
[!if APP_TYPE_MDI]
    CMDIFrameWnd abgeleitet wird und steuert alle MDI-Framefeatures.
[!else]
    CFrameWnd abgeleitet wird und steuert alle SDI-Framefeatures.
[!endif]
[!if PROJECT_STYLE_EXPLORER]

[!output TREE_VIEW_HEADER], [!output TREE_VIEW_IMPL]
    Diese Dateien enthalten die linke Frame-Klasse [!output TREE_VIEW_CLASS], die von
    CTreeView abgeleitet wird.
[!endif]

[!if DOCKING_TOOLBAR]
res\Toolbar.bmp
    Diese Bitmap-Datei wird zum Erstellen unterteilter Bilder für die Symbolleiste verwendet.
    Die erste Symbol- und Statusleiste wird in der Klasse [!output MAIN_FRAME_CLASS]
    erstellt. Bearbeiten Sie diese Bitmap der Symbolleiste mit dem Ressourcen-Editor, und
    aktualisieren Sie das Array IDR_MAINFRAME TOOLBAR in [!output PROJECT_NAME].rc, um 
    Schaltflächen für die Symbolleiste hinzuzufügen.
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]

res\IToolbar.bmp
    Mit dieser Bitmap-Datei werden nebeneinander angeordnete Bilder für die Symbolleiste erstellt, 
    wenn die Server-Anwendung innerhalb eines anderen Containers "vor Ort" aktiviert wird. Die 
    Symbolleiste wird in der Klasse [!output INPLACE_FRAME_CLASS] erstellt. Diese Bitmap ist 
    der Bitmap in res\Toolbar.bmp ähnlich, jedoch fehlen verschiedene Nicht-Server-Befehle.

[!endif]
[!endif]
[!if APP_TYPE_MDI]
/////////////////////////////////////////////////////////////////////////////

Für das untergeordnete Rahmenfenster:

ChildFrm.h, ChildFrm.cpp
    Diese Dateien definieren und implementieren die Klasse [!output CHILD_FRAME_CLASS], die
    die untergeordneten Fenster in einer MDI-Anwendung unterstützt.

[!endif]
/////////////////////////////////////////////////////////////////////////////

[!if DOCVIEW]
[!if !DB_VIEW_NO_FILE]
Der Anwendungs-Assistent erstellt einen Dokumenttyp und eine Ansicht:

[!output DOC_HEADER], [!output DOC_IMPL] - das Dokument
    Diese Dateien enthalten die Klasse [!output DOC_CLASS].  Bearbeiten Sie diese Dateien,
    um Ihre speziellen Dokumentdaten hinzuzufügen und das Speichern und Laden von 
    Dateien zu implementieren (mit [!output DOC_CLASS]::Serialize).
[!if HAS_SUFFIX && !HTML_EDITVIEW]
    Das Dokument enthält folgende Zeichenfolgen:
        Datei erweiterung:      [!output FILE_EXTENSION]
        Dateityp-ID:            [!output FILE_TYPE_ID]
        Hauptrahmenbezeichnung: [!output MAIN_FRAME_CAPTION]
        Dokumenttypname:        [!output DOC_TYPE_NAME]
        Filtername:             [!output FILTER_NAME]
        Neuer kurzer Dateiname: [!output FILE_NEW_NAME_SHORT]
        Langer Dateitypname:    [!output FILE_NEW_NAME_LONG]
[!endif]
[!else]
Der Anwendungs-Assistent erstellt eine Ansicht:
[!endif]

[!output VIEW_HEADER], [!output VIEW_IMPL] - die Ansicht des Dokuments
    Diese Dateien enthalten die Klasse [!output VIEW_CLASS].
[!if !DB_VIEW_NO_FILE]
    [!output VIEW_CLASS]-Objekte werden verwendet, um [!output DOC_CLASS]-Objekte anzuzeigen.
[!endif]

[!if APP_TYPE_MDI]
res\[!output SAFE_PROJECT_NAME]Doc.ico
    Dies ist eine Symboldatei, die als Symbol für untergeordnete MDI-Fenster 
    der Klasse [!output DOC_CLASS] verwendet wird. Dieses Symbol wird durch die
    Haupt-Ressourcendatei [!output PROJECT_NAME].rc eingebunden.
[!endif]

[!endif]

[!if DB_VIEW_NO_FILE || DB_VIEW_WITH_FILE]
/////////////////////////////////////////////////////////////////////////////

Datenbankunterstützung:

[!output ROWSET_HEADER], [!output ROWSET_IMPL]
    Diese Dateien enthalten die Klasse [!output ROWSET_CLASS]. Diese Klasse wird verwendet,
    um auf die im Assistenten ausgewählte Datenquelle zuzugreifen.
[!if DB_VIEW_NO_FILE]
    Es wird keine Serialisierungsunterstützung hinzugefügt.
[!else]
    Die Serialisierungsunterstützung wurde hinzugefügt.
[!endif]
[!endif]
[!if CONTAINER || FULL_SERVER || MINI_SERVER || CONTAINER_SERVER]
/////////////////////////////////////////////////////////////////////////////

Darüber hinaus hat der Anwendungs-Assistent OLE-spezifische Klassen erzeugt.

[!if CONTAINER || CONTAINER_SERVER]
[!output CONTAINER_ITEM_HEADER], [!output CONTAINER_ITEM_IMPL]
    Diese Dateien enthalten die Klasse [!output CONTAINER_ITEM_CLASS]. Diese Klasse wird 
    zum Ändern von OLE-Objekten verwendet. OLE-Objekte werden normalerweise von der Klasse
    [!output VIEW_CLASS] angezeigt und als Teil der Klasse [!output DOC_CLASS] initialisiert.
[!if ACTIVE_DOC_CONTAINER]
    Das Programm unterstützt aktive Dokumente innerhalb seines Rahmens.
[!endif]
[!endif]
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]

[!output SERVER_ITEM_HEADER], [!output SERVER_ITEM_IMPL]
    Diese Dateien enthalten [!output SERVER_ITEM_CLASS]. diese Klasse dient der Verbindung
    der Klasse [!output DOC_CLASS] mit dem OLE-System und stellt auf Wunsch eine 
    Verknüpfung zu Ihrem Dokument zur Verfügung.
[!if ACTIVE_DOC_SERVER]
    Das Projekt unterstützt das Erstellen und Verwalten von aktiven Dokumenten.
[!endif]

[!output INPLACE_FRAME_HEADER], [!output INPLACE_FRAME_IMPL]
    Diese Dateien enthalten [!output INPLACE_FRAME_CLASS]. Diese Klasse wird abgeleitet
    von COleIPFrameWnd und steuert alle Rahmenmerkmale während der Vor-Ort-
    Aktivierung.
[!endif]

[!if SUPPORT_COMPOUND_FILES]
    Das Projekt unterstützt Verbunddateien. Im Verbunddateiformat wird ein Dokument gespeichert,
    das mindestens ein Automatisierungsobjekt enthält. Es ermöglicht den Zugriff auf das
    Objekt für die einzelnen Objekte.
[!endif]
[!endif]
[!else]

/////////////////////////////////////////////////////////////////////////////

[!if AUTOMATION]
Der Anwendungs-Assistent erstellt eine Dialogklasse und eine Automatisierungs-Proxy-Klasse:
[!else]
Der Anwendungs-Assistent erstellt eine Dialogklasse:
[!endif]

[!output DIALOG_HEADER], [!output DIALOG_IMPL] - das Dialogfeld
    Diese Dateien enthalten die Klasse [!output DIALOG_CLASS]. Diese Klasse legt das
    Verhalten des Haupt-Dialogfelds der Anwendung fest. Die Vorlage des Dialog-
    felds befindet sich in [!output PROJECT_NAME].rc, die mit Microsoft Visual C++
    bearbeitet werden kann.
[!if AUTOMATION]

[!output DIALOG_AUTO_PROXY_HEADER], [!output DIALOG_AUTO_PROXY_IMPL] - das Automatisierungsobjekt
    Diese Dateien enthalten die Klasse [!output DIALOG_AUTO_PROXY_CLASS]. Diese Klasse 
    wird als "Automatisierungs-Proxy"-Klasse für das Dialogfeld bezeichnet, 
    da diese darauf achtet, ob die Methoden und Eigenschaften verletzt werden, 
    die die Automatisierungs-Controller für den Zugriff auf das Dialogfeld verwenden. 
    Der direkte Zugriff von der Dialogfeldklasse auf diese Methoden und Eigenschaften 
    ist nicht möglich, da es bei einer modalen dialogfeldbasierten MFC-Anwendung 
    sicherer und einfacher ist, das Automatisierungsobjekt von der
    Benutzeroberfläche zu trennen.
[!endif]
[!endif]

[!if CONTEXT_HELP]
/////////////////////////////////////////////////////////////////////////////

Hilfeunterstützung:

[!if HELPSTYLE_HTML]
hlp\[!output PROJECT_NAME].hhp
    Diese Datei ist eine Hilfeprojektdatei. Sie enthält die Daten, die zum Kompilieren der
    Hilfedateien in eine CHM-Datei erforderlich sind.

hlp\[!output PROJECT_NAME].hhc
    Diese Datei listet den Inhalt des Hilfeprojekts auf.

hlp\[!output PROJECT_NAME].hhk
    Diese Datei enthält einen Index der Hilfethemen.

hlp\afxcore.htm
    Diese Datei enthält die Standardhilfethemen für MFC-Standardbefehle und Oberflächenobjekte. 
    Sie können ihre eigenen Hilfethemen zu dieser Datei hinzufügen.

[!if PRINTING]
hlp\afxprint.htm
    Diese Datei enthält die Hilfethemen für die Druckbefehle.

[!endif]
makehtmlhelp.bat
    Diese Datei wird vom Buildsystem zum Kompilieren der Hilfedateien verwendet.

hlp\Images\*.gif
    Diese sind Bitmapdateien, die für die Standardbefehle der Microsoft Foundation Class 
    Library erforderlich sind.

[!else]
hlp\[!output PROJECT_NAME].hpj
    Diese Datei ist die Hilfe-Projektdatei, die der Hilfe-Compiler für das 
    Erstellen der Hilfedatei Ihrer Anwendung verwendet.

hlp\*.bmp
    Hierbei handelt es sich um Bitmapdateien, die für die Hilfethemen der 
    Standardbefehle der Microsoft Foundation Classes-Bibliothek erforderlich sind.

hlp\*.rtf
    Diese Datei enthält die Hilfethemen für MFC-Standardbefehle und 
    	Oberflächenobjekte.
[!endif]
[!endif]

[!if ACTIVEX_CONTROLS || PRINTING || SPLITTER || MAPI || SOCKETS]
/////////////////////////////////////////////////////////////////////////////

Weitere Features:
[!if ACTIVEX_CONTROLS]

ActiveX-Steuerelemente
    Die Anwendung unterstützt die Verwendung von ActiveX-Steuerelementen.
[!endif]
[!if PRINTING]

Unterstützung für das Drucken und die Seitenansicht
    Der Anwendungs-Assistent hat den Code zum Verarbeiten der Befehle "Drucken", "Seite einrichten" und 
    "Seitenansicht" durch Aufrufen der Memberfuntkionen in der CView-Klasse der MFC-Bibliothek generiert.
[!endif]
[!if DB_SUPPORT_HEADER_ONLY && !APP_TYPE_DLG]

Datenbankunterstützung
    Der Anwendungs-Assistent hat die Basisdatenbankunterstützung für Ihr Programm hinzugefügt. 
    Nur die erforderlichen Dateien wurden einbezogen.
[!endif]
[!if SPLITTER && !APP_TYPE_DLG]

Fenster teilen
    Der Anwendungs-Assistent hat die Unterstützung zum Teilen der Fenster für Ihre Programmdokumente
    hinzugefügt.
[!endif]
[!if MAPI]

MAPI-Unterstützung
    Das generierte Projekt enthält den Code, der zum Erstellen, Ändern, Übertragen und Speichern
    von Mailnachrichten erforderlich ist.
[!endif]
[!if SOCKETS]

Windows-Sockets
    Die Anwendung unterstützt die Kommunikation über TCP/IP-Netzwerke.
[!endif]

[!endif]
/////////////////////////////////////////////////////////////////////////////

Weitere Standarddateien:

StdAfx.h, StdAfx.cpp
    Mit diesen Dateien werden vorkompilierte Headerdateien (PCH) mit der Bezeichnung
    [!output PROJECT_NAME].pch und eine vorkompilierte Typdatei mit der Bezeichnung 
    StdAfx.obj erstellt.

Resource.h
    Dies ist die Standard-Headerdatei, die neue Ressourcen-IDs definiert.
    Microsoft Visual C++ liest und aktualisiert diese Datei.

/////////////////////////////////////////////////////////////////////////////

Weitere Hinweise:

Der Anwendungs-Assistent verwendet "TODO:", um die Stellen anzuzeigen, 
an denen Sie Erweiterungen oder Anpassungen vornehmen können.
[!if APP_TYPE_MDI || APP_TYPE_SDI || APP_TYPE_DLG || APP_TYPE_MTLD]

Wenn Ihre Anwendung die MFC in einer gemeinsam genutzten DLL verwendet und 
eine andere als die aktuell auf dem Betriebssystem eingestellte Sprache verwendet, muss 
die entsprechend lokalisierte Ressource MFC70XXX.DLL von der Microsoft Visual C++ CD-ROM 
in das Verzeichnis system oder system32 kopiert und in MFCLOC.DLL umbenannt werden  
("XXX" steht für die Abkürzung der Sprache. So enthält beispielsweise MFC70DEU.DLL die ins Deutsche 
übersetzten Ressourcen.)  Anderenfalls werden einige Oberflächenelemente Ihrer Anwendung 
in der Sprache des Betriebssystems angezeigt.
[!endif]

/////////////////////////////////////////////////////////////////////////////
