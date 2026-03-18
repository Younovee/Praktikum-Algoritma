#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Produk {
    char nama[50];
    float harga;
    char kategori[30];
    int stok;
};

Produk produk[100];
int jumlah = 0;
const char* filename = "lelele.csv";

void loadData() {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        jumlah = 0;
        return;
    }
    jumlah = 0;
    while (fscanf(file, "%[^,],%f,%[^,],%d\n", produk[jumlah].nama, &produk[jumlah].harga, produk[jumlah].kategori, &produk[jumlah].stok) != EOF) {
        jumlah++;
        if (jumlah >= 100) break;
    }
    fclose(file);
}

void saveData() {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        cout << "Gagal menyimpan data!" << endl;
        return;
    }
    for (int i = 0; i < jumlah; i++) {
        fprintf(file, "%s,%f,%s,%d\n", produk[i].nama, produk[i].harga, produk[i].kategori, produk[i].stok);
    }
    fclose(file);
}

void tambahProduk() {
    if (jumlah >= 100) {
        cout << "Data penuh!" << endl;
        return;
    }
    Produk p;
    cout << "Masukkan nama produk: ";
    cin.ignore();
    cin.getline(p.nama, 50);
    cout << "Masukkan harga: ";
    cin >> p.harga;
    cout << "Masukkan kategori (makanan/minuman): ";
    cin >> p.kategori;
    while (strcmp(p.kategori, "makanan") != 0 && strcmp(p.kategori, "minuman") != 0) {
        cout << "Kategori hanya makanan atau minuman. Ulangi: ";
        cin >> p.kategori;
    }
    cout << "Masukkan stok: ";
    cin >> p.stok;
    produk[jumlah] = p;
    jumlah++;
    saveData();
    cout << "Produk berhasil ditambahkan!" << endl;
}

void tampilkanSemua() {
    if (jumlah == 0) {
        cout << "Tidak ada data." << endl;
        return;
    }
    printf("\n%-5s %-30s %-10s %-15s %-10s\n", "No", "Nama", "Harga", "Kategori", "Stok");
    for (int i = 0; i < jumlah; i++) {
        printf("%-5d %-30s Rp%-9.2f %-15s %-10d\n", i+1, produk[i].nama, produk[i].harga, produk[i].kategori, produk[i].stok);
    }
}

void bubbleSortByName() {
    for (int i = 0; i < jumlah-1; i++) {
        for (int j = 0; j < jumlah-i-1; j++) {
            if (strcmp(produk[j].nama, produk[j+1].nama) > 0) {
                Produk temp = produk[j];
                produk[j] = produk[j+1];
                produk[j+1] = temp;
            }
        }
    }
    cout << "Data telah diurutkan berdasarkan nama (ascending) dengan bubble sort." << endl;
}

void quickSortByPrice(int low, int high) {
    if (low < high) {
        float pivot = produk[high].harga;
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (produk[j].harga > pivot) {
                i++;
                Produk temp = produk[i];
                produk[i] = produk[j];
                produk[j] = temp;
            }
        }
        Produk temp = produk[i+1];
        produk[i+1] = produk[high];
        produk[high] = temp;
        int pi = i + 1;
        quickSortByPrice(low, pi - 1);
        quickSortByPrice(pi + 1, high);
    }
}

void urutkanMenu() {
    if (jumlah == 0) {
        cout << "Tidak ada data untuk diurutkan." << endl;
        return;
    }
    int pilihan;
    cout << "Pilih metode pengurutan:\n";
    cout << "1. Bubble Sort berdasarkan nama (ascending)\n";
    cout << "2. Quick Sort berdasarkan harga (descending)\n";
    cout << "Pilihan: ";
    cin >> pilihan;
    if (pilihan == 1) {
        bubbleSortByName();
        tampilkanSemua();
    } else if (pilihan == 2) {
        quickSortByPrice(0, jumlah-1);
        cout << "Data telah diurutkan berdasarkan harga (descending) dengan quick sort." << endl;
        tampilkanSemua();
    } else {
        cout << "Pilihan tidak valid." << endl;
    }
}

int sequentialSearch(char* cari) {
    for (int i = 0; i < jumlah; i++) {
        if (strcmp(produk[i].nama, cari) == 0) {
            return i;
        }
    }
    return -1;
}

int binarySearch(char* cari) {
    int left = 0, right = jumlah - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(produk[mid].nama, cari);
        if (cmp == 0) return mid;
        else if (cmp < 0) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void cariMenu() {
    if (jumlah == 0) {
        cout << "Tidak ada data." << endl;
        return;
    }
    int pilihan;
    cout << "Pilih metode pencarian:\n";
    cout << "1. Sequential Search\n";
    cout << "2. Binary Search\n";
    cout << "Pilihan: ";
    cin >> pilihan;
    if (pilihan != 1 && pilihan != 2) {
        cout << "Pilihan tidak valid." << endl;
        return;
    }
    char cari[50];
    cout << "Masukkan nama produk yang dicari: ";
    cin.ignore();
    cin.getline(cari, 50);
    int idx;
    if (pilihan == 1) {
        idx = sequentialSearch(cari);
    } else {
        bubbleSortByName();
        idx = binarySearch(cari);
    }
    if (idx == -1) {
        cout << "Produk tidak ditemukan!" << endl;
    } else {
        cout << "Produk ditemukan:\n";
        printf("Nama: %s\nHarga: Rp%.2f\nKategori: %s\nStok: %d\n", produk[idx].nama, produk[idx].harga, produk[idx].kategori, produk[idx].stok);
    }
}

int main() {
    loadData();
    int pilihan;
    do {
        cout << "\n=== MENU UTAMA ===\n";
        cout << "1. Tambah Produk\n";
        cout << "2. Tampilkan Semua Produk\n";
        cout << "3. Urutkan Produk\n";
        cout << "4. Cari Produk\n";
        cout << "5. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1: tambahProduk(); break;
            case 2: tampilkanSemua(); break;
            case 3: urutkanMenu(); break;
            case 4: cariMenu(); break;
            case 5: cout << "Terima kasih!" << endl; break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 5);
    return 0;
}
