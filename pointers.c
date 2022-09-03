#include<stdio.h>

int* add(int *m)
{
    *m+=5;
    return m;   //Returning pointer from a function
}

void main()
{
    int **q, *p, a;

    printf("Enter a number: ");
    scanf("%d",&a);
    p=&a;
    p=add(p);   //Passing pointer to a function
    q=&p;       //q is a pointer to pointer
    **q+=5;
    printf("Accessing the updated value using pointer to pointer: %d \n", **q);  
}

