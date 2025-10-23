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

bool isTheNumberPresent(vector<vector<int>> &a, int m, int n, int x)
{
    int row = 0, col = n - 1;
    while (row < m && col >= 0)
    {
        if (a[row][col] == x)
        {
            return true;
        }
        else if (a[row][col] > x)
        {
            col--;
        }
        else
        {
            row++;
        }
    }
    return false;   
}
int main()
{
    int m, n, x;
    cout << "Enter row and column : ";
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));
    cout << "Enter the elements : ";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "Enter the number to search : ";
    cin >> x;

    if (isTheNumberPresent(a, m, n, x))
    {
        cout << "The number is present in the matrix." << endl;
    }
    else
    {
        cout << "The number is not present in the matrix." << endl;
    }

    return 0;
}