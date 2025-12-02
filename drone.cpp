// Program drone - level kecepatan
#include <iostream>
using namespace std;

int main()
{
    int speed;
    cout << "PROGRAM MENGHITUNG LEVEL KECEPATAN DRONE \n\n";
	cout << "Masukkan kecepatan (kmph) :    ";
	cin >> speed;
	
	cout << "Kecepatan Drone memiliki level : ";
	
    if (speed >= 120) {
        cout << "    Ultra\n";
    } else 
    if (speed >= 80 ) {
        cout << "    Advanced\n";
    } else
    if (speed >= 40) {
        cout << "    Intermediate\n";
    } else {
        cout << "    Basic\n";   
    }
    
    return 0;
}