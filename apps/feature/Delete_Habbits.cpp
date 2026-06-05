void hapusSubHabit(HabitNode* root)
{
    if(root == nullptr)
        return;

    cout << "\n===== HAPUS SUB-HABIT =====\n";

    // Tampilkan seluruh parent
    HabitNode* parent = root->child;
    int jumlahParent = 0;

    while(parent != nullptr)
    {
        jumlahParent++;
        cout << jumlahParent << ". " << parent->nama << endl;
        parent = parent->sibling;
    }

    if(jumlahParent == 0)
    {
        cout << "Belum ada hobi utama!\n";
        return;
    }

    int pilihParent;
    cout << "\nPilih Hobi Utama : ";
    cin >> pilihParent;

    parent = root->child;

    for(int i = 1; i < pilihParent && parent != nullptr; i++)
    {
        parent = parent->sibling;
    }

    if(parent == nullptr)
    {
        cout << "Pilihan tidak valid!\n";
        return;
    }

    // Cek apakah parent punya child
    if(parent->child == nullptr)
    {
        cout << "Hobi ini belum memiliki sub-habit!\n";
        return;
    }

    // Tampilkan child
    cout << "\n===== SUB HABIT " << parent->nama << " =====\n";

    HabitNode* curr = parent->child;
    int jumlahChild = 0;

    while(curr != nullptr)
    {
        jumlahChild++;
        cout << jumlahChild << ". " << curr->nama << endl;
        curr = curr->sibling;
    }

    int pilihChild;
    cout << "\nPilih Sub-Habit Yang Akan Dihapus : ";
    cin >> pilihChild;

    curr = parent->child;
    HabitNode* prev = nullptr;

    for(int i = 1; i < pilihChild && curr != nullptr; i++)
    {
        prev = curr;
        curr = curr->sibling;
    }

    if(curr == nullptr)
    {
        cout << "Pilihan tidak valid!\n";
        return;
    }

    char konfirmasi;
    cout << "\nYakin ingin menghapus \"" 
         << curr->nama 
         << "\" ? (Y/N) : ";
    cin >> konfirmasi;

    if(konfirmasi != 'Y' && konfirmasi != 'y')
    {
        cout << "Penghapusan dibatalkan.\n";
        return;
    }

    if(prev == nullptr)
    {
        parent->child = curr->sibling;
    }
    else
    {
        prev->sibling = curr->sibling;
    }

    curr->sibling = nullptr;

    hapusTree(curr);

    cout << "\nSub-Habit berhasil dihapus!\n";
}