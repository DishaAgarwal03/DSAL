#include <stdio.h>  
#define SIZE 30  
int a[SIZE], top1 = -1, top2 = SIZE;  
    
void push1(int n)  
{
    if (top1 < top2 - 1)   
        a[++top1] = n;  
    else  
        printf("Stack is Full\n");  
}  
 
void push2(int n)  
{     
    if (top1 < top2 - 1)  
        a[--top2] = n;   
    else  
        printf ("Stack is Full\n");  
}  
   

void pop1()  
{    
    if (top1 != -1)         
        printf ("Element popped from Stack 1: %d\n", a[top1--]); 
    else  
        printf ("Stack 1 is Empty\n");  
}  
 
void pop2()  
{     
    if (top2 != SIZE)  
        printf ("Element popped from Stack 2: %d\n", a[top2++]);  
    else  
        printf ("Stack 2 is Empty!\n");  
}  
    
void display1()  
{  
    for (int i = 0; i <= top1; ++i)  
        printf ("%d  ", a[i]);  
    printf ("\n");  
}  
 
void display2()  
{  
    for (int i = SIZE-1; i >= top2; --i)  
        printf ("%d  ", a[i]);  
    printf ("\n");  
}  
   
void main()  
{   
    int i, c, e;  
    while(1)
    {
        printf("\n1,4) Push \n2,5) Pop \n3,6) Display \n7)   Exit \n\nEnter 1,2,3 for operation on Stack 1 \nOr 4,5,6 for operation on Stack 2 \nOr 7 to exit\n");
        scanf("%d", &c);
        if (c==1 || c==4) 
        {
            printf("\nEnter element: ");
            scanf("%d", &e);
        }
        if (c==1) push1(e);
        else if (c==2) pop1();
        else if (c==3) display1();
        else if (c==4) push2(e);
        else if (c==5) pop2();
        else if (c==6) display2();
        else if (c==7) break;
        else printf("\nInvalid Input\n");
    }
}   
