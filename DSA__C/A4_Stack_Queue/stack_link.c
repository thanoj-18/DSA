#include "mystack.h"

void CreateStack(stack *s1)
{
    s1->top = NULL;
}

int isEmpty(stack *s1)
{
    return (s1->top == NULL);
}

void push(stack *s1, int x)
{
    node *n = (node *)malloc(sizeof(node));
    if (n == NULL)
        return;

    n->item = x;
    n->link = s1->top;
    s1->top = n;

    return;
}

int pop(stack *s1)
{
    if (s1->top == NULL)
    {
        printf("\nStack is Empty\n");
        return 0;
    }

    int data = s1->top->item;
    s1->top = s1->top->link;
    return data;
}

int peek(stack *s1)
{
    if (s1->top == NULL)
    {
        printf("\nStack is Empty\n");
        return 0;
    }

    int data = s1->top->item;
    return data;
}

void display(stack *s1)
{
    if (s1->top == NULL)
    {
        printf("\nStack is Empty\n");
        return;
    }
    printf("\nStack Elements :\n");

    node *temp = s1->top;
    while (temp != NULL)
    {
        printf("%d ", temp->item);
        temp = temp->link;
    }
}

int size(stack *s1)
{
    if (s1->top == NULL)
    {
        printf("\nStack is Empty\n");
        return 0;
    }
    int count = 0;
    node *temp = (node *)malloc(sizeof(node));
    temp = s1->top;
    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }

    return count;
}

int main()
{
    stack s1;
    CreateStack(&s1);
    push(&s1, 5);
    push(&s1, 10);
    push(&s1, 15);
    push(&s1, 20);
    pop(&s1);
    printf("Is Stack Empty : %d\n", isEmpty(&s1));
    display(&s1);
    printf("\nSize = %d\n", size(&s1));
    return 0;
}