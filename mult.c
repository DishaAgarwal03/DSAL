#include<stdio.h>

void display(int f[][50], int r, int c)
{
    int i, j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            printf("%d ",f[i][j]);
        printf("\n");
    }  
}

void Multiply(int a[][50], int b[][50], int m, int k, int n)
{
    int i, j, l, c[50][50];
    
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            c[i][j]=0;
            for(l=0;l<k;l++)
                c[i][j]+=a[i][l]*b[l][j];
        }
    printf("\nThe Resultant Matrix is: \n");
    display(c,m,n);
}

void main()
{
    int a[50][50], b[50][50], i, j, r1, r2, c1, c2;

    //Reading matrix 1
    printf("Enter number of rows and columns of matrix 1: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter the elements of matrix 1: ");
    for(i=0;i<r1;i++)
        for(j=0;j<c1;j++)
            scanf("%d",&a[i][j]);

    //Reading matrix 2
    printf("Enter number of rows and columns of matrix 2: ");
    scanf("%d %d", &r2, &c2);
    printf("Enter the elements of matrix 2: ");
    for(i=0;i<r2;i++)
        for(j=0;j<c2;j++)
            scanf("%d",&b[i][j]);

    //Displaying matrix 1    
    printf("\nMatrix 1: \n");
    display(a,r1,c1);

    //Displaying matrix 2    
    printf("\nMatrix 2: \n");
    display(b,r2,c2);

    //Checking if multiplication is possible
    if(c1==r2)
        Multiply(a,b,r1,c1,c2);
    else
       printf("\nMultiplication not possible\n");
}


