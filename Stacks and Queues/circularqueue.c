#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;
void enqueue(int value) 
{
    if ((rear + 1) % SIZE == front) 
    {
        printf("Queue is Full\n");
        return;
    }
    if (front == -1) 
    {
        front = 0;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("%d inserted\n", value);
}
void dequeue() 
{
    if (front == -1) 
    {
        printf("Queue is Empty\n");
        return;
    }
    if (front == rear) 
    {
    	printf("%d removed\n", queue[front]);
        front = -1;
        rear = -1;
    } else 
    {
    	printf("%d removed\n", queue[front]);
        front = (front + 1) % SIZE;
    }
}
void display() 
{
    int i = front;
    printf("Queue elements: ");
    while (1) 
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}
int main()
{
	int option;
    int value;
	while(1)
	{
		printf("Menu\n 1. Enqueue\n 2. Dequeue\n 3. Display queue\n 4. Exit\n Enter your choice: ");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
                printf("Enter a value: ");
                scanf("%d", &value);
				enqueue(value);
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
	}
}
