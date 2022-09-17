#include<stdio.h>

typedef struct
{
    int r;
    int im;
} COMPLEX;

void read(COMPLEX *c)
{
    printf("Enter the real and imaginary part of a complex number: ");
    scanf("%d %d", &c->r, &c->im);
}

void add(COMPLEX *c1, COMPLEX *c2, COMPLEX *sum)
{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
sum->r = c1->r + c2->r;
sum->im = c1->im + c2->im;
}

void subtract(COMPLEX *c1, COMPLEX *c2, COMPLEX *diff)
{
diff->r = c1->r - c2->r;
diff->im = c1->im - c2->im;
}

void multiply(COMPLEX *c1, COMPLEX *c2, COMPLEX *prod)
{
prod->r = (c1->r * c2->r) - (c1->im * c2->im);
prod->im = (c1->r * c2->im) + (c1->im * c2->r);
}

void display(COMPLEX ans)
{
    if (ans.im > 0)
        printf("%d+%di \n", ans.r, ans.im);
    else if (ans.im < 0)
        printf("%d%di \n", ans.r, ans.im);
    else
        printf("%d \n", ans.r);
}

void main()
{
    COMPLEX c1, c2, sum, diff, prod;
    read(&c1);
    read(&c2);

    add(&c1,&c2,&sum);
    subtract(&c1,&c2,&diff);
    multiply(&c1,&c2,&prod);

    printf("The sum is: ");
    display(sum);

    printf("The difference is: ");
    display(diff);

    printf("The product is: ");
    display(prod);
}