#include <stdio.h>
#include <stdlib.h>

typedef struct TNode
{
    int item;
    struct TNode *left;
    struct TNode *right;
} node;

typedef struct BST
{
    node *root;
} bst;

node *createnode(int data)
{
    node *n = (node *)malloc(sizeof(node));
    n->item = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void createBST(bst *tree)
{

    tree->root = NULL;
}

// Insertion

node *insertNode(node *root, int x)
{
    if (root == NULL)
    {
        return createnode(x);
    }
    else if (x > root->item)
    {
        root->right = insertNode(root->right, x);
    }
    else if (x < root->item)
    {
        root->left = insertNode(root->left, x);
    }
    // createnode(x);

    return root;
}

void insert(bst *tree, int x)
{
    tree->root = insertNode(tree->root, x);
}

// Deletion

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
    {
        return NULL;
    }
    if (key > root->item)
    {
        root->right = deleteNode(root->right, key);
    }
    else if (key < root->item)
    {
        root->left = deleteNode(root->left, key);
    }
    else
    {
        // Here Three cases arise when the key matches

        // Case 1 : Node with zero children
        if (root->right == NULL && root->left == NULL)
        {

            free(root);
            return NULL;
        }

        // Case 2 : Node with 1 child
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        else if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }

        // Case 3 : Node with 2 children
        else
        {
            node *temp = findMin(root->right);
            root->item = temp->item; // replacing the key value with inorder succer or inorder predecessor
            root->right = deleteNode(root->right, temp->item);
        }
    }
    return root;
}

void delete(bst *tree, int key)
{
    tree->root = deleteNode(tree->root, key);
}

// Traversal

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

// Using BFS

#define MAX 100
node *Queue[MAX];
int front = 0, rear = 0;
void enqueue(node *curr)
{
    Queue[rear++] = curr;
}
node *dequeue()
{
    return Queue[front++];
}
int isEmpty()
{
    return front == rear;
}
void levelorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    enqueue(root);
    while (!isEmpty())
    {
        node *temp = dequeue();

        printf("%d ", temp->item);

        if (temp->left != NULL)
        {
            enqueue(temp->left);
        }
        if (temp->right != NULL)
        {
            enqueue(temp->right);
        }
    }
}
int search(bst *tree, int key)
{
    if (tree->root == NULL)
    {
        return 0;
    }
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
        else if (key < temp->item)
        {
            temp = temp->left;
        }
    }
    return 0;
}
int main()
{

    bst tree;
    createBST(&tree);

    int arr[] = {5, 3, 7, 2, 4, 6, 8, 1, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        insert(&tree, arr[i]);
    }

    printf("Inorder Traversal : ");
    inorder(tree.root);
    printf("\n");
    printf("Preorder Traversal : ");
    preorder(tree.root);
    printf("\n");
    printf("PostOrder Traversal :");
    postorder(tree.root);
    printf("\n");
    printf("Level Order Traversal :");
    levelorder(tree.root);
    printf("%d ", search(&tree, 11));

    delete(&tree, 8);
    printf("\n");
    printf("\n");

    printf("Inorder Traversal : ");
    inorder(tree.root);
    printf("\n");
    printf("Preorder Traversal : ");
    preorder(tree.root);
    printf("\n");
    printf("PostOrder Traversal :");
    postorder(tree.root);
    printf("\n");
    return 0;
}
