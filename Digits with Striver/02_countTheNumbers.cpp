#include <iostream>
using namespace std;
int counted(int n)
{
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        count++;
    }
    return count;
}
int main()
{
    int n;
    cout << "Give the number: ";
    cin >> n;
    int cou=counted(n);
    cout << "Counted number: "<<cou;
    return 0;
}