#include<stdio.h>
#include<stdlib.h>
int front = -1, rear = -1;
int N, x;
int *queue;
void enqueue()
{
	if(rear >= N - 1)
		printf("Queue is full\n");
	else if(front == -1 && rear == -1)
	{
		front = 0;
		rear = 0;
		printf("Enter value: ");
		scanf("%d", &x);
		queue[rear] = x;
	}
	else
	{
		printf("Enter value: ");
		scanf("%d", &x);
		rear++;
		queue[rear] = x;
	}
}
void dequeue()
{
	if(front == -1 && rear == -1)
		printf("Queue is empty\n");
	else if(front == rear)
	{
		printf("%d\n", queue[front]);
		front = -1;
		rear = -1;
	}
	else
	{
		printf("%d\n", queue[front]);
		front++;
	}
}
void display()
{
	int i;
	printf("Queue: ");
	for(i = front; i <= rear; i++)
	{
		printf("%d ", queue[i]);
	}
	printf("\n");
}
int main()
{
	printf("Enter length of queue: ");
	scanf("%d", &N);
	queue = (int*) calloc(N, sizeof(int));
	if(queue == NULL)
	{
		printf("Memory allocation failed\n");
		return 1;
	}
	int option;
	do
	{
		printf("Menu\n 1. Enqueue\n 2. Dequeue\n 3. Display queue\n 4. Exit\n Enter your choice: ");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
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
