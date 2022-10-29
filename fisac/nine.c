#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
	char data;
	struct node* next;
}node;

node* add(char data)
{
	node* newnode = ( node*) malloc(sizeof( node));
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}

node* create(char text[50] )
{	node* head=NULL;
	head = add(text[0]);
	node* curr = head;

	for (int i = 1; i < strlen(text); i++) {
		curr->next = add(text[i]);
		curr = curr->next;
	}
	return head;
}
int isVowel(char x)
{
    return (x == 'a' || x == 'e' || x == 'i'
            || x == 'o' || x == 'u' || x == 'A'
            || x == 'E' || x == 'I' || x == 'O'
            || x == 'U');
}

void allVowels(node* head)
{

    node* ptr = head;
    while (ptr != NULL) {

        if (isVowel(ptr->data))
           ptr = ptr->next;

        else
            break;
    }
	ptr=head;
    node* prev = ptr;

    ptr = ptr->next;
    while (ptr != NULL) {
        if (isVowel(ptr->data)) {
            ptr = ptr->next;
            while (ptr != NULL)
			{
                if (isVowel(ptr->data)) {
                    ptr = ptr->next;
                }
                else
                    break;
            }

            if (ptr == NULL) {
                prev->next = NULL;
                break;
            }

            else {
                prev->next = ptr;
            }
        }
 
        prev = prev->next;
        ptr = ptr->next;
    }
}

void print(node* head)
{
	node* curr = head;
	while (curr != NULL) {
        printf("%c", curr->data);
		 if(curr->next!=NULL)
    	printf("->");
    	else
    	printf("\n");
		curr = curr->next;
	}
}

int main()
{	char text[50];
	printf("Enter your name\n");
	scanf("%s",text);
	

	node* head = NULL;
	head = create(text);
	node* vowel = NULL;
	print(head);

	allVowels(head);
	print(head);
	return 0;
}
