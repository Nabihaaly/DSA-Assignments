#include<bits/stdc++.h>
using namespace std;

string postfix="";

struct stack_Node{
    char operatr;
    stack_Node *next;
};

// struct for operand/operator
struct Node{
    char element;
    Node* l_child;
    Node* r_child;
};

// stack to store address 
struct stack_address{
    Node* address;
    stack_address *next;
};

void postFix(char operand);
void stackStorage(stack_Node **top,char oper);

void push(stack_Node *ptr,stack_Node **top);
int pop(stack_Node **top);

void postfix_tree(char c,stack_address **top,Node **root);

void pushAddr(Node *ptr,stack_address **top);
Node *popAddr(stack_address **top);

void InOrderTrav(Node *node);

int prec(char c){
    int prec;
    if(c=='(') prec=0;
    else if(c=='|') prec=1;
    else if(c=='&') prec=2;
    else if(c=='!' || c=='=') prec=3;
    else if(c=='<' || c=='>') prec=4;
    else if(c=='+' || c=='-') prec=5;
    else if(c=='*' || c=='/') prec=6;

    return prec;
}


int main(){
    stack_Node *top=nullptr;

    string infix;
    int size=13;
    // infix="2+3*1/2*9-6*2";
    infix="a+b*c/d*x-f*d";
    cout<<"Infix expression is "<<infix;
    // cin<<infix;

    for(char c:infix){
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            postFix(c);
        else
            stackStorage(&top,c);
    }
    while(top!=nullptr){
        pop(&top);
    }
    cout<<endl;
    cout<<"Postfix expression is ";
    for(char c:postfix){
        cout<<c;
    }

    // struct for operand/operator

    // Postfix expression Tree 
    // scan Nodes in postfix
    // create Node
    // if operand store adres in stack
    // else pop address of r operannd and link to operator right, pop left and link to left, 
    //    store operator adres in stack
    // repeat
    
    stack_address* top_addr=nullptr;
    Node *root=nullptr;

    for(char c:postfix){
        postfix_tree(c,&top_addr,&root);
    }
    cout<<"\n";
    InOrderTrav(root);

    return 0;
}

void InOrderTrav(Node *node){
    if(node!=nullptr){
        InOrderTrav(node->l_child);
        cout<<node->element;
        InOrderTrav(node->r_child);
    }
}

void postFix(char operand){
    postfix+=operand;
}

void stackStorage(stack_Node **top,char oper){
    stack_Node *ptr=(stack_Node*)malloc(sizeof(stack_Node));
    ptr->next=nullptr;
    ptr->operatr=oper;

    if(*top==nullptr || ptr->operatr=='('){
        push(ptr,top);
        return;
    }
    else if( ptr->operatr==')'){
        stack_Node *curr=*top;
        while(curr->operatr!='('){
            pop(top);
            curr=curr->next;
        }
        pop(top);
    }
    stack_Node *curr=*top;
    // iterate over stack
    while(curr!=nullptr){
        // agr ptr oper ki prec highest nahi hai 
        if(!(prec(ptr->operatr)>prec(curr->operatr))){
            // jbtk higher prec ka oper stack m nh milta pop
            while(prec((*top)->operatr)!=prec(curr->operatr)){
                pop(top);
            }           
            // oper of same prec as curr found
            // dlt this too
            pop(top);
            // same prec oper dlt now curr is top again
            curr=*top;
            continue;
        }
        curr=curr->next;
    }
    push(ptr,top);
}

void push(stack_Node *ptr,stack_Node **top){
    ptr->next=*top;
    *top=ptr;
}
int pop(stack_Node **top){
    postFix((*top)->operatr);
    stack_Node *curr=*top;
    *top=(*top)->next;
    free(curr);
}

void postfix_tree(char c,stack_address **top,Node **root){
    // create Node
    Node *ptr=(Node*)malloc(sizeof(Node));
    ptr->element=c;
    ptr->l_child=nullptr;
    ptr->r_child=nullptr;
    // if operand store adres in stack
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        pushAddr(ptr,top);
    // else pop address of r operannd and link to operator right, pop left and link to left, 
    //    store operator adres in stack
    else {
        ptr->r_child= popAddr(top);
        ptr->l_child=popAddr(top);
        pushAddr(ptr,top);
        *root=ptr;
    }
    // repeat
}

void pushAddr(Node *ptrNode,stack_address **top){
    stack_address* ptr=(stack_address*)malloc(sizeof(stack_address));
    ptr->address=ptrNode;
    ptr->next=*top;
    *top=ptr;
}

Node *popAddr(stack_address **top){
    stack_address *curr=*top;
    Node *ptr=curr->address;
    *top=(*top)->next;
    free(curr);
    return ptr;
}


/*
 
a+b*c/d*x-f*d
2+3*1/2*9-6*2
abc*d/x*+fd*-
a=2,b=3,c=1,x=9,d=2,f=6
231*2/9*+62*-


*/