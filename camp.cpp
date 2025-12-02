// Program  survival camp - level peralatan
#include <iostream>
using namespace std;

int main()
{
    int age;
    cout << "PROGRAM PENENTUAN LEVEL PERALATAN SURVIVAL CAMP \n\n";
	cout << "Masukkan umur (tahun) :    ";
	cin >> age;
	
	cout << "Peralatan camping dapat memilih level : \n";
	cout << "1. Starter\n";
    if (age >= 10) {
        cout << "2. Basic\n";
        if (age >= 16) {
             cout << "3. Pro\n";
             if (age >= 21) {
                    cout << "4. Expert\n";
             };  
        }; 
    };
    
    return 0;
};