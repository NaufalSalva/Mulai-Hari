#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TimerTemplate {
    string nama;
    int durasi_menit;
    string deskripsi;
};


struct SesiFokusAktif {
    string habit;
    string sub_habit;
    string template_timer;
    int durasi_menit;
    int waktu_berlalu; 
    bool sedang_berjalan;
};


void tampilkanDaftarHabits(HabitNode* root) {
    if (root == nullptr || root->child == nullptr) {
        cout << "Tidak ada habits yang tersimpan\n";
        return;
    }

    cout << "\n================== PILIH HABIT ==================\n";
    int nomor = 1;
    HabitNode* temp = root->child;
    
    while (temp != nullptr) {
        cout << nomor << ". " << temp->nama << "\n";
        temp = temp->sibling;
        nomor++;
    }
    cout << "================================================\n";
}


void tampilkanSubHabits(HabitNode* habitDipilih) {
    if (habitDipilih == nullptr || habitDipilih->child == nullptr) {
        cout << "Tidak ada sub-habit untuk habit ini\n";
        return;
    }

    cout << "\n============= PILIH SUB-HABIT =============\n";
    int nomor = 1;
    HabitNode* temp = habitDipilih->child;
    
    while (temp != nullptr) {
        cout << nomor << ". " << temp->nama << "\n";
        temp = temp->sibling;
        nomor++;
    }
    cout << "==========================================\n";
}


void tampilkanTemplateTimer() {
    cout << "\n========== PILIH TEMPLATE TIMER ==========\n";
    cout << "1. Pomodoro Pendek   (15 Menit)\n";
    cout << "2. Pomodoro Standar  (25 Menit)\n";
    cout << "3. Deep Work         (45 Menit)\n";
    cout << "4. Focus Marathon    (90 Menit)\n";
    cout << "5. Custom            (Masukkan durasi sendiri)\n";
    cout << "=========================================\n";
}


HabitNode* getHabitByNomor(HabitNode* root, int nomor) {
    if (root == nullptr) return nullptr;
    
    int counter = 1;
    HabitNode* temp = root->child;
    
    while (temp != nullptr) {
        if (counter == nomor) {
            return temp;
        }
        temp = temp->sibling;
        counter++;
    }
    return nullptr;
}

HabitNode* getSubHabitByNomor(HabitNode* parentHabit, int nomor) {
    if (parentHabit == nullptr) return nullptr;
    
    int counter = 1;
    HabitNode* temp = parentHabit->child;
    
    while (temp != nullptr) {
        if (counter == nomor) {
            return temp;
        }
        temp = temp->sibling;
        counter++;
    }
    return nullptr;
}

bool setupSesiFokus(HabitNode* root, SesiFokusAktif& sesi) {
    int pilihanHabit, pilihanSubHabit, pilihanTimer;
    
  
    system("cls");
    tampilkanDaftarHabits(root);
    cout << "\nMasukkan nomor habit yang dipilih: ";
    cin >> pilihanHabit;
    
    HabitNode* habitTerpilih = getHabitByNomor(root, pilihanHabit);
    if (habitTerpilih == nullptr) {
        cout << "Habit tidak ditemukan!\n";
        return false;
    }
    
    sesi.habit = habitTerpilih->nama;
    
    system("cls");
    tampilkanSubHabits(habitTerpilih);
    cout << "Masukkan nomor sub-habit yang dipilih: ";
    cin >> pilihanSubHabit;
    
    HabitNode* subHabitTerpilih = getSubHabitByNomor(habitTerpilih, pilihanSubHabit);
    if (subHabitTerpilih == nullptr) {
        cout << "Sub-habit tidak ditemukan!\n";
        return false;
    }
    
    sesi.sub_habit = subHabitTerpilih->nama;
    
    // Tampilkan template timer
    system("cls");
    tampilkanTemplateTimer();
    cout << "Masukkan pilihan template timer (1-5): ";
    cin >> pilihanTimer;
    
    switch (pilihanTimer) {
        case 1:
            sesi.durasi_menit = 15;
            sesi.template_timer = "Pomodoro Pendek (15 Menit)";
            break;
        case 2:
            sesi.durasi_menit = 25;
            sesi.template_timer = "Pomodoro Standar (25 Menit)";
            break;
        case 3:
            sesi.durasi_menit = 45;
            sesi.template_timer = "Deep Work (45 Menit)";
            break;
        case 4:
            sesi.durasi_menit = 90;
            sesi.template_timer = "Focus Marathon (90 Menit)";
            break;
        case 5: {
            cout << "Masukkan durasi custom (dalam menit): ";
            cin >> sesi.durasi_menit;
            sesi.template_timer = "Custom (" + to_string(sesi.durasi_menit) + " Menit)";
            break;
        }
        default:
            cout << "Pilihan tidak valid!\n";
            return false;
    }
    
    sesi.waktu_berlalu = 0;
    sesi.sedang_berjalan = true;
    
    return true;
}

// Fungsi untuk menampilkan ringkasan sesi sebelum dimulai
void tampilkanRingkasanSesi(const SesiFokusAktif& sesi) {
    cout << "\n\n";
    cout << "==================================================\n";
    cout << "         RINGKASAN SESI FOKUS SIAP DIMULAI         \n";
    cout << "==================================================\n";
    cout << "Habit         : " << sesi.habit << "\n";
    cout << "Sub-Habit     : " << sesi.sub_habit << "\n";
    cout << "Template Timer: " << sesi.template_timer << "\n";
    cout << "Durasi        : " << sesi.durasi_menit << " Menit\n";
    cout << "==================================================\n";
    cout << "\nTekan ENTER untuk memulai sesi...\n";
    cin.ignore();
    cin.get();
}
