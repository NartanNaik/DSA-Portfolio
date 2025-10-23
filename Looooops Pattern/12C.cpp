#include <iostream>
using namespace std;
void print12(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= i + 1; j++)
        {
            cout << j;
        }
        for (int l = 0; l < (n - i - 1) * 2; l++)
        {
            cout << " ";
        }
        for (int m = i+1; m >=1; m--)
        {
         cout<<m;
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
        print12(n);
    }

    return 0;
}