#include<stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct
{
    int day;
    char *month;
    int year;
} DOB;

typedef struct
{
    long int reg_no;
    char *name;
    char address[50];
} STU_INFO;

typedef struct
{
    char *college_name;
    char uni_name[30];
} COLLEGE;

typedef struct
{
    DOB *d;
    STU_INFO s;
    COLLEGE c;
} STUDENT;

void read(STUDENT *st)
{
    char n[40];
    printf("\nEnter the details of the Student:");

    printf("\nRegistration number: ");
    scanf("%ld", &(st->s.reg_no));
    getchar();
    printf("Name: ");
    gets(n);
    st->s.name=(char*)calloc(strlen(n)+1,sizeof(char));
    strcpy(st->s.name,n);
    printf("Address: ");
    gets(st->s.address);

    printf("Day, Month and Year of Birth: ");
    scanf("%d", &(st->d->day));
    getchar();
    scanf("%s %d", n, &(st->d->year));
    st->d->month=(char*)calloc(strlen(n)+1,sizeof(char));
    strcpy(st->d->month,n);
    getchar();

    printf("College name: ");
    gets(n);
    st->c.college_name=(char*)calloc(strlen(n)+1,sizeof(char));
    strcpy(st->c.college_name,n);
    printf("University name: ");
    gets(st->c.uni_name);
}

void display(STUDENT *st)
{
    printf("\n\nThe Details are:");
    printf("\nRegistration number:  %ld ", st->s.reg_no);
    printf("\nName: ");
    puts(st->s.name);
    printf("Address: ");
    puts(st->s.address);

    printf("Date of Birth: %d %s %d", st->d->day, st->d->month, st->d->year);

    printf("\nCollege: ");
    puts(st->c.college_name);
    printf("University: ");
    puts(st->c.uni_name);
}

void main()
{
    STUDENT *st;
    st=(STUDENT*)malloc(sizeof(STUDENT));
    st->d=(DOB*)malloc(sizeof(DOB));
    read(st);
    display(st);
}