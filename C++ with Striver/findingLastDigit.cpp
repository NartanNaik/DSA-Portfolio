#include <iostream>
using namespace std;
int reversed(int &n)
{
    int reverse = 0;
    while (n != 0)
    {
        int digit = n % 10;
        reverse = reverse * 10 + digit;
        n = n / 10;
    }
    return reverse;
}
int main()
{
    int n;
    cout << "Enter the Number: ";
    cin >> n;
    int r = reversed(n);
    cout << "Your Reversed Number: " << r;
    return 0;
}