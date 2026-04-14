#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int queue[MAX];
int front = -1, rear = -1;
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
void enqueue(int value)
{
    if(rear == MAX - 1)
        return;

    else if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = value;
    }
    else
    {
        rear++;
        queue[rear] = value;
    }
}
int dequeue()
{
    if(front == -1 && rear == -1)
        return -1;
    int value = queue[front];
    if(front == rear)
        front = rear = -1;
    else
        front++;
    return value;
}
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
void BFS(struct Graph* graph, int startVertex)
{
    enqueue(startVertex); // put the starting vertex into queue
    graph->visited[startVertex] = 1; // mark it as known
    while(front != -1)
    {
        int currentVertex = dequeue(); // dequeue first element in the queue
        printf("%d ", currentVertex); // print the element
        struct Node* temp = graph->adjList[currentVertex]; // Traverse all neighbours of the current vertex of the element
        while(temp)
        {
            int adjVertex = temp->vertex; // vertex of current vertex's neighbour
            if(graph->visited[adjVertex] == 0) // If neighbour is not visited, enqueue it and mark as visited
            {
                enqueue(adjVertex);
                graph->visited[adjVertex] = 1;
            }
            temp = temp->next; // go to next neighbour in linked list
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
    printf("----BFS------");
    while(1) 
    {
        printf("Choose:\n");
        printf("1. Add Edge\n");
        printf("2. BFS\n");
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
                    front = rear = -1;
                    printf("BFS Traversal:\n");
                    BFS(&graph, start);
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