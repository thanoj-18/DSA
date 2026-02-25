#include <stdio.h>
#define MAX 5

int CQueue[MAX];
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
    return (front == (rear + 1) % MAX);
}
void enqueue(int x)
{
    if (front == (rear + 1) % MAX)
    {
        printf("Queue Full\n");
        return;
    }

    rear = (rear + 1) % MAX;
    CQueue[rear] = x;
    if (front == -1)
    {
        front = 0;
    }

    return;
}

int dequeue()
{
    int data;
    if (isEmpty())
    {
        printf("Queue is Empty");
        return -1;
    }
    data = CQueue[front];

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
    return data;
}
void display()
{
    if (isEmpty())
    {
        printf("Queue is Empty");
        return;
    }
    int i = front;
    while (1)
    {
        printf("%d ", CQueue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
}
int size()
{
    if (isEmpty())
    {
        printf("Queue is Empty");
        return -1;
    }
    int count = 1;
    int i = front;
    while (i != rear)
    {
        i = (i + 1) % MAX;
        count++;
    }
    return count;
}
int main()
{

    init();
    enqueue(10);
    enqueue(15);
    enqueue(18);
    enqueue(20);
    enqueue(25);
    display();
    printf("\nSize : %d\n", size());
    enqueue(10);
    dequeue();
    dequeue();
    display();

    return 0;
}
