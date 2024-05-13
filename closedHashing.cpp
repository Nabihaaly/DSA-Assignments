#include<bits/stdc++.h>
using namespace std;


void insertByLinearProb(int hashTable[],int size);
void insertByQuadProb(int hashTable[],int size);
bool searchByLinearProb(int hashTable[],int size);
bool searchByQuadProb(int hashTable[],int size);
void print(int hashTable[],int size);
int hashFnc(int size,int key);
int linearProbing(int hashTable[],int size,int key,int ind);
int quadProbing(int hashTable[],int size,int key,int ind);

int main(){
    int size=7;
    int hashTable[size];
    
    for(int i=0;i<size;i++){
        hashTable[i]=-1;
    }

    int task=1;
    while(task!=0){
        cout<<"\n\nwhat task do you need to perform?\npress1 to insert value\npress2 to search\npress3 to print\npress 0 to exit\nEnter: " ;
        cin>>task;
        cout<<"\n";

        switch(task)
        {
        case 1:
            int algo;
            cout<<"\nHow do you want to Insert?\nress 1 : Linear Insertion \npress 2 : Quadratic Insertion\n";
            cin>>algo;
            switch(algo)
            {
            case 1:
                insertByLinearProb(hashTable,size);
                break;
            case 2:
                insertByQuadProb(hashTable,size);
                break;
            }
            break;
        
        case 2:
            int search;
            cout<<"\nHow do you want to Search?\nress 1 : Linear Search \npress 2 : Quadratic Search\n";
            cin>>search;
            switch(search)
            {
            case 1:
                searchByLinearProb(hashTable,size);
                break;
            case 2:
                searchByQuadProb(hashTable,size);
                break;
            }
            break;
        
        case 3:
            print(hashTable,size);
            break;

        default:
            cout<<"exited";
            exit(0);
            break;
        }
    }
    return 0;
}

void insertByLinearProb(int hashTable[],int size){
    int key;
    cout<<"\nEnter value to insert: ";
    cin>>key;
    int ind=hashFnc(size,key);
    if(hashTable[ind]!=-1)
        ind=linearProbing(hashTable,size,key,ind);
    if(ind==-1){
        cout<<"\nArray is FUll";
        return;
    }
    hashTable[ind]=key;    
    cout<<"\nValue is inserted";
}
void insertByQuadProb(int hashTable[],int size){
    int key;
    cout<<"\nEnter value to insert: ";
    cin>>key;
    int ind=hashFnc(size,key);
    if(hashTable[ind]!=-1)
        ind=quadProbing(hashTable,size,key,ind);
    if(ind==-1){
        cout<<"\nArray is FUll";
        return;
    }
    hashTable[ind]=key;    
    cout<<"\nValue is inserted";
}

bool searchByLinearProb(int hashTable[],int size){
    int key;
    cout<<"\nEnter value to Search: ";
    cin>>key;
    int ind=hashFnc(size,key);
    int i=1;
    while (hashTable[ind]!=key)
    {
        ind+=1;
        if(ind==size){
            ind=0;
        }
        i++;
        // cout<<"\nIndex: "<<ind;
        if(i==size){
            cout<<"\nValue Not Found.";
            return 0;
        }
    }
    cout<<"\nKey Found at index: "<<ind; 
}

bool searchByQuadProb(int hashTable[],int size){
    int key;
    cout<<"\nEnter value to Search: ";
    cin>>key;
    int ind=hashFnc(size,key);
    int i=1;
    int temp=ind;
    while (hashTable[ind]!=key)
    {
        if(i>=size){
            break;
        }
        ind=temp;
        ind=(ind+i*i)%size;
        i++;
        // cout<<"\nIndex in quad: "<<ind;
    }
    if(i>=size){
        int i=1;
        while (hashTable[ind]!=key)
        {
            ind+=1;
            if(ind==size){
                ind=0;
            }
            i++;
            if(i==size){
                cout<<"\nValue Not Found.";
                return 0;
            }
        }
    }
    cout<<"\nKey Found at index: "<<ind; 
}

void print(int hashTable[],int size){
    cout<<"\nPrinting values: ";
    for(int i=0;i<size;i++){
        cout<<hashTable[i];
        cout<<" ";
    }
}

int hashFnc(int size,int key){
    int ind=0;
    ind=key%size;
    return ind;
}

int linearProbing(int hashTable[],int size,int key,int ind){
    int i=1;
    while (hashTable[ind]!=-1 && i<=size)
    {
        ind+=1;
        if(ind==size){
            ind=0;
        }
        i++;
        cout<<"\nIndex in lin: "<<ind;
    }
    if(i<=10){
        return -1;
    }
    else{
        return ind;
    }
}
int quadProbing(int hashTable[],int size,int key,int ind){
    int i=1;
    int temp=ind;
    while (hashTable[ind]!=-1 )
    {
        
        if(i>=size){
            break;
        }
        ind=temp;
        ind=(ind+i*i)%size;
        i++;
        cout<<"\nIndex in quad: "<<ind;
    }
    if(i>=size){
        ind= linearProbing(hashTable,size,key,ind);
        // cout<<"\nInd by linear: "<<ind;
    }
    return ind;

}

