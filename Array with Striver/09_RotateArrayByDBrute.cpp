#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
using namespace std;
vector<int> dApproach(vector<int> &a, int n, int d)
{
    d = d % n;
    vector<int> temp(d);
    for (int i = 0; i < d; i++)
    {
        temp[i] = a[i];
    }
    for (int i = d; i < n; i++)
    {
        a[i - d] = a[i];
    }
    for (int i = n - d; i < n; i++)
    {
        a[i] = temp[i - (n - d)];
    }
    return a;
}
int main()
{
    int n;
    cout << "Enter the size of the Array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter the Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int d;
    cout << "Enter d: ";
    cin >> d;
    dApproach(a, n, d);
    for (auto it : a)
    {
        cout << it << " ";
    }
    return 0;
}