#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}; nodenya;



void InputData(struct Node **start_ref, int data);
void bubbleSort(struct Node *start);
void tukar(struct Node *a, struct Node *b);
void cetak (struct Node *start);

int main()
{ int i ;
int pilih;
int angka;
int n;
    do
    {
        system("cls");
        printf("====================================================\n");
        printf("================ MENU PILIHAN PROGRAM ==============\n");
        printf("====================================================\n");
        printf("1. INPUT DATA\n");
        printf("2. PENGURUTAN\n");
        printf("3. CETAK\n");
        printf("4. KELUAR\n\n");
        printf("Masukan Pilihan : ");
        scanf("%d", &pilih);

        switch (pilih)
        {
            case 1 :
                    printf("Masukan Jumlah Data yang akan Dimasukan : ");
                    scanf("%i", &n);
                    int angka[n];
                    struct Node *start = NULL;
                    for (i = 0; i < n; i++)
                        InputData(&start,angka[n] );
                    break;
            case 2 :
                    bubbleSort(start);
                    system("pause");
                    break;
            case 3 :
                    printf ("\n setelah urut \n")
                    cetak(start);
                    system("pause");
                    break;
            default :
                    system("cls");
                    printf("\nTERIMA KASIH TELAH MENGGUNAKAN APLIKASI INI... SEMOGA HARI ANDA MENYENANGKAN :)\n\n");
                    break;
        }

    }while (pilih != 4);

	return 0;
}


void InputData(struct Node **start_ref, int data)
{
	struct Node *nilai = (struct Node*)malloc(sizeof(struct Node));
    nilai -> data = data;
    nilai -> next = *start_ref;
    *start_ref = nilai;
}

void Cetak(struct Node *start)
{
	struct Node *temp = start ;
    printf ("\n");
	while (temp!=NULL)
	{
        printf ("%d", temp -> data);
        temp = temp -> next;
	}
}


void bubbleSort(struct Node *start)
{
	int swapped, i;
	struct Node *nilai;
	struct Node *lptr = NULL;

	if (start == NULL)
		return;

	do
	{
	    swapped = 0;
	    nilai = start;
       while (nilai -> next != lptr)
       {
           if (nilai -> data > nilai -> next -> data)
           {
               tukar (nilai, nilai -> next);
               swapped = 1;
           }
           nilai = nilai -> next;
       }
       lptr = nilai;
	}
	while (swapped);
}

void tukar(struct Node *a, struct Node *b)
{
	int temp = a->data;
    a -> data = b -> data;
    b -> data = temp;
}
