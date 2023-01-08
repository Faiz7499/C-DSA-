#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=0;
  struct node *temp;
  struct node *tail;
void create(){
    int choice=1;
    while(choice==1){
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
    printf("ENtr data part of the node");
    scanf("%d",&newnode->data);
    printf("hi");
    newnode->prev=0;
    newnode->next=0;
    if(head==0){
        newnode=head=tail;
        tail=newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
        tail->next=head;
        head->prev=tail;}
    printf("ENter the 1 iof u want to continue ");
    scanf("%d",&choice);
    }
}
    struct node * insert(struct node *head){
        temp=head;
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        int i=1,pos;
        printf("entre the data for the node and pos at where u want to insert");
    scanf("%d %d",&newnode->data,pos);
    while(i!=pos-1){
        temp=temp->next;
    }
     newnode->next=temp->next;
     temp->next->prev=newnode;
     temp->next=newnode;
     newnode->prev=temp;
     temp=newnode;
     return head;
    }
    struct node * delete(struct node *head){
        int i=1,pos;
        struct node *p,*q;
        p=head;
        q=p->next;
        printf("Enter pos where u want to delete");
        scanf("%d",&pos);
        while (i!=pos-1)
        {
            p=p->next;
            q=q->next;
        }
        p->next=q->next;
    q->next->prev=p;
    free(q);
    return head;
    }
    void traverse(struct node *head){
        temp=head;
        while (temp->next!=NULL)
        {
            printf("%d  ,",temp->data);
        }
        
    }
    int main(){
        create();
        traverse(head);
        insert(head);
        traverse(head);
        delete(head);
        traverse(head);
        return 0;

    }