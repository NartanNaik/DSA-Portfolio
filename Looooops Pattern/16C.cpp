#include <iostream>
using namespace std;
void print16(int n)
{
    for (int i = 1; i <= n; i++)
    {
        char ch = 'A';
        int breakPoint = (2 * i - 1) / 2;
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }
        for (int l = 1; l <= 2 * i - 1; l++)
        {
            cout << ch;
            if (l <= breakPoint)
            {
                ch++;
            }
            else
            {
                ch--;
            }
        }

        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
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
        print16(n);
    }

    return 0;
}