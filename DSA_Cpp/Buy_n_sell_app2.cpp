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
    int pmax = 0;
    int bestbuy = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > bestbuy)
        {
            pmax = max(pmax, arr[i] - bestbuy);
        }
        bestbuy = min(bestbuy, arr[i]);
    }

    printf("Maximum Profit is %d", pmax);
    return 0;
}
