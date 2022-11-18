#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int* queue;
    int front,rear,max;
}QUEUE;


void pqinsert(QUEUE* apq,int x){
    if(apq->front == -1){
        apq->front = 0;
    }
    apq->rear = (apq->rear+1)%apq->max;
    apq->queue[apq->rear] = x;
}

int pqmindelete(QUEUE* apq){
    int small = apq->queue[apq->front];
    int index = 0;
    for(int i = apq->front+1;i<=apq->rear;i++){
        if(small>apq->queue[i]){
            small = apq->queue[i];
            index = i;
        }
    }
    for(int i=index+1;i<=apq->rear;i++){
        apq->queue[i-1] = apq->queue[i];
    }
    apq->rear--;
    return small;
}   

void display(QUEUE* apq){
    for(int i = apq->front;i<=apq->rear;i++){
        printf("%d ",apq->queue[i]);
    }
    printf("\n");
}

int main(){
    QUEUE *apq,pq;
    int t;
    apq = &pq;
    apq->front = -1;
    apq->rear = -1;
    printf("Enter the max of queue: ");
    scanf("%d",&apq->max);
    apq->queue = (int*)malloc(apq->max*sizeof(int));
    printf("Enter values: ");
    for(int i=0;i<apq->max;i++)
    {
        scanf("%d",&t);
        pqinsert(apq,t);
    }
    display(apq);
    printf("Deleted %d",pqmindelete(apq));
    printf("\n");
    display(apq);
}