#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int n = sizeof(arr) / sizeof(arr[0]);

    int key = 70;

    int s = sqrt(n), prev = 0;

    // Search for block
    while (arr[(s < n ? s : n) - 1] < key)
    {
        prev = s;
        s += sqrt(n);
    }

    // Linear search in Block
    while (arr[key] < key)
    {
        prev++;
    }

    if (arr[prev] == key)
    {
        printf("%d is found at Index %d.", key, prev);
        return 1;
    }

    printf("Key Not Found !!");
    return 0;
}