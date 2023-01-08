#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next
}*head=0,*temp=0;
void create(){
    struct node*newnode;
    int value,choice=1;
    while (choice==1)
    {
        newnode=(struct node *)malloc(sizeof(struct node));

    printf("enter the data of the node")    ;
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(head==0){
        head=temp=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
    printf("if u want to continue then press 1");
    scanf("%d",&choice);
    } 
}
void traverse(struct node * head){
    temp=head;
    while (temp!=NULL)
    {
        printf("%d, ",temp->data);
        temp=temp->next;
    }
    
}
void reverse(struct node *head){
    struct node *p,*c,*n;
    p=0;
    c=n=head;
    while (n->next!=NULL)
    {
        n=n->next;
        c->next=p;
        p=c;
        c=c->next;
    }
    
    
}
int main(){
    create();
    traverse(head);
   reverse(head);
  printf("\n");
     traverse(head);
}