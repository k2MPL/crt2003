================================================================================
    BIBLIOTECA DE MICROSOFT FOUNDATION CLASS: [!output PROJECT_NAME] Información general del proyecto
===============================================================================

El Asistente para aplicaciones ha creado esta [!output PROJECT_NAME] aplicación para usted. Esta 
aplicación no sólo muestra los conceptos básicos para utilizar Microsoft Foundation Classes,
sino que también es un punto de partida para escribir su aplicación.

Este archivo contiene un resumen de lo que encontrará en cada uno de los archivos que
componen su [!output PROJECT_NAME] aplicación.

[!output PROJECT_NAME].vcproj
    Este es el archivo de proyecto principal para proyectos de VC++ generados con un Asistente 
    para aplicaciones. Contiene información sobre la versión de Visual C++ que generó el archivo e 
    información acerca de las plataformas, las configuraciones y las características del proyecto
    seleccionadas con el Asistente para aplicaciones.

[!output APP_HEADER]
    Este es el archivo de encabezado principal para la aplicación. Incluye otros
    encabezados específicos del proyecto (incluyendo Resource.h) y declara la
    clase de la aplicación [!output APP_CLASS].

[!output APP_IMPL]
    Este es el archivo de código fuente principal de la aplicación que contiene la
    clase de la aplicación [!output APP_CLASS].

[!output PROJECT_NAME].rc
    Esta es una lista de todos los recursos de Microsoft Windows que utiliza
    el programa. Incluye los iconos, mapas de bits y cursores almacenados en el
    subdirectorio RES. Este archivo se puede editar directamente en Microsoft
    Visual C++. Los recursos del proyecto están en [!output LCID].

res\[!output SAFE_PROJECT_NAME].ico
    Este es un archivo de icono, que se utiliza como icono de la aplicación. El
    icono está incluido en el archivo de recursos principal [!output PROJECT_NAME].rc.

res\[!output SAFE_PROJECT_NAME].rc2
    Este archivo contiene recursos no editados por Microsoft 
    Visual C++. Debe ubicar todos los recursos no editables por
    el editor de recursos en este archivo.
[!if CONTAINER_SERVER || FULL_SERVER || MINI_SERVER || AUTOMATION || HAS_SUFFIX]
[!if !HTML_EDITVIEW]
[!output PROJECT_NAME].reg
    Este es un archivo .REG de ejemplo que muestra el tipo de configuración de
    registro que el marco de trabajo establecerá. Puede utilizarlo como archivo .REG
[!if APP_TYPE_DLG]
    para incluirlo con la aplicación.
[!else]
    para incluirlo con la aplicación o simplemente eliminarlo y basarse 
    en el registro RegisterShellFileTypes predeterminado.
[!endif]

[!if AUTOMATION]
[!output PROJECT_NAME].idl
    Este archivo contiene el código fuente del Lenguaje de descripción de interfaces
    para la biblioteca de tipos de la aplicación.
[!endif]
[!endif]
[!endif]

[!if !APP_TYPE_DLG]
/////////////////////////////////////////////////////////////////////////////

Para la ventana de marco principal:
[!if PROJECT_STYLE_EXPLORER]
    Estilo Explorador de Windows: el proyecto incluirá una interfaz de tipo Explorador
    de Windows con dos marcos.
[!else]
    El proyecto incluye una interfaz de MFC estándar.
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
    Este archivo de mapa de bits se utiliza para crear imágenes en mosaico para la barra de herramientas.
    La barra de herramientas y la barra de estado iniciales se construyen en la clase [!output MAIN_FRAME_CLASS].
    Edite el mapa de bits de esta barra de herramientas con el editor de recursos y
    actualice la matriz IDR_MAINFRAME TOOLBAR en [!output PROJECT_NAME].rc para agregar
    botones de la barra de herramientas.
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]

res\IToolbar.bmp
    Este archivo de mapa de bits se utiliza para crear imágenes en mosaico para la barra de herramientas
    cuando la aplicación del servidor está activada en el contexto dentro de otro
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
    admite ventanas secundarias en una aplicación MDI.

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
    El documento tendrá las siguientes cadenas:
        Extensión del archivo:      [!output FILE_EXTENSION]
        Id. de tipo de archivo:        [!output FILE_TYPE_ID]
        Título de marco principal:  [!output MAIN_FRAME_CAPTION]
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
    No se agregará compatibilidad con la serialización.
[!else]
    Se agregó compatibilidad con la serialización.
[!endif]
[!endif]
[!if CONTAINER || FULL_SERVER || MINI_SERVER || CONTAINER_SERVER]
/////////////////////////////////////////////////////////////////////////////

El Asistente para aplicaciones también creó clases específicas para OLE

[!if CONTAINER || CONTAINER_SERVER]
[!output CONTAINER_ITEM_HEADER], [!output CONTAINER_ITEM_IMPL]
    Estos archivos contienen la clase [!output CONTAINER_ITEM_CLASS]. Esta clase se utiliza para
    manipular objetos OLE. Los objetos OLE los muestra normalmente la clase
    [!output VIEW_CLASS] y se serializan como parte de la clase [!output DOC_CLASS].
[!if ACTIVE_DOC_CONTAINER]
    El programa admite la inclusión de documentos activos en el marco.
[!endif]
[!endif]
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]

[!output SERVER_ITEM_HEADER], [!output SERVER_ITEM_IMPL]
    Estos archivos contienen la clase [!output SERVER_ITEM_CLASS]. Esta clase se utiliza para
    conectar la clase [!output DOC_CLASS] al sistema OLE y, de manera opcional,
    para proporcionar vínculos a su documento.
[!if ACTIVE_DOC_SERVER]
    El proyecto admite la creación y administración de documentos activos.
[!endif]

[!output INPLACE_FRAME_HEADER], [!output INPLACE_FRAME_IMPL]
    Estos archivos contienen la clase [!output INPLACE_FRAME_CLASS]. Esta clase se deriva
    de COleIPFrameWnd y controla todas las funciones de marco durante la activación en el contexto.
[!endif]

[!if SUPPORT_COMPOUND_FILES]
    El proyecto admite los archivos compuestos. El formato de archivo compuesto almacena en un archivo
    un documento que contiene uno o varios objetos de automatización y sigue permitiendo el acceso
    al mismo a los objetos individuales.
[!endif]
[!endif]
[!else]

/////////////////////////////////////////////////////////////////////////////

[!if AUTOMATION]
El Asistente para aplicaciones crea una clase de diálogo y una clase de proxy de automatización:
[!else]
El Asistente para aplicaciones crea una clase de diálogo:
[!endif]

[!output DIALOG_HEADER], [!output DIALOG_IMPL] - cuadro de diálogo
    Estos archivos contienen la clase [!output DIALOG_CLASS]. Esta clase define
    el comportamiento del cuadro de diálogo principal de la aplicación. La plantilla del cuadro
    de diálogo está en [!output PROJECT_NAME].rc, que se puede editar en Microsoft Visual C++.
[!if AUTOMATION]

[!output DIALOG_AUTO_PROXY_HEADER], [!output DIALOG_AUTO_PROXY_IMPL] - objeto de automatización
    Estos archivos contienen la clase [!output DIALOG_AUTO_PROXY_CLASS]. Esta clase
    se denomina clase de "proxy de automatización" para el cuadro de diálogo, porque
    se ocupa de exponer los métodos de automatización y las propiedades que 
    los controladores de automatización pueden utilizar para obtener acceso al cuadro de diálogo. Estos
    métodos y propiedades no se exponen directamente desde la clase de diálogo porque,
    en el caso de una aplicación MFC basada en cuadros de diálogo modales, es más limpio y
    más sencillo mantener el objeto de automatización separado de la interfaz de usuario.
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
    Este archivo contiene un índice de los temas de ayuda.

hlp\afxcore.htm
    Este archivo contiene los temas de ayuda estándar para los objetos de pantalla
    y los comandos MFC estándar. Agregue sus propios temas de ayuda a este archivo.

[!if PRINTING]
hlp\afxprint.htm
    Este archivo contiene los temas de ayuda para los comandos de impresión.

[!endif]
makehtmlhelp.bat
    Este archivo lo utiliza el sistema de compilación para compilar los archivos de ayuda.

hlp\Images\*.gif
    Estos son archivos de mapas de bits requeridos por los temas de los archivos de ayuda estándar
    para los comandos estándar de la biblioteca de Microsoft Foundation Class.

[!else]
hlp\[!output PROJECT_NAME].hpj
    Este archivo es el archivo de proyecto de ayuda utilizado por el compilador de Ayuda para crear
    el archivo de ayuda de la aplicación.

hlp\*.bmp
    Estos son archivos de mapas de bits requeridos por los temas de los archivos de ayuda estándar
    para los comandos estándar de la biblioteca de Microsoft Foundation Class.

hlp\*.rtf
    Estos archivos contienen los temas de ayuda estándar para los objetos de pantalla y
    los comandos MFC estándar.
[!endif]
[!endif]

[!if ACTIVEX_CONTROLS || PRINTING || SPLITTER || MAPI || SOCKETS]
/////////////////////////////////////////////////////////////////////////////

Otras características:
[!if ACTIVEX_CONTROLS]

Controles ActiveX
    La aplicación admite el uso de los controles ActiveX.
[!endif]
[!if PRINTING]

Compatibilidad para impresión y vista preliminar
    El Asistente para aplicaciones generó el código para controlar los comandos de impresión, de configuración
    de impresión y de vista preliminar llamando a las funciones miembro en la clase CView desde la biblioteca MFC.
[!endif]
[!if DB_SUPPORT_HEADER_ONLY && !APP_TYPE_DLG]

Compatibilidad con bases de datos
    El Asistente para aplicaciones agregó el nivel básico de compatibilidad con bases de datos para el programa. 
    Sólo se han incluido los archivos necesarios.
[!endif]
[!if SPLITTER && !APP_TYPE_DLG]

Ventana de división
    El Asistente para aplicaciones agregó compatibilidad para las ventanas divisoras en los documentos de la aplicación.
[!endif]
[!if MAPI]

Compatibilidad con MAPI
    El proyecto generado contiene el código necesario para crear, manipular, transferir y
    almacenar mensajes de correo.
[!endif]
[!if SOCKETS]

Windows Sockets
    La aplicación admite el establecimiento de comunicaciones en redes TCP/IP.
[!endif]

[!endif]
/////////////////////////////////////////////////////////////////////////////
Otros archivos estándar:

StdAfx.h, StdAfx.cpp
    Estos archivos se utilizan para compilar un archivo de encabezado precompilado (PCH)
    denominado [!output PROJECT_NAME].pch y un archivo de tipos precompilados denominado StdAfx.obj.

Resource.h
    Este es el archivo de encabezado estándar, que define nuevos identificadores de recursos.
    Microsoft Visual C++ lee y actualiza este archivo.

/////////////////////////////////////////////////////////////////////////////

Otras notas:

El Asistente para aplicaciones utiliza "ToDo:" para indicar las partes del código fuente que
debe agregar o personalizar.
[!if APP_TYPE_MDI || APP_TYPE_SDI || APP_TYPE_DLG || APP_TYPE_MTLD]

Si su aplicación utiliza MFC en un archivo DLL compartido y la aplicación está en un
idioma distinto al idioma actual del sistema operativo, será necesario copiar 
los recursos MFC70XXX.DLL localizados correspondientes del CD-ROM de Microsoft
Visual C++ bajo el directorio Win\System en el directorio del sistema o 
system32 de su equipo y cambiar el nombre a MFCLOC.DLL. ("XXX" corresponde a la 
abreviatura del idioma. Por ejemplo, MFC70DEU.DLL contiene recursos traducidos
al alemán.) Si no realiza esta operación, algunos de los elementos de la interfaz de usuario de
su aplicación permanecerán en el idioma del sistema operativo.
[!endif]

/////////////////////////////////////////////////////////////////////////////
