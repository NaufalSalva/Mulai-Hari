#include "../../utils/validation.cpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct FormTraveling {
    string tempatTujuan;
    string jenisTempat;
    int durasiPerjalanan;
    string catatan;
    string waktuAktivitas;
};

bool validasiNamaTempat(const string& nama) {
    if (nama.empty() || nama.length() < 2) {
        return false;
    }
    return true;
}

void tampilkanJenisTempat() {
    cout << "\n=========== PILIH JENIS TEMPAT ==============\n";
    cout << "1. Wisata Alam\n";
    cout << "2. Wisata Budaya dan Sejarah\n";
    cout << "3. Wisata Belanja dan Kuliner\n";
    cout << "4. Wisata Hiburan\n";
    cout << "5. Wisata Religi\n";
    cout << "6. Wisata Edukasi\n";
    cout << "========================================== \n";
}


FormTraveling inputFormTraveling() {
    FormTraveling form;
    int pilihan;
    
    system("cls");
    cout << "\n";
    cout << "=============================================\n";
    cout << "           FORM AKTIVITAS TRAVELING          \n";
    cout << "=============================================\n\n";
    

    cout << "============= 1. NAMA TEMPAT =============\n";
    cout << "Masukkan nama tempat tujuan: ";
    getline(cin, form.tempatTujuan);
    
    while (!validasiNamaTempat(form.tempatTujuan)) {
        cout << "Nama tempat tidak valid! Masukkan lagi: ";
        getline(cin, form.tempatTujuan);
    }
    
    cout << "\n============= 2. JENIS TEMPAT =============\n";
    tampilkanJenisTempat();
    cout << "Pilih jenis (1-6): ";
    cin >> pilihan;
    switch(pilihan) {
        case 1: form.jenisTempat = "Wisata Alam"; break;
        case 2: form.jenisTempat = "Wisata Budaya dan Sejarah"; break;
        case 3: form.jenisTempat = "Wisata Belanja dan Kuliner"; break;
        case 4: form.jenisTempat = "Wisata Hiburan"; break;
        case 5: form.jenisTempat = "Wisata Religi"; break;
        case 6: form.jenisTempat = "Wisata Edukasi"; break;
        default: form.jenisTempat = "Wisata Alam";
    }
    cin.ignore();

    cout << "\n============= 3. WAKTU AKTIVITAS =============\n";
    tampilkanMenuWaktu();
    cout << "Pilih waktu (1-4): ";
    cin >> pilihan;
    form.waktuAktivitas = pilihanWaktu(pilihan);
    cin.ignore();

    cout << "============= 4. DURASI PERJALANAN =============\n";
    cout << "Masukkan durasi (dalam menit): ";
    cin >> form.durasiPerjalanan;
    
    while (!validasiDurasi(form.durasiPerjalanan)) {
        cout << "Durasi harus 1-480 menit! Masukkan lagi: ";
        cin >> form.durasiPerjalanan;
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


string standardisasiDetailTraveling(const FormTraveling& form) {
    string detail = "";
    
    detail += form.tempatTujuan;
    detail += " | ";
    detail += to_string(form.durasiPerjalanan) + " menit";
    detail += " | Jenis: " + form.jenisTempat;
    detail += " | Waktu: " + form.waktuAktivitas;
    
    if (!form.catatan.empty()) {
        detail += " | Catatan: " + form.catatan;
    }
    
    return detail;
}


void tampilkanPreviewTraveling(const FormTraveling& form) {
    system("cls");
    cout << "\n";
    cout << "=============================================\n";
    cout << "           PREVIEW AKTIVITAS TRAVELING     \n";
    cout << "=============================================\n\n";
    
    cout << "Detail Aktivitas:\n";
    cout << "=============================================\n";
    cout << "Tempat Tujuan  : " << form.tempatTujuan << "\n";
    cout << "Jenis Tempat   : " << form.jenisTempat << "\n";
    cout << "Durasi         : " << form.durasiPerjalanan << " menit\n";
    cout << "Waktu Aktivitas: " << form.waktuAktivitas << "\n";

    if (!form.catatan.empty()) {
        cout << "Catatan        : " << form.catatan << "\n";
    }
    
    cout << "\n=============================================\n";
    cout << "String Detail Terstandarisasi:\n";
    cout << standardisasiDetailTraveling(form) << "\n";
    cout << "=============================================\n";
    
    cout << "\nTekan ENTER untuk kembali...";
    cin.ignore();
}

void formTraveling() {
    FormTraveling form = inputFormTraveling();
    tampilkanPreviewTraveling(form);
}
