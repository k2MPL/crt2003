@echo off
[!if HM_NOTE]

REM -- REMARQUE : DIFFERENCES ENTRE LES JEUX DE CARACTERES OEM ET ANSI 
REM -- De nombreux noms de fichiers ci-dessous s'affichent de mani�re incorrecte dans la 
REM -- plupart des �diteurs. Cela est d� au fait qu'ils doivent �tre au format du jeu de 
REM -- caract�res OEM, et non ANSI, pour que les fichiers de commandes 
REM -- puissent s'ex�cuter correctement. Les fen�tres d'�diteur et de sortie 
REM -- utilisent le jeu de caract�res ANSI. Les noms qui apparaissent uniquement dans la 
REM -- fen�tre de sortie demeurent au format du jeu de caract�res ANSI.

[!endif]
REM -- Cr�ez d'abord un fichier de mappage � partir du fichier resource.h g�n�r� par Microsoft Visual C++
echo // MAKEHELP.BAT fichier de mappage g�n�r� pour l'aide. Utilis� par [!output PROJECT_NAME].HPJ. >"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // Commandes (ID_* et IDM_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // Invites de commandes (IDP_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // Ressources (IDR_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // Bo�tes de dialogue (IDD_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // Contr�les frame (IDW_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
REM -- G�n�rez l'aide pour le projet [!output PROJECT_NAME]

echo G�n�ration des fichiers d'aide Win32
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
echo hlp\[!output PROJECT_NAME].hpj(1) : Erreur : Probl�me d�tect� lors de la cr�ation du fichier d'aide

:done
echo.
