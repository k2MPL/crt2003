@echo off


REM -- 首先從 Microsoft Visual C++ 產生的 resource.h 做成 Map 檔
echo // MAKEHELP.BAT 產生的說明 Map 檔。供 [!output PROJECT_NAME].HHP 使用。 >"hlp\HTMLDefines.h"
echo. >>"hlp\HTMLDefines.h"
echo // Commands (ID_* and IDM_*) >>"hlp\HTMLDefines.h"
makehm /h ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\HTMLDefines.h"
echo. >>"hlp\HTMLDefines.h"
echo // Prompts (IDP_*) >>"hlp\HTMLDefines.h"
makehm /h IDP_,HIDP_,0x30000 resource.h >>"hlp\HTMLDefines.h"
echo. >>"hlp\HTMLDefines.h"
echo // Resources (IDR_*) >>"hlp\HTMLDefines.h"
makehm /h IDR_,HIDR_,0x20000 resource.h >>"hlp\HTMLDefines.h"
echo. >>"hlp\HTMLDefines.h"
echo // Dialogs (IDD_*) >>"hlp\HTMLDefines.h"
makehm /h IDD_,HIDD_,0x20000 resource.h >>"hlp\HTMLDefines.h"
echo. >>"hlp\HTMLDefines.h"
echo // Frame Controls (IDW_*) >>"hlp\HTMLDefines.h"
makehm /h /a afxhh.h IDW_,HIDW_,0x50000 resource.h >>"hlp\HTMLDefines.h"

REM -- 製作專案 [!output PROJECT_NAME] 的說明

echo Building Win32 HTML Help files
start /wait hhc "hlp\[!output PROJECT_NAME_OEM].hhp"
if not exist "hlp\[!output PROJECT_NAME_OEM].chm" goto :Error 
if exist Debug\nul copy "hlp\[!output PROJECT_NAME_OEM].chm" Debug
if exist Release\nul copy "hlp\[!output PROJECT_NAME_OEM].chm" Release
goto :done

:Error 
echo hlp\[!output PROJECT_NAME_OEM].hhp(1) : error: 
echo.

:done 
echo.

