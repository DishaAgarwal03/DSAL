#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    int day;
    char month[20];
    int year;
} DOB;

typedef struct
{
    int h_no;
    int zipcode;
    char state[30];
} ADDRESS;

typedef struct
{
    char name[50];
    DOB d;
    ADDRESS a;
} EMP;

void read(EMP *e, int n)
{
    for (int i=0;i<n;i++)
    {
        printf("\nEnter details of Employee %d:",i+1);
        printf("\nName: ");
        gets(e[i].name);
        printf("Day, Month and Year of Birth: ");
        scanf("%d", &(e[i].d.day));
        getchar();
        scanf("%s %d", e[i].d.month, &(e[i].d.year));
        printf("House number, Zipcode and State: ");
        scanf("%d %d",&(e[i].a.h_no), &(e[i].a.zipcode));
        getchar();
        gets(e[i].a.state);
    }
}

void display(EMP e[], int n)
{
    for (int i=0;i<n;i++)
    {
        printf("\n\nEmployee %d: \nName: ",i+1);
        puts(e[i].name);
        printf("Date of Birth: %d %s %d", e[i].d.day, e[i].d.month, e[i].d.year);
        printf("\nAddress: %d, %d, ", e[i].a.h_no, e[i].a.zipcode);
        puts(e[i].a.state);
    }
}

void main()
{
    int n;
    printf("Enter the number of Employees: ");
    scanf("%d",&n);
    getchar();
    EMP *e=(EMP *)calloc(n, sizeof(EMP));
    read(e, n);
    display(e, n);
}