#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <conio.h>
#include <iomanip>
#include <cstdlib>

using namespace std;

struct sesiFokus {
    string nama;
    int durasi;
    string deskripsi;
};

struct namaAktivitas {
    string nama_sesi;
    int waktu_aktual;
    string catatan;
    string waktu_mulai;
    bool selesai;
};

class FokusHariTimer {
private:
    int total_detik;
    int detik_berlalu;
    bool pause;
    bool stop;
    
public:
    FokusHariTimer(int menit) : total_detik(menit * 60), detik_berlalu(0), pause(false), stop(false){}
    
    void formatWaktu(int detik, string& hasil) {
        int menit = detik / 60;
        int sisa_detik = detik % 60;
        hasil = (menit < 10 ? "0" : "") + to_string(menit) + ":" +
                (sisa_detik < 10 ? "0" : "") + to_string(sisa_detik);
    }
    
    void displayTimer(int sisa_detik, string nama_sesi) {
        string waktu_str;
        formatWaktu(sisa_detik, waktu_str);
        
        system("cls");
        cout << "\n";
        cout << "==================================================\n";
        cout << "             FOKUS HARI - SESI               \n";
        cout << "==================================================\n\n";
        
        cout << "Sesi           : " << nama_sesi << "\n";
        cout << "Waktu Tersisa  : " << waktu_str << "\n";
        cout << "==================================================\n\n";
        
        if (pause) {
            cout << "STATUS: PAUSED (Tekan [P] untuk lanjut)\n";
        } else {
            cout << "STATUS: RUNNING\n";
        }
        cout << "Kontrol: [P] Pause/Resume | [S] Stop Awal\n";
        cout << "==================================================\n";
    }
    
    void setPaused(bool state) {
        pause = state;
    }
    
    void setStopped(bool state) {
        stop = state;
    }
    
    bool isPaused() const {
        return pause;
    }
    
    bool isStopped() const {
        return stop;
    }
    
    bool isComplete() const {
        return detik_berlalu >= total_detik;
    }
    
    int getDetikBerlalu() const {
        return detik_berlalu;
    }
    
    int getTotalDetik() const {
        return total_detik;
    }
    
    void incrementDetik() {
        if (!pause && !stop && detik_berlalu < total_detik) {
            detik_berlalu++;
        }
    }
};

sesiFokus getSesiKilat() {
    return {"Sesi Kilat", 15, "Fokus cepat untuk tugas ringan"};
}

sesiFokus getSesiStandar() {
    return {"Sesi Standar", 25, "Fokus standar + istirahat otomatis tercatat"};
}

sesiFokus getSesiDeepWork() {
    return {"Sesi Deep Work", 50, "Fokus mendalam untuk tugas berat"};
}

namaAktivitas runTimerSession(sesiFokus sesi) {
    FokusHariTimer timer(sesi.durasi);
    namaAktivitas record;
    record.nama_sesi = sesi.nama;
    record.selesai = false;
    
    auto waktu_mulai = chrono::system_clock::now();
    
    cout << "\n Sesi dimulai! Tekan ENTER untuk melanjutkan...\n";
    cin.ignore();
    
    while (!timer.isStopped()) {
        int sisa_detik = timer.getTotalDetik() - timer.getDetikBerlalu();
        timer.displayTimer(sisa_detik, sesi.nama);
        
        if (_kbhit()) {
            int key = _getch();
            if (key == 'P' || key == 'p') {
                timer.setPaused(!timer.isPaused());
            } else if (key == 'S' || key == 's') {
                timer.setStopped(true);
                system("cls");
                cout << "\nSesi dihentikan lebih awal!\n";
                break;
            }
        }
        
        if (!timer.isPaused()) {
            this_thread::sleep_for(chrono::milliseconds(1000));
            timer.incrementDetik();
        } else {
            this_thread::sleep_for(chrono::milliseconds(100));
        }
        
        if (timer.isComplete()) {
            break;
        }
    }
    
    auto waktu_akhir = chrono::system_clock::now();
    auto durasi = chrono::duration_cast<chrono::seconds>(waktu_akhir - waktu_mulai);
    
    record.waktu_aktual = static_cast<int>(durasi.count());
    

    system("cls");
    cout << "\n";
    cout << "==================================================\n";
    cout << "                   SESI SELESAI!                  \n";
    cout << "==================================================\n\n";
    
    cout << "Sesi               : " << sesi.nama << "\n";
    cout << "Durasi Direncanakan: " << sesi.durasi << " menit\n";
    cout << "Waktu Aktual       : " << (record.waktu_aktual / 60) << " menit " 
         << (record.waktu_aktual % 60) << " detik\n";
    cout << "Deskripsi          : " << sesi.deskripsi << "\n";
    
    if (sesi.nama == "Sesi Standar") {
        cout << "\n==================================================\n";
        cout << "        PENCATATAN ISTIRAHAT OTOMATIS          \n";
        cout << "==================================================\n";
        cout << "Tips: Istirahat 5 menit untuk sesi 25 menit\n";
        cout << "Istirahat telah dicatat secara otomatis\n";
    }
    
    cout << "\nTekan ENTER untuk kembali...";
    cin.ignore();
    
    return record;
}

void tampilkanMenuTemplate() {
    system("cls");
    cout << "\n";
    cout << "==================================================\n";
    cout << "           FOKUS HARI - PILIH MODE SESI           \n";
    cout << "==================================================\n\n";
    
    cout << "Pilih template sesi Anda:\n\n";
    
    cout << "1. SESI KILAT\n";
    cout << "   Durasi: 15 menit\n\n";

    cout << "2. SESI STANDAR \n";
    cout << "   Durasi: 25 menit\n\n";

    cout << "3. SESI DEEP WORK\n";
    cout << "   Durasi: 50 menit\n\n";

    cout << "0. Kembali ke Menu Utama\n";
    cout << "==================================================\n";
}

void fokusHariSession() {
    int pilihan;
    sesiFokus sesi_dipilih;
    bool valid = false;
    
    while (!valid) {
        tampilkanMenuTemplate();
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                sesi_dipilih = getSesiKilat();
                valid = true;
                break;
            case 2:
                sesi_dipilih = getSesiStandar();
                valid = true;
                break;
            case 3:
                sesi_dipilih = getSesiDeepWork();
                valid = true;
                break;
            case 0:
                return;
            default:
                cout << "\nPilihan tidak valid! Coba lagi.\n";
                cin.ignore();
                cin.ignore();
        }
    }
    
    system("cls");
    cout << "\n";
    cout << "==================================================\n";
    cout << "              KONFIRMASI SESI FOKUS               \n";
    cout << "==================================================\n\n";
    
    cout << "Sesi Terpilih  : " << sesi_dipilih.nama << "\n";
    cout << "Durasi         : " << sesi_dipilih.durasi << " menit\n";
    cout << "Deskripsi: " << sesi_dipilih.deskripsi << "\n\n";
    
    cout << "TIPS PENTING:\n";
    cout << " - Tutup semua distraksi sebelum memulai\n";
    cout << " - Matikan notifikasi ponsel dan komputer\n";
    cout << " - Fokus penuh pada satu tugas saja\n";
    cout << " - Gunakan [P] untuk pause, [S] untuk stop\n\n";
    
    cout << "Lanjutkan sesi? (y/n): ";
    char konfirmasi;
    cin >> konfirmasi;
    
    if (konfirmasi == 'y' || konfirmasi == 'Y') {
        namaAktivitas hasil = runTimerSession(sesi_dipilih);
        cout << "\nData sesi telah disimpan!\n";
    } else {
        cout << "\nSesi dibatalkan.\n";
    }
}

void tampilkanStatistikFokus() {
    system("cls");
    cout << "\n";
    cout << "==================================================\n";
    cout << "            STATISTIK FOKUS HARI ANDA             \n";
    cout << "==================================================\n\n";
}

void menuFokusHari() {
    int pilihan;
    bool kembali = false;
    
    while (!kembali) {
        system("cls");
        cout << "\n";
        cout << "==================================================\n";
        cout << "                    FOKUS HARI                    \n";
        cout << "                                                  \n";
        cout << "            Pembantu Fokus dengan Timer       \n";
        cout << "==================================================\n\n";
        
        cout << "Pilih opsi:\n\n";
        cout << "1. Mulai Sesi Fokus\n";
        cout << "2. Lihat Statistik Fokus Hari\n";
        cout << "0. Kembali ke Menu Utama\n";
        cout << "\n==================================================\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;
        cin.ignore();
        
        switch(pilihan) {
            case 1:
                fokusHariSession();
                break;
            case 2:
                tampilkanStatistikFokus();
                break;
            case 0:
                kembali = true;
                break;
            default:
                cout << "\nPilihan tidak valid!\n";
                this_thread::sleep_for(chrono::seconds(1));
        }
    }
}
