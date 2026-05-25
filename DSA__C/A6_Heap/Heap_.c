#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

#define MAX 100

int Heap[MAX];
int curr;

void init()
{
    curr = -1;
}

void HeapifyUp()
{
    // Restores the Heap property by comparing and replacing the just inserted node with its parent nodes

    int x = curr;
    while (x > 0)
    {
        int parent = (x - 1) / 2;
        if (Heap[x] > Heap[parent])
        {
            int temp = Heap[x];
            Heap[x] = Heap[parent];
            Heap[parent] = temp;

            x = parent;
        }
        else
        {
            break;
        }
    }
}

void HeapifyDown(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        HeapifyDown(arr, n, largest);
    }
}
void insert(int data)
{
    Heap[++curr] = data;
    HeapifyUp();
}

int deleteMax()
{
    if (curr == -1)
    {
        printf("Heap is Empty ");
        return 0;
    }

    int data = Heap[0];
    Heap[0] = Heap[curr--];
    HeapifyDown(Heap, curr+1, 0);
}

void HeapSort(int arr[], int n)
{
    // Build Max Heap
    for (int i = (n - 1) / 2; i >= 0; i--)
    {
        HeapifyDown(arr, n, i);
    }

    // Swap with last element

    for (int i = n-1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        HeapifyDown(arr, i, 0);
    }
}

void display()
{
    printf("\nBinary Heap\n\n");
    for (int i = 0; i <= curr; i++)
    {
        printf("%d ", Heap[i]);
    }
    printf("\n");

    return;
}

int Maximum()
{
    return Heap[0];
}

int Minimum()
{
    int min = INT_MAX;
    for (int i = 0; i <= curr; i++)
    {
        if (Heap[i] < min)
        {
            min = Heap[i];
        }
    }

    return min;
}

int main()
{
    return 0;
}