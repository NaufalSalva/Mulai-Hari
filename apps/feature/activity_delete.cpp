#include <iostream>
#include <string>
#include "../data/data_manager.cpp"
#include "../utils/data_structure.cpp"

using namespace std;

void hapusAktivitasTerakhir (AktivitasStack& stack) {
    if (stack.top == nullptr) {
        cout << "Tidak ada aktivitas yang dapat dihapus." << endl;
        return;
    }

    cout << "Aktivitas terakhir yang akan dihapus:" << endl;
    cout << stack.top->data.hobi << endl;

    popAktivitas(stack);

    cout << "Aktivitas terakhir berhasil dihapus." << endl;
}