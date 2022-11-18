#define MAX 20

typedef struct 
{
    char a[MAX];
    int top;
}stack;

int isOperator(char a)
{
    switch(a)
    {
        case '+':
        case '-':
        case '%':
        case '*':
        case '/':
        case '^': return 1;
    }
    return 0;
}

int empty(stack *s)
{ return s->top==-1?1:0; }

int full(stack *s)
{ return s->top==MAX-1?1:0; }

void push(stack *s,char* x)
{
    if (full(s)) return;
    (s->top)++;
    s->a[s->top]=*x;
}

char* pop(stack *s)
{   
    if (empty(s)) return '#';
    return(s->a[(s->top)--]); 
}