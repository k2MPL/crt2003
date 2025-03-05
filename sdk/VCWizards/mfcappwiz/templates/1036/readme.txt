=================================================================================================
    BIBLIOTH�QUE MICROSOFT FOUNDATION CLASS : Vue d'ensemble du projet [!output PROJECT_NAME]
=================================================================================================

AppWizard a cr�� cette application [!output PROJECT_NAME] � votre attention. Cette application
explique les principes fondamentaux de l'utilisation des classes MFC (Microsoft Foundation Class)
et constitue �galement un point de d�part pour �crire votre propre application.

Ce fichier fait la synth�se des diff�rents �l�ments contenus dans chacun des fichiers qui constituent
votre application [!output PROJECT_NAME].

[!output PROJECT_NAME].vcproj
    Il s'agit du fichier projet principal pour les projets VC++ g�n�r�s � l'aide d'un Assistant Application.
    Ce fichier contient des informations sur la version de Visual C++ qui a �t� utilis�e pour g�n�rer
    le fichier ainsi que des informations relatives aux plates-formes, configurations et fonctionnalit�s
    s�lectionn�es dans l'Assistant Application.

[!output APP_HEADER]
    Il s'agit du fichier d'en-t�te principal pour l'application. Il comporte
    d'autres en-t�tes de projet sp�cifiques (notamment Resource.h) et d�clare la
    classe d'application [!output APP_CLASS].

[!output APP_IMPL]
    Il s'agit du fichier source principal pour l'application. Il contient la classe
    d'application [!output APP_CLASS].

[!output PROJECT_NAME].rc
    Ce fichier dresse la liste de toutes les ressources Microsoft Windows utilis�es
    par le programme, telles que les ic�nes, bitmaps et curseurs qui sont stock�s
    dans le sous-r�pertoire RES. Vous pouvez modifier ce fichier directement dans Microsoft
    Visual C++. Vos ressources projet se trouvent dans [!output LCID].

res\[!output SAFE_PROJECT_NAME].ico
    Il s'agit du fichier ic�ne utilis� en tant qu'ic�ne de l'application. Cette ic�ne
    est incluse dans le fichier de ressources principal [!output PROJECT_NAME].rc.

res\[!output SAFE_PROJECT_NAME].rc2
    Ce fichier contient les ressources qui ne sont pas modifi�es par Microsoft 
    Visual C++. Vous devez y placer toutes les ressources non modifiables par
    l'�diteur de ressources.
[!if CONTAINER_SERVER || FULL_SERVER || MINI_SERVER || AUTOMATION || HAS_SUFFIX]
[!if !HTML_EDITVIEW]
[!output PROJECT_NAME].reg
    C'est un exemple de fichier .REG qui vous montre quels param�tres d'inscription
    sont d�finis par l'infrastructure. Vous pouvez l'utiliser comme un fichier .REG
[!if APP_TYPE_DLG]
    avec votre application.
[!else]
    avec votre application ou bien le supprimer afin que les param�tres d'inscription
    d�finis dans RegisterShellFileTypes soient appliqu�s par d�faut.
[!endif]

[!if AUTOMATION]
[!output PROJECT_NAME].idl
    Ce fichier contient le code source IDL (Interface Description Language) correspondant
    � la biblioth�que de types de votre application.
[!endif]
[!endif]
[!endif]

[!if !APP_TYPE_DLG]
/////////////////////////////////////////////////////////////////////////////

Pour la fen�tre frame principale :
[!if PROJECT_STYLE_EXPLORER]
    Style Explorateur Windows : Le projet a une interface de type Explorateur Windows,
    avec deux frames.
[!else]
    Le projet a une interface MFC standard.
[!endif]

[!output MAIN_FRAME_HEADER], [!output MAIN_FRAME_IMPL]
    Ces fichiers contiennent la classe de frames [!output MAIN_FRAME_CLASS], d�riv�e de
[!if APP_TYPE_MDI]
    CMDIFrameWnd et qui contr�le toutes les fonctionnalit�s des frames MDI.
[!else]
    CFrameWnd et qui contr�le toutes les fonctionnalit�s des frames SDI.
[!endif]
[!if PROJECT_STYLE_EXPLORER]

[!output TREE_VIEW_HEADER], [!output TREE_VIEW_IMPL]
    Ces fichiers contiennent la classe du frame gauche [!output TREE_VIEW_CLASS], d�riv�e de
    CTreeView.
[!endif]

[!if DOCKING_TOOLBAR]
res\Toolbar.bmp
    Ce fichier bitmap permet de cr�er des images en mosa�que pour la barre d'outils.
    La barre d'outils et la barre d'�tat initiales sont cr��es dans la classe [!output MAIN_FRAME_CLASS].
    �ditez cette bitmap de barre d'outils dans l'�diteur de ressources, puis
    mettez � jour le tableau IDR_MAINFRAME TOOLBAR dans [!output PROJECT_NAME].rc pour ajouter
    des boutons de barre d'outils.
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]

res\IToolbar.bmp
    Ce fichier bitmap permet de cr�er des images en mosa�que pour la barre d'outils
    lorsque votre application serveur est activ�e sur place au sein d'un autre conteneur.
    La barre d'outils est cr��e dans la classe [!output INPLACE_FRAME_CLASS].
    Cette bitmap est semblable � la bitmap res\Toolbar.bmp,
    � la diff�rence qu'elle comporte beaucoup moins de commandes non-serveur.

[!endif]
[!endif]
[!if APP_TYPE_MDI]
/////////////////////////////////////////////////////////////////////////////

Pour la fen�tre frame enfant :

ChildFrm.h, ChildFrm.cpp
    Ces fichiers d�finissent et impl�mentent la classe [!output CHILD_FRAME_CLASS], qui
    prend en charge les fen�tres enfants dans une application MDI.

[!endif]
/////////////////////////////////////////////////////////////////////////////

[!if DOCVIEW]
[!if !DB_VIEW_NO_FILE]
AppWizard cr�e un type de document et une vue :

[!output DOC_HEADER], [!output DOC_IMPL] - le document
    Ces fichiers contiennent votre classe [!output DOC_CLASS]. �ditez-les pour ajouter vos
    propres donn�es de document et pour impl�menter l'enregistrement et le chargement de fichier
    (via [!output DOC_CLASS]::Serialize).
[!if HAS_SUFFIX && !HTML_EDITVIEW]
    Le document comporte les cha�nes suivantes :
        Extension de fichier :         [!output FILE_EXTENSION]
        ID du type de fichier :        [!output FILE_TYPE_ID]
        L�gende du frame principal :   [!output MAIN_FRAME_CAPTION]
        Nom du type de document :      [!output SAFE_DOC_TYPE_NAME]
        Nom du filtre :                [!output FILTER_NAME]
        Nouveau nom court de fichier : [!output FILE_NEW_NAME_SHORT]
        Nom long du type de fichier :  [!output FILE_NEW_NAME_LONG]
[!endif]
[!else]
AppWizard cr�e une vue :
[!endif]

[!output VIEW_HEADER], [!output VIEW_IMPL] - la vue du document
    Ces fichiers contiennent votre classe [!output VIEW_CLASS].
[!if !DB_VIEW_NO_FILE]
    Les objets [!output VIEW_CLASS] servent � afficher les objets [!output DOC_CLASS].
[!endif]

[!if APP_TYPE_MDI]
res\[!output SAFE_PROJECT_NAME]Doc.ico
    Il s'agit du fichier ic�ne utilis� en tant qu'ic�ne des fen�tres enfants MDI
    pour la classe [!output DOC_CLASS]. Cette ic�ne est incluse dans le fichier de
    ressources principal [!output PROJECT_NAME].rc.
[!endif]

[!endif]

[!if DB_VIEW_NO_FILE || DB_VIEW_WITH_FILE]
/////////////////////////////////////////////////////////////////////////////

Prise en charge des bases de donn�es :

[!output ROWSET_HEADER], [!output ROWSET_IMPL]
    Ces fichiers contiennent votre classe [!output ROWSET_CLASS], qui est utilis�e pour
    acc�der � la source de donn�es que vous avez s�lectionn�e dans l'Assistant.
[!if DB_VIEW_NO_FILE]
    Aucune prise en charge de la s�rialisation ne sera ajout�e.
[!else]
    Une prise en charge de la s�rialisation a �t� ajout�e.
[!endif]
[!endif]
[!if CONTAINER || FULL_SERVER || MINI_SERVER || CONTAINER_SERVER]
/////////////////////////////////////////////////////////////////////////////

AppWizard a �galement cr�� des classes sp�cifiques � OLE

[!if CONTAINER || CONTAINER_SERVER]
[!output CONTAINER_ITEM_HEADER], [!output CONTAINER_ITEM_IMPL]
    Ces fichiers contiennent votre classe [!output CONTAINER_ITEM_CLASS], qui est utilis�e pour 
    manipuler les objets OLE. Ces objets sont g�n�ralement affich�s par votre
    classe [!output VIEW_CLASS] et s�rialis�s dans votre classe [!output DOC_CLASS].
[!if ACTIVE_DOC_CONTAINER]
    Ce programme offre une prise en charge pour contenir des documents actifs dans son frame.
[!endif]
[!endif]
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]

[!output SERVER_ITEM_HEADER], [!output SERVER_ITEM_IMPL]
    Ces fichiers contiennent votre classe [!output SERVER_ITEM_CLASS], qui est utilis�e pour
    connecter votre classe [!output DOC_CLASS] au syst�me OLE et �ventuellement,
    fournir des liens vers votre document.
[!if ACTIVE_DOC_SERVER]
    Le projet offre une prise en charge pour la cr�ation et la gestion des documents actifs.
[!endif]

[!output INPLACE_FRAME_HEADER], [!output INPLACE_FRAME_IMPL]
    Ces fichiers contiennent votre classe [!output INPLACE_FRAME_CLASS], d�riv�e de
    COleIPFrameWnd. Cette classe contr�le toutes les fonctionnalit�s des frames lors de
    l'activation sur place.
[!endif]

[!if SUPPORT_COMPOUND_FILES]
    Le projet offre une prise en charge des fichiers compos�s. Le format de fichier compos� permet
    de stocker un document contenant un ou plusieurs objets Automation dans un seul fichier, tout
    en autorisant l'acc�s � chacun des objets de ce fichier.
[!endif]
[!endif]
[!else]

/////////////////////////////////////////////////////////////////////////////

[!if AUTOMATION]
AppWizard cr�e une classe de dialogue et une classe proxy Automation :
[!else]
AppWizard cr�e une classe de dialogue :
[!endif]

[!output DIALOG_HEADER], [!output DIALOG_IMPL] - la bo�te de dialogue
    Ces fichiers contiennent votre classe [!output DIALOG_CLASS], qui d�finit le
    comportement de la bo�te de dialogue principale de votre application. Le mod�le de bo�te de
    dialogue se trouve dans le fichier [!output PROJECT_NAME].rc, modifiable dans Microsoft Visual C++.
[!if AUTOMATION]

[!output DIALOG_AUTO_PROXY_HEADER], [!output DIALOG_AUTO_PROXY_IMPL] - l'objet Automation
    Ces fichiers contiennent votre classe [!output DIALOG_AUTO_PROXY_CLASS]. Celle-ci
    est appel�e classe "proxy Automation" pour votre bo�te de dialogue, car elle expose
    les m�thodes et propri�t�s Automation qui peuvent �tre utilis�es par les
    contr�leurs Automation pour acc�der � la bo�te de dialogue. Ces m�thodes et propri�t�s
    ne sont pas expos�es directement � partir de la classe de dialogue ; en effet, dans le cas
    d'une application MFC constitu�e de bo�tes de dialogue modales, il est plus clair et facile
    de s�parer l'objet Automation et l'interface utilisateur.
[!endif]
[!endif]

[!if CONTEXT_HELP]
/////////////////////////////////////////////////////////////////////////////

Prise en charge de l'aide :

[!if HELPSTYLE_HTML]
hlp\[!output PROJECT_NAME].hhp
    Ce fichier est un fichier projet d'aide. Il contient les donn�es n�cessaires
    � la compilation des fichiers d'aide en un fichier .chm.

hlp\[!output PROJECT_NAME].hhc
    Ce fichier affiche le contenu du fichier projet d'aide.

hlp\[!output PROJECT_NAME].hhk
    Ce fichier comporte un index des rubriques d'aide.

hlp\afxcore.htm
    Ce fichier contient les rubriques d'aide standard relatives aux commandes MFC
    et aux objets de l'�cran standard. Ajoutez-y vos propres rubriques d'aide.

[!if PRINTING]
hlp\afxprint.htm
    Ce fichier contient les rubriques d'aide relatives aux commandes d'impression.

[!endif]
makehtmlhelp.bat
    Ce fichier est utilis� par le syst�me de g�n�ration pour compiler les fichiers d'aide.

hlp\Images\*.gif
    Il s'agit des fichiers bitmap requis par les rubriques d'aide standard pour
    les commandes standard de la biblioth�que MFC (Microsoft Foundation Class).

[!else]
hlp\[!output PROJECT_NAME].hpj
    Ce fichier est le fichier projet d'aide utilis� par le compilateur d'aide pour cr�er
    le fichier d'aide sp�cifique � votre application.

hlp\*.bmp
    Il s'agit des fichiers bitmap requis par les rubriques d'aide standard pour
    les commandes standard de la biblioth�que MFC (Microsoft Foundation Class).

hlp\*.rtf
    Ces fichiers contiennent les rubriques d'aide standard relatives aux commandes MFC
    et objets de l'�cran standard.
[!endif]
[!endif]

[!if ACTIVEX_CONTROLS || PRINTING || SPLITTER || MAPI || SOCKETS]
/////////////////////////////////////////////////////////////////////////////

Autres fonctionnalit�s :
[!if ACTIVEX_CONTROLS]

Contr�les ActiveX
    L'application offre la prise en charge des contr�les ActiveX.
[!endif]
[!if PRINTING]

Prise en charge de l'aper�u avant impression et de l'impression
    AppWizard a g�n�r� le code requis pour g�rer les commandes Impression, Configuration de l'impression et
    Aper�u avant impression en appelant des fonctions membres de la classe CView � partir de la biblioth�que MFC.
[!endif]
[!if DB_SUPPORT_HEADER_ONLY && !APP_TYPE_DLG]

Prise en charge des bases de donn�es
    AppWizard a ajout� une prise en charge minimale des bases de donn�es pour votre programme.
    Seuls les fichiers strictement n�cessaires ont �t� inclus.
[!endif]
[!if SPLITTER && !APP_TYPE_DLG]

Fractionnement des fen�tres
    AppWizard a ajout� une prise en charge des fen�tres fractionn�es pour les documents de votre application.
[!endif]
[!if MAPI]

Prise en charge de MAPI
    Le projet g�n�r� contient le code requis pour cr�er, manipuler, transmettre et stocker
    des messages �lectroniques.
[!endif]
[!if SOCKETS]

Windows Sockets
    L'application offre une prise en charge permettant d'�tablir des communications via les r�seaux TCP/IP.
[!endif]

[!endif]
/////////////////////////////////////////////////////////////////////////////

Autres fichiers standard :

StdAfx.h, StdAfx.cpp
    Ces fichiers servent � g�n�rer un fichier d'en-t�te pr�compil� (PCH),
    appel� [!output PROJECT_NAME].pch, et un fichier de types pr�compil�s StdAfx.obj.

Resource.h
    Il s'agit du fichier d'en-t�te standard, qui d�finit les ID des nouvelles ressources.
    Ce fichier est lu et mis � jour par Microsoft Visual C++.

/////////////////////////////////////////////////////////////////////////////

Autres remarques :

AppWizard utilise "TODO:" pour vous signaler les parties du code source
que vous devez ajouter ou personnaliser.
[!if APP_TYPE_MDI || APP_TYPE_SDI || APP_TYPE_DLG || APP_TYPE_MTLD]

Si votre application utilise MFC dans une DLL partag�e et que la langue de cette
application n'est pas la m�me que celle utilis�e par le syst�me d'exploitation, vous
devez copier les ressources localis�es MFC70XXX.DLL correspondantes (situ�es sur le
CD-ROM Microsoft Visual C++ dans le r�pertoire Win\System) dans le r�pertoire system
ou system32 de votre ordinateur, puis renommer MFC70XXX.DLL en MFCLOC.DLL. ("XXX" est
l'abr�viation de la langue. Par exemple, MFC70DEU.DLL contient les ressources en allemand.)
Si vous ne copiez pas la version localis�e des ressources, certains �l�ments d'interface de
votre application seront affich�s dans la langue du syst�me d'exploitation.
[!endif]

/////////////////////////////////////////////////////////////////////////////
