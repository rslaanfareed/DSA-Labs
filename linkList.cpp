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
    cout<<endl<<"Value: ";
    int i = start;
    while (i != -1) {
        cout << data[i].value << " ";
        i = data[i].link;
    }
    cout << endl<<"Link: ";
    while (i != -1) {
        cout << data[i].link << " ";
        i = data[i].link;
    }
}



//Searching single in unsorted ----------
void searchItem(node data[],int start){
if(start==-1){
    cout<<"\nUNDERFLOW"<<endl;
    return;
}
int item;
cout<<"\nEnter item to search"<<endl;
cin>>item;
int i=start;
while(i!=-1){
if(item==data[i].value){
    cout<<data[i].value<<" found at "<<i<<endl;
    return;
}
i=data[i].link;
}
cout<<"\nItem not found"<<endl;
}


//Searching all in unsorted ---------------
void searchItems(node data[],int start){
if(start==-1){
    cout<<"\nUNDERFLOW"<<endl;
    return;
}
int item;
int count=0;
cout<<"\nEnter item to search"<<endl;
cin>>item;
int i=start;
while(i!=-1){
if(item==data[i].value){
    cout<<data[i].value<<" found at "<<i<<endl;
    count++;
}
i=data[i].link;
}
if(count==0){
        cout<<endl;
    cout<<item<<" not found"<<endl<<endl;
    return;
}
cout<<item<<" repeated "<<count<<" times"<<endl<<endl;
}


//Searching all in sorted ---------------------
void searchItemsSorted(node data[],int start){
if(start==-1){
    cout<<"UNDERFLOW"<<endl;
    return;
}
int item;
int count=0;
cout<<"Enter item to search"<<endl;
cin>>item;
int i=start;
while(i!=-1){
if(item==data[i].value){
    cout<<data[i].value<<" found at "<<i<<endl;
    count++;
}
else if(item<data[i].value){
    break;
}
i=data[i].link;
}
if(count==0){
    cout<<item<<" not found"<<endl<<endl;
    return;
}
cout<<item<<" repeated "<<count<<" times"<<endl<<endl;
}

//insertion unsorted-------------------------------
void insertion(node data[],int& start,int& avail){
    if(avail==-1){
        cout<<"UNDERFLOW"<<endl<<endl;
        return;
    }
    cout<<"ENTER ITEM TO INSERT"<<endl;
    int item;
    cin>>item;
    int loc=avail;
    avail=data[avail].link;
    data[loc].value=item;
    data[loc].link=start;
    start=loc;
}

//insertion sorted--------------------------------------------------*****
void sortedInsertion(node sortedData[], int& start, int& avail){
if(avail==-1){
    cout<<"\nOVERFLOW"<<endl;
    return;
}
int prev;
int item;
int i;
cout<<"\nENTER ITEM TO INSERT"<<endl;
cin>>item;
int loc;
if(start==-1 || item<sortedData[start].value){
    loc=avail;
    avail=sortedData[avail].link;
    sortedData[loc].value=item;
    sortedData[loc].link=start;
    start=loc;
    return;
}
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

}//while ended
loc=avail;
avail=sortedData[avail].link;
sortedData[loc].value=item;
sortedData[loc].link=-1;
sortedData[prev].link=loc;
return;
}

//deletion unsorted--------------------------
void deletion(node data[],int start,int avail){
    if(start==-1){
        cout<<"UNDERFLOW"<<endl;
        return;
    }
    int prev;
    int item;
    int i;
    int loc;
    cout<<"\nENTER ITEM TO DELETE"<<endl;
    cin>>item;
    //deletion from start----------
    if(item==data[start].value){
        loc=start;
        start=data[start].link;
        data[loc].link=avail;
        avail=loc;
        cout<<"\nDELETED!"<<endl;
        return;
    }

    //deletion somewhere in the list
    prev=start;
    i=data[start].link;
    while(i!=-1){
        if(item==data[i].value){
            loc=i;
            data[prev].link=data[i].link;
            data[loc].link=avail;
            avail=loc;
            cout<<"\nDeleted"<<endl;
            return;
        }
        prev=i;
        i=data[i].link;
    }

    cout<<"\nITEM NOT FOUND"<<endl;
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

    node data[10];
    data[0]={1,-1};
    data[1]={2,3};
    data[2]={7,1};
    data[3]={4,0};
    data[4]={0,6};
    data[5]={0,-1};
    data[6]={0,5};
    int start=2;
    int avail=4;

    node sortedData[5];
    sortedData[0]={0,1};
    sortedData[1]={0,2};
    sortedData[2]={0,3};
    sortedData[3]={0,4};
    sortedData[4]={0,-1};

    int sortedStart=-1;
    int sortedAvail=0;
while(true){
    cout<<"\n_____MAIN MENU____\n1. Traverse\n2. Search single occurrence in unsorted list\n3. Search all occurrences in unsorted list\n4. Search all occurrences in sorted list\n5. Insertion unsorted \n6. Insertion Sorted\n7. Deletion unsorted\n8. Deletion sorted\n9. Exit"<<endl;
    int choice;
    cin>>choice;
    switch(choice){
case 1:
    traverse(sortedData,sortedStart);
    break;
case 2:
    traverse(data,start);
    searchItem(data,start);
    break;
case 3:
    traverse(data,start);
    searchItems(data,start);
    break;
case 4:
    traverse(sortedData,sortedStart);
    searchItemsSorted(sortedData,sortedStart);
    break;
case 5:
    traverse(data,start);
    insertion(data,start,avail);
    traverse(data,start);
    break;
case 6:
    traverse(sortedData,sortedStart);
    sortedInsertion(sortedData,sortedStart,sortedAvail);
    traverse(sortedData,sortedStart);
    break;
case 7:
    traverse(data,start);
    deletion(data,start,avail);
    traverse(data,start);
    break;
case 8:
    traverse(sortedData,sortedStart);
    sortedDeletion(sortedData,sortedStart,sortedAvail);
    traverse(sortedData,sortedStart);
    break;
case 9:
    return 0;
default:
    cout<<"INVALID ENTRY"<<endl;
    break;
    }
}
}
