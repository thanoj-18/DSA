#ifndef SLL_H
#define SLL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int item;
    struct Node *next;
    struct Node *prev;
} node;

typedef struct DLL
{
    struct Node *head;
    struct Node *tail;
} dll;

void CreateList(dll *list);
int isEmpty(dll *list);

void insertfirst(dll *list, int data);
void insertlast(dll *list, int data);
void insertat(dll *list, int data,int position);

struct Node *Search(dll *list, int data);
void insertafter(dll *list,node *temp, int data);

int deletefirst(dll *list);
int deletelast(dll *list);
int deleteitem(dll *list, int data);

void display(dll *list);
int size(dll *list);
void reverse(dll *ilst);
#endif