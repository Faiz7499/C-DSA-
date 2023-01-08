#include<stdio.h>
#define n 12
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
        printf("full");
    }
    top++;
    stack[top]=a;
}
char pop(){
     if(isempty()){
        printf("empty");
    }
   char c=stack[top];
   top--;
   return c; 
}
char peek(){
    return stack[top];
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
void infixtopostfix(char * infix){
    printf("hi");
    char postfix[12];
    int i=0,j=0;
    char poped;
    while (infix[i]!='\0'){
        if(!isoperator(infix[i])){
            postfix[j]=infix[i];
            i++;
            j++;

        }
        else{
            if(precedence(infix[i])>precedence(peek()))
            {
                push(infix[i]);
                i++;
            }
            else{
                postfix[j]=pop();
                j++;
            }

        }
    }
      printf("h2");
    while (!isempty())
    {
        
        postfix[j]=pop();
         printf("h3");
        j++;
    }
    postfix[j]='\0';
    for(int i=0;postfix[i]!='\0';i++){
         printf("h3");
        printf("%s",postfix[i]);
    }
     
}
void main(){
char *infix="x*y-z";
infixtopostfix(infix);
}