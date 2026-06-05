#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void inputAktivitas();

TaskList userTasks = {nullptr};

int hitungTotalTugasDinamis(const TaskList& list) {
    int total = 0;
    TaskNode* current = list.head; 
    while (current != nullptr) {
        total++;
        current = current->next;
    }
    return total;
}

int hitungTugasSelesaiDinamis(const TaskList& list) {
    int selesai = 0;
    TaskNode* current = list.head;
    while (current != nullptr) {
        if (current->isSelesai) {
            selesai++;
        }
        current = current->next;
    }
    return selesai;
}


int hitungSesiFokusDinamis(const AktivitasStack& stack) {
    int totalFokus = 0;
    StackNode* temp = stack.top;
    
    while (temp != nullptr) {
        if (temp->data.hobi.find("[TIMERS]") != string::npos) {
            totalFokus++;
        }
        temp = temp->next;
    }
    return totalFokus;
}

int hitungTotalLogAktivitas(const AktivitasStack& stack) {
    int total = 0;
    StackNode* temp = stack.top;
    while (temp != nullptr) {
        total++;
        temp = temp->next;
    }
    return total;
}


string dapatkanMoodDashboard(const LogAktivitasNode& data) {

    if (data.hobi.find("[TIMERS]") != string::npos) {
        stringstream ss(data.mood);
        string tanggal, jamMulai, jamSelesai, durasiRencana, statusPenyelesaian;
        
        getline(ss, tanggal, '|');
        getline(ss, jamMulai, '|');
        getline(ss, jamSelesai, '|');
        getline(ss, durasiRencana, '|');
        getline(ss, statusPenyelesaian, '|');
        
        return "Sesi " + statusPenyelesaian;
    }

    return data.mood;
}

void tampilkanDashboard(string username, string email, string daftarHobi)
{
    int pilihan;
    bool berjalan = true;
    HabitNode* root = bangunTreeDariHobi(username, daftarHobi);

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
        cout << "   Total Log Aktivitas : " << hitungTotalLogAktivitas(historyStack) << endl;
        cout << "   Total Sesi Fokus    : " << hitungSesiFokusDinamis(historyStack) << " Sesi Selesai" << endl;
        
        cout << "   Aktivitas Terakhir  : " << (historyStack.top ? historyStack.top->data.hobi + " - " + historyStack.top->data.detail : "Belum ada") << endl;
        
     
        cout << "   Mood / Info Terakhir: " << (historyStack.top ? dapatkanMoodDashboard(historyStack.top->data) : "Belum ada") << endl;
        
        cout << "   Total Tugas         : " << hitungTotalTugasDinamis(userTasks) << " | Tugas Selesai: " << hitungTugasSelesaiDinamis(userTasks) << endl;
        cout << "--------------------------------------------------" << endl;
        
        cout << "MENU DASHBOARD" << endl;
        cout << "--------------------------------------" << endl;
        cout << "1. Lihat Hobi" << endl;
        cout << "2. Catat Aktivitas" << endl;
        cout << "3. Mulai Fokus Hari" << endl;
        cout << "4. Lihat Struktur Habit Tree\n";
        cout << "5. Tambah Sub Habit\n";
        cout << "6. Hapus Sub Habit\n";
        cout << "7. Hapus Aktivitas Terakhir\n";
        cout << "8. Riwayat Aktivitas\n";
        cout << "9. Manajemen Tugas\n";
        cout << "10. Rekomendasi \n";
        cout << "0. Logout" << endl;
        cout << "======================================" << endl;
     
        pilihan = validasiInputAngka(0, 10, "Pilih Menu (0-10): ");

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
                inputAktivitas(root);
                system("pause");
                break;

            case 3:
                menuFokusHari(root, historyStack);
                break;

            case 4: cetakTreeLCRS(root); system("pause"); break;
            case 5: tambahSubHabitUser(root); system("pause"); break;
            case 6: hapusSubHabit(root); system("pause"); break;
            case 7: hapusAktivitasTerakhir(historyStack); system("pause"); break;
            case 8: tampilkanRiwayatAktivitas(historyStack); system("pause"); break;
            case 9: menuTaskManager(userTasks, username, root); system("pause"); break;
            case 10: menuRekomendasiHobi(root); system("pause"); break;
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