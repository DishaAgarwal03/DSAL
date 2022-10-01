#include<stdio.h>

void copy(char *s1, char *s2, int i)
{
    s2[i] = s1[i];
    if (s1[i]=='\0')
        return;
    copy(s1, s2, i+1);
}

void main()
{
    char s[30], sc[30];
    printf("Enter a string: ");
    scanf("%s", s);
    copy(s, sc, 0);
    printf("First String: %s \nSecond String: %s\n", s, sc);
}
