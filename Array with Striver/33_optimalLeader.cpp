#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <algorithm>
using namespace std;
vector<int> optimalSolutionLeader(vector<int> &a, int n)
{
    vector<int> ans;
    int maxi = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] > maxi)
        {
            ans.push_back(a[i]);
        }
        maxi = max(maxi, a[i]);
    }
    sort(ans.begin(), ans.end());
    return ans;
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
    vector<int> soluton = optimalSolutionLeader(a, n);
    cout<<"The Leaders are: ";
    for (auto it : soluton)
    {
        cout << it << " ";
    }
    return 0;
}