#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* next;
};
void push(struct Node** head)
{
    int data;
    printf("Enter value to push: ");
    scanf("%d", &data);
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
    printf("\n");
}
void pop(struct Node** head)
{
	struct Node* temp = *head;
	if(temp == NULL)
	{
        printf("Stack Underflow! Stack is empty.\n");
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
int main() 
{
    struct Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\n--- Stack Using Linked List Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            	push(&head);
            	break;
            case 2:
                pop(&head);
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
