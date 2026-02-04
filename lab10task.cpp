#include<iostream>
#include<string>
using namespace std;

struct node {
    int id;
    string name;
    node* flink;
    node* blink;
};

node* head = nullptr;
node* tail = nullptr;

//-------------------------------------------------------------
// Forward traverse
void traverseFwd() {
    if(head == nullptr) {
        cout << "UNDERFLOW\n";
        return;
    }
    node* i = head;
    cout<<"-------------------"<<endl;
    while(i != nullptr) {
        cout << "Channel Name: " << i->name << "  \n";
        i = i->flink;
    }
    cout << "NULL\n";
}

//-------------------------------------------------------------
// Backward traverse
void traverseBwd() {
    if(tail == nullptr) {
        cout << "UNDERFLOW\n";
        return;
    }
    node* i = tail;
    cout<<"-------------------"<<endl;
    while(i != nullptr) {
        cout << "Channel Name: " << i->name << "  \n";
        i = i->blink;
    }
    cout << "NULL\n";
}

//-------------------------------------------------------------
// Sorted insertion using channel id
void sortedInsertion() {
    node* newnode = new node;
cout<<"-------------------"<<endl;
    cout << "Enter channel no.: ";
    cin >> newnode->id;
    cout << "Enter channel name: ";
    cin.ignore();
    getline(cin, newnode->name);

    newnode->flink = nullptr;
    newnode->blink  = nullptr;

    // for Empty list
    if(head == nullptr) {

        head = tail = newnode;
        cout << "Node inserted at the start!\n";
        return;
    }

    //Insert at start
    if(newnode->id < head->id) {

        newnode->flink = head;
        head->blink = newnode;
        head = newnode;
        return;
    }

    //Insert somewhere in middle
    node* i = head->flink;
    while(i != nullptr) {
        if(newnode->id < i->id) {
            newnode->flink = i;
            newnode->blink = i->blink;
            i->blink->flink = newnode;
            i->blink = newnode;
            cout << "Node inserted at the specified location\n";
            return;
        }
        i = i->flink;
    }

    // Insert at end
    newnode->blink = tail;
    tail->flink = newnode;
    tail = newnode;
    cout << "Node inserted at the end of sorted list!\n";
}

//-------------------------------------------------------------
// Search Forward
void searchFwd() {
    int id;
    cout<<"-------------------"<<endl;
    cout << "Enter channel no.: ";
    cin >> id;

    node* i = head;
    while(i != nullptr) {
        if(i->id == id) {
            cout << "Channel Found \nID: " << i->id << "\n";
            cout << "Channel Name: " << i->name << "\n";
            return;
        }
        i = i->flink;
    }

    cout << "Channel NOT Found!\n";
}

//-------------------------------------------------------------
// Search Backward
void searchBwd() {
    int id;
    cout<<"-------------------"<<endl;
    cout << "Enter channel no.: ";
    cin >> id;

    node* i = tail;
    while(i != nullptr) {
        if(i->id == id) {
            cout << "Channel Found\nIts ID: " << i->id << "\n";
            cout << "Channel Name: " << i->name << "\n";
            return;
        }
        i = i->blink;
    }

    cout << "Channel not Found!\n";
}

//-------------------------------------------------------------
// Delete a node by channel ID
void deleteByID() {
    int id;
    cout<<"-------------------"<<endl;
    cout << "Enter channel no.: ";
    cin >> id;

    if(head == nullptr) {
        cout << "UNDERFLOW\n";
        return;
    }

    node* i = head;

    // Delete from head
    if(id == head->id) {
        if(head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            head = head->flink;
            head->blink = nullptr;
            delete i;
        }
        cout << "item deleted successfully!\n";
        return;
    }

    // for middle or end
    while(i != nullptr) {
        if(i->id == id) {
            if(i == tail) {
                tail = tail->blink;
                tail->flink = nullptr;
                delete i;
            } else {
                i->blink->flink = i->flink;
                i->flink->blink = i->blink;
                delete i;
            }
            cout << "item deleted successfully\n";
            return;
        }
        i = i->flink;
    }

    cout << "ITEM NOT FOUND\n";
}

//-------------------------------------------------------------
int main() {
    while(true) {
            cout<<"-------------------";
        cout << "\n    Main Menu\n";
        cout << "1. Add New Channel!\n";
        cout << "2. Display the entire Channels List (Forward Traversing)\n";
        cout << "3. Display the entire Channels List(Backward Traversing)\n";
        cout << "4. Search channel with Channel ID (Forward Searching)\n";
        cout << "5. Search channel with Channel ID (Backward Searching)\n";
        cout << "6. Delete Channels by ChannelID\n";
        cout << "7. Exit the menu!\n";

        cout << "Enter your choice: ";
        int ch;
        cin >> ch;

        switch(ch) {
            case 1:

                sortedInsertion();
                break;

            case 2:

                traverseFwd();
                break;

            case 3:

                traverseBwd();
                break;

            case 4:

                searchFwd();
                break;

            case 5:

                searchBwd();
                break;

            case 6:

                deleteByID();
                break;

            case 7:
                return 0;

            default:
                cout << "INVALID CHOICE!\n";
        }
    }
}
