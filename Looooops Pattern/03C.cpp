#include <iostream>
using namespace std;
void print3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j<<" ";
        }
        cout << endl;
    }
}
int main()
{
    int n, t;
    cout << "Enter the number of test Cases: ";
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        cout << "Enter the number: ";
        cin >> n;
        print3(n);
    }
    cout << endl;
    return 0;
}