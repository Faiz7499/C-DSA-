#include<stdio.h>
void selection(int * a,int n){
int indm,temp;

for (int i = 0; i < n-1; i++)
{
    indm=i;

    for (int  j = i+1; j <n; j++)
    {
        if (a[j]<a[indm])
        {
            indm=j;
        }
        
    }
   temp=a[i];
   a[i]=a[indm];
   a[indm]=temp;
    
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
    selection(a,5);
    printf("\n");
    traverse(a,5);

}