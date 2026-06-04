#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

const string FILE_SESSION_HISTORY = "apps/data/session_results.txt";

struct RecordSesi {
    string tanggal;
    string jam_mulai;
    string habit;
    string sub_habit;
    string template_timer;
    int durasi_rencana;
    int waktu_aktual;
    string status_penyelesaian;
    string catatan;
};

vector<RecordSesi> bacaSemuaHasilSesi() {
    vector<RecordSesi> data;
    ifstream file(FILE_SESSION_HISTORY);

    if (!file.is_open()) {
        return data;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        stringstream ss(line);
        string token;
        RecordSesi item;

        getline(ss, item.tanggal, '|');
        getline(ss, item.jam_mulai, '|');
        getline(ss, item.habit, '|');
        getline(ss, item.sub_habit, '|');
        getline(ss, item.template_timer, '|');

        getline(ss, token, '|');
        item.durasi_rencana = token.empty() ? 0 : stoi(token);

        getline(ss, token, '|');
        item.waktu_aktual = token.empty() ? 0 : stoi(token);

        getline(ss, item.status_penyelesaian, '|');
        getline(ss, item.catatan);

        data.push_back(item);
    }

    return data;
}

void tampilkanSatuRecordSesi(const RecordSesi& item, int nomor) {
    int menit = item.waktu_aktual / 60;
    int detik = item.waktu_aktual % 60;

    cout << "--------------------------------------------------\n";
    cout << nomor << ". " << item.tanggal << " " << item.jam_mulai << "\n";
    cout << "   Habit      : " << item.habit << "\n";
    cout << "   Sub-Habit  : " << item.sub_habit << "\n";
    cout << "   Template   : " << item.template_timer << "\n";
    cout << "   Durasi     : " << item.durasi_rencana << " menit\n";
    cout << "   Aktual     : " << menit << " menit " << detik << " detik\n";
    cout << "   Status     : " << item.status_penyelesaian << "\n";

    if (!item.catatan.empty()) {
        cout << "   Catatan    : " << item.catatan << "\n";
    }
}

void tampilkanRiwayatSesi() {
    system("cls");
    cout << "==================================================\n";
    cout << "                RIWAYAT SESI FOKUS                \n";
    cout << "==================================================\n\n";

    vector<RecordSesi> data = bacaSemuaHasilSesi();

    if (data.empty()) {
        cout << "Belum ada riwayat sesi.\n";
        cout << "\nTekan ENTER untuk kembali...";
        cin.ignore();
        return;
    }

    int nomor = 1;
    for (int i = static_cast<int>(data.size()) - 1; i >= 0; --i) {
        tampilkanSatuRecordSesi(data[i], nomor);
        nomor++;
    }

    cout << "--------------------------------------------------\n";
    cout << "\nTekan ENTER untuk kembali...";
    cin.ignore();
}

void tampilkanStatistikSesi() {
    system("cls");
    cout << "==================================================\n";
    cout << "                STATISTIK SESI FOKUS              \n";
    cout << "==================================================\n\n";

    vector<RecordSesi> data = bacaSemuaHasilSesi();

    if (data.empty()) {
        cout << "Belum ada data statistik sesi.\n";
        cout << "\nTekan ENTER untuk kembali...";
        cin.ignore();
        return;
    }

    int total = static_cast<int>(data.size());
    int selesai = 0;
    int totalDetik = 0;

    for (int i = 0; i < total; i++) {
        totalDetik += data[i].waktu_aktual;
        if (data[i].status_penyelesaian == "Selesai") {
            selesai++;
        }
    }

    int gagal = total - selesai;
    int persenSukses = (total > 0) ? (selesai * 100 / total) : 0;

    cout << "Total sesi             : " << total << "\n";
    cout << "Sesi selesai           : " << selesai << "\n";
    cout << "Sesi berhenti di tengah: " << gagal << "\n";
    cout << "Persentase sukses      : " << persenSukses << "%\n";
    cout << "Total waktu fokus      : " << totalDetik / 60 << " menit\n";

    cout << "\nTekan ENTER untuk kembali...";
    cin.ignore();
}

void menuRiwayatSesi() {
    bool selesai = false;

    while (!selesai) {
        system("cls");
        cout << "==================================================\n";
        cout << "              RIWAYAT & STATISTIK FOKUS           \n";
        cout << "==================================================\n\n";
        cout << "1. Lihat Riwayat Sesi\n";
        cout << "2. Lihat Statistik Sesi\n";
        cout << "0. Kembali\n";
        cout << "\nMasukkan pilihan Anda: ";

        int pilihan;
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                tampilkanRiwayatSesi();
                break;
            case 2:
                tampilkanStatistikSesi();
                break;
            case 0:
                selesai = true;
                break;
            default:
                cout << "Pilihan tidak valid.\n";
                cout << "Tekan ENTER untuk lanjut...";
                cin.ignore();
                break;
        }
    }
}
