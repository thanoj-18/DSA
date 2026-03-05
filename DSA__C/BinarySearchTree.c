#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define EMPTY -999

int Bstree[MAX];

void init()
{
    for (int i = 0; i < MAX; i++)
    {
        Bstree[i] = EMPTY;
    }
}

void isEmpty()
{
    int r = 1;
    for (int i = 0; i < MAX; i++)
    {
        if (Bstree[i] != EMPTY)
            r = 0;
    }

    return r;
}

int isFull(){
    return 
}