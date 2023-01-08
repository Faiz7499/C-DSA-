#include<stdio.h>
int maximum(int a[], int n){
    int max=0;
    for (int i = 0; i < n; i++)
    {
        if (max<a[i])
        {
            max=a[i];
        }
      
    }
      return max;
}
void count(int a[],int n){
    int max=maximum(a,n);
    int b[max];
    for (int i = 0; i <=max; i++)
    {
        b[i]=0;
    }
    for (int j = 0; j < n; j++)
    {
        b[a[j]]=b[a[j]]+1;
    }
    int i=0,j=0;
    while (i<=max)
    {
        if (b[i]>0)
        {
            a[j]=i;
            b[i]=b[i]-1;
            j++;
        }
        else{
            i++;
        }
        
    }
}
void traverse(int *a,int n){
    for (int  i = 0; i < n; i++)
    {
        printf("%d,",a[i]);
    }
    
}
void main(){
int a[]={9,8,7,6,5,4};
traverse(a,6);
count(a,6);
printf("\n");
traverse(a,6);
}