#include<stdio.h>
#include<string.h>
void palin(char *s, int i, int n)
{
    if (s[i]!=s[n-i-1])
    {
        printf("It is not palindrome\n");
        return;
    }
    else if (i==n/2-1)
    {
        printf("It is Palindrome\n");
        return;
    }
    palin(s, i+1, n);
}

void main()
{
    char s[30];
    printf("Enter a string: ");
    scanf("%s", s);
    palin(s, 0, strlen(s));
}
