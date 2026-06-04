#include "../../utils/validation.cpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct FormMenulis {
    string judulTulisan;
    string jenisTulisan;
    int durasiMenit;
    string catatan;
    string waktuAktivitas;
};

bool validasiJudulTulisan(const string& judul) {
    if (judul.empty() || judul.length() < 2) {
        return false;
    }
    return true;
}


FormMenulis inputFormMenulis() {
    FormMenulis form;
    int pilihan;
    
    system("cls");
    cout << "\n";
    cout << "=============================================\n";
    cout << "            FORM AKTIVITAS MENULIS        \n";
    cout << "=============================================\n\n";
    

    cout << "============= 1. JUDUL MENULIS =============\n";
    cout << "Judul Tulisan: ";
    getline(cin, form.judulTulisan);
    
    while (!validasiJudulTulisan(form.judulTulisan)) {
        cout << "Judul tulisan tidak valid! Masukkan lagi: ";
        getline(cin, form.judulTulisan);
    }
    

    cout << "============= 2. DURASI MENULIS =============\n";
    cout << "Masukkan durasi (dalam menit): ";
    cin >> form.durasiMenit;
    
    while (!validasiDurasi(form.durasiMenit)) {
        cout << "Durasi harus 1-480 menit! Masukkan lagi: ";
        cin >> form.durasiMenit;
    }
    cin.ignore();

    cout << "\n============= 3. Jenis Tulisan =============\n";
    cout << "1. Artikel\n";
    cout << "2. Cerita\n";
    cout << "3. Esai\n";
    cout << "4. Puisi\n";
    cout << "5. Jurnal\n";
    cout << "6. Lainnya\n";
    cout << "Pilih jenis (1-6): ";
    cin >> pilihan;
    cin.ignore();
    switch(pilihan) {
        case 1: form.jenisTulisan = "Artikel"; break;
        case 2: form.jenisTulisan = "Cerita"; break;
        case 3: form.jenisTulisan = "Esai"; break;
        case 4: form.jenisTulisan = "Puisi"; break;
        case 5: form.jenisTulisan = "Jurnal"; break;
        case 6: form.jenisTulisan = "Lainnya"; break;
        default: form.jenisTulisan = "Lainnya"; break;
    }

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


string standardisasiDetailMenulis(const FormMenulis& form)
{
    string detail = "";

    detail += form.judulTulisan;
    detail += " | ";
    detail += form.jenisTulisan;
    detail += " | ";
    detail += to_string(form.durasiMenit) + " menit";
    detail += " | Waktu: " + form.waktuAktivitas;

    if(!form.catatan.empty())
    {
        detail += " | Catatan: " + form.catatan;
    }

    return detail;
}


void tampilkanPreviewMenulis(const FormMenulis& form) {
    system("cls");
    cout << "\n";
    cout << "=============================================\n";
    cout << "           PREVIEW AKTIVITAS MENULIS       \n";
    cout << "=============================================\n\n";
    
    cout << "Detail Aktivitas:\n";
    cout << "=============================================\n";
    cout << "Judul Tulisan : " << form.judulTulisan << "\n";
    cout << "Durasi         : " << form.durasiMenit << " menit\n";
    cout << "Waktu Aktivitas: " << form.waktuAktivitas << "\n";

    if (!form.catatan.empty()) {
        cout << "Catatan        : " << form.catatan << "\n";
    }
    
    cout << "\n=============================================\n";
    cout << "String Detail Terstandarisasi:\n";
    cout << standardisasiDetailMenulis(form) << "\n";
    cout << "=============================================\n";
    
    cout << "\nTekan ENTER untuk kembali...";
    cin.ignore();
}

void formMenulis() {
    FormMenulis form = inputFormMenulis();
    tampilkanPreviewMenulis(form);
}