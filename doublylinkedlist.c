#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * prev;
    struct node *next;

};
 struct node *head=0;
  struct node *temp=0;
void create(){
    int choice=1;
     struct node *newnode;
     while (choice)
     {
        newnode=( struct node *)malloc(sizeof( struct node ));
        printf("enter the data ");
        scanf("%d",&newnode->data);
        newnode->prev=0;
        newnode->next=0;
        if(head==0){
            head=temp=newnode;
        }
        else{
        temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
         printf("if u want to continue then press 1");
    scanf("%d",&choice);
     }
     
}
void taverse(struct node *head){
    temp=head;
    while (temp!=0)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
struct node *insert(struct node *head){
    int pos,i=1;
    temp=head;
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter the data and at which node u have to insert");
    scanf("%d%d",&newnode->data,&pos);
    while (i!=pos-1){
        temp=temp->next;
        i++;
    }
   newnode->next=temp->next;
   temp->next=newnode;
   temp->next->prev=newnode;
   newnode->prev=temp;
   temp=newnode;
   return head;
}
struct node *delete(struct node *head){
    temp=head;
    struct node*p=temp->next;
    int i=1,ind;
    printf("enter the value");
    scanf("%d",&ind);
    while(i!=ind-1){
        temp=temp->next;
        p=p->next;
    }
    temp->next=p->next;
    p->next->prev=temp;
    free(p);
    return head;
}
int main(){
    create();
    taverse(head);
    insert(head);
    taverse(head);
    delete(head);
    taverse(head);
}