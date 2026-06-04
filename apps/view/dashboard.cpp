#include <iostream>
#include <string>
using namespace std;

void tampilkanDashboard(string username, string email, string daftarHobi)
{
    int pilihan;
    bool berjalan = true;

    while (berjalan)
    {
        system("cls");

        cout << "==================================================" << endl;
        cout << "                  MULAIHARI                       " << endl;
        cout << "             Dashboard Produktivitas              " << endl;
        cout << "==================================================" << endl;

        cout << "Halo, " << username << "!" << endl;
        cout << "Selamat datang kembali di MulaiHari." << endl;

        cout << "--------------------------------------------------" << endl;
        cout << "HOBI KAMU" << endl;
        cout << "--------------------------------------------------" << endl;
        tampilkanDaftarHobi(daftarHobi);

        cout << "--------------------------------------------------" << endl;
        cout << "RINGKASAN HARI INI" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "   Total Aktivitas : 0" << endl;
        cout << "   Kondisi Mental  : Belum ada" << endl;

        cout << "--------------------------------------------------" << endl;
        cout << "MENU DASHBOARD" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "   1. Lihat Hobi" << endl;
        cout << "   2. Catat Aktivitas" << endl;
        cout << "   3. Logout" << endl;
        cout << "==================================================" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan)
        {
            case 1:
                system("cls");
                cout << "==================================================" << endl;
                cout << "                   DAFTAR HOBI                    " << endl;
                cout << "==================================================" << endl;
                tampilkanDaftarHobi(daftarHobi);
                system("pause");
                break;

            case 2:
                system("cls");
                cout << "==================================================" << endl;
                cout << "                CATAT AKTIVITAS                   " << endl;
                cout << "==================================================" << endl;
                cout << "Fitur catat aktivitas belum dibuat." << endl;
                system("pause");
                break;

            case 3:
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