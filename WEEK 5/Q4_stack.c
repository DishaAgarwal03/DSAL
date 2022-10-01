#include<stdio.h>

void push(int *ps,int x, int *top)
{   
    (*top)++;
    ps[*top]=x;
}

void delete(int *ps, int *top, int  i)
{
    for(int j=i;j<*top;j++)
        ps[j]=ps[j+1];
    (*top)--;
}

void main()
{
    int a[20], k, i, n, m=0, top=-1, e;
    printf("Enter the array length and the number of elements to be deleted: ");
    scanf("%d %d", &n, &k);
    printf("Enter %d elements: ", n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &e);
        push(a, e, &top);
    }

    for(i=0; i<top && m<k; i++)
        {
            if(a[i]<a[i+1])
            {
                printf("%d", a[i]);
                delete(a, &top, i);
                i=-1;
                m++;
            }
        }
    printf("Modified Array is: ");
    for(i=0; i<=top; i++)
        printf("%d ", a[i]);
    printf("\n");

}