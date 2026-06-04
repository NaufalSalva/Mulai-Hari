#include "../../utils/validation.cpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct FormMusik {
    string judulLagu;
    string alatMusik;
    int durasiMenit;
    string catatan;
    string waktuAktivitas;
};

bool validasiJudulMusik(const string& judul) {
    if (judul.empty() || judul.length() < 2) {
        return false;
    }
    return true;
}

FormMusik inputFormMusik() {
    FormMusik form;
    int pilihan;
    
    system("cls");
    cout << "\n";
    cout << "=============================================\n";
    cout << "            FORM AKTIVITAS MUSIK        \n";
    cout << "=============================================\n\n";
    

    cout << "============= 1. JUDUL LAGU =============\n";
    cout << "Masukkan hal yang dipelajari: ";
    getline(cin, form.judulLagu);
    
    while (!validasiJudulMusik(form.judulLagu)) {
        cout << "Judul lagu tidak valid! Masukkan lagi: ";
        getline(cin, form.judulLagu);
    }
    

    cout << "============= 2. Alat Musik =============\n";
    cout << "1. Piano\n";
    cout << "2. Gitar\n";
    cout << "3. Drum\n";
    cout << "4. Biola\n";
    cout << "5. Lainnya\n";
    cout << "Masukkan pilihan alat musik (1-5): ";
    cin >> pilihan;
    cin.ignore();
    
    switch(pilihan) {
        case 1: form.alatMusik = "Piano"; break;
        case 2: form.alatMusik = "Gitar"; break;
        case 3: form.alatMusik = "Drum"; break;
        case 4: form.alatMusik = "Biola"; break;
        case 5: form.alatMusik = "Lainnya"; break;
        default: form.alatMusik = "Lainnya"; break;
    }

    cout << "============= 3. DURASI LATIHAN =============\n";
    cout << "Masukkan durasi (dalam menit): ";
    cin >> form.durasiMenit;
    
    while (!validasiDurasi(form.durasiMenit)) {
        cout << "Durasi harus 1-480 menit! Masukkan lagi: ";
        cin >> form.durasiMenit;
    }
    cin.ignore();

    cout << "\n============= 4. WAKTU AKTIVITAS =============\n";
    tampilkanMenuWaktu();
    cout << "Pilih waktu (1-4): ";
    cin >> pilihan;
    form.waktuAktivitas = pilihanWaktu(pilihan);
    cin.ignore();
    

    cout << "\n============= 5. CATATAN TAMBAHAN =============\n";
    cout << "Catatan: ";
    getline(cin, form.catatan);
    
    return form;
}


string standardisasiDetailMusik(const FormMusik& form) {
    string detail = "";
    
    detail += form.judulLagu;
    detail += " | ";
    detail += form.alatMusik;
    detail += " | ";
    detail += to_string(form.durasiMenit) + " menit";
    detail += " | Waktu: " + form.waktuAktivitas;

    if (!form.catatan.empty()) {
        detail += " | Catatan: " + form.catatan;
    }
    
    return detail;
}


void tampilkanPreviewMusik(const FormMusik& form) {
    system("cls");
    cout << "\n";
    cout << "=============================================\n";
    cout << "           PREVIEW AKTIVITAS MUSIK       \n";
    cout << "=============================================\n\n";
    
    cout << "Detail Aktivitas:\n";
    cout << "=============================================\n";
    cout << "Judul Lagu : " << form.judulLagu << "\n";
    cout << "Alat Musik     : " << form.alatMusik << "\n";
    cout << "Durasi         : " << form.durasiMenit << " menit\n";
    cout << "Waktu Aktivitas : " << form.waktuAktivitas << "\n";

    if (!form.catatan.empty()) {
        cout << "Catatan        : " << form.catatan << "\n";
    }
    
    cout << "\n=============================================\n";
    cout << "String Detail Terstandarisasi:\n";
    cout << standardisasiDetailMusik(form) << "\n";
    cout << "=============================================\n";
    
    cout << "\nTekan ENTER untuk kembali...";
    cin.ignore();
}

void formMusik() {
    FormMusik form = inputFormMusik();
    tampilkanPreviewMusik(form);
}