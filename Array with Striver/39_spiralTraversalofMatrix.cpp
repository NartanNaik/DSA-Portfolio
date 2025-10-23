#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<int> spiralTraversal(vector<vector<int>> &matrix, int n, int m)
{
    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;
    vector<int> ans;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of column: ";
    cin >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter the element in Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
        cout << endl;
    }
    cout << "Matrix you created:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j];
        }
        cout << endl;
    }

    auto ans = spiralTraversal(matrix, n, m);
    cout << "The Spiral Traversal:\n";
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}