#include <stdio.h>
#define MAX 5
// in this method one block always remains empty
int CQueue[MAX];
int front, rear;
void init()
{
    front = 0;
    rear = 0;
}
int isEmpty()
{
    return (front == rear);
}
int isFull()
{
    return (front == (rear + 1) % MAX);
}
void enqueue(int x)
{
    if (isFull())
    {
        printf("Queue Full\n");
        return;
    }

    rear = (rear + 1) % MAX; // move the front pointer to the deleted element block after deleting it
    CQueue[rear] = x;

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
    front = (front + 1) % MAX;
    data = CQueue[front];

    return data;
}
void display()
{
    if (isEmpty())
    {
        printf("Queue is Empty");
        return;
    }
    int i = (front+1)%MAX;
    while (1)
    {
        printf("%d ", CQueue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
}
int size()  // N-1 if full
{
    if (isEmpty())
    {
        printf("Queue is Empty");
        return 0;
    }
    int count = 1;
    int i = (front+1)%MAX;
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
    
    display();
    printf("\nSize : %d\n", size());
    enqueue(10);
    dequeue();
    dequeue();
    display();

    return 0;
}
