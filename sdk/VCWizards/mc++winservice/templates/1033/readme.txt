========================================================================
    APPLICATION : [!output PROJECT_NAME] Project Overview
========================================================================

Windows Service Wizard has created this [!output PROJECT_NAME] Application for you.  

This file contains a summary of what you will find in each of the files that
make up your [!output PROJECT_NAME] application.

[!output PROJECT_NAME].vcproj
    This is the main project file for VC++ projects generated using a Windows service Wizard. 
    It contains information about the version of Visual C++ that generated the file, and 
    information about the platforms, configurations.

[!output PROJECT_NAME]WinService.cpp
    This is the main application source file.

AssemblyInfo.cpp
	Contains custom attributes for modifying assembly metadata.

ProjectInstaller.cpp
	Contains the ProjectInstaller class used by installutil.exe

references.h
	Contains all the assemblies used by the project


/////////////////////////////////////////////////////////////////////////////
Other notes:

Windows Service Wizard uses "TODO:" to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////

To run your service:
	1. Build the project
	2. from the command line:
		[!output PROJECT_NAME].exe -Install
