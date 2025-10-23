#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <algorithm>
using namespace std;
vector<int> findNextPermutation(vector<int> &a, int n)
{
    int index = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] < a[i + 1])
        {
            index = i;
            break;
        }
    }
    if (index = -1)
    {
        reverse(a.begin(), a.end());
        return a;
    }
    for (int i = n - 1; i > index; i--)
    {
        if (a[i] > a[index])
        {
            swap(a[i], a[index]);
            break;
        }
    }
    reverse(a.begin() + index + 1, a.end());
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
    vector<int> ans = findNextPermutation(a, n);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}