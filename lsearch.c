#include<stdio.h>

void Lsearch(int a[], int n, int num)
{
    int *p=a;
    
    while(n>0)
    {
        n--;
        if(*p==num)
        {
            printf("%d is present at index %ld i.e position %ld \n", num, p-a, p-a+1);
            return;
        }
        p++;
    }
    printf("%d is not present in the array\n",num);
}

void main()
{
    int n, i, a[50], num;

    printf("Enter size of the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the number to be searched: ");
    scanf("%d",&num);

    Lsearch(a,n,num);
}


