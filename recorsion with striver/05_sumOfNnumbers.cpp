#include <iostream>
#include <string>
using namespace std;

void subm(int n, int sum)
{
    if (n < 1)
    {
        cout << sum << endl;
        return;
    }
    subm(n - 1, sum + n);
}

int main()
{
    int n;
    cout << "Enter Num: ";
    cin >> n;
    subm(n, 0);
    return 0;
}