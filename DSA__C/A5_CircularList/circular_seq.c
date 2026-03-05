#include <stdio.h>
#include <stdlib.h>

#define MAX 6

int list[MAX];
int front, size;
void init()
{
    front = 0;
    size = 0;
}

int isEmpty()
{
    return (size == 0);
}

int isFull()
{
    return (size == MAX);
}

void insertfirst(int data)
{
    if (isFull())
    {
        printf("List is Full");
        return;
    }
    front = (front - 1 + MAX) % MAX;
    list[front] = data;
    size++;
    return;
}

void insertlast(int data)
{
    if (isFull())
    {
        printf("List is Full");
        return;
    }
    int rear = (front + size) % MAX;
    list[rear] = data;
    size++;
    return;
}

void insertat(int data, int position)
{
    if (isFull())
    {
        printf("List is Full");
        return;
    }
    if (position < 0 || position > size)
    {
        printf("Invalid Position\n");
        return;
    }
    for (int i = size; i > position; i--)
    {
        int curr = (front + i) % MAX;
        int prev = (front + i - 1) % MAX;
        list[curr] = list[prev];
    }
    list[(front + position) % MAX] = data;
    size++;
}

int deletefirst()
{
    if (isEmpty())
    {
        printf("List is Empty");
        return -1;
    }

    int data = list[front];
    front = (front + 1) % MAX;
    size--;
    return data;
}

int deletelast()
{
    if (isEmpty())
    {
        printf("List is Empty");
        return -1;
    }

    int rear = (front + size - 1) % MAX;
    int data = list[rear];

    size--;
    return data;
}

int deleteat(int position)
{
    if (isEmpty())
    {
        printf("List is Empty");
        return -1;
    }
    if (position < 0 || position >= size)
    {
        printf("Invalid Position\n");
        return -1;
    }
    int data = list[(front + position) % MAX];
    for (int i = position; i < size - 1; i++)
    {
        int curr = (front + i) % MAX;
        int next = (front + i + 1) % MAX;
        list[curr] = list[next];
    }
    size--;
    return data;
}

void display()
{
    if (isEmpty())
    {
        printf("List is Empty");
        return;
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d ", list[(front + i) % MAX]);
    }
    return;
}

int listsize()
{
    return size;
}

int main()
{
    init();
    printf("Is list Empty ?? : %d\n", isEmpty());
    insertfirst(20);
    insertfirst(30);
    insertfirst(40);
    insertfirst(50);
    insertlast(0);
    insertat(10, 0);
    printf("Is list Empty ?? : %d\n", isEmpty());
    display();

    return 0;
}
