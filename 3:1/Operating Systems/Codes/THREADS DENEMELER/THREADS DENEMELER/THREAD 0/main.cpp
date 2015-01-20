#include <windows.h>
#include <iostream>
using namespace std;
DWORD WINAPI ThreadFunction(void * pwParam)
{
	char *pText = (char*)pwParam;
	cout<<"Ýpliðin Parametresi......: "<<pText<<"\n";
	return 0;
}

int main()
{
	DWORD ThreadID;

	HANDLE hThread = CreateThread(NULL,
								  NULL,
								  ThreadFunction,
								  "Merhaba",
								  0,
								  &ThreadID);
	WaitForSingleObject(hThread,INFINITE);
	return 0;
}