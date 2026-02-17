#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int x;
    cout << "Enter the base:" << endl;
    cin >> x;
    int n;
    cout << "Enter the power :" << endl;
    cin >> n;

    // first convert the n into binary form
    double ans = 1;
    long bf = n;

    while (bf > 0)
    {
        if (bf % 2 == 1)
        {
            ans = ans * x;
        }
        x *= x;
        bf = bf / 2;
    }

    cout << ans;

    return 0;
}
