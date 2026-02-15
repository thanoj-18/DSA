#include <iostream>
#include <vector>
using namespace std;
int main()
{

    
    int n;
    cout << "Enter the Size of Array :" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements in an Array :"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cout << "Enter the Key :" << endl;
    cin >> key;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << "The key " << key << " is found at index = " << i << endl;
            return 1;
        }
    }

    return 0;
}