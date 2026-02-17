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
    int t;
    cout << "Enter the Target:" << endl;
    cin >> t;
    cout << endl;

    int psum = 0;
    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        if ((arr[i] + arr[j]) == t)
        {
            cout << "(" << arr[i] << "," << arr[j] << ")";
            return 1;
        }
        else if ((arr[i] + arr[j]) >= t)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    return 0;
}
