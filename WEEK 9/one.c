#include<stdio.h>
#include<stdlib.h>

typedef struct Q* Q_ptr; //cannot write Q* instead of struct Q*

typedef struct Q{
    int data;
    Q_ptr link;
}Q;

Q_ptr get_node(Q_ptr q)
{
    q=(Q_ptr)malloc(sizeof(Q));
    q->link=NULL;
    return q;
}

Q_ptr enqueue(Q_ptr q, int d)
{
    Q_ptr t,rear;

    if(q==NULL)
    {
        q=get_node(q);
        q->data=d;
        printf("Added first node with data %d\n",q->data);
        return q;
    }
    rear=get_node(rear);
    rear=q;
    printf("%d\n",rear->data);
    t=get_node(t);
    while(rear->link!=NULL)
    {
        printf("%d\n",rear->data);
        rear=rear->link;
    }
    t->data=d;
    t->link=NULL;
    rear->link=t;
    printf("Added\n");
    return q;

}

Q_ptr dequeue(Q_ptr q)
{
    Q_ptr temp;
    temp=get_node(temp);
    if (q==NULL)
        printf("\nUnderflow!");
    else
    {
        
        temp=q;
        q=q->link;
    }
    printf("\nDeleted %d\n",temp->data);
    return q;
}

void display(Q_ptr q)
{
    Q_ptr t;
    t=q;
    if(t==NULL)
    {
        printf("\nEmpty queue!");
        return ;
    }
    do{
        printf("%d  ",t->data);
        t=t->link;
    }while(t!=NULL);
}

void main()
{
    Q_ptr q;
    int ch, data;
    q=NULL;
    printf("1) Enqueue 2)Dequeue 3)Display 4)Exit\n\n");
    do
    {
        printf("Enter Choice: ");
        scanf("%d",&ch);
        if (ch==1)  
        {
            printf("Enter data: ");
            scanf("%d",&data);
            q=enqueue(q,data);
        }
        else if(ch==2)  q=dequeue(q);
        else if(ch==3)  display(q);
        else ch=4;
    }while(ch!=4);
}