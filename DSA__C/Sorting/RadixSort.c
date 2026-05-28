#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int n;
    printf("Enter the no.of Elements : ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    int *op = malloc(n * sizeof(int));

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

    // Radix Sort  : 170 45 75 90 802 24 2 66 501 305

    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    int place = 1;
    while (max / place > 0)
    {
        int count[10] = {0};
        for (int i = 0; i < n; i++)
        {
            count[(arr[i] / place) % 10]++;
        }
        for (int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            int digit = arr[i] / place % 10;
            op[count[digit] - 1] = arr[i];
            count[digit]--;
        }

        for (int i = 0; i < n; i++)
        {
            arr[i] = op[i];
        }

        place *= 10;
    }

    printf("\nSorted Array :");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}