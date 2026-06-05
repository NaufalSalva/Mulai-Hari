#ifndef ACTIVITY_READ_CPP
#define ACTIVITY_READ_CPP
#include <iostream>

using namespace std;


bool isStackEmpty(const AktivitasStack& stack) {
    return stack.top == nullptr;
}


void tampilkanRiwayatAktivitas(const AktivitasStack& stack) {
    system("cls"); 
    
    cout << "=========================================================\n";
    cout << "             RIWAYAT AKTIVITAS HARI INI (LIFO)           \n";
    cout << "       (Catatan paling baru selalu berada di teratas)    \n";
    cout << "=========================================================\n";

    if (isStackEmpty(stack)) {
        cout << "\n   [!] Belum ada aktivitas yang dicatat.\n";
        cout << "       Silahkan tambah aktivitas di menu utama.\n\n";
        cout << "=========================================================\n";
        return;
    }

    StackNode* current = stack.top;
    int index = 1;

    // Traversal dari top ke bottom stack
    while (current != nullptr) {
        LogAktivitasNode akt = current->data;
        
        cout << index << ". Hobi/Kategori : " << akt.hobi << "\n";
        cout << "   Durasi       : " << akt.durai << " Menit\n";
        cout << "   Mood Akhir   : " << akt.mood << "\n";
        cout << "   Detail Info  : " << akt.detail << "\n";
        cout << "---------------------------------------------------------\n";
        
        current = current->next; 
        index++;
    }
    
    cout << "=========================================================\n";
}

#endif