#include<stdio.h>
#include<stdlib.h>

typedef struct LIST* Node;

typedef struct LIST{
    char data;
    Node next;
}LIST;

Node getNode(){
    Node temp = (Node)malloc(sizeof(LIST));
    return temp;
}

void InsertRear(Node* List,int data){
    Node head = *List;
    Node rear;
    Node temp = getNode();
    temp->data = data;
    temp->next = head;
    if(*List == NULL){
        *List = temp;
        head = *List;
        (*List)->next = head; 
        return;
    }
    rear = head->next;
    while(rear->next != head){
        rear = rear->next;
    }
    rear->next = temp;
}

void display(Node List){
    Node head = List;
    printf("%c ",head->data);
    Node temp = head->next;
    while(temp != head){
        printf("%c ",temp->data);
        temp = temp->next;
    }
}

void sort(Node* List){
    Node head = *List;
    Node current = *List;
    Node next = NULL;
    char x;
    while(current->next != head){
        next = current->next;
        while(next != head){
            if(current->data > next->data){
                x = current->data;
                current->data = next->data;
                next->data = x;
            }
            next = next->next;
        }
        current = current->next;
    }
}

void merge(Node* List1,Node List2){
    Node First = *List1;
    Node Second = List2;
    Node rear = First->next;
    Node temp;
    while(rear->next != First){
        rear = rear->next;
    }
    temp = getNode();
    temp->data = List2->data;
    temp->next = First;
    rear->next = temp;
    rear = rear->next;
    List2 = List2->next;
    while(List2 != Second){
        temp = getNode();
        temp->data = List2->data;
        temp->next = First;
        rear->next = temp;
        rear = rear->next;
        List2 = List2->next;
    }
}

void main(){
    Node List1 = NULL, List2 = NULL;
    InsertRear(&List1,'f');
    InsertRear(&List1,'y');
    printf("List 1: ");
    display(List1);
    InsertRear(&List2,'a');
    InsertRear(&List2,'x');
    printf("\nList 2: ");
    display(List2);
    merge(&List1,List2);
    sort(&List1);
    printf("\nList after merging: ");
    display(List1);
}