#include <iostream>
#include <string>
using namespace std;

int subm(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + subm(n - 1);
}

int main()
{
    int n;
    cout << "Enter Num: ";
    cin >> n;
    int sum = subm(n);
    cout << sum;
    return 0;
}