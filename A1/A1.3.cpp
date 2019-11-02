

#include <stdio.h>
#include "stdlib.h"

# define NULL 0
# define LEN sizeof(struct node)

int n;

struct node
{
	int num;
	struct node *next;
};

struct node *create()
{	
	// to construct a linked list
	struct node *head;
	struct node *p1, *p2;
	n = 0;
	p1 = (struct node *)malloc(LEN);
	p2 = (struct node *)malloc(LEN);
	p1->num = n;
	head = NULL;

	while (p1->num <= 9)
	{	n = n + 1;
		if (n == 1) head = p1;
		else p2->next = p1;
		p2 = p1;
		p1 = (struct node *)malloc(LEN);
		p1->num = n;
	}
	p2->next = NULL;
	return(head);
}

void print(struct node *head)
{	
	// to print the linked list
	struct node *p;
	printf("The %d numbers are:\n", n);
	p = head;
	if(head!=NULL)
	{	do
		{	printf("%d\n", p->num);
			p = p->next;
		} while (p!=NULL);
	}
}

struct node *reverse(struct node *head) 
{   
	// to rearrange the linked list in the reverse order
	struct node *p1, *p2, *q1, *q2;
	
	q1 = (struct node *)malloc(LEN);
	p1 = head;
	q1->num = p1->num;
	q1->next = NULL;

	while(p1->next!=NULL) 
	{
		p2 = p1;
		p1 = p1->next;
		q2 = q1;
		q1 = (struct node *)malloc(LEN);
		q1->num = p1->num;
		q1->next = q2;
	}

	return q1;
}

void main() 
{
	struct node *ten_numbers;
	struct node *reversed_numbers;
	ten_numbers = create();
	print(ten_numbers);
	reversed_numbers = reverse(ten_numbers);
	print(reversed_numbers);
	getchar();
}