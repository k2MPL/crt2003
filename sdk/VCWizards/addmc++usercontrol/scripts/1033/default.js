// (c) 2001 Microsoft Corporation

function OnFinish(selProj, selObj)
{
	try
	{
		if (!CanAddUserControl(selProj) || !PrepareToAddManagedClass(selProj))
			return VS_E_WIZARDBACKBUTTONPRESS;
		AddReferencesForControl(selProj);
		AddFilesToProjectWithInfFile(selProj, wizard.FindSymbol("PROJECT_NAME"));
		selProj.Object.Save();
	}
	catch (e)
	{
		if (e.description.length > 0)
			SetErrorInfo(e);
		return e.number;
	}
}

function CanAddUserControl(oProject)
{
	try
	{
		if (!IsDllProject(oProject))
		{
			var L_No_Exe_Projects_Text = "User controls can only be added to DLL projects.";
			wizard.ReportError(L_No_Exe_Projects_Text);
			return false;
		}
		
		return true;
	}
	catch(e)
	{   
		throw e;
	}
}

function SetFileProperties(oFileItem, strFileName)
{
	if (strFileName == "NewUserControl.h")
	{
		oFileItem.Object.FileType = eFileTypeCppControl;
	}
		
	return false;
}

function GetTargetName(strName, strProjectName, strResPath, strHelpPath)
{
	try
	{
		return wizard.FindSymbol("SAFE_ITEM_NAME") + "." + strName.split(".")[1];
	}
	catch(e)
	{
		throw e;
	}
}

