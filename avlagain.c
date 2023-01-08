#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * left;
    struct node * right;
    int hight;
}*root;
int max(int a,int b){
    return (a>b)?a:b;
}
struct node* creation(int key){
    struct node * newnode =(struct node *)malloc(sizeof(struct node));
    newnode->data=key;
    newnode->left=NULL;
    newnode->right=NULL;
    int hight=1;
}
int gethight( struct node* n){
    if(n==NULL){
        return 0;
    }
    return n->hight;
}
int getbalancefactor(struct node* n){
    if(n==NULL){
        return 0;
    }
    return gethight(n->left)-gethight(n->right);
} 
struct node* leftrotate(struct node*x){
    struct node* y=x->right;
    struct node*t2=y->left;
    y->left=x;
    x->right=t2;
    x->hight=1+max(gethight(x->right),gethight(x->left));
     y->hight=1+max(gethight(y->right),gethight(y->left));

}
struct node* rightrotate(struct node*x){
    struct node* y=x->left;
    struct node*t2=y->right;
    y->right=x;
    x->left=t2;
    x->hight=1+max(gethight(x->right),gethight(x->left));
     y->hight=1+max(gethight(y->right),gethight(y->left));

}
struct node* insertion(struct node*root ,int key){
    if(root==NULL){
        return creation(key);
    }
    if(key<root->data){
        root->left=insertion(root->left,key);
    }
    else if (key>root->data)
        root->right=insertion(root->right,key);
    root->hight=1+max(gethight(root->left),gethight(root->right));
    int bf=getbalancefactor(root);
    if(bf>1 && key<root->left->data){
        return rightrotate(root);
    }
    if(bf<-1 && key>root->right->data){
        return leftrotate(root);
    }
    if(bf>1 && key>root->left->data){
        root->left=leftrotate(root->left);
        return rightrotate(root);
    }
    if(bf<-1 && key<root->right->data){
        root->right=rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
}
void preorder(struct node * root){
    if(root!=NULL){
        printf(" %d, ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int main(){
    root=NULL;
    root=insertion(root,6);
   root= insertion(root,5);
   root= insertion(root,1);
    root=insertion(root,8);
    preorder(root);
    return 0;
}
