#include <iostream>
#include <string>
using namespace std;

struct Node {
    string title;
    string artist;
    int link;
};

const int SIZE = 10;
Node Data[SIZE];
int Start = -1;
int Avail = 0;


void insertSong() {
    if (Avail == -1) {
        cout << "Overflow! No space left in playlist.\n";
        return;
    }

    int loc = Avail;
    Avail = Data[Avail].link;

    cin.ignore();
    cout << "Enter song title: ";
    getline(cin, Data[loc].title);

    cout << "Enter artist name: ";
    getline(cin, Data[loc].artist);

    Data[loc].link = Start;
    Start = loc;

    cout << "Song inserted successfully!\n";
}


void displayPlaylist() {
    if (Start == -1) {
        cout << "Playlist is empty.\n";
        return;
    }

    cout << "\n--- Playlist ---\n";
    int i = Start;
    while (i != -1) {
        cout << "title: " << Data[i].title << "\n";
        cout << "artist: " << Data[i].artist << "\n";
        cout << "link: " << Data[i].link << "\n\n";
        i = Data[i].link;
    }
}


void deleteSong() {
    if (Start == -1) {
        cout << "Underflow! Playlist is empty.\n";
        return;
    }

    cin.ignore();
    string target;
    cout << "Enter title to delete: ";
    getline(cin, target);

    //delete from start
    if (Data[Start].title == target) {
        int loc = Start;
        Start = Data[Start].link;
        Data[loc].link = Avail;
        Avail = loc;
        cout << "Song deleted successfully!\n";
        return;
    }

    //delete from middle or end
    int prev = Start;
    int i = Data[Start].link;
    while (i != -1) {
        if (Data[i].title == target) {
            int loc = i;
            Data[prev].link = Data[i].link;
            Data[loc].link = Avail;
            Avail = loc;
            cout << "Song deleted successfully!\n";
            return;
        }
        prev = i;
        i = Data[i].link;
    }

    cout << "Song not found in playlist.\n";
}


void searchByArtist() {
    if (Start == -1) {
        cout << "Playlist is empty.\n";
        return;
    }

    cin.ignore();
    string artistSearch;
    cout << "Enter artist name: ";
    getline(cin, artistSearch);

    bool found = false;
    cout << "\nSongs by " << artistSearch << ":\n";
    int i = Start;
    while (i != -1) {
        if (Data[i].artist == artistSearch) {
            cout << "- " << Data[i].title << "\n";
            found = true;
        }
        i = Data[i].link;
    }

    if (!found)
        cout << "No songs found by " << artistSearch << ".\n";
}

int main() {

    for (int i = 0; i < SIZE - 1; i++) {
        Data[i].link = i + 1;
    }
    Data[SIZE - 1].link = -1;
    Avail = 0;

    int choice;
    while (true) {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Add New Song\n";
        cout << "2. Display Playlist\n";
        cout << "3. Delete Song by Title\n";
        cout << "4. Search Songs by Artist\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insertSong();
                break;
            case 2:
                displayPlaylist();
                break;
            case 3:
                deleteSong();
                break;
            case 4:
                searchByArtist();
                break;
            case 5:
                cout << "program exit\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
