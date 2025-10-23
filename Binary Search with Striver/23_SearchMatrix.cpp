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

// but not like this 
// 1 2 3
// 1 4 5
// 3 4 5

// That's why these works but for the second matrix i have drawn the next file will works 

// this is for brute force search and it's time complexity will be TC = 0(n*m)
bool BruteSearch(vector<vector<int>> &a, int target)
{
    int n = a.size();
    int m = a[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}

// this is optimized one where the time complexity of it is TC = O(log2(n*m))
bool searchMatrixOptimized(vector<vector<int>> &a, int target)
{
    int n = a.size();
    int m = a[0].size();
    int low = 0, high = n * m - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int row = mid / m;
        int col = mid % m;
        if (a[row][col] == target)
        {
            return true;
        }
        else if (a[row][col] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
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
    int target;
    cout << "Enter the target: ";
    cin >> target;
    if (BruteSearch(a, target))
    {
        cout << "Hey, I found out your target: " << target;
    }
    else
    {
        cout << "I didn't found your target LOOOOLLL";
    }

    return 0;
}