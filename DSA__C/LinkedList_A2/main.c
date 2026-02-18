#include <stdio.h>
#include <stdlib.h>
#include "mylinkedlist.h"

void CreateList(struct SLL *list)
{
    list->start = NULL;
}

int isEmpty(struct SLL *list)
{
    return list->start == NULL;
}

void insert_at_start(struct SLL *list, int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->item = data;
    n->next = list->start;
    list->start = n;
}

void insert_at_end(struct SLL *list, int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->item = data;
    n->next = NULL;

    if (isEmpty(list))
    {
        list->start = n;
    }
    else
    {
        struct Node *temp = list->start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}

struct Node *Search(struct SLL *list, int data)
{
    struct Node *temp = list->start;
    while (temp->next != NULL)
    {
        if (temp->item == data)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void insert_after(struct Node *temp, int data)
{
    if (temp != NULL)
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->item = data;
        n->next = temp->next;
        temp->next = n;
    }
}

void delete_first(struct SLL *list)
{
    if (!isEmpty(list))
    {
        struct Node *temp = list->start;
        list->start = temp->next;
        free(temp);
    }
}

void delete_last(struct SLL *list)
{
    if (isEmpty(list))
    {
        return;
    }

    if (list->start->next == NULL)
    {
        free(list->start);
        list->start = NULL;
    }
    else
    {
        struct Node *temp = list->start;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void delete_item(struct SLL *list, int data)
{
    if (isEmpty(list))
    {
        return;
    }

    struct Node *temp = list->start;

    if (temp->item == data)
    {
        list->start = temp->next;
        free(temp);
        return;
    }

    while (temp->next != NULL)
    {
        if (temp->next->item == data)
        {
            struct Node *del = temp->next;
            temp->next = del->next;
            free(del);
            return;
        }
        temp = temp->next;
    }
}

void show(struct SLL *list)
{
    struct Node *temp = list->start;
    while (temp != NULL)
    {
        printf("%d ", temp->item);
        temp = temp->next;
    }
}

int size(struct SLL *list)
{
    int count = 0;
    struct Node *temp = list->start;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

int indexOf(struct SLL *list, int data)
{
    int index = 0;
    struct Node *temp = list->start;

    while (temp != NULL)
    {
        if (temp->item == data)
            return index;

        temp = temp->next;
        index++;
    }

    return -1;
}

int main()
{
    struct SLL list1;

    CreateList(&list1);

    insert_at_start(&list1, 12);
    insert_at_start(&list1, 10);
    insert_at_start(&list1, 8);
    insert_at_start(&list1, 6);

    insert_at_end(&list1, 8);
    insert_at_end(&list1, 6);
    insert_at_end(&list1, 12);
    insert_at_end(&list1, 10);

    struct Node *pos = Search(&list1, 8);
    insert_after(pos, 9);

    show(&list1);

    return 0;
}