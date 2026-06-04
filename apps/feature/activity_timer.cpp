#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <conio.h>
#include <iomanip>
#include <cstdlib>
#include "focus_session.cpp"
#include "session_result.cpp"
#include "session_history.cpp"

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

void fokusHariSessionBaru(HabitNode* root) {
   
    SesiFokusAktif sesi;
    if (!setupSesiFokus(root, sesi)) {
        cout << "Setup sesi gagal!\n";
        return;
    }
    
    tampilkanRingkasanSesi(sesi);
    

    FokusHariTimer timer(sesi.durasi_menit);
    
    while (!timer.isStopped()) {
        int sisa_detik = timer.getTotalDetik() - timer.getDetikBerlalu();
        
    
        string waktu_str;
        timer.formatWaktu(sisa_detik, waktu_str);
        
        system("cls");
        cout << "\n";
        cout << "==================================================\n";
        cout << "              SESI FOKUS SEDANG BERJALAN          \n";
        cout << "==================================================\n\n";
        
        cout << "Habit         : " << sesi.habit << "\n";
        cout << "Sub-Habit     : " << sesi.sub_habit << "\n";
        cout << "Template      : " << sesi.template_timer << "\n";
        cout << "\nWaktu Tersisa : " << waktu_str << "\n";
        
        cout << "==================================================\n\n";
        
        if (timer.isPaused()) {
            cout << "STATUS: TERJEDA (Tekan [P] untuk lanjut)\n";
        } else {
            cout << "STATUS: BERJALAN\n";
        }
        cout << "Kontrol: [P] Pause/Resume | [S] Stop\n";
        cout << "==================================================\n";
        
     
        if (_kbhit()) {
            int key = _getch();
            if (key == 'P' || key == 'p') {
                timer.setPaused(!timer.isPaused());
            } else if (key == 'S' || key == 's') {
                timer.setStopped(true);
                system("cls");
                cout << "\nSesi dihentikan lebih awal!\n";
                this_thread::sleep_for(chrono::seconds(1));
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
            system("cls");
            cout << "\n";
            cout << "==================================================\n";
            cout << "         WAKTU HABIS! SESI SELESAI SEMPURNA!      \n";
            cout << "==================================================\n";
            this_thread::sleep_for(chrono::seconds(2));
            break;
        }
    }
    

    int waktu_aktual = timer.getDetikBerlalu();
    bool selesai_sempurna = timer.isComplete();
    
    HasilSesi hasil = buatHasilSesi(
        sesi.habit,
        sesi.sub_habit,
        sesi.template_timer,
        sesi.durasi_menit,
        waktu_aktual,
        selesai_sempurna
    );
    
 
    tampilkanHasilSesi(hasil);
    

    menuSetelahSesi(hasil);
}

void tampilkanStatistikFokus() {
    menuRiwayatSesi();
}

void menuFokusHari(HabitNode* root) {
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
        cout << "1. Mulai Sesi Fokus (Pilih Habit & Sub-Habit)\n";
        cout << "2. Lihat Statistik Fokus Hari\n";
        cout << "0. Kembali ke Menu Utama\n";
        cout << "\n==================================================\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;
        cin.ignore();
        
        switch(pilihan) {
            case 1:
                fokusHariSessionBaru(root);
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
