#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char* queue;
    int front,rear,max;
}Queue;

void enqueueR(Queue* pq,char ch){
    if(pq->front == -1){
        pq->front = 0;
    }
    pq->rear = (pq->rear+1)%pq->max;
    pq->queue[pq->rear] = ch;
}

char dequeueF(Queue* pq){
    char ch;
    ch = pq->queue[pq->front];
    if(pq->front == pq->rear){
        pq->front = pq->rear = -1;
    }
    else{
        pq->front = (pq->front+1)%pq->max;    
    }
    return ch;
}

char dequeueR(Queue* pq){
    char ch;
    ch = pq->queue[pq->rear];
    if(pq->rear == pq->front)
        pq->rear = pq->front = -1;
    else
        pq->rear=(pq->rear-1+pq->max)%pq->max;
    return ch;
}

void display(Queue* pq){
    int i = pq->front;
    while(i!=pq->rear){
        printf("%c ",pq->queue[i]);
        i = (i+1)%pq->max;
    }
    printf("%c ",pq->queue[pq->rear]);
}

int checkPalin(Queue* pq){
    if(pq->front==-1)
        return 1;
    if(dequeueF(pq) == dequeueR(pq))
        checkPalin(pq);
    else
        return 0;
    return 1;
}

void main(){
    Queue *pq,q;
    pq = &q;
    char temp[20];
    printf("Enter the string: ");
    scanf("%s",temp);
    pq->max = strlen(temp);
    pq->front = pq->rear = -1;
    pq->queue = (char*)malloc(pq->max*sizeof(char));
    for(int i = 0; temp[i]!='\0';i++){
        enqueueR(pq,temp[i]);
    }
    if(checkPalin(pq))
        printf("It is a Palindrome\n");
    else
        printf("It is not a Palindrome\n");
}
