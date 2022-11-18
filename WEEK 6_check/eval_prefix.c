#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "eval.h"

void main()
{
    stack s;
    char e[30], x;
    int op1,op2,val;
    s.top=-1;
    printf("Enter the prefix expression (Single digit operand and operators only): ");
    scanf("%s", e);
    for(int i=strlen(e)-1;i>=0;i--)
    {
        x=e[i];
        if(isdigit(x))
            push(&s,x-'0');
        /*x-‘0’ for removing the effect of ascii */
        else
        {
            op1=pop(&s);
            op2=pop(&s);
            val=evaluate(x,op1,op2);
            push(&s,val);
        }
    }
    printf("The result is %d \n",pop(&s));
}