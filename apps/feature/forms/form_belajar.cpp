#include "../../utils/validation.cpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct FormBelajar {
    string judulPelajaran;
    int durasiMenit;
    string catatan;
    string waktuAktivitas;
};

bool validasiJudulPelajaran(const string& judul) {
    if (judul.empty() || judul.length() < 2) {
        return false;
    }
    return true;
}

FormBelajar inputFormBelajar() {
    FormBelajar form;
    int pilihan;
    
    system("cls");
    cout << "\n";
    cout << "=============================================\n";
    cout << "            FORM AKTIVITAS BELAJAR        \n";
    cout << "=============================================\n\n";
    

    cout << "============= 1. JUDUL BELAJAR =============\n";
    cout << "Masukkan hal yang dipelajari: ";
    getline(cin >> ws, form.judulPelajaran);
    
    while (!validasiJudulPelajaran(form.judulPelajaran)) {
        cout << "Judul pelajaran tidak valid! Masukkan lagi: ";
        getline(cin, form.judulPelajaran);
    }
    

    cout << "============= 2. DURASI BELAJAR =============\n";
    form.durasiMenit = validasiInputAngka(1, 480, "Masukkan durasi (dalam menit): ");
    
    while (!validasiDurasi(form.durasiMenit)) {
        form.durasiMenit = validasiInputAngka(1, 480, "Masukkan durasi (dalam menit): ");
    }

    cout << "\n============= 3. WAKTU AKTIVITAS =============\n";
    tampilkanMenuWaktu();
    pilihan = validasiInputAngka(1, 4, "Pilih waktu (1-4): ");
    form.waktuAktivitas = pilihanWaktu(pilihan);
    

    cout << "\n============= 4. CATATAN TAMBAHAN =============\n";
    cout << "Catatan: ";
    getline(cin, form.catatan);
    
    return form;
}


string standardisasiDetailBelajar(const FormBelajar& form) {
    string detail = "";
    
    detail += form.judulPelajaran;
    detail += " | ";
    detail += to_string(form.durasiMenit) + " menit";
    detail += " | Waktu: " + form.waktuAktivitas;
    
    if (!form.catatan.empty()) {
        detail += " | Catatan: " + form.catatan;
    }
    
    return detail;
}


void tampilkanPreviewBelajar(const FormBelajar& form) {
    system("cls");
    cout << "\n";
    cout << "=============================================\n";
    cout << "           PREVIEW AKTIVITAS BELAJAR       \n";
    cout << "=============================================\n\n";
    
    cout << "Detail Aktivitas:\n";
    cout << "=============================================\n";
    cout << "Judul Pelajaran: " << form.judulPelajaran << "\n";
    cout << "Durasi         : " << form.durasiMenit << " menit\n";
    cout << "Waktu Aktivitas: " << form.waktuAktivitas << "\n";

    if (!form.catatan.empty()) {
        cout << "Catatan        : " << form.catatan << "\n";
    }
    
    cout << "\n=============================================\n";
    cout << "String Detail Terstandarisasi:\n";
    cout << standardisasiDetailBelajar(form) << "\n";
    cout << "=============================================\n";
    
    cout << "\nTekan ENTER untuk kembali...";
    cin.ignore();
}

void formBelajar() {
    FormBelajar form = inputFormBelajar();
    tampilkanPreviewBelajar(form);
}
