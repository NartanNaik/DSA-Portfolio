#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
using namespace std;
void mvZero(vector<int> &a, int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            temp.push_back(a[i]);
        }
    }
    int nonZ = temp.size();
    for (int i = 0; i < nonZ; i++)
    {
        a[i] = temp[i];
    }
    for (int i = nonZ; i < n; i++)
    {
        a[i] = 0;
    }
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
    cout << "Sorted: ";
    mvZero(a, n);
    for (auto it : a)
    {
        cout << it << " ";
    }
    return 0;
}