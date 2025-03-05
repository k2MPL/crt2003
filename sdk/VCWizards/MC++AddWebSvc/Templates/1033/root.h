// [!output SAFE_ITEM_NAME].h
[!output COMMENTS_MANAGED_SWITCHES]
#pragma once

using namespace System;
using namespace System::Web;
using namespace System::Web::Services;

namespace [!output SAFE_NAMESPACE_NAME]
{
    public __gc 
        class C[!output SAFE_ITEM_NAME] : public System::Web::Services::WebService
    {
    public:
		C[!output SAFE_ITEM_NAME]()
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
		System::ComponentModel::Container * components;

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent()
		{
		}	

		// WEB SERVICE EXAMPLE
		// Add your methods and their implementation, for this class.
		// To test this web service, ensure that the .asmx file in the deployment path is
		// set as your Debug HTTP URL, in project properties and press F5.
		// An example HelloWorld template, is given below.

    public:
        [System::Web::Services::WebMethod] 
        String __gc* HelloWorld();

        // TODO: Add the methods of your Web Service here
       
    };
}
