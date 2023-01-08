#include<stdio.h>
int s1[10];
int s2[10];
int top1=-1,top2=-1;
void push1(int a){
    top1++;
    s1[top1]=a;
}
void push2(int a){
    top2++;
    s2[top2]=a;
}
int pop1(){
    int b=s1[top1];
    top1--;
    return b;
}
int pop2(){
    int c=s2[top2];
    top2--;
    return c;
}
int enqueue(int a){
    push1(a);
}
int dequeue(){
    int i,j,p,m;
    for(i=top1;i>=0;i--){
        p=pop1();
        push2(p);
    }
    int r=pop2();
    for(j=top2;j>=0;j--){
     m=pop2();
     push1(m);
    }
    return r;
}
void display(){
    for(int i=0;i<=top1;i++){
        printf("%d",s1[i]);
    }
}
int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    display();
   printf("the dequed element is    %d" ,  dequeue());
   printf("\n");
   display();
   return 0;


}
