@echo off
[!if HM_NOTE]

REM -- ����: OEM�� ANSI ���ڿ� ������ ������
REM -- �Ʒ��� ���� ���� �̸��� ��κ��� �����⿡�� ����� ǥ�õ��� ���� �� �ֽ��ϴ�.
REM -- �̷��� ���̴� ������ ��ġ ������ ����� ������ �� �ֵ��� ANSI ��� OEM ���ڿ�
REM -- ������ ���Ǿ��� �����Դϴ�. ������ ��°� ������ â������ ANSI ���ڿ� ������
REM -- ����մϴ�. ��� â������ ���̴� ���� �̸��� ANSI ���ڿ� ��������
REM -- �ۼ��� ���Դϴ�.

[!endif]
REM -- ���� Microsoft Visual C++���� ������ resource.h�� ����Ͽ� �� ������ ����ϴ�.
echo // MAKEHELP.BAT���� ���� �� ������ �����մϴ�. �� ��� ������ [!output PROJECT_NAME].HPJ. >"hlp\[!output HM_FILE_OEM].hm"�� ���� ������ ����մϴ�.
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // ��� (ID_* and IDM_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // ������Ʈ (IDP_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // ���ҽ� (IDR_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // ��ȭ ���� (IDD_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // ������ ��Ʈ�� (IDW_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
REM -- ������Ʈ�� ���� ������ ����ϴ�. �� ��� ������ [!output PROJECT_NAME]�� ���� ������ ����մϴ�.

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
echo hlp\[!output PROJECT_NAME].hpj(1) : error: Problem encountered creating help file

:done
echo.
