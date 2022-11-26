//multiply function probably not correct 
#include<stdio.h>
#include<stdlib.h>

typedef struct node* Node;

typedef struct node{
    int val;
    int e;
    Node next;
}node;

Node getnode(){
    Node temp = (Node)malloc(sizeof(node));
    return temp;
}

void InsertLast(Node* li,int val,int e){
    Node temp = getnode();
    Node rear = *li;
    temp->val = val;
    temp->e = e;
    if(*li == NULL){
        temp->next = temp;
        *li = temp;
        return;
    }
    while(rear->next != *li){
        rear =rear->next;
    }
    temp->next = *li;
    rear->next= temp;
    return;
}

void display(Node li){
    Node temp = li;
    do{
        printf("%dx^%d ",temp->val,temp->e);
        temp = temp->next;
    }while(temp != li);
}

/*Node addpoly(Node Pa, Node Pb){
    Node result = NULL;
    Node A = Pa;
    Node B = Pb;
    do{
        if(Pa->e == Pb->e){
            InsertLast(&result,Pa->val+Pb->val,Pa->e); 
            Pa = Pa->next;
            Pb = Pb->next;
        }
        else if(Pa->e > Pb->e){
            InsertLast(&result,Pa->val,Pa->e);
            Pa = Pa->next;
        }
        else if(Pa->e < Pb->e){
            InsertLast(&result,Pb->val,Pb->e);
            Pb = Pb->next;
        }
    }while(Pb != B || Pa != A);
    return result;
}*/

Node subpoly(Node Pa, Node Pb){
    Node result = NULL;
    Node A = Pa;
    Node B = Pb;
    do{
        if(Pa->e == Pb->e){
            InsertLast(&result,Pa->val-Pb->val,Pa->e); 
            Pa = Pa->next;
            Pb = Pb->next;
        }
        else if(Pa->e > Pb->e){
            InsertLast(&result,Pa->val,Pa->e);
            Pa = Pa->next;
        }
        else if(Pa->e < Pb->e){
            InsertLast(&result,Pb->val,Pb->e);
            Pb = Pb->next;
        }
    }while(Pb != B || Pa != A);
    return result;
}

Node mulpoly(Node Pa, Node Pb){
    Node result = NULL;
    Node A = Pa;
    Node B = Pb;
    do{
        if(Pa->e == Pb->e){
            InsertLast(&result,Pa->val*Pb->val,Pa->e); 
            Pa = Pa->next;
            Pb = Pb->next;
        }
        else if(Pa->e > Pb->e){
            InsertLast(&result,Pa->val,Pa->e);
            Pa = Pa->next;
        }
        else if(Pa->e < Pb->e){
            InsertLast(&result,Pb->val,Pb->e);
            Pb = Pb->next;
        }
    }while(Pb != B || Pa != A);
    return result;
}

void createPoly(Node* Pa){
    int val,e;
    printf("Enter 1 to exit\n");
    while(1){
        printf("Enter the value,exponent: ");
        scanf("%d %d",&val,&e);
        if(val == 1)
            break;
        InsertLast(Pa,val,e);
    }
}

void main(){
    Node Pa = NULL;
    Node Pb = NULL;
    Node res;
    int choice = 0;
        printf("1.Create Polynomial a\n2.Create Polynomial b\n4.Subtract\n5.Multiply\n6.Exit\n");
        while(choice != 6){
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        if(choice == 1){
            createPoly(&Pa);
        }
        else if(choice == 2){
            createPoly(&Pb);
        }
        /*else if(choice == 3){
            res = addpoly(Pa,Pb);
            printf("After addition:\n");
            display(res);
        }*/
        else if(choice == 4){
            res = subpoly(Pa,Pb);
            printf("After subtraction:\n");
            display(res);
        }
        else if(choice == 5){
            res = mulpoly(Pa,Pb);
            printf("After multiplication:\n");
            display(res);
        }
        else{
            choice = 6;
        }
    }
}
