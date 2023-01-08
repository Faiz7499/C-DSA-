#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*left;
    struct node* right;
    int hight;
} *root;
int max(int a,int b){
    return (a>b)?a:b;
}
int gethight(struct node * n){
    if(n==NULL)
    return 0;
    return n->hight;
}
struct node * create(){
    int x;
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nENter the value of node");
    scanf("%d",&x);
    if(x==-1){
        return 0;
    }
    newnode->data=x;
    newnode->hight=1;
    printf("\nEnter the left of %d",x);
    newnode->left=create();
      printf("\nEnter the right of %d",x);
      newnode->right=create();
      return newnode;

}
void preorder(struct node * root){
    if(root!=NULL){
    printf("%d, ",root->data);
    preorder(root->left);
    preorder(root->right);
}
}
 
int getbalance(struct node *n){
    if(n==NULL){
     
            return 0;
        }
        return gethight(n->left) - gethight(n->right);
    
}
struct node * rightrotate(struct node * x){
    struct node * y=x->left;
    struct node * t2=y->right;
    y->right=x;
    x->left=t2;
    x->hight= max(gethight(x->right),gethight(x->left))+1;
    y->hight=max(gethight(y->right),gethight(y->left))+1;
    return y;
}
struct node * leftrotate(struct node * x){
    struct node * y=x->right;
    struct node * t2=y->left;
    y->left=x;
    x->right=t2;
    x->hight = max(gethight(x->right),gethight(x->left))+1;
    y->hight = max(gethight(y->right),gethight(y->left))+1;
    return y;
}
struct node * singly(int key){
struct node * newnode=(struct node * )malloc(sizeof(struct node * ));
newnode->data=key;
newnode->left=0;
newnode->right=0;
newnode->hight=1;
return newnode;
}
struct node * insert(struct node * rot,int key){
    if(rot==NULL){
        return singly(key);
    }
    if(key<rot->data){
        rot->left=insert(rot->left,key);
    }
    else if(key>rot->data)
        rot->right=insert(rot->right,key);
    
    rot->hight=1+max(gethight(rot->left),gethight(rot->right));
    int bf=getbalance(rot);
    if(bf>1 && key<rot->left->data){
        return rightrotate(rot);
    }
    if(bf<-1 && key>rot->right->data){
        return leftrotate(rot);
    }
    if (bf>1 && key>rot->left->data )
    {
        rot->left=leftrotate(rot);
        return rightrotate(rot);
    }
     if (bf<-1 && key<rot->right->data )
    {
        rot->right=rightrotate(rot);
        return leftrotate(rot);
    }
    
    return rot;
}

int main(){
    struct node * root=NULL;
   root= insert(root,6);
    root=insert(root,9);
      root=insert(root,1);
      root=insert(root,5);
      root= insert(root,3);
       root= insert(root,8);
   preorder(root);
}