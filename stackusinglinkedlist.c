#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int isfull(struct node * top){
 struct node *p=(struct node *)malloc(sizeof(struct node ));
 if(p==NULL){
 return 1;
 }
 else{
     return 0;
 }
 }
 int isempty(struct node *top){
     if(top==NULL){
         return 1;
     }
     else{
   return 0;
     }
 }
 
 struct node* push(struct node * top){
    
     if(isfull(top)){
         printf("Stack is in overflow condition,so we are not eligible to insert an element into the stack ");

     }
     else{
    struct node * newnode=(struct node *)malloc(sizeof(struct node ));
     printf("enter the data");
     scanf("%d",&newnode->data);
     newnode->next=top;
     top=newnode;
     return top;
     }
     

 }
 void pop(struct node *top){
     struct node *temp=top;
     if(isempty(top)){
         printf("Stack is in underflow condition");
     }
     else{

       top=top->next;
       free(temp);

     }
 }
void display(struct node *top){
    struct node *temp=top;
    while(temp!=NULL){
        printf("%d ,",temp->data);
        temp=temp->next;
    }
}
int main(){
     struct node * top=NULL;
    push(top);
     push(top);
     push(top);
      push(top);
      display(top);
      pop(top);
      display(top);
        return 0;
}