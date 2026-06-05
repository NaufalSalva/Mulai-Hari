#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>

using namespace std;

struct HasilSesi {
    string tanggal;
    string jam_mulai;
    string jam_selesai;
    string habit;
    string sub_habit;
    string template_timer;
    int durasi_rencana;       
    int waktu_aktual;         
    string status_penyelesaian; 
    string catatan;            
};


string hitungJamSelesai(string jamMulaiStr, int waktuAktualDetik) {
    int jam, menit, detik;
    char separator;
    stringstream ss(jamMulaiStr);
    ss >> jam >> separator >> menit >> separator >> detik;

 
    long totalDetik = (jam * 3600) + (menit * 60) + detik + waktuAktualDetik;


    totalDetik %= 86400;

    int jamAkhir = totalDetik / 3600;
    int menitAkhir = (totalDetik % 3600) / 60;
    int detikAkhir = totalDetik % 60;

    stringstream hasil;
    hasil << (jamAkhir < 10 ? "0" : "") << jamAkhir << ":"
          << (menitAkhir < 10 ? "0" : "") << menitAkhir << ":"
          << (detikAkhir < 10 ? "0" : "") << detikAkhir;

    return hasil.str();
}

bool simpanHasilKeStack(AktivitasStack& stack, const HasilSesi& hasil) {
    LogAktivitasNode dataLog;
    
    dataLog.hobi = "[TIMERS] " + hasil.habit;
    dataLog.detail = hasil.sub_habit;
    dataLog.durasi = hasil.waktu_aktual; 
    

    dataLog.mood = hasil.tanggal + "|" + 
                   hasil.jam_mulai + "|" + 
                   hasil.jam_selesai + "|" + 
                   to_string(hasil.durasi_rencana) + "|" + 
                   hasil.status_penyelesaian;

    pushAktivitas(stack, dataLog);
    
    cout << "\n[Sistem] Hasil sesi sukses di-push ke dalam tumpukan Stack RAM!\n";
    return true;
}

string getWaktuSekarang() {
    time_t now = time(0);
    tm* timeinfo = localtime(&now);
    char tanggal[20];
    strftime(tanggal, sizeof(tanggal), "%d-%m-%Y", timeinfo);
    return string(tanggal);
}

string getJamSekarang() {
    time_t now = time(0);
    tm* timeinfo = localtime(&now);
    char jam[20];
    strftime(jam, sizeof(jam), "%H:%M:%S", timeinfo);
    return string(jam);
}

string konversiDetikKeWaktu(int detik) {
    int menit = detik / 60;
    int sisa = detik % 60;
    stringstream ss;
    ss << (menit < 10 ? "0" : "") << menit << ":" << (sisa < 10 ? "0" : "") << sisa;
    return ss.str();
}

void tampilkanHasilSesi(const HasilSesi& hasil) {
    int menit_aktual = hasil.waktu_aktual / 60;
    int persen_selesai = (hasil.durasi_rencana > 0) ? (hasil.waktu_aktual * 100) / (hasil.durasi_rencana * 60) : 0;
    
    cout << "\n\n";
    cout << "==================================================\n";
    cout << "              HASIL SESI FOKUS ANDA                \n";
    cout << "==================================================\n";
    cout << "\nTanggal       : " << hasil.tanggal << "\n";
    cout << "Rentang Waktu : " << hasil.jam_mulai << " s/d " << hasil.jam_selesai << " WIB\n"; // 🔥 Lebih detail
    cout << "Habit         : " << hasil.habit << "\n";
    cout << "Sub-Habit     : " << hasil.sub_habit << "\n";
    cout << "Template      : " << hasil.template_timer << "\n";
    
    cout << "\n--- DURASI ---\n";
    cout << "Rencana       : " << hasil.durasi_rencana << " Menit\n";
    cout << "Aktual        : " << konversiDetikKeWaktu(hasil.waktu_aktual) << " (" << menit_aktual << " Menit)\n";
    cout << "Persentase    : " << persen_selesai << "%\n";
    
    cout << "\n--- STATUS ---\n";
    cout << "Penyelesaian  : " << hasil.status_penyelesaian << "\n";
    
    if (!hasil.catatan.empty()) {
        cout << "\n--- CATATAN ---\n";
        cout << hasil.catatan << "\n";
    }
    cout << "\n==================================================\n\n";
}

HasilSesi buatHasilSesi(const string& habit, const string& sub_habit, const string& template_timer, int durasi_rencana, int waktu_aktual, bool selesai_sempurna) {
    HasilSesi hasil;
    hasil.tanggal = getWaktuSekarang();
    
  
    time_t now = time(0);
    time_t waktuMulaiAsli = now - waktu_aktual;
    tm* timeinfoMulai = localtime(&waktuMulaiAsli);
    char jamMulai[20];
    strftime(jamMulai, sizeof(jamMulai), "%H:%M:%S", timeinfoMulai);
    
    hasil.jam_mulai = string(jamMulai);
    hasil.jam_selesai = getJamSekarang(); 
    
    hasil.habit = habit;
    hasil.sub_habit = sub_habit;
    hasil.template_timer = template_timer;
    hasil.durasi_rencana = durasi_rencana;
    hasil.waktu_aktual = waktu_aktual;
    hasil.status_penyelesaian = selesai_sempurna ? "Selesai" : "Berhenti di Tengah";
    hasil.catatan = "";
    return hasil;
}

void tambahCatatan(HasilSesi& hasil) {
    cout << "\nApakah Anda ingin menambahkan catatan? (y/n): ";
    char pilihan;
    cin >> pilihan;
    cin.ignore();
    
    if (pilihan == 'y' || pilihan == 'Y') {
        cout << "Masukkan catatan Anda (max 100 karakter):\n";
        getline(cin, hasil.catatan);
        if (hasil.catatan.length() > 100) {
            hasil.catatan = hasil.catatan.substr(0, 100);
        }
    }
}


void menuSetelahSesi(HasilSesi& hasil, AktivitasStack& stack) {
    cout << "\nPilihan Anda:\n";
    cout << "1. Selesaikan & Simpan Hasil\n";
    cout << "2. Selesaikan Tanpa Menyimpan\n";
    cout << "3. Kembali ke Menu Utama\n";
    cout << "Masukkan pilihan (1-3): ";
    
    int pilihan;
    if (!(cin >> pilihan)) {
        cin.clear(); cin.ignore(1000, '\n');
        pilihan = 3;
    }
    
    switch (pilihan) {
        case 1:
            tambahCatatan(hasil);
            simpanHasilKeStack(stack, hasil); 
            break;
        case 2:
            cout << "Hasil diabaikan (tidak disimpan).\n";
            break;
        case 3:
            cout << "Kembali ke menu utama...\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
    }
    system("pause");
}