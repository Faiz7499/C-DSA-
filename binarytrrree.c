#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node * right;
};
struct node * root;
struct node * create(){
    int x;
    printf("Enter the value of node");
    scanf("%d",&x);
    if(x==0){
        return ;
    }
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    printf("Enter the left node of %d",x);
    newnode->left=create();
    printf("Enter the right node of %d",x);
    newnode->right=create();
    return newnode;
}
void treversal( struct node * root){
    if(root==0){
        return ;
    }
    printf("\n%d",root->data);
    treversal(root->left);
    treversal(root->right);
}
struct node * singlycreation(int key){
    struct node * newnode=(struct node *)malloc(sizeof(struct node ));
    newnode->data=key;
     newnode->left=0;
     newnode->right=0;
     return newnode;
}
void insert(struct node * root,int key ){
    struct node * prev=NULL;
    while (root!=NULL){
        prev=root;
        if(root->data==key){
            printf("the key cannit inserted because it is already present");
        }
        else if (key<root->data)
        {
            root=root->left;
        }
        else{
            root=root->right;
        }
        
    }
     struct node * new=singlycreation(key);
     if(prev->data>key){
         prev->left=new;
     }
     else{
         prev->right=new;
     }
    
}
int isbst( struct node *root){
    static struct node * prev=NULL;
    if (root!=NULL){
        if(!isbst(root->left)){
            return 0;
        }
           if(prev!=NULL && root->data<=prev->data){
               return 0;
           }
        prev=root;
        return isbst(root->right);
     
    }
   else{
       return 1;
   }
    
}
void main(){
    root=create();
    treversal(root);
   /* if(isbst(root)){
        printf("\nthe constructed binary tree is BST");
    }
    else
    {
        printf("\nthe Constructed tree is not BST");
    }*/
    insert(root,5);
    treversal(root);
    
}