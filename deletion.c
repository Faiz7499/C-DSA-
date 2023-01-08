#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * left;
    struct node * right;

} *root;
struct node * precedecor(struct node * root){
    root=root->left;
    while (root->right!=NULL)
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
        return NULL;
    }
    if(key<root->data){
        root->left=deletion(root->left,key);
    }
    else if(key>root->data){
      root->right= deletion(root->right,key);
    }
    else{
        ipre=precedecor(root);
        root->data=ipre->data;
       root->left= deletion(root->left,ipre->data);
    }
    return root;
}

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
int main(){
    root=create();
    preorder(root);
    deletion(root,3);
    printf("\n");
    preorder(root);
    return 0;
}