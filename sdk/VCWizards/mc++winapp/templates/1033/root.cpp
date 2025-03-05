#include "stdafx.h"
#include "Form1.h"
#include <windows.h>

using namespace [!output SAFE_NAMESPACE_NAME];

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	System::Threading::Thread::CurrentThread->ApartmentState = System::Threading::ApartmentState::STA;
	Application::Run(new [!output CLASS_NAME_PREFIX]Form1());
	return 0;
}
