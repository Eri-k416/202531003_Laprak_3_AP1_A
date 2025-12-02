#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

class Tool {
    public:
        // properti objek
        int minutes;
        int price;
        // constructor objek, membuat objek di memori
        Tool(int mins, int p) {
            minutes = mins;
            price = p;
        };
        // perilaku objek, bisa menghitung harga pemakaian per menit
        long int countTotalTariff() {
            return price * minutes / 15;
        };
        // destructor objek, menghapus objek dalam memori
        ~Tool() = default;
};

// INHERITANCE
// objek-objek turunan dari Tool
class Dumbbell: public Tool {
    public:
        
        Dumbbell(int mins):Tool(mins, 5000) {};
};
class Treadmill: public Tool {
    public:
        
        Treadmill(int mins):Tool(mins, 10000) {};
};
class Barbell: public Tool {
    public:

        Barbell(int mins):Tool(mins, 8000) {};
};
class StaticBike: public Tool {
    public:
        
        StaticBike(int mins):Tool(mins, 7000) {};
};

// fungsi pembantu
void getValidMinutesInput(int& minutes) {
    cout << "Masukkan berapa lama (menit dalam kelipatan 15) : ";

    while (!(cin >> minutes) || minutes % 15) {
        cout << "Masukkan salah, mohon ulangi : ";
        cin.clear();
        cin.ignore(10000, '\n');
    };
};

int main() {
    char userChoice;
    int minutes;
    long int result = 0;
    vector<unique_ptr<Tool>> toolArray;
    cout << "=================================\n";
    cout << "\t TRACKER TARIF SEWA ALAT\n";
    cout << "\t       -ARENA GYM-\n";
    cout << "=================================\n";
    while (userChoice != 'c') {
        cout << "Pilih alat gym yang ingin dipinjam : \n";
        cout << "1. Dumbbell\n";
        cout << "2. Treadmill\n";
        cout << "3. Barbell\n";
        cout << "4. Static Bike\n\n";
        cout << "r. Reset\n";
        cout << "u. Undo\n";
        cout << "c. Hitung\n\n";

        cout << "Ketik pilihan (hitung untuk ): ";
        cin >> userChoice;

        switch (userChoice) {
            case '1':
                getValidMinutesInput(minutes);
                toolArray.push_back(make_unique<Dumbbell>(minutes));
                cout << "Berhasil dimasukkan!\n\n";
                break;
            case '2':
                getValidMinutesInput(minutes);
                toolArray.push_back(make_unique<Treadmill>(minutes));
                cout << "Berhasil dimasukkan!\n\n";
                break;
            case '3':
                getValidMinutesInput(minutes);
                toolArray.push_back(make_unique<Barbell>(minutes));
                cout << "Berhasil dimasukkan!\n\n";
                break;
            case '4':
                getValidMinutesInput(minutes);
                toolArray.push_back(make_unique<StaticBike>(minutes));
                cout << "Berhasil dimasukkan!\n\n";
                break;

            case 'r':
                toolArray.clear();
                cout << "Berhasil direset!\n\n";
                break;
            case 'u':
                toolArray.pop_back();
                cout << "Undo berhasil!\n\n";
                break;
            case 'c':
                for (auto& tool : toolArray) {
                    result += tool->countTotalTariff();
                };
                toolArray.clear();
                cout << "Total tariff yang harus dibayar : Rp." << result << endl;
                break;
            default:
                cout << "Pilihan tidak valid.\n\n";
                cin.ignore(10000, '\n');
                break;
        };
        if (userChoice == 'c') {
            break;
        };
    };
    return 0;
};