#include<stdio.h>

int fibo(int n)
{
    if (n == 0 || n == 1)
        return n;
    else
        return (fibo(n-1) + fibo(n-2));
}

void main()
{
    int n, i;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci series: ");
    for(i = 0; i < n; i++)
        printf("%d ", fibo(i));
    printf("\n");
}
