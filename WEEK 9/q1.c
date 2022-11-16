#include<stdio.h>
#include<stdlib.h>
#include "list_op.c"



void main(){
    Node q = NULL;
    int ch, data;
    printf("1)Insert 2)Delete 3)Display 4)Exit");
    do
    {
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        if (ch==1)  
        {
            printf("Enter data: ");
            scanf("%d",&data);
            InsertRear(&q,data);
        }
        else if(ch==2)  DeleteFront(&q);
        else if(ch==3)  display(q);
        else ch=4;
    } while (ch!=4);
}
