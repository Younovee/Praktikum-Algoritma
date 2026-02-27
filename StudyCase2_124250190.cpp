#include <iostream>
#include <string>
using namespace std;

// Struktur data buku
struct Buku {
    string judul;
    int harga;
};

int main() {
    // Data buku (SUDAH DIURUTKAN A–Z)
    Buku daftarBuku[] = {
        {"Ayat-Ayat Cinta", 95000},
        {"Bumi", 85000},
        {"Dilan 1990", 80000},
        {"Harry Potter", 120000},
        {"Laskar Pelangi", 90000}
    };

    int jumlah = 5;
    string cariJudul;
    int pilihan;
    bool ditemukan = false;

    cout << "Masukkan judul buku yang dicari: ";
    getline(cin, cariJudul);

    cout << "\nPilih metode pencarian:\n";
    cout << "1. Pencarian Sekuensial\n";
    cout << "2. Pencarian Biner\n";
    cout << "Pilihan: ";
    cin >> pilihan;

    // Pencarian Sekuensial
    if (pilihan == 1) {
        for (int i = 0; i < jumlah; i++) {
            if (daftarBuku[i].judul == cariJudul) {
                cout << "\nBuku ditemukan!\n";
                cout << "Judul : " << daftarBuku[i].judul << endl;
                cout << "Harga : Rp" << daftarBuku[i].harga << endl;
                ditemukan = true;
                break;
            }
        }
    }

    // Pencarian Biner
    else if (pilihan == 2) {
        int kiri = 0, kanan = jumlah - 1;

        while (kiri <= kanan) {
            int tengah = (kiri + kanan) / 2;

            if (daftarBuku[tengah].judul == cariJudul) {
                cout << "\nBuku ditemukan!\n";
                cout << "Judul : " << daftarBuku[tengah].judul << endl;
                cout << "Harga : Rp" << daftarBuku[tengah].harga << endl;
                ditemukan = true;
                break;
            }
            else if (daftarBuku[tengah].judul < cariJudul) {
                kiri = tengah + 1;
            }
            else {
                kanan = tengah - 1;
            }
        }
    }

    else {
        cout << "\nPilihan tidak valid.\n";
        return 0;
    }

    if (!ditemukan) {
        cout << "\nBuku tidak ditemukan.\n";
    }

    return 0;
}