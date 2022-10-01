#include<stdio.h>
#include<string.h>
#include "stack_opn.h"

void main()
{
    char a[15];
    int i, f=1;
    stack s;
    s.top=-1;

    printf("Enter a string: ");
    scanf("%s", a);
    int l = strlen(a);
    for(i=0; i<l/2; i++)
        push(&s, a[i]);
    if (l%2==1)
        i++;
    for(;i<l;i++)
        if (pop(&s)!=a[i])
            {
                f=0;
                break;
            }  

    if (f)
        printf("It is Palindrome\n");
    else
        printf("It is not Palindrome\n");

}