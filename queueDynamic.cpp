#include<bits/stdc++.h>
using namespace std;

struct queueNode{
    int value;
    queueNode *next;
};

void EnQueue(int value,queueNode **front,queueNode **rear);
void DeQueue(queueNode **front,queueNode **rear);
void print(queueNode *front);

int main(){
    queueNode *front=nullptr;
    queueNode *rear=nullptr;
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
            EnQueue(value,&front,&rear);
            break;

        case 2:
            DeQueue(&front,&rear);
            break;

        case 3:
            print(front);
            break;
        

        default:
            cout<<"exited";
            exit(0);
            break;
        }
    }

    return 0;
}

void EnQueue(int value,queueNode **front,queueNode **rear){
    queueNode *ptr=(queueNode*)malloc(sizeof(queueNode));
    ptr->next=nullptr;
    ptr->value=value;
    if(*front==nullptr){
        *front=ptr;
        *rear=*front;
    }
    else{
        queueNode *curr=*front;
        while (curr->next!=nullptr)
        {
            curr=curr->next;
        }
        curr->next=ptr;
        *(rear)=ptr;
        
    }
}
void DeQueue(queueNode **front,queueNode **rear){
    if(*front==nullptr){
        cout<<"\nqueue is empty";
    }
    else{
        queueNode *curr=*front;
        cout<<"The fisrt value is: "<<(*front)->value;
        *front=(*front)->next;
        free(curr);
    }
    
}
void print(queueNode *front){
    if(front==nullptr){
        cout<<"\nqueue is empty";
    }
    queueNode *curr=front;
    while(curr!=nullptr){
        cout<<"\nqueue value : "<<curr->value;
        curr=curr->next;
    }
}