#include<bits/stdc++.h>
using namespace std;

void EnQueue(int *front,int *rear,int queue[]);
void DeQueue(int *front,int *rear,int queue[]);

int front=0;
int rear=0;

int  main(){
    int size=0;
    cout<<"Enter size of array: ";
    cin>>size;
    int queue[size];
    int n=1;
    while(n!=0){
        cout<<"\npress1 to insert value\npress2 to delete value\npress3 to print\n";
        cin>>n;

        switch (n)
        {
        case 1:
            EnQueue(&front,&rear,queue);
            break;
        case 2:
            DeQueue(&front,&rear,queue);
            break;
        case 3:
            for(int i:queue){
                cout<<"\n"<<i;
            }
            break;
        
        default:
            break;
        }
    }
    return 0;
}

void EnQueue(int *front,int *rear,int queue[]){
    if(*rear==6){
        cout<<"\nqueue overflow";
    }
    else{
        cout<<"\nEnter value? ";
        cin>> queue[*rear];
        ++*rear;
    }
}
void DeQueue(int *front,int *rear,int queue[]){
    if(*front==*rear){
        cout<<"\nqueue underflow";
    }
    else{
        cout<<"\n"<<queue[*front];
        queue[*front]=0;
        ++*front;
    }
}
