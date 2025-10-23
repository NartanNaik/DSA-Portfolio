#include <iostream>
#include <string>
using namespace std;

int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int main()
{
    int n;
    cout << "Enter Num: ";
    cin >> n;
    int sum = factorial(n);
    cout << sum;
    return 0;
}