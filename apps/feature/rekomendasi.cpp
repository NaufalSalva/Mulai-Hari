#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<string> dapatkan5RekomendasiTeks(string hobi) {
    vector<string> daftar;
    
    if (hobi == "Olahraga") {
        daftar.push_back("Lakukan sesi timer fokus untuk latihan kardio / jogging selama 30 menit.");
        daftar.push_back("Buat target list di Manajemen Tugas untuk jadwal workout mingguan.");
        daftar.push_back("Catat aktivitas peregangan (stretching) setelah bangun tidur di Menu 2.");
        daftar.push_back("Riset gerakan olahraga baru yang aman untuk persendian melalui artikel.");
        daftar.push_back("Siapkan dan rapikan perlengkapan olahraga/sepatu H-1 sebelum latihan.");
    }
    else if (hobi == "Membaca") {
        daftar.push_back("Mulai sesi timer fokus membaca 5-10 halaman buku pilihan tanpa distraksi.");
        daftar.push_back("Buat checklist target judul buku yang harus selesai bulan ini di Menu Task.");
        daftar.push_back("Gunakan Menu 2 untuk mencatat progres halaman terakhir dari novel yang dibaca.");
        daftar.push_back("Tulis rangkuman atau poin penting dari bab yang baru selesai dibaca.");
        daftar.push_back("Riset referensi buku best-seller atau jurnal ilmiah baru untuk dibaca berikutnya.");
    }
    else if (hobi == "Coding") {
        daftar.push_back("Jalankan sesi timer Deep Work untuk fokus ngoding atau debugging project.");
        daftar.push_back("Breakdown fitur-fitur aplikasi (To-Do List) ke dalam Manajemen Tugas.");
        daftar.push_back("Log durasi ngoding dan baris kode harianmu secara manual di Menu 2.");
        daftar.push_back("Luangkan waktu 15 menit untuk membaca ulang dokumentasi tech stack/framework.");
        daftar.push_back("Rapikan struktur folder repository GitHub dan bersihkan code yang tidak dipakai.");
    }
    else if (hobi == "Belajar") {
        daftar.push_back("Sesi timer fokus untuk mendalami materi kuliah atau topik baru.");
        daftar.push_back("Buat checklist kisi-kisi ujian atau tumpukan tugas di Manajemen Tugas.");
        daftar.push_back("Gunakan Menu 2 untuk mencatat log progres belajar kelompok bersama teman.");
        daftar.push_back("Siapkan alat tulis, buku catatan, dan file materi sebelum sesi belajar dimulai.");
        daftar.push_back("Buat flashcards atau ringkasan kilat untuk review materi sebelum tidur.");
    }
    else if (hobi == "Menulis") {
        daftar.push_back("Sesi timer fokus untuk menulis draft artikel, cerita, atau jurnal harian.");
        daftar.push_back("Buat outline plot, karakter, atau struktur ide tulisan di daftar Task.");
        daftar.push_back("Catat ide-ide tulisan liar yang muncul hari ini melalui formulir Menu 2.");
        daftar.push_back("Cari referensi kosakata baru atau padanan kata yang estetik di KBBI.");
        daftar.push_back("Lakukan editing, pengecekan typo, dan keterbacaan pada draft tulisan kemarin.");
    }
    else if (hobi == "Memasak") {
        daftar.push_back("Gunakan timer fokus saat melakukan persiapan bahan makanan (Cutting & Prep).");
        daftar.push_back("Buat daftar rincian belanja bahan dapur mingguan di Manajemen Tugas.");
        daftar.push_back("Catat nama masakan dan eksperimen rasa resep barumu di Menu 2.");
        daftar.push_back("Tonton video tutorial memasak dari chef profesional untuk mempelajari teknik baru.");
        daftar.push_back("Lakukan pembersihan area dapur, kulkas, and pengorganisasian bumbu masak.");
    }
    else if (hobi == "Musik") {
        daftar.push_back("Sesi timer fokus untuk latihan instrumen (gitar/piano) atau vokal rutin.");
        daftar.push_back("Buat daftar partitur atau chord lagu baru yang ingin dikuasai di Task.");
        daftar.push_back("Catat progres kelancaran latihan progresi kunci gitarmu di Menu 2.");
        daftar.push_back("Lakukan tuning (setem) senar instrumen atau bersihkan alat musikmu.");
        daftar.push_back("Dengarkan playlist lagu referensi untuk melatih tempo.");
    }
    else if (hobi == "Gaming") {
        daftar.push_back("Sesi timer fokus untuk melatih aim atau mekanik game kompetitif.");
        daftar.push_back("Buat jadwal turnamen internal atau target rank mingguan di menu Task.");
        daftar.push_back("Gunakan Menu 2 untuk log aktivitas main mabar santai bareng teman.");
        daftar.push_back("Tonton video analisis strategi gameplay atau VOD review dari pro player.");
        daftar.push_back("Atur ulang setelan keybinds, sensitivitas mouse, dan lakukan update driver.");
    }
    else if (hobi == "Traveling") {
        daftar.push_back("Lakukan riset mendalam mengenai destinasi, rute perjalanan, dan akomodasi.");
        daftar.push_back("Buat packing list (checklist barang bawaan) di Manajemen Tugas.");
        daftar.push_back("Catat rincian pengeluaran dana setelah pulang traveling di Menu 2.");
        daftar.push_back("Hitung estimasi budget/anggaran operasional sebelum keberangkatan.");
        daftar.push_back("Tulis jurnal perjalanan atau rapikan file foto dokumentasi traveling.");
    }
    else if (hobi == "Menonton") {
        daftar.push_back("Gunakan timer fokus untuk menonton film dokumenter atau video edukatif.");
        daftar.push_back("Buat daftar watchlist film/anime yang ingin ditonton di menu Task.");
        daftar.push_back("Catat judul film dan ulasan/rating pribadimu setelah menonton di Menu 2.");
        daftar.push_back("Baca ulasan sinematografi atau teori plot twist sebelum menonton film berat.");
        daftar.push_back("Siapkan tempat menonton yang nyaman dan batasi screen time.");
    }
    else {
        daftar.push_back("Buat breakdown list pekerjaan terstruktur hari ini di menu Task.");
        daftar.push_back("Mulai sesi fokus produktif apa saja menggunakan bantuan Timer.");
        daftar.push_back("Gunakan Menu 2 untuk mencatat evaluasi mood produktivitas harianmu.");
        daftar.push_back("Susun rencana goals atau target baru yang ingin dicapai esok hari.");
        daftar.push_back("Rapikan meja kerja atau ruang belajar agar fokus meningkat.");
    }
    
    return daftar;
}


void menuRekomendasiHobi(HabitNode* root) {
    system("cls");
    cout << "========================================================================\n";
    cout << "                     RISET REKOMENDASI PRODUKTIVITAS                    \n";
    cout << "                         (Saran Teks & Ide Aksi)                        \n";
    cout << "========================================================================\n";
    
    if (root == nullptr || root->child == nullptr) {
        cout << "\n   [Sistem] Kamu belum memilih hobi/habit utama apa pun.\n";
        cout << "========================================================================\n";
        system("pause");
        return;
    }
    
  
    HabitNode* temp = root->child;
    
    while (temp != nullptr) {
        cout << "\n>>> HOBI: " << temp->nama << "\n";
        cout << "------------------------------------------------------------------------\n";
        

        vector<string> rekomendasi = dapatkan5RekomendasiTeks(temp->nama);
        

        for (int i = 0; i < 5; i++) {
            cout << " " << i + 1 << ". " << rekomendasi[i] << "\n";
        }
        cout << "------------------------------------------------------------------------\n";
        

        temp = temp->sibling;
    }
    
    cout << "\n========================================================================\n";
    cout << "[Sistem] Silakan eksekusi ide di atas secara mandiri melalui menu utama.\n";
    cout << "========================================================================\n";
    system("pause"); 
}