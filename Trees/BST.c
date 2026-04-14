#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *findMin(struct Node *root)
{
    while(root && root->left != NULL)
        root = root->left;
    return root;
}
struct Node *createNode(int value)
{
    struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
struct Node* insert(struct Node* root, int value)
 {
    if (root == NULL) 
    {
        return createNode(value);
    }

    if (value < root->data) 
    {
        root->left = insert(root->left, value);
    } 
    else if (value > root->data) 
    {
        root->right = insert(root->right, value);
    }

    return root;
}
void inorder(struct Node* root)
{
    if (root != NULL) 
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct Node* root)
{
    if (root != NULL) 
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node* root)
{
    if (root != NULL) 
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
struct Node *delete(struct Node* root, int value)
{
    if(root == NULL)
        return NULL;
    if(value < root->data)
        root->left = delete(root->left, value);
    else if(value > root->data)
        root->right = delete(root->right, value);
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            struct Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}
int main()
{
    struct Node* root = NULL;
    while(1)
    {
        int choice;
        int data;
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert\n");
        printf("2. Inorder\n");
        printf("3. Preorder\n");
        printf("4. Postorder\n");
        printf("5. Deletion\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter the value you want to delete: ");
                scanf("%d", &data);
                root = delete(root, data);
                break;
            case 6:
                printf("Exiting program.\n");
                return(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}