#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <conio.h>
#include <iomanip>
#include <cstdlib>
#include "../utils/data_structure.cpp"
#include "../feature/habbits.cpp"
using namespace std;

struct PomodoroSession {
    string nama;
    int durasi;  // dalam menit
    string deskripsi;
};

struct ActivityRecord {
    string nama_sesi;
    int waktu_aktual;  // dalam detik
    string catatan;
    string waktu_mulai;
};

