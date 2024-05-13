#include<bits/stdc++.h>
using namespace std;

string prefix="";

struct stack_operators{
    char operatr;
    stack_operators *next;
};

// to store operands while evaluation
struct stack_operands{
    char operand;
    stack_operands *next;
};

void preFix(char operand);
void operatorStack(char oper,stack_operators **top);

void push(stack_operators *ptr,stack_operators **top);
int pop(stack_operators **top);

char evaluate(stack_operands **top);
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
    stack_operators *top_oper=nullptr;
    
    // 2 functions stackOperators and stackPrefix
    // take infix string input
    // reverse infix
    // iterate over infix
        // if operand
            //store in prefix
        // else
            // stack is empty push operator
            // else !ptr->prec>=all last precs push pop last prec push
            // else push
    // empty operator stack

    string infix;
    int size=15;
    // infix="a+b*c/d*x-f*d";
    // infix="1+2*3/5*4-0*5";
    // prefix="-+a*/*bcdx*fd";
    // infix="a+b*c<d+e&c!e*y";
    infix="1+2*(3-4)<5&(3!6|5+6<5)";
    // infix="a+b*c/x+e*y-x*d";
    // infix="1+2*3/3+2*2-3*1";
    cout<<"Infix expression is :  "<<infix;
    // cin<<infix;

    reverse(infix.begin(), infix.end());

    // reverse infix to find prefix
    for(char c:infix){
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            preFix(c);
        else
            operatorStack(c,&top_oper);
    }
    while(top_oper!=nullptr){
        pop(&top_oper);
    }
    cout<<endl;
    reverse(prefix.begin(), prefix.end());

    cout<<"Prefix expression is: ";
    for(int i=0;i<size;i++){
        cout<<prefix[i];
    }
    cout<<endl;

    // // Create stack to store operands
    stack_operands *top2=nullptr;
    char ans=evaluate(&top2);
    cout<<"\n\n";
    if(ans=='t') cout<<"\nAnswer: True"; 
    else if(ans=='f') cout<<"\nAnswer: False"; 
    else cout<<"\nAnswer:"<<ans <<(ans-'0');

    return 0;
}

void preFix(char operand){
    prefix+=operand;
}

void operatorStack(char oper,stack_operators **top){
    stack_operators *ptr=(stack_operators*)malloc(sizeof(stack_operators));
    ptr->next=nullptr;
    ptr->operatr=oper;

    if(*top==nullptr || ptr->operatr=='('){
        push(ptr,top);
        return;
    }
    else if( ptr->operatr==')'){
        stack_operators *curr=*top;
        while(curr->operatr!='('){
            curr=curr->next;
            pop(top);
        }
        *top=(*top)->next;
        free(curr);
        return;
    }

    stack_operators *curr=*top;
    // iterate over stack
    while(curr!=nullptr && curr->operatr!='('){
        // agr ptr oper ki prec highest or equal nahi hai 
        if( prec(ptr->operatr)<prec(curr->operatr) ){
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

void push(stack_operators *ptr,stack_operators **top){
    ptr->next=*top;
    *top=ptr;
}
int pop(stack_operators **top){
    preFix((*top)->operatr);
    stack_operators *curr=*top;
    *top=(*top)->next;
    free(curr);
}

// EVALUATION
char evaluate(stack_operands **top){
    // scan elements 
    for(char c:prefix){
        // if operand push in stack
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            int operand = c - '0';
            push2(operand,top);
        }
        // else: operator ..pop 2 operands from stack, evaluate and store ans back in stack
        else{
            // since stack reverse hai to 
            // num1 jo pehly pop hua wo num 2 hai bcs of reverse str
            // num2 jo bad m pop hua wo num 1 hai egg: num2+num1(bcs ulta chlra hai)
            char num1=pop2(top);
            char num2=pop2(top);
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
    cout<<" "<<c;
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
 infix= 1+2*(3-4)<5&&(3!=6||5+6<55)
 prefix= &<+1*2-345|!36<+565
*/