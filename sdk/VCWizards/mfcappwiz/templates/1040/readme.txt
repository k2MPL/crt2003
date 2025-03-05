================================================================================
    LIBRERIA DI CLASSI MFC: [!output PROJECT_NAME] Informazioni generali sul progetto
===============================================================================

Questa applicazione [!output PROJECT_NAME] è stata creata dalla Creazione guidata applicazioni non solo per illustrare le nozioni fondamentali sull'utilizzo delle classi MFC, ma anche per fornire un punto di inizio per la creazione di un'applicazione.

In questo file è riassunto il contenuto di ciascun file che 
fa parte dell'applicazione [!output PROJECT_NAME].

[!output PROJECT_NAME].vcproj
    File di progetto principale relativo ai progetti VC++ generati utilizzando la Creazione guidata applicazioni. 
    Contiene informazioni sulla versione di Visual C++ che ha generato il file e informazioni sulle piattaforme, le configurazioni e le funzionalità del progetto
    selezionate tramite la Creazione guidata applicazioni.

[!output APP_HEADER]
    File di intestazione principale dell'applicazione. Include altre
    intestazioni specifiche del progetto, (compresa Resource.h) e 
    dichiara la classe dell'applicazione [!output APP_CLASS].

[!output APP_IMPL]
    File di origine principale dell'applicazione che contiene la
    classe dell'applicazione [!output APP_CLASS].

[!output PROJECT_NAME].rc
    Elenco di tutte le risorse Microsoft Windows utilizzate dal
    programma. Include le icone, le bitmap e i cursori memorizzati nella 
    sottodirectory RES. È possibile modificare questo file direttamente in
    Microsoft Visual C++. Le risorse del progetto si trovano in [!output LCID].

res\[!output SAFE_PROJECT_NAME].ico
    File di icona che viene utilizzato come icona dell'applicazione.
    L'icona è inclusa dal principale file di risorse [!output PROJECT_NAME].rc.

res\[!output SAFE_PROJECT_NAME].rc2
    File contenente risorse che non sono modificate da Microsoft 
    Visual C++. È necessario inserire in questo file tutte le risorse
    non modificabili dall'editor di risorse.
[!if CONTAINER_SERVER || FULL_SERVER || MINI_SERVER || AUTOMATION || HAS_SUFFIX]
[!if !HTML_EDITVIEW]
[!output PROJECT_NAME].reg
    File .REG di esempio in cui è illustrato il tipo di impostazioni 
    di registrazione che verranno configurate dal framework.
    È possibile utilizzarlo come file .REG 
[!if APP_TYPE_DLG]
    per procedere con l'applicazione.
[!else]
    per procedere con l'applicazione o semplicemente per eliminarla e basarsi
    sulla registrazione predefinita di RegisterShellFileTypes.
[!endif]

[!if AUTOMATION]
[!output PROJECT_NAME].idl
    File contenente il codice di origine del linguaggio di
    descrizione dell'interfaccia per la libreria dei tipi relativa
    all'applicazione creata.
[!endif]
[!endif]
[!endif]

[!if !APP_TYPE_DLG]
/////////////////////////////////////////////////////////////////////////////

Finestra del frame principale:
[!if PROJECT_STYLE_EXPLORER]
    Stile di Esplora risorse: il progetto conterrà un'interfaccia a due frame, simile a Esplora risorse.
[!else]
    Il progetto include un'interfaccia MFC standard.
[!endif]

[!output MAIN_FRAME_HEADER], [!output MAIN_FRAME_IMPL]
    Questi file contengono la classe di frame [!output MAIN_FRAME_CLASS], che
deriva da
[!if APP_TYPE_MDI]
    CMDIFrameWnd e controlla tutte le funzionalità dei frame MDI.
[!else]
    CFrameWnd e controlla tutte le funzionalità dei frame SDI.
[!endif]
[!if PROJECT_STYLE_EXPLORER]

[!output TREE_VIEW_HEADER], [!output TREE_VIEW_IMPL]
    Questi file contengono la classe dei frame di sinistra [!output TREE_VIEW_CLASS], che deriva da
    CTreeView.
[!endif]

[!if DOCKING_TOOLBAR]
res\Toolbar.bmp
    File bitmap utilizzato per creare immagini affiancate per
    la barra degli strumenti.
    La barra degli strumenti e la barra di stato iniziali sono costruite nella
    classe [!output MAIN_FRAME_CLASS]. Modificare la bitmap della barra degli
    strumenti utilizzando l'editor di risorse e aggiornare la matrice 
    IDR_MAINFRAME TOOLBAR in [!output PROJECT_NAME].rc per aggiungere i
    pulsanti della barra degli strumenti.
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]

res\IToolbar.bmp
    File bitmap utilizzato per creare immagini affiancate per la
    barra degli strumenti quando l'applicazione server è attivata sul posto
    all'interno di un altro contenitore. Questa barra degli strumenti è
    costruita nella classe [!output INPLACE_FRAME_CLASS].
    Questo file bitmap è simile a quello contenuto in res\Toolbar.bmp.
    L'unica differenza è che in questo file sono stati rimossi molti comandi
    che non sono relativi al server.

[!endif]
[!endif]
[!if APP_TYPE_MDI]
/////////////////////////////////////////////////////////////////////////////

Finestra di frame secondaria:

ChildFrm.h, ChildFrm.cpp
    Questi file consentono di definire e di implementare la classe 
    [!output CHILD_FRAME_CLASS], che supporta le finestre secondarie di
    un'applicazione MDI.

[!endif]
/////////////////////////////////////////////////////////////////////////////

[!if DOCVIEW]
[!if !DB_VIEW_NO_FILE]
La Creazione guidata applicazioni crea un tipo di documento e una vista:

[!output DOC_HEADER], [!output DOC_IMPL] - documento
    Questi file contengono la classe [!output DOC_CLASS]. Modificare i file
    per aggiungere dati particolari relativi al documento e per implementare
    il salvataggio e il caricamento di file
    (tramite [!output DOC_CLASS]::Serialize).
[!if HAS_SUFFIX && !HTML_EDITVIEW]
    Nel documento saranno presenti le seguenti stringhe:
        Estensione file:      [!output FILE_EXTENSION]
        ID tipo file:        [!output FILE_TYPE_ID]
        Didascalia frame principale:  [!output MAIN_FRAME_CAPTION]
        Nome tipo doc:       [!output SAFE_DOC_TYPE_NAME]
        Nome filtro:         [!output FILTER_NAME]
        Nuovo nome breve file: [!output FILE_NEW_NAME_SHORT]
        Nuovo nome lungo file+++: [!output FILE_NEW_NAME_LONG]
[!endif]
[!else]
La Creazione guidata applicazioni crea una vista:
[!endif]

[!output VIEW_HEADER], [!output VIEW_IMPL] - vista del documento
    Questi file contengono la classe [!output VIEW_CLASS].
[!if !DB_VIEW_NO_FILE]
    Gli oggetti [!output VIEW_CLASS] vengono utilizzati per visualizzare gli oggetti [!output DOC_CLASS].
[!endif]

[!if APP_TYPE_MDI]
res\[!output SAFE_PROJECT_NAME]Doc.ico
    File icona, utilizzato come icona delle finestre secondarie MDI
    per la classe [!output DOC_CLASS]. Questa icona è inclusa dal file di
    risorse principale [!output PROJECT_NAME].rc.
[!endif]

[!endif]

[!if DB_VIEW_NO_FILE || DB_VIEW_WITH_FILE]
/////////////////////////////////////////////////////////////////////////////

Supporto database:

[!output ROWSET_HEADER], [!output ROWSET_IMPL]
    Questi file contengono la classe [!output ROWSET_CLASS], utilizzata per accedere all'origine dati selezionata nella procedura guidata.
[!if DB_VIEW_NO_FILE]
    Non verrà aggiunto alcun supporto di serializzazione.
[!else]
    È stato aggiunto un supporto di serializzazione.
[!endif]
[!endif]
[!if CONTAINER || FULL_SERVER || MINI_SERVER || CONTAINER_SERVER]
/////////////////////////////////////////////////////////////////////////////

La Creazione guidata applicazioni ha anche creato classi specifiche per OLE.

[!if CONTAINER || CONTAINER_SERVER]
[!output CONTAINER_ITEM_HEADER], [!output CONTAINER_ITEM_IMPL]
    Questi file contengono la classe [!output CONTAINER_ITEM_CLASS]. Questa
    classe è utilizzata per manipolare gli oggetti OLE che vengono in genere
    utilizzati dalla classe [!output VIEW_CLASS] e serializzati come parte 
    della classe [!output DOC_CLASS].
[!if ACTIVE_DOC_CONTAINER]
    Il programma include il supporto per contenere documenti attivi all'interno
    del proprio frame.
[!endif]
[!endif]
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]

[!output SERVER_ITEM_HEADER], [!output SERVER_ITEM_IMPL]
    Questi file contengono la classe [!output SERVER_ITEM_CLASS], che viene
    utilizzata per connettere la classe [!output DOC_CLASS] al sistema OLE
    e facoltativamente fornisce i collegamenti al documento.
[!if ACTIVE_DOC_SERVER]
    Il progetto dispone del supporto per la creazione e la gestione di documenti
    attivi.
[!endif]

[!output INPLACE_FRAME_HEADER], [!output INPLACE_FRAME_IMPL]
    Questi file contengono la classe [!output INPLACE_FRAME_CLASS], che deriva da COleIPFrameWnd e controlla tutte le funzionalità del frame durante
    l'attivazione sul posto.
[!endif]

[!if SUPPORT_COMPOUND_FILES]
    Il progetto dispone di supporto per file composti. Il formato file composti memorizza in un file un documento che contiene uno o più oggetti di automazione
    e consente comunque l'accesso +++to the it for the individual objects.
[!endif]
[!endif]
[!else]

/////////////////////////////////////////////////////////////////////////////

[!if AUTOMATION]
La Creazione guidata applicazioni crea una classe di finestre di dialogo e una classe proxy di automazione:
[!else]
La Creazione guidata applicazioni crea una classe di finestre di dialogo:
[!endif]

[!output DIALOG_HEADER], [!output DIALOG_IMPL] - Finestra di dialogo
    Questi file contengono la classe [!output DIALOG_CLASS]. Questa classe
    definisce il comportamento della finestra principale dell'applicazione
    creata. Il modello della finestra di dialogo si trova nel progetto 
    [!output PROJECT_NAME].rc, che può essere modificato in 
    Microsoft Visual C++.
[!if AUTOMATION]

[!output DIALOG_AUTO_PROXY_HEADER], [!output DIALOG_AUTO_PROXY_IMPL] - oggetto di automazione
    Questi file contengono la classe[!output DIALOG_AUTO_PROXY_CLASS],
    denominata classe "proxy di automazione" per la finestra di dialogo, in
    quanto si occupa dell'esposizione dei metodi e delle proprietà di
    automazione che i controller di automazione possono utilizzare per accedere
    alla finestra di dialogo. Questi metodi non vengono esposti direttamente
    dalla classe delle finestre di dialogo, poiché nel caso di un'applicazione
    MFC modale basata su finestre di dialogo è più semplice e corretto tenere
    separato l'oggetto di automazione dall'interfaccia utente.
[!endif]
[!endif]

[!if CONTEXT_HELP]
/////////////////////////////////////////////////////////////////////////////

Supporto Guida:

[!if HELPSTYLE_HTML]
hlp\[!output PROJECT_NAME].hhp
    File di progetto della Guida contenente i dati necessari
    per compilare i file della Guida in un file .chm.

hlp\[!output PROJECT_NAME].hhc
    File in cui è riportato il contenuto del progetto relativo alla Guida.

hlp\[!output PROJECT_NAME].hhk
    File contenente l'indice degli argomenti della Guida.

hlp\afxcore.htm
    File contenente gli argomenti della Guida standard per i comandi MFC
    standard e gli oggetti dello schermo. Aggiungere a questo file gli 
    argomenti della Guida personali.

[!if PRINTING]
hlp\afxprint.htm
    File contenente gli argomenti della Guida relativi ai comandi di stampa.

[!endif]
makehtmlhelp.bat
    File utilizzato dal sistema di generazione per compilare i file della Guida.

hlp\Images\*.gif
    File bitmap richiesti dagli argomenti dei file della Guida per
    i comandi standard della libreria delle classi MFC.

[!else]
hlp\[!output PROJECT_NAME].hpj
    File di progetto della Guida utilizzato dal compilatore
    della Guida per creare il file della Guida dell'applicazione.

hlp\*.bmp
    File bitmap richiesti dagli argomenti dei file della Guida
    standard per i comandi standard della libreria della classi MCF.

hlp\*.rtf
    Questi file contengono gli argomenti della Guida standard per i comandi standard MFC e gli oggetti dello schermo.
[!endif]
[!endif]

[!if ACTIVEX_CONTROLS || PRINTING || SPLITTER || MAPI || SOCKETS]
/////////////////////////////////////////////////////////////////////////////

Altre funzionalità:
[!if ACTIVEX_CONTROLS]

Controlli ActiveX
    L'applicazione include il supporto per l'utilizzo dei controlli ActiveX.
[!endif]
[!if PRINTING]

Supporto per la stampa e per la visualizzazione in anteprima
    La Creazione guidata applicazioni ha generato il codice per la gestione
    dei comandi Stampa, Imposta stampante e Anteprima di stampa richiamando le
    funzioni membro della classe CView dalla libreria MFC.
[!endif]
[!if DB_SUPPORT_HEADER_ONLY && !APP_TYPE_DLG]

Supporto database
    La Creazione guidata applicazioni ha aggiunto il supporto di base del
    database per il programma. Sono stati inclusi solo i file necessari.
[!endif]
[!if SPLITTER && !APP_TYPE_DLG]

Suddivisione della finestra
    La Creazione guidata applicazioni ha aggiunto il supporto per finestre con
    separatore per i documenti dell'applicazione.
[!endif]
[!if MAPI]

Supporto MAPI
    Il progetto generato contiene il codice necessario per creare, manipolare,
    trasferire e memorizzare i messaggi di posta elettronica.
[!endif]
[!if SOCKETS]

Windows Socket
    L'applicazione è dotata di supporto per le connessioni in rete TCP/IP.
[!endif]

[!endif]
/////////////////////////////////////////////////////////////////////////////

Altri file standard:

StdAfx.h, StdAfx.cpp
    Questi file sono utilizzati per creare un file di intestazione 
    precompilato (PCH, precompiled header )denominato [!output PROJECT_NAME].pch 
    e tipi di file precompilati denominati StdAfx.obj.

Resource.h
    File di intestazione standard che definisce nuovi ID di risorse.
    Con Microsoft Visual C++ è possibile leggere e aggiornare questo file.

/////////////////////////////////////////////////////////////////////////////

Altre note:

La Creazione guidata applicazioni utilizza l'istruzione "TODO:" per indicare parti del codice di origine che vanno aggiunte o personalizzate.
[!if APP_TYPE_MDI || APP_TYPE_SDI || APP_TYPE_DLG || APP_TYPE_MTLD]

Se l'applicazione utilizza classi MFC in una DLL condivisa ed è scritta in una lingua diversa da quella del sistema operativo corrente, sarà necessario copiare le rispettive risorse localizzate MFC70XXX.DLL dalla directory Win\System contenuta nel CD-ROM di Microsoft Visual C++ al sistema del computer o directory system32 e rinominare la DLL in MFCLOC.DLL. ("XXX" sta per l'abbreviazione della lingua. Ad esempio, MFC70DEU.DLL contiene le risorse tradotte in tedesco.) Se non si esegue questa operazione, alcuni elementi di interfaccia dell'applicazione rimarranno nella lingua del sistema operativo.
[!endif]

/////////////////////////////////////////////////////////////////////////////
