#include <iostream>
#include <windows.h>
#include <process.h>     
using namespace std;

UINT WINAPI ThreadFunction1( void * );   
UINT WINAPI ThreadFunction2( void * );  

long global = 0;
FILE *pFile;
CRITICAL_SECTION cs;
INT64	StartTick = 0;
int main()
{

    cout<<"Main Fonksiyonu Baþladý \n";

	HANDLE hHandle[2];
	
	QueryPerformanceCounter((LARGE_INTEGER*)&StartTick);
	
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
	for(int i=0;i<1000;i++)
	{
		
		InitializeCriticalSectionAndSpinCount(&cs,1000);
		{
			INT64	LastTickCount = 0;
			INT64	PassTickCount = 0;

			QueryPerformanceCounter((LARGE_INTEGER*)&LastTickCount);
		
			PassTickCount =LastTickCount-StartTick;
			
			char strTick[256];
			
			ZeroMemory(strTick,sizeof(strTick));
			
			_i64toa_s(PassTickCount,strTick,256,10);

			fprintf(pFile,"111111111111...Thread ...:%s \n",strTick);
		}
		LeaveCriticalSection(&cs);
		Sleep(5);

	}
	return 0;
}
UINT  WINAPI ThreadFunction2( void *arg )
{
	for(int i=0;i<1000;i++)
	{
		InitializeCriticalSectionAndSpinCount(&cs,1000);
		{	
			INT64	LastTickCount = 0;
			INT64	PassTickCount = 0;

			QueryPerformanceCounter((LARGE_INTEGER*)&LastTickCount);
		
			PassTickCount =LastTickCount-StartTick;
			
			char strTick[256];
			
			ZeroMemory(strTick,sizeof(strTick));
			
			_i64toa_s(PassTickCount,strTick,256,10);

			fprintf(pFile,"222222222222...Thread ...:%s \n",strTick);
		}
		LeaveCriticalSection(&cs);
		Sleep(5);

	}

	return 0;
}