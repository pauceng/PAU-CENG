// Bu programdaki amaç iþletim sisteminde çalýþan bütün processlerin
// isimlerini ekrana yazdýrmaktýr.Bu iþlem için EnuProcess API fonksiyonu kullanýlmaktadýr.
// Fonksiyon sistem üzerinde çalýþan bütün proseslerin ID deðerlerini yakalayabilir.

#include <windows.h>
#include <stdio.h>
//EnumProcess fonksiyonu psapi.h kütüphanesi içerisinde tanýmlanmýþtýr.

#include <psapi.h>

//Aþaðýdaki komut satýrý kodumuzu psapi.lib adlý statik kütüphaneye baðlamamýzý saðlar.
//Statik kütüphaneler yolu ile psapi.dll dosyasýný kullanabiliyoruz.
//EnumProcess fonksiyonun gövdesi bütün API fonksiyonlarýnda olduðu gibi bir DLL dosyasý
//içindedir. Bu yüzden psapi.dll dosyasý içerisine baðlanmak þarttýr.

#pragma comment(lib,"psapi.lib")

//Aþaðýdaki fonksiyon ID si verilen prosesin ismini yazdýrýr.
void ProsesBilgileriniYazdir(DWORD ProcessID)
{
	//Proces ismi maksimum 260 karakter alabilir. MAX_PATH in karþýlýðý 260 dýr.
   
	char	ProcessName[MAX_PATH] = "<------Bilinmiyor------>";

    //Aþaðýdaki fonksiyon ID si bilinen procesin handle deðerini döndürür
	//Ve bunu kendi prosesimizin handle tablosuna kopyalar. Bu sayede artýk
	//diðer prosesin kernel nesnesini kullanabileceðiz. Fonksiyon dönüþ
	//deðeri olarak proses çekirdek nesnesinin handle deðerini döndürür.
	//Þunu unutmamak gerek döndürülen handle deðeri ID si verilen prosesin
	//çekirdek nesnesine eriþilebilecek þekilde ayarlanýr.
    
	HANDLE hProcess = OpenProcess( PROCESS_QUERY_INFORMATION |
                                   PROCESS_VM_READ,
                                   FALSE, ProcessID );

    // Prosesin handle deðerinin alýnýp alýnmadýðý kontrol edilir.
	// Eðer NULL ise prosesin handle deperi alýnamamýþtýr.
	// Bunun sebebi prosesin güvenlik ayarlarý olabilir.
    
	if (hProcess != NULL  )
    {
		//Prosesin Modüllerini yakalamaya geldi sýra. 
		//Modülden kasýt prosesin kullandýðý DLL ve kendi exe dosyasýdýr.
		//Zaten modül listesinin ilk sýrasýnda prosesin exe dosyasý bulunmakatadýr.
        //Ýlk olarak modül türünde bir deðiþken oluþturuyoruz.
		//Bir tane modül yükleneceðinden hMod[1024] gibi bir dizi tanýmlamadýk.
		HMODULE hMod;
        
		//DWORD long tipinde bir deðiþkendir.Kafanýz karýþmasýn
		
		DWORD cbNeeded;
		
		//Aþaðýdaki fonksiyon prosesin modüllerini yakalamak için kullanýlýr.
		//Fonksiyon if bloðu içine alýnmýþtýr. Yani eðer fonksiyon false döndürür ise 
		//isim alma iþlemi baþarýlamayacaktýr.
        if ( EnumProcessModules( hProcess,		//Prosesin handle deðeri
								&hMod,			//Modülü tutacak deðiþkenin adresi
								sizeof(hMod),	//yüklenecek modülün boyutu. Modüllerin sadece bir tanesi yüklenecektir.
								&cbNeeded) )	//Fonksiyonun yüklediði toplam byte deðeri
        {
			//Yakalanan modülün ismi al
            GetModuleBaseNameA( hProcess,		//Prosesin handle deðeri	
								hMod,			//Ýsmi alýnacak modül
								ProcessName,	//Ýsmin yükleneceði deðiþkenin adý
								260 );			//ProcessName deðiþkeninin eleman sayýsý. 260 karakter olarak belirlemiþtik.
        }
    }
	
	//Eðer isim <------Bilinmiyor------> ise yazdýrmýyoruz
	//Bunun anlamý modül ismi almayý baþaramamýz demektir.
	if(strcmp(ProcessName,"<------Bilinmiyor------>")!=0)
	{
		printf(ProcessName);
		printf("\n");
	}
	
	//Proses le iþimiz bittiðinde ona ait handle deðerini kapatmalýyýz.
	//Biliyoruzki prosesin çekirdek nesnesini  handle deðeri sayesinde kullandýk.
	//Bu handle deðeri þuan kodunu yazdýðýmýz prosesin handle tablosuna eklenmiþtir.
	//Eðer bu handle deðerini silmezsek çekirdek nesnesini hala kullanýyoruz anlamýna gelmektedir.
	// bu yüzden çekirdek nesnesinin asýl sahibi proses kapansa dahi sistem nesneyi bizim
	// hala kullandýðýmýzý düþünerek nesneyi kaldýrmayacaktýr.
    CloseHandle( hProcess );

}

//DWORD microsft'un long deðiþkeni için kullandýðý isimdir. þaþýrmayýn
//Büyük bir sayý deðiþkenidir.

int main(int argc,char *argv[])
{
	DWORD	NumBytes		= 0;//fonksiyonun diziye aktardýðý toplam byte deðeri		
	DWORD	NumProcess		= 0;//Proses sayýsýný tutacak olan deðiþken
	DWORD	ProIndexes[1024];	//Proses indexlerini tutacak olan dizi

	//Öncelikle ProIndexes dizisini sýfýrlýyoruz
	
	ZeroMemory(ProIndexes,sizeof(ProIndexes));


	//Sistemdeki bütün processlerin ID deðerlerini dizimize kaydediyoruz
	
	EnumProcesses(ProIndexes,	//dizinin adresi
				  1024,			//dizinin eleman sayýsý
				  &NumBytes);	//Diziye yüklenen bilginin byte olarak büyüklüðü
	
	//Diziye yüklenen toplam byte sayýsýný NumBytes Deðiþkeninden alabiliriz.
	//Her bir proses ID si 4byte dýr. DWORD 4 byte dýr. 
	//Eðer NumBytes kadar deðer yüklenmiþ ise NumBytes/4 bize proses sayýsýný verir


	NumProcess = NumBytes/sizeof(DWORD);  

	for(int i=0;i<NumProcess;i++)
	{
		//Her bir proses için bilgi yazdýran fonksiyonu çaðýrýyoruz.
		ProsesBilgileriniYazdir(ProIndexes[i]);
	}
}
