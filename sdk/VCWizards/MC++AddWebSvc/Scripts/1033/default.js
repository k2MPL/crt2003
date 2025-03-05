// (c) 2001 Microsoft Corporation

function OnFinish(selProj, selObj)
{	
	try
	{
		if(!PrepareToAddManagedClass(selProj))
			return VS_E_WIZARDBACKBUTTONPRESS;
		if(!IsWebProject(selProj))
		{
			var L_NotManaged_Text = "Managed Web Service can be added to Managed Web projects only";
			wizard.ReportError (L_NotManaged_Text);
			return VS_E_WIZARDBACKBUTTONPRESS;
		}

		CheckAddtoProject(selProj);
		
		PatchWizardSymbols();	
		var strSafeNamespaceName = wizard.FindSymbol("SAFE_NAMESPACE_NAME");
		var oElement = selProj.CodeModel.Namespaces.Find(strSafeNamespaceName);
		if (oElement)
		{
			var strItemName = wizard.FindSymbol("ITEM_NAME");
			var L_ObjectExist_Text = " is already found in the project. Please choose a different name.";
			wizard.ReportError(strItemName + L_ObjectExist_Text);
			return VS_E_WIZARDBACKBUTTONPRESS; 
		}
		AddReferencesForWebService(selProj);
		AddFilesToProjectWithInfFile(selProj, wizard.FindSymbol("PROJECT_NAME"));        
	}
	catch(e)
	{
		if (e.description.length != 0)
			SetErrorInfo(e);
		return e.number
	}
}
function SetFileProperties(projfile, strName)
{
		if (strName == "root.asmx")
		{
			projfile.Object.DeploymentContent = true;
		}
		else if (strName == "root.h")
		{
			projfile.Object.FileType = eFileTypeCppWebService;
		}
		if (strName == "root.resX")
		{
			var strNS = wizard.FindSymbol("SAFE_NAMESPACE_NAME");
			var strResFileName = "$(IntDir)/" + strNS + ".C" + wizard.FindSymbol("SAFE_ITEM_NAME") + ".resources";
			SetResourceFileName(projfile, strResFileName);
		}
		return false;
}

function GetTargetName(strName, strProjectName, strResPath, strHelpPath)
{
	try
	{
		var strTarget = strName;
		if (strName.substr(0, 4) == "root")
		{
			strTarget = wizard.FindSymbol("FILE_NAME") + strName.substr(4);
		}
		return strTarget; 
	}
	catch(e)
	{
		throw e;
	}
}

function StripPath(strFullPath)
{
	try
	{
		var nIndex = strFullPath.lastIndexOf("\\", strFullPath.length);
		if (nIndex != -1)
		{
			return strFullPath.substring(nIndex+1, strFullPath.length);
		}
		
		return strFullPath;
	}
	catch (e)
	{
		throw e;
	}
}

function CheckAddtoProject(oProj)
{
	wizard.AddSymbol("COMMENTS_MANAGED_SWITCHES","");
	try
	{
		var nTotal = oProj.Object.Configurations.Count;
		for (var nCntr = 1; nCntr <= nTotal; nCntr++)
		{
			var oConfig = oProj.Object.Configurations(nCntr);
			if (oConfig.ManagedExtensions == false)
			{
				var L_MANAGEDSETTINGS_TEXT = "/*\nCheck for the following property settings on the files that include this file.\n";
				var L_MANAGEDSETTINGS1_TEXT = "1. \"Debug Information Format\" should be set to \"Zi\"\n";
				L_MANAGEDSETTINGS_TEXT = L_MANAGEDSETTINGS_TEXT + L_MANAGEDSETTINGS1_TEXT;
				L_MANAGEDSETTINGS2_TEXT = "2. \"Compile As Managed\" should be set to \"Assembly (\\CLR)\"\n";
				L_MANAGEDSETTINGS_TEXT = L_MANAGEDSETTINGS_TEXT + L_MANAGEDSETTINGS2_TEXT;
				L_MANAGEDSETTINGS3_TEXT = "3. \"Enable Minimal Rebuild\" should be set to \"No\"\n";
				L_MANAGEDSETTINGS_TEXT = L_MANAGEDSETTINGS_TEXT + L_MANAGEDSETTINGS3_TEXT;
				L_MANAGEDSETTINGS4_TEXT = "4. \"Basic Runtime Checks\" should be set to \"Default\"\n";
				L_MANAGEDSETTINGS_TEXT = L_MANAGEDSETTINGS_TEXT + L_MANAGEDSETTINGS4_TEXT;
				L_MANAGEDSETTINGS5_TEXT = "5. \"Runtime Library\" should be set to \"Multi-threaded DLL (\\MD)\"\n";
				L_MANAGEDSETTINGS_TEXT = L_MANAGEDSETTINGS_TEXT + L_MANAGEDSETTINGS5_TEXT;
				L_MANAGEDSETTINGS6_TEXT = "6. You might have to make some changes to the precompiled header settings.\n*/\n";
				L_MANAGEDSETTINGS_TEXT = L_MANAGEDSETTINGS_TEXT + L_MANAGEDSETTINGS6_TEXT;
				wizard.AddSymbol("COMMENTS_MANAGED_SWITCHES", L_MANAGEDSETTINGS_TEXT);

				return false;
			}
		}
		return true;

	}
	catch (e)
	{
		return false;
	}
}

function PatchWizardSymbols()
{
	try
	{
		var strProjectName		= wizard.FindSymbol("PROJECT_NAME");
		var strSafeProjectName	= CreateSafeName(strProjectName);

		var strProjectPath		= wizard.FindSymbol("PROJECT_PATH");
		var strTemplatePath		= wizard.FindSymbol("TEMPLATES_PATH");

		var strSafeItemName     = CreateSafeName(StripPath(wizard.FindSymbol("ITEM_NAME")));
		var strFileName		= StripPath(GetUniqueFileName(strProjectPath, strSafeItemName));

		wizard.AddSymbol("SAFE_ITEM_NAME", strSafeItemName);
		wizard.AddSymbol("SAFE_NAMESPACE_NAME", CreateCPPName(strSafeItemName));
		wizard.AddSymbol("FILE_NAME", strFileName);
	}
	catch (e)
	{
		throw e;
	}
}

function IsWebProject(selProj)
{
	try
	{
		var config = selProj.Object.Configurations(1);
		if(!config)
			return false;
		var WebDeployConfig = config.Tools("VCWebDeploymentTool");
		if(!WebDeployConfig)
			return false;
		return (WebDeployConfig.ExcludedFromBuild == false); //web projects have their deployment tool included in the build
	}
	catch (e)
	{
		throw e;
	}
}
