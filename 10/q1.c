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

void insertl(node *list, int d)
{
    node temp;
    temp=getnode(temp);
    temp->data=d;
    temp->r=NULL;
    temp->l=NULL;
    if(*list){   
        (*list)->l=temp;
        temp->r=*list;
    }
    *list=temp;     //freeing temp will result in 0 being printed infinite times
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

void deletel(node *list)
{
    node temp=*list;
    if(*list==NULL)
    {
        printf("Underflow!\n");
        return;
    }
    *list=temp->r;
    if(*list)   (*list)->l=NULL;
    printf("Deleted %d\n",temp->data);
    free(temp);
}

void deleter(node *list)
{
    node temp, rear=*list;
    if(*list==NULL)
    {
        printf("Underflow!\n");
        return;
    }
    while(rear->r)
        rear=rear->r;
    temp=rear;
    rear=rear->l;
    if(rear==NULL) *list=NULL;  //error in logic without this
    if(rear)    rear->r=NULL;
    printf("Deleted %d\n",temp->data);
    free(temp);
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

void main()
{
    node list=NULL;
    int ch,d;
    printf("1)Insert front 2)Insert rear 3)Delete front 4)Delete rear 5)Display 6)Exit\n\n");
    do{
        printf("Enter choice: ");
        scanf("%d",&ch);
        if(ch==1||ch==2)
        {
            printf("Enter data: ");
            scanf("%d",&d);
        }
        if(ch==1) insertl(&list,d);
        else if(ch==2) insertr(&list,d);
        else if(ch==3) deletel(&list);
        else if(ch==4) deleter(&list);
        else if(ch==5) display(list);
        else ch=6;
    }while(ch!=6);
}