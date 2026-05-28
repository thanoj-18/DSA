#include <stdio.h>

void Heapify(int arr[], int n, int i)
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

        Heapify(arr, n, largest);
    }
}

void HeapSort(int arr[], int n)
{
    // Build Max Heap

    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        Heapify(arr, n, i);
    }

    // Swap with last element

    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;

        Heapify(arr, i, 0);
    }
}

void Display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {40, 10, 30, 50, 60, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    Display(arr, n);

    HeapSort(arr, n);

    printf("Sorted Array:\n");
    Display(arr, n);

    return 0;
}