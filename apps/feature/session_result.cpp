#include <iostream>

#include <fstream>
#include <ctime>
#include <sstream>


using namespace std;
const string file_user = "apps/data/session_results.txt";
// Struct untuk menyimpan hasil sesi
struct HasilSesi {
    string tanggal;
    string jam_mulai;
    string habit;
    string sub_habit;
    string template_timer;
    int durasi_rencana;      // durasi awal dalam menit
    int waktu_aktual;        // waktu yang benar-benar dijalani dalam detik
    string status_penyelesaian; // "Selesai" atau "Berhenti di Tengah"
    string catatan;          // catatan tambahan dari user
};

// Fungsi untuk mendapatkan waktu saat ini
string getWaktuSekarang() {
    time_t now = time(0);
    tm* timeinfo = localtime(&now);
    
    char tanggal[20];
    strftime(tanggal, sizeof(tanggal), "%d-%m-%Y", timeinfo);
    
    return string(tanggal);
}

// Fungsi untuk mendapatkan jam saat ini
string getJamSekarang() {
    time_t now = time(0);
    tm* timeinfo = localtime(&now);
    
    char jam[20];
    strftime(jam, sizeof(jam), "%H:%M:%S", timeinfo);
    
    return string(jam);
}

// Fungsi untuk konversi detik ke format MM:SS
string konversiDetikKeWaktu(int detik) {
    int menit = detik / 60;
    int sisa = detik % 60;
    
    stringstream ss;
    ss << (menit < 10 ? "0" : "") << menit << ":"
       << (sisa < 10 ? "0" : "") << sisa;
    
    return ss.str();
}

// Fungsi untuk menampilkan hasil sesi
void tampilkanHasilSesi(const HasilSesi& hasil) {
    int menit_aktual = hasil.waktu_aktual / 60;
    int persen_selesai = (hasil.waktu_aktual * 100) / (hasil.durasi_rencana * 60);
    
    cout << "\n\n";
    cout << "==================================================\n";
    cout << "              HASIL SESI FOKUS ANDA                \n";
    cout << "==================================================\n";
    cout << "\nTanggal       : " << hasil.tanggal << "\n";
    cout << "Jam Mulai     : " << hasil.jam_mulai << "\n";
    cout << "Habit         : " << hasil.habit << "\n";
    cout << "Sub-Habit     : " << hasil.sub_habit << "\n";
    cout << "Template      : " << hasil.template_timer << "\n";
    
    cout << "\n--- DURASI ---\n";
    cout << "Rencana       : " << hasil.durasi_rencana << " Menit\n";
    cout << "Aktual        : " << konversiDetikKeWaktu(hasil.waktu_aktual) 
         << " (" << menit_aktual << " Menit)\n";
    cout << "Persentase    : " << persen_selesai << "%\n";
    
    cout << "\n--- STATUS ---\n";
    cout << "Penyelesaian  : " << hasil.status_penyelesaian << "\n";
    
    if (!hasil.catatan.empty()) {
        cout << "\n--- CATATAN ---\n";
        cout << hasil.catatan << "\n";
    }
    
    cout << "\n==================================================\n";
    
    // Tampilkan motivasi berdasarkan persentase
    cout << "\n";
    if (persen_selesai >= 100) {
        cout << "✓ Luar biasa! Anda menyelesaikan sesi dengan sempurna!\n";
    } else if (persen_selesai >= 80) {
        cout << "✓ Sangat bagus! Hampir sempurna, terus semangat!\n";
    } else if (persen_selesai >= 60) {
        cout << "✓ Bagus! Anda sudah fokus cukup lama. Pertahankan!\n";
    } else if (persen_selesai >= 40) {
        cout << "→ Lumayan, namun coba tingkatkan fokus Anda lagi.\n";
    } else {
        cout << "→ Jangan menyerah! Coba lagi dengan durasi lebih pendek.\n";
    }
    cout << "\n";
}

// Fungsi untuk menyimpan hasil ke file
bool simpanHasilKeFile(const HasilSesi& hasil) {
    ofstream file(file_user, ios::app);
    
    if (!file.is_open()) {
        cout << "Gagal membuka file untuk menyimpan hasil!\n";
        return false;
    }
    
    // Format: tanggal|jam|habit|sub_habit|template|durasi_rencana|waktu_aktual|status|catatan
    file << hasil.tanggal << "|"
         << hasil.jam_mulai << "|"
         << hasil.habit << "|"
         << hasil.sub_habit << "|"
         << hasil.template_timer << "|"
         << hasil.durasi_rencana << "|"
         << hasil.waktu_aktual << "|"
         << hasil.status_penyelesaian << "|"
         << hasil.catatan << "\n";
    
    file.close();
    cout << "Hasil sesi telah disimpan!\n";
    return true;
}

// Fungsi untuk memproses hasil akhir sesi
HasilSesi buatHasilSesi(
    const string& habit,
    const string& sub_habit,
    const string& template_timer,
    int durasi_rencana,
    int waktu_aktual,
    bool selesai_sempurna
) {
    HasilSesi hasil;
    
    hasil.tanggal = getWaktuSekarang();
    hasil.jam_mulai = getJamSekarang();
    hasil.habit = habit;
    hasil.sub_habit = sub_habit;
    hasil.template_timer = template_timer;
    hasil.durasi_rencana = durasi_rencana;
    hasil.waktu_aktual = waktu_aktual;
    
    if (selesai_sempurna) {
        hasil.status_penyelesaian = "Selesai";
    } else {
        hasil.status_penyelesaian = "Berhenti di Tengah";
    }
    
    hasil.catatan = "";
    
    return hasil;
}

// Fungsi untuk menambahkan catatan setelah sesi
void tambahCatatan(HasilSesi& hasil) {
    cout << "\nApakah Anda ingin menambahkan catatan? (y/n): ";
    char pilihan;
    cin >> pilihan;
    cin.ignore();
    
    if (pilihan == 'y' || pilihan == 'Y') {
        cout << "Masukkan catatan Anda (max 100 karakter):\n";
        getline(cin, hasil.catatan);
        
        // Batasi panjang catatan
        if (hasil.catatan.length() > 100) {
            hasil.catatan = hasil.catatan.substr(0, 100);
        }
    }
}

// Fungsi untuk menampilkan menu opsi setelah sesi selesai
void menuSetelahSesi(HasilSesi& hasil) {
    cout << "\n\nPilihan Anda:\n";
    cout << "1. Selesaikan & Simpan Hasil\n";
    cout << "2. Selesaikan Tanpa Menyimpan\n";
    cout << "3. Kembali ke Menu Utama\n";
    cout << "Masukkan pilihan (1-3): ";
    
    int pilihan;
    cin >> pilihan;
    
    switch (pilihan) {
        case 1:
            tambahCatatan(hasil);
            simpanHasilKeFile(hasil);
            break;
        case 2:
            cout << "Hasil tidak disimpan.\n";
            break;
        case 3:
            cout << "Kembali ke menu utama...\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
    }
}
