// lab2.cpp : Defines the entry point for the console application.
#include "stdafx.h"
//CreateProsess fonksiyonun ilk parametresini boþ girmek yerine
//direkt olarak çalýþtýrýlacak programýn adýný yazmayý deneyin
//Yolu doðru yazmayý unutmayýn
#include <windows.h>
#include <stdio.h>
//main fonksiyonun ilk parametresi ikinci parametrenin kaç adet elemaný olduðunu belirtir.
//Ýkinci parametre bir string dizisidir. C dilinde karakter dizileri "char *" þeklinde tanýmlanýr.
int main(int argc,char *argv[])
{
	//argv[0]  bu prosesin tam yolunu barýndýracaktýr.
	//Bu iþletim sistemi tarafýndan girilir.
	//argv deðeri Command Line Arguments adý ile anýlýr
	//Oluþturulacak prosesin baþlangýç bilgilerini belirleyen
	//struct yani yapýdýr. fonksiyonu olmayan sýnýf gibi düþünülebilir.
	//asýl ismi STARTUPINFO dur. fakat bu yapý 16bit karakter düzenine göre tasarlanmýþtýr.
	//Bu yüzden bir 8-bit lik karakter düzenine göre tasarlanmýþ olan STARTUPINFOA ile 
	//çalýþacaðýz.

	printf("Process'in tam yolu: %s\n\n\n", argv[0]);
	printf("Maine gelen dizinin 1. indexi: %s\n\n\n", argv[1]);
	STARTUPINFOA si;
	 
	//Oluþturulan prosesin daha sonradan kontrol edilebilmesi için gereken
	//bilgiler ile doldurulur. CreateProsess eðer doðru dönerse bu parametrenin
	//içerisini de gerekli bilgiler ile dolduracaktýr.
	PROCESS_INFORMATION pi;

	//C dilinde bir deðiþken oluþturulduðunda ilk deðer olarak atandýðý hafýza alanýnda 
	//ne varsa onu alýr. Bu saçma sapan bir deðer olabilir. Bu yüzden kullanmadan önce
	//hafýza alanýný sýfýrlamalýyýz. Aþaðýdaki fonksiyon bu iþi görür.
	// & iþareti si deðiþkeni ile beraber kullanýldýðýnda adres belirtir. si deðiþkeninin
	//adresini ikinci parametre de ise si deðiþkeninin hafýzada kapladýðý alan girilmiþtir.
	printf("Si'nin size		: %i\n" ,sizeof(si));
	printf("Pi'nin size		: %i\n\n", sizeof(pi));
	ZeroMemory( &si, sizeof(si) );
    //si yapýsýnýn ilk parametresi yapýnýn kendi boyutunu bekler.
	//sizeof fonksiyonu yapýlarýn hafýzada ne kadar yer kapladýðýný belirler.
	
	si.cb = sizeof(si);
    
	//Þimdide ikinci yapýnýn adres alanýný sýfýrlýyoruz
	ZeroMemory( &pi, sizeof(pi) );
	//argc 2 den küçük ise prosesimiz üzerine baþka bir proses sürüklenmemiþ demektir.
	//Yani proses klasik yöntemle üzerine çift týklanarak çalýþtýrýlmýþtýr.
	//Bir programýn üstüne çift týklanarak çalýþtýrýldýðýnda argc 1 olacaktýr.
    if( argc <2 )
    {
        printf("Girilen Tek Parametre: %s \n", argv[0]);
        return 0;
    }
	//Fonskyionun aslý CreateProsess dir. Fakat biz 8-bit karakterler
	//kullandýðýmýzdan dolayý CreateProsessA versiyonu kullanýyoruz.
	//Ýki fonksiyon arasýndaki tek fark karakter sistemidir.

    if( !CreateProcessA( NULL,  // Çalýþtýrýlacak programýn adý
        argv[1],				// Command line arguments
        NULL,					// Process handle kalýtýmsal deðil
        NULL,					// Thread handle kalýtýmsal deðil
        FALSE,					// Process in kernel objeleri kalýtýmsal deðil
		CREATE_NEW_CONSOLE,					// Oluþturulma bayraðý yok
        NULL,					// Ana processin çevre deðiþkenlerini kullan
        NULL,					// Ana processin klasörünü varsayýlan klasör olarak kullan
        &si,					// STARTUPINFO yapýsýna adresi
        &pi )					// PROCESS_INFORMATION yapýsýna adresi
    ) 
    
	{
        printf( "CreateProcess Hatali(%d).\n", GetLastError() );
        return 0;
    }

	//aþaðýdaki fonksiyon prosesimizi istenen olay gerçekleþene kadar 
	//beklemeye alacaktýr. Aþaðýdaki istenen olay ise
	//oluþturulan çocuk prosesin bitmesini beklemekitir.
	//ilk parametresi oluþturduðumuz prosesin handle deðeridir.
	//Ýkinci parametre ise bekleme durumunu belirtmektedir.
	//INFINITE deðeri proses bitene kadar beklememizz gerektiðini söylemektedir.
   
	WaitForSingleObject( pi.hProcess, INFINITE );
	
	
	
	printf("Sonunda Process bitti");
    Sleep(10000);
	
	// Çocuk process in handle larýný sonlandýr. 
	//Bu sayede çocuk proses ve ona ait threading kernel nesnelerinin sayacý 1 azaltýlacaktýr.
	//Çünkü bu proses artýk onlarý kullanmadýðýný belirtti
	CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );

	scanf("%i", &argc);
}