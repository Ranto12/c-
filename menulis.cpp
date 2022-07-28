#include <iostream>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <chrono>
#include <thread>
using namespace std;


class penjualan
{
public:
	float harga,total;
	int jumlah;
	string namabarang;

};

class identitas
{
public:
	string nama;
	int nomorhp;
	int nomorantrian;

	
};



int main()
{
	cout<<"program ini adalah program yang digunakan untuk pusat perbelanjaan di sebuah toko\n";
	cout<<"dengan demikian anda hars mematuhi peraturan yang ada disini\n";
	cout<<"anda harus memasukan persaratan sebagai berikut: \n";
	cout<<"masukan nama anda: ";

	identitas pelanggan1;
	cin >>pelanggan1.nama;
	cout<<"masukan nomor hp anda: ";
	cin >>pelanggan1.nomorhp;
	cout<<"masukan nomor antrian: ";
	cin >>pelanggan1.nomorantrian;
	cout<<"loading";
	for (int i = 0; i <pelanggan1.nomorantrian; i++)
	{
		cout<<".";
		this_thread::sleep_for(1s);
	}

	penjualan penjualan1;
	cout<<"\nmasukan belajaan anda: ";
	cin>>penjualan1.namabarang;
	cout<<"masukan jumlah barang anda: ";
	cin>>penjualan1.jumlah;
	cout<<"masukan harga barang anda: ";
	cin>>penjualan1.harga;

	//penjumlahan barang 
	cout<<"jadi total uang yang harus anda bayar adalah: ";
	penjualan1.total=penjualan1.harga * penjualan1.harga;
	cout<<penjualan1.total;




	return 0;
}