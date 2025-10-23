#include <iostream>
using namespace std;
void check(int &n)
{
    if (n % 2 == 0)
    {
        cout << "This is Even number..";
    }
    else
    {
        cout << "This is the Odd number..";
    }
}
int main()
{
    int n;
    cout << "Enter the Number: ";
    cin >> n;
    check(n);
    return 0;
}