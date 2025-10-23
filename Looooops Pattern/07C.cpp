#include <iostream>
using namespace std;
void print7(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i-1; j++)
        {
            cout << " ";
        }
        for (int l = 0; l < 2*i+1; l++)
        {
            cout << "*";
        }
        for (int j = 0; j < n - i-1; j++)
        {
            cout << " ";
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
        print7(n);
    }

    return 0;
}