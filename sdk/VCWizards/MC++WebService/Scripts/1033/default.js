// (c) 2001 Microsoft Corporation

function OnFinish(selProj, selObj)
{
    try
    {
        var strProjectPath = wizard.FindSymbol("PROJECT_PATH");
        var strProjectName = wizard.FindSymbol("PROJECT_NAME");

		if (!CanUseDrive(strProjectPath))
			return VS_E_WIZARDBACKBUTTONPRESS;
			
        var proj = CreateManagedProject(strProjectName, strProjectPath);
		AddManagedConfigsForWeb(proj, strProjectName, ".asmx", "http://localhost");
		AddReferencesForWebService(proj);
        AddFilesToNewProjectWithInfFile(proj, strProjectName);
        proj.Object.Save();
    }
	catch(e)
	{
		if (e.description.length != 0)
			SetErrorInfo(e);
		return e.number
	}
}

function IsAsciiName(strName)
{
	try
	{
		var nLen = strName.length;
		var strSafeName = "";
		
		for (nCntr = 0; nCntr < nLen; nCntr++)
		{
			var cChar = strName.charAt(nCntr);
			if ((cChar >= 'A' && cChar <= 'Z') || (cChar >= 'a' && cChar <= 'z') || (cChar == '_') || (cChar >= '0' && cChar <= '9'))
			{
			}
			else 
				return false;
		}
		return true;
	}
	catch(e)
	{
		throw e;
	}
}

function SetFileProperties(projfile, strName)
{
	try
	{
		if (strName == "root.asmx")
		{
			projfile.Object.DeploymentContent = true;
		}
		else if (strName == "Web.config")
		{
			projfile.Object.DeploymentContent = true;
		}
		else if(strName == "Global.asax")
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
			var strResFileName = "$(IntDir)/" + strNS + "." + strNS + "Class.resources";
			SetResourceFileName(projfile, strResFileName);
		}
		return false;
	}
	catch(e)
	{
		throw e;
	}
}

function GetTargetName(strName, strProjectName, strResPath, strHelpPath)
{
	try
	{
		var strTarget = strName;

		if (strName == "readme.txt")
			strTarget = "ReadMe.txt";

		if (strName.substr(0, 4) == "root")
		{
			if (strName == "root.asmx")
				strTarget = strProjectName + strName.substr(4);
			else
				strTarget = strProjectName + "Class" + strName.substr(4);
		}
		return strTarget; 
	}
	catch(e)
	{
		throw e;
	}
}
