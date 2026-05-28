#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n;
    printf("Enter the no.of Elements : ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));

    printf("Enter the Elements : ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal Array :");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // Insertion sort

    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && temp < arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }

    printf("\nSorted Array :");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}