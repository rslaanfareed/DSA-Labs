#include<iostream>
 using namespace std;

  int main() {
    int arr[5] = {4, 2, 0, 11, 9};
    int n = 5;

    cout << "Original Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;


    //ascending
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n-1; j++) {
            if (arr[j]>arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Sorted Array in Ascending Order: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;


    //descending
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Sorted Array in Descending Order: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
