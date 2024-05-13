#include<bits/stdc++.h>
using namespace std;

struct stackNode{
    // int index;
    int value;
    // float GPA;
    stackNode *next;
};

void push(int value,stackNode **top);
int pop(stackNode **top);
void print(stackNode *top);

int main(){
    stackNode *top=nullptr;
    int task=1;
    while(task!=0){
        cout<<"\n\nwhat task do you need to perform? \npress1 to insert value.\npress2 to delete value.\npress3 to print\npress 4 to exit.";
        cin>>task;

        switch(task)
        {
        case 1:
            int value;
            cout<<"input value to insert ";
            cin>>value;
            push(value,&top);
            break;

        case 2:
            pop(&top);
            break;

        case 3:
            print(top);
            break;
        

        default:
            cout<<"exited";
            exit(0);
            break;
        }
    }

    return 0;
}

void push(int value,stackNode **top){
    stackNode *ptr=(stackNode*)malloc(sizeof(stackNode));
    ptr->next=*top;
    ptr->value=value;
    *top=ptr;
}
int pop(stackNode **top){
    if(top==nullptr){
        cout<<"\nstack underflow";
    }
    if(*top!=nullptr){
        stackNode *curr=*top;
        cout<<"The fisrt value is: "<<(*top)->value;
        *top=(*top)->next;
        free(curr);
    }
}
void print(stackNode *top){
    if(top==nullptr){
        cout<<"\nstack is empty";
    }
    stackNode *curr=top;
    while(curr!=nullptr){
        cout<<"\nstack value : "<<curr->value;
        curr=curr->next;
    }
}