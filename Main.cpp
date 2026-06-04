#include <iostream>
#include <string>
#include "apps/utils/data_structure.cpp"
#include "apps/utils/validation.cpp"
#include "apps/feature/habbits.cpp"
#include "apps/data/data_manager.cpp"
#include "apps/feature/activity_timer.cpp"
#include "apps/feature/Create_Habbits.cpp"
#include "apps/feature/Delete_Habbits.cpp"
#include "apps/feature/activity_delete.cpp"
#include "apps/view/dashboard.cpp"
#include "apps/auth/login.cpp"
#include "apps/auth/register.cpp"
#include "apps/view/splash.cpp"
int main() {
    tampilkanSplash();
    tampilkanOnboarding();
   bool berjalan = true;
    int pilihan;
  while (berjalan) {
        system("cls"); // Bersihkan layar terminal tiap kembali ke menu utama
        cout << "==================================================" << endl;
        cout << "                APLIKASI MULAIHARI                " << endl;
        cout << "              Langkah Awal Disiplin           " << endl;
        cout << "==================================================" << endl;
        cout << "1. Masuk Akun (Login)" << endl;
        cout << "2. Buat Akun Baru (Register)" << endl;
        cout << "3. Keluar Aplikasi" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "Pilih Menu (1-3): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                prosesLogin();
                break;
            case 2:
                Register();
                break;
            case 3:
                berjalan = false;
                cout << "\nTerima kasih! Sampai jumpa besok untuk MulaiHari dengan produktif.\n" << endl;
                break;
            default:
                cout << "\n[Sistem] Pilihan tidak valid! Silakan coba lagi." << endl;
                system("pause");
        }
    }
}