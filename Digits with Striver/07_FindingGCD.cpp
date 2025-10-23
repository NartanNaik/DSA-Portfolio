#include <iostream>
using namespace std;
void findGCD(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }
    if (a == 0)
    {
        cout << b;
    }
    else
    {
        cout << a;
    }
}
int main()
{
    int a, b;
    cout << "Enter the number a: ";
    cin >> a;
    cout << endl;
    cout << "Enter the number b: ";
    cin >> b;
    cout << endl;
    cout << "The GCD is: ";
    findGCD(a, b);
    return 0;
}