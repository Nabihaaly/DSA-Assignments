#include<bits/stdc++.h>
using namespace std;

// to store operands while evaluation
struct stack_operands{
    char operand;
    stack_operands *next;
};

char evaluate(stack_operands **top,string postfix);
void push(char c,stack_operands **top);
char pop(stack_operands **top);

int main(){

    // string postfix="123*32+/231*-*+13+<"; //tr
    string postfix="231*2/9*+62*-"; //-1
    // string postfix="1234-*+5<36!56+5<|&"; //tr

    // Create stack to store operands
    stack_operands *top2=nullptr;

    char ans=evaluate(&top2,postfix);
    cout<<"\n\n";
    if(ans=='t') cout<<"\nAnswer: True"; 
    else if(ans=='f') cout<<"\nAnswer: False"; 
    else cout<<"\nAnswer:"<<(ans-'0');

    return 0;
}

// EVALUATION
char evaluate(stack_operands **top,string postfix){
    // scan elements in postfix
    for(char c:postfix){
        // if operand push in stack
        if (c >= '0' && c <= '9'){
            push(c,top);
        }
        // else: operator ..pop 2 operands from stack, evaluate and store ans back in stack
        else{
            // if num is true or false 
            // int num1=pop(top) - '0';
            // int num2=pop(top) - '0';
            char num2=pop(top);
            char num1=pop(top);
            int int_num1=0;
            int int_num2=0;
            if(num1!='t' && num1!='f')  int_num1=num1-'0' ;
            if(num2!='t' && num2!='f')  int_num2=num2-'0';

            if(c=='|'){
                bool ans=num1 || num2;
                char answer='f';
                if(ans) answer='t';
                push(answer ,top);
            }
            else if(c=='&') {
                bool ans=num1 && num2;
                char answer='f';
                if(ans) answer='t';
                push(answer ,top);
            }
            else if(c=='!'){
                bool ans;
                if(num1!='t' && num1!='f')  ans=int_num1 != int_num2;
                else ans=num1 != num2;
                char answer='f';
                if(ans) answer='t';
                push(answer ,top);
            }
            else if( c=='=') {
                bool ans;
                if(num1!='t' && num1!='f')  ans=int_num1 == int_num2;
                else ans=num1 != num2;
                char answer='f';
                if(ans) answer='t';
                push(answer ,top);
            }
            else if(c=='<') {
                bool ans=int_num1 < int_num2;
                char answer='f';
                if(ans) answer='t';
                push(answer ,top);
            }
            else if(c=='>') {
                bool ans=int_num1 > int_num2;
                char answer='f';
                if(ans) answer='t';
                push(answer ,top);
            }
            else if(c=='+' ) {
                int ans=int_num1 + int_num2;                   
                char ch=(char)ans+'0';
                push(ch,top);
            }
            else if(c=='-' )  {
                int ans=int_num1 - int_num2;
                char ch=(char)ans+'0';
                push(ch,top);
            }                
            else if(c=='*')  {
                int ans=int_num1 * int_num2;
                char ch=(char)ans+'0';
                push(ch,top);
            }                
            else if( c=='/')  {
                int ans=int_num1 / int_num2;                
                char ch=(char)ans+'0';
                push(ch,top);
            }
                
        }
    }
    return pop(top);
}

void push(char c,stack_operands **top){
    stack_operands *ptr=(stack_operands*)malloc(sizeof(stack_operands));
    cout<<" "<<c-'0';
    ptr->operand=c;
    ptr->next=*top;
    *top=ptr;
}

char pop(stack_operands **top){
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
=231*2/9*+62*-
=232/9*+62*-
=219*+62*-
=29+62*-
=1162*-
=1112-
=-1


2.infix  = 1+(2*3/(3+2)*(2-3*1))<1+3
  postfix= 123*32+/231*-*+13+<

  123 2*3 6
  1632 3+2 5
  165  6/5 1
  11231 3*1 3
  1123 2-3 -1
  11-1 1*-1 -1
  1-1  1+-1 0
  013 1+3 4
  04 0<4 true
  true

3. infix  = a+b*(c-d)<x&&(c!=y||x+y<5)

   postfix= abcd-*+x<&c!y=|xy+5<|&
   =1234-*+5<36!56+5<|&
   =12-1 *
   =1-1 +
   =05 <
   =t36 !=
   =tt56 +
   =tt(11)5 <
   =ttf ||
   =tt &&
   =true   

   infix= 1+2*(3-4)<5&&(3!=6||5+6<5)
   1+2*(3-4)<5&(3!6|5+6<5)
   =1+2*(-1)<5&& (tr||11<5)
   =1+(-2)<5 && (tr||false)
   =-1<5 && tr
   =true && tr 
   =tr 


*/