#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Orang {
    string nama;
    int umur;
    string hobi;
};

Orang mhs[5];
int jumlah = 0;
string namaFile;

// ===================== MERGE SORT by NAMA =====================
void merge(Orang arr[], int kiri, int tengah, int kanan) {
    int n1 = tengah - kiri + 1;
    int n2 = kanan - tengah;

    Orang L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[kiri + i];
    for (int j = 0; j < n2; j++) R[j] = arr[tengah + 1 + j];

    int i = 0, j = 0, k = kiri;
    while (i < n1 && j < n2) {
        if (L[i].nama <= R[j].nama) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }
}

void mergeSort(Orang arr[], int kiri, int kanan) {
    if (kiri < kanan) {
        int tengah = (kiri + kanan) / 2;
        mergeSort(arr, kiri, tengah);
        mergeSort(arr, tengah + 1, kanan);
        merge(arr, kiri, tengah, kanan);
    }
}

// ===================== TAMPIL TABEL =====================
void tampilTabel(Orang arr[], int n) {
    cout << "======================================" << endl;
    cout << "  NAMA          UMUR    HOBI" << endl;
    cout << "======================================" << endl;
    for (int i = 0; i < n; i++) {
        cout << "  " << arr[i].nama << "     " << arr[i].umur << "     " << arr[i].hobi << endl;
    }
    cout << "======================================" << endl;
}

// ===================== INPUT DATA =====================
void inputData() {
    cout << "INPUT DATA" << endl;
    cout << "======================================" << endl;
    cout << "Jumlah data (max 5): ";
    cin >> jumlah;
    if (jumlah > 5) {
        cout << "Jumlah melebihi batas! Maksimal 5." << endl;
        return;
    }
    cout << "Disimpan di file : ";
    cin >> namaFile;

    ofstream file(namaFile);
    file << jumlah << endl;

    for (int i = 0; i < jumlah; i++) {
        cout << "Data ke-" << i+1 << endl;
        cout << "  Nama : "; cin >> mhs[i].nama;
        cout << "  Umur : "; cin >> mhs[i].umur;
        cout << "  Hobi : "; cin >> mhs[i].hobi;
        file << mhs[i].nama << " " << mhs[i].umur << " " << mhs[i].hobi << endl;
    }
    file.close();

    char ulang;
    cout << "Kembali ke Menu Utama(y/t)? ";
    cin >> ulang;
}

// ===================== TAMPIL DATA =====================
void tampilData() {
    cout << "TAMPIL DATA" << endl;
    cout << "======================================" << endl;
    cout << "Nama file yang akan ditampilkan : ";
    cin >> namaFile;

    ifstream file(namaFile);
    file >> jumlah;
    for (int i = 0; i < jumlah; i++) {
        file >> mhs[i].nama >> mhs[i].umur >> mhs[i].hobi;
    }
    file.close();

    tampilTabel(mhs, jumlah);

    char ulang;
    cout << "Kembali ke Menu Utama(y/t)? ";
    cin >> ulang;
}

// ===================== SEARCHING =====================
void searching() {
    cout << "SEARCHING" << endl;
    cout << "======================================" << endl;
    string cari;
    cout << "Masukkan Nama yang dicari : ";
    cin >> cari;

    bool ketemu = false;
    for (int i = 0; i < jumlah; i++) {
        if (mhs[i].nama == cari) {
            cout << "Data ditemukan!" << endl;
            cout << "Nama : " << mhs[i].nama << endl;
            cout << "Umur : " << mhs[i].umur << endl;
            cout << "Hobi : " << mhs[i].hobi << endl;
            ketemu = true;
            break;
        }
    }
    if (!ketemu) cout << "Data tidak ditemukan." << endl;

    char ulang;
    cout << "Kembali ke Menu Utama(y/t)? ";
    cin >> ulang;
}

// ===================== SORTING =====================
void sorting() {
    cout << "MENU SORTING :" << endl;
    cout << "==========================" << endl;
    cout << "1. MERGE SORT" << endl;
    cout << "2. Kembali ke MENU UTAMA" << endl;
    cout << "==========================" << endl;
    cout << "Pilih : ";

    int pilih;
    cin >> pilih;

    if (pilih == 1) {
        cout << "Data yang akan disorting dari file : ";
        cin >> namaFile;

        ifstream file(namaFile);
        file >> jumlah;
        for (int i = 0; i < jumlah; i++) {
            file >> mhs[i].nama >> mhs[i].umur >> mhs[i].hobi;
        }
        file.close();

        tampilTabel(mhs, jumlah);

        mergeSort(mhs, 0, jumlah - 1);

        cout << "Data urut by Nama" << endl;
        tampilTabel(mhs, jumlah);

        char ulang;
        cout << "Ulangi (y/t) : ";
        cin >> ulang;
        if (ulang == 'y') sorting();
    }
}

// ===================== MAIN =====================
int main() {
    int pilih;
    do {
        cout << "MENU :" << endl;
        cout << "==========================" << endl;
        cout << "1. INPUT DATA" << endl;
        cout << "2. TAMPIL DATA" << endl;
        cout << "3. SEARCHING" << endl;
        cout << "4. SORTING" << endl;
        cout << "5. EXIT" << endl;
        cout << "==========================" << endl;
        cout << "Pilih : ";
        cin >> pilih;

        if (pilih == 1) inputData();
        else if (pilih == 2) tampilData();
        else if (pilih == 3) searching();
        else if (pilih == 4) sorting();

    } while (pilih != 5);

    cout << "Terima kasih!" << endl;
    return 0;
}
