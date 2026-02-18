#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;
void push(char x)
{

    top++;
    stack[top] = x;
}
char pop()
{

    if (top == -1)
        return -1;
    return stack[top--];
}

int precedence(char operator)
{
    if (operator == '^')
        return 3;
    else if (operator == '/' || operator == '*' || operator == '%')
        return 2;
    else if (operator == '+' || operator == '-')
        return 1;
    else
        return 0;
}
int main()
{
    char ifexp[MAX];
    printf("Enter the Expression :");
    scanf("%s", &ifexp);
    printf("Infix Expression : %s\n", ifexp);

    // char ifexp[MAX] = "2+6"; // 26+
    char pfexp[MAX];
    int n = strlen(ifexp), j = 0;

    for (int i = 0; ifexp[i] != '\0'; i++)
    {
        char ch = ifexp[i];
        if (isalnum(ch))
        {
            pfexp[j] = ch;
            j++;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            char p = pop();
            while (p == '(')
            {
                pfexp[j] = p;
                j++;
            }
        }
        else
        {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
            {
                pfexp[j] = pop();
                j++;
            }
            push(ch);
        }
    }

    while (top != -1)
    {
        pfexp[j] = pop();
        j++;
    }

    pfexp[j] = '\0';
    printf("Postfix Expression: %s", pfexp);

    return 0;
}