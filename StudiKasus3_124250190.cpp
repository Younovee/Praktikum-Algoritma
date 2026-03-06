#include <iostream>
#include <string>
using namespace std;

// Fungsi untuk menampilkan daftar nama
void tampilkanNama(string nama[], int n) {
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << nama[i] << endl;
    }
}

// Fungsi Bubble Sort untuk mengurutkan secara ascending (A-Z)
void bubbleSortAscending(string nama[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Membandingkan dua nama berurutan
            if (nama[j] > nama[j + 1]) {
                // Tukar posisi jika nama[j] lebih besar dari nama[j+1]
                string temp = nama[j];
                nama[j] = nama[j + 1];
                nama[j + 1] = temp;
            }
        }
    }
}

// Fungsi partition untuk Quick Sort
int partition(string nama[], int low, int high) {
    string pivot = nama[high]; // Pilih elemen terakhir sebagai pivot
    int i = (low - 1); // Indeks elemen yang lebih kecil dari pivot
    
    for (int j = low; j < high; j++) {
        // Jika nama[j] lebih besar atau sama dengan pivot (untuk descending)
        if (nama[j] >= pivot) {
            i++;
            // Tukar posisi
            string temp = nama[i];
            nama[i] = nama[j];
            nama[j] = temp;
        }
    }
    
    // Tempatkan pivot di posisi yang benar
    string temp = nama[i + 1];
    nama[i + 1] = nama[high];
    nama[high] = temp;
    
    return i + 1;
}

// Fungsi Quick Sort untuk mengurutkan secara descending (Z-A)
void quickSortDescending(string nama[], int low, int high) {
    if (low < high) {
        // Partisi array dan dapatkan indeks pivot
        int pi = partition(nama, low, high);
        
        // Rekursif mengurutkan elemen sebelum dan sesudah pivot
        quickSortDescending(nama, low, pi - 1);
        quickSortDescending(nama, pi + 1, high);
    }
}

int main() {
    int n;
    
    cout << "=== PROGRAM PENGURUTAN NAMA MAHASISWA ===" << endl;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;
    cin.ignore(); // Mengabaikan newline setelah input angka
    
    // Deklarasi array untuk menyimpan nama
    string nama[n];
    
    // Input nama mahasiswa
    cout << "\nMasukkan " << n << " nama mahasiswa:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nama ke-" << i + 1 << ": ";
        getline(cin, nama[i]);
    }
    
    // Tampilkan nama sebelum diurutkan
    cout << "\n=== DAFTAR NAMA SEBELUM DIURUTKAN ===" << endl;
    tampilkanNama(nama, n);
    
    // Buat salinan array untuk ascending sort
    string namaAsc[n];
    for (int i = 0; i < n; i++) {
        namaAsc[i] = nama[i];
    }
    
    // Urutkan ascending dengan Bubble Sort
    bubbleSortAscending(namaAsc, n);
    
    // Tampilkan hasil ascending
    cout << "\n=== DAFTAR NAMA ASCENDING (A-Z) ===" << endl;
    cout << "Menggunakan Bubble Sort:" << endl;
    tampilkanNama(namaAsc, n);
    
    // Buat salinan array untuk descending sort
    string namaDesc[n];
    for (int i = 0; i < n; i++) {
        namaDesc[i] = nama[i];
    }
    
    // Urutkan descending dengan Quick Sort
    quickSortDescending(namaDesc, 0, n - 1);
    
    // Tampilkan hasil descending
    cout << "\n=== DAFTAR NAMA DESCENDING (Z-A) ===" << endl;
    cout << "Menggunakan Quick Sort:" << endl;
    tampilkanNama(namaDesc, n);
    
    return 0;
}