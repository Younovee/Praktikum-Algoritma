#include <iostream>
using namespace std;

int main() {
    // Deklarasi variabel untuk menyimpan panjang array
    int n;
    cout << "Masukkan Panjang array: ";
    cin >> n;

    // Alokasi array secara dinamis menggunakan new[]
    int *arr = new int[n];
    // Pointer yang akan digunakan untuk mengakses elemen array
    int *ptr = arr;

    // Input nilai ke dalem array 
    // Menggunakan *(ptr + i) untuk menulis ke indeks ke‑i
    cout << "Masukkan " << n << " nilai array (integer): " << endl;
    for (int i = 0; i < n; i++) {
        cin >> *(ptr + i);      // simpan nilai pada posisi ke‑i
    }

    // Menampilkan isi array
    cout << "Isi array: ";
    for (int i = 0; i < n; i++) {
        cout << *(ptr + i) << " ";  // ambil dan tampilkan nilai pada indeks ke‑i
    }
    cout << endl;

    // Inisialisasi nilai maksimum dan minimum dengan elemen pertama
    int maxval = *ptr;   // nilai maksimum = elemen pertama
    int minval = *ptr;   // nilai minimum = elemen pertama

    // Perulangan untuk menentukan nilai terbesar dan terkecil
    for (int i = 1; i < n; i++) {
        int val = *(ptr + i);    // Ambil elemen ke‑i
        if (val > maxval) {
            maxval = val;         // perbarui nilai maksimum
        }
        if (val < minval) {
            minval = val;         // perbarui nilai minimum
        }
    }

    // Tampilkan nilai maksimum dan minimum
    cout << "Nilai maksimum: " << maxval << endl;
    cout << "Nilai minimum: " << minval << endl;

    // Menghitung jumlah (sum) seluruh elemen array
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *(ptr + i);   // tambahkan setiap elemen ke variabel sum
    }

    // Menghitung rata‑rata dengan konversi ke tipe double
    double avg = static_cast<double>(sum) / n;

    // Tampilkan jumlah dan rata‑rata
    cout << "Jumlah: " << sum << endl;
    cout << "Rata-rata: " << avg << endl;

    // Membebaskan memori yang dialokasikan dengan new[]
    delete[] ptr;

    return 0;
}