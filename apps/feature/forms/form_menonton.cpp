#include "../../utils/validation.cpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct FormMenonton {
    string judulTontonan;
    string jenisTontonan;
    string platformTontonan;
    string genreTontonan;
    int durasiMenit;
    string catatan;
    string waktuAktivitas;
};

bool validasiJudulTontonan(const string& judul) {
    if (judul.empty() || judul.length() < 2) {
        return false;
    }
    return true;
}


FormMenonton inputFormMenonton() {
    FormMenonton form;
    int pilihan;
    
    system("cls");
    cout << "\n";
    cout << "=============================================\n";
    cout << "            FORM AKTIVITAS MENONTON        \n";
    cout << "=============================================\n\n";
    

    cout << "============= 1. JUDUL TONTONAN =============\n";
    cout << "Judul Tontonan: ";
    getline(cin, form.judulTontonan);
    
    while (!validasiJudulTontonan(form.judulTontonan)) {
        cout << "Judul tontonan tidak valid! Masukkan lagi: ";
        getline(cin, form.judulTontonan);
    }
    

    cout << "============= 2. DURASI MENONTON =============\n";
    form.durasiMenit = validasiInputAngka(1, 480, "Masukkan durasi (dalam menit): ");

    while (!validasiDurasi(form.durasiMenit)) {
        form.durasiMenit = validasiInputAngka(1, 480, "Masukkan durasi (dalam menit): ");
    }

    cout << "\n============= 3. JENIS TONTONAN =============\n";
    cout << "1. Film\n";
    cout << "2. Series\n";
    cout << "3. Anime\n";
    cout << "4. Documenter\n";
    cout << "5. Live Streaming\n";
    cout << "6. Podcast\n";
    cout << "7. Lainnya\n";
    pilihan = validasiInputAngka(1, 7, "Pilih jenis tontonan (1-7): ");

    switch (pilihan) {
        case 1: form.jenisTontonan = "Film"; break;
        case 2: form.jenisTontonan = "Series"; break;
        case 3: form.jenisTontonan = "Anime"; break;
        case 4: form.jenisTontonan = "Documenter"; break;
        case 5: form.jenisTontonan = "Live Streaming"; break;
        case 6: form.jenisTontonan = "Podcast"; break;
        case 7: form.jenisTontonan = "Lainnya"; break;
        default: form.jenisTontonan = "Lainnya"; break;
    }

    cout << "\n============= 4. PLATFORM MENONTON =============\n";
    cout << "1. YouTube\n";
    cout << "2. Netflix\n";
    cout << "3. Disney+\n";
    cout << "4. TV\n";
    cout << "5. Prime Video\n";
    cout << "6. Lainnya\n";
    pilihan = validasiInputAngka(1, 6, "Pilih platform (1-6): ");

    switch (pilihan) {
        case 1: form.platformTontonan = "YouTube"; break;
        case 2: form.platformTontonan = "Netflix"; break;
        case 3: form.platformTontonan = "Disney+"; break;
        case 4: form.platformTontonan = "TV"; break;
        case 5: form.platformTontonan = "Prime Video"; break;
        case 6: form.platformTontonan = "Lainnya"; break;
        default: form.platformTontonan = "Lainnya"; break;
    }

     cout << "\n============= 5. GENRE TONTONAN =============\n";
    cout << "1. Action\n";
    cout << "2. Komedi\n";
    cout << "3. Drama\n";
    cout << "4. Horror\n";
    cout << "5. Romance\n";
    cout << "6. Lainnya\n";
    pilihan = validasiInputAngka(1, 6, "Pilih genre (1-6): ");

    switch (pilihan) {
        case 1: form.genreTontonan = "Action"; break;
        case 2: form.genreTontonan = "Komedi"; break;
        case 3: form.genreTontonan = "Drama"; break;
        case 4: form.genreTontonan = "Horror"; break;
        case 5: form.genreTontonan = "Romance"; break;
        case 6: form.genreTontonan = "Lainnya"; break;
        default: form.genreTontonan = "Lainnya"; break;
    }

    cout << "\n============= 6. WAKTU AKTIVITAS =============\n";
    tampilkanMenuWaktu();
    pilihan = validasiInputAngka(1, 4, "Pilih waktu (1-4): ");
    form.waktuAktivitas = pilihanWaktu(pilihan);

    cout << "\n============= 7. CATATAN TAMBAHAN =============\n";
    cout << "Catatan: ";
    getline(cin, form.catatan);
    
    return form;
}


string standardisasiDetailMenonton(const FormMenonton& form)
{
    string detail = "";

    detail += form.judulTontonan;
    detail += " | ";
    detail += form.genreTontonan;
    detail += " | ";
    detail += form.platformTontonan;
    detail += " | ";
    detail += form.jenisTontonan;
    detail += " | ";
    detail += to_string(form.durasiMenit) + " menit";
    detail += " | Waktu: " + form.waktuAktivitas;

    if(!form.catatan.empty())
    {
        detail += " | Catatan: " + form.catatan;
    }

    return detail;
}


void tampilkanPreviewMenonton(const FormMenonton& form) {
    system("cls");
    cout << "\n";
    cout << "=============================================\n";
    cout << "           PREVIEW AKTIVITAS MENONTON       \n";
    cout << "=============================================\n\n";
    
    cout << "Detail Aktivitas:\n";
    cout << "=============================================\n";
    cout << "Judul Tontonan : " << form.judulTontonan << "\n";
    cout << "Jenis Tontonan     : " << form.jenisTontonan << "\n";
    cout << "Genre Tontonan     : " << form.genreTontonan << "\n";
    cout << "Platform Tontonan    : " << form.platformTontonan << "\n";
    cout << "Durasi         : " << form.durasiMenit << " menit\n";
    cout << "Waktu Aktivitas: " << form.waktuAktivitas << "\n";

    if (!form.catatan.empty()) {
        cout << "Catatan        : " << form.catatan << "\n";
    }
    
    cout << "\n=============================================\n";
    cout << "String Detail Terstandarisasi:\n";
    cout << standardisasiDetailMenonton(form) << "\n";
    cout << "=============================================\n";
    
    cout << "\nTekan ENTER untuk kembali...";
    cin.ignore();
}

void formMenonton() {
    FormMenonton form = inputFormMenonton();
    tampilkanPreviewMenonton(form);
}