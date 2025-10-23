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

// Peak element is the element which is larger than it's left and right in 1d array but in matrix it's the number which is larger than right, left, top, bottom

// TC => O(log2 m*n)
// SC => O(1)

int findMaxIndex(vector<vector<int>> &a, int n, int m, int col)
{
    int maxValue = -1;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i][col] > maxValue)
        {
            maxValue = a[i][col];
            index = i;
        }
    }
    return index;
}

vector<int> findPeakGrid(vector<vector<int>> &a)
{
    int n = a.size();
    int m = a[0].size();
    int low = 0, high = m - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int maxRowIndex = findMaxIndex(a, n, m, mid);
        int left = mid - 1 >= 0 ? a[maxRowIndex][mid - 1] : -1;
        int right = mid + 1 < m ? a[maxRowIndex][mid + 1] : -1;
        if (a[maxRowIndex][mid] > left && a[maxRowIndex][mid] > right)
        {
            return {maxRowIndex, mid};
        }
        else if (a[maxRowIndex][mid] < left)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return {-1, -1};
}

int main()
{
    int n, m;
    cout << "Enter the size of the row: ";
    cin >> n;
    cout << "Enter the size of the coloumn: ";
    cin >> m;
    vector<vector<int>> a(n, vector<int>(m));
    cout << "Enter the matrix: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            cout << " ";
        }
        cout << "\n";
    }
    vector<int> ans = findPeakGrid(a);
    cout << "The grid which have the PeakElement is: " << ans[0] << " , " << ans[1];
    return 0;
}