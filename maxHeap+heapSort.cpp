#include<bits/stdc++.h>
using namespace std;

void insert(int heap[],int value,int size,int *i);
void heapify(int heap[],int ind);
void swap(int heap[],int ind1,int ind2);
int deleteNode(int heap[],int value,int size);

void ascending(int heap[],int size);
void heapifyDownward(int heap[],int ind,int size);

void print_heap(int heap[],int size);

int main(){

    int values[]={78,99,23,63,97,55,230,117,70,11};
    int size=10;
    int heap[size];
    for(int i=0;i<size;i++){
        heap[i]=-1;
    }
    int ind=0;
    // for(int value:values){
    //     insert(heap,value,size,&ind);
    // }
    // cout<<"\nprinting max heap: ";
    // print_heap(heap,size);


    // ascending(heap,size);
    // cout<<"\nprinting sorted heap: ";
    // print_heap(heap,size);

    // deleteNode(heap,2,size);
    // cout<<"\nprinting after dlt heap: ";
    // print_heap(heap,size);

    int task=1;
    while(task!=0){
        cout<<"\n\nwhat task do you need to perform? \npress1 to insert value\npress2 to deleteValue\npress3 to sort heap\npress4 to print max heap\npress5 to exit.";
        cin>>task;

        switch(task)
        {
        case 1:
            for(int value:values){
                insert(heap,value,size,&ind);
            }
            break;

        case 2:
            deleteNode(heap,2,size);
            cout<<"\nprinting after dlt heap: ";
            print_heap(heap,size);
            break;

        case 3:
            ascending(heap,size);
            cout<<"\nprinting sorted heap: ";
            print_heap(heap,size);
            break;
        
        case 4:
            cout<<"\nprinting heap: ";
            print_heap(heap,size);
            break;
        
        default:
            cout<<"exited";
            exit(0);
            break;
        }
    }


    return 0;
}

void insert(int heap[],int value,int size,int *i){
    heap[*i]=value;
    heapify(heap,*i);    
    *i=*i+1;
}

void heapify(int heap[],int ind){
    if(ind==0) return;
    int parent=(ind-1)/2;
    if(heap[parent]<heap[ind]){
        swap(heap,parent,ind);
        heapify(heap,parent);
    }
}

void heapifyDownward(int heap[],int parent,int size){
    int lc=2*parent+1;
    int rc=2*parent+2;
    if(rc>=size){
        if(lc>=size) return;
        else{
            if(heap[parent]<heap[lc])
                swap(heap,parent,lc);
        }
        return;
    }

    int idx=0;
    if(max(heap[lc],heap[rc])==heap[lc]) idx=lc;
    else idx=rc;
    if(heap[parent]<heap[idx]){
        swap(heap,parent,idx);
        heapifyDownward(heap,idx,size);
    }
}

void swap(int heap[],int ind1,int ind2){//1=230,2=11
    int temp=heap[ind1];//78//230
    heap[ind1]=heap[ind2];//78->99//11
    heap[ind2]=temp;//99->78//230
}

int deleteNode(int heap[],int value,int size){
    while(heap[size-1]==-1) size-=1;
    
    swap(heap,0,size-1);
    heap[size-1]=-1;
    size-=1;
    heapifyDownward(heap,0,size);
}


void ascending(int heap[],int size){
    while(heap[size-1]==-1) size-=1;
    while(size>1){
        // swap first and last
        swap(heap,0,size-1);
        // update size
        size-=1;
        // make max heap
        heapifyDownward(heap,0,size);
    }
}

void print_heap(int heap[],int size){
    for(int i=0;i<size;i++){
        cout<<heap[i];
        cout<<" ";
    }
}
