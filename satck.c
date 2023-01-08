#include<stdio.h>
#define n 10
int stack[n];
int top=-1;

void push(int a){
    if(top==n-1){
        printf("stack is in overflow condition");
    }
    else{
        top++;
        stack[top]=a;
    }
}
void pop(){
    if(top==-1){
        printf("stack is in underflow conditon");
    }
    else{
        printf("deleted element is %d\n",stack[top]);
        top--;
    }
}
int  peek(){
    return stack[top];
}
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

void display(){
    for(int i=top;i>=0;i--){
        printf("%d\n ",stack[i]);
    }
}
int main(){
    push(1);
     push(2);
      push(3);
       push(4);
            display();
      pop();
      display();
      peek();
      isfull();
    return 0;
}