#include <iostream>
#include <string>
#include <vector>
using namespace std;

auto arraySwap(int l, vector<int> &a, int n)
{
    if (l >= n / 2)
    {
        return;
    }
    swap(a[l], a[n - l - 1]);
    arraySwap(l + 1, a, n);
}

int main()
{
    int n;
    cout << "Enter Size: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter numbers:\n";
    for (auto i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    arraySwap(0, a, n);
    for (auto el : a)
    {
        cout << el<<" ";
    }
    return 0;
}