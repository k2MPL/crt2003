// [!output IMPL_FILE] : Implementation of [!output CLASS_NAME]
#include "stdafx.h"
[!if !ATTRIBUTED]
#include "[!output PROJECT_NAME].h"
[!endif]
#include "[!output HEADER_FILE]"


/////////////////////////////////////////////////////////////////////////////
// [!output CLASS_NAME]

//////////////////////////////////////////////////////////////////////////////
// Class, property and method names

// IMPORTANT: the strings defined below are not localizable

[!if CLASS_SPECIFIED]
const static WCHAR * s_pMyClassName = L"[!output WMICLASSNAME]"; //class name

//properies:
[!output PROPERTY_DEFINITIONS]

//methods:
[!output METHOD_DEFINITIONS]

[!else]
//TODO: define provided class name, e.g.:
const static WCHAR * s_pMyClassName = L"MyClassName"; 

//TODO: define property names of the provided class, e.g.:
//const static WCHAR * pMyProperty = L"MyProperty";

//TODO: define method names of the provided class, e.g.:
//const static WCHAR * pMyMethod = L"MyMethod";
[!endif]

//////////////////////////////////////////////////////////////////////////////
// [!output CLASS_NAME]::Initialize
//Refer to MSDN documentation for IWbemProviderInit::Initialize()
//for details about implementing this method

STDMETHODIMP [!output CLASS_NAME]::Initialize(LPWSTR pszUser,	
									  LONG lFlags,
									  LPWSTR pszNamespace,
									  LPWSTR pszLocale,
									  IWbemServices *pNamespace,
							 		  IWbemContext *pCtx,
									  IWbemProviderInitSink *pInitSink) 
{

	CImpersonateClientHelper impersonateClient;
	HRESULT hr = WBEM_S_NO_ERROR;
	DWORD dwImpersonationLevel = 0;

	if(SUCCEEDED(hr = impersonateClient.GetCurrentImpersonationLevel(dwImpersonationLevel)))
	{
		// If the current thread has impersonation level set to RPC_C_IMP_LEVEL_IDENTIFY or RPC_C_IMP_LEVEL_ANONYMOUS
		if(dwImpersonationLevel < RPC_C_IMP_LEVEL_IMPERSONATE)
		{
			hr = WBEM_E_ACCESS_DENIED;
			// Do the access check yourself on the resources accessed based on security configuration for the provider
			// and change the return code hr appropriately
		}
		else
		{
			hr = impersonateClient.ImpersonateClient();
		}
	}

	if(FAILED(hr))
	{
		return hr;
	}
	if ( NULL == pNamespace || NULL == pInitSink) 
	{
		return WBEM_E_INVALID_PARAMETER;
	}

	//cache IWbemServices pointer 
	//Note: m_pNamespace is a smart pointer, so it AddRef()'s automatically
	m_pNamespace = pNamespace;
				
	//cache provided class definition
	//NOTE: the code below assumes that your class definition doesn't change while
	//your provider is running.  If this is not true, you should implement a consumer
	//for class modification ans class deletion events. Refer to WMI documentation
	//for event consumers on MSDN.
	
	hr = m_pNamespace->GetObject(CComBSTR(s_pMyClassName), 
											0, 
											pCtx, 	//passing IWbemContext pointer to prevent deadlocks
											&m_pClass, 
											NULL);
	if(FAILED(hr))
	{
		return WBEM_E_FAILED;
	}
	
	//cache path parser class factory
	hr = CoGetClassObject(CLSID_WbemDefPath, 
							CLSCTX_INPROC_SERVER, 
							NULL,
							IID_IClassFactory,
							(void **) &m_pPathFactory);
	if (FAILED(hr))
	{
		return WBEM_E_FAILED;
	}

	//create helper object
	m_pHelper = new CInstanceProviderHelper(pNamespace, pCtx);

	if(m_pHelper == NULL)
	{
		return WBEM_E_OUT_OF_MEMORY;
	}

	//NOTE: to report a detailed error or status to WMI, you can call 
	//ConstructErrorObject() on m_pHelper anywhere in your provider

	pInitSink->SetStatus(WBEM_S_INITIALIZED,0);
	return WBEM_S_NO_ERROR;
}

//////////////////////////////////////////////////////////////////////////////
// [!output CLASS_NAME]::GetObjectAsync
// Refer to MSDN documentation for IWbemServices::GetObjectAsync()
// for details about implementing this method

STDMETHODIMP [!output CLASS_NAME]::GetObjectAsync( 
							 const BSTR bstrObjectPath,
							 long lFlags,
							 IWbemContext  *pCtx,
							 IWbemObjectSink  *pResponseHandler)
{

	CImpersonateClientHelper impersonateClient;
	HRESULT hr = WBEM_S_NO_ERROR;
	DWORD dwImpersonationLevel = 0;

	if(SUCCEEDED(hr = impersonateClient.GetCurrentImpersonationLevel(dwImpersonationLevel)))
	{
		// If the current thread has impersonation level set to RPC_C_IMP_LEVEL_IDENTIFY or RPC_C_IMP_LEVEL_ANONYMOUS
		if(dwImpersonationLevel < RPC_C_IMP_LEVEL_IMPERSONATE)
		{
			hr = WBEM_E_ACCESS_DENIED;
			// Do the access check yourself on the resources accessed based on security configuration for the provider
			// and change the return code hr appropriately
		}
		else
		{
			hr = impersonateClient.ImpersonateClient();
		}
	}

	if(FAILED(hr))
	{
		return hr;
	}

[!if SUPPORT_GET ]
	if (NULL == pResponseHandler)
	{
		return WBEM_E_INVALID_PARAMETER;
	}

	CComPtr<IWbemClassObject> pInstance;
	hr = GetInstanceByPath(bstrObjectPath, &pInstance);
	if (FAILED (hr))
	{
		return hr;
	}
			
	//if all is well, return the object to WMI and indicate success:
	pResponseHandler->Indicate (1, &(pInstance.p)); 
	pResponseHandler->SetStatus(0, WBEM_S_NO_ERROR, NULL, NULL);

	return WBEM_S_NO_ERROR;
[!else]
	return WBEM_E_PROVIDER_NOT_CAPABLE;
[!endif]}

//////////////////////////////////////////////////////////////////////////////
// [!output CLASS_NAME]::PutInstanceAsync()
// Refer to MSDN documentation for IWbemServices::PutInstanceAsync()
// for details about implementing this method

STDMETHODIMP [!output CLASS_NAME]::PutInstanceAsync( 
							IWbemClassObject  *pInst,
							long lFlags,
							IWbemContext  *pCtx,
							IWbemObjectSink  *pResponseHandler)
{
   
	CImpersonateClientHelper impersonateClient;
	HRESULT hr = WBEM_S_NO_ERROR;
	DWORD dwImpersonationLevel = 0;

	if(SUCCEEDED(hr = impersonateClient.GetCurrentImpersonationLevel(dwImpersonationLevel)))
	{
		// If the current thread has impersonation level set to RPC_C_IMP_LEVEL_IDENTIFY or RPC_C_IMP_LEVEL_ANONYMOUS
		if(dwImpersonationLevel < RPC_C_IMP_LEVEL_IMPERSONATE)
		{
			hr = WBEM_E_ACCESS_DENIED;
			// Do the access check yourself on the resources accessed based on security configuration for the provider
			// and change the return code hr appropriately
		}
		else
		{
			hr = impersonateClient.ImpersonateClient();
		}
	}

	if(FAILED(hr))
	{
		return hr;
	}

[!if SUPPORT_PUT ]
	if ( NULL == pResponseHandler || NULL == pInst)
	{
		return WBEM_E_INVALID_PARAMETER;
	}
	//TODO: examine possible flag values: WBEM_FLAG_UPDATE_ONLY, 
	//WBEM_FLAG_CREATE_ONLY and WBEM_FLAG_CREATE_OR_UPDATE
	//and choose the level of support you need and return WBEM_E_PROVIDER_NOT_CAPABLE
	//for flag values you do not support

	//TODO: if you are planning to support partial updates, examine pCtx 
	//for "__PUT_EXTENSIONS" and other relevant system context values
	//and update your instance data appropriately
	
	//TODO: handle the instance update or creation here			
	
	pResponseHandler->SetStatus(0, WBEM_S_NO_ERROR, NULL, NULL);
	return WBEM_S_NO_ERROR;
[!else]
	return WBEM_E_PROVIDER_NOT_CAPABLE;
[!endif]
}


//////////////////////////////////////////////////////////////////////////////
// [!output CLASS_NAME]::DeleteInstanceAsync()
// Refer to MSDN help for IWbemServices::DeleteInstanceAsync()
// for details about implementing this method

STDMETHODIMP [!output CLASS_NAME]::DeleteInstanceAsync( 
							const BSTR ObjectPath,
							long lFlags,
							IWbemContext  *pCtx,
							IWbemObjectSink  *pResponseHandler)
{
	CImpersonateClientHelper impersonateClient;
	HRESULT hr = WBEM_S_NO_ERROR;
	DWORD dwImpersonationLevel = 0;

	if(SUCCEEDED(hr = impersonateClient.GetCurrentImpersonationLevel(dwImpersonationLevel)))
	{
		// If the current thread has impersonation level set to RPC_C_IMP_LEVEL_IDENTIFY or RPC_C_IMP_LEVEL_ANONYMOUS
		if(dwImpersonationLevel < RPC_C_IMP_LEVEL_IMPERSONATE)
		{
			hr = WBEM_E_ACCESS_DENIED;
			// Do the access check yourself on the resources accessed based on security configuration for the provider
			// and change the return code hr appropriately
		}
		else
		{
			hr = impersonateClient.ImpersonateClient();
		}
	}

	if(FAILED(hr))
	{
		return hr;
	}

	//To implement this method, an instance provider parses the object path string 
	//specified in the strObjectPath parameter and attempts to locate the corresponding 
	//instance and delete it.
[!if SUPPORT_DELETE ]

	if (NULL == pResponseHandler)
	{
		return WBEM_E_INVALID_PARAMETER;
	}

	CComPtr<IWbemClassObject> pInstance;
	hr = GetInstanceByPath(ObjectPath, &pInstance);
	if (FAILED (hr))
	{
		return hr;
	}

	//TODO: iterate through your data source to find the matching object and delete it.
	//NOTE: If you don't find an object that matches key values indicated in the path,
	//uncomment the following line to communicate this back to WMI:
	//return WBEM_E_NOT_FOUND;
	
	pResponseHandler->SetStatus(0, WBEM_S_NO_ERROR, NULL, NULL);	
	return WBEM_S_NO_ERROR;
	
	[!else]
	return WBEM_E_PROVIDER_NOT_CAPABLE;
	[!endif]

}


//////////////////////////////////////////////////////////////////////////////
// [!output CLASS_NAME]::CreateInstanceEnumAsync()
// Refer to MSDN documentation for IWbemServices::CreateInstanceEnumAsync()
// for details about implementing this method

STDMETHODIMP [!output CLASS_NAME]::CreateInstanceEnumAsync( 
							const BSTR Class,
							long lFlags,
							IWbemContext  *pCtx,
							IWbemObjectSink  *pResponseHandler)
{
	
	CImpersonateClientHelper impersonateClient;
	HRESULT hr = WBEM_S_NO_ERROR;
	DWORD dwImpersonationLevel = 0;

	if(SUCCEEDED(hr = impersonateClient.GetCurrentImpersonationLevel(dwImpersonationLevel)))
	{
		// If the current thread has impersonation level set to RPC_C_IMP_LEVEL_IDENTIFY or RPC_C_IMP_LEVEL_ANONYMOUS
		if(dwImpersonationLevel < RPC_C_IMP_LEVEL_IMPERSONATE)
		{
			hr = WBEM_E_ACCESS_DENIED;
			// Do the access check yourself on the resources accessed based on security configuration for the provider
			// and change the return code hr appropriately
		}
		else
		{
			hr = impersonateClient.ImpersonateClient();
		}
	}

	if(FAILED(hr))
	{
		return hr;
	}

	//NOTE: It is important to note that the instance provider has acquired a thread from WMI 
	//to perform these operations. It may be desirable to call the sink AddRef() method and create 
	//another thread for delivering the objects in the result set. 
	//This strategy allows the current thread to return to WMI without depleting the thread pool. 
	//Whether the provider chooses the single thread design over the dual thread design depends on how 
	//long the provider plans on using the WMI thread.

[!if SUPPORT_ENUMERATE ]
	if (NULL == pResponseHandler)
	{
		return WBEM_E_INVALID_PARAMETER;
	}

	hr = WBEM_S_NO_ERROR;
    
[!if IS_SINGLETON]
	// Prepare an empty object to receive the instance data
	CComPtr<IWbemClassObject> pNewInst;
	hr = m_pClass->SpawnInstance(0, &pNewInst);
	
	CComVariant var;
[!if CLASS_SPECIFIED]
	[!output POPULATE_INSTANCE]
[!else]
	//TODO: populate the instance with properties, e.g.:
	//var.ChangeType(VT_BSTR);
	//var = <value>;  //put appropriate value here
	//hr = pNewInst->Put(CComBSTR(pMyProperty), 0, &var, 0);
	//if(FAILED(hr))
	//{
	//	return hr;
	//}
	//var.Clear();
[!endif]
	
	// Deliver the class to WMI.
	pResponseHandler->Indicate(1, &(pNewInst.p));
[!else]
	// Loop through the private source and create each instance
	//while (<there's more instances>)
	{
		// Prepare an empty object to receive the class definition.
		CComPtr<IWbemClassObject> pNewInst;
		hr = m_pClass->SpawnInstance(0, &pNewInst);
		if (FAILED(hr))
		{	
			//TODO: uncomment the line below once the loop condition is in place
			//break;
		}
		
		CComVariant var;
[!if CLASS_SPECIFIED]
[!output POPULATE_INSTANCE]
[!else]
		//TODO: populate the instance with properties, e.g.:
		//var.ChangeType(VT_BSTR);
		//var = <value>;  //put appropriate value here
		//hr = pNewInst->Put(CComBSTR(pMyProperty), 0, &var, 0);
		//var.Clear();
		//if(FAILED(hr))
		//{
		//	return hr;
		//}
		[!endif]
		
		// Deliver the class to WMI.
		hr = pResponseHandler->Indicate(1, &(pNewInst.p));
	}
[!endif]
	pResponseHandler->SetStatus(0, hr, NULL, NULL);
	return hr;
[!else]
	return WBEM_E_PROVIDER_NOT_CAPABLE;
[!endif]
}


//////////////////////////////////////////////////////////////////////////////
//[!output CLASS_NAME]::ExecQueryAsync()
// Refer to MSDN documentation for IWbemServices::ExecQueryAsync()
// for details about implementing this method
[!if SUPPORTS_QUERY]
// Refer to MSDN documentaion of IWbemQuery interface for query parsing
[!endif]
STDMETHODIMP [!output CLASS_NAME]::ExecQueryAsync( 
							const BSTR QueryLanguage,
							const BSTR Query,
							long lFlags,
							IWbemContext  *pCtx,
							IWbemObjectSink  *pResponseHandler)
{

	CImpersonateClientHelper impersonateClient;
	HRESULT hr = WBEM_S_NO_ERROR;
	DWORD dwImpersonationLevel = 0;

	if(SUCCEEDED(hr = impersonateClient.GetCurrentImpersonationLevel(dwImpersonationLevel)))
	{
		// If the current thread has impersonation level set to RPC_C_IMP_LEVEL_IDENTIFY or RPC_C_IMP_LEVEL_ANONYMOUS
		if(dwImpersonationLevel < RPC_C_IMP_LEVEL_IMPERSONATE)
		{
			hr = WBEM_E_ACCESS_DENIED;
			// Do the access check yourself on the resources accessed based on security configuration for the provider
			// and change the return code hr appropriately
		}
		else
		{
			hr = impersonateClient.ImpersonateClient();
		}
	}
	if(FAILED(hr))
	{
		return hr;
	}

	hr = WBEM_E_NOT_SUPPORTED;
[!if SUPPORTS_QUERY]
	// Create WMI Query Parser object to parse the given query
	if(m_pQuery == NULL)
	{
		hr = CoCreateInstance(CLSID_WbemQuery,
						0,
						CLSCTX_INPROC_SERVER,
						IID_IWbemQuery,
						(LPVOID *)&m_pQuery);
	}
	else
	{
		hr = WBEM_S_NO_ERROR;
	}
[!endif]
	
	if(SUCCEEDED(hr))
	{
		// Instance providers have the option of supporting query processing or relying on WMI 
		// for that service. To support queries, an instance provider must be capable of parsing 
		// simple Structured Query Language (SQL) statements, executing the requested query, 
		// and delivering the result set objects to the requester's sink. 
		
[!if SUPPORTS_QUERY]
		// m_pQuery which is an IWbemQuery inteface pointer can be used to parse queries
		// Uncomment the following part to parse query
		//hr = m_pQuery->Parse(QueryLanguage,Query,0);
		//if(FAILED(hr)  and (Provider does support Provider-defined queries))
		//{
		//		// Do parsing of provider-defined queries
		//}
		
		// if(SUCCEEDED(hr)
		// {
		//		// put your query processing code here
		// }
[!else]
		//TODO: put your query processing code here

[!endif]

		//pResponseHandler->SetStatus(0, WBEM_S_NO_ERROR, NULL, NULL);
		// return WBEM_S_NO_ERROR;
	}
	return hr;
	
}

[!if PROVIDE_METHODS ]

//////////////////////////////////////////////////////////////////////////////
// [!output CLASS_NAME]::ExecMethodAsync()
// Refer to MSDN documentation for IWbemServices::ExecMethodAsync()
// for details about implementing this method

STDMETHODIMP [!output CLASS_NAME]::ExecMethodAsync( 
							const BSTR strObjectPath,
							const BSTR strMethodName,
							long lFlags,
							IWbemContext  *pCtx,
							IWbemClassObject  *pInParams,
							IWbemObjectSink  *pResponseHandler)
{
	
	CImpersonateClientHelper impersonateClient;
	HRESULT hr = WBEM_S_NO_ERROR;
	DWORD dwImpersonationLevel = 0;

	if(SUCCEEDED(hr = impersonateClient.GetCurrentImpersonationLevel(dwImpersonationLevel)))
	{
		// If the current thread has impersonation level set to RPC_C_IMP_LEVEL_IDENTIFY or RPC_C_IMP_LEVEL_ANONYMOUS
		if(dwImpersonationLevel < RPC_C_IMP_LEVEL_IMPERSONATE)
		{
			hr = WBEM_E_ACCESS_DENIED;
			// Do the access check yourself on the resources accessed based on security configuration for the provider
			// and change the return code hr appropriately
		}
		else
		{
			hr = impersonateClient.ImpersonateClient();
		}
	}

	if(FAILED(hr))
	{
		return hr;
	}

[!if CLASS_SPECIFIED]
[!if  !HAS_IMPL_METHODS]	
	//[!output WMICLASSNAME] has no implemented methods	
	return WBEM_E_NOT_SUPPORTED;
[!else]
	if (NULL == pResponseHandler)
	{
		return WBEM_E_INVALID_PARAMETER;
	}	
[!output EXEC_METHOD_BODY]
[!endif]
[!else]
	
	hr = WBEM_E_FAILED;	
	ULONG ulPathTest = WBEMPATH_INFO_IS_INST_REF | WBEMPATH_INFO_IS_CLASS_REF;


	//Check that class name in the path is correct.
	if (FAILED(m_pHelper->CheckInstancePath(m_pPathFactory,
											strObjectPath,
											CComBSTR(s_pMyClassName),
											ulPathTest)))
	{
		//syntax error in path or path incorrect for class provided
		return WBEM_E_INVALID_PARAMETER; 
	}			

	CComVariant var;

	//Get input arguments:
	//TODO: if the method has input arguments, they will be passed as properties of
	//the pInParams object. The commented line below demonstrates how to extract these:
	//hr = pInParams->Get(CComBSTR("InputArgument1"), 0, &var, NULL, NULL);
	//if (FAILED(hr))
	//{
	//	return WBEM_E_INVALID_PARAMETER;
	//}
	//TODO: save input parameter value
	var.Clear();		
	
	//parse path to find instance for method execution: for a non-static method
	CComPtr<IWbemClassObject> pInstance;
	hr = GetInstanceByPath(strObjectPath,&pInstance);
	if(!SUCCEEDED(hr))
	{
		return hr;
	}

	
	//TODO: add code to execute the method here
	//get output parameters class
	CComPtr<IWbemClassObject> pOutClass;
	hr = m_pClass->GetMethod(strMethodName, 0, NULL, &pOutClass);
	if(SUCCEEDED(hr) && pOutClass != NULL)
	{
		CComPtr<IWbemClassObject> pOutParams;
		pOutClass->SpawnInstance(0, &pOutParams);
		//TODO: create output parameters by filling properties
		//of pOutParams class. For example:

		//var.ChangeType(VT_BSTR);
		//fill var with appropriate value
		//hr = pOutParams->Put(CComBSTR("MyOutputParameter"), 0, &var, 0);
		//var.Clear();
		//if(FAILED(hr))
		//{
		//	return hr;
		//}
		//var.ChangeType(VT_I2);
		//fill var with appropriate value
		//hr = pOutParams->Put(CComBSTR("ReturnValue"), 0, &var, 0);
		//var.Clear();
		//if(FAILED(hr))
		//{
		//	return hr;
		//}
		// Send the output object back to the client via the sink
		hr = pResponseHandler->Indicate(1, &(pOutParams.p));
		pResponseHandler->SetStatus(WBEM_STATUS_COMPLETE, hr, NULL, NULL);
	}

	return hr;
[!endif]

}
[!endif]



//////////////////////////////////////////////////////////////////////////////
// [!output CLASS_NAME]::GetInstanceByPath() parses the path to find out required key values,
// then searhces the internal store for an object with matching key values. If such
// an object is found, the method spawns a new instance, fills all properties and
// returns it in ppInstance. If not, the method returns WBEM_E_NOT_FOUND.

STDMETHODIMP [!output CLASS_NAME]::GetInstanceByPath (
									/*in*/CComBSTR bstrPath,
									/*out*/IWbemClassObject ** ppInstance )
													
{
	HRESULT hr = WBEM_E_FAILED;				  
		
[!if IS_COMPOUND_KEY]
	ULONG ulPathTest = WBEMPATH_INFO_IS_INST_REF | WBEMPATH_INFO_IS_COMPOUND;
[!else]
[!if IS_SINGLETON]
	ULONG ulPathTest = WBEMPATH_INFO_IS_INST_REF | WBEMPATH_INFO_CONTAINS_SINGLETON;
[!else]
	ULONG ulPathTest = WBEMPATH_INFO_IS_INST_REF;
[!endif]
[!endif]
		
	if (FAILED(m_pHelper->CheckInstancePath(m_pPathFactory,
											bstrPath,
											CComBSTR(s_pMyClassName),
											ulPathTest)))
	{
		//syntax error in path or path incorrect for class provided
		return WBEM_E_INVALID_PARAMETER; 
	}			
		
[!if IS_SINGLETON]
//[!output WMICLASSNAME] is a singleton object. No need to identify the instance.
	//NOTE: If the instance is not present, uncomment the following line to communicate this back to WMI:
	//return WBEM_E_NOT_FOUND;
[!else]
	//Get path parser object:
	CComPtr<IWbemPath>pPath;
	hr = m_pPathFactory->CreateInstance(NULL,
										IID_IWbemPath,
										(void **) &pPath);
	if (FAILED(hr))
	{
		return WBEM_E_FAILED;
	}
	
	hr = pPath->SetText(WBEMPATH_CREATE_ACCEPT_ALL,bstrPath);
	if (FAILED(hr))
	{
		return hr;
	}

	CComPtr<IWbemPathKeyList> pIKeyList;
	hr = pPath->GetKeyList(&pIKeyList);
	if (FAILED(hr))
	{
		return hr;
	}
	unsigned long ulNumKeys;
	hr = pIKeyList->GetCount(&ulNumKeys);
	if(FAILED(hr))
	{
		return hr;
	}

	//Get values of key properties
	unsigned long uKeyNameBufferSize = bstrPath.Length() + 1;
	WCHAR  * wKeyName = new WCHAR[uKeyNameBufferSize];
	if (NULL == wKeyName)
	{
		return WBEM_E_OUT_OF_MEMORY;
	}
	CComVariant vValue;		
	unsigned long ulApparentCimType;
	for (unsigned long i = 0; i < ulNumKeys; i++)
	{			
		hr = pIKeyList->GetKey2(i, 0L, &uKeyNameBufferSize, 
								wKeyName, &vValue, &ulApparentCimType);			
		//TODO: save vValue for later use
	}

	delete[] wKeyName;
		
	//TODO: search your internal data source to find the matching object.
	//If no objects with required key values can be found, 
	//return WBEM_E_NOT_FOUND.
	[!endif]

	//spawn new instance
	CComPtr<IWbemClassObject> pNewInst;
	hr = m_pClass->SpawnInstance(0, &pNewInst);
	if(FAILED(hr))
	{
		return hr;
	}
	CComVariant var;

	//TODO: fill the properties of the new instance with those of the matching internal object
[!if CLASS_SPECIFIED]
	[!output POPULATE_INSTANCE]
[!else]
	//Example:
	//var.ChangeType(VT_BSTR);
	//var = <value>; //put appropriate value here
	//hr = pNewInst->Put(CComBSTR(pMyProperty), 0, &var, 0);
	//if(FAILED(hr))
	//{
	//	return hr;
	//}
	//var.Clear();		
	[!endif]

	pNewInst.CopyTo(ppInstance);

	return hr;
}

