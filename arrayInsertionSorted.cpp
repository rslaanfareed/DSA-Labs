#include<iostream>
using namespace std;
int main(){
int data[5]={2,5,7};
int n=5;
int lb=0;
int ub=2;
int item;
int loc;

//CHECKING OVERFLOW
if(ub==n-1){
    cout<<"OVERFLOW"<<endl;
    return 0;
}

//traversing
for(int i=lb;i<=ub;i++){
    cout<<data[i]<<" ";
}
cout<<endl;


cout<<"ENTER ITEM TO INSERT"<<endl;
cin>>item;

for(int i=lb;i<=ub;i++){
    if(item<data[i]){                  //check if items comes before data[i]
        loc=i;                         //item insertion location
         for(int j=ub;j>=loc;j--){     //insertion loop
        data[j+1]=data[j];
    }
    data[loc]=item;
    ub++;
    cout<<"ITEM INSERTED SUCCESSFULLY"<<endl;
    for(int i=lb;i<=ub;i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
    return 0;
    }


}

//insertion in empty list or last index

ub++;
data[ub]=item;
cout<<"ITEM SUCCESSFULLY INSERTED"<<endl;
for(int i=lb;i<=ub;i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
return 0;
}
