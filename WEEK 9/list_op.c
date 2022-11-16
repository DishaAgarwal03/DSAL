#include<stdio.h>
#include<stdlib.h>

typedef struct Q* Node;

typedef struct Q{
    int data;
    Node next;
}Q;

Node getNode(){
    Node temp = (Node)malloc(sizeof(Q));
    return temp;
}

void InsertRear(Node* List,int data){
    Node rear = *List;
    Node temp = getNode();
    temp->data = data;
    temp->next = NULL;
    if(*List == NULL){
        *List = temp;
        return;
    }
    while(rear->next){
        rear = rear->next;
    }
    rear->next = temp;
}

int DeleteFront(Node* Queue){
    if(*Queue == NULL){
        printf("Underflow!");
        return -1;
    }
    Node temp = *Queue;
    *Queue = (*Queue)->next;
    int data = temp->data;
    free(temp);
    return data;
}

void display(Node List){
    while(List){
        printf("%d ",List->data);
        List = List->next;
    }
    printf("\n");
}