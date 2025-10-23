#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;
// TC->O(nlogn)+O(n) and SC-> O(n)
vector<vector<int>> optimalMerge(vector<vector<int>> &a, int n)
{
    sort(a.begin(), a.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (ans.empty() || a[i][0] > ans.back()[1])
        {
            ans.push_back(a[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], a[i][1]);
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the number of intervals: ";
    cin >> n;
    vector<vector<int>> intervels(n, vector<int>(2));
    cout << "Enter the intervals:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> intervels[i][0] >> intervels[i][1];
    }
    vector<vector<int>> merged = optimalMerge(intervels, n);
    cout<<"Intervals after merge:\n";
    for (auto &interval : merged)
    {
        cout << interval[0] << " " << interval[1] << "\n";
    }
    return 0;
}