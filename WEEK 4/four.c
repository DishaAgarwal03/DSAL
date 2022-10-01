#include<stdio.h>

int TOH(int n,char x,char y,char z) 
{
   static int c=0;
   if(n>0) 
   {
    TOH(n-1,x,z,y);
    c++;
    printf("\n%c to %c",x,y);
    TOH(n-1,z,y,x);
   }
   else
      return c;
}

void main() 
{
   int n;
   printf("Enter the number of disks: ");
   scanf("%d", &n);
   int c = TOH(n,'A','B','C');
   printf("\nNumber of moves required: %d\n\n", c);
}