#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

int findLoweBound(vector<int> &a, int n, int x)
{
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int numberOnrsInTheRow(vector<vector<int>> &a, int m, int n)
{
    int cnt_max = 0;
    int row_index = -1;
    for (int i = 0; i < m; i++)
    {
        int cnt_one = m - findLoweBound(a[i], n, 122);
        if (cnt_one > cnt_max)
        {
            cnt_max = cnt_one;
            row_index = i;
        }
    }
    return row_index;
}

int main()
{
    int m, n;
    cout << "Enter row and column : ";
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));
    cout << "Enter the elements only 0s and 1s : ";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
        sort(a[i].begin(), a[i].end());
    }
    return 0;
}