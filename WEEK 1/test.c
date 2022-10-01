#include<stdio.h>
void main()
{
    int n, i, a[50];
    int *p=a;

    printf("Enter size of the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
     while(p!=NULL)
     {
        printf("%d ",*p);
        p++;
     }
}