#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter No.of ROws :";
    cin >> n;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j < i*2; j++)
        {
            cout << j<<" ";
        }
        
        cout << "\n";
    }
    return 0;
}