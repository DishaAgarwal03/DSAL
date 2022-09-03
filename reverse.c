#include<stdio.h>

void Reverse(int* p, int n)
{
    int t, i;
    
    for(i=0;i<n/2;i++)
    {
        t=*(p+i);
        *(p+i)=*(p+n-i-1);
        *(p+n-i-1)=t;
    }
}

void main()
{
    int n, i, a[50];
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    Reverse(a, n);
    printf("Reversed array:\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}

