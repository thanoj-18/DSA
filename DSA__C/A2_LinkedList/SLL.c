#include "mysinglylinkedlist.h"

void CreateList(sll *list)
{
    list->head = NULL;
}

int isEmpty(sll *list)
{
    return list->head == NULL;
}

void insertfirst(sll *list, int x)
{
    node *n = (node *)malloc(sizeof(node));
    n->item = x;
    n->next = list->head;
    list->head = n;
}

void insertlast(sll *list, int x)
{
    node *n = (node *)malloc(sizeof(node));
    if (!n)
        return;
    n->item = x;
    n->next = NULL;
    if (isEmpty(list))
    {
        list->head = n;
    }
    else
    {
        node *temp = list->head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}

int insertat(sll *list, int data, int position)
{
    if (position < 1)
        return 0;
    if (position == 1)
    {
        insertfirst(list, data);
        return 1;
    }
    node *temp = list->head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
        return 0;

    node *n = malloc(sizeof(node));
    if (!n)
        return 0;
    n->item = data;
    n->next = temp->next;
    temp->next = n;
    return 1;
}

node *Search(sll *list, int data)
{
    node *temp = list->head;
    while (temp != NULL)
    {
        if (temp->item == data)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void insertafter(node *temp, int data)
{
    if (temp != NULL)
    {
        node *n = malloc(sizeof(node));
        if (!n)
            return;
        n->item = data;
        n->next = temp->next;
        temp->next = n;
    }
}

int deletefirst(sll *list)
{
    int data;
    if (isEmpty(list))
    {
        printf("List is Empty !");
        return -1;
    }
    node *temp = list->head;
    data = temp->item;
    list->head = temp->next;
    free(temp);
    return data;
}

int deletelast(sll *list)
{
    int data;
    if (isEmpty(list))
    {
        printf("List is Empty !");
        return -1;
    }
    if (list->head->next == NULL)
    {
        return deletefirst(list);
    }
    node *temp = list->head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    node *last = temp->next;
    data = last->item;
    temp->next = NULL;
    free(last);
    return data;
}

int deleteitem(sll *list, int x)
{
    int data;
    if (isEmpty(list))
    {
        printf("List is Empty !");
        return -1;
    }

    node *temp = list->head;
    node *prev = NULL;

    while (temp != NULL && temp->item != x)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return 0;
    data = temp->item;
    if (prev == NULL)
    {
        list->head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }
    free(temp);
    return data;
}

void display(sll *list)
{
    if (isEmpty(list))
    {
        printf("List is Empty !");
        return;
    }
    node *temp = list->head;
    while (temp != NULL)
    {
        printf("%d ", temp->item);
        temp = temp->next;
    }
}

int size(sll *list)
{
    node *temp = list->head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void reverse(sll *list)
{
    if (isEmpty(list))
    {
        printf("List is Empty !");
        return;
    }
    node *prev = NULL;
    node *curr = list->head;
    node *nxt = NULL;

    while (curr != NULL)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    list->head = prev;
}

/////////// print in reverse ///////////////////////

void reversePrint(node *temp)
{
    if (temp == NULL)
        return;

    reversePrint(temp->next);
    printf("%d ",temp->item);
}

int main()
{
    sll list1;
    CreateList(&list1);
    insertfirst(&list1, 5);
    insertfirst(&list1, 4);
    insertfirst(&list1, 3);
    insertfirst(&list1, 2);
    insertfirst(&list1, 1);
    insertlast(&list1, 6);
    deleteitem(&list1, 4);
    display(&list1);

    printf("\nReverse Print :\n");
    reversePrint(list1.head);

    return 0;
}
