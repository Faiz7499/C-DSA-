#include<stdio.h>
void insertion(int * a,int n){
int key,j;

for (int i = 1; i < n-1; i++)
{
    key=a[i];
    j=i-1;
    while (j>=0 && a[j]>key)
    {
        a[j+1]=a[j];
        j--;
    }
    a[j+1]=key;
    
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
    insertion(a,5);
    printf("\n");
    traverse(a,5);

}