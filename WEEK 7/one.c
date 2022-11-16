#include <stdio.h>
#include <string.h>
#define MAX 5

typedef struct {
    char str[10];
} String;

typedef struct {
    String s[MAX];
    int front,rear;
} Q;

int isFull(Q q) {
    if ((q.front == q.rear + 1) || (q.front == 0 && q.rear == MAX - 1)) 
        return 1;
    return 0;
}

int isEmpty(Q q) {
    if (q.front == -1) 
        return 1;
    return 0;
}

void insertcq(Q * q,char string[10]) {
    if(isFull(*q)) {
        printf("Queue is full");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear = (q->rear + 1) % MAX;
    strcpy((q->s[q->rear]).str,string);
}

void deletecq(Q * q) {
    if(isEmpty(*q)) {
        printf("Queue is empty");
        return;
    }
    char string[10];
    strcpy(string,(q->s[q->front]).str);
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    else 
        q->front = (q->front + 1) % MAX;
    printf("Deleted string: %s",string);
}

void displaycq(Q q) {
    int i;
    if(isEmpty(q)) {
        printf("Empty Queue");
        return;
    }
    for(i=q.front;i!=q.rear;i=(i+1)%MAX)
        printf("%s ",q.s[i].str);
    printf("%s",q.s[i].str);
}

void main() {
    int ch;
    char t[10];
    Q q;
    q.front = -1;
    q.rear = -1;
    printf("\n1)Insert 2)Delete 3)Display 4)Exit");
    do {
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        if (ch == 1) {
            printf("Enter a String: ");
            scanf("%s",t);
            insertcq(&q,t);
        } 
        else if (ch == 2) 
            deletecq(&q);
        else if (ch == 3) 
            displaycq(q);
        else    
            ch = 4;
    } while(ch != 4);
}
