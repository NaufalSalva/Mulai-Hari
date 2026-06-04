#include <iostream>
#include <string>
using namespace std;

void hapusSubTree(HabitNode* node){
 if(node==nullptr) return;
 hapusSubTree(node->child);
 hapusSubTree(node->sibling);
 delete node;
}

void hapusSubHabit(HabitNode* root)
{
 if(root==nullptr) return;
 string namaHobi,namaSubHabit;
 cout<<"\n===== HAPUS SUB-HABIT =====\n";
 cin.ignore();
 cout<<"Pilih Hobi Utama : "; getline(cin,namaHobi);
 HabitNode* parent=cariHobi(root,namaHobi);
 if(parent==nullptr){ cout<<"Hobi tidak ditemukan!\n"; return; }
 cout<<"Nama Sub-Habit Yang Dihapus : "; getline(cin,namaSubHabit);
 HabitNode* curr=parent->child; HabitNode* prev=nullptr;
 while(curr){
   if(curr->nama==namaSubHabit){
      if(prev==nullptr) parent->child=curr->sibling;
      else prev->sibling=curr->sibling;
      curr->sibling=nullptr;
      hapusSubTree(curr);
      cout<<"Sub-Habit berhasil dihapus!\n"; return;
   }
   prev=curr; curr=curr->sibling;
 }
 cout<<"Sub-Habit tidak ditemukan!\n";
}
