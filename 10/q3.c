//Add two long positive integers represented using circular doubly linked list with header node.

#include <stdio.h>
#include <stdlib.h>

typedef struct node* Node;
typedef struct node {
    int val;
    Node r;
    Node l;
} node ;

Node getnode(){
    Node temp = (Node)malloc(sizeof(node));
    return temp;
}

void insertNode(Node prev,int x) {
    Node new = getnode();
    new->val = x;
    new->r = prev->r;
    new->l = prev;
    prev->r = new;
}

void input(Node node,int n) {
    int i,temp;
    for (i=0;i<n;i++) {
        printf("Enter: ");
        scanf("%d",&temp);
        if (i == 0) {
            node->val = temp;
            node->r = NULL;
            node->l = NULL;
            continue;
        }
        insertNode(node,temp);
        node = node->r;
    }
}

void makeCirc(Node *list) {
    Node temp = getnode();
    temp = (*list)->r;
    while (temp -> r != NULL)   
        temp = temp->r;
    temp->r = *list;
    (*list)->l = temp;
}

void displayCirc(Node *node) {
    Node temp = getnode();
    temp = (*node)->r;
    printf("The list is: ");
    while(temp != *node) {
        printf("%d ",temp->val);
        temp = temp->r;
    }
    printf("\n");
}

void insertFrontCDLL(Node *list, int x) {
    Node temp = getnode();
    temp->val = x;
    temp->l = *list;
    if ((*list)->r != NULL) {
        temp->r = (*list)->r;
        ((*list)->r)->l = temp;
    }
    else {
        temp->r = *list;
    }
    (*list)->r = temp;
}

void add(Node *li1, Node *li2, Node *li3) {
    Node li1Rev = getnode();
    Node li2Rev = getnode();
    Node temp = getnode();
    temp = (*li1)->r;
    while (temp->r != *li1)
        temp = temp->r;
    li1Rev = temp;
    temp = (*li2)->r;
    while (temp->r != *li2)
        temp = temp->r;
    li2Rev = temp;
    Node head3 = getnode();
    *li3 = head3;
    head3->r = NULL;

    int carry = 0;
    while ((li1Rev != *li1) || (li2Rev != *li2)) {
        // int val1 = li1Rev->val;
        // if (li1Rev == NULL)
        //     val1 = 0;
        // int val2 = li2Rev->val;
        // if (li2Rev == NULL)
        //     val2 = 0;
        int val1 = li1Rev->val;
        int val2 = li2Rev->val;

        int x = val1 + val2 + carry;
        if (x > 10) {
            carry = 1;
            x = x % 10;
        }
        else
            carry = 0;
        insertFrontCDLL(li3,x);
        li1Rev = li1Rev -> l;
        li2Rev = li2Rev -> l;
    }

    if (carry == 1) 
        insertFrontCDLL(li3,1);
}

void main() {
    int n1,n2;
    printf("Enter length of first number ");
    scanf("%d",&n1);
    printf("Enter length of second number ");
    scanf("%d",&n2);

    Node li1 = getnode();
    Node li2 = getnode();
    Node li3 = getnode();
    li3 = NULL;
    Node head1 = getnode();
    Node head2 = getnode();


    printf("Enter first number\n");
    input(li1,n1);
    head1->r = li1;
    li1 = head1;
    makeCirc(&li1);
    (li1->r)->l = li1;
    displayCirc(&li1);
    printf("Enter second number\n");
    input(li2,n2);
    head2->r = li2;
    li2 = head2;
    makeCirc(&li2);
    (li2->r)->l = li2;
    displayCirc(&li2);

    add(&li1,&li2,&li3);
    printf("Result of addition: \n");
    displayCirc(&li3);

}