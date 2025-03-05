================================================================================
    MICROSOFT 基础类库： [!output PROJECT_NAME] 项目概述
===============================================================================

应用程序向导已为您创建了此 [!output PROJECT_NAME] 应用程序。此应用程序
不仅介绍了使用 Microsoft 基础类的基本知识，
而且是编写应用程序的起点。

此文件包含组成 [!output PROJECT_NAME] 应用程序的每个文件的内容摘要。

[!output PROJECT_NAME].vcproj
    这是使用“应用程序向导”生成的 VC++ 项目的主项目文件。 
    它包含有关生成文件的 Visual C++ 版本的信息，以及
    有关用“应用程序向导”所选择的平台、配置和
    项目功能的信息。

[!output APP_HEADER]
    这是应用程序的主头文件。  它包含其他
    项目特定的头文件（包括 Resource.h），并声明
    [!output APP_CLASS] 应用程序类。

[!output APP_IMPL]
    这是包含应用程序
    类 [!output APP_CLASS] 的主应用程序源文件。

[!output PROJECT_NAME].rc
    这是程序使用的所有 Microsoft Windows 资源
    的列表。  它包含存储在 RES 子目录中
    的图标、位图和光标。  可直接在 Microsoft 
    Visual C++ 中编辑此文件。 项目资源包含在 [!output LCID] 中。

res\[!output SAFE_PROJECT_NAME].ico
    这是一个图标文件，用作应用程序的图标。  此
    图标包含在主资源文件 [!output PROJECT_NAME].rc 中。

res\[!output SAFE_PROJECT_NAME].rc2
    此文件包含不由 Microsoft 
    Visual C++ 编辑的资源。 应将所有不能由
    资源编辑器编辑的资源放在此文件中。
[!if CONTAINER_SERVER || FULL_SERVER || MINI_SERVER || AUTOMATION || HAS_SUFFIX]
[!if !HTML_EDITVIEW]
[!output PROJECT_NAME].reg
    这是一个 .REG 文件示例，向您显示
    框架将为您设置的注册设置类型。  可以将它用作 .REG
[!if APP_TYPE_DLG]
    文件，以与应用程序一起使用。
[!else]
    文件，以与应用程序一起使用，或干脆删除它而依赖
    默认的 RegisterShellFileTypes 注册。
[!endif]

[!if AUTOMATION]
[!output PROJECT_NAME].idl
    此文件包含应用程序类型库的
    “接口描述语言”源代码。
[!endif]
[!endif]
[!endif]

[!if !APP_TYPE_DLG]
/////////////////////////////////////////////////////////////////////////////

对于主框架窗口：
[!if PROJECT_STYLE_EXPLORER]
    Windows 资源管理器样式： 项目将包含类似 Windows 资源管理器的
    界面，其中包含两个框架。
[!else]
    项目将包含标准的 MFC 界面。
[!endif]

[!output MAIN_FRAME_HEADER], [!output MAIN_FRAME_IMPL]
    这些文件包含框架类 [!output MAIN_FRAME_CLASS]，该类派生自
[!if APP_TYPE_MDI]
    CMDIFrameWnd 并控制所有的 MDI 框架功能。
[!else]
    CFrameWnd 并控制所有的 SDI 框架功能。
[!endif]
[!if PROJECT_STYLE_EXPLORER]

[!output TREE_VIEW_HEADER]、[!output TREE_VIEW_IMPL]
    这些文件包含左框架类 [!output TREE_VIEW_CLASS]，此类派生自
    CTreeView。
[!endif]

[!if DOCKING_TOOLBAR]
res\Toolbar.bmp
    此位图文件用于创建工具栏的平铺图像。
    初始工具栏和状态栏在 [!output MAIN_FRAME_CLASS] 
    类中构造。 使用资源编辑器编辑此工具栏位图，并
    更新 [!output PROJECT_NAME].rc 中的 IDR_MAINFRAME TOOLBAR 数组以添加
    工具栏按钮。
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]

res\IToolbar.bmp
    此位图文件的用途在于：在其他容器内就地激活服务器应用程序后，
    创建工具栏的平铺图像
    。 此工具栏在 [!output INPLACE_FRAME_CLASS] 
    类中构造。 此位图类似于 res\Toolbar.bmp 
    中的位图，不同的是它移除了许多非服务器命令。

[!endif]
[!endif]
[!if APP_TYPE_MDI]
/////////////////////////////////////////////////////////////////////////////

对于子框架窗口：

ChildFrm.h、ChildFrm.cpp
    这些文件定义和实现 [!output CHILD_FRAME_CLASS] 类，此类
    支持 MDI 应用程序中的子窗口。

[!endif]
/////////////////////////////////////////////////////////////////////////////

[!if DOCVIEW]
[!if !DB_VIEW_NO_FILE]
应用程序向导将创建一种文档类型和一个视图：

[!output DOC_HEADER]、[!output DOC_IMPL] - 文档
    这些文件包含 [!output DOC_CLASS] 类。  编辑这些文件
    以添加特殊的文档数据并实现文件的保存和加载
    （通过 [!output DOC_CLASS]::Serialize）。
[!if HAS_SUFFIX && !HTML_EDITVIEW]
    此文档将具有下列字符串：
        文件扩展名：      [!output FILE_EXTENSION]
        文件类型 ID：        [!output FILE_TYPE_ID]
        主框架标题：  [!output MAIN_FRAME_CAPTION]
        文档类型名称：       [!output SAFE_DOC_TYPE_NAME]
        筛选器名称：         [!output FILTER_NAME]
        文件的新简称： [!output FILE_NEW_NAME_SHORT]
        文件类型全称： [!output FILE_NEW_NAME_LONG]
[!endif]
[!else]
应用程序向导创建一个视图：
[!endif]

[!output VIEW_HEADER]、[!output VIEW_IMPL] - 文档视图
    这些文件包含 [!output VIEW_CLASS] 类。
[!if !DB_VIEW_NO_FILE]
    [!output VIEW_CLASS] 对象用于查看 [!output DOC_CLASS] 对象。
[!endif]

[!if APP_TYPE_MDI]
res\[!output SAFE_PROJECT_NAME]Doc.ico
    这是一个图标文件，用作 
    [!output DOC_CLASS] 类 MDI 子窗口的图标。  此图标包含在主
    资源文件 [!output PROJECT_NAME].rc 中。
[!endif]

[!endif]

[!if DB_VIEW_NO_FILE || DB_VIEW_WITH_FILE]
/////////////////////////////////////////////////////////////////////////////

数据库支持：

[!output ROWSET_HEADER]、[!output ROWSET_IMPL]
    这些文件包含 [!output ROWSET_CLASS] 类。  此类用于访问
    在向导中选择的数据源。
[!if DB_VIEW_NO_FILE]
    将不添加任何序列化支持。
[!else]
    已添加序列化支持。
[!endif]
[!endif]
[!if CONTAINER || FULL_SERVER || MINI_SERVER || CONTAINER_SERVER]
/////////////////////////////////////////////////////////////////////////////

应用程序向导还创建了特定于 OLE 的类

[!if CONTAINER || CONTAINER_SERVER]
[!output CONTAINER_ITEM_HEADER]、[!output CONTAINER_ITEM_IMPL]
    这些文件包含 [!output CONTAINER_ITEM_CLASS] 类。 此类用于
    操作 OLE 对象。  OLE 对象通常由 
    [!output VIEW_CLASS] 类显示并序列化为 [!output DOC_CLASS] 类的一部分。
[!if ACTIVE_DOC_CONTAINER]
    程序支持将活动文档包含在其框架内。
[!endif]
[!endif]
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]

[!output SERVER_ITEM_HEADER]、[!output SERVER_ITEM_IMPL]
    这些文件包含 [!output SERVER_ITEM_CLASS]。 此类用于
    将 [!output DOC_CLASS] 类连接到 OLE 系统，
    还可用于提供到文档的链接。
[!if ACTIVE_DOC_SERVER]
    项目支持创建和管理活动文档。
[!endif]

[!output INPLACE_FRAME_HEADER]、[!output INPLACE_FRAME_IMPL]
    这些文件包含 [!output INPLACE_FRAME_CLASS]。 此类派生自 
    COleIPFrameWnd 并在就地激活过程中控制所有的框架功能。
[!endif]

[!if SUPPORT_COMPOUND_FILES]
    项目支持复合文件。 复合文件格式将
    包含一个或多个自动化对象的文档存储为一个文件，并且仍允许访问
    该文件中的各个对象。
[!endif]
[!endif]
[!else]

/////////////////////////////////////////////////////////////////////////////

[!if AUTOMATION]
应用程序向导将创建一个对话框类和自动化代理类：
[!else]
应用程序向导将创建一个对话框类：
[!endif]

[!output DIALOG_HEADER]、[!output DIALOG_IMPL] - 对话框
    这些文件包含 [!output DIALOG_CLASS] 类。  此类定义
    应用程序主对话框的行为。  此对话框的模板包含在 
    [!output PROJECT_NAME].rc 中，而此文件可以在 Microsoft Visual C++ 中进行编辑。
[!if AUTOMATION]

[!output DIALOG_AUTO_PROXY_HEADER]、[!output DIALOG_AUTO_PROXY_IMPL] - 自动化对象
    这些文件包含 [!output DIALOG_AUTO_PROXY_CLASS] 类。  此类称为对话框的
    “自动化代理”类，因为它
    负责公开自动化控制器可用来访问对话框的
    自动化方法和属性。  这些方法
    和属性不直接从对话框类公开，因为
    在基于有模式对话框的 MFC 应用程序中，这样可以更清楚和更容易地
    使自动化对象与用户界面分开。
[!endif]
[!endif]

[!if CONTEXT_HELP]
/////////////////////////////////////////////////////////////////////////////

帮助支持：

[!if HELPSTYLE_HTML]
hlp\[!output PROJECT_NAME].hhp
    此文件是帮助项目文件。 它包含将帮助文件编译为 
    .chm 文件所需的数据。

hlp\[!output PROJECT_NAME].hhc
    此文件列出帮助项目的内容。

hlp\[!output PROJECT_NAME].hhk
    此文件包含帮助主题的索引。

hlp\afxcore.htm
    此文件包含标准 MFC 
    命令和屏幕对象的标准帮助主题。 将您自己的帮助主题添加到此文件中。

[!if PRINTING]
hlp\afxprint.htm
    此文件包含关于打印命令的帮助主题。

[!endif]
makehtmlhelp.bat
    此文件由生成系统用来编译帮助文件。

hlp\Images\*.gif
    这些是 Microsoft 基础类库标准命令的标准帮助文件主题
    所需的位图文件。

[!else]
hlp\[!output PROJECT_NAME].hpj
    此文件是帮助编译器用来创建
    应用程序的帮助文件的帮助项目文件。

hlp\*.bmp
    这些是 Microsoft 基础类库标准命令的标准帮助文件主题
    所需的位图文件。

hlp\*.rtf
    这些文件包含标准 MFC 
    命令和屏幕对象的标准帮助主题。
[!endif]
[!endif]

[!if ACTIVEX_CONTROLS || PRINTING || SPLITTER || MAPI || SOCKETS]
/////////////////////////////////////////////////////////////////////////////

其他功能：
[!if ACTIVEX_CONTROLS]

ActiveX 控件
    应用程序支持使用 ActiveX 控件。
[!endif]
[!if PRINTING]

打印支持和打印预览支持
    应用程序向导已生成了一些代码，通过从 MFC 库调用 CView 类中的成员函数来
    处理打印、打印设置和打印预览命令。
[!endif]
[!if DB_SUPPORT_HEADER_ONLY && !APP_TYPE_DLG]

数据库支持
    应用程序向导添加了对程序的基本数据库支持。 只包含了
    所需的文件。
[!endif]
[!if SPLITTER && !APP_TYPE_DLG]

拆分窗口
    应用程序向导添加了对应用程序文档的窗口拆分支持。
[!endif]
[!if MAPI]

MAPI 支持
    生成的项目包含创建、操作、传输
    和存储邮件所需的代码。
[!endif]
[!if SOCKETS]

Windows 套接字
    应用程序支持在 TCP/IP 网络上建立通讯。
[!endif]

[!endif]
/////////////////////////////////////////////////////////////////////////////

其他标准文件：

StdAfx.h、StdAfx.cpp
    这些文件用于生成名为 [!output PROJECT_NAME].pch 的预编译头文件 (PCH)
    和名为 StdAfx.obj 的预编译类型文件。

Resource.h
    这是标准头文件，它定义新资源 ID。
    Microsoft Visual C++ 将读取并更新此文件。

/////////////////////////////////////////////////////////////////////////////

其他说明：

应用程序向导使用“TODO:” 来指示
应添加或自定义的源代码部分。
[!if APP_TYPE_MDI || APP_TYPE_SDI || APP_TYPE_DLG || APP_TYPE_MTLD]

如果应用程序在共享 DLL 中使用 MFC，且应用程序使用的语言不是
操作系统的当前语言，则需要从 Microsoft Visual C++ 光盘上 
Win\System 目录下将相应的本地化资源 MFC70XXX.DLL 
复制到计算机的 system 或 system32 目录下，
并将其重命名为 MFCLOC.DLL。  （“XXX”代表
语言缩写。  例如，MFC70DEU.DLL 包含翻译成
德语的资源。）  如果不这样做，应用程序的某些 UI 元素
将保留为操作系统的语言。
[!endif]

/////////////////////////////////////////////////////////////////////////////
