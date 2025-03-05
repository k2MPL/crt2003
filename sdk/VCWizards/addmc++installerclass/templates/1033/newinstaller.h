#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Configuration::Install;


namespace [!output SAFE_NAMESPACE_NAME]
{
	[RunInstaller(true)]	

	/// <summary> 
	/// Summary for [!output SAFE_ITEM_NAME]
	/// </summary>
	public __gc class [!output SAFE_ITEM_NAME] : public System::Configuration::Install::Installer
	{
	public: 
		[!output SAFE_ITEM_NAME](void)
		{
			InitializeComponent();
		}
        
	protected: 
		void Dispose(Boolean disposing)
		{
			if (disposing && components)
			{
				components->Dispose();
			}
			__super::Dispose(disposing);
		}
		
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container* components;
		
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>		
		void InitializeComponent(void)
		{
		}
	};
}