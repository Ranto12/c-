#include <iostream>
using namespace std;

int main(){
	char pilihan;
	float nilai1;
	float nilai2;
	float jumlah;
	cout<<"KALKULATOR SEDERHANA\n\n";
	cout<<"masukan pilihan kalian: \n";
	cout<<"a. penjumlahan\n";
	cout<<"b. pengurangan\n";
	cout<<"c. pembagian\n";
	cout<<"d. perkalian\n";
	cout<<"pilih: ";
	cin>>pilihan;
	switch(pilihan){
		case 'a':
		cout<<"masukan nilai pertama: ";
		cin>>nilai1;
		cout<<"masukan nilai kedua: ";
		cin>>nilai2;
		jumlah=nilai1+nilai2;
		cout<<"jadi hasil dari"<<nilai1<<" + "<<nilai2<<"adalah : "<<jumlah; 
		break;
		case 'b':
		cout<<"masukan nilai pertama: ";
		cin>>nilai1;
		cout<<"masukan nilai kedua: ";
		cin>>nilai2;
		jumlah=nilai1-nilai2;
		cout<<"jadi hasil dari "<<nilai1<<" - "<<nilai2<<" adalah : "<<jumlah; 
		break;
		case 'c':
		cout<<"masukan nilai pertama: ";
		cin>>nilai1;
		cout<<"masukan nilai kedua: ";
		cin>>nilai2;
		jumlah=nilai1/nilai2;
		cout<<"jadi hasil dari"<<nilai1<<" / "<<nilai2<<"adalah : "<<jumlah;
		break;
		case 'd':
		cout<<"masukan nilai pertama: ";
		cin>>nilai1;
		cout<<"masukan nilai kedua: ";
		cin>>nilai2;
		jumlah=nilai1*nilai2;
		cout<<"jadi hasil dari"<<nilai1<<" x "<<nilai2<<"adalah : "<<jumlah;
		break;



	}
}