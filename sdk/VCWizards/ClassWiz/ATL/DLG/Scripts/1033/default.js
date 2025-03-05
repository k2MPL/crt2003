// (c) 2001 Microsoft Corporation
// Script for ATL Dialog

function OnFinish(selProj, selObj)
{
	var oCM;
	try
	{
		oCM	= selProj.CodeModel;

		var strShortName = wizard.FindSymbol("SHORT_NAME");
		var L_TRANSACTION_Text = "Add ATL Dialog ";
		oCM.StartTransaction(L_TRANSACTION_Text + strShortName);

		var strUpperShortName	= strShortName.toUpperCase();
		wizard.AddSymbol("UPPER_SHORT_NAME", strUpperShortName);
		var strHeaderFile		= wizard.FindSymbol("HEADER_FILE");
		var strImplFile			= wizard.FindSymbol("IMPL_FILE");
		var strTemplatePath		= wizard.FindSymbol("TEMPLATES_PATH");

		var strProjectRC		= GetProjectFile(selProj, "RC", true, false);

		var strDLGID = "IDD_" + strUpperShortName;

		var oResHelper = wizard.ResourceHelper;
		oResHelper.OpenResourceFile(strProjectRC);
		var bDBCSCodePage;
		var strCodePage = wizard.FindSymbol("CODE_PAGE");
		if (strCodePage == "932" || strCodePage == "936" || strCodePage == "950" || strCodePage == "949")
			bDBCSCodePage = true; //VS-supported codedepages that require FontSize 9
		else
			bDBCSCodePage = false; //all the rest and unsupported codepages: Fontsize 8 
		var strRCTemplFile = strTemplatePath + (!bDBCSCodePage ? "\\dialog.rc" : "\\dlg_dbcs.rc");
		var strSymbolValue = oResHelper.AddResource(strDLGID, strRCTemplFile, "DIALOG");
		wizard.AddSymbol("IDD_DIALOGID", strSymbolValue.split("=").shift());
		oResHelper.CloseResourceFile();

		// Add header
		RenderAddTemplate("dialog.h", strHeaderFile, selProj, true);

		// Add CPP
		RenderAddTemplate("dialog.cpp", strImplFile, selProj, false);

		oCM.CommitTransaction();
		
		oCM.Classes.Find(wizard.FindSymbol("CLASS_NAME")).StartPoint.TryToShow(vsPaneShowTop);
	}
	catch(e)
	{
		if (oCM)
			oCM.AbortTransaction();

		if (e.description.length != 0)
			SetErrorInfo(e);
		return e.number
	}
}
