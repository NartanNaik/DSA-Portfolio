#include <iostream>
using namespace std;
void isPrime(int &n)
{
    bool ok = true;
    if (n < 2)
    {
        ok = false;
    }
    else
    {
        for (int i = 2; i <= n / 2; i++)
        {
            if (n % i == 0)
            {
                ok = false;
                break;
            }
        }
    }

    if (ok)
    {
        cout << "This is a Prime Number..";
    }
    else
    {
        cout << "This is not a Prime Number..";
    }
}
int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    isPrime(n);
    return 0;
}