#include <iostream>
#include <windows.h>
#include <process.h>     
using namespace std;
unsigned  int WINAPI ThreadFunction1( void * );   
unsigned  int WINAPI ThreadFunction2( void * );  
long global = 0;
int main()
{

    cout<<"Main Fonksiyonu Baþladý \n";

	HANDLE hHandle[2];

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
}

unsigned int  WINAPI ThreadFunction1( void *arg )
{
	
	for(int i=0;i<100;i++)
	{
		global++;	
		cout<<"birinci iplik....:"<<global<<"\n";
		Sleep(50);
	}
	return 0;
}
unsigned int  WINAPI ThreadFunction2( void *arg )
{

	for(int i=0;i<100;i++)
	{
		global++;	
		cout<<"ikinci iplik....:"<<global<<"\n";
		Sleep(50);
	}
	return 0;
}