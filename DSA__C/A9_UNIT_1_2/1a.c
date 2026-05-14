#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int item;
    struct Node *next;
} node;

node *create(int arr[], int n)
{
    node *head = NULL, *temp = NULL;

    for (int i = 0; i < n; i++)
    {
        node *n = (node *)malloc(sizeof(node));

        n->item = arr[i];
        n->next = NULL;

        if (head == NULL)
        {
            head = temp = n;
        }
        else
        {
            temp->next = n;
            temp = n;
        }
    }

    return head;
}

node *removeDuplicated(node *head)
{
    node newHead;
    newHead.next = head;

    node *curr = head;

    node *prev = &newHead;

    while (curr)
    {
        int duplicate = 0;
        while (curr->next && curr->item == curr->next->item)
        {
            duplicate = 1;
            node *temp = curr;
            curr = curr->next;
            free(temp);
        }

        // removing leftover node
        if (duplicate)
        {
            node *temp = curr;
            curr = curr->next;
            free(temp);
            prev->next = curr;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return newHead.next;
}

void display(node *head)
{
    node *temp = head;
    while (temp)
    {
        printf("%d ", temp->item);
        temp = temp->next;
    }
}

int main()
{
    int n;
    printf("Enter No.of Elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the Elements:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    node *head = create(arr, n);

    printf("Input :\n");

    display(head);

    head = removeDuplicated(head);

    printf("\nOutput :\n");

    display(head);

    free(arr);
    return 0;
}