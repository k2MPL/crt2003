@echo off
[!if HM_NOTE]

REM -- �Ъ`�N�GOEM �P ANSI �r�����۲��B
REM -- �H�U�ɮצW�ٷ|�b�j�h�ƪ��s�边���ݰ_�Ӧ��ǩ_�ǡA�]���o���ɮץ���
REM -- �ϥ� OEM �r�����A�ӫD ANSI �r�����A�p���~��ϧ妸�ɥ��`�B�@�C
REM -- ��X�M�s�边�����ϥ� ANSI �r�����C
REM -- �W�٥u���b��X�������~�i�ݨ��A���̬O�H
REM -- ANSI �r�����s��C

[!endif]
REM -- �����q Microsoft Visual C++ ���ͪ� resource.h ���� Map ��
echo // MAKEHELP.BAT ���ͪ����� Map �ɡC�� [!output PROJECT_NAME].HPJ �ϥΡC>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // Commands (ID_* and IDM_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // Prompts (IDP_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // Resources (IDR_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // Dialogs (IDD_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // Frame Controls (IDW_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
REM -- Make help for Project [!output PROJECT_NAME]

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
