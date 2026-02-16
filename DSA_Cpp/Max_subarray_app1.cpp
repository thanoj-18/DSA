#include <iostream>
#include <climits>
using namespace std;

int main()
{

    int n;
    cout << "Enter the size of an Array :" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the Elements :" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
    int sum = 0;
    int msum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum >= msum)
            {
                msum = sum;
            }
        }
        sum = 0;
    }
    cout << "Maximum Subarray sum is :"<<msum;
    return 0;
}
