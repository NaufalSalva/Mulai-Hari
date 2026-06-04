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
    int durai;
    string mood;
};

struct StackNode {
    LogAktivitasNode data;
    StackNode* next;
};

struct User {
    string username;
    string email;
    string password;
};

#endif