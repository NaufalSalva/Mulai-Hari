# 🌅 MulaiHari

**MulaiHari** adalah aplikasi *Productivity & Lifestyle Management* berbasis **Command Line Interface (CLI)** yang dirancang khusus untuk membantu Anda membangun disiplin harian secara terstruktur. 

Aplikasi ini menggunakan pendekatan arsitektur struktur data tingkat lanjut untuk memastikan seluruh pencatatan aktivitas, pengelolaan waktu, dan manajemen tugas berjalan secara efisien langsung di dalam memori RAM.

---

## 🚀 Fitur Utama

### 1. 🌲 Habit Tree (Struktur Data Tree LCRS)
Mengelola hobi dan kebiasaan harian Anda menggunakan struktur hierarki *Left-Child Right-Sibling (LCRS) Tree*. Anda dapat menambahkan hobi utama hingga membuat cabang sub-habit kustom secara dinamis.

### 2. ⏱️ Sesi Fokus Hari (Sesi Fokus timer)
Pembantu produktivitas dengan *real-time countdown timer*. Menyediakan template waktu adaptif mulai dari Pomodoro Pendek (15 menit), Pomodoro Standar (25 menit), hingga Deep Work (45 menit). Sesi ini dilengkapi dengan fitur kontrol jeda (*Pause/Resume*) dan penghentian awal.

### 3. 📊 Riwayat Aktivitas & Sesi (Struktur Data Stack)
Seluruh hasil evaluasi dari sesi timer fokus maupun pencatatan aktivitas harian langsung disimpan ke dalam tumpukan memory **Stack**. 
* **Riwayat Sesi Fokus**: Menampilkan rentang waktu presisi (*Jam Mulai s/d Jam Selesai*) beserta status penyelesaiannya secara realtime.
* **Riwayat Aktivitas Manual**: Menyimpan catatan kustom dan evaluasi tingkat mood harian Anda setelah beraktivitas.

### 4. 🎯 Manajemen Tugas (Struktur Data Linked List)
Sistem *To-Do List* dinamis terintegrasi yang melacak daftar pekerjaan berdasarkan hobi yang Anda miliki. Dilengkapi fitur ceklis selesai, ubah nama tugas, hingga penghapusan node tugas secara dinamis.

### 5. 💡 Rekomendasi Ide Produktivitas 
Menu pintar yang langsung mendeteksi seluruh hobi aktif Anda di dalam sistem Tree, lalu menyajikan **5 rekomendasi saran aktivitas teks murni** yang padat dan edukatif untuk memicu produktivitas harian Anda tanpa ribet.

---

## 🛠️ Tech Stack & Struktur Data
* **Bahasa Pemrograman**: C++
* **Struktur Data Utama**: 
  * *Tree (Left-Child Right-Sibling)* untuk manajemen hierarki Habit & Hobi.
  * *Linked List* untuk sistem penampungan Manajemen Tugas (To-Do List).
  * *Stack* untuk melacak tumpukan log Riwayat Aktivitas dan Sesi Fokus secara realtime di RAM.

---
*Langkah awal disiplin dimulai dari bagaimana Anda **MulaiHari** ini!*
