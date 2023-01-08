#include<stdio.h>
void selection(int *a,int n ){
    int index,temp;
    for(int i=0;i<n-1;i++){
        index=i;
        for(int j=i+1;j<n;j++){
            if(a[index]>a[j]){
                index=j;
            }
        }
        temp=a[i];
        a[i]=a[index];
        a[index]=temp;

    }
}
void traversal(int *a,int n){
    for(int i=0;i<n;i++){
    printf("%d ,",a[i]);
    }
}
int main(){
    int a[]={7,99,3,54,2,1};
    int n=6;
    selection(a,n);
    traversal(a,n);
}
