 // (c) 2001 Microsoft Corporation
var vsViewKindPrimary                     = "{00000000-0000-0000-0000-000000000000}";
var vsViewKindDebugging                   = "{7651A700-06E5-11D1-8EBD-00A0C90F26EA}";
var vsViewKindCode                        = "{7651A701-06E5-11D1-8EBD-00A0C90F26EA}";
var vsViewKindDesigner                    = "{7651A702-06E5-11D1-8EBD-00A0C90F26EA}";
var vsViewKindTextView                    = "{7651A703-06E5-11D1-8EBD-00A0C90F26EA}";

var GUID_ItemType_PhysicalFolder		  = "{6BB5F8EF-4483-11D3-8BCF-00C04F8EC28C}";
var GUID_ItemType_VirtualFolder			  =	"{6BB5F8F0-4483-11D3-8BCF-00C04F8EC28C}";
var GUID_ItemType_PhysicalFile			  = "{6BB5F8EE-4483-11D3-8BCF-00C04F8EC28C}";

var GUID_Deployment_TemplatePath          = "{54435603-DBB4-11D2-8724-00A0C9A8B90C}";

var vsCMLanguageIDL = "{B5E9BD35-6D3E-4B5D-925E-8A43B79820B4}";
var vsCMLanguageVC = "{B5E9BD32-6D3E-4B5D-925E-8A43B79820B4}";


var gbExceptionThrown = false;

    var vsCMFunctionConstructor = 1;

	var vsCMAddPositionInvalid = -3;
	var vsCMAddPositionDefault = -2;
	var vsCMAddPositionEnd = -1;
	var vsCMAddPositionStart = 0;
//
	var vsCMAccessPublic = 1;
	var vsCMAccessDefault = 32;
//
	var vsCMWhereInvalid = -1;
	var vsCMWhereDefault = 0;
	var vsCMWhereDeclaration = 1;
	var vsCMWhereDefinition = 2;
//
	var vsCMPartName = 1;
	var vsCMPartAttributes = 2;
	var vsCMPartHeader = 4;
	var vsCMPartWhole = 8;
	var vsCMPartBody = 16;
	var vsCMPartNavigate = 32;
	//vsCMPartDelimiter = 64;
	var vsCMPartAttributesWithDelimiter = 68;
	var vsCMPartBodyWithDelimiter = 80;
	var vsCMPartHeaderWithAttributes = 6;
	var vsCMPartWholeWithAttributes = 10;
//
	var vsCMValidateFileExtNone = -1;
	var vsCMValidateFileExtCpp = 0;
	var vsCMValidateFileExtCppSource = 1;
	var vsCMValidateFileExtHtml = 2;
//
	var vsCMElementClass    = 1;
	var vsCMElementFunction = 2;
	var vsCMElementVariable = 3;
	var vsCMElementProperty = 4;
	var vsCMElementNamespace= 5;
	var vsCMElementInterface= 8;
	var vsCMElementStruct   = 11;	
	var vsCMElementUnion    = 12;
	var vsCMElementIDLCoClass=33;
	var vsCMElementVCBase   = 37;
//
	var einterfaceDual = 0;
	var einterfaceCustom = 1;
	var einterfaceDispinterface = 2;
//
	var eparamIn = 0;
	var eparamOut = 1;
	var eparamInOut = 2;
	var eparamOutRetval = 3;


// VS-specific HRESULT failure codes
//
	var OLE_E_PROMPTSAVECANCELLED = -2147221492;
	var VS_E_PROJECTALREADYEXISTS = -2147753952;
	var VS_E_PACKAGENOTLOADED = -2147753953;
	var VS_E_PROJECTNOTLOADED = -2147753954;
	var VS_E_SOLUTIONNOTOPEN = -2147753955;
	var VS_E_SOLUTIONALREADYOPEN = -2147753956;
	var VS_E_INCOMPATIBLEDOCDATA = -2147753962;
	var VS_E_UNSUPPORTEDFORMAT = -2147753963;
	var VS_E_WIZARDBACKBUTTONPRESS = -2147213313;
	var VS_E_WIZCANCEL = VS_E_WIZARDBACKBUTTONPRESS;

////////////////////////////////////////////////////////


/******************************************************************************
 Description: Sets the error info
  nErrNumber: Error code
  strErrDesc: Error description
******************************************************************************/
function SetErrorInfo(oErrorObj)
{
	var oWizard;
	try
	{
		oWizard = wizard;
	}
	catch(e)
	{
		oWizard = window.external;
	}

	try
	{
		var strErrorText = "";

		if(oErrorObj.description.length != 0)
		{
			strErrorText = oErrorObj.description;		
		}
		else
		{
			var strErrorDesc = GetRuntimeErrorDesc(oErrorObj.name);
			if (strErrorDesc.length != 0)
			{
				var L_strScriptRuntimeError_Text = " error occurred while running the script:\r\n\r\n";
				strErrorText = oErrorObj.name + L_strScriptRuntimeError_Text + strErrorDesc;
			}
		}

		oWizard.SetErrorInfo(strErrorText, oErrorObj.number & 0xFFFFFFFF);
	}
	catch(e)
	{
		var L_ErrSettingErrInfo_Text = "An error occurred while setting the error info.";
		oWizard.ReportError(L_ErrSettingErrInfo_Text);
	}
}


/******************************************************************************
         Description: Returns a description for the exception type given
 strRuntimeErrorName: The name of the type of exception occurred
 *****************************************************************************/
function GetRuntimeErrorDesc(strRuntimeErrorName)
{
	var L_strDesc_Text = "";
	switch(strRuntimeErrorName)
	{
		case "ConversionError":
			var L_ConversionError1_Text = "This error occurs whenever there is an attempt to convert";
			var L_ConversionError2_Text = "an object into something to which it cannot be converted.";
			L_strDesc_Text = L_ConversionError1_Text + "\r\n" + L_ConversionError2_Text;
			break;
		case "RangeError":
			var L_RangeError1_Text = "This error occurs when a function is supplied with an argument";
			var L_RangeError2_Text = "that has exceeded its allowable range. For example, this error occurs";
			var L_RangeError3_Text = "if you attempt to construct an Array object with a length that is not";
			var L_RangeError4_Text = "a valid positive integer.";
			L_strDesc_Text = L_RangeError1_Text + "\r\n" + L_RangeError2_Text + "\r\n" + L_RangeError3_Text + "\r\n" + L_RangeError4_Text;
			break;
		case "ReferenceError":
			var L_ReferenceError1_Text = "This error occurs when an invalid reference has been detected.";
			var L_ReferenceError2_Text = "This error will occur, for example, if an expected reference is null.";
			L_strDesc_Text = L_ReferenceError1_Text + "\r\n" + L_ReferenceError2_Text;
			break;
		case "RegExpError":
			var L_RegExpError1_Text = "This error occurs when a compilation error occurs with a regular";
			var L_RegExpError2_Text = "expression. Once the regular expression is compiled, however, this error";
			var L_RegExpError3_Text = "cannot occur. This example will occur, for example, when a regular";
			var L_RegExpError4_Text = "expression is declared with a pattern that has an invalid syntax, or flags";
			var L_RegExpError5_Text = "other than i, g, or m, or if it contains the same flag more than once.";
			L_strDesc_Text = L_RegExpError1_Text + "\r\n" + L_RegExpError2_Text + "\r\n" + L_RegExpError3_Text + "\r\n" + L_RegExpError4_Text + "\r\n" + L_RegExpError5_Text;
			break;
		case "SyntaxError":
			var L_SyntaxError1_Text = "This error occurs when source text is parsed and that source text does not";
			var L_SyntaxError2_Text = "follow correct syntax. This error will occur, for example, if the eval";
			var L_SyntaxError3_Text = "function is called with an argument that is not valid program text.";
			L_strDesc_Text = L_SyntaxError1_Text + "\r\n" + L_SyntaxError2_Text + "\r\n" + L_SyntaxError3_Text;
			break;
		case "TypeError":
			var L_TypeError1_Text = "This error occurs whenever the actual type of an operand does not match the";
			var L_TypeError2_Text = "expected type. An example of when this error occurs is a function call made on";
			var L_TypeError3_Text = "something that is not an object or does not support the call.";
			L_strDesc_Text = L_TypeError1_Text + "\r\n" + L_TypeError2_Text + "\r\n" + L_TypeError3_Text;
			break;
		case "URIError":
			var L_URIError1_Text = "This error occurs when an illegal Uniform Resource Indicator (URI) is detected.";
			var L_URIError2_Text = "For example, this is error occurs when an illegal character is found in a string";
			var L_URIError3_Text = "being encoded or decoded.";
			L_strDesc_Text = L_URIError1_Text + "\r\n" + L_URIError2_Text + "\r\n" + L_URIError3_Text;
			break;
		default:
			break;
	}
	return L_strDesc_Text;
}

/******************************************************************************
    Description: Creates a C++ project
 strProjectName: Project Name
 strProjectPath: The path that the project will be created in
******************************************************************************/
function CreateProject(strProjectName, strProjectPath)
{
	try
	{
		var strProjTemplatePath = wizard.FindSymbol("PROJECT_TEMPLATE_PATH");
		var strProjTemplate = strProjTemplatePath + "\\default.vcproj"; 

		var Solution = dte.Solution;
		var strSolutionName = "";
		if (wizard.FindSymbol("CLOSE_SOLUTION"))
		{
			Solution.Close();
			strSolutionName = wizard.FindSymbol("VS_SOLUTION_NAME");
			if (strSolutionName.length)
			{
				var strSolutionPath = strProjectPath.substr(0, strProjectPath.length - strProjectName.length);
				Solution.Create(strSolutionPath, strSolutionName);
			}
		}

		var strProjectNameWithExt = strProjectName + ".vcproj";
		var oTarget = wizard.FindSymbol("TARGET");
		var oProj;
		if (wizard.FindSymbol("WIZARD_TYPE") == vsWizardAddSubProject)  // vsWizardAddSubProject
		{
			var prjItem = oTarget.AddFromTemplate(strProjTemplate, strProjectPath + "\\" + strProjectNameWithExt);
			oProj = prjItem.SubProject;
		}
		else
		{
			oProj = oTarget.AddFromTemplate(strProjTemplate, strProjectPath, strProjectNameWithExt);
		}

		return oProj;
	}
	catch(e)
	{   
		throw e;
	}
}

function CreateManagedProject(strProjectName, strProjectPath)
{
	try
	{
		var strSafeProjectName = CreateSafeName(strProjectName);
		wizard.AddSymbol("SAFE_PROJECT_NAME", strSafeProjectName);
		wizard.AddSymbol("SAFE_NAMESPACE_NAME", CreateCPPName(strSafeProjectName));

		CopyNCBFileToSolutionDirectory(strProjectName, strProjectPath);
		var oProject = CreateProject(strProjectName, strProjectPath);
		SetupFilters(oProject);
		return oProject;
	}
	catch(e)
	{   
		throw e;
	}
}

/******************************************************************************
 Description: Adds source, include and resource filters for project folders.
              The symbols contain the file extensions to be used for filtering.
       oProj: Project object
******************************************************************************/
function SetupFilters(oProj)
{
	try
	{
	
		var L_strSource_Text = "Source Files";
		var group = oProj.Object.AddFilter(L_strSource_Text);
		group.Filter = "cpp;c;cxx;def;odl;idl;hpj;bat;asm;asmx";
		group.UniqueIdentifier = "{4FC737F1-C7A5-4376-A066-2A32D752A2FF}";

		var L_strHeader_Text = "Header Files";
		group = oProj.Object.AddFilter(L_strHeader_Text);
		group.Filter = "h;hpp;hxx;hm;inl;inc;xsd";
		group.UniqueIdentifier = "{93995380-89BD-4b04-88EB-625FBE52EBFB}";

		var L_strResources_Text = "Resource Files";
		group = oProj.Object.AddFilter(L_strResources_Text);
		group.Filter = "rc;ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe;resx";
		group.UniqueIdentifier = "{67DA6AB6-F800-4c08-8B7A-83BB121AAD01}";
	}
	catch(e)
	{   
		throw e;
	}
}


/******************************************************************************
 Description: Creates the Templates.inf file.
              Templates.inf is created based on TemplatesInf.txt and contains
			  a list of file names to be created by the wizard.
******************************************************************************/
function CreateInfFile()
{
	try
	{
		var oFSO, TemplatesFolder, TemplateFiles, strTemplate;
		oFSO = new ActiveXObject("Scripting.FileSystemObject");

		var TemporaryFolder = 2;
		var oFolder = oFSO.GetSpecialFolder(TemporaryFolder);

		var strTempFolder = oFSO.GetAbsolutePathName(oFolder.Path);
		var strWizTempFile = strTempFolder + "\\" + oFSO.GetTempName();

		var strTemplatePath = wizard.FindSymbol("TEMPLATES_PATH");
		var strInfFile = strTemplatePath + "\\Templates.inf";
		wizard.RenderTemplate(strInfFile, strWizTempFile);

		var oWizTempFile = oFSO.GetFile(strWizTempFile);
		return oWizTempFile;

	}
	catch(e)
	{   
		throw e;
	}
}


/******************************************************************************
 Description: Returns a unique file name
strDirectory: Directory to look for file name in
 strFileName: File name to check.  If unique, same file name is returned.  If 
              not unique, a number from 1-9999999 will be appended.  If not 
			  passed in, a unique file name is returned via GetTempName.
******************************************************************************/
function GetUniqueFileName(strDirectory, strFileName)
{
	try
	{
		oFSO = new ActiveXObject("Scripting.FileSystemObject");
		if (!strFileName)
			return oFSO.GetTempName();

		if (strDirectory.length && strDirectory.charAt(strDirectory.length-1) != "\\")
			strDirectory += "\\";

		var strFullPath = strDirectory + strFileName;
		var strName = strFileName.substring(0, strFileName.lastIndexOf("."));
		var strExt = strFileName.substr(strFileName.lastIndexOf("."));

		var nCntr = 0;
		while (oFSO.FileExists(strFullPath))
		{
			nCntr++;
			strFullPath = strDirectory + strName + nCntr + strExt;
		}
		if (nCntr)
			return strName + nCntr + strExt;
		else
			return strFileName;
	}
	catch(e)
	{   
		throw e;
	}
}

/******************************************************************************
    Description: Adds all the files to the project based on the 
	             Templates.inf file.
          oProj: Project object
 strProjectName: Project name
        InfFile: Templates.inf file object
******************************************************************************/
function AddFilesToProjectWithInfFile(oProj, strProjectName)
{
	try
	{
		var InfFile = CreateInfFile();
		AddFilesToProject(oProj, strProjectName, InfFile);
		InfFile.Delete();
	}
	catch(e)
	{   
		throw e;
	}
}

function AddFilesToNewProjectWithInfFile(oProj, strProjectName)
{
	try
	{
        AddFilesToProjectWithInfFile(oProj, strProjectName);
        SetCommonPchSettings(oProj);
	}
	catch(e)
	{   
		throw e;
	}
}


/******************************************************************************
    Description: Adds all the files to the project based on the 
	             Templates.inf file.
          oProj: Project object
 strProjectName: Project name
        InfFile: Templates.inf file object
******************************************************************************/
function AddFilesToProject(oProj, strProjectName, InfFile)
{
	try
	{
		var strTemplatePath;
		var strResPath;
		var strHelpPath;
		var strItemPath;
		try
		{
			strTemplatePath = wizard.FindSymbol("TEMPLATES_PATH");
			strResPath = wizard.FindSymbol("RES_PATH");
			strHelpPath = wizard.FindSymbol("HELP_PATH");
			strItemPath = wizard.FindSymbol("ITEM_PATH");
		}
		catch(e)
		{
			// OK if some of the symbols aren't there.
		}

		var strName;

		var strTextStream = InfFile.OpenAsTextStream(1, -2);
		var rgstrNames = new Array();
		var rgoFiles = new Array();
		var rgbOpenFiles = new Array();
		var nFiles;
		
		for (nFiles = 0; !strTextStream.AtEndOfStream; nFiles++)
		{
			var bCopyOnly = false;  //"true" will only copy the file from strTemplate to strTarget without rendering/adding to the project
			rgoFiles[nFiles] = null;			
			rgbOpenFiles[nFiles] = false;  //"true" will open the file when it's rendered
			var oParent = oProj; //by default, the file is added to the project

			var strName = strTextStream.ReadLine();
			
			var nSep = strName.indexOf("|")
			while(nSep >= 0)
			{
				var strAttrib = TrimStr(strName.substr(0, nSep-1));
				strName = strName.substr(nSep+1);
				nSep = strName.indexOf("|");
				if("CopyOnly"==strAttrib)
					bCopyOnly = true;
				else if("OpenFile"==strAttrib)
					rgbOpenFiles[nFiles] = true;
				else
				{
					if(strAttrib.substr(0, 7) == "ChildOf")
					{
						var posBegin = strAttrib.indexOf('(') + 1;
						var posEnd = strAttrib.lastIndexOf(')');
						var strParentFile = TrimStr(strAttrib.substr(posBegin, posEnd-posBegin));
						if(strParentFile)
						for(var cnt=0; cnt<nFiles; cnt++)
							if(rgstrNames[cnt]==strParentFile)
							{
								oParent = rgoFiles[cnt]; //this file will be added to the parent file
								break;
							}
					}
				}
			}
			//this code is for compatibility only with old 7.0 customized user wizards
			try
			{
				var bOpenFile = DoOpenFile(strName);
				if(bOpenFile)
					rgbOpenFiles[nFiles] = bOpenFile;
			}
			catch(e)
			{
			}
			//end of compatibility only code
			rgstrNames[nFiles] = TrimStr(strName);
			if (rgstrNames[nFiles] != "")
			{
				var strTarget = GetTargetName(rgstrNames[nFiles], strProjectName, strResPath, strHelpPath);
				var strTemplate = strTemplatePath + "\\" + rgstrNames[nFiles];
				var bHelpImages = false;
				if (strTarget == "")  // help images
				{
					bHelpImages = true;
					strTarget = strHelpPath + "\\Images\\" + rgstrNames[nFiles];
				}
				else if (strItemPath != null && strItemPath != "")
				{
					var oFSO = new ActiveXObject("Scripting.FileSystemObject");
					if (oFSO.GetDriveName(strTarget) == "")
					{
						// If the target drive can not be determined, it must be a relative path, so 
						// add on the item path.
						strTarget = strItemPath + "\\" + strTarget;
					}
				}
				
				wizard.RenderTemplate(strTemplate, strTarget, bCopyOnly, true);
			
				if(bHelpImages)
				{
					continue;
				}
				var projfile = oProj.Object.Files(strTarget);
				if (projfile != null)
					projfile = projfile.Object;
				else
				{
					projfile = oParent.ProjectItems.AddFromFile(strTarget);
				}
				rgoFiles[nFiles] = projfile;

				if(projfile)
				{
					SetFileProperties(projfile, rgstrNames[nFiles]);
				}
			}
		}
		
		// Only open files after all files have been added to the project.
		//
		
		for (var iFileToOpen = 0; iFileToOpen < nFiles; iFileToOpen++)
		{
			var oFileToOpen = rgoFiles[iFileToOpen];
			if(oFileToOpen==null || !rgbOpenFiles[iFileToOpen])
				continue;
			var vsViewKind = vsViewKindPrimary;
			
			switch (oFileToOpen.Object.FileType)
			{
			case eFileTypeCppForm :
			case eFileTypeCppClass :
			case eFileTypeCppControl :
			case eFileTypeCppWebService :
				vsViewKind = vsViewKindDesigner;
			}
			
			var window = oFileToOpen.Open(vsViewKind);
			
			if (window)
			{
				window.visible = true;
			}
		}

		strTextStream.Close();
		
	}
	catch(e)
	{   
		strTextStream.Close();
		throw e;
	}
}


/******************************************************************************
    Description: Adds the default configurations to the project.
          oProj: Project object
 strProjectName: Project name
******************************************************************************/


function AddCommonConfig(oProj, strProjectName)
{
	try
	{
		var config = oProj.Object.Configurations("Debug");
		config.IntermediateDirectory = "Debug";
		config.OutputDirectory = "Debug";

		var CLTool = config.Tools("VCCLCompilerTool");
		CLTool.UsePrecompiledHeader = pchUseUsingSpecific;
		CLTool.WarningLevel = warningLevel_3;
		CLTool.MinimalRebuild = true;
		CLTool.DebugInformationFormat = debugEditAndContinue;
		CLTool.Optimization = optimizeDisabled;
		CLTool.BasicRuntimeChecks = runtimeBasicCheckAll;
		CLTool.Detect64BitPortabilityProblems = true;

		var LinkTool = config.Tools("VCLinkerTool");
		LinkTool.SubSystem = subSystemWindows;
		LinkTool.TargetMachine = machineX86;
		LinkTool.GenerateDebugInformation = true;

		config = oProj.Object.Configurations("Release");
		config.IntermediateDirectory = "Release";
		config.OutputDirectory = "Release";

		CLTool = config.Tools("VCCLCompilerTool");
		CLTool.WarningLevel = warningLevel_3;
		CLTool.UsePrecompiledHeader = pchUseUsingSpecific;
		CLTool.Detect64BitPortabilityProblems = true;
		CLTool.DebugInformationFormat = debugEnabled;

		LinkTool = config.Tools("VCLinkerTool");
		LinkTool.SubSystem = subSystemWindows;
		LinkTool.TargetMachine = machineX86;
		LinkTool.GenerateDebugInformation = true;
		LinkTool.EnableCOMDATFolding = optFolding;
		LinkTool.OptimizeReferences = optReferences;

	}
	catch(e)
	{   
		throw e;
	}
}

/******************************************************************************
 Description: Sets up the pre-compiled header for the project.
       oProj: Project object
******************************************************************************/
function SetCommonPchSettings(oProj)
{
	try
	{
		// setup /Yu (using precompiled headers)
		var configs = oProj.Object.Configurations;
		config = configs("Debug");

		var CLTool = config.Tools("VCCLCompilerTool");
		CLTool.UsePrecompiledHeader = pchUseUsingSpecific;
		config = configs("Release");

		var CLTool = config.Tools("VCCLCompilerTool");
		CLTool.UsePrecompiledHeader = pchUseUsingSpecific;

		// setup /Yc (create precompiled header)
		var files = oProj.Object.Files;
		var strFile = wizard.FindSymbol("PCH_FILE");
		if(null != strFile)
			file = files(strFile);
		else
			file = files("StdAfx.cpp");
		if(!file)
			return;
		config = file.FileConfigurations("Debug");
		config.Tool.UsePrecompiledHeader = pchCreateUsingSpecific;

		config = file.FileConfigurations("Release");
		config.Tool.UsePrecompiledHeader = pchCreateUsingSpecific;
	}
	catch(e)
	{   
		throw e;
	}
}

/******************************************************************************
 Description: Sets up the project config properties when no pre-compiled
              header is used.
       oProj: Project object
******************************************************************************/
function SetNoPchSettings(oProj)
{
	try
	{
		var config = oProj.Object.Configurations("Debug");
		var CLTool = config.Tools("VCCLCompilerTool");
		CLTool.UsePrecompiledHeader = pchNone;

		var config = oProj.Object.Configurations("Release");
		var CLTool = config.Tools("VCCLCompilerTool");
		CLTool.UsePrecompiledHeader = pchNone;
	}
	catch(e)
	{   
		throw e;
	}
}

/******************************************************************************
 Description: Deletes the file given
        oFSO: File System Object
     strFile: Name of the file to be deleted
******************************************************************************/
function DeleteFile(oFSO, strFile)
{
	try
	{
		if (oFSO.FileExists(strFile))
		{
			var oFile = oFSO.GetFile(strFile);
			oFile.Delete();
		}
	}
	catch(e)
	{   
		throw e;
	}
}

/******************************************************************************
    Description: Renders a template file and optionally adds it to the project
strTemplateFile: Template file name only (excluding path, relative to TEMPLATES_PATH)
 strProjectFile: Name of new file created (may include path, but relative to PROJECT_PATH)
   oProjToAddTo: Project object, if the created file needs to be added to it
                 (skip it or pass false if not adding the file to the project)
          bOpen: If true, open the file in the fdefault editor, after adding 
                 it to the project.
******************************************************************************/
function RenderAddTemplate(strTemplateFile, strProjectFile, oProjToAddTo, bOpen)
{
	var oWizard;
	try
	{
		oWizard = wizard;
	}
	catch(e)
	{
		oWizard = window.external;
	}

	try
	{
		var strTemplatePath	= oWizard.FindSymbol("TEMPLATES_PATH");
		if ("\\" != strTemplatePath.charAt(strTemplatePath.length-1))
			strTemplatePath += "\\";

		strTemplateFile = strTemplatePath + strTemplateFile;

		oWizard.RenderTemplate(strTemplateFile, strProjectFile, false, false);
		if (oProjToAddTo)
		{
			AddFileToProject(strProjectFile, oProjToAddTo, bOpen)		
		}
	}
	catch(e)
	{
		throw e
	}
}

/******************************************************************************
    Description: Add file to the project
 strProjectFile: Name of the file to be added
   oProjToAddTo: Project object
          bOpen: If true, open the file in the fdefault editor, after adding 
                 it to the project.
******************************************************************************/
function AddFileToProject(strProjectFile, oProjToAddTo, bOpen)
{
	try
	{
		var projfile;
		var oFiles = oProjToAddTo.Object.Files;
		var oFile = oFiles(strProjectFile);
		if (oFile != null)
			projfile = oFile.Object;
		else
			projfile = oProjToAddTo.ProjectItems.AddFromFile(strProjectFile);

		if(bOpen && projfile != null)
		{
			var window = projfile.Open(vsViewKindPrimary);
			if( window )
				window.visible = true;
		}
	}
	catch(e)
	{
		throw e
	}
}

/******************************************************************************
     Description: Renders and inserts a template file that contains an interface
                  into the project's IDL file
			 oCM: Code Model object
strInterfaceFile: Template file name only (excluding path)
******************************************************************************/
function AddInterfaceFromFile(oCM, strInterfaceFile)
{
	try
	{
		var strTemplateFile	= wizard.FindSymbol("TEMPLATES_PATH") + "\\" + strInterfaceFile;
		var strInsertText = wizard.RenderTemplateToString(strTemplateFile);
		oCM.IDLLibraries(1).StartPoint.CreateEditPoint().Insert(strInsertText);
		oCM.Synchronize();
	}
	catch(e)
	{   
		throw e;
	}
}

/******************************************************************************
   Description: Renders and inserts a template file that contains a coclass
                into the project's IDL file
           oCM: Code Model object
strCoclassFile: Template file name only (excluding path)
******************************************************************************/
function AddCoclassFromFile(oCM, strCoclassFile)
{
	try
	{
		var strTemplateFile	= wizard.FindSymbol("TEMPLATES_PATH") + "\\" + strCoclassFile;
		var strInsertText = wizard.RenderTemplateToString(strTemplateFile);
		oCM.IDLLibraries(1).EndPointOf(vsCMPartBody, vsCMWhereDefinition).CreateEditPoint().Insert(strInsertText);
		oCM.Synchronize();
	}
	catch(e)
	{   
		throw e;
	}
}

/******************************************************************************
        Description: Returns a boolean indicating whether a #include exists in a file
		      oProj: Project object
      strHeaderFile: #include to search for
  strInsertIntoFile: Source file that contains the #include (excluding the path)
******************************************************************************/
function DoesIncludeExist(oProj, strHeaderFile, strInsertIntoFile)
{
	try
	{
		var oProjectItem = oProj.Object.Files(strInsertIntoFile).Object;
		var oIncludes = oProjectItem.FileCodeModel.Includes;
		if(oIncludes.Find(strHeaderFile)!=null)
			return true;
		return false;
	}
	catch(e)
	{   
		throw e;
	}
}


/******************************************************************************
Description: Returns the highest dispid from members of the given interface & 
             all its bases
  oInterface: Interface object
******************************************************************************/
function GetMaxID(oInterface)
{
	var currentMax = 0;
	try
	{
		var funcs = oInterface.Functions;
		if(funcs!=null)
		{
			var nTotal = funcs.Count;
			var nCntr;
			for (nCntr = 1; nCntr <= nTotal; nCntr++)
			{
				var id = funcs(nCntr).Attributes.Find("id");
				if(id!=null)
				{
					var idval = parseInt(id.Value);
					if(idval>currentMax)
						currentMax = idval;
				}
			}
		}
//REMOVE remove this and use Children collection above, if it's implemented
		funcs = oInterface.Variables;
		if(funcs!=null)
		{
			var nTotal = funcs.Count;
			var nCntr;
			for (nCntr = 1; nCntr <= nTotal; nCntr++)
			{
				var id = funcs(nCntr).Attributes.Find("id");
				if(id!=null)
				{
					var idval = parseInt(id.Value);
					if(idval>currentMax)
						currentMax = idval;
				}
			}
		}
		var nextBases = oInterface.Bases;
		var nTotal = nextBases.Count;
		var nCntr;
		for (nCntr = 1; nCntr <= nTotal; nCntr++)
		{
			var nextObject = nextBases(nCntr).Class;
			if(nextObject!=null && nextObject.Name != "IDispatch")
			{
				var idval = GetMaxID(nextObject);
				if(idval>currentMax)
						currentMax = idval;
			}
		}
		return currentMax;
	}
	catch(e)
	{   
		throw e;
	}
}


/******************************************************************************
     Description: Checks if a project is MFC-based.
	       oProj: Project object
bCWinAppRequired: Flag indicating whether Extension DLLs are included in check
******************************************************************************/
function IsMFCProject(oProj, bCWinAppRequired)
{
	try
	{
		var oCM = oProj.CodeModel;
		
		// look for class derived from CWinApp
		var oClasses = oCM.Classes;
		for (var nCntr = 1; nCntr <= oClasses.Count; nCntr++)
		{
			var oClass = oClasses(nCntr);
			if (oClass.IsDerivedFrom("CWinApp"))
			{
				// one global variable must be of this class type
				var oVariables = oCM.Variables;
				for (var nCntr2 = 1; nCntr2 <= oVariables.Count; nCntr2++)
				{
					if (oVariables(nCntr2).TypeString == oClass.Name)
						return true;
				}
			}
		}

		if (!bCWinAppRequired)
		{
			// check if MFC Extension DLL
			if (2 == oProj.Object.Configurations(1).ConfigurationType)
			{
				var oVariables = oCM.Variables;
				for (var nCntr = 1; nCntr <= oVariables.Count; nCntr++)
				{
					if (oVariables(nCntr).TypeString == "AFX_EXTENSION_MODULE")
						return true;
				}
			}
			
			// check if Win32 app with MFC support
			var oVariables = oCM.Variables;
			for (var nCntr2 = 1; nCntr2 <= oVariables.Count; nCntr2++)
			{
				if (oVariables(nCntr2).TypeString == "CWinApp")
					return true;
			}
		}

		// not MFC project
		return false;
	}
	catch(e)
	{   
		throw e;
	}
}

/********************************************************************************
	Description:	Returns a boolean indicating whether ATL support can be added
					to the project.
		selProj:	Selected project
********************************************************************************/
function CanAddATLSupport(selProj)
{
	try
	{
		if (IsATLProject(selProj))
		{
			var L_ErrMsg1_Text = "Current project already has ATL support.";
			wizard.ReportError(L_ErrMsg1_Text);
			return false;
		}
		// check if MFC app
		if (!IsMFCProject(selProj, true))
		{
			var L_ErrMsg2_Text = "ATL support can only be added to MFC Exes or MFC Regular DLLs.";
			wizard.ReportError(L_ErrMsg2_Text);
			return false;
		}

		return AddATLSupportToProject(selProj);
	}
	catch(e)
	{
		if (e.description.length != 0)
			SetErrorInfo(e);
		return e.number
	}
}

/******************************************************************************
 Description: Returns a boolean indicating whether the project supports both
              attributed and non-attributed ATL objects.
******************************************************************************/
function CanAddNonAttributed()
{
	try
	{
		var oProj = window.external.ProjectObject;
		// check for IDL file
		var bIDL = false;
		var oFiles = oProj.Object.Files;
		for (var nCntr = 1; nCntr <= oFiles.Count; nCntr++)
		{
			var strFileName = oFiles(nCntr).Name.toUpperCase();
			var nPos = strFileName.lastIndexOf(".");
			if (nPos>0 && strFileName.substr(nPos) == ".IDL")
			{
				bIDL = true;
				return true;
			}
		}
		return false;
	}
	catch(e)
	{   
		throw e;
	}
}

/******************************************************************************
 Description: Returns a boolean indicating whether a project is attributed or not.
     oWizard: Wizard object
******************************************************************************/
function IsAttributedProject(oWizard)
{
	try
	{
		var oCM = oWizard.ProjectObject.CodeModel;
		
		// check for a global module attribute
		if (oCM.Attributes.Find("module"))
			return true;
			
		// check for a module attribute applied to a class
		var oClasses = oCM.Classes;
		for (var nCntr = 1; nCntr <= oClasses.Count; nCntr++)
		{
			var oClass = oClasses(nCntr);
			if (oClass.Attributes.Find("module"))
				return true;
		}

		return false;
	}
	catch(e)
	{   
		throw e;
	}
}


/******************************************************************************
 Description: Add symbols used by MC++ Wizards
******************************************************************************/
function PrepareToAddManagedClass(oProject)
{
	try
	{
		if (!IsMCppProject(oProject))
		{
			return false;
		}

		// First get a safe class name from the item name
		var strItemName = wizard.FindSymbol("ITEM_NAME");
		
		// Since item name is a file name for us, strip off the extension
		var iDotPos = strItemName.lastIndexOf('.');
		if (iDotPos != -1)
		{
			strItemName = strItemName.substr(0, iDotPos);
		}

		wizard.AddSymbol("ITEM_NAME", GetFileNameUniqueCPPandH(strItemName));
		
		// First, generate a safe version of project and namespace name
		var strProjectName = wizard.FindSymbol("PROJECT_NAME");
		var strSafeProjectName = CreateSafeName(strProjectName);
		wizard.AddSymbol("SAFE_PROJECT_NAME", strSafeProjectName);
		var strNamespaceName = CreateCPPName(strSafeProjectName);
		wizard.AddSymbol("SAFE_NAMESPACE_NAME", strNamespaceName);

		//Then, generate the unique name for the claaa within the namespace	based on strItemName
		var strClassName = CreateSafeName(strItemName);

		if (!wizard.ValidateCLRIdentifier(strClassName))
		{
			wizard.ReportError();
			return false;
		}
		wizard.AddSymbol("SAFE_ITEM_NAME", GetClassNameUnique(oProject, strNamespaceName, strClassName));
				
		// Then, get the name of the precompiled header, if any.
		var strHeader = GetProjectFile(oProject, "STDAFX", false, false);
		wizard.AddSymbol("PCH_NAME", strHeader);
		wizard.AddSymbol("PCH", strHeader != "");
		
		return true;
	}
	catch(e)
	{   
		throw e;
	}
}

/******************************************************************************
 Description: Generates a C++ friendly name
     strName: The old, unfriendly name
******************************************************************************/
function CreateSafeName(strName)
{
	try
	{
		var nLen = strName.length;
		var bFirst = true;
		var strSafeName = "";
		
		for (nCntr = 0; nCntr < nLen; nCntr++)
		{
			var cChar = strName.charAt(nCntr);
			if ((cChar >= 'A' && cChar <= 'Z') || (cChar >= 'a' && cChar <= 'z'))
			{
				// valid character, so add it
				strSafeName += cChar;
				bFirst = false;
			} 
			else if (((cChar == '_') || (cChar >= '0' && cChar <= '9')) && !bFirst)
			{
				// don't allow "_0-9" to be the first char
				strSafeName += cChar;
			}
			// otherwize, we skip it
		}
		if (strSafeName=="")
		{
			// if it's empty, we add My
			strSafeName = "My";
		}
		else if (strSafeName.charAt(0) >= '0' && strSafeName.charAt(0) <= '9')
		{
			// if it starts with a digit, we prepend My
			strSafeName = "My" + strSafeName;
		}
		return strSafeName;
	}
	catch(e)
	{   
		throw e;
	}
}

/******************************************************************************
 Description: Generates a valid C++ identifier name (by appending a number to
 an identifier strSafeName, if it's disallowed (keyword or reserver word)
******************************************************************************/
function CreateCPPName(strSafeName)
{
	try
	{
		var nCnt = 0;
		var strCheck = strSafeName;
		var oLangSvc = wizard.dte.VCLanguageManager;
		while (!oLangSvc.ValidateIdentifier(strCheck)
		|| oLangSvc.IsReservedName(strCheck, true))
		{
			nCnt++;
			strCheck = strSafeName + nCnt.toString();
		}
		
		return strCheck;

	}
	catch(e)
	{   
		throw e;
	}
}

/******************************************************************************
 Description: Returns a boolean indicating whether project is ATL-based.
       oProj: Project object
******************************************************************************/
function IsATLProject(oProj)
{
	try
	{
		var oCM = oProj.CodeModel;
		// look for global variable derived from CAtlModuleT
		var oVariables = oCM.Variables;
		for (var nCntr = 1; nCntr <= oVariables.Count; nCntr++)
		{
			var oVariable = oVariables(nCntr);
			var oType = oVariable.Type;
			var strTypeString = oType.TypeString;
			
			if (strTypeString == "CComModule" || strTypeString == "CAutoThreadModule")
				return true;
			
			var oCodeType = oType.CodeType;
			if (oCodeType && oCodeType.IsDerivedFrom("CAtlModuleT"))
				return true;
		}

		// check for [module] attribute
		if (oCM.Attributes.Find("module"))
			return true;

		if (!oProj.Object.Files("resource.h"))
			return false;
			
		// check for a module attribute applied to a class
		var oClasses = oCM.Classes;
		for (var nCntr = 1; nCntr <= oClasses.Count; nCntr++)
		{
			var oClass = oClasses(nCntr);
			if (oClass.Attributes.Find("module"))
				return true;
		}
		
		return false;
	}
	catch(e)
	{   
		throw e;
	}
}

/******************************************************************************
Description: Returns the file name of per project type of files (RC, IDL, etc.)
      oProj: selected project
    strType: Type of file - STDAFX, RC, IDL, CPP, H, ODL, DEF
  bFullPath: Flag indicating whether to return the full path name.
       bMFC: if strtype == "CPP" or "H", indicates if the project is MFC-base,
             otherwise we assume ATL
******************************************************************************/
function GetProjectFile(oProj, strType, bFullPath, bMFC)
{
	try
	{
		var oFiles = oProj.Object.Files;
		var strFileName = "";

		switch (strType)
		{
			case "RC":
			case "IDL":
			case "ODL":
			case "DEF":
				for (var nCntr = 1; nCntr <= oFiles.Count; nCntr++)
				{
					var oFile = oFiles(nCntr);
					if (-1 != oFile.Name.toUpperCase().indexOf("." + strType))
					{
						if (false == oFile.FileConfigurations(1).ExcludedFromBuild)
						{
							strFileName = oFile.Name;
							break;
						}
					}
				}
				break;

			case "STDAFX":
				// look for name of precompiled header
				var strPrecompiledHeader = oProj.Object.Configurations(1).Tools("VCCLCompilerTool").PrecompiledHeaderThrough;
				if (strPrecompiledHeader.length)
					strFileName = strPrecompiledHeader;
				// if not found look for stdafx.h
				else
					strFileName = "stdafx.h";
				break;

			case "CPP":
			case "H":
				var oCM = oProj.CodeModel;
				if (bMFC)
				{
					var oClasses = oCM.Classes;
					for (var nCntr = 1; nCntr <= oClasses.Count; nCntr++)
					{
						// look for class derived from CWinApp
						if (oClasses(nCntr).IsDerivedFrom("CWinApp"))
						{
							if (strType == "H")
								strFileName = oClasses(nCntr).Location(vsCMWhereDefault);
							// strType == "CPP"
							else
							{
								var oVariables = oCM.Variables;
								for (var nCntr2 = 1; nCntr2 <= oVariables.Count; nCntr2++)
								{
									if (oVariables(nCntr2).TypeString == oClasses(nCntr).Name)
										strFileName = oVariables(nCntr2).Location(vsCMWhereDefault);
								}
							}
							break;
						}
					}
				}
				else
				{
					var oVarOrAttrib = false;
					// look for global variable derived from CAtlModuleT
					var oVariables = oCM.Variables;
					for (var nCntr = 1; nCntr <= oVariables.Count; nCntr++)
					{
						var strTypeString = oVariables(nCntr).TypeString;
						if (strTypeString == "CComModule" || strTypeString == "CAutoThreadModule")
							oVarOrAttrib = oVariables(nCntr);
						else
						{
							var oClass = oCM.Classes.Find(strTypeString)
							if (oClass)
							{
								if (oClass.IsDerivedFrom("CAtlModuleT"))
								{
									oVarOrAttrib = oVariables(nCntr);
									break;
								}
							}
						}
					}

					// check for [module] attribute
					if (!oVarOrAttrib)
						oVarOrAttrib = oCM.Attributes.Find("module");
			
					// check for a module attribute applied to a class
					if (!oVarOrAttrib)
					{
						var oClasses = oCM.Classes;
						for (var nCntr = 1; nCntr <= oClasses.Count; nCntr++)
						{
							var oClass = oClasses(nCntr);
							var oModule = oClass.Attributes.Find("module");
							if (oModule)
							{
								oVarOrAttrib = oModule;
								break;
							}
						}
					}

					if (oVarOrAttrib)
					{
						if (strType == "CPP")
							strFileName = oVarOrAttrib.Location(vsCMWhereDefault);
						// strType == "H"
						else
						{
							var strTemp = oVarOrAttrib.Location(vsCMWhereDefault);
							strFileName = strTemp.substring(0, strTemp.indexOf(".")) + ".h";
						}
					}
				}
				break;
		}

		// remove path
		if (-1 != strFileName.indexOf("\\"))
			strFileName = strFileName.substr(strFileName.lastIndexOf("\\") + 1);

		if (strFileName.length == 0 || !oFiles(strFileName))
		{
			if (strType == "STDAFX")
				return "";

			// try finding projectname.strType
			var strNewFileName = oProj.Name + "." + strType;
			if (strFileName != strNewFileName)
			{
				if (oFiles(strNewFileName))
					strFileName = strNewFileName;
				else
					return "";
			}
			else
				return "";
		}

		if (bFullPath)
			return oFiles(strFileName).FullPath;
		else
			return strFileName;
	}
	catch(e)
	{   
		throw e;
	}
}

/******************************************************************************
 Description: Called from the wizards html script when 'Finish' is clicked. This
              function in turn calls the wizard control's Finish().
    document: HTML document object
******************************************************************************/
function OnWizFinish(document)
{
	document.body.style.cursor='wait';
	try
	{
		window.external.Finish(document, "ok"); 
	}
	catch(e)
	{
		document.body.style.cursor='default';
		if (e.description.length != 0)
			SetErrorInfo(e);
		return e.number;
	}
}

/******************************************************************************
 Description: Converts an ATL project to attributed
******************************************************************************/
function ConvertProjectToAttributed()
{
	try
	{
		var oWizard;
		try
		{
			oWizard = wizard;
		}
		catch(e)
		{
			oWizard = window.external;
		}
		var oProj = oWizard.ProjectObject;
		var oCM = oProj.CodeModel;

		try
		{
			var L_TRANSACTION1_Text = "Convert Project To Attributed";
			oCM.StartTransaction(L_TRANSACTION1_Text);
			
			var strType;
			var bDLL = false;
			var typeDynamicLibrary = 2;
			if (typeDynamicLibrary == oProj.Object.Configurations(1).ConfigurationType)
			{
				bDLL = true;
				strType = "dll";
			}
			else
				bDLL = false;

			var bMFC = IsMFCProject(oProj, true);
			if (bMFC)
				 strType = "unspecified";

			if (!IsAttributedProject(oWizard))
			{
				var L_PART1_Text = "To insert an attributed object, your project must be converted to an attributed project.";
				var strPrompt = L_PART1_Text;
				if (bDLL && !bMFC)
				{
					var L_PART2_Text = "  All exported functions, including DllMain will be commented out.";
					strPrompt += L_PART2_Text;
				}
				var L_PART3_Text = "  Do you wish to continue?";
				strPrompt += L_PART3_Text;
				if (!oWizard.YesNoAlert(strPrompt))
				{
					oCM.AbortTransaction();
					return false;
				}
			}	
			else
			{
				oCM.AbortTransaction();
				return true;
			}
			if (!bMFC)
			{
				// look for global variable derived from CAtlModuleT
				var oVariables = oCM.Variables;
				for (var nCntr = 1; nCntr <= oVariables.Count; nCntr++)
				{
					var strTypeString = oVariables(nCntr).TypeString;
					if (strTypeString == "CComModule" || strTypeString == "CAutoThreadModule")
					{
						if (!bDLL)
						{
							if (strTypeString == "CServiceModule")
								strType = "service";
							else
								strType = "exe";
						}
						//Comment out global Module
						oCM.Remove(oVariables(nCntr).Name);
						break;
					}
					else
					{
						var oClass = oCM.Classes.Find(strTypeString)
						if (oClass)
						{
							if (oClass.IsDerivedFrom("CAtlModuleT"))
							{
								var oModule = oVariables(nCntr);
								if (!bDLL)
								{
									if (oClass.IsDerivedFrom("CAtlServiceModuleT"))
										strType = "service";
									else
										strType = "exe";
								}

								//Comment out class
								oCM.Remove(oClass.Name);

								//Comment out global Module
								oCM.Remove(oModule.Name);
								break;
							}
						}
					}
				}

				if (bDLL)
				{
					// delete DEF file
					var strDefFile = GetProjectFile(oProj, "DEF", false);
					if (strDefFile.length)
					{
						var oFile = oProj.Object.Files(strDefFile);
						oProj.Object.RemoveFile(oFile);
					}
					// Comment out exported functions
					oCM.Remove("DllMain");
					oCM.Remove("DllCanUnloadNow");
					oCM.Remove("DllGetClassObject");
					oCM.Remove("DllRegisterServer");
					oCM.Remove("DllUnregisterServer");

				}
				else
				{
					// Comment out WinMain
					oCM.Remove("_tWinMain");
				}
			}

			// Add module attribute to projectname.cpp
			// [ module(dll, uuid = "{406877CF-6568-11D3-BC62-00C04F990181}", name = "ATLFOO", helpstring = "atlfoo 1.0 Type Library") ];

			var strProjectCPP = GetProjectFile(oProj, "CPP");
			var oAttribute = oCM.AddAttribute("module", strProjectCPP, strType, vsCMAddPositionEnd);
			if (oCM.IDLLibraries.Count)
			{
				var oUUID = oCM.IDLLibraries(1).Attributes.Find("uuid");
				if (oUUID)
				{
					var strUUID = oUUID.Value;
					oAttribute.AddParameter("uuid", '"{' + strUUID + '}"', vsCMAddPositionEnd);
				}
				if (strType == "service")
					oAttribute.AddParameter("resource_name", '"IDS_SERVICENAME"', vsCMAddPositionEnd);
				var oHelpString = oCM.IDLLibraries(1).Attributes.Find("helpstring");
				if (oHelpString)
				{
					var strHelpString = oHelpString.Value;
					oAttribute.AddParameter("helpstring", strHelpString, vsCMAddPositionEnd);
				}
			}
			oAttribute.AddParameter("name", '"' + CreateSafeName(oProj.Name) + 'Lib"', vsCMAddPositionEnd);

			var strProjectIDL = GetProjectFile(oProj, "IDL");
			// Add to the end of stdafx.h - [ importidl(projectname.idl) ];
			if (strProjectIDL.length)
				oAttribute = oCM.AddAttribute("importidl", GetProjectFile(oProj, "STDAFX"), strProjectIDL, vsCMAddPositionEnd);

			// add _ATL_ATTRIBUTES
			var nTotal = oProj.Object.Configurations.Count;
			for (var nCntr = 1; nCntr <= nTotal; nCntr++)
			{
				var oConfig = oProj.Object.Configurations(nCntr);
				var VCCLTool = oConfig.Tools("VCCLCompilerTool");
				if (-1 == VCCLTool.PreprocessorDefinitions.search("_ATL_ATTRIBUTES"))
					VCCLTool.PreprocessorDefinitions += ";_ATL_ATTRIBUTES";

				// add /idlout:_projectname.idl
				var LinkTool = oConfig.Tools("VCLinkerTool");
				LinkTool.MergedIDLBaseFileName = "_" + strProjectIDL;
				if (bDLL && !bMFC)
					LinkTool.ModuleDefinitionFile = "";
			}

			// comment out: 1 TYPELIB "projectname.tlb"
			if (strProjectIDL.length)
			{
				var strProjectRC = GetProjectFile(oProj, "RC", true);
				var oResHelper = oWizard.ResourceHelper;
				oResHelper.OpenResourceFile(strProjectRC);
				var strCompDir = oResHelper.CompileDirectives;
				var nPos = strCompDir.indexOf(" TYPELIB ");
				while (nPos != -1)
				{
					strCompDir = strCompDir.substr(0, nPos-1) + "// " + strCompDir.substr(nPos-1);
					nPos = strCompDir.indexOf(" TYPELIB ", nPos+9);
				}

				oResHelper.CompileDirectives = strCompDir;
				oResHelper.CloseResourceFile();
			}

			oCM.CommitTransaction();
			return true;
		}
		catch(e)
		{   
			var L_ErrMsg13_Text = "Error in ConvertProjectToAttributed: ";
			oWizard.ReportError(L_ErrMsg13_Text + e.description);

			oCM.AbortTransaction();
			return false;
		}
	}
	catch(e)
	{   
		throw e;
	}
}

/******************************************************************************
 Description: Returns the type of interface (e.g. custom, dual, dispinterface, 
              oleautomation)
  oInterface: VCCodeInterface object
******************************************************************************/
function GetInterfaceType(oInterface)
{
	try
	{
		if (-1 != oInterface.DeclarationText.search("dispinterface " + oInterface.Name))
			return "dispinterface";

		var oAttributes = oInterface.Attributes;
		for (var nCntr = 1; nCntr <= oAttributes.Count; nCntr++)
		{
			if (oAttributes(nCntr).Name == "dual")
				return "dual";
			else if (oAttributes(nCntr).Name == "oleautomation")
				return "oleautomation";
			else if (oAttributes(nCntr).Name == "dispinterface")
				return "dispinterface";
		}
		return "custom";
	}
	catch(e)
	{   
		throw e;
	}
}

/******************************************************************************
 Description: Returns the VCCodeClass objects associated with an interface
strInterface: Name of interface
 colElements: CEs we are looking for (Classes/Structs, Namespacees, and recursive members)
  aryClasses: Array of class objects (in/out param)
        bAll: if false, then the search stops at the first matching class found (length of aryClasses can grow by 1 only)
     RETURNS: true if any associated class found (length of aryClasses grew), false otherwise
******************************************************************************/
function GetInterfaceClass(strInterface, colElements, aryClasses, bAll)
{
	try
	{
		var strIID;
		if (strInterface.charAt(0) == '_')
			strIID = "IID" + strInterface;
		else
			strIID = "IID_" + strInterface;
		var originalSize = aryClasses.length;
		var nIndex = originalSize;
		var bMFC = false;
		var bATL = false;
		var nCntr;
		//first, look the classes - direct children of the parent
		for (nCntr = 1; nCntr <= colElements.Count; nCntr++)
		{
			var oClass = colElements(nCntr);
			if(oClass.Kind!=vsCMElementClass && oClass.Kind!=vsCMElementStruct)
				continue;
			if (!bMFC)
			{
				if (oClass.IsDerivedFrom(strInterface))
				{
					aryClasses[nIndex++] = oClass;
					if(!bAll)
						return true;
					bATL = true;
				}
				else if (oClass.IsDerivedFrom("CStockPropImpl"))
				{
					var oBases = oClass.Bases;
					var strCompare = "CStockPropImpl<" + oClass.Name + "," + strInterface + ">";
					for (var nCntr2 = 1; nCntr2 <= oBases.Count; nCntr2++)
					{
						var strBaseName = oBases(nCntr2).DisplayName;
						if (strCompare == strBaseName.substring(0, strCompare.length))
						{
							aryClasses[nIndex++] = oClass;
							if(!bAll)
								return true;
							bATL = true;
							break;
						}
					}
				}
				else if (oClass.IsDerivedFrom("IDispatchImpl"))
				{
					var oBases = oClass.Bases;
					var strCompare = "IDispatchImpl<" + strInterface + ",";
					for (var nCntr2 = 1; nCntr2 <= oBases.Count; nCntr2++)
					{
						var strBaseName = oBases(nCntr2).DisplayName;
						if (strCompare == strBaseName.substring(0, strCompare.length))
						{
							aryClasses[nIndex++] = oClass;
							if(!bAll)
								return true;
							bATL = true;
							break;
						}
					}
				}
			}
			if (!bATL)
			{
				if (oClass.IsDerivedFrom("COleControl"))
				{
					// look for IID_Interface in InitializeIIDs call in constructor.
					oConstructor = oClass.Functions.Find(oClass.Name);
					if (!oConstructor)
						continue;

					var strBody = oConstructor.BodyText;
					if (-1 != strBody.indexOf("&" + strIID + ",") ||
						-1 != strBody.indexOf("&" + strIID + ")"))
					{
						aryClasses[nIndex++] = oClass;
						if(!bAll)
							return true;
						bMFC = true;
					}
				}
				else if (oClass.IsDerivedFrom("CCmdTarget"))
				{
					// look for IID_Interface in INTERFACE MAP.
					var oMap = oClass.Maps.Find("INTERFACE");
					if (oMap)
					{
						var oMapItems = oMap.Entries;
						var bFound = false;
						for (var nCntr2 = 1; nCntr2 <= oMapItems.Count; nCntr2++)
						{
							var oMapItem = oMapItems(nCntr2);
							var oParams = oMapItem.Parameters;
							for (var nCntr3 = 1; nCntr3 <= oParams.Count; nCntr3++)
							{
								if (-1 != oParams(nCntr3).Name.indexOf(strIID))
								{
									aryClasses[nIndex++] = oClass;
									if(!bAll)
										return true;
									bFound = true;
									bMFC = true;
									break;
								}
							}
							if (bFound)
								break;
						}
					}
				}
			}
		}
		//then, look recursively in namespaces		
		for (nCntr = 1; nCntr <= colElements.Count; nCntr++)
		{
			var oNamespace = colElements(nCntr);
			if(oNamespace.Kind!=vsCMElementNamespace)
				continue;
			if(GetInterfaceClass(strInterface, oNamespace.Members, aryClasses, bAll) && !bAll)
				return true;
		}
		//finally, look recursively in classes/structs
		for (nCntr = 1; nCntr <= colElements.Count; nCntr++)
		{
			var oClass = colElements(nCntr);
			if(oClass.Kind!=vsCMElementClass && oClass.Kind!=vsCMElementStruct)
				continue;
			if(GetInterfaceClass(strInterface, oClass.Members, aryClasses, bAll) && !bAll)
				return true;
		}
		return (aryClasses.length > originalSize);
	}
	catch(e)
	{   
		throw e;
	}
}

/******************************************************************************
 Description: Adds ATL support to an MFC project
       oProj: Selected project
******************************************************************************/
function AddATLSupportToProject(oProj)
{
	var oCM;
	try
	{
		var L_ATLSupportQuestion_Text = "ATL support will be added to this project.  Do you wish to continue?";
		if (!wizard.YesNoAlert(L_ATLSupportQuestion_Text))
			return false;
	
		var strProjectName		= wizard.FindSymbol("PROJECT_NAME");
		var strSafeProjectName	= CreateSafeName(strProjectName);
		var strProjectPath		= wizard.FindSymbol("PROJECT_PATH");
		var strTemplatePath		= wizard.FindSymbol("TEMPLATES_PATH");
		if (-1 == strTemplatePath.toUpperCase().indexOf("ADDTOMFC"))
			strTemplatePath = wizard.FindSymbol("PROJECT_TEMPLATE_PATH") + "\\ClassWiz\\ATL\\AddToMFC\\Templates\\" + wizard.GetHostLocale();
		wizard.AddSymbol("SAFE_PROJECT_NAME", strSafeProjectName);

		oCM = oProj.CodeModel;
		var L_ATLSupport_TRANSACTION_Text = "Add ATL Support To Project";
		oCM.StartTransaction(L_ATLSupport_TRANSACTION_Text);

		var strProjectCPP		= GetProjectFile(oProj, "CPP", false, true);
		var strProjectH			= GetProjectFile(oProj, "H", false, true);
		var strProjectRC		= GetProjectFile(oProj, "RC", true, true);
		var strProjectODL		= GetProjectFile(oProj, "ODL", false, true);
		var strProjectIDL		= GetProjectFile(oProj, "IDL", false, true);
		var strSTDAFX			= GetProjectFile(oProj, "STDAFX", false, true);

		var bDLL;
		if (typeDynamicLibrary == oProj.Object.Configurations(1).ConfigurationType)
			bDLL = true;
		else
			bDLL = false;

		wizard.AddSymbol("DLL_APP", bDLL);
		
		// Create necessary GUIDS
		// create LIBID GUID
		var strRawGUID = wizard.CreateGuid();
		var strFormattedGUID = wizard.FormatGuid(strRawGUID, 0);
		wizard.AddSymbol("LIBID_REGISTRY_FORMAT", strFormattedGUID);

		// create APPID GUID
		strRawGUID = wizard.CreateGuid();
		var strAppID = wizard.FormatGuid(strRawGUID, 0);
		wizard.AddSymbol("APPID_REGISTRY_FORMAT", strAppID);

		// check for IDL or ODL file
		var oFiles = oProj.Object.Files;
		// if ODL file found, convert to IDL
		if (strProjectODL.length)
		{
			var oFile = oFiles(strProjectODL);

			strProjectODL = oFile.FullPath;
			oProj.Object.RemoveFile(oFile);
			strProjectIDL = strProjectODL.substr(0, strProjectODL.length-4) + ".idl";

			var oFSO = new ActiveXObject("Scripting.FileSystemObject");
			oFSO.MoveFile(strProjectODL, strProjectIDL);
			oProj.Object.AddFile(strProjectIDL);
		}
		
		var bNewIDL = false;
		// if no IDL, render template
		if (0 == strProjectIDL.length)
		{
			strProjectIDL = strProjectPath + strSafeProjectName + ".idl";
			wizard.RenderTemplate(strTemplatePath + "\\addatl.idl", strProjectIDL);
			oProj.Object.AddFile(strProjectIDL);
			bNewIDL = true;
			oCM.Synchronize();
		}
		else
		{
			oCM.AddIDLImport('"oaidl.idl"', strProjectIDL, vsCMAddPositionStart);
			oCM.AddIDLImport('"ocidl.idl"', strProjectIDL, vsCMAddPositionStart);
		}

		// MIDL settings
		var strMidlHeader = "$(ProjectName)_i.h";
		var strMidlCFile = "$(ProjectName)_i.c";
		var oConfigs = oProj.Object.Configurations;
		for (var nCntr=1; nCntr <= oConfigs.Count; nCntr++)
		{
			var config = oConfigs(nCntr);
			config.UseOfATL = useATLStatic;
			var bDebug = false;
			if (-1 != config.Name.toUpperCase().indexOf("DEBUG"))
				bDebug = true;
			var MidlTool = config.Tools("VCMidlTool");
			MidlTool.MkTypLibCompatible = false;
			if (IsPlatformWin32(config))
				MidlTool.TargetEnvironment = midlTargetWin32;
			if (bDebug)
				MidlTool.PreprocessorDefinitions = "_DEBUG";
			else
				MidlTool.PreprocessorDefinitions = "NDEBUG";

			if (bNewIDL)
			{
				MidlTool.HeaderFileName = strMidlHeader;
				MidlTool.InterfaceIdentifierFileName = strMidlCFile;
			}
			else
			{
				if (MidlTool.HeaderFileName.length && MidlTool.HeaderFileName.charAt(0) != "$")
					strMidlHeader = MidlTool.HeaderFileName;
				else
					MidlTool.HeaderFileName = strMidlHeader;

				if (MidlTool.InterfaceIdentifierFileName.length && MidlTool.InterfaceIdentifierFileName.charAt(0) != "$")
					strMidlCFile = MidlTool.InterfaceIdentifierFileName
				else
					MidlTool.InterfaceIdentifierFileName = strMidlCFile;
			}
			strMidlHeader = config.Evaluate(strMidlHeader);
			strMidlCFile = config.Evaluate(strMidlCFile);
			
			MidlTool.GenerateStublessProxies = true;
			MidlTool.TypeLibraryName = "$(IntDir)/" + "$(ProjectName).tlb";

			// remove .DEF file from linker settings
			if (bDLL)
			{
				var LinkTool = config.Tools("VCLinkerTool");
				LinkTool.ModuleDefinitionFile = "";
			}

			// Resource settings
			var RCTool = config.Tools("VCResourceCompilerTool");
			RCTool.AdditionalIncludeDirectories = "$(IntDir)";

			var PostBuildTool = config.Tools("VCPostBuildEventTool");
			if (!PostBuildTool.CommandLine.length)
			{
				var L_PerformingRegistration1_Text = "Performing registration";
				PostBuildTool.Description = L_PerformingRegistration1_Text;
				if (bDLL)
					PostBuildTool.CommandLine = "regsvr32 /s /c \"$(TargetPath)\"";
				else
					PostBuildTool.CommandLine = "\"$(TargetPath)\" /RegServer";
			}
		}
		
		// Add #include <initguid.h> to strProjectName.cpp
		if (!DoesIncludeExist(oProj, "<initguid.h>", strProjectCPP))
			oCM.AddInclude("<initguid.h>", strProjectCPP, vsCMAddPositionEnd);

		// Add #include "projectname_i.h" to strProjectName.h
		if (!DoesIncludeExist(oProj, '"' + strMidlHeader + '"', strProjectH))
			oCM.AddInclude('"' + strMidlHeader + '"', strProjectH, vsCMAddPositionEnd);

		// Add #include "projectname_i.c" to strProjectName.cpp
		if (!DoesIncludeExist(oProj, '"' + strMidlCFile + '"', strProjectCPP))
			oCM.AddInclude('"' + strMidlCFile + '"', strProjectCPP, vsCMAddPositionEnd);

		// add RGS file resource
		var strRGSFile = strProjectName + ".rgs";
		var strRGSID = "IDR_" + strSafeProjectName.toUpperCase();
		wizard.RenderTemplate(strTemplatePath + "\\addatl.rgs", strProjectPath + strRGSFile);

		var oResHelper = wizard.ResourceHelper;
		oResHelper.OpenResourceFile(strProjectRC);
		oResHelper.AddResource(strRGSID, strProjectPath + strRGSFile, "REGISTRY");

		// add TYPELIB if necessary
		if (bNewIDL)
			oResHelper.CompileDirectives += '\r\n1 TYPELIB "' + strProjectName + '.tlb"';

		oResHelper.CloseResourceFile();

		oCM.AddMacro("_ATL_APARTMENT_THREADED", strSTDAFX, "", vsCMAddPositionStart);

		// add #includes to stdafx.h
		if (!DoesIncludeExist(oProj, "<atlbase.h>", strSTDAFX))
			oCM.AddInclude("<atlbase.h>", strSTDAFX, vsCMAddPositionEnd);
		if (!DoesIncludeExist(oProj, "<atlcom.h>", strSTDAFX))
			oCM.AddInclude("<atlcom.h>", strSTDAFX, vsCMAddPositionEnd);

		// render addatlps.def
		wizard.RenderTemplate(strTemplatePath + "\\addatlps.def", strProjectPath + strProjectName + "ps.def");

		// render addatlps.mk
		wizard.RenderTemplate(strTemplatePath + "\\addatlps.mk", strProjectPath + strProjectName + "ps.mk");

		var oClasses = oCM.Classes;
		var oInitInstance = false;
		var oCWinApp = false;
		for (var nCntr = 1; nCntr <= oClasses.Count; nCntr++)
		{
			oClass = oClasses(nCntr);
			// look for class derived from CWinApp
			if (oClass.IsDerivedFrom("CWinApp"))
			{				
				oInitInstance = oClass.Functions.Find("InitInstance");
				if (!oInitInstance)
				{
					oInitInstance = oClass.AddFunction("InitInstance", vsCMFunctionFunction, "BOOL", vsCMAddPositionEnd, vsCMAccessPublic, strProjectCPP);
					oInitInstance.BodyText = GetCodeForInitInstance(0, 1);
					oInitInstance.Comment = oClass.Name + " initialization";
				}
				oCWinApp = oClass;
				break;
			}
		}

		if (bDLL)
		{
			var oDllCanUnloadNow = GetMemberFunction(false, "DllCanUnloadNow", oProj);

		strCodeForDllCanUnloadNow0 = "\t" + "AFX_MANAGE_STATE(AfxGetStaticModuleState());\r\n";
		strCodeForDllCanUnloadNow1 = "\t" + "if (_AtlModule.GetLockCount() > 0)\r\n" +
									 "\t" + "\treturn S_FALSE;\r\n";
		strCodeForDllCanUnloadNow3 = "\t" + "return S_OK;\r\n";
			
			if (!oDllCanUnloadNow)
			{
				oDllCanUnloadNow = oCM.AddFunction("DllCanUnloadNow", strProjectCPP, vsCMFunctionFunction, "STDAPI", vsCMAddPositionEnd);
				oDllCanUnloadNow.BodyText = strCodeForDllCanUnloadNow0 + strCodeForDllCanUnloadNow1 + strCodeForDllCanUnloadNow3;
				oDllCanUnloadNow.Comment = "DllCanUnloadNow - Allows COM to unload DLL";
			}
			else
			{
				oDllCanUnloadNow.StartPointOf(vsCMPartBody, vsCMWhereDefinition).CreateEditPoint().Insert(strCodeForDllCanUnloadNow1);
				oCM.Synchronize();
			}

		strCodeForDllGetClassObject0 = "\t" + "AFX_MANAGE_STATE(AfxGetStaticModuleState());\r\n";
		strCodeForDllGetClassObject1 = "\t" + "if (S_OK == _AtlModule.GetClassObject(rclsid, riid, ppv))\r\n" + 
									   "\t" + "\treturn S_OK;\r\n";
		strCodeForDllGetClassObject3 = "\t" + "return AfxDllGetClassObject(rclsid, riid, ppv);\r\n";

			var oDllGetClassObject = GetMemberFunction(false, "DllGetClassObject", oProj);
			if (!oDllGetClassObject)
			{
				oDllGetClassObject = oCM.AddFunction("DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)", strProjectCPP, vsCMFunctionFunction, "STDAPI", vsCMAddPositionEnd, vsCMAccessPublic);
				oDllGetClassObject.BodyText = strCodeForDllGetClassObject0 + strCodeForDllGetClassObject1 + strCodeForDllGetClassObject3;
				oDllGetClassObject.Comment = "DllGetClassObject - Returns class factory";
			}
			else
			{
				oDllGetClassObject.StartPointOf(vsCMPartBody, vsCMWhereDefinition).CreateEditPoint().Insert(strCodeForDllGetClassObject1);
				oCM.Synchronize();
			}

		strCodeForDllRegisterServer0 = "\t" + "AFX_MANAGE_STATE(AfxGetStaticModuleState());\r\n";
		strCodeForDllRegisterServer1 = "\t" + "_AtlModule.UpdateRegistryAppId(TRUE);\r\n" +
									   "\t" + "HRESULT hRes = _AtlModule.RegisterServer(TRUE);\r\n" +
									   "\t" + "if (hRes != S_OK)\r\n" +
		 							   "\t" + "\treturn hRes;\r\n";
		strCodeForDllRegisterServer5 = "\t" + "if (!COleObjectFactory::UpdateRegistryAll(TRUE))\r\n" +
									   "\t" + "\treturn ResultFromScode(SELFREG_E_CLASS);\r\n" +
									   "\t" + "return S_OK;\r\n";

			var oDllRegisterServer = GetMemberFunction(false, "DllRegisterServer", oProj);
			if (!oDllRegisterServer)
			{
				oDllRegisterServer = oCM.AddFunction("DllRegisterServer", strProjectCPP, vsCMFunctionFunction, "STDAPI", vsCMAddPositionEnd, vsCMAccessPublic);
				oDllRegisterServer.BodyText = strCodeForDllRegisterServer0 + strCodeForDllRegisterServer1 + strCodeForDllRegisterServer5;
				oDllRegisterServer.Comment = "DllRegisterServer - Adds entries to the system registry";
			}
			else
			{
				oDllRegisterServer.StartPointOf(vsCMPartBody, vsCMWhereDefinition).CreateEditPoint().Insert(strCodeForDllRegisterServer1);
				oCM.Synchronize();
			}

		strCodeForDllUnregisterServer0 = "\t" + "AFX_MANAGE_STATE(AfxGetStaticModuleState());\r\n";
		strCodeForDllUnregisterServer1 = "\t" + "_AtlModule.UpdateRegistryAppId(FALSE);\r\n" +
										 "\t" + "HRESULT hRes = _AtlModule.UnregisterServer(TRUE);\r\n" +
										 "\t" + "if (hRes != S_OK)\r\n" +
										 "\t" + "\treturn hRes;\r\n";
		strCodeForDllUnregisterServer5 = "\t" + "if (!COleObjectFactory::UpdateRegistryAll(FALSE))\r\n" +
										 "\t" + "\treturn ResultFromScode(SELFREG_E_CLASS);\r\n" +
										 "\t" + "return S_OK;\r\n";

			var oDllUnregisterServer = GetMemberFunction(false, "DllUnregisterServer", oProj);
			if (!oDllUnregisterServer)
			{
				oDllUnregisterServer = oCM.AddFunction("DllUnregisterServer", strProjectCPP, vsCMFunctionFunction, "STDAPI", vsCMAddPositionEnd, vsCMAccessPublic);
				oDllUnregisterServer.BodyText = strCodeForDllUnregisterServer0 + strCodeForDllUnregisterServer1 + strCodeForDllUnregisterServer5;
				oDllUnregisterServer.Comment = "DllUnregisterServer - Removes entries from the system registry";
			}
			else
			{
				oDllUnregisterServer.StartPointOf(vsCMPartBody, vsCMWhereDefinition).CreateEditPoint().Insert(strCodeForDllUnregisterServer1);
				oCM.Synchronize();
			}

			// add #pragmas for exporting functions
		strCodeForExportPragmas = '#pragma comment(linker, "/EXPORT:DllCanUnloadNow=_DllCanUnloadNow@0,PRIVATE")\r\n' +
								  '#pragma comment(linker, "/EXPORT:DllGetClassObject=_DllGetClassObject@12,PRIVATE")\r\n' +
								  '#pragma comment(linker, "/EXPORT:DllRegisterServer=_DllRegisterServer@0,PRIVATE")\r\n' +
								  '#pragma comment(linker, "/EXPORT:DllUnregisterServer=_DllUnregisterServer@0,PRIVATE")\r\n';
			
			oDllCanUnloadNow.StartPoint.Insert(strCodeForExportPragmas + "\r\n");
			oCM.Synchronize();

			// delete DEF file
			var strDefFile = GetProjectFile(oProj, "DEF", false);
			if (strDefFile.length)
			{
				var oFile = oProj.Object.Files(strDefFile);
				oProj.Object.RemoveFile(oFile);
			}
				
			if (-1 == oInitInstance.BodyText.indexOf("COleControlModule::InitInstance") &&
				-1 == oInitInstance.BodyText.indexOf("COleObjectFactory::RegisterAll"))
			{
				oInitInstance.StartPointOf(vsCMPartBody, vsCMWhereDefinition).CreateEditPoint().Insert("\tCOleObjectFactory::RegisterAll();\r\n");
				oCM.Synchronize();
			}
		}
		// EXE case
		else
		{
			if (oCWinApp)
			{
				var strCodeForExitInstance0 = "\t" + "_AtlModule.RevokeClassObjects();\r\n";
				var strCodeForExitInstance1 = "\t" + "return CWinApp::ExitInstance();\r\n";

				var oExitInstance = GetMemberFunction(oCWinApp, "ExitInstance", oProj);
				if (!oExitInstance)
				{
					oExitInstance = oCWinApp.AddFunction("ExitInstance", vsCMFunctionFunction, "BOOL", vsCMAddPositionEnd, vsCMAccessPublic, strProjectCPP);
			
					oExitInstance.BodyText = strCodeForExitInstance0 + strCodeForExitInstance1;
				}
				else
				{
					oExitInstance.StartPointOf(vsCMPartBody, vsCMWhereDefinition).CreateEditPoint().Insert(strCodeForExitInstance0);
					oCM.Synchronize();
				}

				var strBody = oInitInstance.BodyText;
				if (-1 == strBody.search("AfxOleInit") &&
					-1 == strBody.search("OleInitialize") &&
					-1 == strBody.search("CoInitialize") &&
					-1 == strBody.search("CoInitializeEx"))
				{
					var oEditPoint = oInitInstance.StartPointOf(vsCMPartBody, vsCMWhereDefinition).CreateEditPoint().Insert(GetCodeForInitInstance(2, 2));
					oCM.Synchronize();
				}			
				// look for ParseCommandLine(cmdInfo)
				var nPos = strBody.indexOf("ParseCommandLine(cmdInfo)");
				if (-1 == nPos)
				{
					if (!InsertIntoFunction(oInitInstance, "AfxEnableControlContainer", 3, 29, false))
						if (!InsertIntoFunction(oInitInstance, "AfxOleInit", 3, 29, false))
							if (!InsertIntoFunction(oInitInstance, "OleInitialize", 3, 29, false))
								if (!InsertIntoFunction(oInitInstance, "CoInitialize", 3, 29, false))
									if (!InsertIntoFunction(oInitInstance, "CoInitializeEx", 3, 29, false))
									throw "Parsing error: COM initialization function not found.";
				}
				else
				{
					// look for cmdInfo.m_bRunAutomated or RunAutomated
					if (-1 == strBody.indexOf("cmdInfo.m_bRunAutomated") &&
						-1 == strBody.indexOf("RunAutomated()"))
					{
						// no cmdInfo.m_bRunAutomated
						InsertIntoFunction(oInitInstance, "ParseCommandLine(cmdInfo)", 6, 29, false);
					}
					else
					{
						// insert CoRegisterClassObject code
						InsertIntoFunction(oInitInstance, "ParseCommandLine(cmdInfo)", 6, 8, false);

						// look for "== CCommandLineInfo::AppUnregister"
						if (!InsertIntoFunction(oInitInstance, "== CCommandLineInfo::AppUnregister", 19, 20, true))
						{
							if (!InsertIntoFunction(oInitInstance, "cmdInfo.m_bRunAutomated", 16, 29, false))
								InsertIntoFunction(oInitInstance, "RunAutomated()", 16, 29, false);
						}
						else
						{
							if (!InsertIntoFunction(oInitInstance, "COleObjectFactory::UpdateRegistryAll()", 26, 27, false))
								if (!InsertIntoFunction(oInitInstance, "UpdateRegistry(OAT_INPLACE_SERVER)", 26, 27, false))
									InsertIntoFunction(oInitInstance, "UpdateRegistry(OAT_DOC_OBJECT_SERVER)", 26, 27, false);
						}
					}
				}
			}			
		}

		var oAtlModule = oCM.AddClass("C" + strSafeProjectName + "Module", strProjectCPP, vsCMAddPositionStart, "CAtlMfcModule", "", vsCMAccessPublic);
		var strBody = "public:\r\n";
		strBody += "\tDECLARE_LIBID(LIBID_" + oCM.IDLLibraries(1).Name + ");\r\n";
		strBody += "\tDECLARE_REGISTRY_APPID_RESOURCEID(" + strRGSID + ', "{' + strAppID + '}");';
		oAtlModule.BodyText = strBody;
		// Add global _AtlModule to project.cpp
		oAtlModule.EndPoint.CreateEditPoint().Insert("\r\n\r\nC" + strSafeProjectName + "Module _AtlModule;\r\n");
		oCM.Synchronize();

		oCM.CommitTransaction();
		return true;
	}
	catch(e)
	{
		if (oCM)
			oCM.AbortTransaction();   
		throw e;
	}
}

/******************************************************************************
 Description: Returns a Function object based on the given name
      oClass: Class object
 strFuncName: Name of the function
       oProj: Selected project
******************************************************************************/
function GetMemberFunction(oClass, strFuncName, oProj)
{
	try
	{
		var oFunctions;
		if (oClass)
			oFunctions = oClass.Functions;
		else
		{
			if (!oProj)
				return false;
			oFunctions = oProj.CodeModel.Functions;
		}

		for (var nCntr = 1; nCntr <= oFunctions.Count; nCntr++)
		{
			if (oFunctions(nCntr).Name == strFuncName)
				return oFunctions(nCntr);
		}
		return false;
	}
	catch(e)
	{   
		throw e;
	}
}

/******************************************************************************
 Description: Helper function to get the text for InitInstance()
  nLineStart: Function's start line number
    nLineEnd: Function's end line number
******************************************************************************/
function GetCodeForInitInstance(nLineStart, nLineEnd)
{
	try
	{
		var strCode = new Array();

		strCode[0] = "CWinApp::InitInstance();";
		strCode[1] = "return TRUE;";

		strCode[2] = "AfxOleInit();";

		strCode[3] = "// Parse command line for standard shell commands, DDE, file open";
		strCode[4] = "CCommandLineInfo cmdInfo;";
		strCode[5] = "ParseCommandLine(cmdInfo);";

		strCode[6] = "// Register class factories via CoRegisterClassObject().";
		strCode[7] = "if (FAILED(_AtlModule.RegisterClassObjects(CLSCTX_LOCAL_SERVER, REGCLS_MULTIPLEUSE)))";
		strCode[8] = "\treturn FALSE;";
		strCode[9] = "// App was launched with /Embedding or /Automation switch.";
		strCode[10] = "// Run app as automation server.";
		strCode[11] = "if (cmdInfo.m_bRunEmbedded || cmdInfo.m_bRunAutomated)";
		strCode[12] = "{";
		strCode[13] = "\t// Don't show the main window";
		strCode[14] = "\treturn TRUE;";
		strCode[15] = "}";

		strCode[16] = "// App was launched with /Unregserver or /Unregister switch.";
		strCode[17] = "if (cmdInfo.m_nShellCommand == CCommandLineInfo::AppUnregister)";
		strCode[18] = "{";
		strCode[19] = "\t_AtlModule.UpdateRegistryAppId(FALSE);";
		strCode[20] = "\t_AtlModule.UnregisterServer(TRUE);";
		strCode[21] = "\treturn FALSE;";
		strCode[22] = "}";

		strCode[23] = "// App was launched with /Register or /Regserver switch.";
		strCode[24] = "if (cmdInfo.m_nShellCommand == CCommandLineInfo::AppRegister)";
		strCode[25] = "{";
		strCode[26] = "\t_AtlModule.UpdateRegistryAppId(TRUE);";
		strCode[27] = "\t_AtlModule.RegisterServer(TRUE);";
		strCode[28] = "\treturn FALSE;";
		strCode[29] = "}";

		var strRet = "";
		for (var nCntr = nLineStart; nCntr <= nLineEnd; nCntr++)
			strRet += "\t" + strCode[nCntr] + "\r\n";
		return strRet;
	}
	catch(e)
	{   
		throw e;
	}
}

/******************************************************************************
 Description: Helper function used by InsertIntoFunction to convert an index in
			  a function body to a line number.
   strString: Function body
        nPos: Position to convert
******************************************************************************/
function OffsetToLineNumber(strString, nPos)
{
	try
	{
		var nCurPos = strString.indexOf("\r\n");
		var nLine = 1;
		while (nCurPos != -1 && nCurPos < nPos)
		{
			nLine++;
			nCurPos = strString.indexOf("\r\n", nCurPos+2);
		}
		return nLine;
	}
	catch(e)
	{   
		throw e;
	}
}

/******************************************************************************
     Description: Helper function used by InsertIntoFunction to determine if a
				  line begins with a particular string
         strBody: Body of function
 strSearchString: String to look for
       nStartPos: Starting position for search
******************************************************************************/
function LineBeginsWith(strBody, strSearchString, nStartPos)
{
	try
	{
		// go to start of line
		var nPos = strBody.lastIndexOf("\n", nStartPos) + 1;
		if (nPos == -1)
			nPos = 0;
		// walk to first char
		while (strBody.charAt(nPos) == " " || strBody.charAt(nPos) == "\t")
			nPos++;
		if (strBody.substr(nPos, strSearchString.length) == strSearchString)
		{
			return true;
		}
		else
			return false;
	}
	catch(e)
	{   
		throw e;
	}
}

/******************************************************************************
     Description: Helper function used by AddATLSupportToProject to insert
				  code into InitInstance.
       oFunction: Function object to insert into
 strSearchString: String to look for to determine insertion point
      nStartLine: Starting line to pass to GetCodeForInitInstance
        nEndLine: Ending line to pass to GetCodeForInitInstance
  bInsideIfBlock: Boolean indicating whether to insert inside if block
******************************************************************************/
function InsertIntoFunction(oFunction, strSearchString, nStartLine, nEndLine, bInsideIfBlock)
{
	try
	{
		var strBody = oFunction.BodyText;
		var nCurPos = strBody.indexOf(strSearchString);
		if (-1 == nCurPos)
			return false;

		if (LineBeginsWith(strBody, "if", nCurPos) || LineBeginsWith(strBody, "else", nCurPos))
		{
			var nEndOfNextLine = strBody.indexOf("\r\n", nCurPos) + 2;
			nEndOfNextLine = strBody.indexOf("\r\n", nEndOfNextLine);

			// look for "{" on current line and next line
			var nPos = strBody.indexOf("{", nCurPos);
			if (nPos != -1 && nPos < nEndOfNextLine)
			{
				if (bInsideIfBlock)
					nCurPos = nPos;
				else
					nCurPos = strBody.indexOf("}", nPos);
			}
			else
				nCurPos = strBody.indexOf("\r\n", nCurPos) + 2;
		}

		var oEditPoint = oFunction.StartPointOf(vsCMPartBody, vsCMWhereDefinition).CreateEditPoint();
		oEditPoint.LineDown(OffsetToLineNumber(strBody, nCurPos));
		oEditPoint.Insert(GetCodeForInitInstance(nStartLine, nEndLine));

		return true;
	}
	catch(e)
	{   
		throw e;
	}
}

/******************************************************************************
    Description: This function is called by the wizard to verify if the project
	             is compatible with the Code Wizard that's about to be run.  The
				 wizard knows to call this function when it sees the param 
				 PREPROCESS_FUNCTION in VC7\VCAddClass\XXX.VSZ
          oProj: Selected project
        oObject: Select object (in this case it will be the project)
******************************************************************************/
function CanAddMFCClass(oProj, oObject)
{
	try
	{
		if (!IsMFCProject(oProj, false))
		{
			var L_CanAddMFCClass_Text = "MFC classes can only be added to MFC projects.";
			wizard.ReportError(L_CanAddMFCClass_Text);
			return false;
		}
		return true;
	}
	catch(e)
	{   
		throw e;
	}
}

/******************************************************************************
    Description: This function is called by the wizard to verify if the VC 
	             Code Model is available.  The wizard knows to call this function 
				 when it sees the param PREPROCESS_FUNCTION in VC7\VCAddClass\XXX.VSZ
		  oProj: Selected project
        oObject: Select object (in this case it will be the project)
******************************************************************************/
function CanAddClass(oProj, oObject)
{
	try
	{
		var oCM = oProj.CodeModel;
		return true;
	}
	catch(e)
	{
		L_CanAddClass_Text = "Code Model not available, cannot add class.";
		wizard.ReportError(L_CanAddClass_Text);
		return false;
	}
}

/******************************************************************************
    Description: This function is called by the wizard to verify if the VC 
	             Code Model is available.  The wizard knows to call this function 
				 when it sees the param PREPROCESS_FUNCTION in VC7\VCAddClass\XXX.VSZ
		  oProj: Selected project
        oObject: Select object (in this case it will be the project)
******************************************************************************/
function CanAddATLConsumerClass(oProj, oObject)
{
	try
	{
		var oCM = oProj.CodeModel;	
		if (IsATLProject(oProj))
			return true;
		if (IsMFCProject(oProj, true))
		{
			var L_CanAddATLConsumerClass_Text = "Cannot add ATL Cunsumer class to MFC EXE and MFC Regular DLL projects. Please use MFC Consumer class";
			wizard.ReportError(L_CanAddATLConsumerClass_Text);
			return false;
		}
		return true;
	}
	catch(e)
	{
		var L_CannotATLConsumerClass_Text = "Code Model not available, cannot add class.";
		wizard.ReportError(L_CannotATLConsumerClass_Text);
		return false;
	}
}

/******************************************************************************
   Description: This function is called by the wizard to verify if the project
                is compatible with the Code Wizard that's about to be run.  The
                wizard knows to call this function when it sees the param 
                PREPROCESS_FUNCTION in VC7\VCAddClass\XXX.VSZ
         oProj: Selected project
       oObject: Select object (in this case it will be the project)
******************************************************************************/
function CanAddATLClass(oProj, oObject)
{
	try
	{
		if (IsATLProject(oProj))
			return true;
		if (!IsMFCProject(oProj, true))
		{   
			var L_CanAddATLClass_Text = "ATL classes can only be added to ATL, MFC EXE and MFC Regular DLL projects.";
			wizard.ReportError(L_CanAddATLClass_Text);
			return false;
		}
		return AddATLSupportToProject(oProj);
	}
	catch(e)
	{
		throw e;
	}
}

/******************************************************************************
       Description: Checks if a file exists.  If it does, prompts the user if
	                they want to merge what's about to be added to the existing 
					file.
       strFileName: File name to check.  If unique, function returns true.
bCheckIfMidlHeader: Displays an error if filename is used by MIDL
     bSetMergeFlag: Whether to set the MERGE_FILE symbol
******************************************************************************/
function CanUseFileName(strFileName, bCheckIfMidlHeader, bCannotExist, bSetMergeFlag)
{
	try
	{
		if (bCheckIfMidlHeader)
		{
			var oMidlTool = window.external.ProjectObject.Object.Configurations(1).Tools("VCMidlTool");
			var strHeadFile = window.external.ProjectObject.Object.Configurations(1).Evaluate(oMidlTool.HeaderFileName);
			if (strHeadFile.toLowerCase() == strFileName.toLowerCase())
			{   
				var L_CanUseFileName_Text = " is generated by MIDL and cannot be used.";
				window.external.ReportError(strFileName + L_CanUseFileName_Text);
				return false;
			}
		}
		if (window.external.DoesFileExist(strFileName))
		{
			if (bCannotExist)
			{   
				var L_CanUseFileName2_Text = " is already in use.";
				window.external.ReportError(strFileName + L_CanUseFileName2_Text);
				return false;
			}
			else
			{
				var L_CanUseFileName3_Text = " already exists. Do you want to merge this class into the same file?";
				var bRet = window.external.YesNoAlert(strFileName + L_CanUseFileName3_Text);
				if (bRet && bSetMergeFlag)
					window.external.AddSymbol("MERGE_FILE", true);
				return bRet;
			}
		}
		else
			return true;
	}
	catch(e)
	{
		throw e;
	}
}

/******************************************************************************
     Description: adds the "include" statement to strInFile, including the header
                  where strCodeElemName is implemented, if such a header found in the oProj
           oProj: the context project
 strCodeElemName: the name (full name) of the code element for which we're searching
                  the definition header
       strInFile: the file that will include the definition header, if found
******************************************************************************/
function IncludeCodeElementDeclaration(oProj, strCodeElemName, strInFile)
{
	try
	{
		var CodeElement = oProj.CodeModel.CodeTypeFromFullName(strCodeElemName);
		if(CodeElement==null)
		{
			var L_IncludeCodeElementDeclaration1_Text = "Unable to find code element: ";
			throw new Error(1, L_IncludeCodeElementDeclaration1_Text + strCodeElemName);
		}
		var strCodeElemFile = CodeElement.Location(vsCMWhereDefault);
		if(strCodeElemFile==null)
		{
			var L_IncludeCodeElementDeclaration2_Text = "Unable to find code element file for code element: ";
			throw new Error(1, L_IncludeCodeElementDeclaration2_Text + strCodeElemName);
		}

		var nIndex = strCodeElemFile.lastIndexOf("\\");
		var strCodeElemFilePath = strCodeElemFile.substr(0, nIndex);
		if(nIndex!=0)
			strCodeElemFile = strCodeElemFile.substr(nIndex+1);

		var strInFileName = strInFile;
		nIndex = strInFileName.lastIndexOf("\\");
		var strInFilePath = strInFileName.substr(0, nIndex);
		if(nIndex!=0)
			strInFileName = strInFileName.substr(nIndex+1);

		strInFileName = strInFileName.toUpperCase();
		var strUpperCEFile = strCodeElemFile.toUpperCase();

		//only if strCodeElemName defined in different header; do not include it recursively to the same file
		if(strInFileName != strUpperCEFile)
		{ 
			var dotIndex = strUpperCEFile.lastIndexOf('.');
			if(dotIndex>=0 && strUpperCEFile.charAt(dotIndex+1)=='H') //only if strUpperCEFile is a valid C++ header file
			{
				var strIncludeText;
				if(strCodeElemFilePath.length==0 || strCodeElemFilePath.toLowerCase()==strInFilePath.toLowerCase())
				{
					//we don't know the path of strCodeElemFile (for example if it comes from ATLMFC headers)
					//or it lies in the same directory as strInFileName
					strIncludeText = '"' + strCodeElemFile + '"';
				}
				else
				{ 
					//if strInFileName and strCodeElemFile files live in different paths, we add the fullpath of strCodeElemFile to #include
					strIncludeText = '"' + strCodeElemFilePath + '\\' + strCodeElemFile + '"';
				}
				if (!DoesIncludeExist(oProj, strIncludeText, strInFile))
					oProj.CodeModel.AddInclude(strIncludeText, strInFile, vsCMAddPositionEnd); //include header where code element class is defined
			}
		}
	}
	catch(e)
	{
		throw e;
	}
}

/******************************************************************************
Description: This function is called by the wizard to add the _MERGE_PROXYSTUB
			 symbol if needed
      oProj: Selected project object
******************************************************************************/
function SetMergeProxySymbol(oProj)
{
	try
	{
		// if merging proxy/stub, proj will have dlldatax.c
		if (!oProj.Object.Files("dlldatax.c"))
			return;

		// add _MERGE_PROXYSTUB if necessary
		var oConfigs = oProj.Object.Configurations;
		for (var nCntr = 1; nCntr <= oConfigs.Count; nCntr++)
		{
			var oConfig = oConfigs(nCntr);
			var oCLTool = oConfig.Tools("VCCLCompilerTool");
			if (-1 == oCLTool.PreprocessorDefinitions.indexOf("_MERGE_PROXYSTUB"))
				oCLTool.PreprocessorDefinitions += ";_MERGE_PROXYSTUB";
		}
	}
	catch(e)
	{
		throw e;
	}
}

/******************************************************************************
 Description: Strip spaces from a string
       strin: The string (is in/out param)
******************************************************************************/
function TrimStr(str)
{
	var nLength = str.length;
	var nStartIndex = 0;
	var nEndIndex = nLength-1;

	while (nStartIndex < nLength && (str.charAt(nStartIndex) == ' ' || str.charAt(nStartIndex) == '\t'))
		nStartIndex++;
		
	while (nEndIndex > nStartIndex && (str.charAt(nEndIndex) == ' ' || str.charAt(nEndIndex) == '\t'))
		nEndIndex--;
	
	return str.substring(nStartIndex, nEndIndex+1);
}
/******************************************************************************
 Description: Open the file that contains the TextPoint, then move the cursor to the 
			  TextPoint.
         oTP: The reference to TextPoint
******************************************************************************/
function ShowTextPoint(oTP)
{
	try
	{
		var oSel = oTP.Parent.Selection;
		oSel.MoveToPoint(oTP);
		oSel.ActivePoint.TryToShow(vsPaneShowHow.vsPaneShowAsIs);
	}
	catch(e)
	{
		throw(e);
	}
}

function ValidateFileNameAndEnsureInProject(strFileName, fileType)
{			
	try
	{
		if (!window.external.dte.VCLanguageManager.ValidateFileName(strFileName, fileType))
		{
			// Not a valid file name.
			return false;
		}

		if (!window.external.DoesFileExist(strFileName))
		{
			// File doesn't already exist.
			return true;
		}

		if (window.external.ProjectObject.Object.Files.Item(strFileName))
		{
			// Already in the project.
			return true;
		}

		if (!window.external.ProjectObject.Object.CanAddFile(strFileName))
		{
			// Can not be added to the project.
			return false;
		}

		var L_ConfirmAddFileToProject_Text = "File '";
		L_ConfirmAddFileToProject_Text = L_ConfirmAddFileToProject_Text + strFileName;
		var L_ConfirmAddFileToProject1_Text = "' is not in the project.  Would you like to add this file to the project?";
		L_ConfirmAddFileToProject_Text = L_ConfirmAddFileToProject_Text + L_ConfirmAddFileToProject1_Text;

		if (!window.external.YesNoAlert(L_ConfirmAddFileToProject_Text))
		{
			// User chose not to add to project.
			return false;
		}

		if (window.external.ProjectObject.Object.AddFile(strFileName))
		{
			// Successfully added the file to the project.
			return true;
		}
	}
	catch(e)
	{
		throw(e);
	}

	return false;
}

/******************************************************************************
        Description: Returns a boolean indicating whether this is a Win32 configuration or not
		    oConfig: VCConfiguration object
******************************************************************************/
function IsPlatformWin32(oConfig)
{
	return oConfig.Platform.Name == "Win32";
}


function GetPlatformDefine(oConfig)
{
	if (oConfig.Platform.Name == "Win32")
		return "WIN32;";
	else
		return "";
}

/******************************************************************************
 Description: Finds the project item in the project that corresponds to the 
		file name specified.
         oFilter: The Project or Filter to start searching from
		 strFile: The file to search for
******************************************************************************/

function FindProjectItem(oProject, strFile)
{
	try
	{
		var oFile = oProject.Object.Files.Item(strFile);
	
		if (oFile)
		{
			return oFile.Object;
		}
	}
	catch(e)
	{
		throw(e);
	}

	return null;
}

//addds the unsigned in front of strTypeName and returns the result
// if its type (or basic type) is "char" and bDefaultUnsigned==true (can be used to adjust the type of params
// in the method implementation when midl setting /char unsigned is in effect)
function AddUnsignedToChar(strTypeName, bDefaultUnsigned)
{
	if(!bEmbeddedIDL && bDefaultUnsigned)
	{
		if(strTypeName.length>4)
		{
			var starSpace = strTypeName.charAt(4);
			if(starSpace != '*' && starSpace != ' ' && starSpace != '[')
				return strTypeName;
		}
		var type4chars = strTypeName.substr(0, 4);		
		if (type4chars=="char")
			return "unsigned " + strTypeName; //add "unsigned "  in front of "char"
	}
	return strTypeName;
}

/******************************************************************************
 Description: 
       oProj: Project object
******************************************************************************/
function AddReferencesForWinForm(oProj)
{
	var oProjObject = oProj.Object;
	oProjObject.AddAssemblyReference("mscorlib.dll");
	oProjObject.AddAssemblyReference("System.Data.dll");
	oProjObject.AddAssemblyReference("System.Windows.Forms.dll");
	oProjObject.AddAssemblyReference("System.XML.dll");
	oProjObject.AddAssemblyReference("System.Drawing.dll");
	oProjObject.AddAssemblyReference("System.dll");
	CollapseReferencesNode(oProj);
	
}


/******************************************************************************
 Description: 
       oProj: Project object
******************************************************************************/
function AddReferencesForApp(oProj)
{
	var oProjObject = oProj.Object;
	oProjObject.AddAssemblyReference("mscorlib.dll");
	oProjObject.AddAssemblyReference("System.dll");
	oProjObject.AddAssemblyReference("System.Data.dll");
	CollapseReferencesNode(oProj);
	
}


/******************************************************************************
 Description: 
       oProj: Project object
******************************************************************************/
function AddReferencesForClass(oProj)
{
	var oProjObject = oProj.Object;
	oProjObject.AddAssemblyReference("mscorlib.dll");
	oProjObject.AddAssemblyReference("System.dll");
	oProjObject.AddAssemblyReference("System.Data.dll");
	oProjObject.AddAssemblyReference("System.XML.dll");
	CollapseReferencesNode(oProj);
}

/******************************************************************************
 Description: 
       oProj: Project object
******************************************************************************/
function AddReferencesForComponent(oProj)
{
	var oProjObject = oProj.Object;
	oProjObject.AddAssemblyReference("mscorlib.dll");
	oProjObject.AddAssemblyReference("System.dll");
	CollapseReferencesNode(oProj);
}

/******************************************************************************
 Description: 
       oProj: Project object
******************************************************************************/
function AddReferencesForInstaller(oProj)
{
	var oProjObject = oProj.Object;
	oProjObject.AddAssemblyReference("mscorlib.dll");
	oProjObject.AddAssemblyReference("System.dll");
	oProjObject.AddAssemblyReference("System.Management.dll");
	oProjObject.AddAssemblyReference("System.Configuration.Install.dll");
	CollapseReferencesNode(oProj);
}

/******************************************************************************
 Description: 
       oProj: Project object
******************************************************************************/
function AddReferencesForControl(oProj)
{
	var oProjObject = oProj.Object;
	oProjObject.AddAssemblyReference("mscorlib.dll");
	oProjObject.AddAssemblyReference("System.dll");
	oProjObject.AddAssemblyReference("System.Data.dll");
	oProjObject.AddAssemblyReference("System.Drawing.dll");
	oProjObject.AddAssemblyReference("System.Windows.Forms.dll");
	oProjObject.AddAssemblyReference("System.XML.dll");
	CollapseReferencesNode(oProj);
}


/******************************************************************************
 Description: 
       oProj: Project object
******************************************************************************/
function AddReferencesForWinService(oProj)
{
	var oProjObject = oProj.Object;
	oProjObject.AddAssemblyReference("mscorlib.dll");
	oProjObject.AddAssemblyReference("System.dll");
	oProjObject.AddAssemblyReference("System.Data.dll");
	oProjObject.AddAssemblyReference("System.ServiceProcess.dll");
	oProjObject.AddAssemblyReference("System.Configuration.Install.dll");
	oProjObject.AddAssemblyReference("System.XML.dll");
	CollapseReferencesNode(oProj);
}

/******************************************************************************
 Description: 
       oProj: Project object
******************************************************************************/
function AddReferencesForWebService(oProj)
{
	var oProjObject = oProj.Object;
	oProjObject.AddAssemblyReference("mscorlib.dll");
	oProjObject.AddAssemblyReference("System.dll");
	oProjObject.AddAssemblyReference("System.Data.dll");
	oProjObject.AddAssemblyReference("System.Web.dll");
	oProjObject.AddAssemblyReference("System.Web.Services.dll");
	oProjObject.AddAssemblyReference("System.XML.dll");
	oProjObject.AddAssemblyReference("System.EnterpriseServices.dll");
	CollapseReferencesNode(oProj);
}

/******************************************************************************
 Description: 
       oProj: Project object
******************************************************************************/
function AddReferencesForWebForm(oProj)
{
	var oProjObject = oProj.Object;
	oProjObject.AddAssemblyReference("mscorlib.dll");
	oProjObject.AddAssemblyReference("System.dll");
	oProjObject.AddAssemblyReference("System.Drawing.dll");
	oProjObject.AddAssemblyReference("System.Data.dll");
	oProjObject.AddAssemblyReference("System.Web.dll");
	oProjObject.AddAssemblyReference("System.XML.dll");
	CollapseReferencesNode(oProj);
}

/******************************************************************************
 Description: 
       oProj: Project object
******************************************************************************/
function AddReferencesForWebControl(oProj)
{
	var oProjObject = oProj.Object;
	oProjObject.AddAssemblyReference("mscorlib.dll");
	oProjObject.AddAssemblyReference("System.dll");
	oProjObject.AddAssemblyReference("System.Drawing.dll");
	oProjObject.AddAssemblyReference("System.Web.dll");
	CollapseReferencesNode(oProj);
}

//Checks to see if the file strItemName.strSuffix exists.  If it does, it appends a number onto strItemName to make it unique

function GetFileNameUnique(strItemName, strSuffix)
{
	try
	{
		var nCnt = 0;
		var strFileCheck = strItemName + strSuffix;
		while (wizard.DoesFileExist(strFileCheck))
		{
			nCnt++;
			strFileCheck = strItemName + nCnt.toString() + strSuffix;
		}
		
		return strFileCheck;
	}
	catch(e)
	{
		throw e;
	}
}


function GetClassNameUnique(oProject, strNamespaceName, strClassName)
{
	var counter = 1;

	var strUniqueName = strClassName;

	var Namespaces = oProject.CodeModel.Namespaces;
	for(nNamespaces = 1; nNamespaces<=Namespaces.Count; nNamespaces++)
	{
		var oNamespace = Namespaces.Item(nNamespaces)
		if(oNamespace.Name != strNamespaceName)
			continue;
		while (oNamespace.Classes.Find(strUniqueName))
		{
			strUniqueName = strClassName + counter.toString();
			counter++;
		}
	}
	return strUniqueName;
}

function GetFileNameUniqueCPPandH(strName)
{
	var strUniqueName = strName;
	var counter = 1;
	while (wizard.DoesFileExist(strUniqueName + ".cpp") || wizard.DoesFileExist(strUniqueName + ".h"))
	{
		strUniqueName = strName + counter.toString();
		counter++;
	}
	return strUniqueName;
}


function CollapseReferencesNode(oProj)
{
	var L_References = "References";
	try
	{
		if (GetUIItem(oProj, L_References))
			GetUIItem(oProj, L_References).UIHierarchyItems.Expanded = false;
	}
	catch(e)
	{
	}
}


function GetUIItem(oProject, sName)
{
	if (sName != "")
	{
		sName = oProject.Name + "\\" + sName;
	}
	else
	{
		sName = oProject.Name;
	}
	
	for (var oParent = getParent(oProject); oParent != null; oParent = getParent(oParent))
	{
		sName = oParent.Name + "\\" + sName;
	}
	
	//
	// We have arrived at the top of the soltuion explorer hierarchy - return the sName index into the solution's UIHierarchyItem collection.
	//
	
	var strSolutionName = dte.Solution.Properties("Name");
	var oHierarchyObject = dte.Windows.Item(vsWindowKindSolutionExplorer).Object;
	   
	return oHierarchyObject.GetItem(strSolutionName + "\\" + sName);
}


function getParent(obj)
{
    var parent = obj.Collection.parent;
    //
    // is obj a project ?
    //
    if (parent == dte)
    {
        //
        // is obj a sub-project ?
        //
        if (obj.ParentProjectItem)
        {                
			parent = obj.ParentProjectItem.Collection.parent;
        }
        else
        {
            //
            // obj is a top-level project
            //
            parent = null;
		}
    }
   
    return parent;    
}


function AddDefaultManagedConfigs(proj)
{
	try
	{
	
		var config = proj.Object.Configurations("Debug");
		config.IntermediateDirectory = "$(ConfigurationName)";
		config.OutputDirectory = "$(SolutionDir)$(ConfigurationName)";
		config.ManagedExtensions = true;
		config.CharacterSet = charSetMBCS;
		
		var CLTool = config.Tools("VCCLCompilerTool");
		CLTool.WarningLevel = warningLevel_3;
		CLTool.MinimalRebuild = false;
		CLTool.DebugInformationFormat = debugEnabled;
		CLTool.Optimization = optimizeDisabled;
		CLTool.BasicRuntimeChecks = runtimeBasicCheckNone;
		CLTool.PreprocessorDefinitions = GetPlatformDefine(config) + "_DEBUG";
		CLTool.RuntimeLibrary = rtMultiThreadedDebug;
		
		var LinkTool = config.Tools("VCLinkerTool");
		LinkTool.GenerateDebugInformation = true;
		LinkTool.LinkIncremental = linkIncrementalYes;
		LinkTool.AssemblyDebug = linkAssemblyDebugFull;

		config = proj.Object.Configurations.Item("Release");
		config.IntermediateDirectory = "$(ConfigurationName)";
		config.OutputDirectory = "$(SolutionDir)$(ConfigurationName)";
		config.ManagedExtensions = true;
		config.CharacterSet = charSetMBCS;

		CLTool = config.Tools("VCCLCompilerTool");
		CLTool.WarningLevel = warningLevel_3;
		CLTool.MinimalRebuild = false;
		CLTool.PreprocessorDefinitions = GetPlatformDefine(config) + "NDEBUG";
		CLTool.RuntimeLibrary = rtMultiThreaded;
		CLTool.DebugInformationFormat = debugEnabled;
				
		LinkTool = config.Tools("VCLinkerTool");
		LinkTool.GenerateDebugInformation = true;
		LinkTool.LinkIncremental = linkIncrementalNo;
		
		proj.Object.keyword = "ManagedCProj";

	}
	catch(e)
	{
		throw e;
	}
}

function AddManagedConfigsForDLL(proj, strProjectName)
{
	try
	{
		AddDefaultManagedConfigs(proj);
		proj.Object.RootNamespace = CreateSafeName(strProjectName);
		AddManagedConfigForDLL(proj.Object.Configurations.Item("Debug"), strProjectName);
		AddManagedConfigForDLL(proj.Object.Configurations.Item("Release"), strProjectName);
	}
	catch(e)
	{
		throw e;
	}
}

function AddManagedConfigForDLL(config, strProjectName)
{
	try
	{
		config.ConfigurationType = typeDynamicLibrary;
		var VCCLTool = config.Tools("VCCLCompilerTool");
		VCCLTool.AdditionalOptions = "/Zl";
		var LinkTool = config.Tools("VCLinkerTool");
		LinkTool.AdditionalOptions = "/noentry";
		LinkTool.AdditionalDependencies = "nochkclr.obj mscoree.lib";
		LinkTool.OutputFile = "$(OutDir)\\$(ProjectName)" + ".dll";			

	}
	catch(e)
	{
		throw e;
	}

}

function AddManagedConfigsForEXE(proj, strProjectName, subSystem, isWinService)
{
	try
	{
		
		AddDefaultManagedConfigs(proj);
		proj.Object.RootNamespace = CreateSafeName(strProjectName);
		AddManagedConfigForEXE(proj.Object.Configurations("Debug"), strProjectName, subSystem, isWinService);
		AddManagedConfigForEXE(proj.Object.Configurations("Release"), strProjectName, subSystem, isWinService);
						
	}
	catch(e)
	{
		throw e;
	}
}

function AddManagedConfigForEXE(config, strProjectName, subSystem, isWinService)
{
	try
	{
		config.ConfigurationType = typeApplication;
		var LinkTool = config.Tools("VCLinkerTool");
							
		if (subSystem)
		{
			LinkTool.SubSystem = subSystem;
		}
		if (isWinService)
		{
			config.CharacterSet = charSetUNICODE;
		}
			
		LinkTool.OutputFile = "$(OutDir)\\$(ProjectName)" + ".exe";
		
	}
	catch(e)
	{
		throw e;
	}
}

function AddManagedConfigsForWeb(proj, strProjectName, ext, strAddress)
{
	try
	{
		AddDefaultManagedConfigs(proj);
		proj.Object.RootNamespace = CreateSafeName(strProjectName);
		AddManagedConfigForWeb(proj.Object.Configurations.Item("Debug"), strProjectName, ext, strAddress);
		AddManagedConfigForWeb(proj.Object.Configurations.Item("Release"), strProjectName, ext, strAddress);
				
	}
	catch(e)
	{
		throw e;
	}
}


function AddManagedConfigForWeb(config, strProjectName, ext, strAddress)
{
	try
	{
		if (ext) config.DebugSettings.HttpUrl = strAddress + "\/" + strProjectName + "\/" + strProjectName + ext ;
		config.ConfigurationType = typeDynamicLibrary;
		var VCCLTool = config.Tools("VCCLCompilerTool");
		VCCLTool.AdditionalOptions = "/Zl";		
		var LinkTool = config.Tools("VCLinkerTool");
		LinkTool.AdditionalDependencies = "nochkclr.obj mscoree.lib";
		LinkTool.AdditionalOptions = "/noentry";
		LinkTool.OutputFile = "$(OutDir)/" + strProjectName + ".dll";
		var WebDeployConfig = config.Tools("VCWebDeploymentTool");
		WebDeployConfig.ExcludedFromBuild = false;
		
	}
	catch(e)
	{
		throw e;
	}
}

function CanUseDrive(strProjectPath)
{
	try
	{
		var fso = new ActiveXObject("Scripting.FileSystemObject");
		var d = fso.GetDrive(fso.GetDriveName(strProjectPath));
		if (d.DriveType == 3)				// Network drive type
		{
			var L_CanUseDrive_Text = " The Project location is not fully trusted by the .NET runtime. ";
			var L_CanUseDrive1_Text = "This is usually because the location is a network ";
			L_CanUseDrive_Text = L_CanUseDrive_Text + L_CanUseDrive1_Text;
			var L_CanUseDrive2_Text = "share or mapped to a network share on a remote ";
			L_CanUseDrive_Text = L_CanUseDrive_Text + L_CanUseDrive2_Text;
			var L_CanUseDrive3_Text = "machine. If the output path is under the project ";
			L_CanUseDrive_Text = L_CanUseDrive_Text + L_CanUseDrive3_Text;
			var L_CanUseDrive4_Text = "location, your code will not execute as fully trusted, ";
			L_CanUseDrive_Text = L_CanUseDrive_Text + L_CanUseDrive4_Text;
			var L_CanUseDrive5_Text = "and you may receive unexpected security exceptions. ";
			L_CanUseDrive_Text = L_CanUseDrive_Text + L_CanUseDrive5_Text;
			var L_CanUseDrive6_Text = "Click OK to ignore and continue. Click CANCEL to ";
			L_CanUseDrive_Text = L_CanUseDrive_Text + L_CanUseDrive6_Text;
			var L_CanUseDrive7_Text = "choose a different project location";
			L_CanUseDrive_Text = L_CanUseDrive_Text + L_CanUseDrive7_Text;
			
			return (wizard.OkCancelAlert(L_CanUseDrive_Text)) ? true : false;
				
		}
		return true;
	}
	catch(e)
	{
		throw e;
	}
}

/******************************************************************************
 Description: Given the LC string (example LCID "1033" for english US)
		it transforms it into 4 digit hex representation with leading 0
		if necessary (example "0409" for english US). Format used in RC files.
		Note that prefix "0x" is not added
******************************************************************************/
function LocaleTo4HexDigit(strLocale)
{
	var nlc = new Number(strLocale);
	var strLoc = nlc.toString(16);
	if(strLoc.length==3)
		return "0" + strLoc;
	return strLoc;
}

/******************************************************************************
 Description: Given the LC string (example LCID "1033" for english US)
 it sets all the required symbols to generate the RC file of given language
******************************************************************************/
function SetLocaleForResources(strLCID)
{
//window.external.ReportError("Adding LCID: " + strLCID);
	var strLang = window.external.GetLangFromLCID(strLCID);
	window.external.AddSymbol("LANGUAGE", strLang);
	window.external.AddSymbol("LANGUAGE_NAME", strLang);

	window.external.AddSymbol("LCID", strLCID);
	window.external.AddSymbol("HEX_LCID", LocaleTo4HexDigit(strLCID));
	var strCodePage = window.external.GetCodePageFromLCID(strLCID);
	window.external.AddSymbol("CODE_PAGE", strCodePage);
	window.external.AddSymbol("HEX_CODE_PAGE", LocaleTo4HexDigit(strCodePage));

	window.external.AddSymbol("PRIMARY_LANG_ID", window.external.GetPrimaryLangIdFromLCID(strLCID));
	window.external.AddSymbol("SUB_LANG_ID", window.external.GetSubLangIdFromLCID(strLCID));
	window.external.AddSymbol("LANG_SUFFIX", window.external.GetLangAbbrevFromLCID(strLCID));
}

function IsMCppProject(selProj)
{
	try
	{
		if (selProj.Object.Configurations(1).ManagedExtensions)
			return true;
		var L_No_MCPP_Projects_Text = "Managed components can only be added to managed projects. Please convert the project to managed";
		wizard.ReportError(L_No_MCPP_Projects_Text);
		return false;
	}
	catch(e)
	{
		return false;
	}
}

function IsDllProject(selProj)
{
	try
	{
		var nTotal = selProj.Object.Configurations.Count;
		for (var nCntr = 1; nCntr <= nTotal; nCntr++)
		{
			if (typeDynamicLibrary != selProj.Object.Configurations(nCntr).ConfigurationType)
			{
				return false;
			}
		}
		return true;
	}
	catch(e)
	{
		return false;
	}
}

/******************************************************************************
 Description: If we are running an AppWizard for a new solution, this will 
 copy default.ncb to SolutionName.ncb
******************************************************************************/
function CopyNCBFileToSolutionDirectory(strProjectName, strProjectPath)
{
	if (!wizard.FindSymbol("CLOSE_SOLUTION"))
	{
		// ...and CLOSE_SOLUTION is false, we are adding a new project to an 
		// existing solution, so the NCB will already exist.
			
		return;
	}

	var strTemplatePath = wizard.FindSymbol("TEMPLATES_PATH");
	var strSource = strTemplatePath + "\\..\\..\\..\\default.ncb";

	var strSolutionDirectory;
	var strSolutionName = wizard.FindSymbol("VS_SOLUTION_NAME");

	if (strSolutionName == "")
	{
		// If VS_SOLUTION_NAME is empty, we are creating a brand new solution,
		// and the project directory is the solution directory
		//
		
		strSolutionDirectory = strProjectPath + "\\";
		strSolutionName = strProjectName;
	}
	else
	{
		// If VS_SOLUTION_NAME is not empty, we are creating a directory for the solution,
		// so strip off the project name to get the solution directory.
		//
	
		strSolutionDirectory = strProjectPath.substr(0, strProjectPath.length - strProjectName.length)
	}

	var strDestination =  strSolutionDirectory + strSolutionName + ".ncb";
	wizard.RenderTemplate(strSource, strDestination, true, false);
}

/******************************************************************************
 Description: Set Resource File Name (managed resource compiler tool) for all 
 file configurations.
******************************************************************************/
function SetResourceFileName(projfile, strResFileName)
{
	projfile = projfile.ContainingProject.Object.Files(projfile.Name);
	
	for (var i=1; i<=projfile.FileConfigurations.Count; i++)
	{
		var config = projfile.FileConfigurations.Item(i);
		if (config != null)
		{
			var RCTool = config.Tool;
			RCTool.ResourceFileName = strResFileName;	
		}
	}
}
