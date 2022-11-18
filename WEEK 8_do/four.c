#include<stdio.h>
#include<stdlib.h>

typedef struct Queue{
    int *queue;
    int front,rear,max;
}Queue;

void enqueue(Queue *pq,int ele){
    if(pq->rear == pq->max-1){
        printf("Queue is full\n");
    }
    else{
        if(pq->front == -1)
            pq->front = 0;
        pq->rear = (pq->rear + 1) % pq->max;
        pq->queue[pq->rear] = ele;
    }
}

int dequeue(Queue *pq){
    int ele;
    if(pq->front == -1)
        return 0;
    else{
        ele = pq->queue[pq->front];
        pq->front = (pq->front + 1) % pq->max;
        return ele;
    }

}

void display(Queue *pq){
    for(int i=pq->front;i<pq->rear+1;i++){
        printf("%d ",pq->queue[i]);
    }
}

void reverse(Queue *pq){
    int temp;
    int end = pq->rear+1;
    int start = pq->front;
    for(int i=start;i<end/2;i++)
    {
        temp = dequeue(pq);
        pq->queue[i] = pq->queue[end-i-1];
        pq->queue[end-i-1] = temp;
    }
    pq->front = start;
}

void main(){
    Queue *pq,q;
    int t;
    pq = &q;
    pq->front = pq->rear = -1;
    printf("Enter max:\n");
    scanf("%d",&pq->max);
    pq->queue = (int*)malloc(pq->max*sizeof(int));
    printf("\nEnter values: ");
    for(int i=0;i<pq->max;i++)
        {
            scanf("%d",&t);
            enqueue(pq,t);
        }
    display(pq);
    printf("\n");
    reverse(pq);
    display(pq);
    printf("\n");
}