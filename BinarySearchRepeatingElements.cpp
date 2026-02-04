#include<iostream>
using namespace std;

int main(){
    int data[10] = {1,3,5,6,8,8,9,9,9};
    int lb = 0;
    int ub = 8;
    int item;
    int mid;
    int n = 9;

    // check underflow
    if(ub == -1){
        cout << "UNDERFLOW";
        return 0;
    }

    for(int i = lb; i <= ub; i++){
        cout << data[i] << " ";
    }
    cout << endl;

    cout << "ENTER ITEM TO SEARCH: ";
    cin >> item;

    // midpoint
    mid = (lb + ub) / 2;
    while(data[mid] != item && lb <= ub){
        if(item < data[mid]){
            ub = mid - 1;
        }
        else{
            lb = mid + 1;
        }
        mid = (lb + ub) / 2;
    }

    if(data[mid] == item){
        cout << "ITEM FOUND AT INDEX " << mid << endl;

        // search to the left
        int tempUb = mid - 1;
        while(tempUb >= 0 && data[tempUb] == item){
            cout << "ITEM FOUND AT INDEX " << tempUb << endl;
            tempUb--;
        }

        // search to the right
        int tempLb = mid + 1;
        while(tempLb <= n-1 && data[tempLb] == item){
            cout << "ITEM FOUND AT INDEX " << tempLb << endl;
            tempLb++;
        }
    }
    else{
        cout << "ITEM NOT FOUND" << endl;
    }

    return 0;
}
