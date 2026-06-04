#include <iostream>
#include <string>

using namespace std;

void tambahSubHabitUser(HabitNode* root)
{
    if(root == nullptr)
        return;

    string namaHobi;
    string namaSubHabit;

    cout << "\n===== TAMBAH SUB-HABIT =====\n";

    cout << "Pilih Hobi Utama : ";
    cin.ignore();
    getline(cin, namaHobi);

    HabitNode* parent = cariHobi(root, namaHobi);

    if(parent == nullptr)
    {
        cout << "Hobi tidak ditemukan!\n";
        return;
    }

    cout << "Nama Sub-Habit Baru : ";
    getline(cin, namaSubHabit);

    tambahSubHabit(parent, namaSubHabit);

    cout << "Sub-Habit berhasil ditambahkan!\n";
}