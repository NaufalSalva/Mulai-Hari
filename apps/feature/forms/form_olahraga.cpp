#include "../../utils/validation.cpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct FormOlahraga {
    string jenisOlahraga;
    int durasiMenit;
    string intensitas;
    float jarakKm;
    int kaloriTerbakar;
    string kondisiFisik;
    string catatan;
    string waktuAktivitas;
};

bool validasiJenisOlahraga(const string& jenis) {
    if (jenis.empty() || jenis.length() < 2) {
        return false;
    }
    return true;
}

bool validasiIntensitas(const string& intensitas) {
    return (intensitas == "Rendah" || intensitas == "Sedang" || intensitas == "Tinggi");
}

bool validasiJarak(float jarak) {
    return (jarak >= 0 && jarak <= 100);
}

bool validasiKalori(int kalori) {
    return (kalori >= 0 && kalori <= 2000);
}

void tampilkanMenuIntensitas() {
    cout << "\n=========== PILIH INTENSITAS ==============\n";
    cout << "1. Rendah    (Berjalan santai, Yoga)       \n";
    cout << "2. Sedang    (Lari ringan, Bersepeda)      \n";
    cout << "3. Tinggi    (HIIT, Gym)                   \n";
    cout << "========================================== \n";
}

string pilihanIntensitas(int pilihan) {
    switch(pilihan) {
        case 1: return "Rendah";
        case 2: return "Sedang";
        case 3: return "Tinggi";
        default: return "Sedang";
    }
}

int estimasiKalori(const string& jenis, int durasi, const string& intensitas) {
    int kalori_per_menit = 0;
    
    if (jenis == "Lari") {
        if (intensitas == "Rendah") kalori_per_menit = 8;
        else if (intensitas == "Sedang") kalori_per_menit = 12;
        else kalori_per_menit = 16;
    }
    else if (jenis == "Bersepeda") {
        if (intensitas == "Rendah") kalori_per_menit = 6;
        else if (intensitas == "Sedang") kalori_per_menit = 10;
        else kalori_per_menit = 14;
    }
    else if (jenis == "Gym") {
        if (intensitas == "Rendah") kalori_per_menit = 5;
        else if (intensitas == "Sedang") kalori_per_menit = 8;
        else kalori_per_menit = 12;
    }
    else if (jenis == "Yoga") {
        kalori_per_menit = 3;
    }
    else if (jenis == "Renang") {
        if (intensitas == "Rendah") kalori_per_menit = 7;
        else if (intensitas == "Sedang") kalori_per_menit = 11;
        else kalori_per_menit = 15;
    }
    else {
        kalori_per_menit = 6;
    }
    
    return kalori_per_menit * durasi;
}

FormOlahraga inputFormOlahraga() {
    FormOlahraga form;
    int pilihan;
    
    system("cls");
    cout << "\n";
    cout << "=============================================\n";
    cout << "            FORM AKTIVITAS OLAHRAGA          \n";
    cout << "=============================================\n\n";
    

    cout << "============= 1. JENIS OLAHRAGA =============\n";
    cout << "Lari, Gym, Yoga, Renang, Bersepeda\n";
    cout << "Masukkan jenis: ";
    getline(cin, form.jenisOlahraga);
    
    while (!validasiJenisOlahraga(form.jenisOlahraga)) {
        cout << "Jenis olahraga tidak valid! Masukkan lagi: ";
        getline(cin, form.jenisOlahraga);
    }
    

    cout << "============= 2. DURASI OLAHRAGA =============\n";
    form.durasiMenit = validasiInputAngka(1, 480, "Masukkan durasi (dalam menit): ");
    
    while (!validasiDurasi(form.durasiMenit)) {
        form.durasiMenit = validasiInputAngka(1, 480, "Durasi harus 1-480 menit! Masukkan lagi: ");
    }
    

    cout << "============= 3. INTENSITAS OLAHRAGA =============\n";
    tampilkanMenuIntensitas();
    cout << "Pilih intensitas (1-3): ";
    pilihan = validasiInputAngka(1, 3, "Pilih intensitas (1-3): ");
    form.intensitas = pilihanIntensitas(pilihan);
    

    cout << "\n============= 4. JARAK OLAHRAGA =============\n";
    form.jarakKm = validasiInputAngka(0, 100, "Masukkan jarak (dalam km): ");
    
    while (!validasiJarak(form.jarakKm)) {
        cout << "Jarak harus 0-100 km! Masukkan lagi: ";
        form.jarakKm = validasiInputAngka(0, 100, "Masukkan jarak (dalam km): ");
    }
    

    form.kaloriTerbakar = estimasiKalori(form.jenisOlahraga, form.durasiMenit, form.intensitas);
    cout << "============= 5. ESTIMASI KALORI TERBAKAR =============\n";
    cout << "Estimasi: " << form.kaloriTerbakar << " kalori (otomatis)\n";
    

    cout << "\n============= 6. KONDISI FISIK =============\n";
    cout << "Contoh: Segar, Lelah, Kesakitan, Pulih\n";
    cout << "Masukkan kondisi: ";
    getline(cin, form.kondisiFisik);
    

    cout << "\n============= 7. WAKTU AKTIVITAS =============\n";
    tampilkanMenuWaktu();
    pilihan = validasiInputAngka(1, 4, "Pilih waktu (1-4): ");
    form.waktuAktivitas = pilihanWaktu(pilihan);
    cin.ignore();
    

    cout << "\n============= 8. CATATAN TAMBAHAN =============\n";
    cout << "Catatan: ";
    getline(cin, form.catatan);
    
    return form;
}


string standardisasiDetailOlahraga(const FormOlahraga& form) {
    string detail = "";
    
    // Format: [Jenis] | [Durasi]min | [Intensitas] | Kalori: [Kalori] | [Kondisi] | [Waktu]
    detail += form.jenisOlahraga;
    detail += " | ";
    detail += to_string(form.durasiMenit) + " menit";
    
    if (form.jarakKm > 0) {
        detail += " | " + to_string(form.jarakKm) + " km";
    }
    
    detail += " | " + form.intensitas;
    detail += " | Kalori: " + to_string(form.kaloriTerbakar);
    detail += " | Kondisi: " + form.kondisiFisik;
    detail += " | Waktu: " + form.waktuAktivitas;
    
    if (!form.catatan.empty()) {
        detail += " | Catatan: " + form.catatan;
    }
    
    return detail;
}


void tampilkanPreviewOlahraga(const FormOlahraga& form) {
    system("cls");
    cout << "\n";
    cout << "=============================================\n";
    cout << "           PREVIEW AKTIVITAS OLAHRAGA        \n";
    cout << "=============================================\n\n";
    
    cout << "Detail Aktivitas:\n";
    cout << "=============================================\n";
    cout << "Jenis Olahraga : " << form.jenisOlahraga << "\n";
    cout << "Durasi         : " << form.durasiMenit << " menit\n";
    
    if (form.jarakKm > 0) {
        cout << "Jarak          : " << fixed << setprecision(2) << form.jarakKm << " km\n";
    }
    
    cout << "Intensitas     : " << form.intensitas << "\n";
    cout << "Kalori Terbakar: " << form.kaloriTerbakar << " kkal\n";
    cout << "Kondisi Fisik  : " << form.kondisiFisik << "\n";
    cout << "Waktu Aktivitas: " << form.waktuAktivitas << "\n";
    
    if (!form.catatan.empty()) {
        cout << "Catatan        : " << form.catatan << "\n";
    }
    
    cout << "\n=============================================\n";
    cout << "String Detail Terstandarisasi:\n";
    cout << standardisasiDetailOlahraga(form) << "\n";
    cout << "=============================================\n";
    
    cout << "\nTekan ENTER untuk kembali...";
    cin.ignore();
}

void formOlahraga() {
    FormOlahraga form = inputFormOlahraga();
    tampilkanPreviewOlahraga(form);
}
