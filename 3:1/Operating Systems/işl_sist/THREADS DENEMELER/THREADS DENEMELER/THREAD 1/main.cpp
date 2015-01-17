#include <iostream>
#include <windows.h>
#include <process.h>     // _beginthread() için gerekli

unsigned int WINAPI ThreadFunction( void * );   // fonksiyon prototipi
using namespace std;
int main()
{

    cout<<"Main Fonksiyonu Basladi \n";

    

	//Ýpliðimizi oluþturuyoruz. Fonksiyon dönüþ deðeri HANDLE türünde deðildir.
	//C++ da iþlem yapmak istiyorsak dönüþümleri yapmamýz gerekir.
	// (HANDLE) dönüþ deðerini HANDLE türüne çevirmek içindir.
	HANDLE hHandle = (HANDLE)_beginthreadex(0,
											0,
											ThreadFunction,
											"Merhaba",
											0,
											0);


	WaitForSingleObject(hHandle,INFINITE);
}

UINT  WINAPI ThreadFunction( void *arg )
{
	cout<<"iplige gonderilen deger......:"<<(char*)arg<<"\n";
	return 0;
}