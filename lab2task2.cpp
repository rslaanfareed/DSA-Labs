#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int arr[10] = {1, 3, 4, 5, 9, 12, 15, 16, 23, 25};
    int n = 10;

    // Traverse array once at start
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout <<endl;

    int choice;

    do {
        cout << "\nMENU\n";
        cout << "1. Print even numbers\n";
        cout << "2. Print odd numbers\n";
        cout << "3. Print prime numbers\n";
        cout << "4. Print perfect square numbers\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cout << "\n";

        if (choice == 1) {
            cout << "Even numbers: ";
            for (int i = 0; i < n; i++) {
                if (arr[i] % 2 == 0)
                    cout << arr[i] << " ";
            }
            cout << "\n";
        }
        else if (choice == 2) {
            cout << "Odd numbers: ";
            for (int i = 0; i < n; i++) {
                if (arr[i] % 2 != 0)
                    cout << arr[i] << " ";
            }
            cout << "\n";
        }
        else if (choice == 3) {
            cout << "Prime numbers: ";
            for (int i = 0; i < n; i++) {
                int num = arr[i];
                bool prime = true;
                if (num < 2) prime = false;
                for (int j = 2; j <=num/2; j++) {
                    if (num % j == 0) {
                        prime = false;
                        break;
                    }
                }
                if (prime) cout << num << " ";
            }
            cout << "\n";
        }
        else if (choice == 4) {
            cout << "Perfect square numbers: ";
            for (int i = 0; i < n; i++) {
                int root = sqrt(arr[i]);
                if (root * root == arr[i])
                    cout << arr[i] << " ";
            }
            cout << "\n";
        }
        else if (choice == 5) {
            cout << "Exiting program...\n";
        }
        else {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
