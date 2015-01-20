#include <iostream>
#include <windows.h>
#include <process.h>     
using namespace std;

UINT WINAPI ThreadFunction1( void * );   
UINT WINAPI ThreadFunction2( void * );  

long global = 0;
FILE *pFile;
CRITICAL_SECTION cs;
int main()
{

    cout<<"Main Fonksiyonu Baþladý \n";

	HANDLE hHandle[2];

	pFile = fopen("Deneme.txt","w");
	hHandle[0] = (HANDLE)_beginthreadex(0,
											0,
											ThreadFunction1,
											0,
											0,
											0);
	hHandle[1] = (HANDLE)_beginthreadex(0,
											0,
											ThreadFunction2,
											0,
											0,
											0);
	//Aþaðýdaki fonskiyon birden fazla ipliðin beklenmesi için kullanýlabilir
	//Ýlk parametre beklenecek iplik sayýsý. Ýkinci parametre iplik handle dizisi
	//üçüncü parametre beklemenin bütün iplikleri etkileyip etkilemiyeceði
	//Son parametre bekleme süresi.
	WaitForMultipleObjects(2,hHandle,true,INFINITE);
	DeleteCriticalSection(&cs);
	fclose(pFile);
}

UINT  WINAPI ThreadFunction1( void *arg )
{
	InitializeCriticalSection(&cs);
	EnterCriticalSection(&cs);
	for(int i=0;i<1000;i++)
	{
		fprintf(pFile,"%s","Thread....1\n");
	}
	Sleep(50);
	//LeaveCriticalSection(&cs);
	return 0;
}
UINT  WINAPI ThreadFunction2( void *arg )
{
	EnterCriticalSection(&cs);
	for(int i=0;i<1000;i++)
	{
		fprintf(pFile,"%s","Thread....2\n");
	}
	Sleep(50);
	LeaveCriticalSection(&cs);

	return 0;
}