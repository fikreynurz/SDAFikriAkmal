/* File        : mainNRSL.cpp */
/* Deskripsi   : Driver / main program untuk ADT Non Restricted Single Linked/Linear List */
/* Dibuat oleh : Ade Chandra Nugraha*/
/* Tanggal     : 25-10-2001 */
/* Diupdate oleh : Santi Sundari, 6-4-2011, hanya tdd operasi2 dasar */

#include "BodyNRSL.cpp"
#include "SpNRSLL.H"
#include <stdio.h>

int main()
{
	/* Kamus Lokal */
	List MyList, List2, List3;
	int i, x;
	int Cari;
	infotype isi, nama, nama1;
	address P, Prec, O, Nm, Nm1;
	tElmtList Kota[5];

	Kota[0].info = "Bandung";
	Kota[1].info = "Batujajar";
	Kota[2].info = "Madiun";
	Kota[3].info = "Cimahi";
	Kota[4].info = "Banjaran";

	/* Program */

	/* Menambah List di awal */
	CreateList(&MyList);
	i = 4;

	/* Insertion */
	printf("List Kota: \n");
	while (i >= 0)
	{
		InsVFirst(&MyList, Kota[i].info);
		i--;
	}

	PrintInfo(MyList);

	printf("Pilih Kota: ");
	scanf("%d", x);
	switch (x)
	{
	case 1:
		if (Kota[0].next == Nil)
		{
			tambahNama(Kota[0], "Fikri");
		}
		
		break;
	
	default:
		break;
	}

	printf("Input nama yang berdomisili kota %s: \n", Kota[i].info);
	scanf(" %[^\n]", &nama);
	Nm = Alokasi(nama);
	Kota[i].next = Nm;
	scanf(" %[^\n]", &nama1);
	Nm1 = Alokasi(nama1);
	Nm->next = Nm1;

	/* Print Insertion */

	printf("Data dari kota mana yang akan anda cari: ");
	scanf("%d", &Cari);
	switch (Cari)
	{
	case 1:
		printf("Data Penduduk di Kota %s: %s, %s\n", Kota[0].info, Info(Next(Kota[0].next)), Info(Kota[0].next));
		break;
	case 2:
		Nm = Alokasi("Firman");
		Kota[1].next = Nm;

		Nm1 = Alokasi("Fanez");
		Nm->next = Nm1;
		printf("Data Penduduk di Kota %s: %s, %s\n", Kota[1].info, Info(Next(Nm)), Info(Nm));
		break;
	case 3:
		Nm = Alokasi("Ijal");
		Kota[0].next = Nm;

		Nm1 = Alokasi("Retro");
		Nm->next = Nm1;
		printf("Data Penduduk di Kota %s: %s, %s\n", Kota[2].info, Info(Next(Nm)), Info(Nm));
		break;
	case 4:
		Nm = Alokasi("Daniel");
		Kota[0].next = Nm;

		Nm1 = Alokasi("Roy");
		Nm->next = Nm1;
		printf("Data Penduduk di Kota %s: %s, %s\n", Kota[3].info, Info(Next(Nm)), Info(Nm));
		break;
	case 5:
		Nm = Alokasi("Nisa");
		Kota[0].next = Nm;

		Nm1 = Alokasi("Ica");
		Nm->next = Nm1;
		printf("Data Penduduk di Kota %s: %s, %s\n", Kota[4].info, Info(Next(Nm)), Info(Nm));
		break;
	}

	/* Mencari suatu elemen di list */

	P = Search(MyList, "tiga");
	printf("Search yang berhasil tiga : P = %d, Ketemu = %d \n", P, FSearch(MyList, P));
	// DelP (&MyList, "dua");

	/* Insert di Last */
	printf("Insert di akhir nilai (contoh) : \n");
	InsVLast(&MyList, "p");
	PrintInfo(MyList);

	/* Insert diantara 2 elemen */
	printf("Insert sebelum elemen empat  : ");
	Prec = SearchPrec(MyList, "empat");
	P = Alokasi("three");
	if (P != Nil)
	{
		InsertAfter(&MyList, P, Prec);
	}
	PrintInfo(MyList);

	/* Menghapus elemen List */
	printf("\tHasil Delete dari elemen List :\n");
	DelVFirst(&MyList, &isi);
	printf("DelVFirst adalah %s\t", isi);

	DelVLast(&MyList, &isi);
	printf("DelVLast adalah %s\t", isi);

	/* Menghapus elemen di tengah-tengah */
	Prec = SearchPrec(MyList, "empat"); /* Node yang akan dihapus */
	if (Prec != Nil)
	{
		DelAfter(&MyList, &P, Prec);
		isi = Info(P);
		DeAlokasi(P);
		printf("DelAfter adalah %s\n", isi);
	}
	printf("Hasil setelah delete : ");
	PrintInfo(MyList);

	printf("Insert sebelum elemen tiga : ");
	Prec = SearchPrec(MyList, "tiga");
	P = Alokasi("nol");
	if (P != Nil)
	{
		InsertAfter(&MyList, P, Prec);
	}
	PrintInfo(MyList);

	/* Finishing */
	P = First(MyList);
	DeAlokasi(P);
	P = First(List2);
	DeAlokasi(P);
	P = First(List3);
	DeAlokasi(P);
	return 0;
}
