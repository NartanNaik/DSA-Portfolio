#include <iostream>
using namespace std;
void print11(int n)
{
    int start = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            start = 1;
        }
        else
        {
            start = 0;
        }
        for (int j = 1; j <= i; j++)
        {
            start = 1 - start;
            cout << start << " ";
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
        print11(n);
    }

    return 0;
}