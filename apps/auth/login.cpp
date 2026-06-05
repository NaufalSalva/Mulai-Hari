bool prosesLogin() {
    system("cls");
    int id;
    string username;
    string password;
    User userDitemukan;
    string daftarHobi;
    int kesempatan = 3;
       cout << "==================================================" << endl;
        cout << "                    LOGIN USER                    " << endl;
        cout << "==================================================" << endl;

    while (kesempatan > 0) {
         cout << "Masukkan Username : ";
         cin >> username;

          cout << "Masukkan Password : ";
          cin >> password;
        if (!cariUserDiFile(username, password, userDitemukan, daftarHobi)) {
         cout << "\n[Sistem] Login gagal. Username atau password salah, atau data belum terdaftar." << endl;
         cout << "[Sistem] Kesempatan tersisa: " << kesempatan - 1 << endl << "\n";  
         kesempatan--;
        } else {
            break;
        }
    }

    if (kesempatan == 0) {
        cout << "\n[Sistem] Login gagal. Kesempatan habis." << endl;
        system("pause");
        return false;
    }

        cout << "\n[Sistem] Login berhasil." << endl;
        system("pause");
        HabitNode* root = bangunTreeDariHobi(userDitemukan.username, daftarHobi);

        tampilkanDashboard(
            userDitemukan.username,
            userDitemukan.email,
            daftarHobi
        );

        return true;
    }

   

   

   

