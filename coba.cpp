#include <iostream>
using namespace std;

void konversi(){
	double suhu, C, R, K, F;
	char pilihan;
	cout<<"masukan nilai suhu yang akan di konversi: ";
	cin >> suhu;
	cout<<"\n silakan pilih metode mana yang mau digunakan: \n";
	cout<<"\n a. celcius ke reamur";
	cout<<"\n b. celcius ke Farenheat";
	cout<<"\n c. celcius ke kelvin";

	cin >>pilihan;
	switch(pilihan){
		case 'a':
		R = (suhu + 273.15) * 9/5;
		cout << R;
		case 'b':
		F = ((9/5) * suhu )+ 32;
		cout<<F;
		case 'c':
		K = suhu + 273.15;
		cout<<K;

	}
}


int main()
{
	
	konversi();
	
	
	return 0;
}





//  Rumus konversi suhu Celcius ke Fahrenheit: 
//         ⁰F = (9/5) × ⁰C + 32

// 2. Rumus konversi suhu Celcius ke Kelvin:
//         K= ⁰C + 273,15

// 3. Rumus konversi suhu Celcius ke Reamur:
//         ⁰R = (4/5) ⁰C

// 4. Rumus konversi suhu Celcius ke Rankine:
//         ⁰Ra = (⁰C + 273.15) × 9/5