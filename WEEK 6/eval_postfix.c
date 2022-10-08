#include<stdio.h>
#include<ctype.h>
#include "eval.h"

void main()
{
    stack s;
    char x;
    int op1,op2,val;
    s.top=-1;
    printf("Enter the postfix expression (Single digit operand and operators only): ");
    while((x=getchar())!='\n')
    {
        if(isdigit(x))
            push(&s,x-'0');
        /*x-‘0’ for removing the effect of ascii */
        else
        {
            op2=pop(&s);
            op1=pop(&s);
            val=evaluate(x,op1,op2);
            push(&s,val);
        }
    }
    printf("The result is %d \n",pop(&s));
}