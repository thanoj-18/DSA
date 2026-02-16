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
    int temp = 0;
    int msum = INT_MIN;
    for (int i = 0; i < n; i++)
    {

        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
        }
        if (sum >= msum)
        {
            msum = sum;
        }
    }
    cout << "Maximum Subarray sum is :" << msum;
    return 0;
}
