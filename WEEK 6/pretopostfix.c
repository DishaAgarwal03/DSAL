#include<stdio.h>
#include<string.h>
#include "convert.h"

void main()
{
    stack s;
    char e[30], r[30], *x;
    char op1[3],op2;
    s.top=-1;
    printf("Enter the prefix expression (Single digit operand and operators only): ");
    scanf("%s", e);
    for(int i=strlen(e)-1;i>=0;i--)
    {
        x=e[i];
        if (!(isOperator(x)))
            push(&s,x);
        else
        {
            op1[0]=pop(&s);
            op2=pop(&s);
            strcat(op1,op2);
            strcat(op1,x);
            push(&s,val);
        }
    }
    printf("The result is %d \n",pop(&s));
}