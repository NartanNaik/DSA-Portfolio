#include <iostream>
using namespace std;
int main()
{
    int facto = 1;
    int n;
    cout << "Enter the Size of Factorial: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        facto *= i;
    }
    cout << "Factorial is: " << facto;
    return 0;
}