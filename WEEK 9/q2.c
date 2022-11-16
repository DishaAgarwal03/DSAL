#include<stdio.h>
#include<stdlib.h>
#include "list_op.c"

void Union(Node* List1,Node List2){
    Node First = *List1;
    Node Second = List2;
    Node rear = *List1;
    Node temp;
    int found = 0;
    while(rear->next){
        rear = rear->next;
    }
    while(Second){
        while(First){
            if(First->data == Second->data){
                found = 1;
                break;
            }
            First = First->next;
        }
        if(!found){
            temp = getNode();
            temp->data = Second->data;
            temp->next = NULL;
            rear->next = temp;
            rear = rear->next;
        }
        First = *List1;
        found = 0;
        Second = Second->next;
    }
}

Node Intersection(Node* List1,Node List2){
    Node First = *List1;
    Node Second = List2;
    Node Inter = NULL;
    Node rear;
    Node temp;
    int found = 0;
    while(Second){
        while(First){
            if(First->data == Second->data){
                found = 1;
                break;
            }
            First = First->next;
        }
        if(found){
            temp = getNode();
            temp->data = Second->data;
            temp->next = NULL;
            if(Inter == NULL){
                Inter = temp;
                rear = Inter;
            }
            else{
                rear->next = temp;
                rear = rear->next;
            }
        }
        First = *List1;
        found = 0;
        Second = Second->next;
    }
    return Inter;
}

void main(){
    Node List1 = NULL;
    Node List2 = NULL;
    InsertRear(&List1,1);
    InsertRear(&List1,2);
    printf("List 1: ");
    display(List1);
    InsertRear(&List2,2);
    InsertRear(&List2,3);
    printf("List 2: ");
    display(List2);
    Node inter = Intersection(&List1,List2);
    Union(&List1,List2);
    printf("Union: ");
    display(List1);
    printf("Intersection: ");
    display(inter);
}