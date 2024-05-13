#include<bits/stdc++.h>
using namespace std;

struct Record{
    int value;
    Record *next;
};

void insert(Record *hashTable[],int size);
void search(Record *hashTable[],int size);
void print(Record *hashTable[],int size);
int hashFnc(int size,int key);
void linearProbing(Record *hashTable[],int size,int key,int ind);

int main(){
    int size=7;
    Record *hashTable[size];
    
    for(int i=0;i<size;i++){
        Record *ptr=(Record*)malloc(sizeof(Record));
        ptr->value=-1;
        ptr->next=nullptr;
        hashTable[i]=ptr;
    }

    int task=1;
    while(task!=0){
        cout<<"\n\nwhat task do you need to perform?\npress1 to insert value\npress2 to search\npress3 to print\npress 0 to exit\nEnter: " ;
        cin>>task;
        cout<<"\n";

        switch(task)
        {
        case 1:
            insert(hashTable,size);
            break;
        
        case 2:
            search(hashTable,size);
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

void insert(Record *hashTable[],int size){
    int key;
    cout<<"\nEnter value to insert: ";
    cin>>key;
    int ind=hashFnc(size,key);
    if((hashTable[ind])->value!=-1){
        linearProbing(hashTable,size,key,ind);
        return;
    }
    hashTable[ind]->value=key;    
    cout<<"\nValue is inserted";
}

void search(Record *hashTable[],int size){
    int key;
    cout<<"\nEnter value to Search: ";
    cin>>key;
    int ind=hashFnc(size,key);
    if((hashTable[ind])->value!=key){
        Record *curr=hashTable[ind];
        while(curr->next!=nullptr){
            if(curr->next->value==key)
                break;
            curr=curr->next;
        }
        if(curr->next==nullptr){
            cout<<"\nValue Not Found.";
            return;
        }
    } 
    cout<<"\nKey Found at index: "<<ind; 
}

void print(Record *hashTable[],int size){
    cout<<"\nPrinting values: ";
    for(int i=0;i<size;i++){
        cout<<"\nValue: "<<hashTable[i]->value;
        Record *curr=hashTable[i];
        while(curr->next!=nullptr){
            cout<<"\n-Value: "<<curr->next->value;
            curr=curr->next;
        }
    }
}
int hashFnc(int size,int key){
    int ind=0;
    ind=key%size;
    return ind;
}
void linearProbing(Record *hashTable[],int size,int key,int ind){
    Record *curr=hashTable[ind];
    while(curr->next!=nullptr){
        curr=curr->next;
    }
    Record *ptr=(Record*)malloc(sizeof(Record));
    ptr->value=key;
    ptr->next=nullptr;
    curr->next=ptr;
    cout<<"\nValue is inserted in prob: "<<curr->next->value;
}