#pragma once

using namespace System;
using namespace System::Collections;
using namespace System::ServiceProcess;
using namespace System::ComponentModel;


namespace [!output SAFE_NAMESPACE_NAME]
{
	/// <summary> 
	/// Summary for [!output SAFE_NAMESPACE_NAME]WinService
	/// </summary>
	///
	/// WARNING: If you change the name of this class, you will need to change the 
	///          'Resource File Name' property for the managed resource compiler tool 
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	public __gc class [!output SAFE_NAMESPACE_NAME]WinService : public System::ServiceProcess::ServiceBase 
	{
	public:
		[!output SAFE_NAMESPACE_NAME]WinService()
		{
			InitializeComponent();    
		}
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		void Dispose(bool disposing)
		{
			if (disposing && components)
			{
				components->Dispose();
			}
			__super::Dispose(disposing);
		}
		
	protected:
		/// <summary>
		/// Set things in motion so your service can do its work.
		/// </summary>
		void OnStart(String* args[])
		{
			// TODO: Add code here to start your service.
		}
		
		/// <summary>
		/// Stop this service.
		/// </summary>
		void OnStop()
		{     
			// TODO: Add code here to perform any tear-down necessary to stop your service.
		}
    		
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container *components;

		/// <summary> 
		/// Required method for Designer support - do not modify 
		/// the contents of this method with the code editor.
		/// </summary>	
		void InitializeComponent(void)
		{
			this->components = new System::ComponentModel::Container();
			this->CanStop = true;
			this->CanPauseAndContinue = true;
			this->AutoLog = true;
			this->ServiceName = S"[!output SAFE_NAMESPACE_NAME]WinService";
		}		
	};
}