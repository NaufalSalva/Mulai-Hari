#include <iostream>
#include <string>
#include "../utils/data_structure.cpp"
#include "../feature/habbits.cpp"
using namespace std;

void hapusSubHabit(HabitNode* root)
{
    if(root == nullptr)
        return;

    string namaHobi;
    string namaSubHabit;

    cout << "\n===== HAPUS SUB-HABIT =====\n";

    cout << "Pilih Hobi Utama : ";
    cin.ignore();
    getline(cin, namaHobi);

    HabitNode* parent = cariHobi(root, namaHobi);

    if(parent == nullptr)
    {
        cout << "Hobi tidak ditemukan!\n";
        return;
    }

    cout << "Nama Sub-Habit Yang Dihapus : ";
    getline(cin, namaSubHabit);

    HabitNode* curr = parent->child;
    HabitNode* prev = nullptr;

    while(curr != nullptr)
    {
        if(curr->nama == namaSubHabit)
        {
            if(prev == nullptr)
            {
                parent->child = curr->sibling;
            }
            else
            {
                prev->sibling = curr->sibling;
            }

            delete curr;

            cout << "Sub-Habit berhasil dihapus!\n";
            return;
        }

        prev = curr;
        curr = curr->sibling;
    }

    cout << "Sub-Habit tidak ditemukan!\n";
}