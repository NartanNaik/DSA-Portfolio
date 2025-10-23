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

// this is the brute force approach
// int middleNumber(vector<vector<int>> &matrix, int n, int m)
// {
//     vector<int> tube;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             tube.push_back(matrix[i][j]);
//         }
//     }

//     sort(tube.begin(), tube.end());

//     int midIndex = tube.size() / 2;

//     return midIndex;
// }

int findUpperBound(vector<int> &a, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] > x)
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

int countSmallEqual(vector<vector<int>> &a, int n, int m, int x)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += findUpperBound(a[i], m, x);
    }
    return cnt;
}

int optimalMedian(vector<vector<int>> matrix, int n, int m)
{
    int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][m - 1]);
    }
    int req = (n * m) / 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(matrix, n, m, mid);
        if (smallEqual <= req)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    int n, m;
    cout << "Enter the Row and the Column: ";
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter the matrix: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int MiddleNumer = optimalMedian(matrix, n, m);
    cout << "The middle number is " << MiddleNumer;
    return 0;
}