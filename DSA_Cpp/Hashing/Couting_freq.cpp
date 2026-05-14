#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int n;
    cout << "Enter the size of Array :";
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int hash[13] = {0};

    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
    }

    int q;
    cin >> q;
    cout << hash[q];

    return 0;
}
