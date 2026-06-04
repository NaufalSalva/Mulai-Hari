#include "../../utils/validation.cpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct FormMembaca {
    string judulBacaan;
    string genreBacaan;
    string mediaBacaan;
    string tujuanMembaca;
    int durasiMenit;
    string catatan;
    string waktuAktivitas;
};

bool validasiJudulBacaan(const string& judul) {
    if (judul.empty() || judul.length() < 2) {
        return false;
    }
    return true;
}

FormMembaca inputFormMembaca() {
    FormMembaca form;
    int pilihan;
    
    system("cls");
    cout << "\n";
    cout << "=============================================\n";
    cout << "            FORM AKTIVITAS MEMBACA        \n";
    cout << "=============================================\n\n";
    

    cout << "============= 1. JUDUL BACAAN =============\n";
    cout << "Judul Bacaan: ";
    getline(cin, form.judulBacaan);
    
    while (!validasiJudulBacaan(form.judulBacaan)) {
        cout << "Judul bacaan tidak valid! Masukkan lagi: ";
        getline(cin, form.judulBacaan);
    }
    

    cout << "============= 2. DURASI MEMBACA =============\n";
    cout << "Masukkan durasi (dalam menit): ";
    cin >> form.durasiMenit;
    
    while (!validasiDurasi(form.durasiMenit)) {
        cout << "Durasi harus 1-480 menit! Masukkan lagi: ";
        cin >> form.durasiMenit;
    }
    cin.ignore();

    cout << "\n============= 3. GENRE BACAAN =============\n";
    cout << "1. Action\n";
    cout << "2. Fantasi\n";
    cout << "3. Komedi\n";
    cout << "4. Misteri\n";
    cout << "5. Horror\n";
    cout << "6. Thriller\n";
    cout << "7. Lainnya\n";
    cout << "Pilih genre (1-7): ";
    cin >> pilihan;
    cin.ignore();

    switch (pilihan) {
        case 1: form.genreBacaan = "Action"; break;
        case 2: form.genreBacaan = "Fantasi"; break;
        case 3: form.genreBacaan = "Komedi"; break;
        case 4: form.genreBacaan = "Misteri"; break;
        case 5: form.genreBacaan = "Horror"; break;
        case 6: form.genreBacaan = "Thriller"; break;
        case 7: form.genreBacaan = "Lainnya"; break;
        default: form.genreBacaan = "Lainnya"; break;
    }

    cout << "\n============= 4. MEDIA BACA =============\n";
    cout << "1. Buku Fisik\n";
    cout << "2. E-Book\n";
    cout << "3. Jurnal Online\n";
    cout << "4. Website\n";
    cout << "5. PDF\n";
    cout << "6. Lainnya\n";
    cout << "Pilih media (1-6): ";
    cin >> pilihan;
    cin.ignore();

    switch (pilihan) {
        case 1: form.mediaBacaan = "Buku Fisik"; break;
        case 2: form.mediaBacaan = "E-Book"; break;
        case 3: form.mediaBacaan = "Jurnal Online"; break;
        case 4: form.mediaBacaan = "Website"; break;
        case 5: form.mediaBacaan = "PDF"; break;
        case 6: form.mediaBacaan = "Lainnya"; break;
        default: form.mediaBacaan = "Lainnya"; break;
    }

     cout << "\n============= 5. TUJUAN MEMBACA =============\n";
    cout << "1. Belajar\n";
    cout << "2. Hiburan\n";
    cout << "3. Riset\n";
    cout << "4. Mencari Inspirasi\n";
    cout << "5. Menambah Wawasan\n";
    cout << "6. Lainnya\n";
    cout << "Pilih tujuan (1-6): ";
    cin >> pilihan;
    cin.ignore();

    switch (pilihan) {
        case 1: form.tujuanMembaca = "Belajar"; break;
        case 2: form.tujuanMembaca = "Hiburan"; break;
        case 3: form.tujuanMembaca = "Riset"; break;
        case 4: form.tujuanMembaca = "Mencari Inspirasi"; break;
        case 5: form.tujuanMembaca = "Menambah Wawasan"; break;
        case 6: form.tujuanMembaca = "Lainnya"; break;
        default: form.tujuanMembaca = "Lainnya"; break;
    }

    cout << "\n============= 6. WAKTU AKTIVITAS =============\n";
    tampilkanMenuWaktu();
    cout << "Pilih waktu (1-4): ";
    cin >> pilihan;
    form.waktuAktivitas = pilihanWaktu(pilihan);
    cin.ignore();

    cout << "\n============= 7. CATATAN TAMBAHAN =============\n";
    cout << "Catatan: ";
    getline(cin, form.catatan);
    
    return form;
}


string standardisasiDetailMembaca(const FormMembaca& form)
{
    string detail = "";

    detail += form.judulBacaan;
    detail += " | ";
    detail += form.genreBacaan;
    detail += " | ";
    detail += form.tujuanMembaca;
    detail += " | ";
    detail += form.mediaBacaan;
    detail += " | ";
    detail += to_string(form.durasiMenit) + " menit";
    detail += " | Waktu: " + form.waktuAktivitas;

    if(!form.catatan.empty())
    {
        detail += " | Catatan: " + form.catatan;
    }

    return detail;
}


void tampilkanPreviewMembaca(const FormMembaca& form) {
    system("cls");
    cout << "\n";
    cout << "=============================================\n";
    cout << "           PREVIEW AKTIVITAS MEMBACA       \n";
    cout << "=============================================\n\n";
    
    cout << "Detail Aktivitas:\n";
    cout << "=============================================\n";
    cout << "Judul Bacaan : " << form.judulBacaan << "\n";
    cout << "Genre Bacaan     : " << form.genreBacaan << "\n";
    cout << "Tujuan Membaca    : " << form.tujuanMembaca << "\n";
    cout << "Media Bacaan         : " << form.mediaBacaan << "\n";
    cout << "Durasi         : " << form.durasiMenit << " menit\n";
    cout << "Waktu Aktivitas: " << form.waktuAktivitas << "\n";

    if (!form.catatan.empty()) {
        cout << "Catatan        : " << form.catatan << "\n";
    }
    
    cout << "\n=============================================\n";
    cout << "String Detail Terstandarisasi:\n";
    cout << standardisasiDetailMembaca(form) << "\n";
    cout << "=============================================\n";
    
    cout << "\nTekan ENTER untuk kembali...";
    cin.ignore();
}

void formMembaca() {
    FormMembaca form = inputFormMembaca();
    tampilkanPreviewMembaca(form);
}