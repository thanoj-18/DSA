#include <stdio.h>

#define MAX 100

int Queue[MAX];
int front, rear;

void init()
{
    front = -1;
    rear = -1;
}

int isEmpty()
{
    return (front == -1);
}

int isFull()
{
    return (rear == MAX - 1);
}

void enqueue(int item)
{
    if (rear == MAX - 1)
    {
        printf("QueueOverFlow");
        return;
    }
    rear++;
    Queue[rear] = item;
    if (front == -1)
        front = 0;

    return;
}

int dequeue()
{
    int data;
    if (front == -1)
    {
        printf("QueueUnderFlow");
        return -1;
    }
    data = Queue[front];
    if (front == rear) // Queue will become empty
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }

    return data;
}

void show()
{
    if (isEmpty())
    {
        printf("Queue is Empty ");
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", Queue[i]);
    }
}

int main()
{

    init();

    enqueue(2);
    enqueue(5);
    enqueue(9);
    enqueue(23);
    enqueue(34);
    
    dequeue();

    show();

    return 0;
}