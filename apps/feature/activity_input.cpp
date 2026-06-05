#pragma once
#include "../utils/validation.cpp"
#include <iostream>
#include "forms/form_coding.cpp"
#include "forms/form_gaming.cpp"
#include "forms/form_membaca.cpp"
#include "forms/form_olahraga.cpp"
#include "forms/form_menulis.cpp"
#include "forms/form_musik.cpp"
#include "forms/form_memasak.cpp"
#include "forms/form_belajar.cpp"
#include "forms/form_menonton.cpp"
#include "forms/form_traveling.cpp"

using namespace std;

void inputAktivitas(HabitNode* root)
{
    LogAktivitasNode aktivitas;

    int pilihan;

    system("cls");

    cout << "=====================================\n";
    cout << "      INPUT AKTIVITAS HARIAN\n";
    cout << "=====================================\n\n";

    cout << "Pilih Hobi:\n";
    int nomor = 1;
    HabitNode* temp = root->child;
    while (temp != nullptr) {
        cout << nomor << ". " << temp->nama << "\n";
        temp = temp->sibling;
        nomor++;
    }

    // cout << "1. Coding\n";
    // cout << "2. Gaming\n";
    // cout << "3. Membaca\n";
    // cout << "4. Olahraga\n";
    // cout << "5. Menulis\n";
    // cout << "6. Musik\n";
    // cout << "7. Memasak\n";
    // cout << "8. Menonton\n";
    // cout << "9. Traveling\n";
    // cout << "10. Belajar\n";

    cout << "\nPilihan: ";
    cin >> pilihan;
    cin.ignore();

    switch (pilihan)
    {
        case 1:
        {
            FormCoding form = inputFormCoding();

            aktivitas.hobi = "Coding";
            aktivitas.detail = standardisasiDetailCoding(form);
            aktivitas.durai = form.durasiCoding;
            break;
        }

        case 2:
        {
            FormGaming form = inputFormGaming();

            aktivitas.hobi = "Gaming";
            aktivitas.detail = standardisasiDetailGaming(form);
            aktivitas.durai = form.durasiMenit;
            break;
        }

        case 3:
        {
            FormMembaca form = inputFormMembaca();

            aktivitas.hobi = "Membaca";
            aktivitas.detail = standardisasiDetailMembaca(form);
            aktivitas.durai = form.durasiMenit;
            break;
        }

        case 4:
        {
            FormOlahraga form = inputFormOlahraga();

            aktivitas.hobi = "Olahraga";
            aktivitas.detail = standardisasiDetailOlahraga(form);
            aktivitas.durai = form.durasiMenit;
            break;
        }

        case 5:
        {
            FormMenulis form = inputFormMenulis();

            aktivitas.hobi = "Menulis";
            aktivitas.detail = standardisasiDetailMenulis(form);
            aktivitas.durai = 0; // atau ambil dari form jika ada
            break;
        }

        case 6:
        {
            FormMusik form = inputFormMusik();

            aktivitas.hobi = "Musik";
            aktivitas.detail = standardisasiDetailMusik(form);
            aktivitas.durai = form.durasiMenit;
            break;
        }
        case 7:
        {
            FormMemasak form = inputFormMemasak();

            aktivitas.hobi = "Memasak";
            aktivitas.detail = standardisasiDetailMemasak(form);
            aktivitas.durai = form.durasiMemasak;
            break;
        }
        case 8:
        {
            FormMenonton form = inputFormMenonton();

            aktivitas.hobi = "Menonton";
            aktivitas.detail = standardisasiDetailMenonton(form);
            aktivitas.durai = form.durasiMenit;
            break;
        }
        case 9:
        {
            FormTraveling form = inputFormTraveling();

            aktivitas.hobi = "Traveling";
            aktivitas.detail = standardisasiDetailTraveling(form);
            aktivitas.durai = form.durasiPerjalanan;
            break;
        }
        case 10:
        {
            FormBelajar form = inputFormBelajar();

            aktivitas.hobi = "Belajar";
            aktivitas.detail = standardisasiDetailBelajar(form);
            aktivitas.durai = form.durasiMenit;
            break;
        }


        default:
        {
            cout << "\nPilihan tidak valid!\n";
            return;
        }
    }

    cout << "\nMood Saat Ini:\n";
    cout << "1. Senang\n";
    cout << "2. Semangat\n";
    cout << "3. Biasa\n";
    cout << "4. Capek\n";
    cout << "5. Stres\n";

    int moodPilihan = validasiInputAngka(1, 5, "\nPilih Mood Kamu Sekarang: ");

    switch (moodPilihan)
    {
        case 1: aktivitas.mood = "Senang"; break;
        case 2: aktivitas.mood = "Semangat"; break;
        case 3: aktivitas.mood = "Biasa"; break;
        case 4: aktivitas.mood = "Capek"; break;
        case 5: aktivitas.mood = "Stres"; break;
        default: aktivitas.mood = "Biasa";
    }

    pushAktivitas(historyStack, aktivitas);


    cout << "\n=====================================\n";
    cout << " Aktivitas berhasil disimpan!\n";
    cout << "=====================================\n";
}