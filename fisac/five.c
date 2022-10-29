#include<stdio.h>
#include<stdlib.h>

typedef struct emp{
int a;
struct emp *next;
}node;

node *head,*tail;

void input(node *p){
    static int c=0;
    printf("Enter data of node %d: ",++c);
    scanf("%d",&(p->a));
    p->next=NULL;
}

void myadd(){
    node *t;
    t= (node*)calloc(1,sizeof(node));
    input(t);
    if(head==NULL)
        head = t;
    else
        tail->next=t;
    tail=t;
}

void print(node *p){
    printf(" %d ",p->a);
}

void mylist(){
    if(head==NULL){
        printf(" list is empty \n");
        return;
    }
    node *t;
    for(t= head;t!=NULL;t=t->next)
        print(t);
    printf("\n");
}

void del(){
    if(head==NULL){
        printf(" list is empty \n"); return;
    }
    int n;
    printf("Enter key to be considered for deletion: ");
    scanf("%d",&n);
    node *t,*k;

    if(head->a==(n*n)){
        t=head;
        head=head->next;
        free(t);
    }
    for(t=head;t->next!=NULL;){
        if(t->next->a==(n*n)){
            k=t->next;
            t->next=k->next;
            free(k);
        }
        else
            t=t->next;
    }
    printf("Element deleted \nList after deletion:\n");
    mylist();
}

void main(){
    int ch,num;
    head= NULL;
    while(1){
        printf("\nEnter 1)to create/add 2)to display 3) to delete 4) to exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter number of nodes to create: ");
                    scanf("%d",&num);
                    for(int i=0;i<num;i++)
                        myadd();
                    break;
            case 2: mylist();break;
            case 3: del();break;
            case 4: exit(0);
        }
    }
}
