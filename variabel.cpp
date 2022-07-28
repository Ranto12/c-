#include <iostream>
using namespace std;
int main()
{
	deklarasi variabel
	int jumah_siswa; // int adalah singaktan dari integer
	cout<<"masukan jumlah siswa: ";
	cin >> jumah_siswa;
	cout<<jumah_siswa;
	float nilai_siswa;
	cout<<"masukan nilai siswa: ";
	cin >> nilai_siswa;
	cout<<"nilai siswa adalah: "<<nilai_siswa;
	char abjad_awal = 'A';
	char abjad_kedua= 'B';
	cout<< abjad_kedua<<" "<<abjad_awal;
	char pilihan;
	cout<<"\nmasukan A-D untuk mengetahui nilai anda : ";
	cin >>pilihan;
	switch(pilihan){
		case 'A':
		cout<<"anda mendapatakan nilai sangat baik";break;
		case'B':
		cout<<"anda mendapatkan nilai baik";break;
		case 'C':
		cout<<"anda mendapatkan nilai cukup";break;
		case 'D': 
		cout<<"anda mendapatkan nilai kurang";break;

	}
	bool nilai_benar=false;
	bool nilai_salah=false;
	cout<< nilai_benar<<endl;
	cout<<nilai_salah;


	return 0;
}
