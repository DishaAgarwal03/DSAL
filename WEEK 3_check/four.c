#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    int day;
    char *month;
    int year;
} DOB;

typedef struct
{
    int reg_no;
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
    printf("\nEnter the details:");

    printf("\nRegistration number:");
    scanf("%d", &(st->s.reg_no));
    getchar();
    fflush(stdin);
    printf("\nName: ");
    gets(n);
    st->s.name=(char*)calloc(strlen(n)+1,sizeof(char));
    printf("Address: ");
    gets(st->s.address);

    printf("Day, Month and Year of Birthday: ");
    scanf("%d", &(st->d->day));
    fflush(stdin);
    scanf("%s %d", st->d->month, &(st->d->year));
    fflush(stdin);

    printf("College name: ");
    gets(st->c.college_name);
    printf("University name: ");
    gets(st->c.uni_name);
}

void display(STUDENT *st)
{
    printf("\n\nRegistration number: %d ", st->s.reg_no);
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
    read(st);
    display(st);
}