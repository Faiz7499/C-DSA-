#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * prev;
    struct node * next;
}*head=0,*temp=0,*tail=0;
void create(){
    
    int choice=1;
   
    while (choice==1)
    
    {
        struct node * newnode=(struct node *)malloc(sizeof(struct node));
    printf("ENter the data of the node");
    scanf("%d",&newnode->data);
    newnode->prev=0;
    newnode->next=0;
    if (head==0)
    {
        head=tail=newnode;
        tail->next=head;
    }
    else{
       tail->next=newnode;
       newnode->prev=tail;
       tail=newnode;
       tail->next=head;
       head->prev=tail;

    }
    printf("Entr the choice if want to continue");
    scanf("%d",&choice);    
    }
    
}
void traverse(struct node * head){
    temp=head;
    printf("hi");
    while (temp!=tail)
    {
        printf("%d,",temp->data);
        temp=temp->next;
    }
   printf("%d,",temp->data);
    
}
 struct node * insertion(struct node * head){
    temp=head;
    int i=1;
    int pos;
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data and the position of insertion of node");
    scanf("%d %d",&newnode->data,&pos);
    if (pos==1)
    {
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        head->prev=tail;
    }
    else{
    while (i!=pos-1)
    {
        temp=temp->next;
    }
      newnode->next=temp->next;
     temp->next->prev=newnode;
     temp->next=newnode;
     newnode->prev=temp;
     temp=newnode;
    }
     return head;

 }
struct node * deletion(struct node * head){
    int i=1,pos;
    printf("Enter the position of deleting element ");
    scanf("%d",&pos);
    struct node *p=head;
    struct node *q=p->next;
    while (i!=pos-1)
    {
        p=p->next;
        q=q->next;
    }
    
    
}
void main(){
    create();
    traverse(head);
    insertion(head);
    traverse(head);
}