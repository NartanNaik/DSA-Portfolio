#include <iostream>
using namespace std;
int doing(int &a)
{
    return a+1;
}
int main()
{
    int a;
    cout << "Enter the Value: ";
    cin >> a;
    int b = doing(a);
    cout << "The Value is: " << b;
    return 0;
}