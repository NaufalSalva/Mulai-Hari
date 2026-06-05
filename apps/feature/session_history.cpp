#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

void menuRiwayatSesi(const AktivitasStack& stack) {
    system("cls");
    cout << "========================================================================================\n";
    cout << "                              RIWAYAT AKTIVITAS FOKUS ANDA                              \n";
    cout << "========================================================================================\n";

    if (stack.top == nullptr) {
        cout << "\n                     [Sistem] Riwayat sesi fokus kosong.\n";
        cout << "========================================================================================\n";
        system("pause"); 
        return;
    }
   
    StackNode* temp = stack.top;
    int nomor = 1;
    bool adaDataTimer = false; 


    cout << left << setw(5) << "No" 
         << left << setw(15) << "| Tanggal"
         << left << setw(23) << "| Waktu Aktivitas (WIB)"
         << left << setw(15) << "| Habit" 
         << left << setw(15) << "| Sub-Habit" 
         << "| Status\n";
    cout << "----------------------------------------------------------------------------------------\n";

    while (temp != nullptr) {
        if (temp->data.hobi.find("[TIMERS]") != string::npos) {
            adaDataTimer = true; 
            
            string habitBersih = temp->data.hobi.substr(9); 

          
            stringstream ss(temp->data.mood);
            string tanggal, jamMulai, jamSelesai, durasiRencana, statusPenyelesaian;
            
            getline(ss, tanggal, '|');
            getline(ss, jamMulai, '|');
            getline(ss, jamSelesai, '|'); 
            getline(ss, durasiRencana, '|');
            getline(ss, statusPenyelesaian, '|');

         
            int menitRiil = temp->data.durasi / 60;
            int detikRiil = temp->data.durasi % 60;
            
            string stringDurasiJam = jamMulai + " - " + jamSelesai + " (" + to_string(menitRiil) + "m " + to_string(detikRiil) + "s)";

            cout << left << setw(5) << nomor 
                 << "| " << left << setw(13) << tanggal
                 << "| " << left << setw(21) << stringDurasiJam
                 << "| " << left << setw(13) << habitBersih 
                 << "| " << left << setw(13) << temp->data.detail 
                 << "| " << statusPenyelesaian << "\n";
            
            nomor++;
        }
        temp = temp->next; 
    }

    if (!adaDataTimer) {
        system("cls");
        cout << "========================================================================================\n";
        cout << "                              RIWAYAT AKTIVITAS FOKUS ANDA                              \n";
        cout << "========================================================================================\n";
        cout << "\n                     [Sistem] Riwayat sesi fokus kosong.\n";
    }

    cout << "========================================================================================\n";
    system("pause"); 
}