    #ifndef DATA_STRUCTURE_CPP
    #define DATA_STRUCTURE_CPP

    #include <iostream>
    #include <string>

    using namespace std;

    struct HabitNode {
        string nama;
        HabitNode* child;
        HabitNode* sibling;
    };

    struct LogAktivitasNode {
        string hobi;
        string detail;
        int durasi;
        string mood;
    };

    struct StackNode {
        LogAktivitasNode data;
        StackNode* next;
    };

    struct AktivitasStack {
        StackNode* top;
    };

    struct User {
        int id;
        string username;
        string email;
        string password;
    };

    struct TaskNode {
        string username;
        string namaHabit;
        string namaTask;
        bool isSelesai;
        TaskNode* next;
    };

    struct TaskList {
        TaskNode* head;
    };

    #endif