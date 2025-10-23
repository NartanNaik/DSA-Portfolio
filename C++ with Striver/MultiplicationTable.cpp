#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the Number: ";
    cin >> n;
    cout << "Your Multiplication Table:\n";
    int mul;
    for (int i = 1; i <= 10; i++)
    {
        mul = i * n;
        cout << n << " X " << i << " = " << mul<<endl;
    }
    cout << "Done";
    return 0;
}