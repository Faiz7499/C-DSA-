#include<stdio.h>
void merging(int a[],int low,int mid,int high){
    int i=low;
    int j=mid+1;
    int k=low;
    int b[100];
    while (i<=mid && j<=high){
        if (a[i]<a[j])
        {
        b[k]=a[i];
        i++;
        k++;
        }
         else
        {
        b[k]=a[j];
        j++;
        k++;
        }
    }
        while (i<=mid)
        {
            b[k]=a[i];
          i++;
         k++;
        }
         while (j<=high)
        {
            b[k]=a[j];
          j++;
         k++;
        }
        for(int h=0;h<=high;h++){
            a[h]=b[h];
        }
        
    }
   
    

void merge(int a[], int low ,int high){
    int mid;
    if (low<high)
    {
        mid=(low+high)/2;
        merge(a,low,mid);
        merge(a,mid+1,high);
        merging(a,  low ,mid, high);
    }
    
}
void traverse(int *a,int n){
    for (int  i = 0; i < n; i++)
    {
        printf("%d,",a[i]);
    }
    
}
void main(){
int a[]={5,4,3,2,1};
traverse(a,5);
merge(a,0,5);
printf("\n");
traverse(a,5);
}