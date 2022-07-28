#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char nama[100];
	double nilai_tugas, nilai_hasil;
	int jumlah_mk;
	printf("input nama anda sayang:");
	gets(nama);


	printf("Selamat belajar sayang %s\n",nama );
	scanf("%d", &jumlah_mk);
	printf("masukan nilai- nilai kamu : !" );
	for (int i = 0; i <jumlah_mk; i++)
	{
		scanf("%d", nilai_tugas);
	}
	
	return 0;
	
}