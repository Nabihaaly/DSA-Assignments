#include<bits/stdc++.h>
using namespace std;

void push(int *top,int stack[]);
void pop(int *top,int stack[]);

int  main(){
    int size=6;
    int stack[size];
    int top=0;
    int n=1;
    while(n!=0){
        cout<<"\npress1 to insert value\npress2 to delete value\npress3 to print\n";
        cin>>n;

        switch (n)
        {
        case 1:
            push(&top,stack);
            break;
        case 2:
            pop(&top,stack);
            break;
        case 3:
            for(int i:stack){
                cout<<"\n"<<i;
            }
            break;
        
        default:
            break;
        }
    }
    return 0;
}

void push(int *top,int stack[]){
    // int sizeArr=sizeof(stack)/sizeof(int);
    if(*top==6){
        cout<<"\nstack overflow";
    }
    else{
        cout<<"\nEnter value? ";
        cin>> stack[*top];
        ++*top;
    }
}
void pop(int *top,int stack[]){
    if(*top==0){
        cout<<"\nstack underflow";
    }
    else{
        --(*top);
        cout<<"\n"<<stack[*top];
        stack[*top]=0;
    }
}
