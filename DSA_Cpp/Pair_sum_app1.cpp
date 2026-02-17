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
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        psum = arr[temp] + arr[i + 1];
        if (psum == t)
        {
            cout << "(" << arr[temp] << "," << arr[i + 1] << ")";
        }

        if ((i + 1) == n)
        {
            temp++;
            psum = 0;
            i = temp - 1;
        }

        psum = 0;
    }
    return 0;
}
