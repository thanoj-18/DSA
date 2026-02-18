#include <iostream>
using namespace std;

int main()
{
    int n;
    printf("Enter the size of an Array :");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the Elements of an Array :");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int temp = 0, profit = 0;
    int pmax = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[temp])
        {
            profit = arr[i] - arr[temp];
            if (profit > pmax)
                pmax = profit;
        }
        if ((i + 1) == n)
        {
            temp++;
            i = temp;
        }
    }

    printf("Maximum Profit is %d", pmax);
    return 0;
}
