#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

const int LEBAR_TERMINAL = 80;

string padCenter(string teks) {
    int panjangTeks = teks.length();
    if (panjangTeks >= LEBAR_TERMINAL) return teks;
    
    int spasiKiri = (LEBAR_TERMINAL - panjangTeks) / 2;
    string padding = string(spasiKiri, ' ');
    return padding + teks;
}

void tampilkanSplash() {
    system("cls");
    cout << "\n\n\n"; 
    cout << padCenter("M U L A I  H A R I") << endl;
    cout << padCenter("Kuasai Waktumu, Bangun Kebiasaanmu") << endl;
    cout << "\n\n"; 
    cout << padCenter("Loading System...") << endl;

    int totalLoading = 22;
    string paddingKiri = string((LEBAR_TERMINAL - 25) / 2, ' ');

    for (int i = 0; i <= totalLoading; i++) {
    
        this_thread::sleep_for(chrono::milliseconds(70)); 
        
        int persen = (i * 100) / totalLoading;
        string barIsi = string(i, 'O');        
        string barKosong = string(totalLoading - i, '-'); 

   
        cout << "\r" << paddingKiri << "[" << barIsi << barKosong << "] " << persen << "%" << flush;
    }
    cout << "\n\n";
    this_thread::sleep_for(chrono::milliseconds(500));
}


void tampilkanOnboarding() {

    system("cls");
    cout << "\n\n";
    cout << padCenter("[ Halaman 1 dari 3 ]") << endl;
    cout << padCenter("=========================================") << endl;
    cout << padCenter("🌱  PILIH DAN STRUKTURKAN HOBI ANDA") << endl;
    cout << padCenter("=========================================") << endl;
    cout << padCenter("Ubah minat kasual Anda menjadi pohon") << endl;
    cout << padCenter("kebiasaan yang terarah dan produktif.") << endl;
    cout << "\n\n\n";
    cout << padCenter(">> Tekan ENTER untuk lanjut...");
    cin.get();


    system("cls");
    cout << "\n\n";
    cout << padCenter("[ Halaman 2 dari 3 ]") << endl;
    cout << padCenter("=========================================") << endl;
    cout << padCenter("🔥  SESI FOKUSHARI DENGAN TIMER") << endl;
    cout << padCenter("=========================================") << endl;
    cout << padCenter("Gunakan sistem activity template pomodoro") << endl;
    cout << padCenter("untuk melatih fokus bebas dari distraksi.") << endl;
    cout << "\n\n\n";
    cout << padCenter(">> Tekan ENTER untuk lanjut...");
    cin.get();


    system("cls");
    cout << "\n\n";
    cout << padCenter("[ Halaman 3 dari 3 ]") << endl;
    cout << padCenter("=========================================") << endl;
    cout << padCenter("🧠  SMART MOOD ANALYTICS REPORT") << endl;
    cout << padCenter("=========================================") << endl;
    cout << padCenter("Pantau kondisi mental Anda dan dapatkan") << endl;
    cout << padCenter("rekomendasi aktivitas pemulihan instan.") << endl;
    cout << "\n\n\n";
    cout << padCenter(">> Tekan ENTER untuk Masuk Aplikasi...");
    cin.get();
    system("cls");
}


void loadingTransisiTimer() {
    system("cls");
    cout << "\n\n"; 
    cout << padCenter("M U L I A H A R I   |   F O K U S H A R I") << endl;
    cout << padCenter("Menyiapkan Ruang Fokus dan Alarm Anda...") << endl;
    cout << "\n"; 
    cout << padCenter("Membuka Ruang Sesi...");

    int totalLoading = 22;
    string paddingKiri = string((LEBAR_TERMINAL - 25) / 2, ' ');

    for (int i = 0; i <= totalLoading; i++) {
        this_thread::sleep_for(chrono::milliseconds(50)); 
        int persen = (i * 100) / totalLoading;
        string barIsi = string(i, 'X');
        string barKosong = string(totalLoading - i, '-');
        cout << "\r" << paddingKiri << "[" << barIsi << barKosong << "] " << persen << "%" << flush;
    }
    cout << "\n\n"; 
    this_thread::sleep_for(chrono::milliseconds(300));
}