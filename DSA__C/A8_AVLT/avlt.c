#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int item;
    struct Node *left;
    struct Node *right;
    int height;
} node;

typedef struct AVL
{
    node *root;
} avl;

int height(node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

node *newNode(int data)
{
    node *n = (node *)malloc(sizeof(node));
    n->item = data;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}


void insert(avl *tree, int data)
{
}