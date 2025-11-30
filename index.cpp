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
        Tool(int mins) {
            minutes = mins;
        };

        // perilaku objek, bisa menghitung harga pemakaian per menit
        int countTotalTariff() {
            return price * minutes / 15;
        };

        // destructor objek, menghapus objek dalam memori
        ~Tool() = default;

};

// INHERITANCE
// objek-objek turunan dari Tool
class Dumbbell: public Tool {
    public:
        
        int price = 5000;
        Dumbbell(int mins):Tool(mins) {};
};
class Treadmill: public Tool {
    public:
        
        int price = 10000;
        Treadmill(int mins):Tool(mins) {};
};
class Barbell: public Tool {
    public:
        
        int price = 8000;
        Barbell(int mins):Tool(mins) {};
};
class StaticBike: public Tool {
    public:
        
        int price = 7000;
        StaticBike(int mins):Tool(mins) {};
};

// fungsi pembantu
void getValidMinutesInput(int minutes) {
    cout << "Masukkan berapa lama (menit dalam kelipatan 15) : ";

    while (!(cin >> minutes) || minutes % 15) {
        cout << "Masukkan salah, mohon ulangi : ";
        cin.clear();
        cin.ignore(10000, '\n');
    };
}

int main() {
    char userChoice;
    int minutes;
    int result;
    vector<unique_ptr<Tool>> toolArray;
    cout << "=================================\n";
    cout << "\t TRACKER TARIF SEWA ALAT\n";
    cout << "\t       -ARENA GYM-\n";
    cout << "=================================\n";
    while (true) {
        cout << "Pilih alat gym yang ingin dipinjam : \n";
        cout << "1. Dumbbell\n";
        cout << "2. Treadmill\n";
        cout << "3. Barbell\n";
        cout << "4. Static Bike\n\n";
        cout << "r. Reset\n";
        cout << "u. Undo\n";
        cout << "c. Hitung\n\n";

        cout << "Ketik pilihan (hitung untuk quit): ";
        cin >> userChoice;

        switch (userChoice) {
            case '1':
                getValidMinutesInput(minutes);
                toolArray.push_back(make_unique<Dumbbell>(minutes));
                break;
            case '2':
                getValidMinutesInput(minutes);
                toolArray.push_back(make_unique<Treadmill>(minutes));
                break;
            case '3':
                getValidMinutesInput(minutes);
                toolArray.push_back(make_unique<Barbell>(minutes));
                break;
            case '4':
                getValidMinutesInput(minutes);
                toolArray.push_back(make_unique<StaticBike>(minutes));
                break;

            case 'r':
                toolArray.clear();
                break;
            case 'u':
                toolArray.pop_back();
                break;
            case 'c':
                for (auto& tool : toolArray) {
                    result += tool->countTotalTariff();
                };

                cout << "Total tariff yang harus dibayar : " << result << endl;
                break;
        };

        if (userChoice == 'c') {
            break;
        };

    };

    return 0;
}