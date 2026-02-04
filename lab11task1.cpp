
#include <iostream>
using namespace std;

const int SIZE = 20;
int Stack[SIZE];
int top = -1;

bool isEmpty() {
    return top == -1;
}

void push(int value) {
    if (top == SIZE - 1) {
        cout << "Overflow!" << endl;
        return;
    }
    top++;
    Stack[top] = value;
}

void pop() {
    if (isEmpty()) {
        cout << "Underflow" << endl;
        return;
    }
    cout << "The popped element is " << Stack[top] << endl;
    top--;
}

void peek() {
    if (isEmpty()) {
        cout << "Underflow" << endl;
        return;
    }
    cout << "The peek element is " << Stack[top] << endl;
}

void display() {
    if (isEmpty()) {
        cout << "Underflow" << endl;
        return;
    }

    for (int i = top; i >= 0; i--) {
        cout << Stack[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, value;

    while (true) {
        cout<<"-----------------------"<<endl;
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
            cout << "Invalid Choice!";
        }
    }
}
