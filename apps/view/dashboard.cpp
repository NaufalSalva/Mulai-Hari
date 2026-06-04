#include <iostream>
#include <string>
#include "../feature/activity_timer.cpp"
using namespace std;

void tampilkanDashboard(string username, string email, string daftarHobi)
{
    int pilihan;
    bool berjalan = true;

    while (berjalan)
    {
        system("cls");

        cout << "======================================" << endl;
        cout << "          DASHBOARD MULAIHARI         " << endl;
        cout << "======================================" << endl;

        cout << "Halo, " << username << endl;
        cout << "Email : " << email << endl;

        cout << "--------------------------------------" << endl;
        cout << "HOBI KAMU" << endl;
        cout << "--------------------------------------" << endl;
        cout << daftarHobi << endl;
        cout << "--------------------------------------" << endl;
        cout << "RINGKASAN HARI INI" << endl;
        cout << "--------------------------------------" << endl;
        cout << "Total Aktivitas : 0" << endl;
        cout << "Kondisi Mental  : Belum ada" << endl;

        cout << "--------------------------------------" << endl;
        cout << "MENU DASHBOARD" << endl;
        cout << "--------------------------------------" << endl;
        cout << "1. Lihat Hobi" << endl;
        cout << "2. Catat Aktivitas" << endl;
        cout << "3. Mulai Fokus Hari" << endl;
        cout << "0. Logout" << endl;
        cout << "======================================" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan)
        {
            case 1:
                system("cls");
                cout << "======================================" << endl;
                cout << "              DAFTAR HOBI             " << endl;
                cout << "======================================" << endl;
                cout << daftarHobi << endl;
                system("pause");
                break;

            case 2:
                system("cls");
                cout << "======================================" << endl;
                cout << "           CATAT AKTIVITAS            " << endl;
                cout << "======================================" << endl;
                cout << "Fitur catat aktivitas belum dibuat." << endl;
                system("pause");
                break;

            case 3:
                menuFokusHari();
                break;

            case 0:
                berjalan = false;
                cout << "\n[Sistem] Logout berhasil." << endl;
                system("pause");
                break;

            default:
                cout << "\n[Sistem] Pilihan tidak valid! Silakan coba lagi." << endl;
                system("pause");
        }
    }
}