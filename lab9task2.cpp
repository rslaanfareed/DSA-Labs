#include<iostream>
#include<string>
using namespace std;

struct node {
    int stationNo;
    string stationName;
    float distance;
    node* link;
};

node* start = NULL;

//_____________________________________________
void traverse() {
    if (start == NULL) {
        cout << "UNDERFLOW" << endl;
        return;
    }
    node* i = start;
    while (i != NULL) {
        cout << "___________________________" << endl;
        cout << "Station No: " << i->stationNo << endl;
        cout << "Station Name: " << i->stationName << endl;
        cout << "Distance from previous: " << i->distance << " km" << endl;
        i = i->link;
    }
}
//____________________________________________________
void insertion(int stationNo, string stationName, float distance) {
    node* newnode = new node;
    newnode->stationNo = stationNo;
    newnode->stationName = stationName;
    newnode->distance = distance;
    newnode->link = NULL;

    if (start == NULL || start->stationNo > stationNo) {
        newnode->link = start;
        start = newnode;
    } else {
        node* current = start;
        while (current->link != NULL && current->link->stationNo < stationNo) {
            current = current->link;
        }
        newnode->link = current->link;
        current->link = newnode;
    }
    cout << "STATION ADDED SUCCESSFULLY" << endl;

}
//____________________________________________________
void search(int stationNo) {
    if (start == NULL) {
        cout << "UNDERFLOW" << endl;
        return;
    }
    node* i = start;
    while (i != NULL) {
        if (stationNo == i->stationNo) {
            cout << "Station found" << endl;
            cout << "Station No: " << i->stationNo << endl;
            cout << "Station Name: " << i->stationName << endl;
            cout << "Distance from previous: " << i->distance << " km" << endl;
            return;
        }
        i = i->link;
    }
    cout << "STATION NOT FOUND" << endl;
}
//______________________________________________________
void deleteStation(int stationNo) {
    if (start == NULL) {
        cout << "UNDERFLOW" << endl;
        return;
    }

    node* curr;
    node* prev = NULL;
    node* i = start;

    //delete from start
    if (stationNo == start->stationNo) {
        curr = start;
        start = start->link;
        delete curr;
        cout << "Station deleted successfully" << endl;
        return;
    }


    prev = start;
    i = start->link;

    while (i != NULL) {
        if (stationNo == i->stationNo) {
            curr = i;
            prev->link = i->link;
            delete curr;
            cout << "Station deleted successfully" << endl;
            return;
        }
        else if (stationNo < i->stationNo) {
            break;
        }
        prev = i;
        i = i->link;
    }

    cout << "Station not found" << endl;
}
//______________________________________________________
int main() {
    int stationNo;
    string stationName;
    float distance;

    while (true) {
            cout<<"\n--------------------------\n";
        cout << "\n1. Add station\n2. Display all stations\n3. Delete station by number\n4. Search station by number\n5. Exit" << endl;
        cout<<"\n____________________________\n";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nEnter Station No, Name, and Distance (km): " << endl;
            cin >> stationNo;
            cin.ignore();
            getline(cin, stationName);
            cin >> distance;
            insertion(stationNo, stationName, distance);
            break;

        case 2:
            traverse();
            break;

        case 3:
            cout << "Enter Station No to delete: ";
            cin >> stationNo;
            deleteStation(stationNo);
            break;

        case 4:
            cout << "Enter Station No to search: ";
            cin >> stationNo;
            search(stationNo);
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid choice" << endl;
        }
    }
}
