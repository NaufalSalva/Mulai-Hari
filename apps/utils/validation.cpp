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
