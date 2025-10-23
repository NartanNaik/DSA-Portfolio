#include <iostream>
using namespace std;
void print18(int n)
{
    int inspace = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }
        for (int l = 0; l < inspace; l++)
        {
            cout << " ";
        }
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }
        inspace += 2;
        cout << endl;
    }
    int anSpace = (n*2)-2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= i + 1; j++)
        {
            cout << "*";
        }
        for (int l = 0; l <anSpace; l++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i + 1; j++)
        {
            cout << "*";
        }
        anSpace -=2;
        cout<<endl;
    }
}
int main()
{
    int n, t;
    // cout << "Enter the number how many time to test: ";
    // cin >> t;
    // for (int k = 0; k < t; k++)
    // {
    cout << "Enter the number: ";
    cin >> n;
    print18(n);
    // }

    return 0;
}