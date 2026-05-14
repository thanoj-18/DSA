#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node
{
    int item;
    struct Node *next;
} node;

node *adj_list[MAX];
int visited[MAX];

node *createNode(int data)
{
    node *n = (node *)malloc(sizeof(node));

    n->item = data;
    n->next = NULL;

    return n;
}

void addedge(int u, int v)
{
    node *n = createNode(v);
    n->next = adj_list[u];
    adj_list[u] = n;

    node *n = createNode(u);
    n->next = adj_list[v];
    adj_list[v] = n;
}

// DFS Recursive

void DFS(int snode)
{

    visited[snode] = 1;

    printf("%d ", snode);

    node *temp = adj_list[snode];

    while (temp != NULL)
    {
        int neighbor = temp->item;

        if (visited[neighbor] == 0)
        {
            DFS(neighbor);
        }

        temp = temp->next;
    }
}

void BFS(int start)
{
    int Queue[MAX], front = 0, rear = 0;

    Queue[rear++] = start;
    visited[start] = 1;

    while (front < rear)
    {
        int val = Queue[front++];

        printf("%d ", val);
        node *temp = adj_list[val];

        while (temp != NULL)
        {
            int neighbor = temp->item;

            if (visited[neighbor] == 0)
            {
                visited[neighbor] = 1;
                Queue[rear++] = neighbor;
            }
            temp = temp->next;
        }
    }
}

int main()
{
    int n, e, u, v, start;

    printf("Enter Number of Vertices : ");
    scanf("%d", &n);

    // Initialize
    for (int i = 0; i < n; i++)
    {
        adj_list[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter Number of Edges : ");
    scanf("%d", &e);

    printf("Enter Edges (u v):\n");

    for (int i = 0; i < e; i++)
    {
        scanf("%d %d", &u, &v);

        addEdge(u, v);
    }

    printf("Enter Starting Node : ");
    scanf("%d", &start);

    printf("\nDFS Traversal : ");
    DFS(start);

    // Reset visited
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    printf("\nBFS Traversal : ");
    BFS(start);

    return 0;
}
