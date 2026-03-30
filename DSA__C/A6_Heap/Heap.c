#include <stdio.h>
#include <stdlib.h>

#define MAX 30

int heap[MAX];
int curr;

void init()
{
    curr = -1;
}

void swap(int x, int y)
{
    int temp = heap[x];
    heap[x] = heap[y];
    heap[y] = temp;
}

void heapifyup()
{
    int x = curr;

    while (x > 0)
    {

        int parent = (x - 1) / 2;

        if (heap[x] > heap[parent])
        {
            swap(x, parent);
            x = parent;
        }
        else
        {
            break;
        }
    }
}

void insert(int data)
{
    curr++;
    heap[curr] = data;
    heapifyup();
}

void heapifydown(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l <= n && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (r <= n && arr[r] > arr[largest]) /// o
    {
        largest = r;
    }
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapifydown(arr, n, largest);
    }
}

int delete()
{
    if (curr == -1)
    {
        printf("Heap is empty\n");
        return -1;
    }

    int data = heap[0];
    heap[0] = heap[curr--];
    heapifydown(heap, curr, 0);
    return data;
}

void heapsort(int arr[], int n)
{

    // Build max heap

    for (int i = (n - 1) / 2; i >= 0; i--)
    {
        heapifydown(arr, n, i);
    }

    for (int i = n; i >= 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapifydown(arr, i - 1, 0);
    }
}

void display()
{
    printf("\nBinary Heap\n\n");
    for (int i = 0; i <= curr; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");

    return;
}

int Maximum()
{
    return heap[0];
}

int Minimum(){
    
}

int main()
{
    init();
    insert(5);
    insert(7);
    insert(10);
    insert(13);
    insert(15);
    insert(8);
    insert(11);
    display();
    // delete();
    // display();
    heapsort(heap, curr);
    display();

    return 0;
}