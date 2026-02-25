#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Qnode
{
    int item;
    struct Qnode *link;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
} q;

void createqueue(q *q1);
int isEmpty(q *q1);
void enqueue(q *q1, int x);
int dequeue(q *q1);
int peek(q *q1);
void display(q *q1);
int size(q *q1);

#endif