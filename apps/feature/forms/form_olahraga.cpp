#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct FormOlahraga {
    string jenis_olahraga;
    int durasi_menit;
    string intensitas;
    float jarak_km;
    int kalori_terbakar;
    string kondisi_fisik;
    string catatan;
    string waktu_aktivitas;
};

bool validasiJenisOlahraga(const string& jenis) {
    if (jenis.empty() || jenis.length() < 2) {
        return false;
    }
    return true;
}

bool validasiDurasi(int durasi_menit) {
    return (durasi_menit > 0 && durasi_menit <= 480);
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
    cout << "          FORMULIR AKTIVITAS OLAHRAGA        \n";
    cout << "=============================================\n\n";
    

    cout << "============= 1. JENIS OLAHRAGA =============\n";
    cout << "Lari, Gym, Yoga, Renang, Bersepeda\n";
    cout << "Masukkan jenis: ";
    getline(cin, form.jenis_olahraga);
    
    while (!validasiJenisOlahraga(form.jenis_olahraga)) {
        cout << "Jenis olahraga tidak valid! Masukkan lagi: ";
        getline(cin, form.jenis_olahraga);
    }
    

    cout << "============= 2. DURASI OLAHRAGA =============\n";
    cout << "Masukkan durasi (dalam menit): ";
    cin >> form.durasi_menit;
    
    while (!validasiDurasi(form.durasi_menit)) {
        cout << "Durasi harus 1-480 menit! Masukkan lagi: ";
        cin >> form.durasi_menit;
    }
    cin.ignore();
    

    cout << "============= 3. INTENSITAS OLAHRAGA =============\n";
    tampilkanMenuIntensitas();
    cout << "Pilih intensitas (1-3): ";
    cin >> pilihan;
    form.intensitas = pilihanIntensitas(pilihan);
    cin.ignore();
    

    cout << "\n============= 4. JARAK OLAHRAGA =============\n";
    cout << "   Masukkan jarak (dalam km): ";
    cin >> form.jarak_km;
    
    while (!validasiJarak(form.jarak_km)) {
        cout << "Jarak harus 0-100 km! Masukkan lagi: ";
        cin >> form.jarak_km;
    }
    cin.ignore();
    

    form.kalori_terbakar = estimasiKalori(form.jenis_olahraga, form.durasi_menit, form.intensitas);
    cout << "============= 5. ESTIMASI KALORI TERBAKAR =============\n";
    cout << "Estimasi: " << form.kalori_terbakar << " kalori (otomatis)\n";
    

    cout << "\n============= 6. KONDISI FISIK =============\n";
    cout << "Contoh: Segar, Lelah, Kesakitan, Pulih\n";
    cout << "Masukkan kondisi: ";
    getline(cin, form.kondisi_fisik);
    

    cout << "\n============= 7. WAKTU AKTIVITAS =============\n";
    tampilkanMenuWaktu();
    cout << "   Pilih waktu (1-4): ";
    cin >> pilihan;
    form.waktu_aktivitas = pilihanWaktu(pilihan);
    cin.ignore();
    

    cout << "\n============= 8. CATATAN TAMBAHAN =============\n";
    cout << "   Catatan: ";
    getline(cin, form.catatan);
    
    return form;
}


string standardisasiDetailOlahraga(const FormOlahraga& form) {
    string detail = "";
    
    // Format: [Jenis] | [Durasi]min | [Intensitas] | Kalori: [Kalori] | [Kondisi] | [Waktu]
    detail += form.jenis_olahraga;
    detail += " | ";
    detail += to_string(form.durasi_menit) + " menit";
    
    if (form.jarak_km > 0) {
        detail += " | " + to_string(form.jarak_km) + " km";
    }
    
    detail += " | " + form.intensitas;
    detail += " | Kalori: " + to_string(form.kalori_terbakar);
    detail += " | Kondisi: " + form.kondisi_fisik;
    detail += " | Waktu: " + form.waktu_aktivitas;
    
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
    cout << "Jenis Olahraga : " << form.jenis_olahraga << "\n";
    cout << "Durasi         : " << form.durasi_menit << " menit\n";
    
    if (form.jarak_km > 0) {
        cout << "Jarak          : " << fixed << setprecision(2) << form.jarak_km << " km\n";
    }
    
    cout << "Intensitas     : " << form.intensitas << "\n";
    cout << "Kalori Terbakar: " << form.kalori_terbakar << " kkal\n";
    cout << "Kondisi Fisik  : " << form.kondisi_fisik << "\n";
    cout << "Waktu Aktivitas: " << form.waktu_aktivitas << "\n";
    
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
