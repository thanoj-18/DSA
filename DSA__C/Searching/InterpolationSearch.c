#include <stdio.h>
#include <stdlib.h>

int position(int arr[], int key, int l, int h)
{
    return (l + (((key - arr[l]) * (h - l)) / (arr[h] - arr[l]))); // Interpolation formula
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    int key = 70;
    int low = 0, high = n - 1;
    int p = 0;
    while (low <= high && key >= arr[low] && key <= arr[high])
    {
        p = position(arr, key, low, high);
        if (key == arr[p])
        {
            printf("%d is found at Index %d.", key, p);
            return 1;
        }
        else if (arr[p] >= key)
        {
            high = p - 1;
        }
        else
        {
            low = p + 1;
        }
    }
    printf("Key Not Found !!");

    return 0;
}