#include<iostream>
using namespace std;

struct node {
    int data;
    node* flink;
    node* blink;
};

node* head = nullptr;
node* tail = nullptr;

//----------------------------------------------------
void traverse() {
    if(head == nullptr) {
        cout << "UNDERFLOW" << endl;
        return;
    }
    cout << "-------" << endl;
    node* i = head;
    while(i != nullptr) {
        cout << i->data << endl;
        i = i->flink;
    }
}

//----------------------------------------------------
void sortedInsertion(int item) {
    node* newnode = new node;
    newnode->data = item;
    newnode->flink = nullptr;
    newnode->blink = nullptr;

    // Empty list
    if(head == nullptr) {
        head = tail = newnode;
        return;
    }

    // Insert at start
    if(item < head->data) {
        newnode->flink = head;
        head->blink = newnode;
        head = newnode;
        return;
    }

    // Middle insertion
    node* i = head->flink;
    while(i != nullptr) {
        if(item < i->data) {
            newnode->flink = i;
            newnode->blink = i->blink;
            i->blink->flink = newnode;
            i->blink = newnode;
            return;
        }
        i = i->flink;
    }

    // Insert at end
    newnode->blink = tail;
    tail->flink = newnode;
    tail = newnode;
}

//----------------------------------------------------
void sortedDeletion(int item) {

    if(head == nullptr) {
        cout << "UNDERFLOW" << endl;
        return;
    }

    // If item out of range
    if(item < head->data || item > tail->data) {
        cout << "ITEM NOT FOUND" << endl;
        return;
    }

    node* i = head;

    // Delete from head
    if(item == head->data) {
        if(head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            head = head->flink;
            head->blink = nullptr;
            delete i;
        }
        cout << "DELETED SUCCESSFULLY" << endl;
        return;
    }

    // Middle or end
    while(i != nullptr) {
        if(i->data == item) {
            if(i == tail) {
                tail = tail->blink;
                tail->flink = nullptr;
                delete i;
            } else {
                i->blink->flink = i->flink;
                i->flink->blink = i->blink;
                delete i;
            }
            cout << "DELETED SUCCESSFULLY" << endl;
            return;
        }

        if(item < i->data) {
            break;
        }

        i = i->flink;
    }

    cout << "ITEM NOT FOUND" << endl;
}

//----------------------------------------------------
void searching(int item) {
    node* i = head;
    while(i != nullptr) {
        if(i->data == item) {
            cout << "ITEM FOUND" << endl;
            return;
        }
        i = i->flink;
    }
    cout << "ITEM NOT FOUND" << endl;
}

//----------------------------------------------------
int main() {
    int item;

    while(true) {
        int choice;
        cout << "\n--------------\n";
        cout << "1. Insertion\n2. Traverse\n3. Search\n4. Delete\n0. Exit\n";
        cout << "--------------\n";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "ENTER ITEM TO INSERT\n";
                cin >> item;
                sortedInsertion(item);
                break;

            case 2:
                traverse();
                break;

            case 3:
                cout << "ENTER ITEM TO SEARCH\n";
                cin >> item;
                searching(item);
                break;

            case 4:
                cout << "ENTER ITEM TO DELETE\n";
                cin >> item;
                sortedDeletion(item);
                break;

            case 0:
                exit(0);

            default:
                cout << "INVALID CHOICE\n";
        }
    }
}
