#include<stdio.h>
int partition(int a[],int low,int high){
    int pivot=a[low];
    int i=low+1;
    int j=high;
    int temp;
    do
    {
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
        a[j]=a[i];
        }
         
    } while (i<j);
    temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;
    
}
void quiksort(int a[],int low,int high){
    int parti;
    if (low<high)
    {
        parti=partition(a,low,high);
        quiksort(a,low,parti-1);
        quiksort(a,parti+1,high);
    }
    
}
void traverse(int *a,int n){
    for (int  i = 0; i < n; i++)
    {
        printf("%d,",a[i]);
    }
    
}

void main(){
    
    int a[]={7,4,3,5,9};
    traverse(a,5);
  quiksort(a,0,5);
    printf("\n");
    traverse(a,5);

}