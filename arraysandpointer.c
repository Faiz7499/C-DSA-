#include<stdio.h>
int main(){
    int a[]={1,2,4,5,65,6};
    int *p=a;
   printf("%d\n",p);
   printf("%d\n",a);
   printf("%d\n",*p);
   printf("%d\n",*(p+1));
    printf("%d\n",*(a+1));
     printf("%d\n",*p++);
      printf("%d\n",*p);
     
  
  
        
}