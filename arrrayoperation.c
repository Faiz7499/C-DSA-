#include<stdio.h>
int main(){
    int a[5]={1,2,3,4,5};
    int n=5;
   int ind,val;
   for(int i=0;i<n;i++){
        printf("%d",a[i]);
    }
    printf("\nEnter index and value to be inserted");
    scanf("%d %d",&ind,&val);
    for(int i=n-1;i>=ind-1;i--){
        a[i+1]=a[i];}
        a[ind-1]=val;

        n++;
        for(int i=0;i<n;i++){
        printf("%d",a[i]);
    }
    return 0;
}