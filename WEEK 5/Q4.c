#include<stdio.h>

void main()
{
    int a[20], k, i, n, m=0, j;
    printf("Enter the array length and the number of elements to be deleted: ");
    scanf("%d %d", &n, &k);
    printf("Enter %d elements: ", n);
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    for(i=0; i<n-1 && m<k; i++)
        {
            if(a[i]<a[i+1])
            {
                for(j=i;j<n-1;j++)
                    a[j]=a[j+1];
                n--;
                i=-1;
                m++;
            }
        }
    printf("Modified Array is: ");
    for(i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");

}