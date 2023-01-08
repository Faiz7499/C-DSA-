
#include<stdio.h>
void mergesort(int *a,int low,int high){
    int mid=(low+high)/2;
    if (low<high)
    {
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
    }
}
    void merge(int *a,int low,int high,int mid){
        int i=low;
        int j=mid+1;
        int k=low;
        int b[100];
        while(i<=mid && j<=high){
            if(a[i]<a[j]){
                b[k]=a[i];
                i++;
                k++;
            }
            if(a[j]<a[i]){
                b[k]=a[j];
                j++;
                k++;
            }
        }
        while (i<=mid)
        {b[k]=a[i];
        k++;
        i++;
        }
         while (j<=high)
        {b[k]=a[j];
        k++;
        j++;
        }
        for(int i=low;i<=high;i++){
            a[i]=b[i];
        }
        
    }
    void traversal(int *a,int n){
    for(int i=0;i<n;i++){
    printf("%d ,",a[i]);
    }
}
    
int main(){
    int a[]={7,99,3,4,12};
    int n=5;
    traversal(a,n);
    printf("\n");
    mergesort(a,0,n-1);
    traversal(a,n);

}