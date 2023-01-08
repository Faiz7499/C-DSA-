#include<stdio.h>
void insertion(int *a,int n){;
    int key;
    int j;
    for(int i=0;i<n;i++){
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
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
    insertion(a,n);
    traversal(a,n);
}
