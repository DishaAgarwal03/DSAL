#define MAX 20

typedef struct 
{
    int a[MAX];
    int top;
}stack;

int evaluate(char x,int op1,int op2)
{
    if(x=='+')
        return(op1+op2);
    if(x=='-')
        return(op1-op2);
    if(x=='*')
        return(op1*op2);
    if(x=='/')
        return(op1/op2);
    if(x=='%')
        return(op1%op2);
}

int empty(stack *s)
{ return s->top==-1?1:0; }

int full(stack *s)
{ return s->top==MAX-1?1:0; }

void push(stack *s,int x)
{
    (s->top)++;
    s->a[s->top]=x;
}

int pop(stack *s)
{ return(s->a[(s->top)--]); }