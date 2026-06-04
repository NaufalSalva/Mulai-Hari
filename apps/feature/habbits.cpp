// #include <iostream>
// #include <string>
// using namespace std;

// void tambahSubHabit(HabitNode* parent, string namaSubHabit)
// {
//     if(parent == nullptr)
//         return;

//     HabitNode* baru = new HabitNode;
//     baru->nama = namaSubHabit;
//     baru->child = nullptr;
//     baru->sibling = nullptr;

//     if(parent->child == nullptr)
//     {
//         parent->child = baru;
//     }
//     else
//     {
//         HabitNode* temp = parent->child;

//         while(temp->sibling != nullptr)
//         {
//             temp = temp->sibling;
//         }

//         temp->sibling = baru;
//     }
// }

// HabitNode* cariHobi(HabitNode* root, string namaHobi)
// {
//     if(root == nullptr)
//         return nullptr;

//     HabitNode* temp = root->child;

//     while(temp != nullptr)
//     {
//         if(temp->nama == namaHobi)
//             return temp;

//         temp = temp->sibling;
//     }

//     return nullptr;
// }

// void generateSubHabitOtomatis(HabitNode* root)
// {
//     if(root == nullptr)
//         return;

//     HabitNode* currentHobi = root->child;

//     while(currentHobi != nullptr)
//     {
//         if(currentHobi->nama == "Olahraga")
//         {
//             tambahSubHabit(currentHobi,"Lari Pagi 15 Menit");
//             tambahSubHabit(currentHobi,"Stretching & Pemanasan");
//         }
//         else if(currentHobi->nama == "Coding")
//         {
//             tambahSubHabit(currentHobi,"Eksplorasi Sintaks C++");
//             tambahSubHabit(currentHobi,"Debugging Error");
//             tambahSubHabit(currentHobi,"Riset Algoritma");
//         }
//         else if(currentHobi->nama == "Membaca")
//         {
//             tambahSubHabit(currentHobi,"Baca 10 Halaman");
//             tambahSubHabit(currentHobi,"Review Bab Terakhir");
//         }
//         else if(currentHobi->nama == "Masak")
//         {
//             tambahSubHabit(currentHobi,"Siapkan Bahan");
//             tambahSubHabit(currentHobi,"Eksperimen Resep Baru");
//         }
//         else
//         {
//             tambahSubHabit(currentHobi,"Persiapan Aktivitas");
//             tambahSubHabit(currentHobi,"Evaluasi Sesi");
//         }

//         currentHobi = currentHobi->sibling;
//     }
// }

// void cetakTreeLCRS(HabitNode* node,
//                    string prefix = "",
//                    bool isLast = true,
//                    bool isRoot = true)
// {
//     if(node == nullptr)
//         return;

//     if(isRoot)
//     {
//         cout << "[Root] " << node->nama << endl;
//     }
//     else
//     {
//         cout << prefix;
//         cout << (isLast ? "└── " : "├── ");
//         cout << node->nama << endl;
//     }

//     string nextPrefix =
//         prefix +
//         (isLast && !isRoot
//         ? "    "
//         : (isRoot ? "" : "│   "));

//     HabitNode* child = node->child;

//     while(child != nullptr)
//     {
//         bool lastSibling =
//             (child->sibling == nullptr);

//         cetakTreeLCRS(
//             child,
//             nextPrefix,
//             lastSibling,
//             false
//         );

//         child = child->sibling;
//     }
// }