#include<stdio.h>
#include "stack_opn.h"

void main()
{
    char a[20], ch;
    int c=1;
    stack s;
    s.top=-1;
    while(c!=4)
    {
        printf("\nEnter \n1 to push \n2 to pop \n3 to display \n4 to exit \n");
        scanf("%d", &c);
        if (c==1) 
        {
            getchar();
            printf("\nEnter a Character: ");
            scanf("%c", &ch);
            push(&s, ch);
        }
        else if (c==2) 
        {
            char x = pop(&s);
            if (x!='#')
                printf("\nElement popped: %c \n", x);
        }
        else if (c==3) display(&s);
        else if (c==4);
        else printf("\nInvalid Input! \n");
    }
    
}

