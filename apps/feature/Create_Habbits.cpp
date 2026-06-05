#include <iostream>
#include <string>

using namespace std;

void tambahSubHabitUser(HabitNode* root)
{
    if(root == nullptr)
        return;

    cout << "\n===== TAMBAH HABIT =====\n";

    HabitNode* parent = root->child;

    int jumlah = 0;

    while(parent != nullptr)
    {
        jumlah++;
        cout << jumlah << ". " << parent->nama << endl;
        parent = parent->sibling;
    }

    int pilihParent;
    cout << "\nPilih Hobi Utama : ";
    cin >> pilihParent;

    parent = root->child;

    for(int i=1; i<pilihParent && parent!=nullptr; i++)
    {
        parent = parent->sibling;
    }

    if(parent == nullptr)
    {
        cout << "Pilihan tidak valid!\n";
        return;
    }

    int pilihanTemplate;

    if(parent->nama == "Olahraga")
    {
        cout << "\n===== OLAHRAGA =====\n";
        cout << "1. Renang\n";
        cout << "2. Lari\n";
        cout << "3. Gym\n";
        cout << "4. Sepeda\n";
        cout << "5. Bulu Tangkis\n";

        cout << "Pilih : ";
        cin >> pilihanTemplate;

        switch(pilihanTemplate)
        {
            case 1: tambahSubHabit(parent,"Renang"); break;
            case 2: tambahSubHabit(parent,"Lari"); break;
            case 3: tambahSubHabit(parent,"Gym"); break;
            case 4: tambahSubHabit(parent,"Sepeda"); break;
            case 5: tambahSubHabit(parent,"Bulu Tangkis"); break;
            default: cout<<"Pilihan tidak valid!\n";
        }
    }

    else if(parent->nama == "Coding")
    {
        cout << "\n===== CODING =====\n";
        cout << "1. Belajar C++\n";
        cout << "2. Linked List\n";
        cout << "3. Stack\n";
        cout << "4. Queue\n";
        cout << "5. Debugging\n";

        cout << "Pilih : ";
        cin >> pilihanTemplate;

        switch(pilihanTemplate)
        {
            case 1: tambahSubHabit(parent,"Belajar C++"); break;
            case 2: tambahSubHabit(parent,"Linked List"); break;
            case 3: tambahSubHabit(parent,"Stack"); break;
            case 4: tambahSubHabit(parent,"Queue"); break;
            case 5: tambahSubHabit(parent,"Debugging"); break;
            default: cout<<"Pilihan tidak valid!\n";
        }
    }

    else if(parent->nama == "Membaca")
    {
        cout << "\n===== MEMBACA =====\n";
        cout << "1. Novel\n";
        cout << "2. Artikel\n";
        cout << "3. Jurnal\n";
        cout << "4. Buku Kuliah\n";

        cout << "Pilih : ";
        cin >> pilihanTemplate;

        switch(pilihanTemplate)
        {
            case 1: tambahSubHabit(parent,"Novel"); break;
            case 2: tambahSubHabit(parent,"Artikel"); break;
            case 3: tambahSubHabit(parent,"Jurnal"); break;
            case 4: tambahSubHabit(parent,"Buku Kuliah"); break;
            default: cout<<"Pilihan tidak valid!\n";
        }
    }

    else if(parent->nama == "Memasak")
    {
        cout << "\n===== MEMASAK =====\n";
        cout << "1. Masakan Tradisional\n";
        cout << "2. Masakan Modern\n";
        cout << "3. Masakan Cepat Saji\n";

        cout << "Pilih : ";
        cin >> pilihanTemplate;

        switch(pilihanTemplate)
        {
            case 1: tambahSubHabit(parent,"Masakan Tradisional"); break;
            case 2: tambahSubHabit(parent,"Masakan Modern"); break;
            case 3: tambahSubHabit(parent,"Maskan Cepat Saji"); break;
            default: cout<<"Pilihan tidak valid!\n";
        }
    }

    else if(parent->nama == "Traveling")
    {
        cout << "\n===== TRAVELING =====\n";
        cout << "1. Riset Destinasi\n";
        cout << "2. Belajar Budaya Lokal\n";
        cout << "3. Fotografi Perjalanan\n";
        cout << "4. Menulis Travel Journal\n";

        cout << "Pilih : ";
        cin >> pilihanTemplate;

        switch(pilihanTemplate)
        {
            case 1: tambahSubHabit(parent,"Riset Destinasi"); break;
            case 2: tambahSubHabit(parent,"Belajar Budaya Lokal"); break;
            case 3: tambahSubHabit(parent,"Fotografi Perjalanan"); break;
            case 4: tambahSubHabit(parent,"Menulis Travel Journal"); break;
            default: cout<<"Pilihan tidak valid!\n";
        }
    }

    else if(parent->nama == "Musik")
    {
        cout << "\n===== MUSIK =====\n";
        cout << "1. Latihan Gitar\n";
        cout << "2. Latihan Vokal\n";
        cout << "3. Rekaman Cover Lagu\n";
        cout << "4. Belajar Teori Musik\n";

        cout << "Pilih : ";
        cin >> pilihanTemplate;

        switch(pilihanTemplate)
        {
            case 1: tambahSubHabit(parent,"Latihan Gitar"); break;
            case 2: tambahSubHabit(parent,"Latihan Vokal"); break;
            case 3: tambahSubHabit(parent,"Rekaman Cover Lagu"); break;
            case 4: tambahSubHabit(parent,"Belajar Teori Musik"); break;
            default: cout<<"Pilihan tidak valid!\n";
        }
    }

    else if(parent->nama == "Menulis")
    {
        cout << "\n===== MENULIS =====\n";
        cout << "1. Novel\n";
        cout << "2. Artikel\n";
        cout << "3. Jurnal\n";
        cout << "4. Cerita\n";

        cout << "Pilih : ";
        cin >> pilihanTemplate;

        switch(pilihanTemplate)
        {
            case 1: tambahSubHabit(parent,"Novel"); break;
            case 2: tambahSubHabit(parent,"Artikel"); break;
            case 3: tambahSubHabit(parent,"Jurnal"); break;
            case 4: tambahSubHabit(parent,"Cerita"); break;
            default: cout<<"Pilihan tidak valid!\n";
        }
    }

    else if(parent->nama == "Gaming")
    {
        cout << "\n===== GAMING =====\n";
        cout << "1. Latihan Aim\n";
        cout << "2. Mabar\n";
        cout << "3. Farming\n";
        cout << "4. Guide Gameplay\n";

        cout << "Pilih : ";
        cin >> pilihanTemplate;

        switch(pilihanTemplate)
        {
            case 1: tambahSubHabit(parent,"Latihan Aim"); break;
            case 2: tambahSubHabit(parent,"Mabar"); break;
            case 3: tambahSubHabit(parent,"Farming"); break;
            case 4: tambahSubHabit(parent,"Guide Gameplay"); break;
            default: cout<<"Pilihan tidak valid!\n";
        }
    }

    else if(parent->nama == "Belajar")
    {
        cout << "\n===== BELAJAR =====\n";
        cout << "1. Fisika\n";
        cout << "2. Matematika\n";
        cout << "3. Kimia\n";
        cout << "4. UTBK\n";

        cout << "Pilih : ";
        cin >> pilihanTemplate;

        switch(pilihanTemplate)
        {
            case 1: tambahSubHabit(parent,"Fisika"); break;
            case 2: tambahSubHabit(parent,"Matematika"); break;
            case 3: tambahSubHabit(parent,"Kimia"); break;
            case 4: tambahSubHabit(parent,"UTBK"); break;
            default: cout<<"Pilihan tidak valid!\n";
        }
    }

    else if(parent->nama == "Menonton")
    {
        cout << "\n===== MENONTON =====\n";
        cout << "1. Film\n";
        cout << "2. Drama\n";
        cout << "3. Anime\n";
        cout << "4. Drachin\n";

        cout << "Pilih : ";
        cin >> pilihanTemplate;

        switch(pilihanTemplate)
        {
            case 1: tambahSubHabit(parent,"Film"); break;
            case 2: tambahSubHabit(parent,"Drama"); break;
            case 3: tambahSubHabit(parent,"Anime"); break;
            case 4: tambahSubHabit(parent,"Drachin"); break;
            default: cout<<"Pilihan tidak valid!\n";
        }
    }



    cout << "\nHabit berhasil ditambahkan!\n";
}