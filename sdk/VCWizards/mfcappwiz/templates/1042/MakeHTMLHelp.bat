@echo off

REM -- 먼저 Microsoft Visual C++에서 생성된 resource.h를 사용하여 맵 파일을 만듭니다.
echo // MAKEHELP.BAT에서 도움말 맵 파일을 생성합니다. 이 경우 구문은 [!output PROJECT_NAME].HHP. >"hlp\HTMLDefines.h"와 같은 형식을 사용합니다.
echo. >>"hlp\HTMLDefines.h"
echo // 명령 (ID_* and IDM_*) >>"hlp\HTMLDefines.h"
makehm /h ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\HTMLDefines.h"
echo. >>"hlp\HTMLDefines.h"
echo // 프롬프트 (IDP_*) >>"hlp\HTMLDefines.h"
makehm /h IDP_,HIDP_,0x30000 resource.h >>"hlp\HTMLDefines.h"
echo. >>"hlp\HTMLDefines.h"
echo // 리소스 (IDR_*) >>"hlp\HTMLDefines.h"
makehm /h IDR_,HIDR_,0x20000 resource.h >>"hlp\HTMLDefines.h"
echo. >>"hlp\HTMLDefines.h"
echo // 대화 상자 (IDD_*) >>"hlp\HTMLDefines.h"
makehm /h IDD_,HIDD_,0x20000 resource.h >>"hlp\HTMLDefines.h"
echo. >>"hlp\HTMLDefines.h"
echo // 프레임 컨트롤 (IDW_*) >>"hlp\HTMLDefines.h"
makehm /h /a afxhh.h IDW_,HIDW_,0x50000 resource.h >>"hlp\HTMLDefines.h"

REM -- 프로젝트에 대한 도움말을 만듭니다. 이 경우 구문은 [!output PROJECT_NAME]과 같은 형식을 사용합니다.

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

