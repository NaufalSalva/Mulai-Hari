#include <iostream>
#pragma once
#include <string>


using namespace std;

bool popAktivitas(AktivitasStack& stack);

void hapusAktivitasTerakhir(AktivitasStack& stack)
{
    if (stack.top == nullptr)
    {
        cout << "\nTidak ada aktivitas yang dapat dihapus.\n";
        return;
    }

    cout << "\n=====================================\n";
    cout << "     KONFIRMASI HAPUS AKTIVITAS\n";
    cout << "=====================================\n";

    cout << "Hobi   : " << stack.top->data.hobi << endl;
    cout << "Detail : " << stack.top->data.detail << endl;
    cout << "Mood   : " << stack.top->data.mood << endl;

    char konfirmasi;

    cout << "\nYakin ingin menghapus? (Y/N): ";
    cin >> konfirmasi;

    if (konfirmasi == 'Y' || konfirmasi == 'y')
    {
        popAktivitas(stack);

        cout << "\nAktivitas berhasil dihapus.\n";
    }
    else
    {
        cout << "\nPenghapusan dibatalkan.\n";
    }
}