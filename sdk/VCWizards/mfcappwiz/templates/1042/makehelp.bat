@echo off
[!if HM_NOTE]

REM -- 참고: OEM과 ANSI 문자열 집합의 차이점
REM -- 아래의 여러 파일 이름이 대부분의 편집기에서 제대로 표시되지 않을 수 있습니다.
REM -- 이렇게 보이는 이유는 배치 파일이 제대로 동작할 수 있도록 ANSI 대신 OEM 문자열
REM -- 집합이 사용되었기 때문입니다. 하지만 출력과 편집기 창에서는 ANSI 문자열 집합을
REM -- 사용합니다. 출력 창에서만 보이는 파일 이름은 ANSI 문자열 집합으로
REM -- 작성된 것입니다.

[!endif]
REM -- 먼저 Microsoft Visual C++에서 생성된 resource.h를 사용하여 맵 파일을 만듭니다.
echo // MAKEHELP.BAT에서 도움말 맵 파일을 생성합니다. 이 경우 구문은 [!output PROJECT_NAME].HPJ. >"hlp\[!output HM_FILE_OEM].hm"과 같은 형식을 사용합니다.
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // 명령 (ID_* and IDM_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // 프롬프트 (IDP_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // 리소스 (IDR_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // 대화 상자 (IDD_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // 프레임 컨트롤 (IDW_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
REM -- 프로젝트에 대한 도움말을 만듭니다. 이 경우 구문은 [!output PROJECT_NAME]과 같은 형식을 사용합니다.

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
