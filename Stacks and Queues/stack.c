#include<stdio.h>
#include<stdlib.h>
int N, x, top = -1;
int *stack;
void push()
{
	if(top >= N-1)
	{
		printf("Stack Overflow\n");
	}
	else
	{
		printf("Enter value: ");
		scanf("%d", &x);
		top++;
		stack[top] = x;
	}
}
void pop()
{
	if(top <= -1)
	{
		printf("Stack Underflow\n");
	}
	else
	{
		printf("Popped value: %d\n", stack[top]);
		top--;
	}
}
void display()
{
	int i;
	printf("Stack: ");
	for(i = 0; i <= top; i++)
	{
		printf("%d ", stack[i]);
	}
	printf("\n");
}
int main()
{
	printf("Enter length of stack: ");
	scanf("%d", &N);
	stack = (int *) calloc(N, sizeof(int));
	if(stack == NULL)
	{
		printf("Memory allocation failed\n");
		return 1;
	}
	int option;
	do
	{
		printf("Menu\n 1. Push element in stack\n 2. Pop element from stack\n 3. Display stack\n 4. Exit\n Enter your choice: ");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				return 0;
			default:
				printf("Invalid option");
		}
	}while(option != 4);
}
