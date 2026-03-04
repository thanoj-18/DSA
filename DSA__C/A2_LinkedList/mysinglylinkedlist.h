#ifndef SLL_H
#define SLL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int item;
    struct Node *next;
} node;

typedef struct SLL
{
    struct Node *head;
} sll;

void CreateList(sll *list);
int isEmpty(sll *list);

void insertfirst(sll *list, int data);
void insertlast(sll *list, int data);
int insertat(sll *list, int data,int position);

struct Node *Search(sll *list, int data);
void insertafter(node *temp, int data);

int deletefirst(sll *list);
int deletelast(sll *list);
int deleteitem(sll *list, int data);

void display(sll *list);
int size(sll *list);
void reverse(sll *ilst);


void reversePrint(node *temp);


#endif