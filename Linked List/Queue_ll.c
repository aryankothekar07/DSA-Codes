#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* next;
};
void enqueue(struct Node** head)
{
    int data;
    printf("Enter value to enqueue: ");
    scanf("%d", &data);
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	if(*head == NULL)
	{
		*head = newNode;
		return;
	}
	struct Node* temp = *head;
	while(temp->next != NULL)
	{
		temp = temp->next; 
	}
	temp->next = newNode;
}
void dequeue(struct Node** head)
{
	struct Node* temp = *head;
	if(temp == NULL)
	{
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }
    printf("Popped element: %d\n", temp->data);
	*head = temp->next;
	free(temp);
    
}
void display(struct Node* head)
{
	struct Node* temp = head;
	while(temp != NULL)
	{
		printf("%d --> ", temp->data);
		temp = temp->next;
	}
    printf("NULL\n");
}
int main() {
    struct Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\n--- Queue Using Linked List Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            	enqueue(&head);
            	break;
            case 2:
                dequeue(&head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
