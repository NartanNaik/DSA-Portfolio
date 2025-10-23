#include <iostream>
using namespace std;
int isArmstrong(int n)
{
    int digit, sum = 0, dub = n;
    while (n != 0)
    {
        digit = n % 10;
        sum += (digit * digit * digit);
        n /= 10;
    }
    if (sum == dub)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int n;
    cout << "Enter the Number: ";
    cin >> n;
    int is = isArmstrong(n);
    if (is == 1)
    {
        cout << "This is the Armstrong Number..";
    }
    else
    {
        cout << "This is not the Armstrong Number..";
    }

    return 0;
}