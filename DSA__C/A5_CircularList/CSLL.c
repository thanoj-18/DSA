#include "mycircularSinglylinkedlist.h"

void CreateList(sll *list)
{
    list->head = NULL;
    list->tail = NULL;
}

int isEmpty(sll *list)
{
    return list->head == NULL;
}

void insertfirst(sll *list, int x)
{
    node *n = (node *)malloc(sizeof(node));
    if (!n)
        return;
    n->item = x;

    if (list->head)
    {
        n->next = list->head;
        list->tail->next = n;

        list->head = n;
    }
    else
    {
        list->head = n;
        list->tail = n;
        n->next = n;
    }
}

void insertlast(sll *list, int x)
{
    node *n = malloc(sizeof(node));
    if (!n)
        return;

    if (isEmpty(list))
    {
        insertfirst(list, x);
    }
    else
    {
        n->item = x;
        n->next = list->head;
        list->tail->next = n;
        list->tail = n;
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
    for (int i = 1; i < position - 1 && temp != list->head; i++)
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
    if (isEmpty(list))
        return NULL;

    node *temp = list->head;

    do
    {
        if (temp->item == data)
        {
            return temp;
        }
        temp = temp->next;
    } while (temp != list->head);
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

    if (isEmpty(list))
    {
        printf("List is Empty !");
        return -1;
    }
    node *temp = list->head;
    int data = temp->item;
    if (list->head == list->tail)
    {
        list->head = list->tail = NULL;
    }
    else
    {

        list->tail->next = temp->next;
        list->head = temp->next;
    }
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
    node *temp = list->head;
    if (list->head == list->tail)
    {
        int data = temp->item;
        free(temp);
        list->head = list->tail = NULL;
        return data;
    }

    while (temp->next != list->head)
    {
        temp = temp->next;
    }
    node *last = temp->next;
    data = last->item;
    temp->next = list->head;
    list->tail = temp;
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

    // while (temp != NULL && temp->item != x)
    // {
    //     prev = temp;
    //     temp = temp->next;
    // }
    // if (temp == NULL)
    //     return 0;
    // data = temp->item;
    // if (prev == NULL)
    // {
    //     list->head = temp->next;
    // }
    // else
    // {
    //     prev->next = temp->next;
    // }
    do
    {
        if (temp->item == x)
        {
            int data = temp->item;

            if (temp == list->head)
                return deletefirst(list);

            if (temp == list->tail)
                return deletelast(list);

            prev->next = temp->next;
            free(temp);
            return data;
        }

        prev = temp;
        temp = temp->next;

    } while (temp != list->head);
}

void display(sll *list)
{
    if (isEmpty(list))
    {
        printf("List is Empty !");
        return;
    }
    node *temp = list->head;
    do
    {
        printf("%d ", temp->item);
        temp = temp->next;
    } while (temp != list->head);

    printf("\n");
}

int size(sll *list)
{
    if (isEmpty(list))
        return 0;

    int count = 0;
    node *temp = list->head;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != list->head);
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

    do
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    } while (curr != list->head);
    node *temp = list->head;
    list->head = list->tail;
    list->tail = temp;
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

    return 0;
}
