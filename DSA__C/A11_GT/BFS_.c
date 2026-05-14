#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];

int main()
{
    int n, u, v, start, e;

    printf("Enter No.of Vertices :");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    printf("Enter no.of edges :");
    scanf("%d", &e);
    printf("Enter the edges (u v) :");

    for (int i = 0; i < e; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    printf("Enter the Stating Node : ");
    scanf("%d", &start);

    int Queue[MAX], front = 0, rear = 0;

    Queue[rear++] = start;
    visited[start] = 1;

    while (front < rear)
    {
        int val = Queue[front++];
        printf("%d ", val);
        for (int i = 0; i < n; i++)
        {
            if (graph[val][i] == 1 && visited[i] == 0)
            {
                Queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    return 0;
}