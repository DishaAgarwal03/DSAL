#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct emp{
char a[100];
int r;
int m1,m2,m;
struct emp *next;
}node;

node *head,*tail;

void input(node *p){
    printf("enter name \n");
    scanf("%s",(p->a));
    printf("enter roll number ");
    scanf("%d",&(p->r));
    printf("enter marks 1 and 2 ");
    scanf("%d",&(p->m1));
    scanf("%d",&(p->m2));
    p->m=p->m1+p->m2;
    p->next=NULL;
}

void sort1(node *p){
    node *t;
    int bulb=0;
    if(head->m>p->m){
        p->next=head;
        head =p;
        return;
    }
    for(t=head;t->next!=NULL;t=t->next){
        if(p->m<t->next->m){
            bulb =1;
            break;
        }
    }
    if(bulb==1){
        p->next=t->next;
        t->next=p;
    }
    else{
        t->next=p;
    //p->next =NULL;
        tail=p;
    }
}

void myadd(){
    node *t;
    t= (node*)calloc(1,sizeof(node));
    input(t);
    if(head==NULL)
        head = t;
    else
       sort1(t);
       // tail->next=t;
    //tail=t;
}

void print(node *p){
    printf("{%s, %d, %d}\t",p->a,p->r,p->m);
}

void mylist(){
    if(head==NULL){
        printf(" list is empty \n");
        return;
    }
    node *t;
    printf("Sorted list based on marks: \n");
    for(t= head;t!=NULL;t=t->next)
        print(t);
    printf("\n");
    if(head->next!=NULL){
        for(t=head;t->next->next!=NULL;t=t->next);
        printf("Second highest: \n%s, %d, %d\n",t->a,t->r,t->m);
    }
}

void main(){
    int ch;
    head= NULL;
    do{
        printf("\nEnter \n1)to add values \n2)to display details\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: myadd();break;
            case 2: break;
        }
    }while(ch!=2);
    mylist();
}
