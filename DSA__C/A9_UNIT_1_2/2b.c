#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int item;
    struct Node *left, *right;
} node;

node *newNode(int data)
{
    node *n = (node *)malloc(sizeof(node));
    n->item = data;
    n->left = n->right = NULL;
    return n;
}

node *insert(node *root, int data)
{
    if (root == NULL)
        return newNode(data);
    if (data < root->item)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }

    return root;
}

node *findnode(node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (root->item == key)
        return root;

    node *left = findnode(root->left, key);

    if (left != NULL)
        return left;

    node *right = findnode(root->right, key);

    if (right != NULL)
        return right;

    return NULL;
}

int height(node *root)
{
    if (root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return (left > right ? left : right) + 1;
}

int longestpath(node *root, int key)
{
    node *target = findnode(root, key);

    if (target == NULL)
    {
        printf("Node Not Found\n");
        return -1;
    }

    return height(target)-1;
}

int main()
{
    node *root = NULL;
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 5);
    insert(root, 15);
    insert(root, 21);

    int key = 10;

    int result = longestpath(root, key);

    printf("Longest path from %d = %d\n", key, result);

    return 0;
}