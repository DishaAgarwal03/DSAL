#include<stdio.h>
#include<stdlib.h>

typedef struct LIST* Node;

typedef struct LIST{
    int data;
    Node next;
}LIST;

Node getnode(){
    Node temp = (Node)malloc(sizeof(LIST));
    return temp;
}

Node Insert(Node head,int item){
    Node rear,temp;
    temp = getnode();
    temp->data = item;
    temp->next = NULL;
    rear = head;
    if(head == NULL){
        head = temp;
        return head; 
    }
    else{
        while(rear->next)
        {
            rear = rear->next;
        }
        rear->next = temp;
        return head;
    }
}

void Rem(Node *head){
    Node current = *head;
    Node next,prev;   
    if(head == NULL){
        printf("List is Empty,cannot delete\n");
    }
    else{
        while(current != NULL){
            next = current->next;
            prev = current;
            while(next!=NULL){
                if(current->data == next->data){
                    prev->next = next->next;
                    free(next);
                    next = prev;
                }
                next = next->next;
                prev = prev->next;
            }
            current = current->next;
        }
    }
}
void display(Node head){
    Node temp;
    temp = head;
    while(temp){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

void main(){
    Node List = NULL;
    List = Insert(List,1);
    List = Insert(List,1);
    List = Insert(List,2);
    List = Insert(List,2);
    display(List);
    printf("\nAfter removing duplicates:\n");
    Rem(&List);
    display(List);

}