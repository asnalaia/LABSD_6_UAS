#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <vector>
using namespace std;

struct Produk {
    int id;
    string nama;
    string kategori;
    int harga;
};

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

vector<Produk> daftarProduk = {
    {1, "Beras", "Konsumsi", 50000}, {2, "Mi Instan", "Konsumsi", 3000},
    {3, "Minyak Goreng", "Konsumsi", 20000}, {4, "Telur", "Konsumsi", 25000},
    {5, "Gula", "Konsumsi", 15000}, {6, "Kopi", "Konsumsi", 10000},
    {7, "Teh", "Konsumsi", 8000}, {8, "Roti", "Konsumsi", 12000},
    {9, "Cokelat", "Konsumsi", 18000}, {10, "Susu", "Konsumsi", 22000},
    {11, "Buah Apel", "Konsumsi", 30000}, {12, "Jeruk", "Konsumsi", 28000},
    {13, "Daging Sapi", "Konsumsi", 120000}, {14, "Ikan", "Konsumsi", 45000},
    {15, "Sayur Bayam", "Konsumsi", 5000}, {16, "Smartphone", "Elektronik", 2500000},
    {17, "Laptop", "Elektronik", 7500000}, {18, "Tablet", "Elektronik", 3200000},
    {19, "Televisi", "Elektronik", 4000000}, {20, "Kipas Angin", "Elektronik", 250000},
    {21, "AC", "Elektronik", 3000000}, {22, "Kulkas", "Elektronik", 2800000},
    {23, "Mesin Cuci", "Elektronik", 2500000}, {24, "Setrika", "Elektronik", 300000},
    {25, "Speaker", "Elektronik", 1000000}, {26, "Headphone", "Elektronik", 800000},
    {27, "Mouse", "Elektronik", 150000}, {28, "Keyboard", "Elektronik", 350000},
    {29, "Power Bank", "Elektronik", 500000}, {30, "Charger", "Elektronik", 200000},
    {31, "Lipstik", "Kecantikan", 100000}, {32, "Bedak", "Kecantikan", 85000},
    {33, "Maskara", "Kecantikan", 120000}, {34, "Foundation", "Kecantikan", 150000},
    {35, "Parfum", "Kecantikan", 300000}, {36, "Pelembap", "Kecantikan", 90000},
    {37, "Serum Wajah", "Kecantikan", 200000}, {38, "Sabun Muka", "Kecantikan", 75000},
    {39, "Shampoo", "Kecantikan", 50000}, {40, "Conditioner", "Kecantikan", 55000},
    {41, "Lulur", "Kecantikan", 40000}, {42, "Masker Rambut", "Kecantikan", 60000},
    {43, "Cat Kuku", "Kecantikan", 25000}, {44, "Sunblock", "Kecantikan", 70000},
    {45, "Toner", "Kecantikan", 80000}, {46, "Sepatu Lari", "Olahraga", 500000},
    {47, "Bola Sepak", "Olahraga", 250000}, {48, "Raket Badminton", "Olahraga", 300000},
    {49, "Pakaian Olahraga", "Olahraga", 150000}, {50, "Topi", "Olahraga", 50000},
    {51, "Jersey", "Olahraga", 120000}, {52, "Matras Yoga", "Olahraga", 200000},
    {53, "Kettlebell", "Olahraga", 400000}, {54, "Treadmill", "Olahraga", 5000000},
    {55, "Sepeda", "Olahraga", 2000000}, {56, "Dumbbell", "Olahraga", 350000},
    {57, "Skipping Rope", "Olahraga", 100000}, {58, "Pelindung Lutut", "Olahraga", 75000},
    {59, "Sarung Tangan Gym", "Olahraga", 80000}, {60, "Botol Minum", "Olahraga", 30000},
    {61, "Boneka", "Mainan", 50000}, {62, "Mobil-mobilan", "Mainan", 40000},
    {63, "Lego", "Mainan", 500000}, {64, "Puzzle", "Mainan", 150000},
    {65, "Drone", "Mainan", 1200000}, {66, "Robot", "Mainan", 800000},
    {67, "Mainan Kayu", "Mainan", 100000}, {68, "Kereta Api Mini", "Mainan", 250000},
    {69, "Sepeda Anak", "Mainan", 700000}, {70, "Alat Musik Anak", "Mainan", 300000},
    {71, "Balok Bangunan", "Mainan", 200000}, {72, "Mainan Edukasi", "Mainan", 150000},
    {73, "Game Konsol", "Mainan", 3500000}, {74, "Mainan Air", "Mainan", 60000},
    {75, "Mainan Pasir", "Mainan", 50000}
};

vector<Produk> keranjangBelanja;

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

void displayItems(const string& category) {
    cout << "List barang " << category << ":" << endl;
    for (const auto& produk : daftarProduk) {
        if (produk.kategori == category) {
            cout << produk.id << ". " << produk.nama << " - Rp" << produk.harga << endl;
        }
    }
    cout << "0. Kembali ke menu kategori" << endl;
}

void addToCart(int itemIndex) {
    keranjangBelanja.push_back(daftarProduk[itemIndex - 1]);
    cout << "-> " << daftarProduk[itemIndex - 1].nama << " telah ditambahkan ke keranjang belanja.\n";
}

void listCart() {
    if (keranjangBelanja.empty()) {
        cout << "Keranjang belanja Anda kosong.\n";
        return;
    }
    cout << "List belanja Anda:\n";
    for (const auto& produk : keranjangBelanja) {
        cout << produk.nama << " - Rp" << produk.harga << endl;
    }
}

void categoryMenu() {
    int categoryChoice;
    do {
        displayCategoryMenu();
        cout << "Pilih kategori [0-5]: ";
        cin >> categoryChoice;

        if (categoryChoice == 0) {
            break;
        }

        string category;
        switch (categoryChoice) {
            case 1: category = "Konsumsi"; break;
            case 2: category = "Elektronik"; break;
            case 3: category = "Kecantikan"; break;
            case 4: category = "Olahraga"; break;
            case 5: category = "Mainan"; break;
            default:
                cout << "-> Pilihan tidak valid. Silakan coba lagi!" << endl;
                continue;
        }

        int itemChoice;
        char addMore;
        do {
            displayItems(category);
            cout << "Pilih barang [0-" << daftarProduk.size() << "]: ";
            cin >> itemChoice;

            if (itemChoice > 0 && itemChoice <= daftarProduk.size() && daftarProduk[itemChoice - 1].kategori == category) {
                cout << "-> Anda memilih: " << daftarProduk[itemChoice - 1].nama << endl;
                cout << "Ada tambahan (y/t)?: ";
                cin >> addMore;
                if (addMore == 't' || addMore == 'T') {
                    cout << "Kembali ke menu kategori..." << endl;
                    break;
                } else {
                    addToCart(itemChoice);
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