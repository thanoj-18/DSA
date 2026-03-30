#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int item;
    struct Node *left;
    struct Node *right;
} node;

typedef struct BST
{
    node *root;
} bst;

void createBST(bst *tree)
{
    tree->root = NULL;
}

node *createNode(int data)
{
    node *n = (node *)malloc(sizeof(node));
    n->item = data;
    n->left = n->right = NULL;
    return n;
}

int isEmpty(bst *tree)
{
    return tree->root == NULL;
}

node *insertNode(node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->item)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->item)
    {
        root->right = insertNode(root->right, data);
    }

    return root;
}

void insert(bst *tree, int data)
{
    tree->root = insertNode(tree->root, data);
}

node *findMin(node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

node *deleteNode(node *root, int key)
{

    if (root == NULL)
        return NULL;

    if (key < root->item)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->item)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {

        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        else if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }

        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }

        else
        {
            node *temp = findMin(root->right);
            root->item = temp->item;
            root->right = deleteNode(root->right, temp->item);
        }
    }
    return root;
}

void delete(bst *tree, int key)
{
    tree->root = deleteNode(tree->root, key);
}

int search(bst *tree, int key)
{
    node *temp = tree->root;
    while (temp != NULL)
    {
        if (key == temp->item)
        {
            return 1;
        }
        else if (key > temp->item)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->item);
        inorder(root->right);
    }
}

void preorder(node *root)
{

    if (root != NULL)
    {
        printf("%d ", root->item);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->item);
    }
}

#define MAX 100

node *queue[MAX];
int front = -1, rear = -1;

void enqueue(node *n)
{
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = n;
}

node *dequeue()
{
    if (front == -1 || front > rear)
        return NULL;
    return queue[front++];
}

void levelOrder(node *root)
{
    if (root == NULL)
        return;

    enqueue(root);

    while (front <= rear)
    {
        node *temp = dequeue();
        printf("%d ", temp->item);

        if (temp->left)
            enqueue(temp->left);
        if (temp->right)
            enqueue(temp->right);
    }
}

int main()
{
    bst tree;
    createBST(&tree);

    insert(&tree, 5);
    insert(&tree, 7);
    insert(&tree, 2);
    insert(&tree, 20);
    insert(&tree, 35);
    insert(&tree, 17);
    insert(&tree, 10);
    insert(&tree, 6);
    insert(&tree, 1);
    
    printf("Inorder  ");
    inorder(tree.root);

    printf("\nPreorder  ");
    preorder(tree.root);

    printf("\nPostorder  ");
    postorder(tree.root);

    printf("\nLevel Order: ");
    levelOrder(tree.root);

    delete(&tree, 50);

    printf("\nAfter deletion (Inorder): ");
    inorder(tree.root);

    return 0;
}