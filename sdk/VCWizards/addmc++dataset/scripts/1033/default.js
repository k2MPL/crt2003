// (c) 2001 Microsoft Corporation
function OnFinish(selProj, selObj)
{
	try
	{
		if (!PrepareToAddManagedClass(selProj))
			return VS_E_WIZARDBACKBUTTONPRESS;
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
	if (strFileName == "NewDataSet.xsd")
   	{
		oFileItem.Properties("CustomTool").Value = "MSDataSetGenerator";
	}

	return false;
}

function GetTargetName(strName, strProjectName, strResPath, strHelpPath)
{
	try
	{
		var strTarget = strName;

		if (strName.substr(0, 10) == "NewDataset")
		{
			var strItemName = wizard.FindSymbol("ITEM_NAME");
			var extension = strName.substr(10);
			strTarget = GetFileNameUnique(strItemName, extension);
		}

		return strTarget;
	}
	catch(e)
	{
		throw e;
	}
}

