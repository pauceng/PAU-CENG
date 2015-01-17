select ParcaID from TEDARIK;

select ParcaAdi, Agirlik from PARCA where Renk='kirmizi';

select ParcaAdi, Renk from PARCA where ParcaID=(select ParcaID from TEDARIK where ProjeID=(select ProjeID from PROJE where ProjeAdi='J2'));

select ParcaAdi, Renk from PARCA where ParcaID=(select ParcaID from TEDARIK where ProjeID=(select ProjeID from PROJE where Sehir='Londra'));


select count(*) from TEDARIKCI

--select TedarikciAdi from TEDARIKCI where TedarikciID=(select TedarikciId from TEDARIK where ParcaID=(select ParcaID from PARCA where Renk='Kýrmýzý'))
--Parcalar tablosunda birden fazla kýrmýzý renkli parca olduðu için "Joinle" yapuýlmalý

--1) P2 parçasýný tedarik eden tedarikçi adi
--2) P5 parçasýný tedarik eden tedarikçi adý ve kullanýldýðý proje adlarý