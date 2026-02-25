#include "myqueue.h"

void createqueue(q *q1)
{
    q1->front = NULL;
    q1->rear = NULL;
}

int isEmpty(q *q1)
{
    return (q1->front == NULL);
}

void enqueue(q *q1, int x)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->item = x;
    n->link = NULL;
    if (isEmpty(q1))
    {
        q1->front = n;
        q1->rear = n;
    }
    else
    {
        q1->rear->link = n;
        q1->rear = n;
    }

    return;
}

int dequeue(q *q1)
{
    if (isEmpty(q1))
    {
        printf("Queue Is Empty\n");
        return 0;
    }
    Node *temp = q1->front;

    int data;
    data = temp->item;
    temp = temp->link;
    if (temp == NULL)
    {
        q1->rear = NULL;
    }
    return data;
}

int peek(q *q1)
{
    if (isEmpty(q1))
    {
        printf("Queue Is Empty\n");
        return 0;
    }

    int data;
    data = q1->rear->item;
    return data;
}

void display(q *q1)
{
    if (isEmpty(q1))
    {
        printf("Queue Is Empty\n");
        return;
    }
    Node *temp = q1->front;
    while (temp != NULL)
    {
        printf("%d ", temp->item);
        temp = temp->link;
    }
}

int size(q *q1)
{
    if (isEmpty(q1))
    {
        printf("Queue Is Empty\n");
        return 0;
    }
    Node *temp = q1->front;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }
    return count;
}

int main()
{
    q q1;
    createqueue(&q1);
    printf("\nIs queue Empty : %d\n", isEmpty(&q1));
    enqueue(&q1, 3);
    enqueue(&q1, 6);
    printf("\nIs queue Empty : %d\n", isEmpty(&q1));
    enqueue(&q1, 13);
    enqueue(&q1, 26);
    dequeue(&q1);
    display(&q1);
    printf("\nSize = %d", size(&q1));

    return 0;
}