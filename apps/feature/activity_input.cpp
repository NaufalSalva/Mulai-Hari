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

    if (pilihan < 1 || pilihan >= nomor) {
        cout << "\nPilihan tidak valid!\n";
        return;
    }
    
    HabitNode* pilihanNode = root->child;

    for (int i = 1; i < pilihan && pilihanNode != nullptr; i++) {
        pilihanNode = pilihanNode->sibling;
    }

    if(pilihanNode == nullptr) {
        cout << "\nPilihan tidak valid!\n";
        return;
    }


    if (pilihanNode->nama == "Coding")
        {
            FormCoding form = inputFormCoding();

            aktivitas.hobi = "Coding";
            aktivitas.detail = standardisasiDetailCoding(form);
            aktivitas.durasi = form.durasiCoding;
        }

     else if (pilihanNode->nama == "Gaming")
        {
            FormGaming form = inputFormGaming();

            aktivitas.hobi = "Gaming";
            aktivitas.detail = standardisasiDetailGaming(form);
            aktivitas.durasi = form.durasiMenit;
        }

     else if (pilihanNode->nama == "Membaca")
        {
            FormMembaca form = inputFormMembaca();

            aktivitas.hobi = "Membaca";
            aktivitas.detail = standardisasiDetailMembaca(form);
            aktivitas.durasi = form.durasiMenit;
        }

      else if (pilihanNode->nama == "Olahraga")
        {
            FormOlahraga form = inputFormOlahraga();

            aktivitas.hobi = "Olahraga";
            aktivitas.detail = standardisasiDetailOlahraga(form);
            aktivitas.durasi = form.durasiMenit;
        }

      else if (pilihanNode->nama == "Menulis")
        {
            FormMenulis form = inputFormMenulis();

            aktivitas.hobi = "Menulis";
            aktivitas.detail = standardisasiDetailMenulis(form);
            aktivitas.durasi = form.durasiMenit;
        }

        else if (pilihanNode->nama == "Musik")
        {
            FormMusik form = inputFormMusik();

            aktivitas.hobi = "Musik";
            aktivitas.detail = standardisasiDetailMusik(form);
            aktivitas.durasi = form.durasiMenit;
        }
        else if (pilihanNode->nama == "Memasak")
        {
            FormMemasak form = inputFormMemasak();

            aktivitas.hobi = "Memasak";
            aktivitas.detail = standardisasiDetailMemasak(form);
            aktivitas.durasi = form.durasiMemasak;
        }
        else if (pilihanNode->nama == "Menonton")
        {
            FormMenonton form = inputFormMenonton();

            aktivitas.hobi = "Menonton";
            aktivitas.detail = standardisasiDetailMenonton(form);
            aktivitas.durasi = form.durasiMenit;
        }
        else if (pilihanNode->nama == "Traveling")
        {
            FormTraveling form = inputFormTraveling();

            aktivitas.hobi = "Traveling";
            aktivitas.detail = standardisasiDetailTraveling(form);
            aktivitas.durasi = form.durasiPerjalanan;
        }
        else if (pilihanNode->nama == "Belajar")
        {
            FormBelajar form = inputFormBelajar();

            aktivitas.hobi = "Belajar";
            aktivitas.detail = standardisasiDetailBelajar(form);
            aktivitas.durasi = form.durasiMenit;
        }
        else
        {
            cout << "\nPilihan tidak valid!\n";
            return;
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