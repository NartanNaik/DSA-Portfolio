#include <iostream>
using namespace std;
void print15(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (char j = 'A'; j < 'A' + i; j++)
        {
            cout << j;
        }
        cout << endl;
    }
    for (int i = n-2 ; i >= 0; i--)
    {
        for (char j = 'A'; j <= 'A' + i; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}
int main()
{
    int n, t;
    cout << "Enter the number how many time to test: ";
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        cout << "Enter the number: ";
        cin >> n;
        print15(n);
    }

    return 0;
}