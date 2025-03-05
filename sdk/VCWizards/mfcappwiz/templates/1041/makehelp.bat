@echo off
[!if HM_NOTE]

REM -- 注意事項 : OEM と ANSI 文字セットの違い
REM -- ANSI 文字セットを使用すると、ほとんどのエディタでは、
REM -- 下記のようにファイル名が壊れて表示されます。  
REM -- バッチ ファイルが正常に動作するためには、ANSI ではなく OEM 文字セットを使用してください。
REM -- 出力とエディタ ウィンドウは ANSI 文字セットで動作します。
REM -- 出力ウィンドウにだけ名前が表示される場合は、ANSI 文字セットのままにしてあります。

[!endif]
REM -- 最初に Microsoft Visual C++ で生成した resource.h でマップ ファイルを作成します。
echo // MAKEHELP.BAT 生成されたヘルプ マップ ファイルです。[!output PROJECT_NAME].HPJ で使用されます。 >"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // コマンド (ID_* and IDM_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // 表示 (IDP_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // リソース (IDR_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // ダイアログ (IDD_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // フレーム コントロール (IDW_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
REM -- プロジェクト [!output PROJECT_NAME] のヘルプを作成します。

echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\[!output PROJECT_NAME_OEM].hpj"
if errorlevel 1 goto :Error
if not exist "hlp\[!output PROJECT_NAME_OEM].hlp" goto :Error
if not exist "hlp\[!output PROJECT_NAME_OEM].cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\[!output PROJECT_NAME_OEM].hlp" Debug
if exist Debug\nul copy "hlp\[!output PROJECT_NAME_OEM].cnt" Debug
if exist Release\nul copy "hlp\[!output PROJECT_NAME_OEM].hlp" Release
if exist Release\nul copy "hlp\[!output PROJECT_NAME_OEM].cnt" Release
echo.
goto :done

:Error
echo hlp\[!output PROJECT_NAME].hpj(1) : エラー : ヘルプ ファイルの作成中に問題が発生しました。

:done
echo.
