#include<stdio.h>

void main()
{
    int n, i, a[50], *p;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    p=a;
    
    for(i=0;i<n;i++)
    {
        printf("%d ",*p);
        p++;
    }
    printf("\n");

    for(i=0;i<n;i++)
    {
        printf("%d ",*p);
        p--;
    }
    printf("\n");
}
