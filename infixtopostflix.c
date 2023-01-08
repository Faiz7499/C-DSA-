#include<stdio.h>
#define n 10
char stack[n];
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
        printf("overflow");
    }
    top++;
    stack[top]=a;
}
char pop(){
    if (isempty())
    {
        printf("undreflow");
    }
    char b=stack[top];
    top--;
    return b;
    
}
char peek(){
    return stack[top];
}
int match(char a,char b){
    if(a=='[' && b==']'){
        return 1;   
    }
    if(a=='{' && '}'){
        return 1;
    }
    if(a=='(' && b==')'){
        return 1;
    }
    return 0;
}
int parenthesis(char *exp){
    char poped;
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{'){
            push(exp[i]);
        }
        else{
            if(exp[i]==')' || exp[i]==']' || exp[i]=='}'){
                if(isempty()){
                    return 0;
                }
                poped=pop();
                if(!match(poped,exp[i])){
                    return 0;
                }
            }
        }
    }
    if(isempty()){
        return 1;
    }
    else
    return 0;
}
int main(){
    char exp[]="({})[()";
    if(parenthesis(exp)){
        printf("matcheddddddddddd");
    }
    else{
        printf("nottttttttttt");

    }
    return 0;
}