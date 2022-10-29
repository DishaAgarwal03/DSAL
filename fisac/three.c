#include<stdio.h>
#include<stdlib.h>

typedef struct emp{
int a;
struct emp *next;
}node;

node *h,*ta;

void input(node *p){
    printf("Enter a number \n");
    scanf("%d",&(p->a));
    p->next=NULL;
}
    
void ad(node *p,node *q){
    node *t;
    t= (node*)calloc(1,sizeof(node));
    t->a=p->a +q->a;
    q->next=t;
    t->next =NULL; 
}

void main()
{
    int ch;
    h= NULL;
    node *t;
    int k ,y;
    
    h=(node*)calloc(1,sizeof(node));
    h->a=0;
    t=(node*)calloc(1,sizeof(node));
    t->a=1;
    h->next=t;
    t->next=NULL;
    printf("enter number of terms ");
    scanf("%d",&y);

    if(y==1)
        printf("%d\n",h->a);
    else
        if(y==2)
            printf("%d\t%d\n",h->a,t->a);
        else{
                printf("%d\t%d\t",h->a,t->a);
                for(t=h,k=2;k<y;k++,t=t->next)
                {
                ad(t,t->next);
                printf("%d\t",t->next->next->a);
                }
                printf("\n");
            }
    
}