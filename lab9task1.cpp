#include<iostream>
#include<string>
using namespace std;

struct node {
    string sport;
    string event;
    string time;
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
        cout << "Sport: " << i->sport << endl;
        cout << "Event: " << i->event << endl;
        cout << "Time: " << i->time << endl;
        i = i->link;
    }
}
//____________________________________________________
void insertion(string sport, string event, string time) {
    node* newnode = new node;
    newnode->sport = sport;
    newnode->event = event;
    newnode->time = time;
    newnode->link = start;
    start = newnode;
    cout << "INSERTION SUCCESSFUL" << endl;
}
//____________________________________________________
void search(string event) {
    if (start == NULL) {
        cout << "UNDERFLOW" << endl;
        return;
    }
    node* i = start;
    while (i != NULL) {
        if (event == i->event) {
            cout << "Event found" << endl;
            cout << "Sport: " << i->sport << endl;
            cout << "Event: " << i->event << endl;
            cout << "Time: " << i->time << endl;
            return;
        }
        i = i->link;
    }
    cout << "EVENT NOT FOUND" << endl;
}
//______________________________________________________
void deleteEvent(string event) {
    if (start == NULL) {
        cout << "UNDERFLOW" << endl;
        return;
    }

    node* temp = start;
    node* prev = NULL;


    if (temp != NULL && temp->event == event) {
        start = temp->link;
        delete temp;
        cout << "Event deleted successfully" << endl;
        return;
    }


    while (temp != NULL && temp->event != event) {
        prev = temp;
        temp = temp->link;
    }

    if (temp == NULL) {
        cout << "Event not found" << endl;
        return;
    }

    prev->link = temp->link;
    delete temp;
    cout << "Event deleted successfully" << endl;
}
//______________________________________________________
int main() {
    string sport, event, time;
    while (true) {
        cout << "\n1. Add highlight\n2. Display all highlights\n3. Delete highlight by name\n4. Search highlight by name\n5. Exit" << endl;
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nEnter sport, event and time: " << endl;
            cin.ignore();
            getline(cin, sport);
            getline(cin, event);
            getline(cin, time);
            insertion(sport, event, time);
            break;

        case 2:
            traverse();
            break;

        case 3: {
            cout << "Enter event name to delete: ";
            cin.ignore();
            getline(cin, event);
            deleteEvent(event);
            break;
        }

        case 4: {
            cout << "Enter event name to search: ";
            cin.ignore();
            getline(cin, event);
            search(event);
            break;
        }

        case 5:
            return 0;

        default:
            cout << "Invalid choice" << endl;
        }
    }
}
