@echo off

REM -- ���� Microsoft Visual C++���� ������ resource.h�� ����Ͽ� �� ������ ����ϴ�.
echo // MAKEHELP.BAT���� ���� �� ������ �����մϴ�. �� ��� ������ [!output PROJECT_NAME].HHP. >"hlp\HTMLDefines.h"�� ���� ������ ����մϴ�.
echo. >>"hlp\HTMLDefines.h"
echo // ��� (ID_* and IDM_*) >>"hlp\HTMLDefines.h"
makehm /h ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\HTMLDefines.h"
echo. >>"hlp\HTMLDefines.h"
echo // ������Ʈ (IDP_*) >>"hlp\HTMLDefines.h"
makehm /h IDP_,HIDP_,0x30000 resource.h >>"hlp\HTMLDefines.h"
echo. >>"hlp\HTMLDefines.h"
echo // ���ҽ� (IDR_*) >>"hlp\HTMLDefines.h"
makehm /h IDR_,HIDR_,0x20000 resource.h >>"hlp\HTMLDefines.h"
echo. >>"hlp\HTMLDefines.h"
echo // ��ȭ ���� (IDD_*) >>"hlp\HTMLDefines.h"
makehm /h IDD_,HIDD_,0x20000 resource.h >>"hlp\HTMLDefines.h"
echo. >>"hlp\HTMLDefines.h"
echo // ������ ��Ʈ�� (IDW_*) >>"hlp\HTMLDefines.h"
makehm /h /a afxhh.h IDW_,HIDW_,0x50000 resource.h >>"hlp\HTMLDefines.h"

REM -- ������Ʈ�� ���� ������ ����ϴ�. �� ��� ������ [!output PROJECT_NAME]�� ���� ������ ����մϴ�.

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

