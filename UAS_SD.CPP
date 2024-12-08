#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <vector>
using namespace std;

void printLine(char ch = '=', int length = 50) {
    for (int i = 0; i < length; i++) {
        cout << ch;
    }
    cout << endl;
}

void printHeader() {
    printLine('*', 50);
    cout << "*        SELAMAT DATANG DI TOKO (GO GURL)        *" << endl;
    printLine('*', 50);
    cout << endl;
}

void displayMenu() {
    printLine('-', 50);
    cout << "                  MASUK KE MENU" << endl;
    printLine('-', 50);
    cout << "| 1 | Pilih kategori belanja                  |" << endl;
    cout << "| 2 | List belanja                            |" << endl;
    cout << "| 3 | Pembayaran                              |" << endl;
    cout << "| 0 | Exit                                    |" << endl;
    printLine('-', 50);
}


string getCurrentTime() {
    time_t now = time(0);
    tm *localTime = localtime(&now);
    char buffer[100];
    strftime(buffer, sizeof(buffer), "%H:%M:%S pada %d/%m/%Y", localTime);
    return string(buffer);
}

string getFilename(const string& nama) {
    time_t now = time(0);
    tm *localTime = localtime(&now);
    char buffer[50];
    strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", localTime);
    return nama + "_" + buffer + ".txt";
}

void saveReceipt(const string& nama, double amount) {
    string filename = getFilename(nama);
    ofstream file(filename);
    if (file.is_open()) {
        file << "===========================\n";
        file << "       STRUK PEMBAYARAN\n";
        file << "===========================\n";
        file << "Nama Pelanggan: " << nama << endl;
        file << "Jumlah Pembayaran: Rp" << fixed << setprecision(2) << amount << endl;
        file << "Waktu Pembayaran: " << getCurrentTime() << endl;
        file << "===========================\n";
        file << "   Terima kasih telah\n";
        file << "   berbelanja di Toko (GO GURL)!\n";
        file << "===========================\n";
        file.close();
        cout << "Struk pembayaran berhasil disimpan sebagai '" << filename << "'\n";
    } else {
        cout << "Gagal menyimpan struk pembayaran.\n";
    }
}

void paymentMenu(const string& nama) {
    double amount;
    cout << "=== Menu Pembayaran ===\n";
    cout << "Pembayaran atas nama: " << nama << endl;
    cout << "Masukkan jumlah pembayaran: ";
    cin >> amount;

    cout << "\nMemproses pembayaran...\n";
    cout << "Pembayaran untuk " << nama << " sebesar Rp" << fixed << setprecision(2) << amount
         << " berhasil.\n";
    cout << "Waktu Pembayaran: " << getCurrentTime() << endl;

    saveReceipt(nama, amount);
}

void printFarewell(const string& nama) {
    int totalWidth = 50;
    int nameLength = nama.length();
    int padding = totalWidth - 2 - 14 - nameLength;
    int leftPadding = padding / 2;
    int rightPadding = padding - leftPadding;

    printLine('*', totalWidth);
    cout << "*" << string(leftPadding, ' ') << "SAMPAI JUMPA, " << nama << string(rightPadding, ' ') << "*" << endl;
    printLine('*', totalWidth);
}


void displayCategoryMenu() {
    printLine('-', 50);
    cout << "             PILIH KATEGORI BELANJA" << endl;
    printLine('-', 50);
    cout << "| 1 | Konsumsi                              |" << endl;
    cout << "| 2 | Elektronik                            |" << endl;
    cout << "| 3 | Kecantikan                            |" << endl;
    cout << "| 4 | Olahraga                              |" << endl;
    cout << "| 5 | Mainan                                |" << endl;
    cout << "| 0 | Kembali ke menu utama                 |" << endl;
    printLine('-', 50);
}

void displayItems(const string& category, const vector<string>& items) {
    cout << "List barang " << category << ":" << endl;
    for (size_t i = 0; i < items.size(); ++i) {
        cout << i + 1 << ". " << items[i] << endl;
    }
    cout << "0. Kembali ke menu kategori" << endl;
}

void categoryMenu() {
    int categoryChoice;
    do {
        displayCategoryMenu();
        cout << "Pilih kategori [0-5]: ";
        cin >> categoryChoice;
        cin.ignore();

        vector<string> items;
        string category;

        switch (categoryChoice) {
            case 1:
                category = "Konsumsi";
                items = {
                    "Beras - Rp50,000", "Mi Instan - Rp3,000", "Minyak Goreng - Rp20,000", "Telur - Rp25,000",
                    "Gula - Rp15,000", "Kopi - Rp10,000", "Teh - Rp8,000", "Roti - Rp12,000",
                    "Cokelat - Rp18,000", "Susu - Rp22,000", "Buah Apel - Rp30,000", "Jeruk - Rp28,000",
                    "Daging Sapi - Rp120,000", "Ikan - Rp45,000", "Sayur Bayam - Rp5,000"
                };
                break;
            case 2:
                category = "Elektronik";
                items = {
                    "Smartphone - Rp2,500,000", "Laptop - Rp7,500,000", "Tablet - Rp3,200,000", "Televisi - Rp4,000,000",
                    "Kipas Angin - Rp250,000", "AC - Rp3,000,000", "Kulkas - Rp2,800,000", "Mesin Cuci - Rp2,500,000",
                    "Setrika - Rp300,000", "Speaker - Rp1,000,000", "Headphone - Rp800,000", "Mouse - Rp150,000",
                    "Keyboard - Rp350,000", "Power Bank - Rp500,000", "Charger - Rp200,000"
                };
                break;
            case 3:
                category = "Kecantikan";
                items = {
                    "Lipstik - Rp100,000", "Bedak - Rp85,000", "Maskara - Rp120,000", "Foundation - Rp150,000",
                    "Parfum - Rp300,000", "Pelembap - Rp90,000", "Serum Wajah - Rp200,000", "Sabun Muka - Rp75,000",
                    "Shampoo - Rp50,000", "Conditioner - Rp55,000", "Lulur - Rp40,000", "Masker Rambut - Rp60,000",
                    "Cat Kuku - Rp25,000", "Sunblock - Rp70,000", "Toner - Rp80,000"
                };
                break;
            case 4:
                category = "Olahraga";
                items = {
                    "Sepatu Lari - Rp500,000", "Bola Sepak - Rp250,000", "Raket Badminton - Rp300,000", "Pakaian Olahraga - Rp150,000",
                    "Topi - Rp50,000", "Jersey - Rp120,000", "Matras Yoga - Rp200,000", "Kettlebell - Rp400,000",
                    "Treadmill - Rp5,000,000", "Sepeda - Rp2,000,000", "Dumbbell - Rp350,000", "Skipping Rope - Rp100,000",
                    "Pelindung Lutut - Rp75,000", "Sarung Tangan Gym - Rp80,000", "Botol Minum - Rp30,000"
                };
                break;
            case 5:
                category = "Mainan";
                items = {
                    "Boneka - Rp50,000", "Mobil-mobilan - Rp40,000", "Lego - Rp500,000", "Puzzle - Rp150,000",
                    "Drone - Rp1,200,000", "Robot - Rp800,000", "Mainan Kayu - Rp100,000", "Kereta Api Mini - Rp250,000",
                    "Sepeda Anak - Rp700,000", "Alat Musik Anak - Rp300,000", "Balok Bangunan - Rp200,000", "Mainan Edukasi - Rp150,000",
                    "Game Konsol - Rp3,500,000", "Mainan Air - Rp60,000", "Mainan Pasir - Rp50,000"
                };
                break;
            case 0:
                cout << "Kembali ke menu utama..." << endl;
                return;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi!" << endl;
                continue;
        }

        int itemChoice;
        char addMore;
        do {
            displayItems(category, items);
            cout << "Pilih barang [0-" << items.size() << "]: ";
            cin >> itemChoice;

            if (itemChoice > 0 && itemChoice <= items.size()) {
                cout << "-> Anda memilih: " << items[itemChoice - 1] << endl;
                cout << "Ada tambahan (y/t)?: ";
                cin >> addMore;
                if (addMore == 't' || addMore == 'T') {
                    cout << "Kembali ke menu kategori..." << endl;
                    break;
                }
            } else if (itemChoice == 0) {
                cout << "Kembali ke menu kategori..." << endl;
            } else {
                cout << "Pilihan tidak valid. Silakan coba lagi!" << endl;
            }
        } while (itemChoice != 0);

    } while (true);
}


int main() {
    string nama;
    int pilihan;

    printHeader();
    cout << "Masukkan nama Anda: ";
    cin.ignore();
    getline(cin, nama);
    cout << endl;
    cout << "Halo, " << nama << "! Selamat berbelanja di Toko (GO GURL)!" << endl;

    do {
        displayMenu();
        cout << "Pilih menu [0-3]: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                categoryMenu();
                break;
            case 2:
                cout << "-> Anda memilih 'List belanja'.\n   (Fitur masih dalam pengembangan)" << endl;
                break;
            case 3:
                paymentMenu(nama);
                break;
            case 0:
                cout << "-> Terima kasih telah berbelanja di Toko (GO GURL), " << nama << "!" << endl;
                break;
            default:
                cout << "-> Pilihan tidak valid. Silakan coba lagi!" << endl;
        }
    } while (pilihan != 0);

    printFarewell(nama);

    return 0;
}
