#include<iostream>
using namespace std;
int main(){
 while(true){
        int i;
        int j;
        int k;
        int l;

        cout << "Enter number of rows for matrix 1" << endl;
        cin >> i;
        cout << "Enter number of cols for matrix 1" << endl;
        cin >> j;
        cout << "Enter elements of matrix 1" << endl;
        int A[i][j];
        for(int a = 0; a < i; a++){
            for(int b = 0; b < j; b++){
                cin >> A[a][b];
            }
        }

        cout << "Enter number of rows for matrix 2" << endl;
        cin >> k;
        cout << "Enter number of cols for matrix 2" << endl;
        cin >> l;
        int B[k][l];
        cout << "Enter elements of matrix 2" << endl;
        for(int a = 0; a < k; a++){
            for(int b = 0; b < l; b++){
                cin >> B[a][b];
            }
        }
    cout<<"Matrix 1"<<endl;
         for(int a = 0; a < i; a++){
            for(int b = 0; b < j; b++){
                cout << A[a][b]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
      cout<<"Matrix 2"<<endl;
for(int a = 0; a < k; a++){
    for(int b = 0; b < l; b++){
        cout<< B[a][b]<<" ";
    }
    cout<<endl;
}


        cout << "\n1. Multiplication\n2. Addition\n3. Subtraction\n";
        int choice;
        cin >> choice;

        switch(choice){
        case 1:
            if(j == k){
                int c[i][l] = {}; // Declare result matrix

                for(int p = 0; p < i; p++){
                    for(int q = 0; q < l; q++){
                        for(int r = 0; r < j; r++){
                            c[p][q] += A[p][r] * B[r][q];
                        }
                    }
                }

                // Output the result
                cout << "Result of multiplication:\n";
                for(int p = 0; p < i; p++){
                    for(int q = 0; q < l; q++){
                        cout << c[p][q] << " ";
                    }
                    cout << endl;
                }
            }
            else {
                cout << "Matrix multiplication not possible. Columns of matrix 1 must equal rows of matrix 2.\n";
            }
            break;


        case 2:
    if(i == k && j == l){
        int d[i][j];
        for(int p = 0; p < i; p++){
            for(int q = 0; q < j; q++){
                d[p][q] = A[p][q] + B[p][q];
            }
        }
        for(int p = 0; p < i; p++){
            for(int q = 0; q < j; q++){
                cout << d[p][q] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "Matrix addition not possible. Dimensions must match.\n";
    }
    break;
        case 3:
             if(i == k && j == l){
        int d[i][j];
        for(int p = 0; p < i; p++){
            for(int q = 0; q < j; q++){
                d[p][q] = A[p][q] - B[p][q];
            }
        }
        for(int p = 0; p < i; p++){
            for(int q = 0; q < j; q++){
                cout << d[p][q] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "Matrix addition not possible. Dimensions must match.\n";
    }
    break;
        default:
            cout<<"Irrelevant response"<<endl;
        }


    }
}
