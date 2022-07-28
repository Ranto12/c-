#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	string Nama;
	string cari;
	int n;
	int size;
	string target;
	cout<<"masukan jumlah yang akan dimasukan: ";
	cin >> n;
	for (int i = 0; i <n; i++)
	{
		cout<<"masukan nama anda: ";
		cin>>Nama[i];
	}
	for (int i = 0; i <n; i++)
	{
		cout<<Nama[i]<<endl;
	}

	cout<<"cari alamat yang ada: ";
	cin >>target;
	cout<<cari;
	int j;
	{
	for(j=0; j < size; j++)
		if(Nama[j] == target)
			cout << Nama[j] << endl;
		else cout << "Not Found";
	}
	
	return 0;
}

	
