#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    int reverse = 0;
    while (n != 0)
    {
        int digit = n % 10;
        reverse = reverse * 10 + digit;
        n = n / 10;
    }
    cout << "Number after Reversed: " << reverse;
    return 0;
}