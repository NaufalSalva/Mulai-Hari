#include "../../utils/validation.cpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct FormMemasak {
    string namaMasakan;
    string jenisMasakan;
    int durasiMemasak;
    string catatan;
    string waktuAktivitas;
};

bool validasiNamaMasakan(const string& nama) {
    if (nama.empty() || nama.length() < 2) {
        return false;
    }
    return true;
}


void tampilkanJenisMasakan() {
    cout << "\n=========== PILIH JENIS MASAKAN ==============\n";
    cout << "1. Masakan Tradisional\n";
    cout << "2. Masakan Luar Negeri\n";
    cout << "3. Masakan Cepat Saji\n";
    cout << "4. Lainnya\n";
    cout << "========================================== \n";
}

FormMemasak inputFormMemasak() {
    FormMemasak form;
    int pilihan;
    
    system("cls");
    cout << "\n";
    cout << "=============================================\n";
    cout << "            FORM AKTIVITAS MEMASAK         \n";
    cout << "=============================================\n\n";
    

    cout << "============= 1. NAMA MASAKAN =============\n";
    cout << "Masukkan nama masakan: ";
    getline(cin, form.namaMasakan);
    
    while (!validasiNamaMasakan(form.namaMasakan)) {
        cout << "Nama masakan tidak valid! Masukkan lagi: ";
        getline(cin, form.namaMasakan);
    }
    
    cout << "\n============= 2. JENIS MASAKAN =============\n";
    tampilkanJenisMasakan();
    cout << "Pilih jenis (1-3): ";
    cin >> pilihan;
    switch(pilihan) {
        case 1: form.jenisMasakan = "Masakan Tradisional"; break;
        case 2: form.jenisMasakan = "Masakan Luar Negeri"; break;
        case 3: form.jenisMasakan = "Masakan Cepat Saji"; break;
        case 4: form.jenisMasakan = "Lainnya"; break;
        default: form.jenisMasakan = "Masakan Tradisional";
    }
    cin.ignore();

    cout << "\n============= 3. WAKTU AKTIVITAS =============\n";
    tampilkanMenuWaktu();
    cout << "Pilih waktu (1-4): ";
    cin >> pilihan;
    form.waktuAktivitas = pilihanWaktu(pilihan);
    cin.ignore();

    cout << "============= 4. DURASI MEMASAK =============\n";
    cout << "Masukkan durasi (dalam menit): ";
    cin >> form.durasiMemasak;
    
    while (!validasiDurasi(form.durasiMemasak)) {
        cout << "Durasi harus 1-480 menit! Masukkan lagi: ";
        cin >> form.durasiMemasak;
    }
    cin.ignore();

    cout << "\n============= 3. WAKTU AKTIVITAS =============\n";
    tampilkanMenuWaktu();
    cout << "Pilih waktu (1-4): ";
    cin >> pilihan;
    form.waktuAktivitas = pilihanWaktu(pilihan);
    cin.ignore();
    

    cout << "\n============= 4. CATATAN TAMBAHAN =============\n";
    cout << "Catatan: ";
    getline(cin, form.catatan);
    
    return form;
}


string standardisasiDetailMemasak(const FormMemasak& form) {
    string detail = "";
    
    detail += form.namaMasakan;
    detail += " | ";
    detail += to_string(form.durasiMemasak) + " menit";
    detail += " | Jenis: " + form.jenisMasakan;
    detail += " | Waktu: " + form.waktuAktivitas;
    
    if (!form.catatan.empty()) {
        detail += " | Catatan: " + form.catatan;
    }
    
    return detail;
}


void tampilkanPreviewMemasak(const FormMemasak& form) {
    system("cls");
    cout << "\n";
    cout << "=============================================\n";
    cout << "           PREVIEW AKTIVITAS MEMASAK       \n";
    cout << "=============================================\n\n";
    
    cout << "Detail Aktivitas:\n";
    cout << "=============================================\n";
    cout << "Nama Masakan   : " << form.namaMasakan << "\n";
    cout << "Jenis Masakan  : " << form.jenisMasakan << "\n";
    cout << "Durasi         : " << form.durasiMemasak << " menit\n";
    cout << "Waktu Aktivitas: " << form.waktuAktivitas << "\n";

    if (!form.catatan.empty()) {
        cout << "Catatan        : " << form.catatan << "\n";
    }
    
    cout << "\n=============================================\n";
    cout << "String Detail Terstandarisasi:\n";
    cout << standardisasiDetailMemasak(form) << "\n";
    cout << "=============================================\n";
    
    cout << "\nTekan ENTER untuk kembali...";
    cin.ignore();
}

void formMemasak() {
    FormMemasak form = inputFormMemasak();
    tampilkanPreviewMemasak(form);
}
