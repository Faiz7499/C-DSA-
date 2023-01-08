#include<stdio.h>
int size=7;
void traverse(int *a,int size){
    for(int i=0;i<size;i++){
        printf("%d ,",a[i]);
    }
}
void insertion(int *a,int size){
    int pos,data;
    printf("\nenter the pstion and data for insertion");
    scanf("%d%d",&pos,&data);
    for(int i=size-1;i>=pos-1;i--){
        a[i+1]=a[i];
    }
       
    a[pos-1]=data;
    size=size+1;

}
void deletion(int *a,int size){
    int pos,data;
    printf("\nenter the pstion and data for insertion");
    scanf("%d",&pos);
    for(int i=pos-1;i<size;i++){
       a[i]= a[i+1];
    }
    size=size-1;

}
 void search(int *a,int size,int value){
     for(int j=0;j<size;j++){
         if(value==a[j]){
             printf("\nelement is present ");
             break;
         }
     }
     printf("\nnot present");
 }
int main(){

    int a[12]={1,2,4,5,6,7,8};
    traverse(a,size);
 insertion(a,size);
 traverse(a,size);
 // search(a,size,10);
  //  deletion(a,size);
   //   traverse(a,size);
  
}