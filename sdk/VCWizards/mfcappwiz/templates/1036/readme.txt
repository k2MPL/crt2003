=================================================================================================
    BIBLIOTHÈQUE MICROSOFT FOUNDATION CLASS : Vue d'ensemble du projet [!output PROJECT_NAME]
=================================================================================================

AppWizard a créé cette application [!output PROJECT_NAME] à votre attention. Cette application
explique les principes fondamentaux de l'utilisation des classes MFC (Microsoft Foundation Class)
et constitue également un point de départ pour écrire votre propre application.

Ce fichier fait la synthèse des différents éléments contenus dans chacun des fichiers qui constituent
votre application [!output PROJECT_NAME].

[!output PROJECT_NAME].vcproj
    Il s'agit du fichier projet principal pour les projets VC++ générés à l'aide d'un Assistant Application.
    Ce fichier contient des informations sur la version de Visual C++ qui a été utilisée pour générer
    le fichier ainsi que des informations relatives aux plates-formes, configurations et fonctionnalités
    sélectionnées dans l'Assistant Application.

[!output APP_HEADER]
    Il s'agit du fichier d'en-tête principal pour l'application. Il comporte
    d'autres en-têtes de projet spécifiques (notamment Resource.h) et déclare la
    classe d'application [!output APP_CLASS].

[!output APP_IMPL]
    Il s'agit du fichier source principal pour l'application. Il contient la classe
    d'application [!output APP_CLASS].

[!output PROJECT_NAME].rc
    Ce fichier dresse la liste de toutes les ressources Microsoft Windows utilisées
    par le programme, telles que les icônes, bitmaps et curseurs qui sont stockés
    dans le sous-répertoire RES. Vous pouvez modifier ce fichier directement dans Microsoft
    Visual C++. Vos ressources projet se trouvent dans [!output LCID].

res\[!output SAFE_PROJECT_NAME].ico
    Il s'agit du fichier icône utilisé en tant qu'icône de l'application. Cette icône
    est incluse dans le fichier de ressources principal [!output PROJECT_NAME].rc.

res\[!output SAFE_PROJECT_NAME].rc2
    Ce fichier contient les ressources qui ne sont pas modifiées par Microsoft 
    Visual C++. Vous devez y placer toutes les ressources non modifiables par
    l'Éditeur de ressources.
[!if CONTAINER_SERVER || FULL_SERVER || MINI_SERVER || AUTOMATION || HAS_SUFFIX]
[!if !HTML_EDITVIEW]
[!output PROJECT_NAME].reg
    C'est un exemple de fichier .REG qui vous montre quels paramètres d'inscription
    sont définis par l'infrastructure. Vous pouvez l'utiliser comme un fichier .REG
[!if APP_TYPE_DLG]
    avec votre application.
[!else]
    avec votre application ou bien le supprimer afin que les paramètres d'inscription
    définis dans RegisterShellFileTypes soient appliqués par défaut.
[!endif]

[!if AUTOMATION]
[!output PROJECT_NAME].idl
    Ce fichier contient le code source IDL (Interface Description Language) correspondant
    à la bibliothèque de types de votre application.
[!endif]
[!endif]
[!endif]

[!if !APP_TYPE_DLG]
/////////////////////////////////////////////////////////////////////////////

Pour la fenêtre frame principale :
[!if PROJECT_STYLE_EXPLORER]
    Style Explorateur Windows : Le projet a une interface de type Explorateur Windows,
    avec deux frames.
[!else]
    Le projet a une interface MFC standard.
[!endif]

[!output MAIN_FRAME_HEADER], [!output MAIN_FRAME_IMPL]
    Ces fichiers contiennent la classe de frames [!output MAIN_FRAME_CLASS], dérivée de
[!if APP_TYPE_MDI]
    CMDIFrameWnd et qui contrôle toutes les fonctionnalités des frames MDI.
[!else]
    CFrameWnd et qui contrôle toutes les fonctionnalités des frames SDI.
[!endif]
[!if PROJECT_STYLE_EXPLORER]

[!output TREE_VIEW_HEADER], [!output TREE_VIEW_IMPL]
    Ces fichiers contiennent la classe du frame gauche [!output TREE_VIEW_CLASS], dérivée de
    CTreeView.
[!endif]

[!if DOCKING_TOOLBAR]
res\Toolbar.bmp
    Ce fichier bitmap permet de créer des images en mosaïque pour la barre d'outils.
    La barre d'outils et la barre d'état initiales sont créées dans la classe [!output MAIN_FRAME_CLASS].
    Éditez cette bitmap de barre d'outils dans l'Éditeur de ressources, puis
    mettez à jour le tableau IDR_MAINFRAME TOOLBAR dans [!output PROJECT_NAME].rc pour ajouter
    des boutons de barre d'outils.
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]

res\IToolbar.bmp
    Ce fichier bitmap permet de créer des images en mosaïque pour la barre d'outils
    lorsque votre application serveur est activée sur place au sein d'un autre conteneur.
    La barre d'outils est créée dans la classe [!output INPLACE_FRAME_CLASS].
    Cette bitmap est semblable à la bitmap res\Toolbar.bmp,
    à la différence qu'elle comporte beaucoup moins de commandes non-serveur.

[!endif]
[!endif]
[!if APP_TYPE_MDI]
/////////////////////////////////////////////////////////////////////////////

Pour la fenêtre frame enfant :

ChildFrm.h, ChildFrm.cpp
    Ces fichiers définissent et implémentent la classe [!output CHILD_FRAME_CLASS], qui
    prend en charge les fenêtres enfants dans une application MDI.

[!endif]
/////////////////////////////////////////////////////////////////////////////

[!if DOCVIEW]
[!if !DB_VIEW_NO_FILE]
AppWizard crée un type de document et une vue :

[!output DOC_HEADER], [!output DOC_IMPL] - le document
    Ces fichiers contiennent votre classe [!output DOC_CLASS]. Éditez-les pour ajouter vos
    propres données de document et pour implémenter l'enregistrement et le chargement de fichier
    (via [!output DOC_CLASS]::Serialize).
[!if HAS_SUFFIX && !HTML_EDITVIEW]
    Le document comporte les chaînes suivantes :
        Extension de fichier :         [!output FILE_EXTENSION]
        ID du type de fichier :        [!output FILE_TYPE_ID]
        Légende du frame principal :   [!output MAIN_FRAME_CAPTION]
        Nom du type de document :      [!output SAFE_DOC_TYPE_NAME]
        Nom du filtre :                [!output FILTER_NAME]
        Nouveau nom court de fichier : [!output FILE_NEW_NAME_SHORT]
        Nom long du type de fichier :  [!output FILE_NEW_NAME_LONG]
[!endif]
[!else]
AppWizard crée une vue :
[!endif]

[!output VIEW_HEADER], [!output VIEW_IMPL] - la vue du document
    Ces fichiers contiennent votre classe [!output VIEW_CLASS].
[!if !DB_VIEW_NO_FILE]
    Les objets [!output VIEW_CLASS] servent à afficher les objets [!output DOC_CLASS].
[!endif]

[!if APP_TYPE_MDI]
res\[!output SAFE_PROJECT_NAME]Doc.ico
    Il s'agit du fichier icône utilisé en tant qu'icône des fenêtres enfants MDI
    pour la classe [!output DOC_CLASS]. Cette icône est incluse dans le fichier de
    ressources principal [!output PROJECT_NAME].rc.
[!endif]

[!endif]

[!if DB_VIEW_NO_FILE || DB_VIEW_WITH_FILE]
/////////////////////////////////////////////////////////////////////////////

Prise en charge des bases de données :

[!output ROWSET_HEADER], [!output ROWSET_IMPL]
    Ces fichiers contiennent votre classe [!output ROWSET_CLASS], qui est utilisée pour
    accéder à la source de données que vous avez sélectionnée dans l'Assistant.
[!if DB_VIEW_NO_FILE]
    Aucune prise en charge de la sérialisation ne sera ajoutée.
[!else]
    Une prise en charge de la sérialisation a été ajoutée.
[!endif]
[!endif]
[!if CONTAINER || FULL_SERVER || MINI_SERVER || CONTAINER_SERVER]
/////////////////////////////////////////////////////////////////////////////

AppWizard a également créé des classes spécifiques à OLE

[!if CONTAINER || CONTAINER_SERVER]
[!output CONTAINER_ITEM_HEADER], [!output CONTAINER_ITEM_IMPL]
    Ces fichiers contiennent votre classe [!output CONTAINER_ITEM_CLASS], qui est utilisée pour 
    manipuler les objets OLE. Ces objets sont généralement affichés par votre
    classe [!output VIEW_CLASS] et sérialisés dans votre classe [!output DOC_CLASS].
[!if ACTIVE_DOC_CONTAINER]
    Ce programme offre une prise en charge pour contenir des documents actifs dans son frame.
[!endif]
[!endif]
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]

[!output SERVER_ITEM_HEADER], [!output SERVER_ITEM_IMPL]
    Ces fichiers contiennent votre classe [!output SERVER_ITEM_CLASS], qui est utilisée pour
    connecter votre classe [!output DOC_CLASS] au système OLE et éventuellement,
    fournir des liens vers votre document.
[!if ACTIVE_DOC_SERVER]
    Le projet offre une prise en charge pour la création et la gestion des documents actifs.
[!endif]

[!output INPLACE_FRAME_HEADER], [!output INPLACE_FRAME_IMPL]
    Ces fichiers contiennent votre classe [!output INPLACE_FRAME_CLASS], dérivée de
    COleIPFrameWnd. Cette classe contrôle toutes les fonctionnalités des frames lors de
    l'activation sur place.
[!endif]

[!if SUPPORT_COMPOUND_FILES]
    Le projet offre une prise en charge des fichiers composés. Le format de fichier composé permet
    de stocker un document contenant un ou plusieurs objets Automation dans un seul fichier, tout
    en autorisant l'accès à chacun des objets de ce fichier.
[!endif]
[!endif]
[!else]

/////////////////////////////////////////////////////////////////////////////

[!if AUTOMATION]
AppWizard crée une classe de dialogue et une classe proxy Automation :
[!else]
AppWizard crée une classe de dialogue :
[!endif]

[!output DIALOG_HEADER], [!output DIALOG_IMPL] - la boîte de dialogue
    Ces fichiers contiennent votre classe [!output DIALOG_CLASS], qui définit le
    comportement de la boîte de dialogue principale de votre application. Le modèle de boîte de
    dialogue se trouve dans le fichier [!output PROJECT_NAME].rc, modifiable dans Microsoft Visual C++.
[!if AUTOMATION]

[!output DIALOG_AUTO_PROXY_HEADER], [!output DIALOG_AUTO_PROXY_IMPL] - l'objet Automation
    Ces fichiers contiennent votre classe [!output DIALOG_AUTO_PROXY_CLASS]. Celle-ci
    est appelée classe "proxy Automation" pour votre boîte de dialogue, car elle expose
    les méthodes et propriétés Automation qui peuvent être utilisées par les
    contrôleurs Automation pour accéder à la boîte de dialogue. Ces méthodes et propriétés
    ne sont pas exposées directement à partir de la classe de dialogue ; en effet, dans le cas
    d'une application MFC constituée de boîtes de dialogue modales, il est plus clair et facile
    de séparer l'objet Automation et l'interface utilisateur.
[!endif]
[!endif]

[!if CONTEXT_HELP]
/////////////////////////////////////////////////////////////////////////////

Prise en charge de l'aide :

[!if HELPSTYLE_HTML]
hlp\[!output PROJECT_NAME].hhp
    Ce fichier est un fichier projet d'aide. Il contient les données nécessaires
    à la compilation des fichiers d'aide en un fichier .chm.

hlp\[!output PROJECT_NAME].hhc
    Ce fichier affiche le contenu du fichier projet d'aide.

hlp\[!output PROJECT_NAME].hhk
    Ce fichier comporte un index des rubriques d'aide.

hlp\afxcore.htm
    Ce fichier contient les rubriques d'aide standard relatives aux commandes MFC
    et aux objets de l'écran standard. Ajoutez-y vos propres rubriques d'aide.

[!if PRINTING]
hlp\afxprint.htm
    Ce fichier contient les rubriques d'aide relatives aux commandes d'impression.

[!endif]
makehtmlhelp.bat
    Ce fichier est utilisé par le système de génération pour compiler les fichiers d'aide.

hlp\Images\*.gif
    Il s'agit des fichiers bitmap requis par les rubriques d'aide standard pour
    les commandes standard de la bibliothèque MFC (Microsoft Foundation Class).

[!else]
hlp\[!output PROJECT_NAME].hpj
    Ce fichier est le fichier projet d'aide utilisé par le compilateur d'aide pour créer
    le fichier d'aide spécifique à votre application.

hlp\*.bmp
    Il s'agit des fichiers bitmap requis par les rubriques d'aide standard pour
    les commandes standard de la bibliothèque MFC (Microsoft Foundation Class).

hlp\*.rtf
    Ces fichiers contiennent les rubriques d'aide standard relatives aux commandes MFC
    et objets de l'écran standard.
[!endif]
[!endif]

[!if ACTIVEX_CONTROLS || PRINTING || SPLITTER || MAPI || SOCKETS]
/////////////////////////////////////////////////////////////////////////////

Autres fonctionnalités :
[!if ACTIVEX_CONTROLS]

Contrôles ActiveX
    L'application offre la prise en charge des contrôles ActiveX.
[!endif]
[!if PRINTING]

Prise en charge de l'aperçu avant impression et de l'impression
    AppWizard a généré le code requis pour gérer les commandes Impression, Configuration de l'impression et
    Aperçu avant impression en appelant des fonctions membres de la classe CView à partir de la bibliothèque MFC.
[!endif]
[!if DB_SUPPORT_HEADER_ONLY && !APP_TYPE_DLG]

Prise en charge des bases de données
    AppWizard a ajouté une prise en charge minimale des bases de données pour votre programme.
    Seuls les fichiers strictement nécessaires ont été inclus.
[!endif]
[!if SPLITTER && !APP_TYPE_DLG]

Fractionnement des fenêtres
    AppWizard a ajouté une prise en charge des fenêtres fractionnées pour les documents de votre application.
[!endif]
[!if MAPI]

Prise en charge de MAPI
    Le projet généré contient le code requis pour créer, manipuler, transmettre et stocker
    des messages électroniques.
[!endif]
[!if SOCKETS]

Windows Sockets
    L'application offre une prise en charge permettant d'établir des communications via les réseaux TCP/IP.
[!endif]

[!endif]
/////////////////////////////////////////////////////////////////////////////

Autres fichiers standard :

StdAfx.h, StdAfx.cpp
    Ces fichiers servent à générer un fichier d'en-tête précompilé (PCH),
    appelé [!output PROJECT_NAME].pch, et un fichier de types précompilés StdAfx.obj.

Resource.h
    Il s'agit du fichier d'en-tête standard, qui définit les ID des nouvelles ressources.
    Ce fichier est lu et mis à jour par Microsoft Visual C++.

/////////////////////////////////////////////////////////////////////////////

Autres remarques :

AppWizard utilise "TODO:" pour vous signaler les parties du code source
que vous devez ajouter ou personnaliser.
[!if APP_TYPE_MDI || APP_TYPE_SDI || APP_TYPE_DLG || APP_TYPE_MTLD]

Si votre application utilise MFC dans une DLL partagée et que la langue de cette
application n'est pas la même que celle utilisée par le système d'exploitation, vous
devez copier les ressources localisées MFC70XXX.DLL correspondantes (situées sur le
CD-ROM Microsoft Visual C++ dans le répertoire Win\System) dans le répertoire system
ou system32 de votre ordinateur, puis renommer MFC70XXX.DLL en MFCLOC.DLL. ("XXX" est
l'abréviation de la langue. Par exemple, MFC70DEU.DLL contient les ressources en allemand.)
Si vous ne copiez pas la version localisée des ressources, certains éléments d'interface de
votre application seront affichés dans la langue du système d'exploitation.
[!endif]

/////////////////////////////////////////////////////////////////////////////
