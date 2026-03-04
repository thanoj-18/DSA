#ifndef mystack_H
#define mystack_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int item;
    struct Node *link;
} node;

typedef struct Stack
{
    node *top;
} stack;

void CreateStack(stack *s1);
int isEmpty(stack *s1);
void push(stack *s1, int x);
int pop(stack *s1);
int peek(stack *s1);
void display(stack *s1);
int size(stack *s1);

#endif