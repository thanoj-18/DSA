#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{

    int n;
    printf("Enter the no.of Elements : ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    int *oparr = malloc(n * sizeof(int));
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

    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    int *count = malloc((max + 1) * sizeof(int));

    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        count[arr[i]] += 1;
    }

    // cumulative count array
    for (int i = 1; i < max + 1; i++)
    {
        count[i] += count[i - 1];
    }

    // output array
    for (int i = n - 1; i >= 0; i--)
    {
        oparr[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = oparr[i];
    }

    printf("\nSorted Array :");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}