#include<stdio.h>

void push(int *ps,int x, int *top)
{   
    (*top)++;
    ps[*top]=x;
}

int pop(int *ps, int *top)
{
    return (ps[(*top)--]);
}

void main()
{
    int a[64], i, n, top=-1, bnum=0;
    printf("Enter a number: ");
    scanf("%d", &n);
    while(n>0)
    {
        push(a, n%2, &top);
        n/=2;
    }
    while(top>-1)
        bnum=bnum*10+pop(a, &top);
    printf("Binary Representation is: %d\n", bnum);
}
