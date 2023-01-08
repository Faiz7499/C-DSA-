#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * left;
    struct node * right;

} *root;
struct node * create(){
    int x;
    struct node *newnode=(struct node* )malloc(sizeof(struct node));
    printf(" \nEnter the data for the node");
    scanf("%d",&x);
    if(x==-1){
        return 0;
    }
    newnode->data=x;
    printf("enter left of %d  ",x);
    newnode->left=create();
    printf("enter right of %d ",x);
    newnode->right=create();
    return newnode;
}
void preorder(struct node * root){
    if(root==NULL){
        return ;
    }
    printf(" %d ,",root->data);
    preorder(root->left);
    preorder(root->right);
}
int isBST(struct node * root){
   static  struct node *prev=NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data<=prev->data){
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
    
}
int serarching(struct node * root,int key){
    if(root==NULL){
        return NULL;
    }
    if(key==root->data){
        return root;
    }
    else if(key<root->data){
        return serarching(root->left,key);
    }
    else{
        return serarching(root->right,key);
    }
}
int iterativesearch(struct node * root ,int key){
    while (root!=NULL)
    {
         if(key==root->data){
        return root;
    }
    else if(key<root->data){
        return serarching(root->left,key);
    }
    else{
        return serarching(root->right,key);
    }
    }
    return NULL;
    
}
struct node *singlycreation( int key){
     struct node *newnode=( struct node *)malloc(sizeof( struct node ));
     newnode->data=key;
     newnode->left=0;
     newnode->right=0;
     return newnode;
}
void insert( struct node *root,int key){
     struct node *pichla=NULL;
      while (root!=NULL)
    {
        pichla=root;
         if(key==root->data){
             printf("you cannot insert the data already present");
        return ;
    }
    else if(key<root->data){
        root= root->left;
    }
    else{
        root= root->right;
    }
    }
      struct node *c=singlycreation(key);
      if(pichla->data<key){
        pichla->right=c;
      }
      else{
          pichla->left=c;
      }
     
}
struct node * precedecor(struct node * root){
    root=root->left;
    while (root!=NULL)
    {
        root=root->right;
    }

    return root;
}
struct node * deletion(struct node * root,int key){
    struct node *ipre;
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        free(root);
    }
    if(key<root->data){
        return deletion(root->left,key);
    }
    else if(key>root->data){
        return deletion(root->right,key);
    }
    else{
        ipre=precedecor(root);
        root->data=ipre->data;
        deletion(root->left,ipre->data);
    }
}
int main(){
    root=create();
    preorder(root);
   if(isBST(root)){
       printf("\nthe Given tree is BST");
   }
   else{
       printf("\nTHe given tree is not BST");
   }
  struct node * n=iterativesearch(root,5);
   if(n!=NULL){
   printf("\nElement found");       
   }
   else{
       printf("\nelement not found");
   }
   
    insert(root,6);

    preorder(root);
    printf("\n");
    //deletion(root,3);
      printf("\n");
    preorder(root);
    return 0;
}