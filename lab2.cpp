#include <iostream>
using namespace std;

int main() {
    int mainChoice;
    int data[5] = {2, 3, 3, 3, 2};        //unsorted data
    int data2[5] = {1, 4, 5, 5, 6};       //sorted data
    do {
        cout << "\nMENU" << endl;
        cout << "1. Linear Search" << endl;
        cout << "2. Insertion"<<endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
        case 1: {                                           //main case 1
            int choice2;
            cout << "\n1. Unsorted Array" << endl;
            cout << "2. Sorted Array" << endl;
            cout << "Enter your choice: ";
            cin >> choice2;

            switch (choice2) {
            case 1: { // Unsorted

                int lb = 0, ub = 4;

                cout << "Array elements: ";
                for (int i = lb; i <= ub; i++)
                    cout << data[i] << " ";
                cout << endl;

                int item;
                cout << "Enter element to search: ";
                cin >> item;

                if (ub == -1) {
                    cout << "UNDERFLOW" << endl;
                } else {
                    int count = 0;
                    for (int i = lb; i <= ub; i++) {
                        if (item == data[i]) {
                            cout << data[i] << " found at index " << i << endl;
                            count++;
                        }
                    }
                    if (count == 0)
                        cout << item << " not found" << endl;
                    else
                        cout << item << " repeats " << count << " times" << endl;
                }
                break;
            }

            case 2: { // Sorted

                int lb = 0, ub = 4;

                cout << "Array elements: ";
                for (int i = lb; i <= ub; i++)
                    cout << data2[i] << " ";
                cout << endl;

                int item;
                cout << "Enter element to search: ";
                cin >> item;

                int count2 = 0;
                for (int i = lb; i <= ub; i++) {
                    if (data2[i] == item) {
                        cout << item << " found at index " << i << endl;
                        count2++;
                    } else if (data2[i] > item) {
                        break; // no need to continue in sorted array
                    }
                }

                if (count2 == 0)
                    cout << item << " not found" << endl;
                else
                    cout << item << " repeats " << count2 << " times" << endl;

                break;
            }

            default:
                cout << "Invalid choice for array type!" << endl;
            }

            break;
        }
        case 2:                                                 //main case 2
            int choice3;
            cout<<"1. sorted"<<endl;
            cout<<"2. unsorted"<<endl;
            cin>>choice3;
            switch(choice3){
            case 2:
            int n=sizeof(data2);
            int lb=0; int ub=4;
            if(ub==n-1){
                cout<<"Underflow"<<endl;
                break;
            }
            break;

            }
        break;
        case 3:                                                 //main case 3
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice in main menu!" << endl;
        }

    } while (mainChoice != 2);

    return 0;
}
