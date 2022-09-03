#include<stdio.h>
#include<stdlib.h>

int Smallest(int* p, int n)
{
    int i, s;
    s=*p;
    for(i=1;i<n;i++)
        if (*(p+i)<s)
            s=*(p+i);
    return s;
}

void main()
{
    int n, i, *a;
    printf("Enter the size of the array: ");
    scanf("%d",&n);

    a = (int *)malloc(sizeof(int)*n);
    if(a==NULL)
    {
        printf("Could not allocate memory!");
        exit(1);
    }
    
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("The smallest element in the array is: %d \n", Smallest(a, n));
}

