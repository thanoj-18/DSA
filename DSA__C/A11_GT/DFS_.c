#include <stdio.h>
#define MAX 100

int visited[MAX];
int graph[MAX][MAX];

void DFS_Recursive(int node, int n)
{
    visited[node] = 1;

    printf("%d ", node);

    for (int i = 0; i < n; i++)
    {
        if (graph[node][i] == 1 && visited[node] == 0)
        {
            DFS_Recursive(i,n);
        }
    }
}
void DFS(int start, int n)
{
    int stack[MAX], top = -1;
    stack[++top] = start;
    visited[start] = 1;

    while (top != -1)
    {
        int node = stack[top--];

        // if (!visited[node])
        // {
        //     printf("%d ", node);
        //     visited[node] = 1;
        // }

        printf("%d ", node);

        for (int i = n - 1; i >= 0; i--)
        {
            if (graph[node][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                stack[++top] = i;
            }
        }
    }
}

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

    DFS(start, n);

    return 0;
}