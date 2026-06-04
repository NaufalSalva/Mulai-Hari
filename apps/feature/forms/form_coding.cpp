#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct FormCoding {
    string namaProjek;
    string jenisPemrograman;
    string bahasaPemrograman;
    int durasiCoding;
    string catatan;
    string waktuAktivitas;
};

bool validasiNamaProjek(const string& nama) {
    if (nama.empty() || nama.length() < 2) {
        return false;
    }
    return true;
}


void tampilkanJenisCoding() {
    cout << "\n=========== PILIH JENIS CODING ==============\n";
    cout << "1. Web Development\n";
    cout << "2. Mobile Development\n";
    cout << "3. Desktop Development\n";
    cout << "4. Data Science\n";
    cout << "5. Game Development\n";
    cout << "6. Cyber Security\n";
    cout << "7. Machine Learning\n";
    cout << "8. Lainnya\n";
    cout << "========================================== \n";
}


FormCoding inputFormCoding() {
    FormCoding form;
    int pilihan;
    
    system("cls");
    cout << "\n";
    cout << "=============================================\n";
    cout << "            FORM AKTIVITAS CODING         \n";
    cout << "=============================================\n\n";
    

    cout << "============= 1. NAMA PROJEK =============\n";
    cout << "Masukkan nama projek: ";
    getline(cin, form.namaProjek);
    
    while (!validasiNamaProjek(form.namaProjek)) {
        cout << "Nama projek tidak valid! Masukkan lagi: ";
        getline(cin, form.namaProjek);
    }
    
    cout << "\n============= 2. JENIS PEMROGRAMAN =============\n";
    tampilkanJenisCoding();
    cout << "Pilih jenis (1-8): ";
    cin >> pilihan;
    switch(pilihan) {
        case 1: form.jenisPemrograman = "Web Development"; break;
        case 2: form.jenisPemrograman = "Mobile Development"; break;
        case 3: form.jenisPemrograman = "Desktop Development"; break;
        case 4: form.jenisPemrograman = "Data Science"; break;
        case 5: form.jenisPemrograman = "Game Development"; break;
        case 6: form.jenisPemrograman = "Cyber Security"; break;
        case 7: form.jenisPemrograman = "Machine Learning"; break;
        case 8: form.jenisPemrograman = "Lainnya"; break;
        default: form.jenisPemrograman = "Web Development";
    }
    cin.ignore();

    cout << "\n============= 3. BAHASA PEMROGRAMAN =============\n";
    cout << "Masukkan bahasa pemrograman yang digunakan: ";
    getline(cin, form.bahasaPemrograman);


    cout << "============= 4. DURASI CODING =============\n";
    cout << "Masukkan durasi (dalam menit): ";
    cin >> form.durasiCoding;
    
    while (!validasiDurasi(form.durasiCoding)) {
        cout << "Durasi harus 1-480 menit! Masukkan lagi: ";
        cin >> form.durasiCoding;
    }
    cin.ignore();

    cout << "\n============= 5. WAKTU AKTIVITAS =============\n";
    tampilkanMenuWaktu();
    cout << "Pilih waktu (1-4): ";
    cin >> pilihan;
    form.waktuAktivitas = pilihanWaktu(pilihan);
    cin.ignore();
    

    cout << "\n============= 6. CATATAN TAMBAHAN =============\n";
    cout << "Catatan: ";
    getline(cin, form.catatan);
    
    return form;
}


string standardisasiDetailCoding(const FormCoding& form) {
    string detail = "";
    
    detail += form.namaProjek;
    detail += " | ";
    detail += to_string(form.durasiCoding) + " menit";
    detail += " | Jenis: " + form.jenisPemrograman;
    detail += " | Waktu: " + form.waktuAktivitas;
    
    if (!form.catatan.empty()) {
        detail += " | Catatan: " + form.catatan;
    }
    
    return detail;
}


void tampilkanPreviewCoding(const FormCoding& form) {
    system("cls");
    cout << "\n";
    cout << "=============================================\n";
    cout << "           PREVIEW AKTIVITAS CODING       \n";
    cout << "=============================================\n\n";
    
    cout << "Detail Aktivitas:\n";
    cout << "=============================================\n";
    cout << "Nama Projek   : " << form.namaProjek << "\n";
    cout << "Jenis Pemrograman  : " << form.jenisPemrograman << "\n";
    cout << "Durasi         : " << form.durasiCoding << " menit\n";
    cout << "Waktu Aktivitas: " << form.waktuAktivitas << "\n";

    if (!form.catatan.empty()) {
        cout << "Catatan        : " << form.catatan << "\n";
    }
    
    cout << "\n=============================================\n";
    cout << "String Detail Terstandarisasi:\n";
    cout << standardisasiDetailCoding(form) << "\n";
    cout << "=============================================\n";
    
    cout << "\nTekan ENTER untuk kembali...";
    cin.ignore();
}

void formCoding() {
    FormCoding form = inputFormCoding();
    tampilkanPreviewCoding(form);
}
