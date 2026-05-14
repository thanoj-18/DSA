#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
} queue;

int isEmpty(queue *q)
{
    return q->f == q->r;
}

int isFull(queue *q)
{
    return q->r == q->size - 1;
}

void enqueue(queue *q, int x)
{
    if (isFull(q))
        printf("Queue is Full ");
    else
    {
        q->r++;
        q->arr[q->r] = x;
    }
}

int dequeue(queue *q)
{
    int data;
    if (isEmpty(q))
        printf("Queue is Empty ");
    else
    {
        q->f++;
        data = q->arr[q->f];
    }
    return data;
}

int main()
{
    queue q;
    q.size = 10;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // BFS
    int node;
    int i = 2;

    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};

    printf("%d ",i);
    visited[i]=1;
    enqueue(&q,i);  // enqueue i for exploration

    while(!isEmpty(&q)){
        node = dequeue(&q);
        for(int j =0;j<7;j++){
            if(a[node][j]==1 &&visited[j]== 0){
                printf("%d ",j);
                visited[j]=1;
                enqueue(&q,j);
            }
        }
    }
}
