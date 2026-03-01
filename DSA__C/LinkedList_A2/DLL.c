#include "mydoublylinkedlist.h"

void CreateList(dll *list)
{
    list->head = NULL;
    list->tail = NULL;
}

int isEmpty(dll *list)
{
    return list == NULL || list->head == NULL;
}

void insertfirst(dll *list, int data)
{
    node *n = malloc(sizeof(node));
    if (!n)
        return;
    n->item = data;
    n->prev = NULL;
    n->next = list->head;
    if (list->head)

        list->head->prev = n;
    else
        list->tail = n;
    list->head = n;
}

void insertlast(dll *list, int data)
{
    node *n = malloc(sizeof(node));
    if (!n)
        return;
    n->item = data;
    n->next = NULL;
    n->prev = list->tail;
    if (list->tail)
        list->tail->next = n;
    else
        list->head = n;
    list->tail = n;
}

void insertat(dll *list, int data, int position)
{
    if (position < 1)
        return;
    if (position == 1)
    {
        insertfirst(list, data);
        return;
    }

    node *temp = list->head;

    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
        return;

    node *n = malloc(sizeof(node));
    if (!n)
        return;
    n->item = data;
    n->next = temp->next;
    n->prev = temp;
    if (temp->next)
    {
        temp->next->prev = n;
    }
    else
    {
        list->tail = n;
    }
    temp->next = n;
    return;
}

node *Search(dll *list, int data)
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

void insertafter(dll *list, node *temp, int data)
{
    if (temp != NULL)
    {
        node *n = malloc(sizeof(node));
        if (!n)
            return;
        n->item = data;
        n->prev = temp;
        n->next = temp->next;
        if (temp->next)
            temp->next->prev = n;
        else
            list->tail = n;
        temp->next = n;
    }
    else
    {
        return;
    }
}

int deletefirst(dll *list)
{
    if (isEmpty(list))
    {
        return -1;
    }
    node *temp = list->head;
    int data = temp->item;

    list->head = temp->next;

    if (list->head)
        list->head->prev = NULL;
    else
        list->tail = NULL;

    free(temp);
    return data;
}

int deletelast(dll *list)
{
    if (isEmpty(list))
    {
        return -1;
    }
    node *temp = list->tail;
    int data = temp->item;
    list->tail = temp->prev;
    if (list->tail)
        list->tail->next = NULL;
    else
        list->head = NULL;
    temp->prev = NULL;
    free(temp);
    return data;
}

int deleteitem(dll *list, int x)
{
    if (isEmpty(list))
    {
        return -1;
    }

    node *temp = list->head;
    while (temp != NULL && temp->item != x)
    {
        temp = temp->next;
    }
    if (temp == NULL)
        return 0;
    int data = temp->item;
    if (temp->prev)
        temp->prev->next = temp->next;
    else
        list->head = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;
    else
        list->tail = temp->prev;
    temp->next = NULL;
    temp->prev = NULL;
    free(temp);

    return data;
}

void display(dll *list)
{
    if (isEmpty(list))
    {
        return;
    }
    node *temp = list->head;
    while (temp != NULL)
    {
        printf("%d ", temp->item);
        temp = temp->next;
    }
}

int size(dll *list)
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

void reverse(dll *list)
{
    if (isEmpty(list))
    {
        return;
    }

    node *curr = list->head;
    node *temp = NULL;
    while (curr)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    temp = list->head;
    list->head = list->tail;
    list->tail = temp;
}

int main()
{

    dll list1;
    CreateList(&list1);
    printf("Is DLL Empty ? == %d\n", isEmpty(&list1));
    CreateList(&list1);
    insertfirst(&list1, 5);
    insertfirst(&list1, 4);
    insertfirst(&list1, 3);
    insertfirst(&list1, 2);
    insertfirst(&list1, 1);
    insertlast(&list1, 6);
    deleteitem(&list1, 4);
    display(&list1);
    return 0;
}