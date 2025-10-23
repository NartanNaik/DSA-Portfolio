#include <iostream>
using namespace std;
int main()
{
    // int a = 0, b = 1, n;
    // cout << "Enter the term: ";
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << a << " ";
    //     int temp = a + b;
    //     a = b;
    //     b = temp;
    // }
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "#";
        }
        cout << "\n";
    }

    return 0;
}