#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int isPrimeNumber(int n)
{
    if (n == 1)
    {
        return 0;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}
int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    int num = isPrimeNumber(n);
    if (num == 0)
    {
        cout << "This is not the prime number";
    }
    else
    {
        cout << "This is the prime number";
    }
}