
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

bool isEmpty() {
    return top == NULL;
}

void push(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    cout << value << " pushed to stack." << endl;
}

void pop() {
    if (isEmpty()) {
        cout << "underflow" << endl;
        return;
    }
    cout << top->data << " popped from stack." << endl;

    Node* loc = top;
    top = top->next;
    delete loc;
}

void peek() {
    if (isEmpty()) {
        cout << "underflow" << endl;
        return;
    }
    cout << "The peek element is " << top->data << endl;
}

void display() {
    if (isEmpty()) {
        cout << "underflow" << endl;
        return;
    }

    cout << "Stack elements: ";
    Node* temp = top;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, value;

    while (true) {
        cout << "\n1 Push in stack\n2 Pop from stack\n3 Display stack\n4 Peek element of stack\n5 Exit\n";

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to be pushed: ";
            cin >> value;
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            peek();
            break;

        case 5:
            cout << "Exit";
            return 0;

        default:
            cout << "Invalid choice!";
        }
    }
}
