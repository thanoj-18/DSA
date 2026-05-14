#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n;
void BFS(int start)
{

    int Queue[MAX], front = 0, rear = 0;

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    Queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal :\n");

    while (front < rear)
    {
        int node = Queue[front++];
        printf("%d ", node);

        for (int i = 0; i < n; i++)
        {
            if (graph[node][i] == 1 && visited[i] == 0)
            {
                Queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

void DFS(int start)
{
    int Stack[MAX], top = -1;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    Stack[++top] = start;
    printf("DFS Traversal (Stack) :");

    while (top != -1)
    {
        int node = Stack[top--];

        if (!visited[node])
        {
            printf("%d ", node);
            visited[node] = 1;
        }

        for (int i = n - 1; i > 0; i--)
        {
            if (graph[node][i] == 1 && !visited[i])
            {

                Stack[++top] = i;
            }
        }
    }
}

int main()
{
    int v, edges, u, start;

    printf("Enter No.of Vertices :");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter No.of Edges:\n");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("Enter the Starting Node :");
    scanf("%d", &start);

    BFS(start);

    printf("\nDFS Traversal");

    DFS(start);
    
    return 0;
}