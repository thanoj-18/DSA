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

void findpresuc(node *root, node **pre, node **suc, int key)
{
    if (root == NULL)
        return;
    if (root->item == key)
    {
        if (root->left)
        {
            node *temp = root->left;
            while (temp->right)
                temp = temp->right;
            *pre = temp;
        }
        if (root->right)
        {
            node *temp = root->right;
            while (temp->left)
                temp = temp->left;
            *suc = temp;
        }
    }
    else if (key < root->item)
    {
        *suc = root;
        findpresuc(root->left, pre, suc, key);
    }
    else
    {
        *pre = root;
        findpresuc(root->right, pre, suc, key);
    }
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

    node *pre = NULL, *suc = NULL;
    int key = 15;

    findpresuc(root, &pre, &suc, key);

    if (pre)
        printf("Predecessor: %d\n", pre->item);
    if (suc)
        printf("Successor: %d\n", suc->item);
}