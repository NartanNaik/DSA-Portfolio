#include <iostream>
using namespace std;
void print18(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }   
        }
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