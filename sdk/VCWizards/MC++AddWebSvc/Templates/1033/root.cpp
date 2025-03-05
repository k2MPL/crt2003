#include "stdafx.h"
#include "[!output SAFE_ITEM_NAME].h"

// [!output SAFE_ITEM_NAME].cpp
using namespace System;
using namespace System::Web;
using namespace System::Web::Services;

namespace [!output SAFE_NAMESPACE_NAME]
{        
	// WEB SERVICE EXAMPLE
	// Add your methods and their implementation, for this class.
	// To test this web service, ensure that the .asmx file in the deployment path is
	// set as your Debug HTTP URL, in project properties and press F5.
	// An example HelloWorld template, is given below.

    String __gc* C[!output SAFE_ITEM_NAME]::HelloWorld()
    {

		// TODO: Add the implementation of your Web Service here

		return S"Hello World!";
        
    }

};
