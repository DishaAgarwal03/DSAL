#include<stdio.h>
#include<stdlib.h>

typedef struct node* Node;
typedef struct node{
    int d;
    Node l,r;
}node;

Node getnode(int k)
{
    Node temp = (Node)malloc(sizeof(struct node));
    temp->l=temp->r=NULL;
    temp->d=k;
    return temp;
}

void insert(Node *root, int k)
{
    Node temp = getnode(k);
    if(*root==NULL) 
    {
        *root=temp;
        return;
    }
    Node x = *root;
    Node y = NULL;
    while(x!=NULL)
    {
        y=x;
        if(k==x->d)     
        {
            printf("Cannot insert duplicate element1\n");
            return;
        }
        else if(k<x->d)
            x=x->l;
        else
            x=x->r;
    }
    if(k<y->d)
        y->l=temp;
    else
        y->r=temp;
}

void delete(Node *root, int k)
{
    Node cur=*root;
    Node prev=NULL;
    while(cur)
    {
        prev=cur;
        if (k<cur->d)
            cur=cur->l;
        else if (k>cur->d)
            cur=cur->r;
        if(cur->d==k)
        {
            //leaf node
            if(cur->l==NULL && cur->r==NULL)
                {
                    if(cur->d>prev->d)  prev->r=NULL;
                    else prev->l=NULL;
                }
            //one child not working
            else if(cur->l==NULL)
                {
                    if(cur->d>prev->d)  prev->r=cur->r;
                    else prev->l=cur->r;
                }
            else if(cur->r==NULL)
                {
                    if(cur->d>prev->d)  prev->r=cur->l;
                    else prev->l=cur->l;
                }
            //two children segmentation fault
            else
            {
                Node x=cur->l;
                Node y=NULL;
                while(x->r)
                {
                    y=x;
                    x=x->r;
                }
                y->r=x->l;
                cur->d=x->d;
            }
            printf("Deleted!\n");
            return;
        }
    }
    printf("Not found!\n");
}

void inorder(Node root)
{
    if (root != NULL) 
    {
        inorder(root->l);
        printf("%d ", root->d);
        inorder(root->r);
    }
}

void main()
{
    int ele, ch;
    Node root = (Node)malloc(sizeof(struct node));
    root=NULL;
    printf("Enter 1)Insert  2)Delete  3)Display  4)Exit\n");
    do
    {
        printf("Enter choice: ");
        scanf("%d",&ch);
        if(ch==1 || ch==2)
        {
            printf("Enter element: ");
            scanf("%d",&ele);
        }
        if(ch==1)
            insert(&root, ele);
        else if(ch==2)
            delete(&root, ele);
        else if(ch==3)
        {
            inorder(root);
            printf("\n");
        }
        else
            ch=4;
    }while(ch!=4);
}