
#include <windows.h>
#include <stdio.h>

//main fonksiyonun ilk parametresi ikinci parametrenin kaç adet elemaný olduðunu belirtir.
//Ýkinci parametre bir string dizisidir. C dilinde karakter dizileri "char *" þeklinde tanýmlanýr.
//
int main(int argc, char *argv[])
{
	for(int i=0;i<60;i++)
	{
		printf("%i....Merhaba \n",i);
		Sleep(100);//Prosesin ana threadini 100 milisaniye bekleme moduna alýr
	}
}