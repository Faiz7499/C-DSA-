#include<stdio.h>
#define n 10
int queue[n];
int front =-1;
int rear=-1;
int isfull(){
    if(rear==n-1){
        return 1;
    }
    return 0;
}
int isempty(){
    if(rear==-1){
        return 1;
    
    }
    return 0;
}
void enqueue(int a){
    if(isfull()){
        printf("overflow");

    }
    if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=a;
        
    }
    else
    {
        rear++;
        queue[rear]=a;
    }
}
void dequeue(){
    if(isempty()){
        printf("underflow");
    }
   else if(front==rear){
       front=rear=-1;
    }
    else{
        front++;
    }
}
void peek(){
    printf("%d",queue[rear]);
}
void display(){
    if(isempty()){
        printf("have no element");
    }
    for(int i=front;i<=rear;i++){
        printf("%d ,",queue[i]);
    }
}
int main(){
    enqueue(1);
     enqueue(2);
      enqueue(3);
       enqueue(4);
       display();
      dequeue();
      peek();
    display();
     return 0;
}