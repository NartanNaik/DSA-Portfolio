#include <iostream>
using namespace std;
void print6(int n)
{
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n, t;
    cout << "Enter the Number: ";
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        cout << "Enter: ";
        cin >> n;
        print6(n);
    }

    return 0;
}