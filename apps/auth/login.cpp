bool prosesLogin() {
    system("cls");

    string username;
    string password;
    User userDitemukan;
    string daftarHobi;

    cout << "==================================================" << endl;
    cout << "                    LOGIN USER                    " << endl;
    cout << "==================================================" << endl;

    cout << "Masukkan Username : ";
    cin >> username;

    cout << "Masukkan Password : ";
    cin >> password;

    if (!cariUserDiFile(username, password, userDitemukan, daftarHobi)) {
        cout << "\n[Sistem] Login gagal. Username atau password salah, atau data belum terdaftar." << endl;
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