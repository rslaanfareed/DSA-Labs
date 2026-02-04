#include <iostream>
using namespace std;

struct node {
    int value;
    int link;
};

//Traversing----------------------------------------------------
void traverse(node data[], int start) {

    if (start == -1) {
        cout << "\nUnderflow" << endl;
        return;
    }
    cout<<endl;
    int i = start;


    cout<<"Data  ";
    while (i != -1) {
        cout << data[i].value << "  ";
        i = data[i].link;
    }

    cout << endl;
    cout<<"index ";
    i=start;
    while (i != -1) {
        cout <<i << "  ";
        i = data[i].link;
    }


    cout << endl;
    cout<<"Link  ";
    i=start;
    while (i != -1) {
        cout <<data[i].link << "  ";
        i = data[i].link;
    }
}

//insertion-- sorted
void sortedInsertion(node sortedData[], int& start, int& avail){
if(avail==-1){
    cout<<"\nOVERFLOW"<<endl;
    return;
}

//insertion at the start-------
int prev;
int item;
int i;
cout<<"\nENTER ITEM TO INSERT"<<endl;
cin>>item;
int loc;
if(start==-1 || item<sortedData[start].value){
    loc=avail;
    sortedData[loc].value=item;
    avail=sortedData[avail].link;

    sortedData[loc].link=start;
    start=loc;
    return;
}

//insertion somewhere in list-------
prev=start;
i=sortedData[start].link;
while(i!=-1){
    if(item<sortedData[i].value){
        loc=avail;
        avail=sortedData[avail].link;
        sortedData[loc].value=item;
        sortedData[loc].link=i;
        sortedData[prev].link=loc;
        return;
    }
    prev=i;
    i=sortedData[i].link;

}

//insertion at the end
loc=avail;
avail=sortedData[avail].link;
sortedData[loc].value=item;
sortedData[loc].link=-1;
sortedData[prev].link=loc;
return;
}

//deletion sorted----------------------------------------------*********
void sortedDeletion(node data[], int& start, int& avail){
if(start==-1){
    cout<<"\nUNDERFLOW"<<endl;
    return;
}
int item;
int loc;
int i;
int prev;
int counter;
cout<<"\nEnter item to delete"<<endl;
cin>>item;
//deletion from start--------------
if(item==data[start].value){
    loc=start;
    start=data[start].link;
    data[loc].link=avail;
    avail=loc;
    cout<<"\nDELETED"<<endl;
    return;
}
//deletion somewhere in the list---------
prev=start;
i=data[start].link;
counter=0;
while(i!=-1){
    if(item==data[i].value){
        loc=i;
        data[prev].link=data[i].link;
        data[loc].link=avail;
        avail=loc;
        cout<<"\nDELETED"<<endl;
        counter++;
        return;
    }
    else if(item<data[i].value){
        break;
    }
    prev=i;
    i=data[i].link;
}
if(counter==0){
    cout<<"\nITEM NOT IN THE LIST"<<endl;
    return;
}
}


int main() {

    node sortedData[5];
    sortedData[0]={0,1};
    sortedData[1]={0,2};
    sortedData[2]={0,3};
    sortedData[3]={0,4};
    sortedData[4]={0,-1};

    int sortedStart=-1;
    int sortedAvail=0;
while(true){
    cout<<"\n_____MAIN MENU____\n1. Traverse\n2. Insertion\n3. Deletion\n4. Exit"<<endl;
    int choice;
    cin>>choice;
    switch(choice){
case 1:
    traverse(sortedData,sortedStart);
    break;

case 2:
    traverse(sortedData,sortedStart);
    sortedInsertion(sortedData,sortedStart,sortedAvail);
    traverse(sortedData,sortedStart);
    break;

case 3:
    traverse(sortedData,sortedStart);
    sortedDeletion(sortedData,sortedStart,sortedAvail);
    traverse(sortedData,sortedStart);
    break;

case 4:
    return 0;
default:
    cout<<"INVALID ENTRY"<<endl;
    break;
    }
}
}
