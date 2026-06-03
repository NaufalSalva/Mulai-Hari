#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

const string FILE_USER = "apps/data/user.txt";

// Ambil semua hobi dari tree lalu jadikan 1 string: "Hobi1,Hobi2,Hobi3"
string ambilHobiDariTree(HabitNode* root) {
    if (root == nullptr || root->child == nullptr) {
        return "-";
    }

    string hasil = "";
    HabitNode* node = root->child;

    while (node != nullptr) {
        if (!node->nama.empty()) {
            if (!hasil.empty()) {
                hasil += ",";
            }
            hasil += node->nama;
        }
        node = node->sibling;
    }

    if (hasil.empty()) {
        return "-";
    }

    return hasil;
}

// Simpan 1 user ke file dengan format:
// username|email|password|rootName|hobi1,hobi2
bool simpanUserKeFile(const User& userBaru, HabitNode* userTree) {
    ofstream file(FILE_USER, ios::app);
    if (!file.is_open()) {
        return false;
    }

    // Jika tree kosong, tetap simpan user tanpa hobi
    string rootName = userBaru.username;
    string daftarHobi = "-";

    if (userTree != nullptr) {
        rootName = userTree->nama;
        daftarHobi = ambilHobiDariTree(userTree);
    }

    file << userBaru.username << "|"
         << userBaru.email << "|"
         << userBaru.password << "|"
         << rootName << "|"
            << daftarHobi << '\n';

    return true;
}

bool usernameSudahTerdaftar(const string& username) {
    ifstream file(FILE_USER);
    if (!file.is_open()) {
        return false;
    }

    string baris;
    while (getline(file, baris)) {
        if (baris.empty()) {
            continue;
        }

        stringstream aliran(baris);
        string namaTersimpan;

        if (getline(aliran, namaTersimpan, '|') && namaTersimpan == username) {
            return true;
        }
    }

    return false;
}

bool cariUserDiFile(const string& username, const string& password, User& userDitemukan, string& daftarHobi) {
    ifstream file(FILE_USER);
    if (!file.is_open()) {
        return false;
    }

    string baris;
    while (getline(file, baris)) {
        if (baris.empty()) {
            continue;
        }

        // Pecah kolom berdasarkan '|'
        stringstream aliran(baris);
        string usernameTersimpan;
        string emailTersimpan;
        string passwordTersimpan;
        string rootNameTersimpan;
        string hobiTersimpan;

        // Kalau format baris tidak lengkap, lewati
        if (!getline(aliran, usernameTersimpan, '|')) {
            continue;
        }
        if (!getline(aliran, emailTersimpan, '|')) {
            continue;
        }
        if (!getline(aliran, passwordTersimpan, '|')) {
            continue;
        }
        if (!getline(aliran, rootNameTersimpan, '|')) {
            continue;
        }

        // Data lama mungkin belum punya kolom hobi
        if (!getline(aliran, hobiTersimpan, '|')) {
            hobiTersimpan = "-";
        }

        if (usernameTersimpan == username && passwordTersimpan == password) {
            userDitemukan.username = usernameTersimpan;
            userDitemukan.email = emailTersimpan;
            userDitemukan.password = passwordTersimpan;
            daftarHobi = hobiTersimpan;
            return true;
        }
    }

    return false;
}

// Tampilkan hobi ke layar
void tampilkanDaftarHobi(const string& daftarHobi) {
    if (daftarHobi.empty() || daftarHobi == "-") {
        cout << "- Belum ada hobi tersimpan" << endl;
        return;
    }

    string item;
    stringstream aliran(daftarHobi);

    while (getline(aliran, item, ',')) {
        if (!item.empty()) {
            cout << "- " << item << endl;
        }
    }
}
