#include <iostream>
#include <vector>
using namespace std;

struct Student {
    int roll;
    string name;
    string cls;
    string contact;
};

const int TABLE_SIZE = 50;   // can be bigger for real project
vector<vector<Student>> table(TABLE_SIZE);

// simple hash function
int hashFunc(int roll) {
    return roll % TABLE_SIZE;
}

// insert student
void addStudent() {
    Student s;
    cout << "Enter Roll Number: ";
    cin >> s.roll;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, s.name);

    cout << "Enter Class: ";
    getline(cin, s.cls);

    cout << "Enter Contact: ";
    getline(cin, s.contact);

    int idx = hashFunc(s.roll);
    table[idx].push_back(s);

    cout << "Student Added Successfully!\n\n";
}

// search student
void searchStudent() {
    int roll;
    cout << "Enter Roll Number to Search: ";
    cin >> roll;

    int idx = hashFunc(roll);

    for (auto &st : table[idx]) {
        if (st.roll == roll) {
            cout << "---- Student Found ----\n";
            cout << "Name: " << st.name << endl;
            cout << "Class: " << st.cls << endl;
            cout << "Contact: " << st.contact << endl;
            cout << "-----------------------\n\n";
            return;
        }
    }

    cout << "Student Not Found!\n\n";
}

// display whole table
void displayAll() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "Bucket " << i << ": ";
        if (table[i].empty()) {
            cout << "Empty\n";
            continue;
        }

        cout << endl;
        for (auto &st : table[i]) {
            cout << "  Roll: " << st.roll
                 << " | Name: " << st.name
                 << " | Class: " << st.cls
                 << " | Contact: " << st.contact << endl;
        }
    }
    cout << endl;
}

int main() {
    while (true) {
        cout << "===== SCHOOL MANAGEMENT (HASH TABLE) =====\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student\n";
        cout << "3. Display All Students\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                searchStudent();
                break;

            case 3:
                displayAll();
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice!\n\n";
        }
    }
}
