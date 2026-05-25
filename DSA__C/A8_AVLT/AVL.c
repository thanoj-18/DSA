#include <stdio.h>
#include <stdlib.h>

typedef struct TNode
{
    int item;
    struct TNode *left;
    struct TNode *right;
    int height;
} node;

typedef struct AVL
{
    node *root;
} avl;

int Max(int a, int b)
{
    return a > b ? a : b;
}

int height(node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

int balancefactor(node *n)
{
    return height(n->left) - height(n->right);
}

node *createNode(int data)
{
    node *n = (node *)malloc(sizeof(node));
    n->item = data;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}

node *rotate_right(node *n)
{
    node *n1 = n->left;
    node *n2 = n1->right;

    n1->right = n;
    n->left = n2;

    n->height = 1 + Max(height(n->left), height(n->right));
    n1->height = 1 + Max(height(n1->left), height(n1->right));

    return n1;
}

node *rotate_left(node *n)
{
    node *n1 = n->right;
    node *n2 = n1->left;

    n1->left = n;
    n->right = n2;

    n->height = 1 + Max(height(n->left), height(n->right));
    n1->height = 1 + Max(height(n1->left), height(n1->right));

    return n1;
}

node *insert(node *n, int data)
{
    if (n == NULL)
    {
        return createNode(data);
    }
    else if (data > n->item)
    {
        n->right = insert(n->right, data);
    }
    else if (data < n->item)
    {
        n->left = insert(n->left, data);
    }
    else
    {
        return n;
    }

    n->height = 1 + Max(height(n->left), height(n->right));

    int b = balancefactor(n);

    // LL
    if (b > 1 && data < n->left->item)
    {
        return rotate_right(n);
    }

    // RR
    if (b < -1 && data > n->right->item)
    {
        return rotate_left(n);
    }

    // RL
    if (b < -1 && data < n->right->item)
    {
        n->right = rotate_right(n->right);
        return rotate_left(n);
    }

    // LR
    if (b > 1 && data > n->left->item)
    {
        n->left = rotate_left(n->left);
        return rotate_right(n);
    }

    return n;
}

node *inorderSuccesor(node *n)
{
    node *succ = n;
    while (succ->left != NULL)
    {
        succ = succ->left;
    }
    return succ;
}

node *inorderPredecessor(node *n)
{
    node *pred = n;
    while (pred->right != NULL)
    {
        pred = pred->right;
    }

    return pred;
}

node *delete(node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    else if (key > root->item)
    {
        root->right = delete(root->right, key);
    }
    else if (key < root->item)
    {
        root->left = delete(root->left, key);
    }
    else
    {
        // 0 Child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        // 1 child
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

        // 2 Child
        else
        {
            node *temp = inorderSuccesor(root->right);
            root->item = temp->item;
            root->right = delete(root->right, temp->item);
        }
    }

    if (root == NULL)
    {
        return root;
    }

    root->height = 1 + Max(height(root->left), height(root->right));

    int b = balancefactor(root);

    // LL
    if (b > 1 && balancefactor(root->left) >= 0)
    {
        return rotate_right(root);
    }
    // LR
    if (b > 1 && balancefactor(root->left) < 0)
    {
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }
    // RR
    if (b < -1 && balancefactor(root->right) <= 0)
    {
        return rotate_left(root);
    }
    // RL
    if (b < -1 && balancefactor(root->right) > 0)
    {
        root->right = rotate_right(root->right);
        return rotate_left(root);
    }

    return root;
}

node *search(node *root, int key)
{

    while (root != NULL)
    {
        if (root->item == key)
        {
            return root;
        }
        else if (key > root->item)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return NULL;
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

// Level order traversal using BFS

#define MAX 100
node *Queue[MAX];
int front = 0, rear = 0;
int isEmpty()
{
    return front == rear;
}
void enqueue(node *curr)
{
    Queue[rear++] = curr;
}
node *dequeue()
{
    if (isEmpty())
    {
        return NULL;
    }
    return Queue[front++];
}

void LevelOrder(node *root)
{
    if (root == NULL)
        return;

    enqueue(root);
    while (front < rear)
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

int main()
{
    node *root = NULL;

    int arr[] = {50, 40, 30, 60, 70, 65, 20, 10, 25};

    int n = sizeof(arr) / sizeof(arr[0]);

    // INSERT
    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }

    // Traversals
    printf("Inorder Traversal : ");
    inorder(root);

    printf("\n");

    printf("Preorder Traversal : ");
    preorder(root);

    printf("\n");

    printf("Postorder Traversal : ");
    postorder(root);

    printf("\n");

    printf("LevelOrder Traversal : ");
    LevelOrder(root);

    printf("\n");

    // SEARCH
    int key = 65;

    if (search(root, key) != NULL)
        printf("%d Found", key);
    else
        printf("%d Not Found", key);

    printf("\n");

    // DELETE
    root = delete(root, 60);

    printf("\nAfter Deleting 60\n");

    printf("Inorder Traversal : ");
    inorder(root);

    printf("\n");

    printf("LevelOrder Traversal : ");
    LevelOrder(root);

    printf("\n");

    printf("Preorder Traversal : ");
    preorder(root);

    printf("\n");

    printf("Postorder Traversal : ");
    postorder(root);

    printf("\n");

    return 0;
}