#include<iostream>
using namespace std;
int main()
{

    //THIS CODE IF FOR ASCENDING ORDER

int data[5]={3,6,8,9,12};
int lb=0;
int ub=4;
int n=5;
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
    if(item<data[i]){         //FOR ASCENDING
        cout<<"ITEM DOES NOT EXIST"<<endl;
        return 0;
    }
    else if(item==data[i]){
        loc=i;

        for(int j=loc;j<ub;j++){
            data[j]=data[j+1];
        }
        ub--;
        cout<<"DELETED"<<endl;
        //TRAVERSING
        for(int i=lb;i<=ub;i++){
        cout<<data[i]<<" ";
}
cout<<endl;
        return 0;
    }

}

cout<<"ITEM NOT FOUND"<<endl;
return 0;


}
