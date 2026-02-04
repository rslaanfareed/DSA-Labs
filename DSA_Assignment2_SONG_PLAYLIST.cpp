#include<iostream>
using namespace std;

struct node {
    int songID;
    string title;
    float duration;
    node* link;
};

node* tail = nullptr;

//---------------------------------------
void traverse() {
    if (tail == nullptr) {
        cout << "EMPTY" << endl;
        return;
    }
    node* head = tail->link;
    node* curr = head;
    do {
        cout << "_______________________" << endl;
        cout << "ID: " << curr->songID
             << "\nTITLE: " << curr->title
             << "\nDuration: " << curr->duration << " mins" << endl;
        curr = curr->link;
    } while (curr != head);
}

//---------------------------------------
void insertAtBeginning(int id, string title, float duration) {
    node* newnode = new node();
    newnode->songID = id;
    newnode->title = title;
    newnode->duration = duration;

    if (tail == nullptr) {
        newnode->link = newnode;
        tail = newnode;
        cout << "SONG INSERTED AS FIRST SONG" << endl;
        return;
    }
    node* head = tail->link;
    newnode->link = head;
    tail->link = newnode;
    cout << "SONG INSERTED AT THE BEGINNING" << endl;
}

//-----------------------------------------------
void insertAtEnd(int id, string title, float duration) {
    node* newnode = new node();
    newnode->songID = id;
    newnode->title = title;
    newnode->duration = duration;

    if (tail == nullptr) {
        newnode->link = newnode;
        tail = newnode;
        cout << "SONG INSERTED AS FIRST SONG" << endl;
        return;
    }

    node* head = tail->link;
    newnode->link = head;
    tail->link = newnode;
    tail = newnode;
    cout << "SONG INSERTED AT THE END" << endl;
}

//-----------------------------------------------
void searchSong(string title) {
    if (tail == nullptr) {
        cout << "Playlist is empty" << endl;
        return;
    }

    node* head = tail->link;
    node* curr = head;

    do {
        if (curr->title == title) {
            cout << "_____Song found_____\n";
            cout << "ID: " << curr->songID
                 << "\nTitle: " << curr->title
                 << "\nDuration: " << curr->duration << " mins\n";
            return;
        }
        curr = curr->link;
    } while (curr != head);

    cout << "Song not found" << endl;
}

//-----------------------------------------------
void deletesong(string title) {
    if (tail == nullptr) { // Empty list
        cout << "Empty playlist" << endl;
        return;
    }

    node* head = tail->link;
    node* prev = tail;   // Start prev at tail to handle deleting head easily
    node* curr = head;

    do {
        if (curr->title == title) {
            prev->link = curr->link;  // Remove curr from list
            if (curr == tail) tail = prev; // Update tail if needed
            if (curr == head && curr == tail) tail = nullptr; // List becomes empty
            delete curr;
            cout << "Song deleted successfully" << endl;
            return;
        }
        prev = curr;
        curr = curr->link;
    } while (curr != head);

    cout << "Song not found" << endl;
}


//-----------------------------------------------
void countSongs() {
    if (tail == nullptr) {
        cout << "Playlist is empty" << endl;
        return;
    }

    node* head = tail->link;
    node* curr = head;
    int count = 0;

    do {
        count++;
        curr = curr->link;
    } while (curr != head);

    cout << "Total songs: " << count << endl;
}

//-----------------------------------------------
void insertAtLoc(int songID, string title, float duration, int loc) {
    node* newnode = new node();
    newnode->songID = songID;
    newnode->title = title;
    newnode->duration = duration;

    // Empty list
    if (tail == nullptr) {
        newnode->link = newnode;
        tail = newnode;
        cout << "Song inserted as first song\n";
        return;
    }

    node* head = tail->link;

    // Insert at beginning
    if (loc == 1) {
        newnode->link = head;
        tail->link = newnode;
        cout << "Song inserted at beginning\n";
        return;
    }

    // Traverse to position
    node* curr = head;
    for (int count = 1; count < loc - 1 && curr->link != head; count++)
        curr = curr->link;

    // Insert new node
    newnode->link = curr->link;
    curr->link = newnode;

    // Update tail if inserted at end
    if (curr == tail) tail = newnode;

    cout << "Song inserted at position " << loc << "\n";
}


//-----------------------------------------------
int main() {
    int id, choice, position;
    string title;
    float duration;

    while (true) {
        cout << "_______________________" << endl;
        cout << "1. Traverse\n"
             << "2. Insert at beginning\n"
             << "3. Insert at end\n"
             << "4. Search by title\n"
             << "5. Delete by title\n"
             << "6. Count songs\n"
             << "7. Insert at specific position\n"
             << "8. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                traverse();
                break;
            case 2:
                cout << "Enter song details (id, title, duration):\n";
                cin >> id;
                cin.ignore();
                getline(cin, title);
                cin >> duration;
                insertAtBeginning(id, title, duration);
                break;
            case 3:
                cout << "Enter song details (id, title, duration):\n";
                cin >> id;
                cin.ignore();
                getline(cin, title);
                cin >> duration;
                insertAtEnd(id, title, duration);
                break;
            case 4:
                cin.ignore();
                cout << "Enter song title to search:\n";
                getline(cin, title);
                searchSong(title);
                break;
            case 5:
                cin.ignore();
                cout << "Enter song title to delete:\n";
                getline(cin, title);
                deletesong(title);
                break;
            case 6:
                countSongs();
                break;
            case 7:
                cout << "Enter song details (id, title, duration, position):\n";
                cin >> id;
                cin.ignore();
                getline(cin, title);
                cin >> duration >> position;
                insertAtLoc(id, title, duration, position);
                break;
            case 8:
                cout << "Exiting playlist manager..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }
}
