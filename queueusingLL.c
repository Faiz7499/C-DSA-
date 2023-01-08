#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node * front=0;
struct node * rear=0;

void enqueue(int a){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=a;
    newnode->next=0;
    if(front==0){
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}
int dequeue(){
    int b;
    if(rear==0){
        printf("have no element");
    }
   else if(front==rear){
        front=rear=0;
    }
    else{
         b=front->data;
        front=front->next;
    }
   return b;
}
void peek(){
    printf(" ,%d, ",rear->data);
}
void display(struct node * front){
    struct node * temp=front;
    while (temp!=NULL)
    {
        printf(" %d,",temp->data);
        temp=temp->next;
    }
    
}
int main(){
    printf("hello");
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    display(front);
    dequeue();
    display(front);
    peek();
}