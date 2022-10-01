#include<stdio.h>

int sLargest(int a[], int n)
{
    int l=0, sl=-1, i;
 
    // finding the largest element 
    for (i=1; i<n; i++) 
        if (a[i] > a[l])
            l=i;
 
    // finding the second largest element 
    for (i=0; i<n; i++) 
    {
        if (a[i] != a[l]) 
        {
            if (sl == -1)
                sl=i;
            else if (a[i] > a[sl])
                sl=i;
        }
    }
    return sl;
}

void main()
{
    int n, i, a[50], sl;

    printf("Enter size of the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    sl=sLargest(a,n);
    if (sl==-1)
        printf("There is no second largest element \n");
    else
        printf("The second largest element is %d \n",a[sl]);
}


