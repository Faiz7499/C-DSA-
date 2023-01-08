#include<stdio.h>
int partion(int *a,int low,int high){
    int pivot=a[low];
    int i=low+1;
    int j=high;
    int temp;
    do{
    while (a[i]<=pivot)
    {
        i++;
    }
    while (a[j]>pivot)
    {
        j--;
    }
    if(i<j){
        temp=a[i];
        a[i]=a[j];
        a[i]=temp;
    }
    }
    while(i<j);
   temp=a[low];
   a[low]=a[j];
   a[j]=temp;
   return j;  
}
void quiksort(int *a,int low,int high){
     int index;
    if(low<high){
       index=partion(a,low,high);
       quiksort(a,low,index-1);
       quiksort(a,index,high);

    }
}
void traversal(int *a,int n){
    for(int i=0;i<n;i++){
    printf("%d ,",a[i]);
    }
}
int main(){
    int a[]={7,99,3,2,6,1};
    int low=0;
    int n=6;
      traversal(a,n);
      printf("\n");

    traversal(a,n);
     printf("\n");
       quiksort(a,low,n);
        printf("\n");
          traversal(a,n);
          return 0;
       
}