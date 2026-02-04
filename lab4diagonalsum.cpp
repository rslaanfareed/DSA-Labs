#include <iostream>
using namespace std;

// Function to calculate left diagonal sum
int leftDiagonalSum(int matrix[][50], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += matrix[i][i];       // same row and column index
    }
    return sum;
}


int rightDiagonalSum(int matrix[][50], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += matrix[i][n - 1 - i];
    }
    return sum;
}

int main() {
    int n;
    int matrix[50][50];

    cout << "Enter size of square matrix (N x N): ";
    cin >> n;

    cout << "Enter elements of the matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }

    }

     for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<< matrix[i][j]<<" ";
        }
         cout<<endl;
    }

    cout << "\nLeft diagonal sum = " << leftDiagonalSum(matrix, n);
    cout << "\nRight diagonal sum = " << rightDiagonalSum(matrix, n);

    return 0;
}

