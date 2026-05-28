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

    // Shell sort

    for (int gap = n / 2; gap > 0; gap = gap / 2)
    {
        for (int i = gap; i < n; i++)
        {
            int j, temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j = j - gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    // Insertion sort By me !!!

    /*
    int gap = n / 2;
    while (gap > 0)
    {
       int j = gap;
       for (int i = 0; j < n; j++, i++)
       {
           if (arr[j] < arr[i])
           {
               int temp = arr[j];
               arr[j] = arr[i];
               arr[i] = temp;
           }
           if (i - gap >= 0 && arr[i] < arr[i - gap])
           {
               int temp = arr[i - gap];
               arr[i - gap] = arr[i];
               arr[i] = temp;
           }
       }
       gap = gap / 2;
   } */

    printf("\nSorted Array :");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}