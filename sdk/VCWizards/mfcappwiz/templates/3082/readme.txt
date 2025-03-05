================================================================================
    BIBLIOTECA DE MICROSOFT FOUNDATION CLASS: [!output PROJECT_NAME] Informaci�n general del proyecto
===============================================================================

El Asistente para aplicaciones ha creado esta [!output PROJECT_NAME] aplicaci�n para usted. Esta 
aplicaci�n no s�lo muestra los conceptos b�sicos para utilizar Microsoft Foundation Classes,
sino que tambi�n es un punto de partida para escribir su aplicaci�n.

Este archivo contiene un resumen de lo que encontrar� en cada uno de los archivos que
componen su [!output PROJECT_NAME] aplicaci�n.

[!output PROJECT_NAME].vcproj
    Este es el archivo de proyecto principal para proyectos de VC++ generados con un Asistente 
    para aplicaciones. Contiene informaci�n sobre la versi�n de Visual C++ que gener� el archivo e 
    informaci�n acerca de las plataformas, las configuraciones y las caracter�sticas del proyecto
    seleccionadas con el Asistente para aplicaciones.

[!output APP_HEADER]
    Este es el archivo de encabezado principal para la aplicaci�n. Incluye otros
    encabezados espec�ficos del proyecto (incluyendo Resource.h) y declara la
    clase de la aplicaci�n [!output APP_CLASS].

[!output APP_IMPL]
    Este es el archivo de c�digo fuente principal de la aplicaci�n que contiene la
    clase de la aplicaci�n [!output APP_CLASS].

[!output PROJECT_NAME].rc
    Esta es una lista de todos los recursos de Microsoft Windows que utiliza
    el programa. Incluye los iconos, mapas de bits y cursores almacenados en el
    subdirectorio RES. Este archivo se puede editar directamente en Microsoft
    Visual C++. Los recursos del proyecto est�n en [!output LCID].

res\[!output SAFE_PROJECT_NAME].ico
    Este es un archivo de icono, que se utiliza como icono de la aplicaci�n. El
    icono est� incluido en el archivo de recursos principal [!output PROJECT_NAME].rc.

res\[!output SAFE_PROJECT_NAME].rc2
    Este archivo contiene recursos no editados por Microsoft 
    Visual C++. Debe ubicar todos los recursos no editables por
    el editor de recursos en este archivo.
[!if CONTAINER_SERVER || FULL_SERVER || MINI_SERVER || AUTOMATION || HAS_SUFFIX]
[!if !HTML_EDITVIEW]
[!output PROJECT_NAME].reg
    Este es un archivo .REG de ejemplo que muestra el tipo de configuraci�n de
    registro que el marco de trabajo establecer�. Puede utilizarlo como archivo .REG
[!if APP_TYPE_DLG]
    para incluirlo con la aplicaci�n.
[!else]
    para incluirlo con la aplicaci�n o simplemente eliminarlo y basarse 
    en el registro RegisterShellFileTypes predeterminado.
[!endif]

[!if AUTOMATION]
[!output PROJECT_NAME].idl
    Este archivo contiene el c�digo fuente del Lenguaje de descripci�n de interfaces
    para la biblioteca de tipos de la aplicaci�n.
[!endif]
[!endif]
[!endif]

[!if !APP_TYPE_DLG]
/////////////////////////////////////////////////////////////////////////////

Para la ventana de marco principal:
[!if PROJECT_STYLE_EXPLORER]
    Estilo Explorador de Windows: el proyecto incluir� una interfaz de tipo Explorador
    de Windows con dos marcos.
[!else]
    El proyecto incluye una interfaz de MFC est�ndar.
[!endif]

[!output MAIN_FRAME_HEADER], [!output MAIN_FRAME_IMPL]
    Estos archivos contienen la clase de marco [!output MAIN_FRAME_CLASS], que deriva de
[!if APP_TYPE_MDI]
    CMDIFrameWnd y controla todas las funciones de marco MDI.
[!else]
    CFrameWnd y controla todas las funciones de marco SDI.
[!endif]
[!if PROJECT_STYLE_EXPLORER]

[!output TREE_VIEW_HEADER], [!output TREE_VIEW_IMPL]
    Estos archivos contienen la clase de marco a la izquierda [!output TREE_VIEW_CLASS], que deriva de
    CTreeView.
[!endif]

[!if DOCKING_TOOLBAR]
res\Toolbar.bmp
    Este archivo de mapa de bits se utiliza para crear im�genes en mosaico para la barra de herramientas.
    La barra de herramientas y la barra de estado iniciales se construyen en la clase [!output MAIN_FRAME_CLASS].
    Edite el mapa de bits de esta barra de herramientas con el editor de recursos y
    actualice la matriz IDR_MAINFRAME TOOLBAR en [!output PROJECT_NAME].rc para agregar
    botones de la barra de herramientas.
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]

res\IToolbar.bmp
    Este archivo de mapa de bits se utiliza para crear im�genes en mosaico para la barra de herramientas
    cuando la aplicaci�n del servidor est� activada en el contexto dentro de otro
    contenedor. Esta barra de herramientas se construye en la clase [!output INPLACE_FRAME_CLASS].
    Este mapa de bits es similar al mapa de bits en res\Toolbar.bmp, con la 
    diferencia de que se han quitado muchos comandos que no son del servidor.

[!endif]
[!endif]
[!if APP_TYPE_MDI]
/////////////////////////////////////////////////////////////////////////////

Para la ventana de marco secundaria:

ChildFrm.h, ChildFrm.cpp
    Estos archivos definen e implementan la clase [!output CHILD_FRAME_CLASS], que
    admite ventanas secundarias en una aplicaci�n MDI.

[!endif]
/////////////////////////////////////////////////////////////////////////////

[!if DOCVIEW]
[!if !DB_VIEW_NO_FILE]
El Asistente para aplicaciones crea un tipo de documento y una vista:

[!output DOC_HEADER], [!output DOC_IMPL] - documento
    Estos archivos contienen la clase [!output DOC_CLASS]. Edite estos archivos para
    agregar sus datos de documentos especiales e implementar la carga y guardado de archivos
    (via [!output DOC_CLASS]::Serialize).
[!if HAS_SUFFIX && !HTML_EDITVIEW]
    El documento tendr� las siguientes cadenas:
        Extensi�n del archivo:      [!output FILE_EXTENSION]
        Id. de tipo de archivo:        [!output FILE_TYPE_ID]
        T�tulo de marco principal:  [!output MAIN_FRAME_CAPTION]
        Nombre de tipo de documento:       [!output SAFE_DOC_TYPE_NAME]
        Nombre de filtro:         [!output FILTER_NAME]
        Nuevo nombre corto de archivo: [!output FILE_NEW_NAME_SHORT]
        Nombre largo de tipo de archivo: [!output FILE_NEW_NAME_LONG]
[!endif]
[!else]
El Asistente para aplicaciones crea una vista:
[!endif]

[!output VIEW_HEADER], [!output VIEW_IMPL] - vista del documento
    Estos archivos contienen la clase [!output VIEW_CLASS].
[!if !DB_VIEW_NO_FILE]
    Los objetos [!output VIEW_CLASS] se utilizan para ver objetos [!output DOC_CLASS].
[!endif]

[!if APP_TYPE_MDI]
res\[!output SAFE_PROJECT_NAME]Doc.ico
    Este es un archivo de icono, que se utiliza como icono para las ventanas secundarias MDI
    en la clase [!output DOC_CLASS]. Este icono lo incluye el archivo de 
    recursos principal [!output PROJECT_NAME].rc.
[!endif]

[!endif]

[!if DB_VIEW_NO_FILE || DB_VIEW_WITH_FILE]
/////////////////////////////////////////////////////////////////////////////

Compatibilidad con bases de datos:

[!output ROWSET_HEADER], [!output ROWSET_IMPL]
    Estos archivos contienen la clase [!output ROWSET_CLASS]. Esta clase se utiliza para obtener acceso
    al origen de datos seleccionado en el asistente.
[!if DB_VIEW_NO_FILE]
    No se agregar� compatibilidad con la serializaci�n.
[!else]
    Se agreg� compatibilidad con la serializaci�n.
[!endif]
[!endif]
[!if CONTAINER || FULL_SERVER || MINI_SERVER || CONTAINER_SERVER]
/////////////////////////////////////////////////////////////////////////////

El Asistente para aplicaciones tambi�n cre� clases espec�ficas para OLE

[!if CONTAINER || CONTAINER_SERVER]
[!output CONTAINER_ITEM_HEADER], [!output CONTAINER_ITEM_IMPL]
    Estos archivos contienen la clase [!output CONTAINER_ITEM_CLASS]. Esta clase se utiliza para
    manipular objetos OLE. Los objetos OLE los muestra normalmente la clase
    [!output VIEW_CLASS] y se serializan como parte de la clase [!output DOC_CLASS].
[!if ACTIVE_DOC_CONTAINER]
    El programa admite la inclusi�n de documentos activos en el marco.
[!endif]
[!endif]
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]

[!output SERVER_ITEM_HEADER], [!output SERVER_ITEM_IMPL]
    Estos archivos contienen la clase [!output SERVER_ITEM_CLASS]. Esta clase se utiliza para
    conectar la clase [!output DOC_CLASS] al sistema OLE y, de manera opcional,
    para proporcionar v�nculos a su documento.
[!if ACTIVE_DOC_SERVER]
    El proyecto admite la creaci�n y administraci�n de documentos activos.
[!endif]

[!output INPLACE_FRAME_HEADER], [!output INPLACE_FRAME_IMPL]
    Estos archivos contienen la clase [!output INPLACE_FRAME_CLASS]. Esta clase se deriva
    de COleIPFrameWnd y controla todas las funciones de marco durante la activaci�n en el contexto.
[!endif]

[!if SUPPORT_COMPOUND_FILES]
    El proyecto admite los archivos compuestos. El formato de archivo compuesto almacena en un archivo
    un documento que contiene uno o varios objetos de automatizaci�n y sigue permitiendo el acceso
    al mismo a los objetos individuales.
[!endif]
[!endif]
[!else]

/////////////////////////////////////////////////////////////////////////////

[!if AUTOMATION]
El Asistente para aplicaciones crea una clase de di�logo y una clase de proxy de automatizaci�n:
[!else]
El Asistente para aplicaciones crea una clase de di�logo:
[!endif]

[!output DIALOG_HEADER], [!output DIALOG_IMPL] - cuadro de di�logo
    Estos archivos contienen la clase [!output DIALOG_CLASS]. Esta clase define
    el comportamiento del cuadro de di�logo principal de la aplicaci�n. La plantilla del cuadro
    de di�logo est� en [!output PROJECT_NAME].rc, que se puede editar en Microsoft Visual C++.
[!if AUTOMATION]

[!output DIALOG_AUTO_PROXY_HEADER], [!output DIALOG_AUTO_PROXY_IMPL] - objeto de automatizaci�n
    Estos archivos contienen la clase [!output DIALOG_AUTO_PROXY_CLASS]. Esta clase
    se denomina clase de "proxy de automatizaci�n" para el cuadro de di�logo, porque
    se ocupa de exponer los m�todos de automatizaci�n y las propiedades que 
    los controladores de automatizaci�n pueden utilizar para obtener acceso al cuadro de di�logo. Estos
    m�todos y propiedades no se exponen directamente desde la clase de di�logo porque,
    en el caso de una aplicaci�n MFC basada en cuadros de di�logo modales, es m�s limpio y
    m�s sencillo mantener el objeto de automatizaci�n separado de la interfaz de usuario.
[!endif]
[!endif]

[!if CONTEXT_HELP]
/////////////////////////////////////////////////////////////////////////////

Compatibilidad de la ayuda:

[!if HELPSTYLE_HTML]
hlp\[!output PROJECT_NAME].hhp
    Este archivo es un archivo de proyecto de ayuda. Contiene los datos necesarios
    para compilar los archivos de ayuda en un archivo .chm.

hlp\[!output PROJECT_NAME].hhc
    Este archivo enumera el contenido del proyecto de ayuda.

hlp\[!output PROJECT_NAME].hhk
    Este archivo contiene un �ndice de los temas de ayuda.

hlp\afxcore.htm
    Este archivo contiene los temas de ayuda est�ndar para los objetos de pantalla
    y los comandos MFC est�ndar. Agregue sus propios temas de ayuda a este archivo.

[!if PRINTING]
hlp\afxprint.htm
    Este archivo contiene los temas de ayuda para los comandos de impresi�n.

[!endif]
makehtmlhelp.bat
    Este archivo lo utiliza el sistema de compilaci�n para compilar los archivos de ayuda.

hlp\Images\*.gif
    Estos son archivos de mapas de bits requeridos por los temas de los archivos de ayuda est�ndar
    para los comandos est�ndar de la biblioteca de Microsoft Foundation Class.

[!else]
hlp\[!output PROJECT_NAME].hpj
    Este archivo es el archivo de proyecto de ayuda utilizado por el compilador de Ayuda para crear
    el archivo de ayuda de la aplicaci�n.

hlp\*.bmp
    Estos son archivos de mapas de bits requeridos por los temas de los archivos de ayuda est�ndar
    para los comandos est�ndar de la biblioteca de Microsoft Foundation Class.

hlp\*.rtf
    Estos archivos contienen los temas de ayuda est�ndar para los objetos de pantalla y
    los comandos MFC est�ndar.
[!endif]
[!endif]

[!if ACTIVEX_CONTROLS || PRINTING || SPLITTER || MAPI || SOCKETS]
/////////////////////////////////////////////////////////////////////////////

Otras caracter�sticas:
[!if ACTIVEX_CONTROLS]

Controles ActiveX
    La aplicaci�n admite el uso de los controles ActiveX.
[!endif]
[!if PRINTING]

Compatibilidad para impresi�n y vista preliminar
    El Asistente para aplicaciones gener� el c�digo para controlar los comandos de impresi�n, de configuraci�n
    de impresi�n y de vista preliminar llamando a las funciones miembro en la clase CView desde la biblioteca MFC.
[!endif]
[!if DB_SUPPORT_HEADER_ONLY && !APP_TYPE_DLG]

Compatibilidad con bases de datos
    El Asistente para aplicaciones agreg� el nivel b�sico de compatibilidad con bases de datos para el programa. 
    S�lo se han incluido los archivos necesarios.
[!endif]
[!if SPLITTER && !APP_TYPE_DLG]

Ventana de divisi�n
    El Asistente para aplicaciones agreg� compatibilidad para las ventanas divisoras en los documentos de la aplicaci�n.
[!endif]
[!if MAPI]

Compatibilidad con MAPI
    El proyecto generado contiene el c�digo necesario para crear, manipular, transferir y
    almacenar mensajes de correo.
[!endif]
[!if SOCKETS]

Windows Sockets
    La aplicaci�n admite el establecimiento de comunicaciones en redes TCP/IP.
[!endif]

[!endif]
/////////////////////////////////////////////////////////////////////////////
Otros archivos est�ndar:

StdAfx.h, StdAfx.cpp
    Estos archivos se utilizan para compilar un archivo de encabezado precompilado (PCH)
    denominado [!output PROJECT_NAME].pch y un archivo de tipos precompilados denominado StdAfx.obj.

Resource.h
    Este es el archivo de encabezado est�ndar, que define nuevos identificadores de recursos.
    Microsoft Visual C++ lee y actualiza este archivo.

/////////////////////////////////////////////////////////////////////////////

Otras notas:

El Asistente para aplicaciones utiliza "ToDo:" para indicar las partes del c�digo fuente que
debe agregar o personalizar.
[!if APP_TYPE_MDI || APP_TYPE_SDI || APP_TYPE_DLG || APP_TYPE_MTLD]

Si su aplicaci�n utiliza MFC en un archivo DLL compartido y la aplicaci�n est� en un
idioma distinto al idioma actual del sistema operativo, ser� necesario copiar 
los recursos MFC70XXX.DLL localizados correspondientes del CD-ROM de Microsoft
Visual C++ bajo el directorio Win\System en el directorio del sistema o 
system32 de su equipo y cambiar el nombre a MFCLOC.DLL. ("XXX" corresponde a la 
abreviatura del idioma. Por ejemplo, MFC70DEU.DLL contiene recursos traducidos
al alem�n.) Si no realiza esta operaci�n, algunos de los elementos de la interfaz de usuario de
su aplicaci�n permanecer�n en el idioma del sistema operativo.
[!endif]

/////////////////////////////////////////////////////////////////////////////
