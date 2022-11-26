#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct n* node;
typedef struct n{
    char data[15];
    node l,r;
}n;

node getnode(node l)
{
    l=(node)malloc(sizeof(n));
    return l;
}

void insertr(node *list, char d[])
{
    node temp, rear=*list;
    temp=getnode(temp);
    strcpy(temp->data,d);
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
        printf("%s  ",list->data);
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
    insertr(&list,"My");
    insertr(&list,"name");
    insertr(&list,"is");
    insertr(&list,"Disha");
    display(list);
    Rev(&list);
    display(list);
}