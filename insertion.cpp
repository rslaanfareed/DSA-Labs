#include<iostream>
using namespace std;
int main(){
int data[5]={1,7,5};
int lb=0;
int ub=2;
int n=5;
for(int i=0;i<=ub;i++){
    cout<<data[i]<<" ";
}
cout<<endl;

if(ub==n-1){
    cout<<"Overflow"<<endl;
    return 0;
}
ub++;
cout<<"Enter number to insert"<<endl;
int item;
cin>>item;

data[ub]=item;
cout<<"Inserted successfully"<<endl;
for(int i=0;i<=ub;i++){
    cout<<data[i]<<" ";
}

}
