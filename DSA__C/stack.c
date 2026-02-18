#include <stdio.h>

#define MAX 100
int stack[MAX];
int top;
void init()
{
    top = -1;
}
int isEmpty()
{
    return (top == -1);
}
int isFull()
{
    return (top == MAX - 1);
}
void push(int item)
{
    if (top == MAX - 1)
    {
        printf("Stack OverFlow");
        return;
    }
    top++;
    stack[top] = item;
}

int pop()
{
    int data;
    if (top == -1)
    {
        printf("Stack UnderFlow");
        return -1;
    }
    data = stack[top];
    top--;
    return data;
}

int peek()
{
    if (top == -1)
    {
        printf("Stack UnderFlow");
        return -1;
    }
    return stack[top];
}
void show()
{
    if (top == -1)
    {
        printf("Stack is Empty");
        return;
    }
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    return;
}
int main()
{

    init();
    push(2);
    push(6);
    push(7);
    push(108);
    pop();
    show();
    printf("\n%d", peek());

    return 0;
}