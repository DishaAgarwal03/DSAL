#include<stdio.h>
#include<stdlib.h>
typedef struct emp{
int a;
struct emp *next;
}node;

node *h,*ta,*ta2,*h2;

void input(node *p){
    scanf("%d",&(p->a));
    p->next=NULL;
    }

void sort1(node *p){
    node *t;
    int b=0;
    if(h->a>p->a){
        p->next=h;
        h =p;
        return;

    }
    for(t=h;t->next!=NULL;t=t->next){
        if(p->a<t->next->a){
            b =1;
            break;
        }}
        if(b==1){
            p->next=t->next;
            t->next=p;

        }
        else{
            t->next=p;
    //2p->next =NULL;

           // ta=p;
        }

    }

void ad(){
    node *t;
    t= (node*)calloc(1,sizeof(node));
    input(t);
    if(h==NULL)
        h = t;
    else
        sort1(t);
    }

void sort2(node *p){
    node *t;
    int b=0;
    if(h2->a>p->a){
        p->next=h2;
        h2 =p;
        return;

    }
    for(t=h2;t->next!=NULL;t=t->next){
        if(p->a<t->next->a){
            b =1;
            break;
        }
        }
        if(b==1){
            p->next=t->next;
            t->next=p;

        }
        else{
            t->next=p;

            ta2=p;
        }
    }

void ad1(){
    node *t;
    t= (node*)calloc(1,sizeof(node));
    input(t);
    if(h2==NULL)
        h2 = t;
    else
        sort2(t);
    }
    void print(node *p){
    printf(" %d ",p->a);

    }

void myl(){
    if(h==NULL){
        printf(" list is empty \n");
        return;

    }
    node *t;
    for(t= h;t!=NULL;t=t->next)
    {
        print(t);
    }
    printf("\n");
    }
    
void myl1(){
    if(h2==NULL){
        printf(" list is empty \n");
        return;

    }
    node *t;
    for(t= h2;t!=NULL;t=t->next)
    {
        print(t);
    }
    printf("\n");
    }

void finalsort(node *p)
{
    node *t,*temp;

    int b=0;
    if(h->a>p->a)
    {
        p->next=h;
        h =p;
        return;

    }
    for(t=h;t->next!=NULL;t=t->next)
    {
        if(p->a<t->next->a)
        {
            b =1;
        break;
        }
    }

    if(b==1)
    {
        p->next=t->next;
        t->next=p;
    }
    else
    {
        t->next=p;
        p->next =NULL;
        ta=p;
    }
}

void main()
{
    int ch,i,n1;
    h= NULL;
    int n;
    node *t;
    printf("enter total elements in list 1  ");
    scanf("%d",&n);
    printf("enter %d numbers:  \n", n);
    for(i=0;i<n;i++)
        ad();
    printf("enter total elements in list 2  ");
    scanf("%d",&n1);
    printf("enter %d numbers:  \n", n1);
    for(i=0;i<n1;i++)
        ad1();
    node *temp;
    myl();
    myl1();
    for(t=h2;t!=NULL;)
    {
        temp=t->next;
        finalsort(t);
        t=temp;
    }
    myl();
}

