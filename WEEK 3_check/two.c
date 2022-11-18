#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char name[50];
    int roll;
    float cgpa;
} Student;

void read(Student *c)
{
    char t[3];
    gets(t);
    printf("Enter name: ");
    gets(c->name);
    printf("Enter rollnumber and cgpa: ");
    scanf("%d %f", &c->roll, &c->cgpa);
    fflush(stdin);
}

void sort(Student *c[], int n)
{
    int i,j;
    Student *t;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
            if(c[j]->roll > c[j+1]->roll)
            {
                t = c[j];
                c[j] = c[j+1];
                c[j+1] = t;
            }
}

void display(Student s)
{
    printf("Name: ");
    puts(s.name);
    printf(" Roll Number: %d CGPA: %f \n", s.roll, s.cgpa);
}

void main()
{
    int i, n;
    printf("Enter the number of students: ");
    scanf("%d",&n);
    Student *c=(Student*)malloc(sizeof(Student)*n);
    for(i=0;i<n;i++)
        read(&c[i]);
    sort(&c, n);
    printf("After sorting:\n");
    for(i=0;i<n;i++)
        display(c[i]);
}