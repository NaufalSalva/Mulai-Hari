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

// id|username|email|password|rootName|hobi1,hobi2
bool simpanUserKeFile(const User& userBaru, HabitNode* userTree) {
    ofstream file(FILE_USER, ios::app);
    if (!file.is_open()) {
        return false;
    }


    string rootName = userBaru.username;
    string daftarHobi = "-";

    if (userTree != nullptr) {
        rootName = userTree->nama;
        daftarHobi = ambilHobiDariTree(userTree);
    }

    file << userBaru.id << "|"
         << userBaru.username << "|"
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
        string idTersimpan, namaTersimpan;

       if (getline(aliran, idTersimpan, '|') && getline(aliran, namaTersimpan, '|')) {
            if (namaTersimpan == username) {
                file.close();
                return true;
            }
        }
    }
    file.close();
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
        stringstream aliran(baris);
        string idTersimpan;
        string usernameTersimpan;
        string emailTersimpan;
        string passwordTersimpan;
        string rootNameTersimpan;
        string hobiTersimpan;


  
       if (!getline(aliran, idTersimpan, '|')) continue;
        if (!getline(aliran, usernameTersimpan, '|')) continue;
        if (!getline(aliran, emailTersimpan, '|')) continue;
        if (!getline(aliran, passwordTersimpan, '|')) continue;
        if (!getline(aliran, rootNameTersimpan, '|')) continue;

   
        if (!getline(aliran, hobiTersimpan, '|')) {
            hobiTersimpan = "-";
        }

        if (usernameTersimpan == username && passwordTersimpan == password) {
            stringstream konverter(idTersimpan);
            konverter >> userDitemukan.id;
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



AktivitasStack historyStack;

void inisialisasiStack() {
    historyStack.top = nullptr;
}

void pushAktivitas(AktivitasStack& stack, const LogAktivitasNode& aktivitas)
{
    StackNode* nodeBaru = new StackNode;

    nodeBaru->data = aktivitas;
    nodeBaru->next = stack.top;

    stack.top = nodeBaru;
}

bool popAktivitas(AktivitasStack& stack) {
    if (stack.top == nullptr) {
        return false;
    }

    StackNode* nodeHapus = stack.top;
    stack.top = stack.top->next;

    delete nodeHapus;

    return true;
}