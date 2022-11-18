#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char** queue;
    int front,rear,max;
}Queue;

void enqueueF(Queue* pq,char str[]){
    if(pq->front == -1){
        pq->rear = pq->front = 0;
        strcpy(pq->queue[pq->front],str);
    }
    else{
        pq->front = (pq->front-1+pq->max)%pq->max;
        strcpy(pq->queue[pq->front],str);
    }
}

void enqueueR(Queue* pq,char str[]){
    if(pq->front == -1){
        pq->front = 0;
    }
    pq->rear = (pq->rear+1)%pq->max;
    strcpy(pq->queue[pq->rear],str);
}

char* dequeueF(Queue* pq){
    if((pq->front == pq->rear) && (pq->rear == pq->max-1)){
        return "EMPTY";
    }
    char* str = (char*)malloc((strlen(pq->queue[pq->front])+1)*sizeof(char));
    strcpy(str,pq->queue[pq->front]);
    pq->front = (pq->front+1)%pq->max;
    return str;
}

void display(Queue* pq){
    int i = pq->front;
    while(i!=pq->rear){
        printf("%s ",pq->queue[i]);
        i = (i+1)%pq->max;
    }
    printf("%s ",pq->queue[pq->rear]);
}

void main(){
    Queue *pq,q;
    int ch;
    char str[10];
    pq = &q;
    printf("Enter the max: ");
    scanf("%d",&pq->max);
    pq->front = pq->rear = -1;
    pq->queue = (char**)malloc(pq->max*sizeof(char*));
    for(int i = 0; i< pq->max; i++){
        pq->queue[i] = (char*)malloc(20*sizeof(char));
    }
    printf("\n1)enqueue front 2)enqueue rear 3)dequeue front 4)display 5)exit\n");
    do{
        printf("\nenter choice: ");
        scanf("%d",&ch);
        if(ch==1)
        {
            scanf("%s", str);
            enqueueF(pq,str);
        }
        else if(ch==2)
        {
            scanf("%s", str);
            enqueueR(pq,str);
        }
        else if(ch==3) dequeueF(pq);
        else if(ch==4) display(pq);
        else ch=5;
    }while(ch!=5);

}