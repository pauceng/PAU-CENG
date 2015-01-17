//Bu programdaki amaç Ýþletim sistemi üzerinde çalýþan bütün
//prosesleri ve bunlara ait bütün modülleri yazdýrmaktýr.
//bir önceki örnekte kodun büyük  bir bölümünü tek tek anlattýðým için
//Bu programda yorum sayýsý azalýyor.
//Fonksiyonlarýn sonunda A deðeri görünce þaþýrmayýn bu onlarýn 8 bitlik karakter 
//sisteminde çalýþtýðýný gösterir.
//GetProcessNameA örneðinde olduðu gibi

#include <windows.h>
#include <stdio.h>
#include <psapi.h>

#pragma comment(lib,"psapi.lib")

//Proseslerin modül listesini sadece konsole yazmaktansa bir txt dosyasý içerisine yazdýracaðýz.
//Aþaðýdaki global deðiþken dosya kontrolü için gereklidir.

FILE *File;
void PrintProcessInformation(DWORD ProcessID)
{
	//Proces ismi maksimum 260 karakter alabilir.
    char ProcessName[MAX_PATH] = "<------Bilinmiyor------>";

    // Proces handle deðeri alýnýyor.
	// Bazý proseslerin handle deðeri alýnamaz
    HANDLE hProcess = OpenProcess( PROCESS_QUERY_INFORMATION |
                                   PROCESS_VM_READ,
                                   FALSE, ProcessID );

    // Prosesin handle deðeri alýnýp alýnmadýðý kontrol edilir.

    if (hProcess != NULL  )
    {
		//Var olan bütün modülleri alacaðýmýzdan  1024 kapasiteli bir dizi oluþturdum
		//Umalýmki 1024 den fazla modül olmasýn :)
        HMODULE hMod[1024]; 

		DWORD NumBytes;
		//Proses'in ilk Modülünü yakala
        if ( EnumProcessModules(hProcess, 
								hMod, 
								sizeof(hMod), //1024 adet hMod olduðunu bu paraametre ile belirtiyoruz. Bu sayede fonksiyon bulduðu bütün modülleri yükleyecektir.
								&NumBytes) )
        {
			
			DWORD NumModule		= NumBytes/sizeof(HMODULE);
			
			//Yakalanan modülün ismi al
			GetModuleBaseNameA( hProcess, hMod[0], ProcessName, 
							   sizeof(ProcessName)/sizeof(char) );
			
			printf("\n----------------------------------------------------------------------\n");
			
			//Aþaðýdaki fonksiyonu hatýrlamadýysanýz açýklayayým. Ayný printf gibi davranýr.
			//sadeece ekrana yazacaðýna dosyaya yazar yazýsýný.
			//Ýlk parametre dosyayý kontrol eden deðiþkendir.
			
			fprintf(File,"\n----------------------------------------------------------------------\n");
			
			printf(ProcessName);
			fprintf(File,ProcessName);
			
			printf("\n----------------------------------------------------------------------\n");
			fprintf(File,"\n----------------------------------------------------------------------\n");
			for(int i = 1;i<NumModule; i++)
			{

				char ModuleName[MAX_PATH] = "isimsiz";
				
				//Yakalanan modülün ismi al
				
				GetModuleBaseNameA( hProcess, hMod[i], ModuleName, 
								   sizeof(ModuleName)/sizeof(char) );
				printf("\n----->");
				fprintf(File,"\n----->");
				printf(ModuleName);
				fprintf(File,ModuleName);

			}

        }
    }

    CloseHandle( hProcess );

}


int main(int argc,char *argv[])
{
	DWORD	NumBytes		= 0;		
	DWORD	NumProcess		= 0;
	DWORD	ProIndexes[1024];
	
	//Aþaðýdaki fonksiyon "ProsesModulListesi.txt" adýndan bir dosya oluþturup kullanýma açacaktýr.
	//bu dosyaya File deðiþkeni ile eriþeceðiz.
	//   "..\\"  anlamý bir önceki klasör demektir. (daha ne kadar derine giderim bilemiyorum)
	// Eðer bir tane \ kullanýrsanýz escape karakteri anlamýna gelmektedir. bu yüzden iki tane kullanýyoruz.
	// derleyici bir tane \ olarak algýlar .
	
	File = fopen("..\\ProsesModulListesi.txt","w");
	
	
	//Öncelikle ProIndexes dizinini sýfýrlýyoruz
	ZeroMemory(ProIndexes,sizeof(ProIndexes));


	//Sistemdeki bütün processlerin ID deðerlerini dizinimize kaydediyoruz
	EnumProcesses(ProIndexes,	//dizinin adresi
				  1024,			//dizinin eleman sayýsý
				  &NumBytes);	//Diziye yüklenen bilginin byte olarak büyüklüðü
	
	//Diziye yüklenen bilgi byte olarak gelmiþ durumda
	//Her bir bilgi 4byte yani DWORD
	//Bölüm iþlemi sonucunda diziye kaç eleman yüklenmiþ olduðunu bulacaðýz.

	NumProcess = NumBytes/sizeof(DWORD);  

	for(int i=0;i<NumProcess;i++)
	{
		PrintProcessInformation(ProIndexes[i]);
	}
	///dosyayý kontrol eden deðiþkeni kapatýyoruz
	fclose(File);
}
//Konsolumuzun buffer kýsýtlandýrmasý yüzünden bütün yazýlarý görememekteyiz.

