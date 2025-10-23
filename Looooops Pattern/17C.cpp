#include <iostream>
using namespace std;
void print17(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char j = 'E' - i; j <= 'E'; j++)
        {
            cout << j << " ";
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
        print17(n);
    }

    return 0;
}