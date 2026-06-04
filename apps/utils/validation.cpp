#pragma once
#include <cctype>
#include <string>

using namespace std;

bool validasiUsername(const string& username) {
    if (username.size() < 3 || username.size() > 20) {
        return false;
    }

    for (char karakter : username) {
        if (!isalnum(static_cast<unsigned char>(karakter)) && karakter != '_') {
            return false;
        }
    }

    return true;
}

bool validasiEmail(const string& email) {
    size_t posisiAt = email.find('@');
    size_t posisiDot = email.rfind('.');

    if (email.empty() || email.find(' ') != string::npos) {
        return false;
    }

    if (posisiAt == string::npos || posisiDot == string::npos) {
        return false;
    }

    if (posisiAt == 0 || posisiAt == email.size() - 1) {
        return false;
    }

    if (posisiDot < posisiAt + 2 || posisiDot == email.size() - 1) {
        return false;
    }

    return true;
}

bool validasiPassword(const string& password) {
    if (password.size() < 6) {
        return false;
    }

    bool adaHuruf = false;
    bool adaAngka = false;

    for (char karakter : password) {
        if (isalpha(static_cast<unsigned char>(karakter))) {
            adaHuruf = true;
        }
        if (isdigit(static_cast<unsigned char>(karakter))) {
            adaAngka = true;
        }
    }

    return adaHuruf && adaAngka;
}

bool validasiPilihan(int pilihan, int minimal, int maksimal) {
    return pilihan >= minimal && pilihan <= maksimal;
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
