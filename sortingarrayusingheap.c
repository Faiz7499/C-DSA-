#include<stdio.h>

/*void swap(int *a,int *b){
    int *temp=*a;
    *a=*b;
    *b=temp;
}*/
void maxheapify(int *a,int n,int i){
    int largest=i;
    int l=2*i;
    int r=(2*i)+1;
    while (l<=n && a[largest]<a[l])
    {
        largest=l;
    }
    while (r<=n && a[largest]<a[r])
    {
        largest=r;
    }
    if (largest!=i)
    {   int temp=a[i];
         a[i]=a[largest];
         a[largest]=temp;
       // swap(a[i],a[largest]);
        maxheapify(a,n,largest);
    }
    
}

void heap(int *a,int n){
for(int i=n/2;i>=0;i--){
    maxheapify(a,n,i);
}
for (int i = n-1; i >=0; i--)
{
     int temp=a[0];
         a[0]=a[i];
         a[i]=temp;
   //swap(a[i],a[1]);
   maxheapify(a,n,i);
}

}
void display(int *a,int n){
    for(int i=0;i<n;i++){
        printf("%d ,",a[i]);
    }
}
int main(){
    int a[]={7,40,800,100,270};
int n=5;
    display(a,n);
    heap(a,n);
    printf("\n");
     display(a,n);
    return 0;
}