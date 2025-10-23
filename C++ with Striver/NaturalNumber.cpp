#include <iostream>
using namespace std;
void Natural(int &n)
{
    int sum = (n * (n + 1)) / 2;
    cout << "Sum of the Natural Numbers is: " << sum;
}
int main()
{
    int n;
    cout << "Enter the number of Natural Numbers: ";
    cin >> n;
    Natural(n);
    return 0;
}