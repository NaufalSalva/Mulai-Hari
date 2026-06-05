int generateUserIdBaru() {
    ifstream file("apps/data/user.txt");
    if (!file.is_open()) {
        return 1; 
    }

    string baris;
    int idTerbesar = 0;

 
    while (getline(file, baris)) {
        if (baris.empty()) continue;
        
        stringstream ss(baris);
        string idStr;
        

        if (getline(ss, idStr, ',')) {
        
            stringstream konverter(idStr);
            int idSekarang = 0;
            
        
            if (konverter >> idSekarang) {
                if (idSekarang > idTerbesar) {
                    idTerbesar = idSekarang;
                }
            }
        }
    }
    file.close();
    return idTerbesar + 1; 
}

void hubungkanHobiTree(HabitNode* root, string namaHobi) {
    HabitNode* newNode = new HabitNode;
    newNode->nama = namaHobi;
    newNode->child = nullptr;
    newNode->sibling = nullptr;

    if (root->child == nullptr){
        root->child = newNode;
    } else {
        HabitNode* temp = root->child;
        while (temp->sibling != nullptr) {
            temp = temp->sibling;
        }
        temp->sibling = newNode;
    }
}

bool hobiSudahDipilih(HabitNode* root, const string& namaHobi) {
    if (root == nullptr) {
        return false;
    }

    HabitNode* node = root->child;
    while (node != nullptr) {
        if (node->nama == namaHobi) {
            return true;
        }
        node = node->sibling;
    }

    return false;
}

void tampilkanHobiDipilih(HabitNode* root) {
    cout << "Hobi yang sudah dipilih:" << endl;

    if (root == nullptr || root->child == nullptr) {
        cout << "- Belum ada hobi dipilih" << endl;
        return;
    }

    HabitNode* node = root->child;
    while (node != nullptr) {
        cout << "- " << node->nama << endl;
        node = node->sibling;
    }
}

void Register(){
    system("cls");
    User userBaru;
    userBaru.id = generateUserIdBaru();
    cout << "==================================================" << endl;
    cout << "               REGISTRASI USER BARU               " << endl;
    cout << "==================================================" << endl;

    do {
        cout << "Masukkan Username : ";
        cin >> userBaru.username;

        if (!validasiUsername(userBaru.username)) {
            cout << "Username tidak valid. Gunakan 3-20 karakter, huruf/angka/underscore." << endl;
            continue;
        }

        if (usernameSudahTerdaftar(userBaru.username)) {
            cout << "Username sudah terdaftar. Gunakan username lain." << endl;
            userBaru.username.clear();
            continue;
        }

        break;
    } while (true);

    do {
        cout << "Masukkan Email    : ";
        cin >> userBaru.email;

        if (!validasiEmail(userBaru.email)) {
            cout << "Format email tidak valid." << endl;
            continue;
        }

        break;
    } while (true);

    do {
        cout << "Masukkan Password : ";
        cin >> userBaru.password;

        if (!validasiPassword(userBaru.password)) {
            cout << "Password minimal 6 karakter dan harus berisi huruf serta angka." << endl;
            continue;
        }

        break;
    } while (true);

    HabitNode* userTree = new HabitNode;
    userTree->nama = userBaru.username;
    userTree->child = nullptr;
    userTree->sibling = nullptr;

      cout << "\n==================================================" << endl;
    cout << "PILIH HOBI REKOMENDASI (Maksimal 5, masukkan nomor, ketik 0 jika selesai)" << endl;
      cout << "====================================================" << endl;
    cout << "1. Olahraga" << endl;
    cout << "2. Membaca" << endl;
    cout << "3. Memasak" << endl;
    cout << "4. Traveling" << endl;
    cout << "5. Coding" << endl;
    cout << "6. Musik" << endl;
    cout << "7. Menulis" << endl;
    cout << "8. Gaming" << endl;
    cout << "9. Belajar" << endl;
    cout << "10. Menonton" << endl;

    cout << "0. Selesai" << endl;
    cout << "====================================================" << endl;
    
      int pilihanHobi;
      int jumlahHobi = 0;

      while(jumlahHobi < 5){
                cout << "Pilihan Hobi Ke-" << (jumlahHobi + 1) << " (nomor): ";
                if (!(cin >> pilihanHobi)) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Input harus angka. Silakan masukkan nomor hobi dari daftar di atas." << endl;
                        continue;
                }

                    if (!validasiPilihan(pilihanHobi, 0, 10)) {
                        cout << "Pilihan tidak valid! Silakan pilih nomor antara 0-10." << endl;
                        continue;
                    }

        if (pilihanHobi == 0) {
            break; 
        }
        switch (pilihanHobi){
            case 1:
                    if (hobiSudahDipilih(userTree, "Olahraga")) {
                        cout << "Hobi sudah dipilih sebelumnya." << endl;
                        continue;
                    }
                hubungkanHobiTree(userTree, "Olahraga");
                break;
            case 2:
                    if (hobiSudahDipilih(userTree, "Membaca")) {
                        cout << "Hobi sudah dipilih sebelumnya." << endl;
                        continue;
                    }
                hubungkanHobiTree(userTree, "Membaca");
                break;
            case 3:
                    if (hobiSudahDipilih(userTree, "Memasak")) {
                        cout << "Hobi sudah dipilih sebelumnya." << endl;
                        continue;
                    }
                hubungkanHobiTree(userTree, "Memasak");
                break;
            case 4:
                    if (hobiSudahDipilih(userTree, "Traveling")) {
                        cout << "Hobi sudah dipilih sebelumnya." << endl;
                        continue;
                    }
                hubungkanHobiTree(userTree, "Traveling");
                break;
            case 5:
                    if (hobiSudahDipilih(userTree, "Coding")) {
                        cout << "Hobi sudah dipilih sebelumnya." << endl;
                        continue;
                    }
                hubungkanHobiTree(userTree, "Coding");
                break;
            case 6:
                    if (hobiSudahDipilih(userTree, "Musik")) {
                        cout << "Hobi sudah dipilih sebelumnya." << endl;
                        continue;
                    }
                hubungkanHobiTree(userTree, "Musik");
                break;
            case 7:
                    if (hobiSudahDipilih(userTree, "Menulis")) {
                        cout << "Hobi sudah dipilih sebelumnya." << endl;
                        continue;
                    }
                hubungkanHobiTree(userTree, "Menulis");
                break;
            case 8:
                    if (hobiSudahDipilih(userTree, "Gaming")) {
                        cout << "Hobi sudah dipilih sebelumnya." << endl;
                        continue;
                    }
                hubungkanHobiTree(userTree, "Gaming");
                break;
            case 9:
                    if (hobiSudahDipilih(userTree, "Belajar")) {
                        cout << "Hobi sudah dipilih sebelumnya." << endl;
                        continue;
                    }
                hubungkanHobiTree(userTree, "Belajar");
                break;
            case 10:
                    if (hobiSudahDipilih(userTree, "Menonton")) {
                        cout << "Hobi sudah dipilih sebelumnya." << endl;
                        continue;
                    }
                hubungkanHobiTree(userTree, "Menonton");
                break;
            default:
                cout << "Pilihan tidak valid! Silakan pilih nomor antara 1-15 atau 0 untuk selesai." << endl;
                continue;
        }
        jumlahHobi++;

                cout << "\n";
                tampilkanHobiDipilih(userTree);
                cout << "\n";

      }



    if (!simpanUserKeFile(userBaru, userTree)) {
        cout << "\n[Sistem] Gagal menyimpan data user ke file." << endl;
        system("pause");
        return;
    }

    cout << "\n[Sistem] Akun " << userBaru.username << " berhasil didaftarkan!" << endl;
    cout << "[Sistem] Data tersimpan di apps" << endl;
    cout << "[Sistem] Root name pohon user menggunakan username: " << userTree->nama << endl;
    cout << "[Sistem] Pohon Habit rekomendasi telah dibuat otomatis." << endl;
    system("pause");

}