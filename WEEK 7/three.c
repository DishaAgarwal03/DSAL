//does not work
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int * ele;
    int front,rear,size;
} Q;

int isFull(Q q) {
    if (q.rear == q.size - 1) 
        return 1;
    return 0;
}

int isEmpty(Q q) {
    if (q.front == -1) 
        return 1;
    return 0;
}

void insert(Q * q,int x) {
    if(isFull(*q)) {
        printf("Queue is full");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear = q->rear + 1;
    q->ele[q->rear] = x;
}

int delete(Q * q) {
    if(isEmpty(*q)) {
        printf("Queue is empty");
        return -5;
    }
    int item = q->ele[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    else {
        q->front = q->front + 1;
    }
    return item;
}

void display(Q q) {
    int i;
    if(isEmpty(q)) {
        printf("Empty Queue");
        return;
    }
    for(i=q.front;i<=q.rear;i++) {
        printf("%d ",q.ele[i]);
    }
    printf("%d",q.ele[i]);
}

int search(Q *q,int x) {
    Q temp;
    int n = sizeof((q->ele));
    int i,t;
    temp.ele = (int *) malloc(n*sizeof(int));
    temp.front = -1;
    temp.rear = -1;
    temp.size = n;

    for(i=0;i<n;i++) {
        if(isEmpty(*q)) 
            return -1;
        t = delete(q);
        insert(&temp,t);
        if (t == x) {
            q->front = -1;
            q->rear = -1;
            while (!isEmpty(temp)) 
                insert(q,delete(&temp));
            return i;
        }
    }
    return -1;
}

void main() {
    int i,temp,n,x;
    Q q;
    printf("Enter n ");
    scanf("%d",&n);
    q.ele = (int *) malloc(n*sizeof(int));
    q.front = -1;
    q.rear = -1;
    q.size = n;
    printf("\nEnter elements of Queue\n");
    for(i=0;i<n;i++) {
        printf("Enter number to insert ");
        scanf("%d",&temp);
        insert(&q,temp);
    }
    printf("Enter number to search for ");
    scanf("%d",&x);
    int ch = search(&q,x);
    if (ch == -1)
        printf("Element not in Queue");
    else
        printf("Element is at index: %d",ch);
    printf("\nThe Queue is: ");
    display(q);
}
