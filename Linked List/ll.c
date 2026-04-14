#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* next;
};
void insert_last(struct Node** head, int data)
{
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
void insert_first(struct Node** head, int data)
{
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}
void insert_at_pos(struct Node** head, int data, int pos)
{
	int c = 1;
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = data;
	struct Node* temp = *head;
	if(pos <= 0)
	{
		printf("Invalid position\n");
		return;
	}
	if(pos == 1)
	{
		insert_first(head, data);
		return;
	}
	while(temp != NULL && c < pos - 1)
	{
		temp = temp->next;
		c++;
	}
	if(temp == NULL)
	{
		printf("Position out of bounds\n");
		return;
	}
	newNode->next = temp->next;
	temp->next = newNode;
}
void delete_first(struct Node** head)
{
	if(*head == NULL)
	{
		printf("List is empty. Nothing to delete.\n");
		return;
	}
	struct Node* temp = *head;
	*head = temp->next;
	free(temp);
}
void delete_last(struct Node** head)
{
	if(*head == NULL)
	{
		printf("List is Empty. Nothing to delete.\n");
		return;
	}
	if((*head)->next == NULL)
	{
		delete_first(head);
		return;
	}
	struct Node* temp = *head;
	struct Node* prev = NULL;
	while(temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = temp->next;
	free(temp);
}
void delete_at_pos(struct Node** head, int pos)
{
	if(*head == NULL)
	{
		printf("List is Empty. Nothing to delete.\n");
		return;
	}
	struct Node* temp = *head;
	struct Node* prev = NULL;
	int c = 1;
	if(pos <= 0)
	{
		printf("Invalid position\n");
		return;
	}
	if(pos == 1)
	{
		delete_first(head);
		return;
	}
	while(temp != NULL && c < pos)
	{
		prev = temp;
		temp = temp->next;
		c++;
	}
	if(temp == NULL)
	{
		printf("Position out of bounds\n");
		return;
	}
	prev->next = temp->next;
	free(temp);
}
void search(struct Node** head, int data)
{
	int c = 1;
	if(*head == NULL)
	{
		printf("List is empty\n");
		return;
	}
	struct Node* temp = *head;
	while(temp != NULL && temp->data != data)
	{
		temp = temp->next;
		c++;
	}
	if(temp == NULL)
	{
		printf("Element not found in the list\n");
		return;
	}
	printf("Element %d found at position %d\n", data, c);
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
    int choice, value, pos;

    while (1) 
	{
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at first\n");
        printf("2. Insert at last\n");
        printf("3. Insert at a position\n");
        printf("4. Delete from first\n");
        printf("5. Delete from last\n");
		printf("6. Delete from a position\n");
		printf("7. Search for an element\n");
		printf("8. Display\n");
		printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
		{
            case 1:
                printf("Enter value to insert at first: ");
                scanf("%d", &value);
                insert_first(&head, value);
                break;
            case 2:
            	printf("Enter value to insert at last: ");
            	scanf("%d", &value);
            	insert_last(&head, value);
            	break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
				printf("Enter position: ");
				scanf("%d", &pos);
                insert_at_pos(&head, value, pos);
                break;
			case 4:
                delete_first(&head);
                break;
            case 5:
				delete_last(&head);
            	break;
            case 6:
				printf("Enter position: ");
				scanf("%d", &pos);
                delete_at_pos(&head, pos);
                break;
			case 7:
				printf("Enter the value you wish to search: ");
				scanf("%d", &value);
				search(&head, value);
				break;
            case 8:
                display(head);
                break;
            case 9:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}