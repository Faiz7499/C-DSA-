#include<stdio.h>
#include<stdlib.h>
#define n 10
char stack [n];
int top=-1;

int isfull(){
    if(top==n-1){
        return 1;
    }
    return 0;
}
int isempty(){
    if(top==-1){
        return 1;
    }
    return 0;
}
void push(char a){
    if(isfull()){
        printf("overflow ");
    }
    else{
        top++;
        stack[top]=a;
    }
}
char pop(){
    if (isempty())
    {
        printf("UNderlow condition");
    }
    char b =stack[top];
    top--;
    return b;
    
}
int isoperator(char c){
    if(c=='+' || c=='-' || c=='*'|| c=='/'){
        return 1;
    }
    return 0;
}
int precedence(char a){
    if(a=='*' || a=='/'){
        return 3;
    }
     if(a=='+' || a=='-'){
        return 2;}
    return 0;
}
char peek(){
    return stack[top];
}
void *infixtopostix(char * infix){
    char  postfix[10];
    int i=0,j=0;
    char poped;
    while (infix[i]!='\0')
    {
        if(!isoperator(infix[i])){
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else{
            if(precedence(infix[i])>precedence(peek())){
                push(infix[i]);
                i++;
            }
            else{
                poped=pop();
                postfix[j]=poped;

                
            }
        }
    }
    while (!isempty())
    {
        postfix[j]=pop();
        j++;
    }
    postfix[j]='\0';
    printf("%s",postfix);
    
    
}
int main(){
    char  infix[]="x-y+z";
    infixtopostix(infix);
// printf("%s",infixtopostix(infix));
}