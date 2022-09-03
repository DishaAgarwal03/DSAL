#include<stdio.h>

double Add(double a[], int n)
{
    int i;
    double sum=0;
    
    for(i=0;i<n;i++)
        sum+=a[i];
    return sum;
}

void main()
{
    int n, i;
    double a[50], sum;
    printf("Enter size of the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++)
        scanf("%lf",&a[i]);
    sum=Add(a, n);
    printf("The sum of the elements of the array is %lf \n",sum);
}


