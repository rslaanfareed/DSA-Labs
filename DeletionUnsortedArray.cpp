#include<iostream>
using namespace std;
int main(){
int data[5]={3,5,7,8,12};
int n=5;
int lb=0;
int ub=4;
int item;
int loc;

//TRAVERSING
for(int i=lb;i<=ub;i++){
    cout<<data[i]<<" ";
}
cout<<endl;

//check underflow
if(ub==-1){
    cout<<"UNDERFLOW"<<endl;
    return 0;
}
cout<<"ENTER ITEM TO DELETE"<<endl;
cin>>item;
for(int i=lb;i<=ub;i++){
    if(item==data[i]){
        loc=i;
    for(int j=loc;j<ub;j++){
        data[j]=data[j+1];
    }
     ub--;
     cout<<item<<" DELETED from index "<<loc<<endl;

     for(int i=lb;i<=ub;i++){
    cout<<data[i]<<" ";
    }
    cout<<endl;
     return 0;
    }


    }
    cout<<"ITEM NOT FOUND"<<endl;
    }

