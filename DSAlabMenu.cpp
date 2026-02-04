#include <iostream>
using namespace std;

int main() {
    int mainChoice;
    int data[10] = {2, 5, 8, 1, 9};       // unsorted data
    int data2[10] = {1, 4, 5, 5, 6};      // sorted data
    int n = 10;
    int lb = 0;                           // always start index 0
    int item;
    int unsortedUb = 4;                   // current end of unsorted array
    int sortedUb = 4;                     // current end of sorted array
    int ub;
    do {
        cout << "\nMENU" << endl;
        cout << "1. Linear Search" << endl;
        cout << "2. Binary Search" << endl;
        cout << "3. Insertion" << endl;
        cout << "4. Deletion" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice) {

        case 1: {  // Linear Search
            int choice2;
            cout << "\n1. Unsorted Array" << endl;
            cout << "2. Sorted Array" << endl;
            cout << "Enter your choice: ";
            cin >> choice2;

            if (choice2 == 1) {
                cout << "Unsorted array: ";
                for (int i = lb; i <= unsortedUb; i++)
                    cout << data[i] << " ";
                cout << endl;

                cout << "Enter element to search: ";
                cin >> item;

                if (unsortedUb == -1) {
                    cout << "UNDERFLOW" << endl;
                } else {
                    int count = 0;
                    for (int i = lb; i <= unsortedUb; i++) {
                        if (data[i] == item) {
                            cout << item << " found at index " << i << endl;
                            count++;
                        }
                    }
                    if (count == 0)
                        cout << item << " not found" << endl;
                    else
                        cout << item << " repeats " << count << " times" << endl;
                }

            } else if (choice2 == 2) {
                cout << "Sorted array: ";
                for (int i = lb; i <= sortedUb; i++)
                    cout << data2[i] << " ";
                cout << endl;

                cout << "Enter element to search: ";
                cin >> item;

                int count = 0;
                for (int i = lb; i <= sortedUb; i++) {
                    if (data2[i] == item) {
                        cout << item << " found at index " << i << endl;
                        count++;
                    } else if (data2[i] > item) {
                        break;
                    }
                }

                if (count == 0)
                    cout << item << " not found" << endl;
                else
                    cout << item << " repeats " << count << " times" << endl;
            } else {
                cout << "Invalid array choice!" << endl;
            }

            break;
        }

      case 2: {  // Binary Search
    int count = 0;

    lb = 0;                    // reset lower bound
    ub = sortedUb;             // reset upper bound to cover full array

    if (ub == -1) {
        cout << "UNDERFLOW";
        break;
    }

    for (int i = lb; i <= ub; i++) {
        cout << data2[i] << " ";
    }
    cout << endl;

    cout << "ENTER ITEM TO SEARCH" << endl;
    cin >> item;

    int mid;
    bool found = false;

    while (lb <= ub) {
        mid = (lb + ub) / 2;

        if (data2[mid] == item) {
            cout << "ITEM FOUND AT INDEX: " << mid << endl;
            found = true;

            count = 1;

            int left = mid - 1;
            while (left >= 0 && data2[left] == item) {
                cout << "ITEM FOUND AT INDEX: " << left << endl;
                count++;
                left--;
            }

            int right = mid + 1;
            while (right <= sortedUb && data2[right] == item) {
                cout << "ITEM FOUND AT INDEX: " << right << endl;
                count++;
                right++;
            }
            break;
        }
        else if (item < data2[mid]) {
            ub = mid - 1;
        }
        else {
            lb = mid + 1;
        }
    }

    if (!found)
        cout << "ITEM NOT FOUND" << endl;
    else
        cout << "ITEM REPEATED " << count << " TIMES" << endl;

    break;
}


        case 3: {  // Insertion
            int choice3;
            cout << "1. Sorted Array" << endl;
            cout << "2. Unsorted Array" << endl;
            cout << "Enter your choice: ";
            cin >> choice3;

            if (choice3 == 1) { // Sorted insertion
                if (sortedUb == n - 1) {
                    cout << "OVERFLOW" << endl;
                    break;
                }

                cout << "Sorted array: ";
                for (int i = lb; i <= sortedUb; i++) {
                    cout << data2[i] << " ";
                }
                cout << endl;

                cout << "Enter item to insert in sorted array: ";
                cin >> item;

                int loc = sortedUb + 1;
                for (int i = lb; i <= sortedUb; i++) {
                    if (item < data2[i]) {
                        loc = i;
                        break;
                    }
                }

                for (int j = sortedUb; j >= loc; j--) {
                    data2[j + 1] = data2[j];
                }

                data2[loc] = item;
                sortedUb++;

                cout << "After insertion: ";
                for (int i = lb; i <= sortedUb; i++) {
                    cout << data2[i] << " ";
                }
                cout << endl;

            } else if (choice3 == 2) { // Unsorted insertion
                if (unsortedUb == n - 1) {
                    cout << "OVERFLOW" << endl;
                    break;
                }

                cout << "Unsorted array: ";
                for (int i = lb; i <= unsortedUb; i++) {
                    cout << data[i] << " ";
                }
                cout << endl;

                cout << "Enter item to insert in unsorted array: ";
                cin >> item;

                unsortedUb++;
                data[unsortedUb] = item;

                cout << "After insertion: ";
                for (int i = lb; i <= unsortedUb; i++) {
                    cout << data[i] << " ";
                }
                cout << endl;
            } else {
                cout << "Invalid choice for insertion!" << endl;
            }

            break;
        }

        case 4: {  // Deletion
            int choice;
            cout << "1. Sorted Array" << endl;
            cout << "2. Unsorted Array" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1) {
                if (sortedUb == -1) {
                    cout << "UNDERFLOW" << endl;
                    break;
                }

                cout << "Sorted array: ";
                for (int i = lb; i <= sortedUb; i++) {
                    cout << data2[i] << " ";
                }
                cout << endl;

                cout << "Enter item to delete: ";
                cin >> item;

                bool found = false;
                for (int i = lb; i <= sortedUb; i++) {
                    if (item < data2[i]) {
                        cout << "Item does not exist" << endl;
                        found = true;
                        break;
                    } else if (item == data2[i]) {
                        for (int j = i; j < sortedUb; j++) {
                            data2[j] = data2[j + 1];
                        }
                        sortedUb--;
                        cout << "Deleted " << item << endl;
                        cout << "Array after deletion: ";
                        for (int k = lb; k <= sortedUb; k++) {
                            cout << data2[k] << " ";
                        }
                        cout << endl;
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Item not found" << endl;
                }

            } else if (choice == 2) {
                if (unsortedUb == -1) {
                    cout << "UNDERFLOW" << endl;
                    break;
                }

                cout << "Unsorted array: ";
                for (int i = lb; i <= unsortedUb; i++) {
                    cout << data[i] << " ";
                }
                cout << endl;

                cout << "Enter item to delete: ";
                cin >> item;

                bool found = false;
                for (int i = lb; i <= unsortedUb; i++) {
                    if (data[i] == item) {
                        for (int j = i; j < unsortedUb; j++) {
                            data[j] = data[j + 1];
                        }
                        unsortedUb--;
                        cout << "Deleted " << item << " from index " << i << endl;
                        cout << "Array after deletion: ";
                        for (int k = lb; k <= unsortedUb; k++) {
                            cout << data[k] << " ";
                        }
                        cout << endl;
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Item not found" << endl;
                }

            } else {
                cout << "Invalid choice for deletion!" << endl;
            }

            break;
        }

        case 5:
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (mainChoice != 5);

    return 0;
}
