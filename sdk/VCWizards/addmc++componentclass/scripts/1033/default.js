// (c) 2001 Microsoft Corporation

function OnFinish(selProj, selObj)
{
	try
	{
		if (!PrepareToAddManagedClass(selProj))
			return VS_E_WIZARDBACKBUTTONPRESS;
		AddReferencesForComponent(selProj);
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

function SetFileProperties(oFileItem, strFileName)
{
	if (strFileName == "NewComponentClass.h")
	{
		oFileItem.Object.FileType = eFileTypeCppClass;
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

