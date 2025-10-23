#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;
// TC->O(nlogn)+O(2n) and SC-> O(n)
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &a)
{
    int n = a.size();
    sort(a.begin(), a.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        int start = a[i][0];
        int end = a[i][1];
        if (!ans.empty() && end <= ans.back()[1])
        {
            continue;
        }
        for (int j = 0; j < n; j++)
        {
            if (a[j][0] <= end)
            {
                end = max(end, a[j][1]);
            }
            else
            {
                break;
            }
        }
        ans.push_back({start, end});
    }

    return ans;
}

int main()
{
    int n;
    cout << "Enter the number of Intervels...";
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    cout << "Enter each interval as two space-separated integers (start end):\n";
    for (int i = 0; i < n; i++)
    {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    vector<vector<int>> merged = mergeOverlappingIntervals(intervals);
    cout << "Merged Intervals:\n";
    for (auto &interval : merged)
    {
        cout << interval[0] << " " << interval[1] << "\n";
    }

    return 0;

    //Sample intput and output:
    //Enter the number of Intervels...4
    // Enter each interval as two space-separated integers (start end):
    // 1 3
    // 2 6
    // 8 10
    // 9 11
    // Merged Intervals:
    // 1 6
    // 8 11
}