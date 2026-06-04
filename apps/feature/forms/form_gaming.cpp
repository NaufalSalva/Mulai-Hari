#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct FormGaming {
    string namaGame;
    string genreGame;
    string tujuanMain;
    int durasiMenit;
    string catatan;
    string waktuAktivitas;
};

bool validasiNamaGame(const string& nama) {
    if (nama.empty() || nama.length() < 2) {
        return false;
    }
    return true;
}

bool validasiDurasi(int durasi_menit) {
    return (durasi_menit > 0 && durasi_menit <= 480);
}


void tampilkanMenuWaktu() {
    cout << "\n========== PILIH WAKTU AKTIVITAS ==========\n";
    cout << "1. Pagi    (05:00 - 11:00)                   \n";
    cout << "2. Siang   (11:00 - 15:00)                   \n";
    cout << "3. Sore    (15:00 - 18:00)                   \n";
    cout << "4. Malam   (18:00 - 23:00)                   \n";
    cout << "========================================== \n";
}

string pilihanWaktu(int pilihan) {
    switch(pilihan) {
        case 1: return "Pagi";
        case 2: return "Siang";
        case 3: return "Sore";
        case 4: return "Malam";
        default: return "Siang";
    }
}


FormGaming inputFormGaming() {
    FormGaming form;
    int pilihan;
    
    system("cls");
    cout << "\n";
    cout << "=============================================\n";
    cout << "            FORM AKTIVITAS GAMING        \n";
    cout << "=============================================\n\n";
    

    cout << "============= 1. NAMA GAME =============\n";
    cout << "Nama Game: ";
    getline(cin, form.namaGame);
    
    while (!validasiNamaGame(form.namaGame)) {
        cout << "Nama game tidak valid! Masukkan lagi: ";
        getline(cin, form.namaGame);
    }
    

    cout << "============= 2. DURASI MENULIS =============\n";
    cout << "Masukkan durasi (dalam menit): ";
    cin >> form.durasiMenit;
    
    while (!validasiDurasi(form.durasiMenit)) {
        cout << "Durasi harus 1-480 menit! Masukkan lagi: ";
        cin >> form.durasiMenit;
    }
    cin.ignore();

    cout << "\n============= 3. GENRE GAME =============\n";
    cout << "1. Action\n";
    cout << "2. RPG\n";
    cout << "3. FPS\n";
    cout << "4. MOBA\n";
    cout << "5. Strategy\n";
    cout << "6. Simulation\n";
    cout << "7. Sports\n";
    cout << "8. Racing\n";
    cout << "9. Lainnya\n";
    cout << "Pilih genre (1-9): ";
    cin >> pilihan;
    cin.ignore();

    switch (pilihan) {
        case 1: form.genreGame = "Action"; break;
        case 2: form.genreGame = "RPG"; break;
        case 3: form.genreGame = "FPS"; break;
        case 4: form.genreGame = "MOBA"; break;
        case 5: form.genreGame = "Strategy"; break;
        case 6: form.genreGame = "Simulation"; break;
        case 7: form.genreGame = "Sports"; break;
        case 8: form.genreGame = "Racing"; break;
        default: form.genreGame = "Lainnya"; break;
    }

     cout << "\n============= 4. TUJUAN MAIN =============\n";
    cout << "1. Hiburan\n";
    cout << "2. Menghilangkan Stres\n";
    cout << "3. Chill With Bros\n";
    cout << "4. Latihan\n";
    cout << "5. Mencari Achievement\n";
    cout << "6. Lainnya\n";
    cout << "Pilih genre (1-6): ";
    cin >> pilihan;
    cin.ignore();

    switch (pilihan) {
        case 1: form.tujuanMain = "Hiburan"; break;
        case 2: form.tujuanMain = "Menghilangkan Stres"; break;
        case 3: form.tujuanMain = "Chill With Bros"; break;
        case 4: form.tujuanMain = "Latihan"; break;
        case 5: form.tujuanMain = "Mencari Achievement"; break;
        case 6: form.tujuanMain = "Lainnya"; break;
    }

    cout << "\n============= 5. WAKTU AKTIVITAS =============\n";
    tampilkanMenuWaktu();
    cout << "Pilih waktu (1-4): ";
    cin >> pilihan;
    form.waktuAktivitas = pilihanWaktu(pilihan);
    cin.ignore();

    cout << "\n============= 6. CATATAN TAMBAHAN =============\n";
    cout << "Catatan: ";
    getline(cin, form.catatan);
    
    return form;
}


string standardisasiDetailGaming(const FormGaming& form)
{
    string detail = "";

    detail += form.namaGame;
    detail += " | ";
    detail += form.genreGame;
    detail += " | ";
    detail += form.tujuanMain;
    detail += " | ";
    detail += to_string(form.durasiMenit) + " menit";
    detail += " | Waktu: " + form.waktuAktivitas;

    if(!form.catatan.empty())
    {
        detail += " | Catatan: " + form.catatan;
    }

    return detail;
}


void tampilkanPreviewGaming(const FormGaming& form) {
    system("cls");
    cout << "\n";
    cout << "=============================================\n";
    cout << "           PREVIEW AKTIVITAS GAMING       \n";
    cout << "=============================================\n\n";
    
    cout << "Detail Aktivitas:\n";
    cout << "=============================================\n";
    cout << "Nama Game : " << form.namaGame << "\n";
    cout << "Genre Game     : " << form.genreGame << "\n";
    cout << "Tujuan Main    : " << form.tujuanMain << "\n";
    cout << "Durasi         : " << form.durasiMenit << " menit\n";
    cout << "Waktu Aktivitas: " << form.waktuAktivitas << "\n";

    if (!form.catatan.empty()) {
        cout << "Catatan        : " << form.catatan << "\n";
    }
    
    cout << "\n=============================================\n";
    cout << "String Detail Terstandarisasi:\n";
    cout << standardisasiDetailGaming(form) << "\n";
    cout << "=============================================\n";
    
    cout << "\nTekan ENTER untuk kembali...";
    cin.ignore();
}

void formGaming() {
    FormGaming form = inputFormGaming();
    tampilkanPreviewGaming (form);
}