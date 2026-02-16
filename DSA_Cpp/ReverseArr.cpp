#include <iostream>
using namespace std;

void rev(int *arr, int si, int li)
{
    for (int i = si, j = li; i < j; i++, j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
}

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
    cout << "Given Array : \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Reversing an Array

    rev(&arr[0], 0, n - 1);

    cout << "\nReversed Array : \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
