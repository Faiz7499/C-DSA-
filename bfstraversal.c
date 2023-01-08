#include<stdio.h>
int queue[15];
int front=-1, rear=-1;
void enqueue(int a){
   if(front==-1 && rear==-1){
       front=rear=0;
       queue[rear]=a;
   }
   else{
       rear++;
       queue[rear]=a;
   }
}
int isempty(){
    if(front==-1 && rear==-1){
        return 1;
    }
    return 0;
}
int  dequeue(){
    int b=queue[front];
    front++;
    return b;
} 
void peek(){
    printf("\n%d ",queue[rear]);
}
int main(){
    int visited[7]={0,0,0,0,0,0,0};
    int node;
    int i=0;
    int array[7][7]={ {0,1,1,1,0,0,0},
                      {1,0,1,0,0,0,0},
                      {1,1,0,1,1,0,0},
                      {1,0,1,0,1,0,0},
                      {0,0,1,1,0,1,1},
                      {0,0,0,0,1,0,0},
                      {0,0,0,0,1,0,0} };
    visited[i]=1;
    enqueue(1);
    printf("%d",i);
    
    while(!isempty()){
    
        node=dequeue();
        for(int j=0;j<7;j++){
            if(array[node][j]==1 && visited[j]==0){
                printf("%d",j);
                visited[j]=1;
                enqueue(j);
            }
        }
    }
    enqueue(4);
    peek();
                      
}