================================================================================
    MFC 程式庫 : [!output PROJECT_NAME] 專案概觀
===============================================================================

AppWizard 為您建立了 [!output PROJECT_NAME] 應用程式。此應用程式不只展示
使用 MFC 的基礎用法，它也是個讓您學習如何撰寫應用程式的出發點。

這個檔案包含構成 [!output PROJECT_NAME] 應用程式的所有檔案的摘要。

[!output PROJECT_NAME].vcproj
    這是使用應用程式精靈所建立的 VC++ 專案的主專案檔。它包含有關產生此
    檔案的 Visual C++ 版本資訊，以及以應用程式精靈選取的平台、組態和專
    案功能等相關資訊。

[!output APP_HEADER]
    這是應用程式的主標頭檔。它包括其他專案指定的標頭 (包括 Resource.h) 
    和宣告 [!output APP_CLASS] 應用程式類別。

[!output APP_IMPL]
    這是包含應用程式類別 [!output APP_CLASS] 的主應用程式來源檔。

[!output PROJECT_NAME].rc
    這是此程式使用的所有 Microsoft Windows 資源的清單。它包括圖示、點陣圖
    以及儲存在 RES 子目錄中的游標。您可以在 Microsoft Visual C++ 中直接編
    輯此檔案。專案資源位於 [!output LCID] 中。

res\[!output SAFE_PROJECT_NAME].ico
    這是個圖示檔，它被當成應用程式的圖示使用。主資源檔 [!output PROJECT_NAME].rc 
    中包含此圖示。

res\[!output SAFE_PROJECT_NAME].rc2
    這個檔案包含未經由 Microsoft Visual C++ 編輯的檔案。您必須將所有不可由
    資源編輯器編輯的資源放置在此檔案中。
[!if CONTAINER_SERVER || FULL_SERVER || MINI_SERVER || AUTOMATION || HAS_SUFFIX]
[!if !HTML_EDITVIEW]
[!output PROJECT_NAME].reg
    這是顯示此架構將為您設定的登錄設定範例的 .REG 檔。您可以將它當成 .REG 使用。
[!if APP_TYPE_DLG]
    與應用程式一起使用的檔案。
[!else]
    讓檔案與專案一起存放或是刪除此檔案，然後使用預設的 RegisterShellFileTypes 
    登錄。
[!endif]

[!if AUTOMATION]
[!output PROJECT_NAME].idl
    這個檔案包含應用程式型別程式庫的介面描述語言 (Interface Description Language) 
    原始程式碼。
[!endif]
[!endif]
[!endif]

[!if !APP_TYPE_DLG]
/////////////////////////////////////////////////////////////////////////////

關於主框架視窗:
[!if PROJECT_STYLE_EXPLORER]
    Windows 檔案總管樣式: 此專案將會包含一個類似 Windows 檔案總管 (有兩個框架) 
    的介面。
[!else]
    此專案將包含標準 MFC 介面。
[!endif]

[!output MAIN_FRAME_HEADER], [!output MAIN_FRAME_IMPL]
    這些檔案包含框架類別 [!output MAIN_FRAME_CLASS]，此類別衍生自
[!if APP_TYPE_MDI]
    CMDIFrameWnd 並控制所有 MDI 框架功能。
[!else]
    CFrameWnd 並控制所有 SDI 框架功能。
[!endif]
[!if PROJECT_STYLE_EXPLORER]

[!output TREE_VIEW_HEADER], [!output TREE_VIEW_IMPL]
    這些檔案包含左框架類別 [!output TREE_VIEW_CLASS]，此類別衍生自
    CTreeView。
[!endif]

[!if DOCKING_TOOLBAR]
res\Toolbar.bmp
    這個點陣圖檔用於建立工具列的並排影像。初始的工具列和狀態列是在 
    [!output MAIN_FRAME_CLASS] 類別中建構。請使用資源編輯器編輯此工
    具列點陣圖，然後在 [!output PROJECT_NAME].rc 中更新 IDR_MAINFRAME TOOLBAR 
    陣列以加入工具列按鈕。
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]

res\IToolbar.bmp
    當您的伺服器應用程式在另一個容器中已就位且已執行時，這個點陣圖檔
    用於建立工具列的並排影像。此工具列是在 [!output INPLACE_FRAME_CLASS] 
    類別中建構。除了已移除多個非伺服器命令外，此點陣圖與 res\Toolbar.bmp 
    中的點陣圖類似。

[!endif]
[!endif]
[!if APP_TYPE_MDI]
/////////////////////////////////////////////////////////////////////////////

關於子框架視窗:

ChildFrm.h, ChildFrm.cpp
    這些檔案定義和實作 [!output CHILD_FRAME_CLASS] 類別，此類別支援 
    MDI 應用程式中的子視窗。

[!endif]
/////////////////////////////////////////////////////////////////////////////

[!if DOCVIEW]
[!if !DB_VIEW_NO_FILE]
AppWizard 建立文件類型及檢視:

[!output DOC_HEADER], [!output DOC_IMPL] - 此文件
    這些檔案包含您的 [!output DOC_CLASS] 類別。編輯這些檔案以加入特殊的文件
    資料，然後實作檔案儲存和載入 (透過 [!output DOC_CLASS]::Serialize)。
[!if HAS_SUFFIX && !HTML_EDITVIEW]
    文件將會有下列字串:
        檔案副檔名:         [!output FILE_EXTENSION]
        檔案類型 ID:        [!output FILE_TYPE_ID]
        主框架標題: 	    [!output MAIN_FRAME_CAPTION]
        文件類型名稱:       [!output SAFE_DOC_TYPE_NAME]
        篩選條件名稱:       [!output FILTER_NAME]
        檔案新簡短名稱:     [!output FILE_NEW_NAME_SHORT]
        檔案類型長檔名:     [!output FILE_NEW_NAME_LONG]
[!endif]
[!else]
AppWizard 建立檢視:
[!endif]

[!output VIEW_HEADER], [!output VIEW_IMPL] - 文件的檢視
    這些檔案包含您的 [!output VIEW_CLASS] 類別。
[!if !DB_VIEW_NO_FILE]
    [!output VIEW_CLASS] 物件用於檢視 [!output DOC_CLASS] 物件。
[!endif]

[!if APP_TYPE_MDI]
res\[!output SAFE_PROJECT_NAME]Doc.ico
    這是個圖示檔，它做為 [!output DOC_CLASS] 類別的 MDI 子視窗的圖示使用。
    此圖示由主資源檔 [!output PROJECT_NAME].rc 所引用。
[!endif]

[!endif]

[!if DB_VIEW_NO_FILE || DB_VIEW_WITH_FILE]
/////////////////////////////////////////////////////////////////////////////

資料庫支援:

[!output ROWSET_HEADER], [!output ROWSET_IMPL]
    這些檔案包含您的 [!output ROWSET_CLASS] 類別。此類別用於存取您在精靈中
    選取的資料來源。
[!if DB_VIEW_NO_FILE]
    將不會加入序列化支援。
[!else]
    將加入序列化支援。
[!endif]
[!endif]
[!if CONTAINER || FULL_SERVER || MINI_SERVER || CONTAINER_SERVER]
/////////////////////////////////////////////////////////////////////////////

AppWizard 同時也建立 OLE 特定類別。

[!if CONTAINER || CONTAINER_SERVER]
[!output CONTAINER_ITEM_HEADER], [!output CONTAINER_ITEM_IMPL]
    這些檔案包含您的 [!output CONTAINER_ITEM_CLASS] 類別。此類別用於處理 OLE 物件。
    OLE 物件通常是由 [!output VIEW_CLASS] 類別顯示，並序列化為 [!output DOC_CLASS] 
    類別的一部份。
[!if ACTIVE_DOC_CONTAINER]
    這個程式包含在其框架中包含 Active 文件的支援。
[!endif]
[!endif]
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]

[!output SERVER_ITEM_HEADER], [!output SERVER_ITEM_IMPL]
    這些檔案包含您的 [!output SERVER_ITEM_CLASS]。此類別用於連接 [!output DOC_CLASS] 
    類別與 OLE 系統，以及選擇性地提供至您的文件的連結。
[!if ACTIVE_DOC_SERVER]
    此專案支援建立和管理現用文件。
[!endif]

[!output INPLACE_FRAME_HEADER], [!output INPLACE_FRAME_IMPL]
    這些檔案包含您的 [!output INPLACE_FRAME_CLASS]。此類別是從 COleIPFrameWnd 衍生，
    並且在就位啟動過程中控制所有的框架功能。
[!endif]

[!if SUPPORT_COMPOUND_FILES]
    這個專案支援複合檔案。此複合檔案格式儲存包含一或多個至某檔案的 Automation 物件的
    文件，並且允許存取個別物件的檔案。
[!endif]
[!endif]
[!else]

/////////////////////////////////////////////////////////////////////////////

[!if AUTOMATION]
AppWizard 建立對話方塊類別和 Automation Proxy 類別:
[!else]
AppWizard 建立對話方塊類別:
[!endif]

[!output DIALOG_HEADER], [!output DIALOG_IMPL] - 對話方塊
    這些檔案包含 [!output DIALOG_CLASS] 類別。此類別定義應用程式的主要對話方塊
    的行為。此對話方塊的範本位於可使用 Microsoft Visual C++ 編輯的 
    [!output PROJECT_NAME].rc 中。
[!if AUTOMATION]

[!output DIALOG_AUTO_PROXY_HEADER], [!output DIALOG_AUTO_PROXY_IMPL] - Automation 物件
    這些檔案包含 [!output DIALOG_AUTO_PROXY_CLASS] 類別。此類別在對話方塊中稱為 
    "automation proxy" 類別，因為它可處理Automation 控制程式用來存取對話方塊的
    Automaton 方法及屬性的顯露。這些方法和屬性並非直接自對話方塊顯露，因為在以
    強制回應對話方塊為基礎的 MFC 應用程式中，將 Automation 物件與使用者介面分開
    可讓應用程式保持更為簡潔和簡易。
[!endif]
[!endif]

[!if CONTEXT_HELP]
/////////////////////////////////////////////////////////////////////////////

說明支援:

[!if HELPSTYLE_HTML]
hlp\[!output PROJECT_NAME].hhp
    這個檔案是個說明專案檔。它包含將說明檔編譯成 .chm 檔所需的資料。

hlp\[!output PROJECT_NAME].hhc
    這個檔案會列出說明專案的內容。

hlp\[!output PROJECT_NAME].hhk
    這個檔案包含說明主題的索引。

hlp\afxcore.htm
    這個檔案包含標準 MFC 命令和螢幕物件的標準說明主題。將您自己的說明
    主題加入至此檔案。

[!if PRINTING]
hlp\afxprint.htm
    這個檔案包含列印命令的說明主題。

[!endif]
makehtmlhelp.bat
    這個檔案是組建系統編譯說明檔時使用。

hlp\Images\*.gif
    這些是 MFC 程式庫標準命令的標準說明檔主題所必須的點陣圖檔。

[!else]
hlp\[!output PROJECT_NAME].hpj
    這個檔案是說明編譯器建立應用程式的說明檔所使用的說明專案檔。

hlp\*.bmp
    這些是 MFC 程式庫標準命令的標準說明檔主題所必須的點陣圖檔。

hlp\*.rtf
    這些檔案包含標準 MFC 命令和螢幕物件的標準說明主題。
[!endif]
[!endif]

[!if ACTIVEX_CONTROLS || PRINTING || SPLITTER || MAPI || SOCKETS]
/////////////////////////////////////////////////////////////////////////////

其他功能:
[!if ACTIVEX_CONTROLS]

ActiveX 控制項
    此應用程式包含使用 ActiveX 控制項的支援。
[!endif]
[!if PRINTING]

列印和預覽列印支援
    Appwizard 已產生程式碼藉由呼叫來自 MFC 程式庫 CView 類別中的成員函式來處理
    列印、列印設定和預覽列印命令。
[!endif]
[!if DB_SUPPORT_HEADER_ONLY && !APP_TYPE_DLG]

資料庫支援
    Appwizard 已為您的程式加入基本層級的資料庫支援。只包含必須的檔案。
[!endif]
[!if SPLITTER && !APP_TYPE_DLG]

分隔視窗
    Appwizard 已為您的應用程式文件加入分隔視窗支援。
[!endif]
[!if MAPI]

MAPI 支援
    產生的物件包含建立、操作、傳輸和儲存郵件訊息所需要的程式碼。
[!endif]
[!if SOCKETS]

Windows Sockets
    此應用程式支援在 TCP/IP 網路上建立通訊。
[!endif]

[!endif]
/////////////////////////////////////////////////////////////////////////////

其他標準檔案:

StdAfx.h, StdAfx.cpp
    這些檔案用於建置名為 [!output PROJECT_NAME].pch 的先行編譯標頭檔 (PCH)，
    以及名為 StdAfx.obj 的先行編譯型別檔。

Resource.h
    這是標準的標頭檔，它定義新資源 ID。
    Microsoft Visual C++ 會讀取並更新此檔案。

/////////////////////////////////////////////////////////////////////////////

其他注意事項:

AppWizard 使用 "TODO:" 來表示您應該加入或自訂的原始程式碼。
[!if APP_TYPE_MDI || APP_TYPE_SDI || APP_TYPE_DLG || APP_TYPE_MTLD]

如果您的應用程式在共用的 DLL 中使用 MFC，而且此應用程式使用與作業系統不同的
語言，您必須從 Microsoft Visual C++ CD-ROM 中 Win\System 目錄下將相對應的當
地語系化資源 MFC70XXX.DLL 複製到電腦的 system 或 system32 目錄，然後將它重
新命名為 MFCLOC.DLL ("XXX" 代表語言縮寫。例如，MFC70DEU.DLL 包含翻譯為德文的
資源)。如果您並未執行此步驟，應用程式中的某些 UI 項目仍將使用作業系統所用的
語言。
[!endif]

/////////////////////////////////////////////////////////////////////////////
