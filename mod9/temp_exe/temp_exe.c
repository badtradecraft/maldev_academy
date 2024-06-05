#include <windows.h>

//Construct a new data type that represents HelloWorld's function pointer
typedef void (WINAPI* HelloWorldFunctionPointer)();

void call() 
{
	//Attempt to get handle of the DLL that is already in memory
	HMODULE hModule = GetModuleHandleA("babysteps.dll");
	
	//Load the DLL if it is not already using LoadLibrary
	if (hModule == NULL) 
	{
		hModule = LoadLibraryA("babysteps.dll"); //hModule now contains babysteps.dll's handle
	}
	
	PVOID pHelloWorld = GetProcAddress(hModule, "HelloWorld"); //pHelloWorld stores HelloWorld's function address

	HelloWorldFunctionPointer HelloWorld = (HelloWorldFunctionPointer)pHelloWorld;

	//invoke HelloWorld
	HelloWorld();

}

int main()
{
	call(); //invoke the call() function
	return 0;
}

