#include<stdio.h>
# define MAX 20

typedef struct
{
    char item[MAX];
    int top;
}stack;

int isempty(stack *ps)
{
    if (ps->top==-1)
        return 1;
    else
        return 0;
}

int isfull(stack *ps)
{
    if (ps->top==MAX-1)
        return 1;
    else
        return 0;
}

void push(stack *ps,char x)
{
    if (isfull(ps))
        {
            printf("\nOverflow!\n");
            return; 
        }
    
    ps->top++;
    ps->item[ps->top]=x;
}

char pop(stack *ps)
{
    if (isempty(ps))
    {
            printf("\nUnderflow!\n");
            return '#'; 
    }
    return(ps->item[ps->top--]);
}

void display(stack *ps)
{
    printf("\nArray is:\n");
    for(int i=0; i<=ps->top; i++)
        printf("%c ", ps->item[i]);
    printf("\n");
}

