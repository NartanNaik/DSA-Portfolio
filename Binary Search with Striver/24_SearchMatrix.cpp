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

// Here the matrix is sorted
// like this
// 1 2 3
// 4 5 6
// 7 8 9

// but maybe also like this 
// 1 2 3
// 1 4 5
// 3 4 5

// That's why these works for both the cases 

// this is for optimized search and it's time complexity will be TC = 0(n+m) and SC = O(1)
bool OptimizedMatrixSearch(vector<vector<int>> &a, int target)
{
    int n = a.size();
    int m = a[0].size();
    int row = 0, colo = m - 1;
    while (row < n && colo >= 0)
    {
        if (a[row][colo] == target)
        {
            return true;
        }
        else if (a[row][colo] < target)
        {
            row++;
        }
        else
        {
            colo--;
        }
    }
    return false;
}

int main()
{
    int n, m;
    cout << "Enter the row: ";
    cin >> n;
    cout << "Enter the column: ";
    cin >> m;
    vector<vector<int>> a(n, vector<int>(m));
    cout << "Enter the matrix: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            cout << " ";
        }
        cout << "\n";
    }
    int t;
    cout << "Enter the target: ";
    cin >> t;
    if (OptimizedMatrixSearch(a, t))
    {
        cout << "You got me " << t;
    }
    else
    {
        cout << "Why are you " << t;
    }

    return 0;
}