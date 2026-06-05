#include <iostream>
#include <string>
#include "../utils/data_structure.cpp"

using namespace std;

void tampilkanTask(TaskList list, string username) {
    cout << "\n=====================================\n";
    cout << "        MANAJEMEN TUGAS HABITMU        \n";
    cout << "=====================================\n";
    
    bool ada = false;
    string habits[50];
    int hCount = 0;
    
    for(TaskNode* t = list.head; t != nullptr; t = t->next) {
        if(t->username == username) {
            ada = true;
            bool exist = false;
            for(int i=0; i<hCount; i++) {
                if(habits[i] == t->namaHabit) exist = true;
            }
            if(!exist) habits[hCount++] = t->namaHabit;
        }
    }
    
    if(!ada) {
        cout << "Belum ada tugas. Bebas rebahan!\n";
        cout << "=====================================\n";
        return;
    }
    
    for(int i=0; i<hCount; i++) {
        cout << i+1 << ". [ Habit: " << habits[i] << " ]\n";
        
        int index = 1;
        
        for(TaskNode* t = list.head; t != nullptr; t = t->next) {
            if(t->username == username && t->namaHabit == habits[i]) {
                string status = t->isSelesai ? "[V]" : "[ ]";
                cout << "   " << index << ". " << status << " " << t->namaTask << "\n";
                index++;
            }
        }
        cout << "\n"; 
    }
    cout << "=====================================\n";
}

void tambahTask(TaskList& list, string username, HabitNode* root) {
    if (root == nullptr || root->child == nullptr) {
        cout << "Belum ada hobi/habit.\n";
        return;
    }
    
    cout << "\n===== PILIH HABIT UNTUK TUGAS INI =====\n";
    HabitNode* parent = root->child;
    int num = 1;
    while (parent != nullptr) {
        cout << num << ". " << parent->nama << "\n";
        parent = parent->sibling;
        num++;
    }
    
    cout << "Pilih nomor habit: ";
    int pilHabit; cin >> pilHabit;
    
    parent = root->child;
    for (int i = 1; i < pilHabit && parent != nullptr; i++) {
        parent = parent->sibling;
    }
    
    if (parent == nullptr) {
        cout << "Pilihan habit tidak valid!\n";
        return;
    }
    
    string nama;
    cout << "Masukkan nama tugas untuk habit [" << parent->nama << "]: ";
    getline(cin >> ws, nama); 

    TaskNode* baru = new TaskNode;
    baru->username = username;
    baru->namaHabit = parent->nama; 
    baru->namaTask = nama;
    baru->isSelesai = false; 
    baru->next = nullptr;

    if (list.head == nullptr) {
        list.head = baru;
    } else {
        TaskNode* temp = list.head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = baru;
    }
    cout << "Tugas berhasil ditambahkan ke To-Do List!\n";
}

void editTask(TaskList& list, string username) {
    tampilkanTask(list, username);
    if (list.head == nullptr) return;

    string habits[50];
    int hCount = 0;
    for (TaskNode* t = list.head; t != nullptr; t = t->next) {
        if (t->username == username) {
            bool exist = false;
            for (int i = 0; i < hCount; i++) {
                if (habits[i] == t->namaHabit) exist = true;
            }
            if (!exist) habits[hCount++] = t->namaHabit;
        }
    }
    if (hCount == 0) return;

    int pilHabit;
    cout << "Pilih nomor Habit (1-" << hCount << "): ";
    cin >> pilHabit;

    if (pilHabit < 1 || pilHabit > hCount) {
        cout << "Nomor habit tidak valid!\n";
        return;
    }

    string habitTarget = habits[pilHabit - 1];

    int pilTugas;
    cout << "Pilih nomor tugas di [" << habitTarget << "]: ";
    cin >> pilTugas;

    TaskNode* target = nullptr;
    int localIndex = 1;
    for (TaskNode* t = list.head; t != nullptr; t = t->next) {
        if (t->username == username && t->namaHabit == habitTarget) {
            if (localIndex == pilTugas) {
                target = t;
                break;
            }
            localIndex++;
        }
    }

    if (!target) {
        cout << "Nomor tugas tidak ditemukan!\n";
        return;
    }
    
    cout << "\n1. Tandai Selesai / Belum Selesai\n";
    cout << "2. Ganti Nama Tugas\n";
    cout << "Pilih aksi (1/2): ";
    int aksi; cin >> aksi;
    
    if (aksi == 1) {
        target->isSelesai = !target->isSelesai; 
        cout << "Status tugas berhasil diupdate!\n";
    } else if (aksi == 2) {
        cout << "Masukkan nama tugas yang baru: ";
        getline(cin >> ws, target->namaTask);
        cout << "Nama tugas berhasil diganti!\n";
    }
}

void hapusTask(TaskList& list, string username) {
    tampilkanTask(list, username);
    if (list.head == nullptr) return;

    string habits[50];
    int hCount = 0;
    for (TaskNode* t = list.head; t != nullptr; t = t->next) {
        if (t->username == username) {
            bool exist = false;
            for (int i = 0; i < hCount; i++) {
                if (habits[i] == t->namaHabit) exist = true;
            }
            if (!exist) habits[hCount++] = t->namaHabit;
        }
    }
    if (hCount == 0) return;

    int pilHabit;
    cout << "Pilih nomor Habit (1-" << hCount << "): ";
    cin >> pilHabit;

    if (pilHabit < 1 || pilHabit > hCount) {
        cout << "Nomor habit tidak valid!\n";
        return;
    }

    string habitTarget = habits[pilHabit - 1];

    int pilTugas;
    cout << "Pilih nomor tugas di [" << habitTarget << "]: ";
    cin >> pilTugas;

    TaskNode* targetNode = nullptr;
    int localIndex = 1;
    for (TaskNode* t = list.head; t != nullptr; t = t->next) {
        if (t->username == username && t->namaHabit == habitTarget) {
            if (localIndex == pilTugas) {
                targetNode = t;
                break;
            }
            localIndex++;
        }
    }

    if (!targetNode) {
        cout << "Nomor tugas tidak valid!\n";
        return;
    }
    
    if (list.head == targetNode) {
        list.head = targetNode->next;
    } else {
        TaskNode* prev = list.head;
        while (prev->next != targetNode) prev = prev->next;
        prev->next = targetNode->next;
    }
    delete targetNode;
    cout << "Tugas berhasil dihapus!\n";
}

void menuTaskManager(TaskList& list, string username, HabitNode* root) { 
    bool jalan = true;
    while (jalan) {
        system("cls");
        tampilkanTask(list, username);
        
        cout << "Menu Manajemen Tugas:\n";
        cout << "1. Tambah Tugas Baru\n";
        cout << "2. Edit / Ceklis Tugas\n";
        cout << "3. Hapus Tugas\n";
        cout << "0. Kembali ke Dashboard\n";
        cout << "Pilih menu: ";
        int pil; cin >> pil;

        switch(pil) {
            case 1: tambahTask(list, username, root); system("pause"); break; 
            case 2: editTask(list, username); system("pause"); break;
            case 3: hapusTask(list, username); system("pause"); break;
            case 0: jalan = false; break;
            default: cout << "Pilihan ga valid!\n"; system("pause");
        }
    }
}