#include<bits/stdc++.h>
using namespace std;

string postfix="";;

struct stack_node{
    char operatr;
    stack_node *next;
};
// to store operands while evaluation
struct stack_operands{
    char operand;
    stack_operands *next;
};

void postFix(char operand);
void stackStorage(stack_node **top,char oper);

void push(stack_node *ptr,stack_node **top);
int pop(stack_node **top);

char evaluate(stack_operands **top,string postfix);
void push2(char c,stack_operands **top);
char pop2(stack_operands **top);

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
    stack_node *top=nullptr;
    
    // 2 functions stack and postfix 
    // make array of operators
    // take infixstring input
    // iterate if match with operator: array -> store in stack
        // in stack 
            //make temp stack curr=top
            // if stack is empty store temp
            // else curr->prec>=temp->prec pop curr
                // while curr->prec>=temp->prec || curr is null-- pop curr
                // pop m return operayor and free operator null
            // store 

    // else store in postfix 
        // push 
    cout<<endl;

    string infix;
    int size=15;
    // infix="1+(2*3/(3+2)*(2-3*1))";
    // infix="a+b*(c-d)<x&&(c!=y||x+y<5)";
    infix="1+2*(3-4)<5&(3!6|5+6<5)";


    cout<<"Infix expression is :  "<<infix;
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
    // Create stack to store operands
    stack_operands *top2=nullptr;

    char ans=evaluate(&top2,postfix);
    cout<<"\n\n";
    if(ans=='t') cout<<"\nAnswer: True"; 
    else if(ans=='f') cout<<"\nAnswer: False"; 
    else cout<<"\nAnswer:"<<(ans-'0');

    return 0;
}

void postFix(char operand){
    postfix+=operand;
}

void stackStorage(stack_node **top,char oper){
    stack_node *ptr=(stack_node*)malloc(sizeof(stack_node));
    ptr->next=nullptr;
    ptr->operatr=oper;

    if(*top==nullptr || ptr->operatr=='('){
        push(ptr,top);
        return;
    }
    else if( ptr->operatr==')'){
        stack_node *curr=*top;
        while(curr->operatr!='('){
            curr=curr->next;
            pop(top);
        }
        *top=(*top)->next;
        free(curr);
        return;
    }
    stack_node *curr=*top;
    // iterate over stack
    while(curr!=nullptr && curr->operatr!='('){
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

void push(stack_node *ptr,stack_node **top){
    ptr->next=*top;
    *top=ptr;
}
int pop(stack_node **top){
    postFix((*top)->operatr);
    stack_node *curr=*top;
    *top=(*top)->next;
    free(curr);
}

// EVALUATION
char evaluate(stack_operands **top,string postfix){
    // scan elements in postfix
    for(char c:postfix){
        // if operand push in stack
        if (c >= '0' && c <= '9'){
            push2(c,top);
        }
        // else: operator ..pop 2 operands from stack, evaluate and store ans back in stack
        else{
            // if num is true or false 
            // int num1=pop(top) - '0';
            // int num2=pop(top) - '0';
            char num2=pop2(top);
            char num1=pop2(top);
            int int_num1=0;
            int int_num2=0;
            if(num1!='t' && num1!='f')  int_num1=num1-'0' ;
            if(num2!='t' && num2!='f')  int_num2=num2-'0';

            if(c=='|'){
                bool ans=num1 || num2;
                char answer='f';
                if(ans) answer='t';
                push2(answer ,top);
            }
            else if(c=='&') {
                bool ans=num1 && num2;
                char answer='f';
                if(ans) answer='t';
                push2(answer ,top);
            }
            else if(c=='!'){
                bool ans;
                if(num1!='t' && num1!='f')  ans=int_num1 != int_num2;
                else ans=num1 != num2;
                char answer='f';
                if(ans) answer='t';
                push2(answer ,top);
            }
            else if( c=='=') {
                bool ans;
                if(num1!='t' && num1!='f')  ans=int_num1 == int_num2;
                else ans=num1 != num2;
                char answer='f';
                if(ans) answer='t';
                push2(answer ,top);
            }
            else if(c=='<') {
                bool ans=int_num1 < int_num2;
                char answer='f';
                if(ans) answer='t';
                push2(answer ,top);
            }
            else if(c=='>') {
                bool ans=int_num1 > int_num2;
                char answer='f';
                if(ans) answer='t';
                push2(answer ,top);
            }
            else if(c=='+' ) {
                int ans=int_num1 + int_num2;                   
                char ch=(char)ans+'0';
                push2(ch,top);
            }
            else if(c=='-' )  {
                int ans=int_num1 - int_num2;
                char ch=(char)ans+'0';
                push2(ch,top);
            }                
            else if(c=='*')  {
                int ans=int_num1 * int_num2;
                char ch=(char)ans+'0';
                push2(ch,top);
            }                
            else if( c=='/')  {
                int ans=int_num1 / int_num2;                
                char ch=(char)ans+'0';
                push2(ch,top);
            }
                
        }
    }
    return pop2(top);
}

void push2(char c,stack_operands **top){
    stack_operands *ptr=(stack_operands*)malloc(sizeof(stack_operands));
    cout<<" "<<c-'0';
    ptr->operand=c;
    ptr->next=*top;
    *top=ptr;
}

char pop2(stack_operands **top){
    char oper=(*top)->operand;
    stack_operands *curr=*top;
    *top=(*top)->next;
    free(curr);
    return oper;
}

/*
 
a+b*c/d*x-f*d
2+3*1/2*9-6*2
abc*d/x*+fd*-
a=2,b=3,c=1,x=9,d=2,f=6
231*2/9*+62*-
232/9*+62*-
219*+62*-
29+62*-
1162*-
1112-
-1

*/