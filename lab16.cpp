#include <iostream>
using namespace std;

const int TABLE_SIZE = 20;

int studentId[TABLE_SIZE];
string studentName[TABLE_SIZE];
string studentPhone[TABLE_SIZE];

// initialize hash table--------------------
void init() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        studentId[i] = 0;
    }
}

// hash function
int getIndex(int id) {
    return id % TABLE_SIZE;
}

// check if ID already exists
bool idExists(int id) {
    int index = getIndex(id);
    int start = index;

    while (studentId[index] != 0) {
        if (studentId[index] == id) {
            return true;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == start) break;
    }

    return false;
}

// 1) Insertion----------------------
void insertRecord() {
    int id;
    string name, phone;

    cout << "Enter Student ID: ";
    cin >> id;

    if (idExists(id)) {
        cout << "Student ID already exists. Cannot insert.\n";
        return;
    }

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Telephone: ";
    cin >> phone;

    int index = getIndex(id);

    while (studentId[index] != 0) {
        index = (index + 1) % TABLE_SIZE;
    }

    studentId[index] = id;
    studentName[index] = name;
    studentPhone[index] = phone;

    cout << phone << " inserted at " << index << endl;
}

// 2) Deletion
void deleteRecord() {
    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;

    int index = getIndex(id);
    int start = index;

    while (studentId[index] != 0) {
        if (studentId[index] == id) {
            studentId[index] = 0;
            studentName[index] = "";
            studentPhone[index] = "";
            cout << "Record Deleted successfully\n";
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == start) break;
    }

    cout << "Record not found\n";
}

// 3) Traversing
void displayRecords() {
    cout << "Name\t\tTelephone\n";
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (studentId[i] != 0) {
            cout << studentName[i] << "\t\t"
                 << studentPhone[i] << endl;
        }
    }
}

// 4) Searching
void searchRecord() {
    int id;
    cout << "Enter Student ID to search: ";
    cin >> id;

    int index = getIndex(id);
    int start = index;

    while (studentId[index] != 0) {
        if (studentId[index] == id) {
            cout << "Record found\n";
            cout << "Name: " << studentName[index] << endl;
            cout << "Telephone : " << studentPhone[index] << endl;
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == start) break;
    }

    cout << "Record not found\n";
}

// 5) Updation
void updateRecord() {
    int id;
    cout << "Enter Student ID to update: ";
    cin >> id;

    int index = getIndex(id);
    int start = index;

    while (studentId[index] != 0) {
        if (studentId[index] == id) {
            cout << "Enter the new telephone number: ";
            cin >> studentPhone[index];
            cout << "Record Updated successfully\n";
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == start) break;
    }

    cout << "Record not found\n";
}

int main() {
    init();
    int choice;

    do {
        cout << "\n1) Insertion\n2) Deletion\n3) Traversing\n4) Searching\n5) Updation\n6) Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insertRecord(); break;
            case 2: deleteRecord(); break;
            case 3: displayRecords(); break;
            case 4: searchRecord(); break;
            case 5: updateRecord(); break;
            case 6:
                cout << "=== Session Ended. Please Run the code again ===\n";
                break;
            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 6);

    return 0;
}
