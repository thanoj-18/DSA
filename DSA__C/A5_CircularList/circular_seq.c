#include <stdio.h>
#include <stdlib.h>

#define MAX 6

int list[MAX];
int size = 0;
int front, rear;
void init()
{
    front = -1;
    rear = -1;
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
    for (int i = front; i > 0; i++)
    {
        list[(i + 1) % MAX] = list[(i - 1) % MAX];
    }
    list[0] = data;
    size++;
    return;
}