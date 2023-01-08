#include<stdio.h>
void bubblesort(int *a,int n){
    int temp;
      int sorted=1;
    for(int i=0;i<n-1;i++){
      
        for(int j=0;j<n-1;j++){
           if(a[j]>a[j+1]){
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            sorted=0;
           }
        }
        if(sorted==1){
            printf("the array is sorted");
            break;
        }
        else{
            printf("array is not sorted");
            
        }
    }
}
void traversal(int *a,int n){
    for(int i=0;i<n;i++){
    printf("%d",a[i]);
    }
}
int main(){
    int n=5;
    int a[]={9,11,3,2,1};
    bubblesort(a,n);
    traversal(a,n);
}