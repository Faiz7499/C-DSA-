#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head=0,*temp=0;
void create(){
    struct node * newnode;
    int value ,choice=0;
    while (choice==0)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data of the list");
        scanf("%d",&value);
        newnode->data=value;
        newnode->next=0;
        if(head==0){
            
            head=temp=newnode;
        }
        else{
             temp->next=newnode;
             temp=newnode;
        }
        printf("Enter O for continue creatin other wise enter the other number");
        scanf("%d",&choice);
    }
    
}
void traverse(struct node * head){
    temp=head;
    while (temp!=0)
    {
        printf("%d ,",temp->data);
        temp=temp->next;
    }
    
}
struct node * insert(struct node * head){
    temp=head;
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    int pos,i=1;
    printf("ENter the position and the data of the inserting list");
    scanf("%d %d",&newnode->data,&pos);
    if (pos==0)
    {
        newnode->next=temp;
        temp=newnode;
        
    }
    else{
    while (i!=pos-1)
    {
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    temp=newnode;
    }
    return head;
}
struct node * delete(struct node * head){
    temp=head;
    struct node * p=temp->next;
    int pos;
    int i=1;
    printf("ENter the position you want to delete ");
    scanf("%d",&pos);
    while (i!=pos-1)
    {
        temp=temp->next;
        p=p->next;
        i++;
    }
    temp->next=p->next;
    free(p);
    return head;
}
void main(){
     create();
     traverse(head);
     insert(head);
     traverse(head);
     delete(head);
     traverse(head);
}