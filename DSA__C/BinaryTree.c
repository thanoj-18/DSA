#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define EMPTY -999

int Btree[MAX];

void init()
{
    for (int i = 0; i < MAX; i++)
    {
        Btree[i] = EMPTY;
    }
}
int isEmpty()
{
    int r = 1;
    for (int i = 0; i < MAX; i++)
    {
        if (Btree[i] != EMPTY)
            r = 0;
    }

    return r;
}

void insertroot(int data)
{
    if (Btree[0] != EMPTY)
    {
        printf("Root Already Exists !\n");
        return;
    }
    else
    {
        Btree[0] = data;
    }
}

void insertlchild(int parentindex, int data)
{
    if (parentindex >= MAX)
    {
        printf("Invalid Index !\n");
        return;
    }
    int left = 2 * parentindex + 1;

    if (left >= MAX)
    {
        printf("Index is out of Range !\n");
        return;
    }
    if (Btree[parentindex] == EMPTY)
    {
        printf("Parent doesn't Exist\n");
    }
    else if (Btree[left] != EMPTY)
    {
        printf("Leftchild Already exists\n");
    }
    else
    {
        Btree[left] = data;
    }
}

void insertrchild(int parentindex, int data)
{

    if (parentindex >= MAX)
    {
        printf("Invalid Index !\n");
        return;
    }
    int right = 2 * parentindex + 2;
    if (right >= MAX)
    {
        printf("Index is out of Range !\n");
        return;
    }
    if (Btree[parentindex] == EMPTY)
    {
        printf("Parent doesn't Exist\n");
    }
    else if (Btree[right] != EMPTY)
    {
        printf("Rightchild Already exists\n");
    }
    else
    {
        Btree[right] = data;
    }
}

void display()
{
    for (int i = 0; i < MAX; i++)
    {
        if (Btree[i] == EMPTY)
            printf("_ ");
        else
            printf("%d ", Btree[i]);
    }
}

int main()
{

    init();
    // insertroot(30);
    // insertlchild(0, 34);
    // insertrchild(1, 36);
    // insertlchild(1, 35);
    // insertrchild(0, 32);
    // display();
    printf("%d", isEmpty());

    return 0;
}