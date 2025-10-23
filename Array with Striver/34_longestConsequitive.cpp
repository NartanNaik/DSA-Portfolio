#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <algorithm>
using namespace std;
int betterLongestCons(vector<int> &a, int n)
{
    if (n == 0)
    {
        return 0;
    }
    sort(a.begin(), a.end());
    int lastSmaller = INT_MIN;
    int count = 0;
    int longest = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] - 1 == lastSmaller)
        {
            count++;
            lastSmaller = a[i];
        }
        else if (a[i] != lastSmaller)
        {
            count = 1;
            lastSmaller = a[i];
        }
        longest = max(longest, count);
    }
    return longest;
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
    int ans = betterLongestCons(a, n);
    cout << "The Longest Consecutive Sequence: " << ans;
    return 0;
}