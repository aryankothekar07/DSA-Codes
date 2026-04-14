#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int stack[MAX];
int top = -1;
// Self-referential node used in adjacency list to store a vertex and pointer to next node 
struct Node
{
    int vertex;
    struct Node* next;
};
// Structure of the graph
struct Graph
{
    struct Node* adjList[MAX]; // Array of Linked lists
    int visited[MAX]; // Nodes that have been visited in BFS
};
struct Node* createNode(int v) // Creating a node for linked list
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
void addEdge(struct Graph* graph, int src, int dest)
{
    struct Node* graphNode = createNode(dest); // creating a node
    graphNode->next = graph->adjList[src]; // make new node point to current first node.
    graph->adjList[src] = graphNode; // update head to point to new node (src -> dest)
}
void push(int value)
{
    if(top == MAX - 1)
        return;
    else
        stack[++top] = value;
}
int pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
void DFS(struct Graph* graph, int startVertex)
{
    push(startVertex);
    graph->visited[startVertex] = 1;
    while(top != -1)
    {
        int current = pop(); //pops top element of stack
        printf("%d ", current); 
        struct Node* temp = graph->adjList[current]; // access the neighbours of popped element
        while(temp != NULL)
        {
            if(graph->visited[temp->vertex] == 0)
            {
                push(temp->vertex); // pushes the neighbour into stack
                graph->visited[temp->vertex] = 1; // marks them as visited
            }
            temp = temp->next; // goes to next neighbour
        }
    }
}
int main()
{
    struct Graph graph;
    for(int i = 0; i < MAX; i++) 
    {
        graph.adjList[i] = NULL;
        graph.visited[i] = 0;
    }
    int choice;
    int src, dest;
    int start;
    int empty = 1;
    printf("----DFS------");
    while(1) 
    {
        printf("Choose:\n");
        printf("1. Add Edge\n");
        printf("2. DFS\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter source vertex: ");
                scanf("%d", &src);
                printf("Enter destination vertex: ");
                scanf("%d", &dest);
                if (src == dest) 
                {
                    printf("Self-loops are not allowed in this model.\n");
                } 
                else 
                {
                    addEdge(&graph, src, dest);
                    addEdge(&graph, dest, src);
                    printf("Edge added between %d and %d\n\n", src, dest);
                }
                break;
            case 2:
                for(int i = 0; i < MAX; i++)
                {
                    if (graph.adjList[i] != NULL)
                    {
                        empty = 0;
                        break;
                    }
                }
                if(empty)
                {
                    printf("Graph is empty.\n");
                }
                else
                {
                    printf("Enter starting vertex: ");
                    scanf("%d", &start);
                    for(int i = 0; i < MAX; i++)
                        graph.visited[i] = 0;
                    top = -1;
                    printf("DFS Traversal:\n");
                    DFS(&graph, start);
                    printf("\n\n");
                }
                empty = 1;
                break;
            case 3:
                return 0;
        }
    }
    return 0;
}