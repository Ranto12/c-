#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void bubbleSort(int arr[], int n){
  int i, j, tmp;
  for(i = 0; i < n; i++){
    for(j=0; j < n-i-1; j ++){
      if(arr[j] > arr[j+1]){
        tmp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;
      }
    }
  }
}
int NoPenulis() {
  int array[100], n, i, j;
  printf("Masukkan banyak elemen: ");
  scanf("%d", &n);

  printf("Masukkan nomor penulis: \n");

  for(i = 0; i < n; i++){
    scanf("%d", &array[i]);
  }

    bubbleSort(array, n);

  printf("Hasil pengurutan :\n");
  for(i = 0; i < n; i++){
    printf("\n%d ", array[i]);
  }
  printf("\n");
}

int main()
{
    int x;

    printf ("PENGURUTAN NOMOR DAN NAMA PENULIS");
    printf ("\n 1. Pengurutan Nomor Penulis");
    printf ("\n 2. Pengurutan Nama Penulis");
    printf ("\n 3. Selesai");
    printf ("\n Silakan Input Pilihan Anda");
    scanf("\n%i", &x);
    if (x == 1)
    {
        NoPenulis();
    }
    else
    {
        exit(0);
    }
}