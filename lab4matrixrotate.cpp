#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of square matrix (N x N): ";
    cin >> n;

    int matrix[50][50];   // assuming max size 50, you can adjust as needed

    cout << "Enter elements of the matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    cout<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<< matrix[i][j]<<" ";

        }
        cout<<endl;
    }
    // Step 1: Transpose
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Step 2: Reverse each row
    for(int i = 0; i < n; i++) {
        int start = 0, end = n - 1;
        while(start < end) {
            int temp = matrix[i][start];
            matrix[i][start] = matrix[i][end];
            matrix[i][end] = temp;
            start++;
            end--;
        }
    }

    cout << "\nMatrix after 90 degree clockwise rotation:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
