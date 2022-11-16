//instead of integers include words as data
#include<stdio.h>
#include<stdlib.h>
typedef struct n* node;
typedef struct n{
    int data;
    node l,r;
}n;

node getnode(node l)
{
    l=(node)malloc(sizeof(n));
    return l;
}

void insertr(node *list, int d)
{
    node temp, rear=*list;
    temp=getnode(temp);
    temp->data=d;
    temp->r=NULL;
    temp->l=NULL;
    if(*list==NULL)
    {
        *list=temp;
        return;
    }
    while(rear->r)
        rear=rear->r;
    rear->r=temp;
    temp->l=rear;
}

void display(node list)
{
    if(list==NULL)
    {
        printf("Empty List\n");
        return;
    }
    while(list)
    {
        printf("%d  ",list->data);
        list=list->r;
    }
    printf("\n");
}

void Rev(node *list)
{
    node temp,curr,prev;
    curr=*list;
    while(curr)
    {
        prev=curr;
        temp=curr->l;
        curr->l=curr->r;
        curr->r=temp;
        curr=curr->l;
    }
    *list=prev;
}

void main()
{
    node list=NULL;
    insertr(&list,1);
    insertr(&list,2);
    insertr(&list,3);
    insertr(&list,4);
    display(list);
    Rev(&list);
    display(list);
}
