#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <limits>

using namespace std;

// Fungsi untuk clear input buffer
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Input string dengan validasi basic - tidak boleh kosong
string inputString(const string& prompt, bool allowSpaces = false) {
    string input;
    bool valid = false;
    
    while (!valid) {
        cout << prompt;
        
        if (allowSpaces) {
            getline(cin, input);
        } else {
            cin >> input;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        // Cek jika input kosong
        if (input.empty()) {
            cout << "Input tidak boleh kosong. Coba lagi.\n";
            clearInputBuffer();
            continue;
        }
        
        valid = true;
    }
    
    return input;
}

// Input integer dengan validasi
int inputInteger(const string& prompt, int minVal = INT_MIN, int maxVal = INT_MAX) {
    int input;
    bool valid = false;
    
    while (!valid) {
        cout << prompt;
        
        if (!(cin >> input)) {
            cout << "Input harus berupa angka. Coba lagi.\n";
            clearInputBuffer();
            continue;
        }
        
        if (input < minVal || input > maxVal) {
            cout << "Angka harus antara " << minVal << " dan " << maxVal << ". Coba lagi.\n";
            clearInputBuffer();
            continue;
        }
        
        clearInputBuffer();
        valid = true;
    }
    
    return input;
}

// Input char dengan validasi
char inputChar(const string& prompt) {
    char input;
    bool valid = false;
    
    while (!valid) {
        cout << prompt;
        cin >> input;
        clearInputBuffer();
        
        valid = true;
    }
    
    return input;
}

// Input angka (0-9) untuk menu
int inputMenu(const string& prompt, int minOption, int maxOption) {
    return inputInteger(prompt, minOption, maxOption);
}

// Input email dengan validasi @ dan format
string inputEmail(const string& prompt) {
    string email;
    bool valid = false;
    
    while (!valid) {
        cout << prompt;
        cin >> email;
        clearInputBuffer();
        
        if (email.empty()) {
            cout << "Email tidak boleh kosong. Coba lagi.\n";
            continue;
        }
        
        // Check @ exists
        if (email.find('@') == string::npos) {
            cout << "Email harus mengandung @. Coba lagi.\n";
            continue;
        }
        
        valid = true;
    }
    
    return email;
}

// Input password (hide character optional)
string inputPassword(const string& prompt) {
    string password;
    bool valid = false;
    
    while (!valid) {
        cout << prompt;
        cin >> password;
        clearInputBuffer();
        
        if (password.empty()) {
            cout << "Password tidak boleh kosong. Coba lagi.\n";
            continue;
        }
        
        valid = true;
    }
    
    return password;
}
