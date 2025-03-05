================================================================================
    MICROSOFT FOUNDATION CLASS ライブラリ : [!output PROJECT_NAME] プロジェクトの概要
===============================================================================



    アプリケーション ウィザードが作成した [!output PROJECT_NAME] には Microsoft 
    Foundation Classes の基本的な使い方が示されています。アプリケーション作成のひな型としてお使い
    ください。
    このファイルには [!output PROJECT_NAME] アプリケーションを構成している各ファイルの概要説明が含
    まれています。

[!output PROJECT_NAME].vcproj
    これはアプリケーション ウィザードで生成された VC++ プロジェクトのメイン プロジェクト ファイ	    ルです。ファイルが生成された Visual C++ のバージョン情報が含まれています。また、アプリケーシ	    ョン ウィザードで選択したプラットフォーム、構成およびプロジェクト機能に関する情報も含まれ		    ています。


[!output APP_HEADER]
    このファイルはアプリケーションの中心となるヘッダー ファイルです。このファイルには、Resource.h 
    も含み、他のプロジェクト特定のヘッダが含まれていて、[!output APP_CLASS] アプリケーション クラス
    の宣言をします。

[!output APP_IMPL]
    このファイルは [!output APP_CLASS] アプリケーションクラスを含むアプリケーションの中心となるソー
    スファイルです。

[!output PROJECT_NAME].rc
    このファイルはプログラムが使用する Microsoft Windows のリソースを列挙します。このファイルは RES 
    サブディレクトリに保存されているアイコン、ビットマップ、カーソルを含みます。このファイルは、
    Microsoft Visual C++ で直接編集可能です。プロジェクト リソースは [!output LCID] にあります。

res\[!output SAFE_PROJECT_NAME].ico
    このファイルは、アプリケーションのアイコンとして使用されるアイコンファイルです。このアイコンは
    リソース ファイル [!output PROJECT_NAME].rc によってインクルードされます。

res\[!output SAFE_PROJECT_NAME].rc2
    このファイルは Microsoft Visual C++ によって編集されないリソースを含んでいます。このファイルに
    リソース エディタで編集されないすべてのリソースを記述してください。
[!if CONTAINER_SERVER || FULL_SERVER || MINI_SERVER || AUTOMATION || HAS_SUFFIX]
[!if !HTML_EDITVIEW]
[!output PROJECT_NAME].reg
    このレジストリ ファイルはフレームワークの設定法を紹介するためのサンプル ファイルです。アプリケー
    ションと共に .reg [!if APP_TYPE_DLG] ファイルとして使用します。
[!else]
    アプリケーションと一緒に使用するか、または削除してデフォルトの登録 RegisterShellFileTypes を使用
    します。
[!endif]

[!if AUTOMATION]
[!output PROJECT_NAME].idl
    このファイルはアプリケーションのタイプ ライブラリ用のインターフェース記述言語ソース コードを含ん
    でいます。
[!endif]
[!endif]
[!endif]

[!if !APP_TYPE_DLG]
/////////////////////////////////////////////////////////////////////////////

メイン フレーム ウィンドウ :
[!if PROJECT_STYLE_EXPLORER]
    Windows Explorer Style: これらのプロジェクトは、2 つフレームを持つ Windows Explorer のようなイン
    ターフェースを含みます。
[!else]
    プロジェクトは標準の MFC インターフェースを含みます。
[!endif]

[!output MAIN_FRAME_HEADER], [!output MAIN_FRAME_IMPL]
    これらのファイルは、[!if APP_TYPE_MDI] から派生しすべての MDI フレーム機 能を制御するフレーム 
    クラス [!output MAIN_FRAME_CLASS] CMDIFrameWnd を含みます。
    
[!else]
    CFrameWnd で、すべての MDI フレーム機能を制御します。
[!endif]
[!if PROJECT_STYLE_EXPLORER]

[!output TREE_VIEW_HEADER], [!output TREE_VIEW_IMPL]
    これらのファイルは CTreeView から派生した左フレーム クラス [!output TREE_VIEW_CLASS] を含み
    ます。
   
[!endif]

[!if DOCKING_TOOLBAR]
res\Toolbar.bmp
    このビットマップ ファイルはツールバーのイメージとして使います。
    ツールバーやステータスバーの初期設定は [!output MAIN_FRAME_CLASS] クラスによってビルドされます。
    ツールバーのボタンコントロールを追加したい時にはツールバーのビットマップをリソースエディタで
    編集し、[!output PROJECT_NAME].rc ファイル内の IDR_MAINFRAME TOOLBAR 配列を変更してください。
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]

res\IToolbar.bmp
    サーバー アプリケーションが他のコンテナで埋めこみ先起動したときに、このビットマップ ファイルが
    ツールバーのタイル イメージとして使われます。このツールバーは [!output INPLACE_FRAME_CLASS] ク 
    ラスによってビルドされます。このビットマップは、多くの非サーバー コマンドが除かれていることを除い 
    て res\Toolbar.bmp 内のビットマップと共通です。

[!endif]
[!endif]
[!if APP_TYPE_MDI]
/////////////////////////////////////////////////////////////////////////////

子ウィンドウ フレーム :

ChildFrm.h, ChildFrm.cpp
    これらのファイルは [!output CHILD_FRAME_CLASS] クラスの定義とインプリメンテーションを行います。 
    このクラスは MDI アプリケーションの子ウィンドウをサポートするためのものです。

[!endif]
/////////////////////////////////////////////////////////////////////////////

[!if DOCVIEW]
[!if !DB_VIEW_NO_FILE]
アプリケーション ウィザードは 1 つのドキュメントタイプと 1 つのビューを作成します:

[!output DOC_HEADER], [!output DOC_IMPL] - ドキュメント
    これらのファイルは [!output DOC_CLASS] クラスを含みます。特別なドキュメント データを付け加えた 
    り、ファイルの保存や (via [!output DOC_CLASS]::Serialize) を読み込んだりするには、このファイル 
    を編集してください。
[!if HAS_SUFFIX && !HTML_EDITVIEW]
    ドキュメントには次の文字列が含まれます :
        ファイルの拡張子 :             [!output FILE_EXTENSION]
        ファイルの種類の識別子 :       [!output FILE_TYPE_ID]
        メイン フレーム キャプション : [!output MAIN_FRAME_CAPTION]
        ドキュメントの種類の名前 :     [!output DOC_TYPE_NAME]
        フィルタ名 :                   [!output FILTER_NAME]
        ファイルの新しい短い名前 :     [!output FILE_NEW_NAME_SHORT]
        ファイルの種類の長い名前 :     [!output FILE_NEW_NAME_LONG]
[!endif]
[!else]
アプリケーション ウィザードは 1 つのビューを作成します :
[!endif]

[!output VIEW_HEADER], [!output VIEW_IMPL] - ドキュメントのビュー
    これらのファイルは [!output VIEW_CLASS] クラスを含みます。
[!if !DB_VIEW_NO_FILE]
    [!output VIEW_CLASS] オブジェクトは [!output DOC_CLASS] オブジェクトを表示するために使用され 
    ます。
[!endif]

[!if APP_TYPE_MDI]
res\[!output SAFE_PROJECT_NAME]Doc.ico
    このファイルは [!output DOC_CLASS] クラスの MDI 子ウィンドウ用アイコンとして使われるアイコン  
    ファイルです。このアイコンはリソースファイル [!output PROJECT_NAME].rc によってインクルード 
    されます。
[!endif]

[!endif]

[!if DB_VIEW_NO_FILE || DB_VIEW_WITH_FILE]
/////////////////////////////////////////////////////////////////////////////
データベース サポート :

[!output ROWSET_HEADER], [!output ROWSET_IMPL]
    これらのファイルには [!output ROWSET_CLASS] クラスが含まれています。このクラスはウィザードで 
    選択したデータ ソースにアクセスするのに使用されます。
[!if DB_VIEW_NO_FILE]
    シリアル化サポートは追加されません。
[!else]
    シリアル化サポートが追加されました。
[!endif]
[!endif]
[!if CONTAINER || FULL_SERVER || MINI_SERVER || CONTAINER_SERVER]
/////////////////////////////////////////////////////////////////////////////

アプリケーション ウィザードは OLE に特定のクラスを作成しました。

[!if CONTAINER || CONTAINER_SERVER]
[!output CONTAINER_ITEM_HEADER], [!output CONTAINER_ITEM_IMPL]
    これらのファイルは [!output CONTAINER_ITEM_CLASS] クラスを含みます。このクラスは OLE オブジェク 
    トの操作に使われます。OLE オブジェクトは [!output VIEW_CLASS] クラスによって表示され、 
    [!output DOC_CLASS] クラスの一部分としてシリアル化されます。
[!if ACTIVE_DOC_CONTAINER]
    このプログラムは、フレーム内でアクティブ ドキュメントを操作するためのサポートを含みます。
[!endif]
[!endif]
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]

[!output SERVER_ITEM_HEADER], [!output SERVER_ITEM_IMPL]
    これらのファイルは [!output SERVER_ITEM_CLASS] を含みます。このクラスは [!output DOC_CLASS]  
    クラスを OLE システムに接続し、必要であればドキュメントにリンクを設定するために使われます。
    
[!if ACTIVE_DOC_SERVER]
    プロジェクトはアクティブ ドキュメントを作成し管理するためのサポートをします。
[!endif]

[!output INPLACE_FRAME_HEADER], [!output INPLACE_FRAME_IMPL]
    これらのファイルは [!output INPLACE_FRAME_CLASS] 含みます。このクラスは COleIPFrameWnd から 
    派生し、埋め込み先で起動されている間すべてのフレームの機能を制御します。
[!endif]

[!if SUPPORT_COMPOUND_FILES]
    このプロジェクトは複合ファイルをサポートします。複合ファイルフォーマットは、1 つのファイルの中 
    に 1 つ以上の自動オブジェクトを持つドキュメントを保存します。またファイルの中のオブジェクトには 
    個別にアクセスすることができます。
[!endif]
[!endif]
[!else]

/////////////////////////////////////////////////////////////////////////////

[!if AUTOMATION]
アプリケーション ウィザードは 1 つのダイアログ クラスおよびオートメーション プロキシ クラスを作成 
    します :
[!else]
アプリケーション ウィザードは 1 つのダイアログ クラスを作成します :
[!endif]

[!output DIALOG_HEADER], [!output DIALOG_IMPL] - the dialog
    Tこれらのファイルは [!output DIALOG_CLASS] クラスを含みます。このクラスはアプリケーションの 
    メイン ダイアログの動作を定義します。ダイアログ テンプレートは Microsoft Visual C++ で編集 
    可能な [!output PROJECT_NAME].rc に含まれます。
[!if AUTOMATION]

[!output DIALOG_AUTO_PROXY_HEADER], [!output DIALOG_AUTO_PROXY_IMPL] - オートメーション オブジェクト
    これらのファイルは [!output DIALOG_AUTO_PROXY_CLASS] クラスを含みます。このクラスはダイアログ用 
    の "オートメーション プロキシ" クラスと呼ばれます。理由はオーメーション コントローラがダイアログ 
    にアクセスするために使用可能なオートメーション メソッドおよびプロパティの表示を行うためです。こ 
    れらのメソッドおよびプロパティはダイアログ クラスから直接表示されません。それはダイアログ ベース 
    の MFC アプリケーション モデルの場合、オートメーション オブジェクトとユーザー インターフェイスを 
    別々にしておくことが簡潔で簡単だからです。
[!endif]
[!endif]

[!if CONTEXT_HELP]
/////////////////////////////////////////////////////////////////////////////

ヘルプ サポート :

[!if HELPSTYLE_HTML]
hlp\[!output PROJECT_NAME].hhp
    このファイルはヘルプ プロジェクト ファイルです。ヘルプ ファイルを .chm ファイルにコンパイルする 
    のに必要なデータを含んでいます

hlp\[!output PROJECT_NAME].hhc
    このファイルはヘルプ プロジェクトのコンテンツ一覧を表示します。

hlp\[!output PROJECT_NAME].hhk
    このファイルはヘルプ トピックのインデックスを含みます。

hlp\afxcore.htm
    このファイルは標準の MFC コマンドと画面オブジェクト用の標準ヘルプ トピックを含みます。任意の 
    ヘルプ トピックをこのファイルに追加してください。

[!if PRINTING]
hlp\afxprint.htm
    このファイルは印刷コマンド用のヘルプ トピックを含みます。

[!endif]
makehtmlhelp.bat
    このファイルはヘルプ ファイルをコンパイルするためにビルド システムで使用します。

hlp\Images\*.gif
    これらのファイルは Microsoft Foundation Class ライブラリの標準コマンドに 関する標準ヘルプ ファ 
    イルのトピックで使用するビットマップ ファイルです。
[!else]
hlp\[!output PROJECT_NAME].hpj
    このファイルはヘルプ コンパイラがアプリケーションのヘルプ ファイルを作成するためのヘルプ プロ 
    ジェクト ファイルです。

hlp\*.bmp
    これらのファイルは Microsoft Foundation Class ライブラリの標準コマンドに関する標準ヘルプ ファ 
    イルのトピックで使用するビットマップ ファイルです。

hlp\*.rtf
    これらのファイルは標準 MFC コマンドと画面オブジェクトに関する標準ヘルプ トピックを含んでいます。
[!endif]
[!endif]

[!if ACTIVEX_CONTROLS || PRINTING || SPLITTER || MAPI || SOCKETS]
/////////////////////////////////////////////////////////////////////////////

その他の機能 :
[!if ACTIVEX_CONTROLS]

ActiveX コントロール
    アプリケーションは ActiveX コントロールの使用に関するサポートを含みます。
[!endif]
[!if PRINTING]

印刷と印刷プレビューのサポート
    アプリケーション ウィザードでは MFC ライブラリから CView クラスのメンバ関数を呼び出すことによっ 
    て、印刷、印刷の設定、そして印刷プレビューコマンドを処理できるようコード生成が行われました。
[!endif]
[!if DB_SUPPORT_HEADER_ONLY && !APP_TYPE_DLG]
データベース サポート
    アプリケーション ウィザードにプログラムのため基本的なレベルのデータベース サポートが追加されま 
    した。必要なファイルのみが含まれています。
[!endif]
[!if SPLITTER && !APP_TYPE_DLG]
分割ウィンドウ
    アプリケーション ウィザードはThe application wizard has added support for アプリケーション ド 
    キュメント用に分割ウィンドウのサポートを追加しました。
[!endif]
[!if MAPI]

MAPI サポート
    生成されたプロジェクトにはメール メッセージを作成、操作、送信、そして保存するために必要なコード 
    が含まれています。
[!endif]
[!if SOCKETS]

Windows ソケット 
    アプリケーションは TCP/IP ネットワークを通したコミュニケーションの確立のサポートをします。
[!endif]

[!endif]
/////////////////////////////////////////////////////////////////////////////

その他の標準ファイル :

StdAfx.h, StdAfx.cpp
    これらのファイルは既にコンパイルされたヘッダー ファイル (PCH) [!output PROJECT_NAME].pch や既にコン 
    パイルされた型のファイル StdAfx.obj をビルドするために使われるファイルです。

Resource.h
    このファイルは新規リソース ID を定義する標準ヘッダー ファイルです。Microsoft Visual C++ はこの 
    ファイルの読み込と更新を行います。

/////////////////////////////////////////////////////////////////////////////

その他の注意 :

アプリケーション ウィザードは "TODO:" で始まるコメントを使用して、追加したりカスタイズの必要な 
    ソース コードの部分を示します。
[!if APP_TYPE_MDI || APP_TYPE_SDI || APP_TYPE_DLG || APP_TYPE_MTLD]

アプリケーションで共有 DLL 内で MFC を使用する場合や、アプリケーションがオペレーティング システムで現在使用している言語以外の言語を使用している場合は、Win\System ディレクトリにある Microsoft Visual C++ CD-ROM から、ローカライズされたリソースに対応する MFC70XXX.DLL を system または system32 ディレクトリにコピーして、ファイル名を MFCLOC.DLL にする必要があります。("XXX" は言語の省略形を示します。例えば、MFC70JPN.DLL は日本語に翻訳されたリソースを含みます。) この例を無視するとアプリケーション内のいくつかの UI 要素はオペレーティング システムの言語のまま残ります。
[!endif]

/////////////////////////////////////////////////////////////////////////////
