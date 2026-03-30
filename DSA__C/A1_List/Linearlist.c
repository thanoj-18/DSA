#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int list[MAX];
int size = 0;

int isEmpty()
{
    return size == 0;
}

int isFull()
{
    return size == MAX;
}

void display()
{
    if (isEmpty())
    {
        return;
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d ", list[i]);
    }
}

void insertfirst(int data)
{
    if (isFull())
    {
        return;
    }
    for (int i = size; i > 0; i--)
    {
        list[i] = list[i - 1];
    }
    list[0] = data;
    size++;
    return;
}
void insertlast(int data)
{
    if (isFull())
    {
        return;
    }
    list[size++] = data;
}

void insertat(int data, int position)
{
    if (isFull() || position > MAX || position < 0)
    {
        return;
    }
    for (int i = size; i > position; i--)
    {
        list[i] = list[i - 1];
    }
    list[position] = data;
    size++;
    return;
}

int deletefirst()
{
    if (isEmpty())
    {
        return;
    }
    int data = list[0];
    for (int i = 0; i < size; i++)
    {
        list[i] = list[i + 1];
    }
    size--;
}

int deletelast()
{
    if (isEmpty())
    {
        return;
    }
    int data = list[size--];
    return data;
}

int deleteat(int position)
{
    if (isEmpty() || position >= size || position < 0)
    {
        return;
    }
    int data = list[size];
    for (int i = position; i < size - 1; i++)
    {
        list[i] = list[i + 1];
    }
    size--;
}

int search(int key)
{
    for (int i = 0; i < size; i++)
    {
        if (list[i] == key)
        {
            return i;
        }
    }
}

int main()
{

    insertfirst(10);
    insertfirst(30);
    insertlast(40);
    insertlast(50);
    insertfirst(90);
    display();


    return 0;
}