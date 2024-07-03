/*Name : keerthick vasa M
Date : 03/07/2024
description :push and pop inmplement
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define SUCCESS 0
#define FAILURE -1
typedef struct stack
{
    unsigned int capacity;
    int top;
    int *stack;
}Stack_t;
int create_stack(Stack_t *stk, int size)
{
    stk->stack=malloc(sizeof(int)*size);
    if(stk->stack==NULL)
    {
	return FAILURE;
    }
    else
    {
	stk->top=-1;
	stk->capacity=size;
    }

}
int Push(Stack_t *s, int element)
{
    if(s->top==(s->capacity)-1)     
    {
	return FAILURE;
    }
    else
    {
	s->top++;
	s->stack[s->top]=element;   
	return SUCCESS;
    }
}
int Pop(Stack_t *s)
{
    if(s->top==-1)
    {
	return FAILURE; 
    }
    else
    {
	s->top--;  
    }  

}
void Peep(Stack_t s)
{
    if (s.top == -1)
    {
	printf("INFO : Stack is empty\n");
    }
    else
    {
	printf("Top -> ");
	while (s.top > -1)
	{
	    printf("%d ", (s.stack[(s.top)--]));
	}
	printf("\n");
    }
    return ;
}
int main()
{
    int choice, element, peek, size;
    Stack_t stk;

    printf("Enter the size of the stack: ");
    scanf("%d", &size);

    create_stack(&stk, size);
    printf("1. Push\n2. Pop\n3. Display Stack\n4. Exit\n");

    while (1)
    {
	printf("Enter your choice : ");
	scanf("%d", &choice);
	switch(choice)
	{
	    case 1:
		printf("Enter the element to be pushed in stack : ");
		scanf("%d", &element);
		if (Push(&stk, element) == FAILURE)
		{
		    printf("INFO : Stack Full\n");
		} 
		break;
	    case 2:
		if (Pop(&stk) == FAILURE)
		{
		    printf("INFO : Stack is empty\n");
		}
		else
		{
		    printf("INFO : Pop operation is successfull\n");
		}
		break;
	    case 3:
		Peep(stk);
		break;
	    case 4:
		exit(0);
		break;
	}
    }
}



