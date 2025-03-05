// This is the main project file for VC++ Windows Service project

#include "stdafx.h"
#include <string.h>
#include "[!output PROJECT_NAME]WinService.h"

using namespace [!output SAFE_NAMESPACE_NAME];
using namespace System::Text;

//To install the service, type: "[!output PROJECT_NAME].exe -Install"
int _tmain(int argc, _TCHAR* argv[])
{
	if (argc >= 2)
	{
		if (argv[1][0] == _T('/'))
		{
			argv[1][0] = _T('-');
		}

		if (_tcsicmp(argv[1], _T("-Install")) == 0)
		{
			//Install this Windows Service using InstallUtil.exe
			String* myargs[] = System::Environment::GetCommandLineArgs();
			String* args[] = new String*[myargs->Length - 1];
			args[0] = (myargs[0]);
			Array::Copy(myargs, 2, args, 1, args->Length - 1);
			AppDomain* dom = AppDomain::CreateDomain(S"execDom");
			Type* type = __typeof(System::Object);
			String* path = type->get_Assembly()->get_Location();
			StringBuilder* sb = new StringBuilder(path->Substring(0, path->LastIndexOf(S"\\")));
			sb->Append(S"\\InstallUtil.exe");
			dom->ExecuteAssembly(sb->ToString(), 0, args);
		}
	}
	else 
	{
		ServiceBase::Run(new [!output SAFE_NAMESPACE_NAME]WinService());    
	}
	return 0;
}

  