#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int * ele;
    int front1,rear1,front2,rear2,halfN;
} Q;

int isFull1(Q q) {
    if ((q.front1 == q.rear1 + 1) || (q.front1 == 0 && q.rear1 == q.halfN - 1)) 
        return 1;
    return 0;
}

int isEmpty1(Q q) {
    if (q.front1 == -1) 
        return 1;
    return 0;
}

int isFull2(Q q) {
    if ((q.front2 == q.rear2 + 1) || (q.front2 == q.halfN && q.rear2 == (q.halfN * 2) - 1)) 
        return 1;
    return 0;
}

int isEmpty2(Q q) {
    if (q.front2 == q.halfN-1) 
        return 1;
    return 0;
}

void insertcq1(Q * q,int x) {
    if(isFull1(*q)) {
        printf("Queue1 is full");
        return;
    }
    if (q->front1 == -1)
        q->front1 = 0;
    q->rear1 = (q->rear1 + 1) % q->halfN;
    q->ele[q->rear1] = x;
}

void insertcq2(Q * q,int x) {
    if(isFull2(*q)) {
        printf("Queue2 is full");
        return;
    }
    if (q->front2 == q->halfN-1)
        q->front2 = q->halfN;
    q->rear2 = ((q->rear2 + 1) % q->halfN)+q->halfN;
    q->ele[q->rear2] = x;
}

int deletecq1(Q * q) {
    if(isEmpty1(*q)) {
        printf("Queue1 is empty");
        return -5;
    }
    int item = q->ele[q->front1];
    if (q->front1 == q->rear1) {
        q->front1 = -1;
        q->rear1 = -1;
    }
    else 
        q->front1 = (q->front1 + 1) % q->halfN;
    return item;
}

int deletecq2(Q * q) {
    if(isEmpty2(*q)) {
        printf("Queue2 is empty");
        return -5;
    }
    int item = q->ele[q->front2];
    if (q->front2 == q->rear2) {
        q->front2 = q->halfN-1;
        q->rear2 = q->halfN-1;
    }
    else
        q->front2 = ((q->front2 + 1) % q->halfN) + q->halfN;
    return item;
}

void displaycq(Q q) {
    int i;
    printf("\nQueue 1: ");
    if(isEmpty1(q)) {
        printf("Empty Queue1");
    }
    else {

        for(i=q.front1;i!=q.rear1;i=(i+1)%q.halfN) {
            printf("%d ",q.ele[i]);
        }
        printf("%d",q.ele[i]);
    }
    printf("\nQueue 2: ");
    if(isEmpty2(q)) {
        printf("Empty Queue2");
    }
    else {

        for(i=q.front2;i!=q.rear2;i=((i+1)%(q.halfN * 2))+q.halfN) {
            printf("%d ",q.ele[i]);
        }
        printf("%d",q.ele[i]);
    }
}

void main() {
    int t,ch,n;
    Q q;
    printf("Enter size: ");
    scanf("%d",&n);
    q.ele = (int *) malloc(n*sizeof(int));
    q.front1 = -1;
    q.rear1 = -1;
    q.halfN = n/2;
    q.front2 = q.halfN - 1;
    q.rear2 = q.halfN - 1;
    printf("\n1)Insert1 2)Insert2 3)Delete1 4)Delete2 5)Display 6)Exit");
    do {
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        if (ch == 1) {
            printf("Enter a number: ");
            scanf("%d",&t);
            insertcq1(&q,t);
        }
        else if (ch == 2) {
            printf("Enter a number: ");
            scanf("%d",&t);
            insertcq2(&q,t);
        }
        else if (ch == 3)
            printf("\nElement deleted is: %d",deletecq1(&q));
        else if (ch == 4)
            printf("\nElement deleted is: %d",deletecq2(&q));
        else if (ch == 5) 
            displaycq(q);
        else    
            ch = 6;
    } while(ch != 6);
}