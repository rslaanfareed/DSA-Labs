#include <iostream>
using namespace std;

const int SIZE=5;
int arr[SIZE];
int frontIndex = -1;
int rearIndex = -1;


bool isFull() {
    if ((frontIndex == 0 && rearIndex == SIZE - 1) || (rearIndex + 1 == frontIndex))
        return true;
    return false;
}


bool isEmpty() {
    return frontIndex == -1;
}


void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full" << endl;
        return;
    }

    if (frontIndex == -1) {
        frontIndex = rearIndex = 0;
    }
    else if (rearIndex == SIZE - 1) {
        rearIndex = 0;
    }
    else {
        rearIndex++;
    }

    arr[rearIndex] = value;
    cout << "Inserted " << value << endl;
}


void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }

    int element = arr[frontIndex];
    cout << "Deleted -> " << element << endl;

    if (frontIndex == rearIndex) {
        frontIndex = rearIndex = -1;
    }
    else if (frontIndex == SIZE - 1) {
        frontIndex = 0;
    }
    else {
        frontIndex++;
    }
}


void peek() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "The peek element is " << arr[frontIndex] << endl;
}


void display() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "Front index: " << frontIndex << endl;
    cout << "Items: ";

    if (frontIndex <= rearIndex) {
        for (int i = frontIndex; i <= rearIndex; i++)
            cout << arr[i] << "  ";
    }
    else {
        for (int i = frontIndex; i < SIZE; i++)
            cout << arr[i] << "  ";
        for (int i = 0; i <= rearIndex; i++)
            cout << arr[i] << "  ";
    }

    cout << endl;
    cout << "Rear index: " << rearIndex << endl;
}

// Main Menu --------------------
int main() {
    int choice, value;

    while (true) {
        cout << "--------------Main Menu-----------" << endl;
        cout << "1. enqueue" << endl;
        cout << "2. dequeue" << endl;
        cout << "3. Traversing" << endl;
        cout << "4. Peek element in queue" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to be inserted: ";
                cin >> value;
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                peek();
                break;

            case 5:
                cout << "Exit" << endl;
                return 0;

            default:
                cout << "Invalid choice" << endl;
        }

        cout << endl;
    }
}
